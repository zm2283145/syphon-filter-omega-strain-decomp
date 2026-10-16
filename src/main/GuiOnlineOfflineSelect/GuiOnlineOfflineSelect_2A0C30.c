#pragma cplusplus on
#include "types.h"
#include "guarded_new_init.h"

/* Factory: allocate, run the base constructor, set the vtable and members. */
extern "C" { char D_004AAF38[] = "guiWidget.hh"; }
DEFINE_GUARDED_NEW_VT_INIT(GuiOnlineOfflineSelect_Create, 0x4C, D_004AAF38, GuiWidget_ctor, D_004DD6B0,
                           GN_B(0x48, 0))
