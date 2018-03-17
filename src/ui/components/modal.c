/*
 * modal.c -- Modal component for adding dialogs.
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

#include <LCUI_Build.h>
#include <LCUI/LCUI.h>
#include <LCUI/gui/widget.h>
#include <LCUI/gui/widget/scrollbar.h>
#include <LCUIEx/ui/components/modal.h>

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
		ScrollBar_BindTarget( modal->scrollbar, modal->dialog );
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
