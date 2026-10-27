#pragma cplusplus on
#include "types.h"
#include "guarded_new_init.h"

/* Factory: allocate, run the base constructor, set the vtable and members. */
extern "C" { char D_004A9660[] = "guiWidget.hh"; }
DEFINE_GUARDED_NEW_VT_INIT(ConcreteWidgetClassRep_GuiTitleScreen_Create, 0x54, D_004A9660, GuiWidget_ctor, D_004DD0A0,
                           GN_B(0x48, 0); GN_W(0x4C, 0); GN_W(0x50, -2))
