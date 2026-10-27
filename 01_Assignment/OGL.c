// header files

#include <windows.h>

#include <stdio.h>

// For File I/O

// OpenGL Related Files

#include <gl/GL.h>

#include <gl/glu.h>

#include "OGL.h"

#include <stdlib.h> // FOR EXIT()

// Link With OpenGL Import Library
#pragma comment(lib, "Opengl32.lib")
#pragma comment(lib, "GLU32.lib")

// Macros
 
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

// global function declarations

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// global variable declarations
HWND ghwnd = NULL;
HDC ghdc = NULL;
HGLRC ghrc = NULL;
BOOL bFullscreen = FALSE;
DWORD dwStyle;
WINDOWPLACEMENT wpPrev;
FILE *gpFile = NULL;
BOOL bActiveWindow = FALSE;
BOOL bEscapeKeyPressed = FALSE;
// GLfloat anglePyramid = 0.0f;
// GLfloat angleCube = 0.0f;

// Entry-Point Function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hprevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	// Function Declarations
	int Initialize(void);
	void render(void);
	// void update(void);
	void Uninitialize(void);
	
	// variable declarations
	WNDCLASSEX wndclass;
	HWND hwnd = NULL;
	MSG msg;
	TCHAR szAppName[] = TEXT("HAPPY_BIRTHDAY");
	BOOL bDone = FALSE;
	
	// code
	// Create Log File
	gpFile = fopen("Log.txt", "w");
	if (gpFile == NULL)
	{
		MessageBox(NULL, TEXT("LogFile creation failled"), TEXT("Error"), MB_OK);
		exit(0);
	}
	else
	{
		fprintf(gpFile, "AK : Program Started Successfully \n");
	}

	// WNDCLASSEX initialization
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));

	// Register above wndclass
	RegisterClassEx(&wndclass);

	// Centaring 
	int screenWIDTH = GetSystemMetrics(SM_CXSCREEN);
	int screenHEIGHT = GetSystemMetrics(SM_CYSCREEN);

	// create the windowEx
	hwnd = CreateWindowEx(WS_EX_APPWINDOW,
		szAppName, TEXT("My First RTR7 Programe:Aniket M Kweat"),
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
		screenWIDTH/ 2 - WIN_WIDTH / 2,
		screenHEIGHT/ 2 - WIN_HEIGHT / 2, 
		WIN_WIDTH,
		WIN_HEIGHT, 
		NULL, 
		NULL,
		hInstance,
		NULL);

	// Set global window handal
	ghwnd = hwnd;

	int iResult = Initialize();
	if (iResult != 0)
	{
		fprintf(gpFile, "AK : WinMain() : Initialize() Failed\n");
		DestroyWindow(hwnd);
		hwnd = NULL;
	}
	else
	{
		fprintf(gpFile, "AK : WinMain() : Initialize() Successed\n");
	}

	// show window
	ShowWindow(hwnd, iCmdShow);

	// update the window to point its background
	UpdateWindow(hwnd);

	SetForegroundWindow(hwnd);
	SetFocus(hwnd);

	// Game loop
	while (bDone == FALSE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				bDone = TRUE;
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			if (bActiveWindow == TRUE)
			{
				if (bEscapeKeyPressed == TRUE)
					bDone = TRUE;
				
				// Render
				render();

					// Update
					// update();
			}
		}
	}

	// Uninitialize
	Uninitialize();

	return((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT imsg, WPARAM wparam, LPARAM lparam)
{
	// Local Function declarations
	void resize (int, int);
	void toggleFullscreen (void);
	void Uninitialize(void);

	// code
	switch (imsg)
	{
	case WM_CREATE:
		memset(&wpPrev, 0, sizeof(WINDOWPLACEMENT));
		wpPrev.length = sizeof(WINDOWPLACEMENT);
			break;
		case WM_SETFOCUS:
			bActiveWindow = TRUE;
				break;
			case WM_KILLFOCUS:
				bActiveWindow = FALSE;
					break;
				case WM_SIZE:
					resize(LOWORD(lparam), HIWORD(lparam));
						break;
					case WM_KEYDOWN:
						switch (wparam)
						{
						case VK_ESCAPE:
							bEscapeKeyPressed = TRUE;
							break;
						default:
							break;
						}
						break;
					case WM_CHAR:
						switch (wparam)
						{
						case 'F':
						case 'f':
							if (bFullscreen == FALSE)
							{
								toggleFullscreen();
								bFullscreen = TRUE;
							}
							else
							{
								toggleFullscreen();
								bFullscreen = FALSE;
							} 
							break;
						default:
							break;
						}
						break;
					case WM_CLOSE:
						Uninitialize();
						break;
	case WM_DESTROY:
		PostQuitMessage(100);
		break;
	default:
		break;

	}
	return(DefWindowProc(hwnd, imsg, wparam, lparam));

}

// defination
void toggleFullscreen(void)
{
	// variable declarations
	MONITORINFO mi;

	// code
	
	if (bFullscreen == FALSE)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);
		
		if (dwStyle & WS_OVERLAPPEDWINDOW)
		{
			memset(&mi, 0, sizeof(MONITORINFO));
			mi.cbSize = sizeof(MONITORINFO);
			if (GetWindowPlacement(ghwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))
			{
				SetWindowLong(ghwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);
				SetWindowPos(ghwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top, SWP_NOZORDER | SWP_FRAMECHANGED);
			}
		}
		ShowCursor(FALSE);
	}
	else
	{
		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
		SetWindowPlacement(ghwnd, &wpPrev);
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);
		ShowCursor(TRUE);
	}
}

int Initialize(void)
{
	// Function declarations
	void resize(int, int);

	// Variable Declarations
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormateIndex;
	
	// code
	memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1; // Conventional
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cRedBits = 8;
	pfd.cGreenBits = 8;
	pfd.cBlueBits = 8;
	pfd.cAlphaBits = 8;
	pfd.cDepthBits = 32;

	ghdc = GetDC(ghwnd);
	if (ghdc == NULL)
	{
		return -1;
	}

	iPixelFormateIndex = ChoosePixelFormat(ghdc, &pfd); 
	if (iPixelFormateIndex == 0)
	{
		return -2;
	}

	if (SetPixelFormat(ghdc, iPixelFormateIndex, &pfd) == FALSE)
	{
		return -3;
	}

	// breezing API
	ghrc = wglCreateContext(ghdc);
	if (ghrc == NULL)
	{
		return -4;
	}

	if (wglMakeCurrent(ghdc, ghrc) == FALSE)
	{
		return -5;
	}
	
	// Enable Depth
	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	// chose screen clearing colour as blue
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	// warmup resize
	resize(WIN_WIDTH, WIN_HEIGHT);

	return 0;
}

void resize(int Width, int Height)
{
	// code 
	if (Height <= 0)
	Height = 1;

	glViewport(0, 0, (GLsizei)Width, (GLsizei)Height);

	// Projection Matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Perspective
	gluPerspective(45.0f, (GLfloat)Width / (GLfloat)Height, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void render(void) // Display
{
	//code
	// gl Clear ///
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Piramid
	 glMatrixMode(GL_MODELVIEW);
	 glLoadIdentity();

	// glTranslatef(0.0f, 0.0f, 0.0f);

	// glScalef(0.75f, 0.75f, 0.75f);

	// glRotatef(anglePyramid, 0.0f, 1.0f, 0.0f);

	// RGB Colour Piramid

	glLineWidth(5.0f);

	glBegin(GL_LINES);
	
	glColor3f(1.0f, 0.0f, 0.0f);

	glVertex3f(-2.0f, 0.0f, -3.0f);
	glVertex3f(2.0f, 0.0f, -3.0f);
	glEnd();
	 
	// Do double Buffering
	SwapBuffers(ghdc);

}

	
 void update(void)
	{
		// code 
		// Pyraimd
		// anglePyramid = anglePyramid + 0.05f;
		// if (anglePyramid >= 360.0f)
			// anglePyramid = anglePyramid - 360.0f;

		// Cube 
		// angleCube = angleCube + 0.05f;
		// if (angleCube >= 360.0f)
			// angleCube = angleCube - 360.0f;
	}


void Uninitialize(void)
{
	// code

	// If Exiting In full screen 1st restore and than procced
	if (bFullscreen == TRUE)
	{
		toggleFullscreen();

	bFullscreen = FALSE;

	}
		// 1st Check The Current if it is then Unmake it 
		if (wglGetCurrentContext() == ghrc)
		{
			wglMakeCurrent(NULL, NULL);
		}
	// Now Distroy The Rendering Context
	if (ghrc)
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;

	}

	// Distroy The Release The Devise context
	if (ghdc)
	{
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}

	// Distroy window
	if (ghwnd)
	{
		DestroyWindow(ghwnd);
		ghwnd = NULL;
	}

	// Close Log File
	if (gpFile)
	{
		fprintf(gpFile, "Program Terminated Successfully \n");
		fclose(gpFile);
		gpFile = NULL;
	}
}






