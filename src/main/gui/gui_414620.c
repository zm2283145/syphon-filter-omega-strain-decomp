/*
 * main/gui: 2 files, 00414620-00414790
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00414620 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


extern "C" {
int Mem_Free(...);                      
extern char D_0049AE90;
extern unsigned char D_00533880;
}
extern "C" void func_00414620(char * arg0, int arg1, int arg2, char *arg3, char * arg4) {
    char * temp_s2;

    {
        AllocGuard g;
    if ((arg2 != 0) && (arg0 != NULL) && (arg0 != NULL) && (F_(arg0, 0x0, int) & 1)) {
        temp_s2 = (char *)(F_(arg0, 0x8, int));
        if (temp_s2 != NULL) {
            {
                AllocGuard g;
            Mem_Free(0, temp_s2, &D_0049AE90, 0x64);
            }
        }
    }
    Mem_Free(arg1, arg0, arg3, arg4);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00414620 */

/* merge_units: begin func_00414790 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

extern int D_00571FB0;
extern int D_00571FB8;

int Gui_GetScreenList(void) {
    return D_00571FB8;
}

int Gui_GetScreenStack(void) {
    return D_00571FB0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00414790 */
