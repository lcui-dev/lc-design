#define ID_SIDEBAR_LINKS	"demo-sidebar-links"
#define ID_NAVBAR_LINKS		"demo-navbar-links"
#define ID_LINK_NAV_HOME	"navbar-link-home"
#define ID_LINK_GETTING_STARTED	"doc-link-getting-strted"

typedef enum NavigationPointId {
	NAV_HOME,
	NAV_DOCS,
	NAV_TOTAL_NUM
} NavigationPointId;


void ActiveLink( LCUI_Widget parent, const char *link_id );

void Navigation_Init( void );

void DocumentationView_Init( void );
void DocumentationView_Free( void );
void HomeView_Init( void );
void HomeView_Free( void );
