#include "pch.h"
#include "CMain.h"

CAppModule _Module;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	::InitCommonControls();

	CMain dlg;
	dlg.DoModal();

	return 0;
}