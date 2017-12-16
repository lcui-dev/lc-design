#include <LCUI_Build.h>
#include <LCUI/LCUI.h>
#include "ui/components.h"

typedef struct LCUIEx_ModalRec_ {
	LCUI_Widget backdrop;
} LCUIEx_ModalRec, *LCUIEx_Modal;

static struct LCUIEx_ModalModule {
	LCUI_WidgetPrototype proto;
} self;

static void Modal_Init( LCUI_Widget w )
{
	const size_t size = sizeof( LCUIEx_ModalRec );
	LCUIEx_Modal modal = Widget_AddData( w, self.proto, size );
	modal->backdrop = NULL;
}

static void Modal_Destroy( LCUI_Widget w )
{
	LCUIEx_Modal modal = Widget_GetData( w, self.proto );
	if( modal->backdrop ) {
		Widget_Destroy( modal->backdrop );
		modal->backdrop = NULL;
	}
}

void Modal_Show( LCUI_Widget w )
{
	LCUI_Widget root = LCUIWidget_GetRoot();
	LCUIEx_Modal modal = Widget_GetData( w, self.proto );
	if( !modal->backdrop ) {
		modal->backdrop = LCUIWidget_New( NULL );
		Widget_AddClass( modal->backdrop, "modal-backdrop" );
		Widget_Append( root, modal->backdrop );
	}
	Widget_Append( root, w );
	Widget_Show( w );
	Widget_PrintStyleSheets( w );
}

void Modal_Hide( LCUI_Widget w )
{
	LCUIEx_Modal modal = Widget_GetData( w, self.proto );
	if( modal->backdrop ) {
		Widget_Destroy( modal->backdrop );
		modal->backdrop = NULL;
	}
	Widget_Hide( w );
}

void LCUIEx_InitModal( void )
{
	self.proto = LCUIWidget_NewPrototype( "modal", NULL );
	self.proto->init = Modal_Init;
}
