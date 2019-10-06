#include <LCUI.h>
#include <LCDesign.h>

static LCUI_WidgetPrototype message_view_proto;

static void OpenNormalMessage(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
	LCDesign_OpenInfoMessage(L"This is a normal message", 3000);
}

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

static void OpenCustomDurationMessage(LCUI_Widget w, LCUI_WidgetEvent e,
				      void *arg)
{
	LCDesign_OpenSuccessMessage(L"This is a prompt message for success, "
				    L"and it will disappear in 10 seconds",
				    10000);
}

static void OpenLoadingMessage(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
	LCDesign_OpenLoadingMessage(L"Action in progress..", 3000);
}

static void MessageView_OnReady(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
	Dict *dict;
	LCUI_Widget btn;

	dict = Widget_CollectReferences(w);
	btn = Dict_FetchValue(dict, "open-normal-message");
	Widget_BindEvent(btn, "click", OpenNormalMessage, NULL, NULL);

	btn = Dict_FetchValue(dict, "open-success-message");
	Widget_BindEvent(btn, "click", OpenSuccessMessage, NULL, NULL);

	btn = Dict_FetchValue(dict, "open-warning-message");
	Widget_BindEvent(btn, "click", OpenWarningMessage, NULL, NULL);

	btn = Dict_FetchValue(dict, "open-error-message");
	Widget_BindEvent(btn, "click", OpenErrorMessage, NULL, NULL);

	btn = Dict_FetchValue(dict, "open-custom-duration-message");
	Widget_BindEvent(btn, "click", OpenCustomDurationMessage, NULL, NULL);

	btn = Dict_FetchValue(dict, "open-loading-message");
	Widget_BindEvent(btn, "click", OpenLoadingMessage, NULL, NULL);

	Dict_Release(dict);
	Widget_UnbindEvent(w, "ready", MessageView_OnReady);
}

static void MessageView_OnInit(LCUI_Widget w)
{
	Widget_BindEvent(w, "ready", MessageView_OnReady, NULL, NULL);
}

void UI_InitMessageView(void)
{
	message_view_proto = LCUIWidget_NewPrototype("message-view", NULL);
	message_view_proto->init = MessageView_OnInit;
}
