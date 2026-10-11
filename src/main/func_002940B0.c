#pragma cplusplus on
#include "types.h"
#include "guarded_new_init.h"

extern "C" char D_004DD460[];
extern "C" char D_004DD400[];

/* Factory: allocate and construct a three-level widget. */
DEFINE_GUARDED_NEW_VT_INIT(func_002940B0, 0x80, D_004A9E10, GuiWidget_ctor, D_004E1220,
                           GN_W(0x48, -2); GN_VT(D_004DD460); GN_F(0x78, 10.0f);
                           GN_B(0x7C, 0); GN_VT(D_004DD400))
