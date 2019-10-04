#include <LCUI.h>
#include <LCUI/timer.h>
#include <LCUI/gui/widget.h>
#include <LCUI/gui/widget/textview.h>
#include <LCDesign/ui/components/icon.h>
#include <LCDesign/ui/components/notification.h>

struct LCDesign_Notification {
	LCUI_Widget top_left_container;
	LCUI_Widget top_right_container;
	LCUI_Widget bottom_left_container;
	LCUI_Widget bottom_right_container;
	LCUI_Widget custom_container;
} self;

static void OnClickCloseButton(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
	LCDesign_CloseNotification(e->data);
}


void LCDesign_SetNotificationContainer(LCUI_Widget w)
{
	self.custom_container = w;
}

LCUI_Widget LCDesign_OpenNotification(LCDesign_NotificationConfig config)
{
	LCUI_Widget box;
	LCUI_Widget title;
	LCUI_Widget description;
	LCUI_Widget close;
	LCUI_Widget content;
	LCUI_Widget container;

	const char *placement = config->placement;

	if (!placement) {
		placement = "top-right";
	}
	if (self.custom_container) {
		container = self.custom_container;
	} else if (strcmp(placement, "top-left") == 0) {
		container = self.top_left_container;
		if (!container) {
			container = LCUIWidget_New(NULL);
			self.top_left_container = container;
			Widget_AddClass(container,
					"notification-container "
					"notification-container-top-left");
			Widget_Append(LCUIWidget_GetRoot(), container);
		}
	} else if (strcmp(placement, "bottom-left") == 0) {
		container = self.bottom_left_container;
		if (!container) {
			container = LCUIWidget_New(NULL);
			self.bottom_left_container = container;
			Widget_AddClass(container,
					"notification-container "
					"notification-container-bottom-left");
			Widget_Append(LCUIWidget_GetRoot(), container);
		}
	} else if (strcmp(placement, "bottom-right") == 0) {
		container = self.bottom_right_container;
		if (!container) {
			container = LCUIWidget_New(NULL);
			self.bottom_right_container = container;
			Widget_AddClass(container,
					"notification-container "
					"notification-container-bottom-right");
			Widget_Append(LCUIWidget_GetRoot(), container);
		}
	} else {
		container = self.top_right_container;
		if (!container) {
			container = LCUIWidget_New(NULL);
			self.top_right_container = container;
			Widget_AddClass(container,
					"notification-container "
					"notification-container-top-right");
			Widget_Append(LCUIWidget_GetRoot(), container);
		}
	}
	box = LCUIWidget_New(NULL);
	content = LCUIWidget_New(NULL);
	title = LCUIWidget_New("text");
	close = LCUIWidget_New("icon");
	description = LCUIWidget_New("text");
	Icon_SetName(close, "close");
	TextView_SetTextW(title, config->title);
	TextView_SetTextW(description, config->description);
	if (config->icon) {
		Widget_AddClass(box, "notification-has-icon");
		Widget_AddClass(config->icon, "notification-notice-icon");
		Widget_Append(box, config->icon);
	}
	Widget_AddClass(box, "notification-notice");
	Widget_AddClass(close, "notification-notice-close");
	Widget_AddClass(title, "notification-notice-title");
	Widget_AddClass(description, "notification-notice-description");
	Widget_AddClass(content, "notification-notice-content");
	Widget_BindEvent(close, "click", OnClickCloseButton, box, NULL);
	Widget_Append(content, title);
	Widget_Append(content, description);
	Widget_Append(box, content);
	Widget_Append(box, close);
	Widget_Append(container, box);
	if (config->duration > 0) {
		LCUI_SetTimeout(config->duration,
				(TimerCallback)LCDesign_CloseNotification, box);
	}
	return box;
}

void LCDesign_CloseNotification(LCUI_Widget noti)
{
	Widget_Destroy(noti);
}

LCUI_Widget LCDesign_OpenNormalNotification(const wchar_t *title,
					    const wchar_t *description,
					    const char *placement,
					    long duration)
{
	LCDesign_NotificationConfigRec config;

	config.icon = NULL;
	config.title = title;
	config.placement = placement;
	config.description = description;
	config.duration = duration;
	return LCDesign_OpenNotification(&config);
}

LCUI_Widget LCDesign_OpenSuccessNotification(const wchar_t *title,
					     const wchar_t *description,
					     const char *placement,
					     long duration)
{
	LCUI_Widget icon;
	LCDesign_NotificationConfigRec config;

	icon = LCUIWidget_New("icon");
	Icon_SetName(icon, "check-circle-outline");
	Widget_AddClass(icon, "notification-notice-icon-success");

	config.icon = icon;
	config.title = title;
	config.placement = placement;
	config.description = description;
	config.duration = duration;
	return LCDesign_OpenNotification(&config);
}

LCUI_Widget LCDesign_OpenInfoNotification(const wchar_t *title,
					  const wchar_t *description,
					  const char *placement, long duration)
{
	LCUI_Widget icon;
	LCDesign_NotificationConfigRec config;

	icon = LCUIWidget_New("icon");
	Icon_SetName(icon, "information-outline");
	Widget_AddClass(icon, "notification-notice-icon-info");

	config.icon = icon;
	config.title = title;
	config.placement = placement;
	config.description = description;
	config.duration = duration;
	return LCDesign_OpenNotification(&config);
}

LCUI_Widget LCDesign_OpenWarningNotification(const wchar_t *title,
					     const wchar_t *description,
					     const char *placement,
					     long duration)
{
	LCUI_Widget icon;
	LCDesign_NotificationConfigRec config;

	icon = LCUIWidget_New("icon");
	Icon_SetName(icon, "alert-circle-outline");
	Widget_AddClass(icon, "notification-notice-icon-warning");

	config.icon = icon;
	config.title = title;
	config.placement = placement;
	config.description = description;
	config.duration = duration;
	return LCDesign_OpenNotification(&config);
}

LCUI_Widget LCDesign_OpenErrorNotification(const wchar_t *title,
					   const wchar_t *description,
					   const char *placement, long duration)
{
	LCUI_Widget icon;
	LCDesign_NotificationConfigRec config;

	icon = LCUIWidget_New("icon");
	Icon_SetName(icon, "close-circle-outline");
	Widget_AddClass(icon, "notification-notice-icon-error");

	config.icon = icon;
	config.title = title;
	config.placement = placement;
	config.description = description;
	config.duration = duration;
	return LCDesign_OpenNotification(&config);
}
