/* ***************************************************************************
 * components.c -- components
 *
 * Copyright (C) 2017 by Liu Chao <lc-soft@live.cn>
 *
 * This file is part of the LCUI.css project, and may only be used, modified,
 * and distributed under the terms of the GPLv2.
 *
 * By continuing to use, modify, or distribute this file you indicate that you
 * have read the license and understand and accept it fully.
 *
 * The LCUI.css project is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GPL v2 for more details.
 *
 * You should have received a copy of the GPLv2 along with this file. It is
 * usually in the LICENSE.TXT file, If not, see <http://www.gnu.org/licenses/>.
 * ****************************************************************************/

#ifndef LCUIEX_UI_COMPONETS_H
#define LCUIEX_UI_COMPONETS_H

#include <LCUI/gui/widget.h>

LCUI_API void LCUIEx_InitAlert( void );

LCUI_API void LCUIEx_InitLabel( void );

LCUI_API void LCUIEx_InitIcon( void );

LCUI_API void LCUIEx_InitPassword( void );

LCUI_API void LCUIEx_InitTypograhy( void );

LCUI_API void LCUIEx_InitModal( void );

LCUI_API void Modal_Show( LCUI_Widget w );

LCUI_API void Modal_Hide( LCUI_Widget w );

LCUI_API void LCUIEx_InitDropdown( void );

LCUI_API void Dropdown_Hide( LCUI_Widget w );

LCUI_API void Dropdown_Show( LCUI_Widget w );

LCUI_API void Dropdown_BindTarget( LCUI_Widget w, LCUI_Widget target );

LCUI_API void Dropdown_Toggle( LCUI_Widget w );

LCUI_API void Dropdown_SetPosition( LCUI_Widget w, LCUI_StyleValue position );

#endif
