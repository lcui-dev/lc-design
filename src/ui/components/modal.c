#include <LCUI_Build.h>
#include <LCUI/LCUI.h>
#include <LCUI/timer.h>
#include "ui/components.h"
#include <LCUI/gui/widget/scrollbar.h>

typedef struct LCUIEx_ModalRec_ {
	LCUI_Widget backdrop;
	LCUI_Widget scrollbar;
	LCUI_Widget dialog;
} LCUIEx_ModalRec, *LCUIEx_Modal;

static struct LCUIEx_ModalModule {
	LCUI_WidgetPrototype proto;
} self;

static void Modal_Init( LCUI_Widget w )
{
	const size_t size = sizeof( LCUIEx_ModalRec );
	LCUIEx_Modal modal = Widget_AddData( w, self.proto, size );

	modal->dialog = NULL;
	modal->backdrop = NULL;
	modal->scrollbar = LCUIWidget_New( "scrollbar" );
	Widget_Append( w, modal->scrollbar );
	ScrollBar_BindBox( modal->scrollbar, w );
}

static void Modal_Destroy( LCUI_Widget w )
{
	LCUIEx_Modal modal = Widget_GetData( w, self.proto );
	if( modal->backdrop ) {
		Widget_Destroy( modal->backdrop );
		modal->backdrop = NULL;
	}
}

static void Modal_InitDialog( LCUI_Widget w )
{
	LinkedListNode *node;
	LCUIEx_Modal modal = Widget_GetData( w, self.proto );
	for( LinkedList_Each( node, &w->children ) ) {
		if( Widget_HasClass( node->data, "modal-dialog" ) ) {
			modal->dialog = node->data;
			break;
		}
	}
	if( modal->dialog ) {
		ScrollBar_BindLayer( modal->scrollbar, modal->dialog );
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
	if( !modal->dialog ) {
		Modal_InitDialog( w );
	}
	Widget_Append( root, w );
	Widget_AddClass( w, "show" );
}

void Modal_Hide( LCUI_Widget w )
{
	LCUIEx_Modal modal = Widget_GetData( w, self.proto );
	if( modal->backdrop ) {
		Widget_Destroy( modal->backdrop );
		modal->backdrop = NULL;
	}
	Widget_RemoveClass( w, "show" );
}

void LCUIEx_InitModal( void )
{
	self.proto = LCUIWidget_NewPrototype( "modal", NULL );
	self.proto->init = Modal_Init;
}
