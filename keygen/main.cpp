#include <windows.h>
#include "resource.h"

#define MAX_BUFFER_LENGTH 32

BOOL CALLBACK MainDlgProc( HWND, UINT, WPARAM, LPARAM );

/*
 * Application name, form title
 */
char szAppName[] = "Keygen";

/*
 * About dialog's text
 */
char szAbout[] = "Fab1o's keygen base";

/*
 * Key variable
 */
char szSerial[ MAX_BUFFER_LENGTH ] = "";

/*
 * Keygeneration routine
 */
void Generate( HWND hDlg )
{
	// HAVE FUN!!1one!1
	
	SetDlgItemTextA( hDlg, IDC_SERIAL, szSerial );
}

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow )
{
	DialogBoxA( NULL, MAKEINTRESOURCEA( IDD_KEYGEN ), NULL, MainDlgProc );
	
	return 0;
}

BOOL CALLBACK MainDlgProc( HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam )
{
	switch( message )
	{
	case WM_INITDIALOG:
		SetWindowTextA( hDlg, szAppName );
		return true;

	case WM_COMMAND:
		switch( wParam )
		{
		case IDC_CLOSE:
			EndDialog( hDlg, 0 );
			break;
		case IDC_ABOUT:
			MessageBoxA( hDlg, szAbout, szAppName, MB_OK );
			break;
		case IDC_GENERATE:
			Generate( hDlg );
			break;
		}
		return true;

	case WM_CLOSE:
		EndDialog( hDlg, 0 );
		return true;
	}
	return false;
}


