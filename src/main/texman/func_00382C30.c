#include "types.h"
typedef struct { char p0[0x60]; signed char f60; signed char f61; unsigned char active; } E382C30;
typedef struct N382C30 { int p0; struct N382C30* next; int key; } N382C30;
typedef struct { char p0[4]; int state; E382C30** items; char pC[0x410]; int count; char list420[4]; } M382C30;
extern void func_00380250(N382C30** out, int it);
extern int func_00380260(void* list);
extern N382C30* func_00380270(void* list, int off);
extern void func_00383560(int* out, void* list, N382C30** it);
#pragma push
#pragma opt_common_subs off
void func_00382C30(M382C30* m, int idx)
{
    int r[1];
    N382C30* it[1];
    N382C30* end[1];
    int off;
    E382C30* e;
    N382C30* n;

    off = idx * 4;
    e = *(E382C30**)((char*)m->items + off);
    if (e->active != 0) {
        e->active = 0;
        (*(E382C30**)((char*)m->items + off))->f60 = 0;
        (*(E382C30**)((char*)m->items + off))->f61 = 0;
        n = func_00380270(m->list420, off)->next;
        func_00380250(end, func_00380260(&m->count));
        if (n != end[0]) {
loop:
            if (idx == n->key) {
                it[0] = n;
                func_00383560(r, &m->count, it);
            } else {
                n = n->next;
                func_00380250(end, func_00380260(&m->count));
                if (n != end[0]) goto loop;
            }
        }
        if (m->count == 0) m->state = 0x4000;
    }
}
#pragma pop
