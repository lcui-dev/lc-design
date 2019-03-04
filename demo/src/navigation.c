#include <LCUI_Build.h>
#include <LCUI/LCUI.h>
#include <LCUI/display.h>
#include <LCUI/gui/widget.h>
#include "ui.h"

#define PATH_LEN	256

typedef struct NavigationPointRec_ {
	void(*init)(void);
	void(*free)(void);
} NavigationPointRec, *NavigationPoint;

static struct {
	LCUI_Widget active;
	NavigationPoint point;
	NavigationPointRec points[NAV_TOTAL_NUM];
} nav;

static LCUI_Widget GetNavigationItem(LCUI_Widget link)
{
	for (; link; link = link->parent) {
		if (Widget_HasClass(link, "nav-item")) {
			return link;
		}
	}
	return NULL;
}

static NavigationPointId GetNavigationPointId(const char *name)
{
	if (strcmp(name, "home") == 0) {
		return NAV_HOME;
	} else if (strcmp(name, "docs") == 0) {
		return NAV_DOCS;
	}
	return NAV_NONE;
}

static NavigationPointId Navigation_GetPointId(LCUI_Widget link)
{
	const char *name;

	name = Widget_GetAttribute(link, "nav-point");
	if (!name) {
		return NAV_NONE;
	}
	return GetNavigationPointId(name);
}

static void Navgation_BeforeActivePoint(LCUI_Widget link, NavigationPointId id)
{
	if (nav.point) {
		nav.point->free();
		nav.point = NULL;
	}
	if (nav.active) {
		Widget_RemoveClass(nav.active, "active");
		nav.active = NULL;
	}
	Widget_AddClass(link, "active");
}

static void Navgation_ActivePoint(LCUI_Widget link, NavigationPointId id)
{
	if (id == NAV_NONE) {
		return;
	}
	Navgation_BeforeActivePoint(link, id);
	nav.point = &nav.points[id];
	nav.point->init();
	nav.active = link;
	Widget_AddClass(link, "active");
}

static void OnViewLoaded(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
	const char *link_id;
	NavigationPointId id;
	LCUI_Widget link = GetNavigationItem(e->target);

	if (link) {
		id = Navigation_GetPointId(link);
	} else {
		if (arg) {
			id = GetNavigationPointId(arg);
		} else {
			id = Navigation_GetPointId(arg);
		}
		switch (id) {
		case NAV_HOME:
			link_id = ID_LINK_NAV_HOME;
			break;
		case NAV_DOCS:
			link_id = ID_LINK_NAV_DOCS;
			break;
		default:return;
		}
		link = GetNavigationItem(LCUIWidget_GetById(link_id));
	}
	Navgation_ActivePoint(link, id);
}

static void OnClickNavbarLink(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
	int id;
	LCUI_Widget link;

	link = GetNavigationItem(e->target);
	id = Navigation_GetPointId(link);
	if (id == NAV_NONE) {
		return;
	}
	Navgation_BeforeActivePoint(link, id);
}

void Navigation_Init(void)
{
	LCUI_Widget root = LCUIWidget_GetRoot();
	LCUI_Widget navbar = LCUIWidget_GetById(ID_NAVBAR_LINKS);

	Widget_BindEvent(navbar, "click", OnClickNavbarLink, NULL, NULL);
	Widget_BindEvent(root, "loaded.anchor", OnViewLoaded, NULL, NULL);
	ActiveLink(navbar, ID_LINK_NAV_HOME);
	nav.points[NAV_HOME].init = HomeView_Init;
	nav.points[NAV_HOME].free = HomeView_Free;
	nav.points[NAV_DOCS].init = DocumentationView_Init;
	nav.points[NAV_DOCS].free = DocumentationView_Free;
}
