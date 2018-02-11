#include <LCUI_Build.h>
#include <LCUI/LCUI.h>
#include <LCUIEx/ui/components.h>

static struct LCUIEx_LabelModule {
	LCUI_WidgetPrototype proto;
} self;

static void Label_OnClick( LCUI_Widget w, LCUI_WidgetEvent e, void *arg )
{
	LCUI_Widget target = NULL;
	const char *target_id = Widget_GetAttribute( w, "for" );
	if( target_id ) {
		target = LCUIWidget_GetById( target_id );
	}
	if( target ) {
		LCUIWidget_SetFocus( target );
	}
}

static void Label_Init( LCUI_Widget w )
{
	self.proto->proto->init( w );
	Widget_BindEvent( w, "click", Label_OnClick, NULL, NULL );
}

void LCUIEx_InitLabel( void )
{
	self.proto = LCUIWidget_NewPrototype( "label", "textview" );
	self.proto->init = Label_Init;
}
