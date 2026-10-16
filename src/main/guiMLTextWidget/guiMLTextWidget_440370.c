/*
 * main/guiMLTextWidget: 2 files, 00440370-00440450
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00440370 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
extern "C" unsigned char D_005723C8;
#pragma define_section REENT_DTOR ".dtors_drop" far_absolute RX
struct ReentGuard {
    ReentGuard() { if (!D_005723C8) D_005723C8 = 1; }
    __declspec(weak) __declspec(REENT_DTOR) ~ReentGuard() { D_005723C8 = 0; }
};typedef struct { int a, b, f8; } E440;
extern "C" {
extern int D_00494198;
extern int Gui_GetScreenStack(void);
extern void GuiWidget_SendEvent(int, int, int, int, int);
}
extern "C" int func_00440370(int a0, int a1, int a2, E440* ev) {
    ReentGuard g;
    if (ev->f8 == D_00494198) {
        if (Gui_GetScreenStack()) GuiWidget_SendEvent(Gui_GetScreenStack(), Gui_GetScreenStack(), 0x1E, 1, 0);
    } else {
        if (Gui_GetScreenStack()) GuiWidget_SendEvent(Gui_GetScreenStack(), Gui_GetScreenStack(), 0x1E, 0, (int)"F_TO_CONNECT");
    }
    return 12;
}
#pragma pop /* merge_units */
/* merge_units: end func_00440370 */

/* merge_units: begin func_00440450 */
#pragma push /* merge_units */
#include "message_pack.h"
extern int D_00583998;
extern void printf(char* s);
int NetLevelInfoMsg_Send(void* e, int a1, int* type, int a3, int a4, unsigned int sz, void* buf)
{
    int r = -1;
    if (sz >= 12 && buf) {
        char* b = (char*)buf;
        Event_PackHeader(e, a1, type, a3, a4, sz, buf);
        MP_I(b, 8) = MP_I(e, 0x24);
        if (type) {
            r = 12;
            *type = D_00583998;
        }
    }
    printf("\n\n*** cNetLevelInfoMsg: sending\n");
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_00440450 */
