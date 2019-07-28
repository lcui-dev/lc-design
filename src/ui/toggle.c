/*
 * toggle.c -- The widget status toggle controller.
 *
 * Copyright (c) 2018, Liu chao <lc-soft@live.cn> All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of LCUI nor the names of its contributors may be used
 *     to endorse or promote products derived from this software without
 *     specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <LCUI.h>
#include <LCUI/gui/widget.h>
#include <LCDesign/ui/components.h>
#include <LCDesign/ui/toggle.h>

#define HANDLERS_COUNT 2

typedef struct LCDesign_ToggleHandlerRec_ {
	const char *name;
	void( *toggle )(LCUI_Widget, LCUI_Widget);
} LCDesign_ToggleHandlerRec, *LCDesign_ToggleHandler;

static void ToggleModal( LCUI_Widget btn, LCUI_Widget target )
{
	if( target ) {
		Modal_Show( target );
	}
}

static void ToggleDropdown( LCUI_Widget btn, LCUI_Widget target )
{
	if( target ) {
		Dropdown_BindTarget( target, btn );
		Dropdown_Toggle( target );
	}
}

static struct LCDesign_ToggleModule {
	LCDesign_ToggleHandlerRec handlers[HANDLERS_COUNT];
} self = {
	{
		{ "modal", ToggleModal },
		{ "dropdown", ToggleDropdown }
	}
};

static void OnClick( LCUI_Widget w, LCUI_WidgetEvent e, void *arg )
{
	int i;
	const char *target_id;
	const char *name = NULL;
	LCDesign_ToggleHandler handler;
	LCUI_Widget btn;

	for( btn = e->target; btn; btn = btn->parent ) {
		name = Widget_GetAttribute( btn, "data-toggle" );
		if( name ) {
			break;
		}
	}
	if( !name ) {
		return;
	}
	for( i = 0; i < HANDLERS_COUNT; ++i ) {
		handler = &self.handlers[i];
		if( strcmp( handler->name, name ) != 0 ) {
			continue;
		}
		target_id = Widget_GetAttribute( btn, "data-target" );
		handler->toggle( btn, LCUIWidget_GetById( target_id ) );
	}
}

void LCDesign_InitToggle( void )
{
	LCUI_Widget root = LCUIWidget_GetRoot();
	Widget_BindEvent( root, "click", OnClick, NULL, NULL );
}
