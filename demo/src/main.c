#include <LCUI_Build.h>
#include <LCUI/LCUI.h>
#include <LCUI/gui/widget.h>
#include <LCUI/gui/builder.h>
#include <LCUI/timer.h>
#include <LCUIEx.h>

#ifdef _WIN32
#include <locale.h>

static void LoggerHandler(const char *str)
{
	OutputDebugStringA(str);
}

static void LoggerHandlerW(const wchar_t *str)
{
	OutputDebugStringW(str);
}
#endif

static void OnTimer( void *arg ) {
	Widget_PrintTree( NULL );
}

int main( int argc, char **argv )
{
	LCUI_Widget root, pack;

#ifdef _WIN32
	_wsetlocale( LC_ALL, L"chs" );
	Logger_SetHandler( LoggerHandler );
	Logger_SetHandlerW( LoggerHandlerW );
#endif
	LCUI_Init();
	LCUIEx_Init();
	root = LCUIWidget_GetRoot();
	pack = LCUIBuilder_LoadFile( "assets/views/main.xml" );
	if (!pack) {
		return -1;
	}
	Widget_Append( root, pack );
	Widget_Unwrap( pack );
	Widget_SetTitleW( root, L"LCUI.css - Simple CSS framework for developing LCUI application." );
	Widget_PrintStyleSheets( LCUIWidget_GetById( "debug-text" ) );
	LCUITimer_Set( 1000, OnTimer, NULL, FALSE );
	return LCUI_Main();
}
