# Message

Display global messages as feedback in response to user operations.

## Normal prompt

Normal message for information.

``` embedded-xml
<w class="button-container">
  <button ref="open-normal-message" class="btn btn-primary">Display normal message</button>
</w>
```

``` c
#include <LCUI.h>
#include <LCUI/gui/widget.h>
#include <LCDesign/ui/components/message.h>

static void OpenMessage(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
    LCDesign_OpenInfoMessage(L"This is a normal message", 3000);
}

// ... other code

    LCUI_Widget btn = LCUIWidget_GetById("btn-open-message");
    Widget_BindEvent(btn, "click", OpenMessage, NULL, NULL);

// ... other code
```

## Other types of message

Messages of success, error and warning types.

``` embedded-xml
<w class="button-container">
  <button ref="open-success-message" class="btn">Success</button>
  <button ref="open-error-message" class="btn">Error</button>
  <button ref="open-warning-message" class="btn">Warning</button>
</w>
```

``` c
#include <LCUI.h>
#include <LCUI/gui/widget.h>
#include <LCDesign/ui/components/message.h>

static void OpenSuccessMessage(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
    LCDesign_OpenSuccessMessage(L"This is a success message", 3000);
}

static void OpenWarningMessage(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
    LCDesign_OpenWarningMessage(L"This is a warning message", 3000);
}

static void OpenErrorMessage(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
    LCDesign_OpenErrorMessage(L"This is a error message", 3000);
}

// ... other code

    LCUI_Widget btn;

    btn = LCUIWidget_GetById("btn-open-success-message");
    Widget_BindEvent(btn, "click", OpenSuccessMessage, NULL, NULL);

    btn = LCUIWidget_GetById("btn-open-warning-message");
    Widget_BindEvent(btn, "click", OpenWarningMessage, NULL, NULL);

    btn = LCUIWidget_GetById("btn-open-error-message");
    Widget_BindEvent(btn, "click", OpenErrorMessage, NULL, NULL);

// ... other code
```

## Customize duration

Customize message display duration to `10s`.

``` embedded-xml
<w class="button-container">
  <button ref="open-custom-duration-message" class="btn">Customized display duration</button>
</w>
```

``` c
#include <LCUI.h>
#include <LCUI/gui/widget.h>
#include <LCDesign/ui/components/message.h>

static void OpenMessage(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
    LCDesign_OpenSuccessMessage(L"This is a prompt message for success, "
                                L"and it will disappear in 10 seconds",
                                10000);
}

// ... other code

    LCUI_Widget btn = LCUIWidget_GetById("btn-open-message");
    Widget_BindEvent(btn, "click", OpenMessage, NULL, NULL);

// ... other code
```

## Message with loading indicator

Display a global loading indicator, which is dismissed by itself asynchronously.

``` embedded-xml
<w class="button-container">
  <button ref="open-loading-message" class="btn">Display a loading indicator</button>
</w>
```

``` c
#include <LCUI.h>
#include <LCUI/gui/widget.h>
#include <LCDesign/ui/components/message.h>

static void OpenMessage(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
    LCDesign_OpenLoadingMessage(L"Action in progress..", 3000);
}

// ... other code

    LCUI_Widget btn = LCUIWidget_GetById("btn-open-message");
    Widget_BindEvent(btn, "click", OpenMessage, NULL, NULL);

// ... other code
```
