#include <LCUI_Build.h>
#include <LCUI/LCUI.h>
#include <LCUI/gui/widget.h>

void LCUIEx_InitAlert( void )
{
	LCUIWidget_NewPrototype( "alert", "textview" );
}
