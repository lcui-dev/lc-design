/* ***************************************************************************
 * typography.c -- Typography
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

#include <LCUI_Build.h>
#include <LCUI/LCUI.h>
#include <LCUI/gui/widget.h>
#include "ui/components.h"

void LCUIEx_InitTypograhy( void )
{
	LCUIWidget_NewPrototype( "h1", "textview" );
	LCUIWidget_NewPrototype( "h2", "textview" );
	LCUIWidget_NewPrototype( "h3", "textview" );
	LCUIWidget_NewPrototype( "h4", "textview" );
	LCUIWidget_NewPrototype( "h5", "textview" );
	LCUIWidget_NewPrototype( "h6", "textview" );
	LCUIWidget_NewPrototype( "p", "textview" );
	LCUIWidget_NewPrototype( "pre", "textview" );
	LCUIWidget_NewPrototype( "code-block", "textview" );
	LCUIWidget_NewPrototype( "blockquote", "textview" );
	LCUIWidget_NewPrototype( "i", "textview" );
	LCUIWidget_NewPrototype( "b", "textview" );
	LCUIWidget_NewPrototype( "cite", "textview" );
	LCUIWidget_NewPrototype( "strong", "textview" );
}
