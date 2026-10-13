#include "types.h"
typedef struct NetConnInfo_h5 { int session; int status; } NetConnInfo_h5;
extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_005721C8;
extern unsigned char D_005723C8;
extern int D_00572470;
extern int D_00572478;
extern signed char D_005724B0;
extern int Gui_GetScreenStack(void);
extern void func_0041E0F0(int a, int b, int c, int d, int e);
extern void func_002EBAF8(int* out, int session);
extern void func_002EBBA0(int session, int* out);
static inline int LocalSlot_h5(int session)
{
    if (D_005721C8) {
        if (D_00494178 == -1) {
            func_002EBAF8(&D_00494178, session);
        }
        return D_00494178;
    }
    return 0;
}
void func_00429790(NetConnInfo_h5* info)
{
    int slot[2];
    if (!D_005723C8) {
        D_005723C8 = 1;
    }
    D_005721A8 = info->session;
    if (info->status == 3) {
        D_005724B0 = 7;
        if (Gui_GetScreenStack()) {
            func_0041E0F0(Gui_GetScreenStack(), Gui_GetScreenStack(), 0x1E, 0, (int)"F_TO_CONNECT");
        }
    } else {
        D_005724B0 = 6;
        D_005721C8 = 1;
        func_002EBAF8(slot, info->session);
        D_00494178 = slot[0];
        func_002EBBA0(info->session, slot);
        if (slot[0] == LocalSlot_h5(D_005721A8) && Gui_GetScreenStack()) {
            func_0041E0F0(Gui_GetScreenStack(), Gui_GetScreenStack(), 0x1E, 1, 0);
        }
    }
    D_00572470 = 0;
    D_00572478 = 0;
    D_005723C8 = 0;
}