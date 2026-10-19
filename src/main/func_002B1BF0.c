#pragma cplusplus on
#include "types.h"
#include "guarded_new_init.h"

/* Factory: allocate, run the base constructor, set the vtable and members. */
extern "C" { char D_004ABF30[] = "guiWidget.hh"; }
DEFINE_GUARDED_NEW_VT_INIT(GuiQuickChat_Create, 0x5C, D_004ABF30, GuiWidget_ctor, D_004DDE60,
                           GN_W(0x48, 0))
