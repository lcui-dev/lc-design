/*
 * spinner.c -- Spinner, used to indicate the loading state of a component
 * or page.
 *
 * Copyright (c) 2019, Liu chao <lc-soft@live.cn> All rights reserved.
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

#include <math.h>
#include <LCUI.h>
#include <LCUI/timer.h>
#include <LCUI/gui/metrics.h>
#include <LCUI/gui/widget.h>
#include <LCUI/gui/widget/canvas.h>
#include <LCUI/gui/css_parser.h>
#include <LCUI/gui/css_fontstyle.h>
#include <LCDesign/build.h>

#define M_PI 3.14159265358979323846
#define SmoothLeftPixel(PX, X) (uchar_t)((PX)->a * (1.0 - (X - 1.0 * (int)X)))
#define SmoothRightPixel(PX, X) (uchar_t)((PX)->a * (X - 1.0 * (int)X))

typedef enum SpinnerType { SPINNER_DEFAULT, SPINNER_RING } SpinnerType;

typedef struct SpinnerRec_ {
	int size;
	int custom_size;
	int timer;
	int angle;
	int duration;
	int start;
	int line_width;
	SpinnerType type;
	LCUI_Color color;
	clock_t start_time;
} SpinnerRec, *Spinner;

static struct {
	LCUI_WidgetPrototype proto;
} spinner_module;

static INLINE FillPixel(LCUI_Graph *g, int x, int y, LCUI_Color *color)
{
	g->argb[g->width * y + x] = *color;
}

static INLINE int line_angle(double x, double y)
{
	double radians = atan(y / x);

	if (x < 0) {
		radians += M_PI;
	} else {
		if (y < 0) {
			radians += 2 * M_PI;
		}
	}
	return (int)(radians * 180 / M_PI);
}

static INLINE LCUI_BOOL CheckInSlider(double x, double y, int start, int end)
{
	int angle = line_angle(x, y);

	if (end < 0 && ((angle < start && angle > 0) || (angle > end + 360))) {
		return TRUE;
	} else if (angle > end && angle < start) {
		return TRUE;
	}
	return FALSE;
}

static void Spinner_Render(LCUI_Widget w)
{
	LCUI_Color c;
	LCUI_Color slider_color, border_color;
	LCUI_CanvasContext ctx = Canvas_GetContext(w);
	Spinner spinner = Widget_GetData(w, spinner_module.proto);

	int xi, yi;
	int start = spinner->start;
	int end = start - spinner->angle;

	double d;
	double r = spinner->size / 2.0 - 0.5;
	double inner_r = r - spinner->line_width * ctx->scale;
	double outer_smooth_r2 = (r + 1.0) * (r + 1.0);

	if (spinner->type == SPINNER_RING) {
		border_color = spinner->color;
		border_color.alpha = 25;
		slider_color = spinner->color;
	} else {
		border_color = spinner->color;
		slider_color = ARGB(0, 0, 0, 0);
	}
	ctx->clearRect(ctx, 0, 0, ctx->width, ctx->height);
	if (ctx->width < spinner->size || ctx->height < spinner->size) {
		ctx->release(ctx);
		return;
	}
	for (yi = 0; yi < spinner->size; ++yi) {
		double y = r - yi;
		double y2 = y * y;

		for (xi = 0; xi < spinner->size; ++xi) {
			double x = xi - r;
			double x2 = x * x;

			d = x2 + y2;
			if (d >= outer_smooth_r2) {
				continue;
			}
			if (CheckInSlider(x, y, start, end)) {
				c = slider_color;
			} else {
				c = border_color;
			}
			d = sqrt(d) - r;
			if (d >= 0) {
				c.a = SmoothLeftPixel(&c, d);
				FillPixel(&ctx->buffer, xi, yi, &c);
				continue;
			}
			d = d + r - inner_r;
			if (d < 0) {
				continue;
			}
			if (d < 1.0) {
				c.a = SmoothRightPixel(&c, d);
			}
			FillPixel(&ctx->buffer, xi, yi, &c);
		}
	}
	Widget_InvalidateArea(w, NULL, SV_CONTENT_BOX);
	ctx->release(ctx);
}

static Spinner_OnFrame(LCUI_Widget w)
{
	Spinner spinner = Widget_GetData(w, spinner_module.proto);

	clock_t now = clock();
	clock_t duration = (now - spinner->start_time) % spinner->duration;

	spinner->start = (int)(360.0 - duration * 360.0 / spinner->duration);
	if (duration >= spinner->start_time) {
		spinner->start_time = now;
	}
	Spinner_Render(w);
}

static void Spinner_OnInit(LCUI_Widget w)
{
	Spinner spinner =
	    Widget_AddData(w, spinner_module.proto, sizeof(SpinnerRec));

	spinner_module.proto->proto->init(w);
	spinner->line_width = 2;
	spinner->custom_size = 32;
	spinner->size = spinner->custom_size;
	spinner->type = SPINNER_DEFAULT;
	spinner->angle = 90;
	spinner->start = 360;
	spinner->duration = 750;
	spinner->start_time = clock();
	spinner->timer =
	    LCUI_SetInterval(LCUI_MAX_FRAME_MSEC, Spinner_OnFrame, w);
}

static void Spinner_OnDestroy(LCUI_Widget w)
{
	Spinner spinner = Widget_GetData(w, spinner_module.proto);

	LCUITimer_Free(spinner->timer);
}

static void Spinner_AutoSize(LCUI_Widget w, float *width, float *height,
			     LCUI_LayoutRule rule)
{
	float scale = LCUIMetrics_GetScale();
	Spinner spinner = Widget_GetData(w, spinner_module.proto);

	*width = spinner->size / scale;
	*height = spinner->size / scale;
}

static void Spinner_OnUpdateStyle(LCUI_Widget w)
{
	LCUI_CSSFontStyleRec style;
	Spinner spinner = Widget_GetData(w, spinner_module.proto);

	CSSFontStyle_Init(&style);
	CSSFontStyle_Compute(&style, w->style);
	if (Widget_HasAutoStyle(w, LCUI_GetFontStyleKey(key_font_size))) {
		spinner->size = spinner->custom_size;
	} else {
		spinner->size = style.font_size;
	}
	spinner->line_width = max(2, spinner->size / 8);
	spinner->color = style.color;
	CSSFontStyle_Destroy(&style);
	Widget_AddTask(w, LCUI_WTASK_REFLOW);
}

static void Spinner_OnSetAttribute(LCUI_Widget w, const char *name,
				   const char *value)
{
	Spinner spinner = Widget_GetData(w, spinner_module.proto);

	if (strcmp(name, "type") == 0) {
		spinner->type = SPINNER_DEFAULT;
		if (strcmp(value, "ring") == 0) {
			spinner->type = SPINNER_RING;
		}
	} else if (strcmp(name, "size") == 0) {
		if (strcmp(value, "small") == 0) {
			spinner->custom_size = 14;
		} else {
			spinner->custom_size = 32;
		}
	}
}

void LCDesign_InitSpinner(void)
{
	spinner_module.proto = LCUIWidget_NewPrototype("spinner", "canvas");
	spinner_module.proto->init = Spinner_OnInit;
	spinner_module.proto->destroy = Spinner_OnDestroy;
	spinner_module.proto->autosize = Spinner_AutoSize;
	spinner_module.proto->update = Spinner_OnUpdateStyle;
	spinner_module.proto->setattr = Spinner_OnSetAttribute;
	LCUI_LoadCSSString("spinner { display: inline-block; }", __FILE__);
}
