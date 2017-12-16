#include <LCUI_Build.h>
#include <LCUI/LCUI.h>
#include <LCUI/gui/widget.h>
#include "LCUIEx.h"

#define HANDLERS_COUNT 1

typedef struct LCUIEx_ToggleHandlerRec_ {
	const char *name;
	void( *toggle )(LCUI_Widget, LCUI_Widget);
} LCUIEx_ToggleHandlerRec, *LCUIEx_ToggleHandler;

static void ToggleModal( LCUI_Widget btn, LCUI_Widget target )
{
	if( target ) {
		Modal_Show( target );
	}
}

static struct LCUIEx_ToggleModule {
	LCUIEx_ToggleHandlerRec handlers[HANDLERS_COUNT];
} self = {
	{
		{ "modal", ToggleModal }
	}
};

static void OnClick( LCUI_Widget w, LCUI_WidgetEvent e, void *arg )
{
	int i;
	const char *target_id;
	const char *name = NULL;
	LCUIEx_ToggleHandler handler;
	if( e->target ) {
		name = Widget_GetAttribute( e->target, "data-toggle" );
	}
	if( !name ) {
		return;
	}
	for( i = 0; i < HANDLERS_COUNT; ++i ) {
		handler = &self.handlers[i];
		if( strcmp( handler->name, name ) != 0 ) {
			continue;
		}
		target_id = Widget_GetAttribute( e->target, "data-target" );
		handler->toggle( e->target, LCUIWidget_GetById( target_id ) );
	}
}

void LCUIEx_InitToggle( void )
{
	LCUI_Widget root = LCUIWidget_GetRoot();
	Widget_BindEvent( root, "click", OnClick, NULL, NULL );
}
