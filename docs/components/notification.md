# Notification

Display a notification message globally.

## Basic

The simplest usage that close the notification box after 4.5s.

``` embedded-xml
<w class="button-container">
  <button ref="notification-basic" class="btn btn-primary">Open the notification box</button>
</w>
```

``` c
#include <LCUI.h>
#include <LCUI/gui/widget.h>
#include <LCDesign/ui/components/notification.h>

static void OpenNotification(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
    LCDesign_OpenNormalNotification(
        L"Notification Title",
        L"This is the content of the notification. This is the content of "
        L"the notification. This is the content of the notification.",
        NULL, 4500);
}

// ... other code

    LCUI_Widget btn = LCUIWidget_GetById("btn-open-notification");
    Widget_BindEvent(btn, "click", OpenNotification, NULL, NULL);

// ... other code
```

## Placement

A notification box can appear from the `top right`, `bottom-right`, `bottom-left` or `top-left` of the viewport.

``` embedded-xml
<w class="button-container">
  <button ref="notification-top-left" class="btn">top-left</button>
  <button ref="notification-top-right" class="btn">top-right</button>
  <button ref="notification-bottom-left" class="btn">bottom-left</button>
  <button ref="notification-bottom-right" class="btn">bottom-right</button>
</w>
```

``` c
#include <LCUI.h>
#include <LCUI/gui/widget.h>
#include <LCDesign/ui/components/notification.h>

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

// ... other code

    LCUI_Widget btn;

    btn = LCUIWidget_GetById("btn-open-at-top-left");
    Widget_BindEvent(btn, "click", OpenNotificationAtTopLeft, NULL, NULL);

    btn = LCUIWidget_GetById("btn-open-at-top-right");
    Widget_BindEvent(btn, "click", OpenNotificationAtTopRight, NULL, NULL);

    btn = LCUIWidget_GetById("btn-open-at-bottom-left");
    Widget_BindEvent(btn, "click", OpenNotificationAtBottomLeft, NULL, NULL);

    btn = LCUIWidget_GetById("btn-open-at-bottom-right");
    Widget_BindEvent(btn, "click", OpenNotificationAtBottomRight, NULL, NULL);

// ... other code
```

## Customize duration

`Duration` can be used to specify how long the notification stays open. After the duration time elapses, the notification closes automatically. If you set the value to 0, the notification box will never close automatically.

``` embedded-xml
<w class="button-container">
  <button ref="notification-custom-duration" class="btn btn-primary">Open the notification box</button>
</w>
```

``` c
#include <LCUI.h>
#include <LCUI/gui/widget.h>
#include <LCDesign/ui/components/notification.h>

static void OpenNotification(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
    LCDesign_OpenNormalNotification(
        L"Notification Title",
        L"This is the content of the notification. This is the content of "
        L"the notification. This is the content of the notification.",
        NULL, 0);
}

// ... other code

    LCUI_Widget btn = LCUIWidget_GetById("btn-open-notification");
    Widget_BindEvent(btn, "click", OpenNotification, NULL, NULL);

// ... other code
```

## Notification with icon

A notification box with a icon at the left side.

``` embedded-xml
<w class="button-container">
  <button ref="notification-success" class="btn">Success</button>
  <button ref="notification-info" class="btn">Info</button>
  <button ref="notification-warning" class="btn">Warning</button>
  <button ref="notification-error" class="btn">Error</button>
</w>
```

``` c
#include <LCUI.h>
#include <LCUI/gui/widget.h>
#include <LCDesign/ui/components/notification.h>

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

// ... other code

    LCUI_Widget btn;

    btn = LCUIWidget_GetById("btn-open-success-notification");
    Widget_BindEvent(btn, "click", OpenSuccessNotification, NULL, NULL);

    btn = LCUIWidget_GetById("btn-open-info-notification");
    Widget_BindEvent(btn, "click", OpenInfoNotification, NULL, NULL);

    btn = LCUIWidget_GetById("btn-open-warning-notification");
    Widget_BindEvent(btn, "click", OpenWarningNotification, NULL, NULL);

    btn = LCUIWidget_GetById("btn-open-error-notification");
    Widget_BindEvent(btn, "click", OpenErrorNotification, NULL, NULL);

// ... other code
```

## Customized Icon

The icon can be customized to any widget.

``` embedded-xml
<w class="button-container">
  <button ref="notification-custom-icon" class="btn btn-primary">Open the notification box</button>
</w>
```

``` c
#include <LCUI.h>
#include <LCUI/gui/widget.h>
#include <LCDesign/ui/components/notification.h>

static void OpenNotification(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
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

// ... other code

    LCUI_Widget btn = LCUIWidget_GetById("btn-open-notification");
    Widget_BindEvent(btn, "click", OpenNotification, NULL, NULL);

// ... other code
```
