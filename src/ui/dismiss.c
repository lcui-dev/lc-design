#include <LCUI_Build.h>
#include <LCUI/LCUI.h>
#include <LCUI/gui/widget.h>
#include "LCUIEx.h"

#define HANDLERS_COUNT 2

typedef struct LCUIEx_DismissHandlerRec_ {
	const char *name;
	void( *dismiss )(LCUI_Widget);
} LCUIEx_DismissHandlerRec, *LCUIEx_DismissHandler;

static struct LCUIEx_DismissModule {
	LCUIEx_DismissHandlerRec handlers[HANDLERS_COUNT];
} self = {
	{
		{ "modal", Modal_Hide },
		{ "alert", Widget_Destroy }
	}
};

static void OnClick( LCUI_Widget w, LCUI_WidgetEvent e, void *arg )
{
	int i;
	const char *name = NULL;
	LCUIEx_DismissHandler handler;
	if( e->target ) {
		name = Widget_GetAttribute( e->target, "data-dismiss" );
	}
	if( !name ) {
		return;
	}
	for( i = 0; i < HANDLERS_COUNT; ++i ) {
		handler = &self.handlers[i];
		if( strcmp( handler->name, name ) != 0 ) {
			continue;
		}
		for( w = e->target->parent; w; w = w->parent ) {
			if( Widget_CheckType( w, "alert" ) ) {
				handler->dismiss( w );
				break;
			}
		}
		break;
	}
}

void LCUIEx_InitDismiss( void )
{
	LCUI_Widget root = LCUIWidget_GetRoot();
	Widget_BindEvent( root, "click", OnClick, NULL, NULL );
}
