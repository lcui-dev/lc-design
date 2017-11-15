#include <LCUI_Build.h>
#include <LCUI/LCUI.h>
#include <LCUI/display.h>
#include <LCUI/gui/widget.h>
#include "ui.h"

#define PATH_LEN	256

typedef struct NavigationPointRec_ {
	void( *init )(void);
	void( *free )(void);
} NavigationPointRec, *NavigationPoint;

static struct {
	LCUI_Widget active;
	NavigationPoint point;
	NavigationPointRec points[NAV_TOTAL_NUM];
} nav;

static LCUI_Widget GetNavigationItem( LCUI_Widget link )
{
	for( ; link; link = link->parent ) {
		if( Widget_HasClass( link, "nav-item" ) ) {
			return link;
		}
	}
	return NULL;
}

static int Navigation_GetPointId( LCUI_Widget link )
{
	const char *name;
	name = Widget_GetAttribute( link, "nav-point" );
	if( !name ) {
		return -1;
	}
	if( strcmp( name, "home" ) == 0 ) {
		return NAV_HOME;
	} else if( strcmp( name, "docs" ) == 0 ) {
		return NAV_DOCS;
	}
	return -1;
}

static void OnViewLoaded( LCUI_Widget w, LCUI_WidgetEvent e, void *arg )
{
	LCUI_Widget link = GetNavigationItem( e->target );
	int id = Navigation_GetPointId( link );
	if( id != -1 ) {
		nav.points[id].init();
		nav.point = &nav.points[id];
	}
}

static void OnClickNavbarLink( LCUI_Widget w, LCUI_WidgetEvent e, void *arg )
{
	int id;
	LCUI_Widget link;
	link = GetNavigationItem( e->target );
	id = Navigation_GetPointId( link );
	if( id == -1 ) {
		return;
	}
	if( nav.active ) {
		Widget_RemoveClass( nav.active, "active" );
	}
	if( nav.point ) {
		nav.point->free();
	}
	Widget_AddClass( link, "active" );
	nav.point = &nav.points[id];
	nav.active = link;
}

void Navigation_Init( void )
{
	LCUI_Widget root = LCUIWidget_GetRoot();
	LCUI_Widget navbar = LCUIWidget_GetById( ID_NAVBAR_LINKS );
	Widget_BindEvent( navbar, "click", OnClickNavbarLink, NULL, NULL );
	Widget_BindEvent( root, "loaded.anchor", OnViewLoaded, NULL, NULL );
	ActiveLink( navbar, ID_LINK_NAV_HOME );
	nav.points[NAV_HOME].init = HomeView_Init;
	nav.points[NAV_HOME].free = HomeView_Free;
	nav.points[NAV_DOCS].init = DocumentationView_Init;
	nav.points[NAV_DOCS].free = DocumentationView_Free;
}
