#include "types.h"
typedef struct { char p0[8]; int id; char pc[4]; } Slot45;
typedef struct { Slot45 e[8]; char p80[4]; unsigned char sel; } Slots45;
typedef struct { char p[0x3524]; Slots45* s; } Gm45;
typedef struct { char p[0x30]; Gm45* g; } Root45;
typedef struct { char p[0x70]; PtrVec vec; char p7c[0x14]; int idx; char p94[0x48]; int vis; } W45C760;
extern Root45* D_004FFC0C;
extern int D_00497B18;
extern int WeaponInv_SlotOfItem(int);
extern void PtrVec_PushBack_1C1080(PtrVec*, int*);
extern int func_0045C960(Iter*, Iter*);
extern Iter* func_0045C980(Iter*);
extern Word* func_0045C9A0(Word*, Iter*);
extern int* func_0045C9B0(Iter*);
extern void func_0045C9C0(Iter*, PtrVec*);
extern void func_0045C9E0(Iter*, PtrVec*);
extern Word* func_0045C9F0(Word*, Iter*);
extern void func_0045CA00(Iter*, PtrVec*);
static inline Word* find45(Word* out, Iter* b, Iter* e, int* v)
{
    while (func_0045C960(b, e)) {
        if (*v == *func_0045C9B0(b)) {
            func_0045C9A0(out, b);
            return out;
        }
        func_0045C980(b);
    }
    func_0045C9A0(out, e);
    return out;
}
void GuiGameScreen_GatherWeapons(W45C760* w)
{
    Slots45* s = D_004FFC0C->g->s;
    int cur;
    int start, i, n;
    cur = s->sel != 6 ? s->e[s->sel].id : -1;
    w->vec.count = 0;
    w->idx = -1;
    start = cur != -1 ? (unsigned char)WeaponInv_SlotOfItem(cur) : 0;
    i = start;
    n = 0;
    do {
        int item;
        Word found;
        Word endc;
        Iter tmp;
        Iter b;
        Iter e; Word* r;
        if ((item = s->e[i & 0xFF].id) != -1) {
            func_0045CA00(&tmp, &w->vec);
            func_0045C9F0(&endc, &tmp);
            func_0045C9E0(&b, &w->vec);
            func_0045C9C0(&e, &w->vec);
            if (r = find45(&found, &b, &e, &item), r->value == endc.value) {
                PtrVec_PushBack_1C1080(&w->vec, &item);
                if (cur == item) w->idx = n;
                n++;
            }
        }
        i++;
        if (i >= 6) i = 0;
    } while (i != start);
    PtrVec_PushBack_1C1080(&w->vec, &D_00497B18);
    if (w->idx == -1) w->idx = w->vec.count - 1;
    w->vis = w->vec.count < 5 ? w->vec.count : 5;
}