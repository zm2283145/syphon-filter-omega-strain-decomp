#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

/* Backpack_SnapshotCrates: drop the old crate snapshots, then snapshot every backpack in state 1
 * (its id, the four words at +0x2E0 and the 0x27C-byte body at +0x64) into the snapshot list
 * D_004F7F48 (Backpack_RestoreCrateSnapshots copies them back). */

struct Crate {
    char pad0[0xC];
    int id;
    char pad10[0x60 - 0x10];
    unsigned char state;
    char pad61[3];
    char body[0x27C];
    int f2E0, f2E4, f2E8, f2EC;
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

extern "C" {
extern CrateVec* g_BackpackList;
extern char D_004A7B50[];
extern char D_004F7F48[];
void cBackpack_PurgeCrateSaves(void);
void* Mem_Alloc(int pool, int size, char* file, int line);
void CrateSnapshot_Init(Snapshot* s);
Crate** std_vector_cBackpackPtr_opIndex(CrateVec* v, int i);
void CrateSnapshotList_Append(void* list, Snapshot** s);
void Backpack_SnapshotCrates(void);
}

/* byte/quadword copy macro (the copy loop of cLoader_AllocateAndFillAnimationBuffer.c); volatile here because retail
 * recomputes the index scaling after it (a non-volatile block lets MW keep i*4 in a saved register) */
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
        nop
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

/* the new snapshot pointer lives in memory (its address goes to the list append) */
union SnapRef { Snapshot* p; };

void Backpack_SnapshotCrates(void)
{
    CrateVec* list = g_BackpackList;
    int i;
    cBackpack_PurgeCrateSaves();
    for (i = 0; i < list->count; i++) {
        if (list->items[i]->state == 1) {
            SnapRef s;
            {
                Snapshot* p;
                {
                    AllocGuard g;
                    p = (Snapshot*)Mem_Alloc(0, sizeof(Snapshot), D_004A7B50, 0x1EA);
                }
                if (p) p->id = -1;
                s.p = p;
            }
            CrateSnapshot_Init(s.p);
            {
                Crate* c = *std_vector_cBackpackPtr_opIndex(list, i);
                Snapshot* d = s.p;
                d->id = c->id;
            }
            s.p->f280 = list->items[i]->f2E0;
            s.p->f284 = list->items[i]->f2E4;
            s.p->f288 = list->items[i]->f2E8;
            s.p->f28C = list->items[i]->f2EC;
            MemCopy(s.p->body, (*std_vector_cBackpackPtr_opIndex(list, i))->body, sizeof(s.p->body));
            CrateSnapshotList_Append(D_004F7F48, &s.p);
        }
    }
}
