#include "types.h"
typedef struct { char p0[0x255C]; int state; char p2560[0x2C]; int last; } S449800;
extern int Lobby_GetTime(void);
extern void func_00449D20(S449800*, int);
extern void func_0044A290(S449800*);
extern int D_00497800;
extern int D_00497818;
#pragma push
#pragma opt_common_subs off
void func_00449800(S449800* s, int arg1)
{
    int last = s->last;
    int dt = Lobby_GetTime() - last;
    if (s->state == 7) {
        if (last == 0 || dt > D_00497800) {
            func_00449D20(s, arg1);
            func_0044A290(s);
            s->last = Lobby_GetTime();
        }
    } else if (last == 0 || dt > D_00497818) {
        func_00449D20(s, arg1);
        s->last = Lobby_GetTime();
    }
}
#pragma pop
