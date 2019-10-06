/*
 * typography.c -- Including headings, body text, and more.
 *
 * Copyright (c) 2018-2019, Liu chao <lc-soft@live.cn> All rights reserved.
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
#include <LCDesign/build.h>
#include <LCDesign/ui/components/typography.h>

void LCDesign_InitTypograhy(void)
{
	LCUIWidget_NewPrototype("text", "textview");
	LCUIWidget_NewPrototype("span", "text");
	LCUIWidget_NewPrototype("h1", "text");
	LCUIWidget_NewPrototype("h2", "text");
	LCUIWidget_NewPrototype("h3", "text");
	LCUIWidget_NewPrototype("h4", "text");
	LCUIWidget_NewPrototype("h5", "text");
	LCUIWidget_NewPrototype("h6", "text");
	LCUIWidget_NewPrototype("p", "text");
	LCUIWidget_NewPrototype("pre", "text");
	LCUIWidget_NewPrototype("code-block", "text");
	LCUIWidget_NewPrototype("blockquote", "text");
	LCUIWidget_NewPrototype("i", "text");
	LCUIWidget_NewPrototype("b", "text");
	LCUIWidget_NewPrototype("cite", "text");
	LCUIWidget_NewPrototype("strong", "text");
	LCUIWidget_NewPrototype("small", "text");
}
