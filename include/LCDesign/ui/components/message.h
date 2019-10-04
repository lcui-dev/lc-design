#ifndef LCDESIGN_MESSAGE_H
#define LCDESIGN_MESSAGE_H

typedef struct LCDesign_MessageConfigRec_ {
	/** Customized Icon */
	LCUI_Widget icon;

	/** content of the message */
	const wchar_t *content;

	/** time(milliseconds) before auto-dismiss, don't dismiss if set to 0 */
	long duration;
} LCDesign_MessageConfigRec, *LCDesign_MessageConfig;

LCUI_API void LCDesign_SetMessageContainer(LCUI_Widget w);

LCUI_API LCUI_Widget LCDesign_OpenMessage(LCDesign_MessageConfig config);

LCUI_API void LCDesign_CloseMessage(LCUI_Widget message);

LCUI_API LCUI_Widget LCDesign_OpenSuccessMessage(const wchar_t *content,
						 long duration);

LCUI_API LCUI_Widget LCDesign_OpenInfoMessage(const wchar_t *content,
					      long duration);

LCUI_API LCUI_Widget LCDesign_OpenWarningMessage(const wchar_t *content,
						 long duration);

LCUI_API LCUI_Widget LCDesign_OpenErrorMessage(const wchar_t *content,
					       long duration);

LCUI_API LCUI_Widget LCDesign_OpenLoadingMessage(const wchar_t *content,
						 long duration);

#endif
