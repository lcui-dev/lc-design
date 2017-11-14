#define ID_SIDEBAR_LINKS	"demo-sidebar-links"
#define ID_NAVBAR_LINKS		"demo-navbar-links"
#define ID_NAV_LINK_HOME	"navbar-link-home"

typedef enum NavigationPointId {
	NAV_HOME,
	NAV_DOCS,
	NAV_TOTAL_NUM
} NavigationPointId;

void Navigation_Init( void );

void DocumentationView_Init( void );
void DocumentationView_Free( void );
void HomeView_Init( void );
void HomeView_Free( void );
