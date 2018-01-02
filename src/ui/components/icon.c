#include <stdio.h>
#include <LCUI_Build.h>
#include <LCUI/LCUI.h>
#include "ui/components.h"

#define CLASS_NAME		"icon"
#define CLASS_PREFIX_NAME	"icon-"

static struct LCUIEx_IconModule {
	LCUI_WidgetPrototype proto;
} self;

static void Icon_Init( LCUI_Widget w )
{
	self.proto->proto->init( w );
	Widget_AddClass( w, CLASS_NAME );
}

int Icon_SetName( LCUI_Widget w, const char *name )
{
	char class_name[256];
	strcpy( class_name, CLASS_PREFIX_NAME );
	strcat( class_name, name );
	return Widget_AddClass( w, class_name );
}

static void Icon_SetAttr( LCUI_Widget w, const char *name,
			  const char *value )
{
	if( strcmp( name, "name" ) == 0 ) {
		Icon_SetName( w, value );
	}
}

void LCUIEx_InitIcon( void )
{
	self.proto = LCUIWidget_NewPrototype( "icon", "textview" );
	self.proto->init = Icon_Init;
	self.proto->setattr = Icon_SetAttr;
}
