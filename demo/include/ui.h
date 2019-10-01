#define ID_SIDEBAR_LINKS "demo-sidebar-links"
#define ID_NAVBAR_LINKS "demo-navbar-links"
#define ID_LINK_NAV_HOME "navbar-link-home"
#define ID_LINK_NAV_DOCS "navbar-link-docs"
#define ID_LINK_GETTING_STARTED "doc-link-getting-strted"

typedef enum NavigationPointId {
	NAV_NONE,
	NAV_HOME,
	NAV_DOCS,
	NAV_TOTAL_NUM
} NavigationPointId;

void ActiveLink(LCUI_Widget parent, const char *link_id);

void Navbar_Init(void);
void Navigation_Init(void);

void DocumentationView_Init(void);
void DocumentationView_Free(void);
void HomeView_Init(void);
void HomeView_Free(void);

void UI_InitMessageView(void);
void UI_InitNotificationView(void);
