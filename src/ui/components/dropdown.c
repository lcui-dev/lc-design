/* ***************************************************************************
 * dropdown.c -- contextual menu for displaying options of target
 *
 * Copyright (C) 2017 by Liu Chao <lc-soft@live.cn>
 *
 * This file is part of the LC-Finder project, and may only be used, modified,
 * and distributed under the terms of the GPLv2.
 *
 * By continuing to use, modify, or distribute this file you indicate that you
 * have read the license and understand and accept it fully.
 *
 * The LC-Finder project is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GPL v2 for more details.
 *
 * You should have received a copy of the GPLv2 along with this file. It is
 * usually in the LICENSE.TXT file, If not, see <http://www.gnu.org/licenses/>.
 * ****************************************************************************/

/* ****************************************************************************
 * dropdown.c -- 上下文菜单，用于显示目标的选项列表
 *
 * 版权所有 (C) 2017 归属于 刘超 <lc-soft@live.cn>
 *
 * 这个文件是 LC-Finder 项目的一部分，并且只可以根据GPLv2许可协议来使用、更改和
 * 发布。
 *
 * 继续使用、修改或发布本文件，表明您已经阅读并完全理解和接受这个许可协议。
 *
 * LC-Finder 项目是基于使用目的而加以散布的，但不负任何担保责任，甚至没有适销
 * 性或特定用途的隐含担保，详情请参照GPLv2许可协议。
 *
 * 您应已收到附随于本文件的GPLv2许可协议的副本，它通常在 LICENSE 文件中，如果
 * 没有，请查看：<http://www.gnu.org/licenses/>.
 * ****************************************************************************/

#include <LCUI_Build.h>
#include <LCUI/LCUI.h>
#include <LCUIEx/ui/components.h>

typedef struct LCUIEx_DropdownRec_ {
	int handler_id;
	LCUI_Widget target;
	LCUI_StyleValue position;
} LCUIEx_DropdownRec, *LCUIEx_Dropdown;

static struct DropdwonModule {
	LCUI_WidgetPrototype menu;
	int change_event;
} self;

void Dropdown_UpdatePosition( LCUI_Widget w )
{
	float x, y;
	LCUIEx_Dropdown data = Widget_GetData( w, self.menu );
	if( !data->target ) {
		Widget_Move( w, 0, 0 );
		return;
	}
	Widget_GetOffset( data->target, w->parent, &x, &y );
	switch( data->position ) {
	case SV_TOP_LEFT:
		y -= data->target->height + w->height;
		break;
	case SV_TOP_RIGHT:
		y -= data->target->height + w->height;
		x += data->target->width - w->width;
		break;
	case SV_BOTTOM_RIGHT:
		y += data->target->height;
		x += data->target->width - w->width;
		break;
	case SV_BOTTOM_LEFT:
	default:
		y += data->target->height;
		break;
	}
	switch( data->position ) {
	case SV_TOP_LEFT:
	case SV_TOP_RIGHT:
		if( y >= 0 ) {
			break;
		}
		Widget_GetOffset( data->target, w->parent, &x, &y );
		y += data->target->height;
		break;
	case SV_BOTTOM_LEFT:
	case SV_BOTTOM_RIGHT:
	default:
		if( y + w->height <= w->parent->height ) {
			break;
		}
		Widget_GetOffset( data->target, w->parent, &x, &y );
		y = y - data->target->height + w->height;
		break;
	}
	switch( data->position ) {
	case SV_BOTTOM_RIGHT:
	case SV_TOP_RIGHT:
		if( x >= 0 ) {
			break;
		}
		Widget_GetOffset( data->target, w->parent, &x, &y );
		y += data->target->height;
		break;
	case SV_TOP_LEFT:
	case SV_BOTTOM_LEFT:
	default:
		if( x + w->width <= w->parent->width ) {
			break;
		}
		Widget_GetOffset( data->target, w->parent, &x, &y );
		x = x + data->target->width - w->width;
		break;
	}
	Widget_Move( w, x, y );
}

void Dropdown_Hide( LCUI_Widget w )
{
	LCUIEx_Dropdown data = Widget_GetData( w, self.menu );
	if( data->target ) {
		Widget_RemoveClass( data->target, "active" );
	}
	Dropdown_UpdatePosition( w );
	Widget_RemoveClass( w, "show" );
}

void Dropdown_Show( LCUI_Widget w )
{
	LCUI_Widget root = LCUIWidget_GetRoot();
	LCUIEx_Dropdown data = Widget_GetData( w, self.menu );
	if( data->target ) {
		Widget_AddClass( data->target, "active" );
	}
	if( w->parent != root ) {
		Widget_Append( root, w );
	}
	Dropdown_UpdatePosition( w );
	Widget_AddClass( w, "show" );
}

void Dropdown_Toggle( LCUI_Widget w )
{
	if( Widget_IsVisible( w ) ) {
		Dropdown_Hide( w );
	} else {
		Dropdown_Show( w );
	}
}

static void Dropdown_OnClickOutside( LCUI_Widget w,
				     LCUI_WidgetEvent e, void *arg )
{
	LCUI_Widget target;
	LCUIEx_Dropdown dropdown = Widget_GetData( e->data, self.menu );
	for( target = e->target; target; target = target->parent ) {
		if( target == dropdown->target ) {
			return;
		}
	}
	Dropdown_Hide( e->data );
}

static void Dropdown_OnClick( LCUI_Widget w, LCUI_WidgetEvent e, void *arg )
{
	LCUI_Widget item;
	LCUI_WidgetEventRec ev = { 0 };
	LCUIEx_Dropdown data;

	data = Widget_GetData( w, self.menu );
	for( item = e->target; item; item = item->parent ) {
		if( Widget_HasClass( item, "dropdown-item" ) ) {
			e->cancel_bubble = TRUE;
			ev.target = item;
			ev.type = self.change_event;
			Widget_TriggerEvent( w, &ev, NULL );
			Dropdown_Hide( w );
			break;
		}
	}
}

static void Dropdown_Init( LCUI_Widget w )
{
	const size_t size = sizeof( LCUIEx_DropdownRec );
	LCUIEx_Dropdown data = Widget_AddData( w, self.menu, size );

	data->target = NULL;
	data->position = SV_BOTTOM_LEFT;
	data->handler_id = Widget_BindEvent( LCUIWidget_GetRoot(), "click",
					     Dropdown_OnClickOutside,
					     w, NULL );
	Widget_BindEvent( w, "click", Dropdown_OnClick, NULL, NULL );
	Widget_AddClass( w, "dropdown-menu" );
}

static void Dropdown_Destroy( LCUI_Widget w )
{
	LCUIEx_Dropdown data = Widget_GetData( w, self.menu );
	Widget_UnbindEventByHandlerId( LCUIWidget_GetRoot(), data->handler_id );
}

static void DropdownTarget_OnClick( LCUI_Widget w, LCUI_WidgetEvent e, void *arg )
{
	if( w->disabled ) {
		return;
	}
	Dropdown_Toggle( e->data );
	e->cancel_bubble = TRUE;
}

void Dropdown_BindTarget( LCUI_Widget w, LCUI_Widget target )
{
	LCUIEx_Dropdown data = Widget_GetData( w, self.menu );
	data->target = target;
	if( data->target ) {
		Widget_UnbindEvent( target, "click", DropdownTarget_OnClick );
	}
	Widget_BindEvent( target, "click", DropdownTarget_OnClick, w, NULL );
	data->target = target;
}

void Dropdown_SetPosition( LCUI_Widget w, LCUI_StyleValue position )
{
	LCUIEx_Dropdown data = Widget_GetData( w, self.menu );
	data->position = position;
	Dropdown_UpdatePosition( w );
}

static void Dropdown_SetAttr( LCUI_Widget w, const char *name,
			      const char *value )
{
	if( strcasecmp( name, "data-position" ) == 0 ) {
		LCUIEx_Dropdown menu = Widget_GetData( w, self.menu );
		int position = LCUI_GetStyleValue( value );
		if( position <= 0 ) {
			position = SV_BOTTOM_LEFT;
		}
		Dropdown_SetPosition( w, position );
	}
}

void LCUIEx_InitDropdown( void )
{
	self.menu = LCUIWidget_NewPrototype( "dropdown-menu", NULL );
	self.menu->init = Dropdown_Init;
	self.menu->destroy = Dropdown_Destroy;
	self.menu->setattr = Dropdown_SetAttr;
	self.change_event = LCUIWidget_AllocEventId();
	LCUIWidget_SetEventName( self.change_event, "change.dropdown" );
}
