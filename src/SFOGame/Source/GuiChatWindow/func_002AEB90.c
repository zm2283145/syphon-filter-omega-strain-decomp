#pragma cplusplus on
#include "types.h"
#include "guarded_new_init.h"

/* Factory: allocate, run the base constructor, set the vtable and members. */
extern "C" { char D_004ABBA8[] = "guiWidget.hh"; }
DEFINE_GUARDED_NEW_VT_INIT(ConcreteWidgetClassRep_GuiNetContacts_Create, 0x168, D_004ABBA8, GuiMissionLobbyScreen_ctor, D_004DDC20,
                           GN_W(0x84, 4); GN_W(0x160, 0); GN_W(0x164, 0))
