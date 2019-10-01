#include <LCUI.h>
#include <LCUI/timer.h>
#include <LCUI/gui/widget.h>
#include <LCUI/gui/widget/textview.h>
#include <LCDesign/ui/components/icon.h>
#include <LCDesign/ui/components/message.h>

static LCUI_Widget container;

LCUI_Widget LCDesign_OpenMessage(LCDesign_MessageConfig config)
{
	LCUI_Widget wrapper;
	LCUI_Widget message;
	LCUI_Widget content;

	if (!container) {
		container = LCUIWidget_New(NULL);
		Widget_AddClass(container, "message-notice-container");
		Widget_Append(LCUIWidget_GetRoot(), container);
	}
	wrapper = LCUIWidget_New(NULL);
	message = LCUIWidget_New(NULL);
	content = LCUIWidget_New("text");
	if (config->icon) {
		Widget_AddClass(config->icon, "message-notice-icon");
		Widget_Append(message, config->icon);
	}
	Widget_AddClass(wrapper, "message-notice-wrapper");
	Widget_AddClass(message, "message-notice");
	Widget_AddClass(content, "message-notice-content");
	TextView_SetTextW(content, config->content);
	Widget_Append(message, content);
	Widget_Append(wrapper, message);
	Widget_Append(container, wrapper);
	if (config->duration > 0) {
		LCUI_SetTimeout(config->duration,
				(TimerCallback)LCDesign_CloseMessage, wrapper);
	}
	return wrapper;
}

void LCDesign_CloseMessage(LCUI_Widget message)
{
	Widget_Destroy(message);
}

LCUI_Widget LCDesign_OpenSuccessMessage(const wchar_t *content, long duration)
{
	LCUI_Widget icon;
	LCUI_Widget message;
	LCDesign_MessageConfigRec config;

	icon = LCUIWidget_New("icon");
	Icon_SetName(icon, "check-circle");

	config.icon = icon;
	config.content = content;
	config.duration = duration;
	message = LCDesign_OpenMessage(&config);
	Widget_AddClass(message, "message-notice-success");
	return message;
}

LCUI_Widget LCDesign_OpenInfoMessage(const wchar_t *content, long duration)
{
	LCUI_Widget icon;
	LCUI_Widget message;
	LCDesign_MessageConfigRec config;

	icon = LCUIWidget_New("icon");
	Icon_SetName(icon, "information");

	config.icon = icon;
	config.content = content;
	config.duration = duration;
	message = LCDesign_OpenMessage(&config);
	Widget_AddClass(message, "message-notice-info");
	return message;
}

LCUI_Widget LCDesign_OpenWarningMessage(const wchar_t *content, long duration)
{
	LCUI_Widget icon;
	LCUI_Widget message;
	LCDesign_MessageConfigRec config;

	icon = LCUIWidget_New("icon");
	Icon_SetName(icon, "alert-circle");

	config.icon = icon;
	config.content = content;
	config.duration = duration;
	message = LCDesign_OpenMessage(&config);
	Widget_AddClass(message, "message-notice-warning");
	return message;
}

LCUI_Widget LCDesign_OpenErrorMessage(const wchar_t *content, long duration)
{
	LCUI_Widget icon;
	LCUI_Widget message;
	LCDesign_MessageConfigRec config;

	icon = LCUIWidget_New("icon");
	Icon_SetName(icon, "close-circle");

	config.icon = icon;
	config.content = content;
	config.duration = duration;
	message = LCDesign_OpenMessage(&config);
	Widget_AddClass(message, "message-notice-error");
	return message;
}

LCUI_Widget LCDesign_OpenLoadingMessage(const wchar_t *content, long duration)
{
	LCUI_Widget icon;
	LCUI_Widget message;
	LCDesign_MessageConfigRec config;

	icon = LCUIWidget_New("spinner");
	Widget_SetAttribute(icon, "type", "ring");

	config.icon = icon;
	config.content = content;
	config.duration = duration;
	message = LCDesign_OpenMessage(&config);
	Widget_AddClass(message, "message-notice-loading");
	return message;
}
