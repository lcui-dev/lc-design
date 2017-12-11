#include <LCUI_Build.h>
#include <LCUI/LCUI.h>
#include <LCUI/gui/widget.h>
#include <LCUI/gui/widget/textview.h>

static struct LCUIEx_AlertModule {
	LCUI_WidgetPrototype proto;
} self;

static void Alert_OnClick( LCUI_Widget w, LCUI_WidgetEvent e, void *arg )
{
	const char *attr;
	if( e->target ) {
		attr = Widget_GetAttribute( e->target, "data-dismiss" );
		if( attr && strcmp( attr, "alert" ) ) {
			Widget_Destroy( w );
		}
	}
}

static void Alert_Init( LCUI_Widget w )
{
	self.proto->proto->init( w );
	Widget_BindEvent( w, "click", Alert_OnClick, NULL, NULL );
}

void LCUIEx_InitAlert( void )
{
	self.proto = LCUIWidget_NewPrototype( "alert", "textview" );
	self.proto->init = Alert_Init;
}
