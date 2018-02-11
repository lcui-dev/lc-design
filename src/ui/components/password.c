#include <LCUI_Build.h>
#include <LCUI/LCUI.h>
#include <LCUIEx/ui/components.h>
#include <LCUI/gui/widget/textedit.h>

static struct LCUIEx_PasswordModule {
	LCUI_WidgetPrototype proto;
} self;

static void Password_Init( LCUI_Widget w )
{
	self.proto->proto->init( w );
	TextEdit_SetPasswordChar( w, L'●' );
}

void LCUIEx_InitPassword( void )
{
	self.proto = LCUIWidget_NewPrototype( "password", "textedit" );
	self.proto->init = Password_Init;
}
