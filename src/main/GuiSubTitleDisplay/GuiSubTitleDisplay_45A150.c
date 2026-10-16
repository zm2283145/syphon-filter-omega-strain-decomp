#pragma cplusplus on
#include "types.h"
struct Msg {
    int a;
    unsigned char b0, b1, b2, b3;
    float x, y, z;
    int d;
    unsigned char e0, e1;
    float f;
    int g;
    Msg() {}
};
struct Obj { char pad[0x59D]; unsigned char ready; };
struct Net { Obj* obj; unsigned char busy; };
extern "C" {
extern Net D_0055A830;
extern int D_004979A0;
extern Msg* func_0045A7A0(Msg*);
extern int func_0040DBB0(Net*, int);
extern int MemCardWrap_Read(Net*, int, void*, int);
extern int GameOptions_Diff(Msg*, Msg*);
extern void GameOptions_Apply(Msg*, int);
int func_0045A150(Msg* s);
}

int func_0045A150(Msg* s)
{
    Net* n = &D_0055A830;
    Msg m;
    func_0045A7A0(&m);
    if (((n->busy != 0) ^ 1) && n->obj->ready) {
        if (func_0040DBB0(n, D_004979A0) != sizeof(Msg)) {
            return 0;
        }
        if (MemCardWrap_Read(n, D_004979A0, &m, sizeof(Msg))) {
            int r;
            if (m.a != 1) {
                return 0;
            }
            r = GameOptions_Diff(s, &m);
            *s = m;
            GameOptions_Apply(s, r);
            return 1;
        }
    }
    return 0;
}

