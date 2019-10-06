#include <LCUI.h>
#include <LCDesign.h>

static LCUI_WidgetPrototype notification_view_proto;

static void OpenBasicNotification(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
	LCDesign_OpenNormalNotification(
	    L"Notification Title",
	    L"This is the content of the notification. This is the content of "
	    L"the notification. This is the content of the notification.",
	    NULL, 4500);
}

static void OpenNotificationAtTopLeft(LCUI_Widget w, LCUI_WidgetEvent e,
				      void *arg)
{
	LCDesign_OpenNormalNotification(
	    L"Notification Title",
	    L"This is the content of the notification. This is the content of "
	    L"the notification. This is the content of the notification.",
	    "top-left", 4500);
}

static void OpenNotificationAtTopRight(LCUI_Widget w, LCUI_WidgetEvent e,
				       void *arg)
{
	LCDesign_OpenNormalNotification(
	    L"Notification Title",
	    L"This is the content of the notification. This is the content of "
	    L"the notification. This is the content of the notification.",
	    "top-right", 4500);
}

static void OpenNotificationAtBottomLeft(LCUI_Widget w, LCUI_WidgetEvent e,
					 void *arg)
{
	LCDesign_OpenNormalNotification(
	    L"Notification Title",
	    L"This is the content of the notification. This is the content of "
	    L"the notification. This is the content of the notification.",
	    "bottom-left", 4500);
}

static void OpenNotificationAtBottomRight(LCUI_Widget w, LCUI_WidgetEvent e,
					  void *arg)
{
	LCDesign_OpenNormalNotification(
	    L"Notification Title",
	    L"This is the content of the notification. This is the content of "
	    L"the notification. This is the content of the notification.",
	    "bottom-right", 4500);
}

static void OpenNotificationCustomDuration(LCUI_Widget w, LCUI_WidgetEvent e,
					   void *arg)
{
	LCDesign_OpenNormalNotification(
	    L"Notification Title",
	    L"This is the content of the notification. This is the content of "
	    L"the notification. This is the content of the notification.",
	    NULL, 0);
}

static void OpenSuccessNotification(LCUI_Widget w, LCUI_WidgetEvent e,
				    void *arg)
{
	LCDesign_OpenSuccessNotification(
	    L"Notification Title",
	    L"This is the content of the notification. This is the content of "
	    L"the notification. This is the content of the notification.",
	    NULL, 4500);
}

static void OpenInfoNotification(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
	LCDesign_OpenInfoNotification(
	    L"Notification Title",
	    L"This is the content of the notification. This is the content of "
	    L"the notification. This is the content of the notification.",
	    NULL, 4500);
}

static void OpenWarningNotification(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
	LCDesign_OpenWarningNotification(
	    L"Notification Title",
	    L"This is the content of the notification. This is the content of "
	    L"the notification. This is the content of the notification.",
	    NULL, 4500);
}

static void OpenErrorNotification(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
	LCDesign_OpenErrorNotification(
	    L"Notification Title",
	    L"This is the content of the notification. This is the content of "
	    L"the notification. This is the content of the notification.",
	    NULL, 4500);
}

static void OpenNotificationCustomIcon(LCUI_Widget w, LCUI_WidgetEvent e,
				       void *arg)
{
	LCUI_Widget icon;
	LCDesign_NotificationConfigRec config;

	icon = LCUIWidget_New("icon");
	Icon_SetName(icon, "emoticon-happy-outline");
	Widget_SetStyleString(icon, "color", "#108ee9");

	config.icon = icon;
	config.duration = 4500;
	config.placement = NULL;
	config.title = L"Notification Title";
	config.description =
	    L"This is the content of the notification. This is the content of "
	    L"the notification. This is the content of the notification.";
	LCDesign_OpenNotification(&config);
}

static void NotificationView_OnReady(LCUI_Widget w, LCUI_WidgetEvent e,
				     void *arg)
{
	Dict *dict;
	LCUI_Widget btn;

	dict = Widget_CollectReferences(w);

	btn = Dict_FetchValue(dict, "notification-basic");
	Widget_BindEvent(btn, "click", OpenBasicNotification, NULL, NULL);

	btn = Dict_FetchValue(dict, "notification-top-left");
	Widget_BindEvent(btn, "click", OpenNotificationAtTopLeft, NULL, NULL);

	btn = Dict_FetchValue(dict, "notification-top-right");
	Widget_BindEvent(btn, "click", OpenNotificationAtTopRight, NULL, NULL);

	btn = Dict_FetchValue(dict, "notification-bottom-left");
	Widget_BindEvent(btn, "click", OpenNotificationAtBottomLeft, NULL,
			 NULL);

	btn = Dict_FetchValue(dict, "notification-bottom-right");
	Widget_BindEvent(btn, "click", OpenNotificationAtBottomRight, NULL,
			 NULL);

	btn = Dict_FetchValue(dict, "notification-custom-duration");
	Widget_BindEvent(btn, "click", OpenNotificationCustomDuration, NULL,
			 NULL);

	btn = Dict_FetchValue(dict, "notification-success");
	Widget_BindEvent(btn, "click", OpenSuccessNotification, NULL, NULL);

	btn = Dict_FetchValue(dict, "notification-info");
	Widget_BindEvent(btn, "click", OpenInfoNotification, NULL, NULL);

	btn = Dict_FetchValue(dict, "notification-warning");
	Widget_BindEvent(btn, "click", OpenWarningNotification, NULL, NULL);

	btn = Dict_FetchValue(dict, "notification-error");
	Widget_BindEvent(btn, "click", OpenErrorNotification, NULL, NULL);

	btn = Dict_FetchValue(dict, "notification-custom-icon");
	Widget_BindEvent(btn, "click", OpenNotificationCustomIcon, NULL, NULL);

	Dict_Release(dict);
	Widget_UnbindEvent(w, "ready", NotificationView_OnReady);
}

static void NotificationView_OnInit(LCUI_Widget w)
{
	Widget_BindEvent(w, "ready", NotificationView_OnReady, NULL, NULL);
}

void UI_InitNotificationView(void)
{
	notification_view_proto =
	    LCUIWidget_NewPrototype("notification-view", NULL);
	notification_view_proto->init = NotificationView_OnInit;
}
