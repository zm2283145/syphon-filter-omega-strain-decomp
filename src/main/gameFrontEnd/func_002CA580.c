#include "types.h"
typedef struct { char p0[0x255C]; int state; } L2CA580;
extern unsigned char D_0051EEB0;
extern unsigned char D_005723B8;
extern L2CA580* DME_GetLobby(void);
extern void func_004536B0(L2CA580* l);
extern int func_00452FD0(L2CA580* l);
extern int Gui_GetScreenList(void);
extern void func_00419260(int mgr, float t);
extern void func_002CA6F0(void* s);
extern void func_002CA640(void* s, int v);
extern void func_00453B00(L2CA580* l, int v);
/* Lobby tick: when the session is ready either flags the pending state or starts the game screen. */
void func_002CA580(void* s)
{
    L2CA580* l;
    if (D_0051EEB0) return;
    l = DME_GetLobby();
    if (!l) return;
    func_004536B0(l);
    if (!func_00452FD0(l)) return;
    if (l->state == 10) {
        D_005723B8 = 1;
        return;
    }
    func_00419260(Gui_GetScreenList(), 0.0f);
    func_002CA6F0(s);
    func_002CA640(s, 1);
    func_00453B00(l, 1);
}
