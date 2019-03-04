#include <LCUI_Build.h>
#include <LCUI/LCUI.h>
#include <LCUI/gui/widget.h>
#include "ui.h"

static struct {
	LCUI_Widget active_item;
} self;

static void OnClickSidebarLink(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
	LinkedListNode *node;
	LCUI_Widget link, subnav;

	for (link = e->target; link; link = link->parent) {
		if (Widget_HasClass(link, "nav-item")) {
			break;
		}
		if (!Widget_HasClass(link, "nav-header")) {
			continue;
		}
		subnav = Widget_GetNext(link);
		if (!subnav) {
			continue;
		}
		for (LinkedList_Each(node, &subnav->children)) {
			link = node->data;
			if (Widget_HasClass(link, "nav-item")) {
				break;
			}
		}
		break;
	}
	if (!link) {
		return;
	}
	if (self.active_item) {
		Widget_RemoveClass(self.active_item, "active");
	}
	Widget_AddClass(link, "active");
	self.active_item = link;
}

void DocumentationView_Init(void)
{
	LCUI_Widget sidebar = LCUIWidget_GetById(ID_SIDEBAR_LINKS);

	Widget_BindEvent(sidebar, "click", OnClickSidebarLink, NULL, NULL);
	ActiveLink(sidebar, ID_LINK_GETTING_STARTED);
}

void DocumentationView_Free(void)
{
	self.active_item = NULL;
}
