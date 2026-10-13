#include "types.h"
typedef struct { char p0[0xC4]; char listA[0x70]; char listB[0x2428]; int state; char p2560[0x2C]; int last; } S44A0D0;
extern int Lobby_GetTime(void);
extern void func_00449A00(S44A0D0*);
extern void func_00449D20(S44A0D0*, int);
extern void func_0044A290(S44A0D0*);
extern int func_00450A90(void*, int, int);
extern int D_00497800;
extern int D_00497818;
static inline void Tick44A0D0(S44A0D0* s, int arg1)
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
#pragma push
int func_0044A0D0(S44A0D0* s, int key, int update)
{
    if (update) {
        func_00449A00(s);
        Tick44A0D0(s, 1);
    }
    if (func_00450A90(s->listB, key, 0)) return 1;
    return func_00450A90(s->listA, key, 0) != 0;
}
#pragma pop
