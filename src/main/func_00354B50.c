#pragma cplusplus on
#include "types.h"

enum { MODE_0, MODE_1, MODE_2 };

typedef struct { int id; char pad4[4]; unsigned char state; char pad9[0x1C - 9]; } E4B50;

struct L4B50 {
    int a0;
    int count;
    E4B50* data;
    unsigned char aC;
    int size() const { return count; }
};

typedef struct { char pad0[0x48]; void* tbl; char pad4C[0x84 - 0x4C]; unsigned char kind; char pad85[3]; int arg; } O4B50;

extern "C" char D_004FFB50[];
extern "C" const char* D_0048C160[];
extern "C" char D_004BB0D0[];
extern "C" void func_00296F20(L4B50* l);
extern "C" void func_00299270(L4B50* l, int flags);
extern "C" void* Agent_GetSelected(void* list, int idx);
extern "C" void func_00333260(void* ag, int a, int b, L4B50* l);
extern "C" void* func_00336060(void* ag, const char* name);
extern "C" void func_003353F0(void* ag, void* x, L4B50* l);
extern "C" int Loc_LookupText(const char* key);
extern "C" void func_00421290(void* t, int id, int i, int mode);

/* The inline size() keeps the loop-entry test on the stack slot; enum constants keep the 0/1 select as branches. */
extern "C" void func_00354B50(O4B50* self)
{
    void* ag = Agent_GetSelected(D_004FFB50, -1);
    L4B50 l;
    int text;
    int i;
    func_00296F20(&l);
    l.aC = 1;
    if (self->kind == 6) {
        const char* name = 0;
        void* x;
        if (self->arg >= 0 && self->arg < 17)
            name = D_0048C160[self->arg];
        if (!name) {
            func_00299270(&l, 0);
            return;
        }
        x = func_00336060(ag, name);
        if (!x) {
            func_00299270(&l, 0);
            return;
        }
        func_003353F0(ag, x, &l);
    } else {
        func_00333260(ag, self->kind, self->arg, &l);
    }
    text = Loc_LookupText(D_004BB0D0);
    for (i = 0; i < l.size(); i++) {
        E4B50* e = (E4B50*)((int)l.data + i * sizeof(E4B50));
        int id = text;
        int mode;
        if (e->state == 0) {
            mode = MODE_2;
        } else {
            id = e->id;
            mode = e->state == 2 ? MODE_0 : MODE_1;
        }
        func_00421290(self->tbl, id, i, mode);
    }
    func_00299270(&l, 0);
}
