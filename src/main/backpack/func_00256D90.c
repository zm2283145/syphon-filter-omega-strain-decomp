#pragma cplusplus on
#include "types.h"

/* Backpack_RestoreCrateSnapshots: copy every crate snapshot (Backpack_SnapshotCrates) back into
 * the backpack with the same id and give it a runtime hotbox if it has none. */

struct RT { char pad[0x94]; int id; };
struct Crate {
    char pad0[0xC];
    int id;
    char pad10[0x60 - 0x10];
    char pad60[4];
    char body[0x27C];
    int f2E0, f2E4, f2E8, f2EC;
    char pad2F0[0x2FC - 0x2F0];
    RT* rt;
};

struct Snapshot {
    int id;
    char body[0x27C];
    int f280, f284, f288, f28C;
};

struct CrateVec {
    int pad0;
    int count;
    Crate** items;
};

struct Raw { int p; };
struct SNode { SNode* prev; SNode* next; Snapshot* snap; };
extern "C" {
extern CrateVec* g_BackpackList;
extern char D_004F7F48[];
Crate** func_00256D80(CrateVec* v, int i);
void Backpack_RestoreCrateSnapshots(void);
extern int g_HotboxTracker;
RT* Hotbox_CreateRuntime(int tracker, Crate* c, int flag, int big);
Raw List_Begin(void* list);
Raw func_00256B20(void* list);
void func_00256B30(SNode** out, const Raw& r);
void func_00256B10(SNode** out, const Raw& r);
}

/* byte/quadword copy macro (func_001C3C50.c's, without the nop after the alignment branch, as
 * retail has it here); volatile because retail recomputes the index scaling after the copy (a
 * non-volatile block lets MW keep i*4 in a saved register) */
static inline void MemCopy(void* dst, void* src, int n)
{
    int t;
    int m;
    asm volatile {
        .set noreorder
        blez n, done
        andi m, src, 0xF
        andi t, dst, 0xF
        or m, m, t
        andi t, n, 0xF
        or m, m, t
        nop
        bgtz m, bytes
    quads:
        lq t, 0(src)
        addiu dst, dst, 0x10
        addi n, n, -0x10
        addiu src, src, 0x10
        bgtz n, quads
        sq t, -0x10(dst)
        b done
        nop
    bytes:
        lb t, 0(src)
        addiu dst, dst, 1
        addi n, n, -1
        addiu src, src, 1
        bgtz n, bytes
        sb t, -1(dst)
    done:
        .set reorder
    }
}

struct SIt {
    SNode* p;
    SIt() {}
    SIt(const SIt& o) { p = o.p; }
    SIt& operator=(const SIt& o) { p = o.p; return *this; }
};

void Backpack_RestoreCrateSnapshots(void)
{
    CrateVec* list = g_BackpackList;
    SIt it;
    SIt old;
    SNode* end;
    SNode* b;
    SIt r;
    SIt t;
    int i;
    func_00256B30(&b, List_Begin(D_004F7F48));
    it.p = b;
    while ((func_00256B10(&end, func_00256B20(D_004F7F48)), it.p != end)) {
        for (i = 0; i < list->count; i++) {
            Crate* c = *func_00256D80(list, i);
            Snapshot* s = it.p->snap;
            if (s->id == c->id) {
                { int v = it.p->snap->f280; list->items[i]->f2E0 = v; }
                { int v = it.p->snap->f284; list->items[i]->f2E4 = v; }
                { int v = it.p->snap->f288; list->items[i]->f2E8 = v; }
                { int v = it.p->snap->f28C; list->items[i]->f2EC = v; }
                MemCopy((*func_00256D80(list, i))->body, it.p->snap->body, sizeof(it.p->snap->body));
                if (!list->items[i]->rt) {
                    Crate* k = *func_00256D80(list, i);
                    if (!k->rt) {
                        RT* q;
                        int id;
                        k->rt = Hotbox_CreateRuntime(g_HotboxTracker, k, 0, 1);
                        id = k->id;
                        q = k->rt;
                        q->id = id;
                    }
                }
            }
        }
        /* it++ (post-increment, result kept): t = it, advance, r = t, old = r */
        t = it;
        it.p = it.p->next;
        r = t;
        old = r;
    }
}
