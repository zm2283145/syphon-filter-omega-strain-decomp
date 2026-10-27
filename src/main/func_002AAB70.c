#pragma cplusplus on
#include "types.h"
#include "guarded_new_init.h"

extern "C" void SFOLobbyList_ctor(void* member);

/* Factory: allocate and construct a screen with a member list. */
extern "C" { char D_004AB8B8[] = "guiWidget.hh"; }
DEFINE_GUARDED_NEW_VT_INIT(GuiOnlineOptions_Create, 0xBC, D_004AB8B8, GuiLobbyScreen_ctor, D_004DDAF0,
                           SFOLobbyList_ctor((char*)p + 0xA0); GN_W(0x84, 5);
                           GN_W(0x88, 0); GN_W(0x90, 0); GN_W(0x8C, 0); GN_W(0x94, 0);
                           GN_W(0x9C, -1); GN_W(0x98, -1); GN_B(0x78, 0))
