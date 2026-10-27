#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
/* cAiTargetTransfer_Get: save an AI record: copy its 48-byte header out, the target
 * id, and up to four queued entries (missing ones get the invalid id). */
struct V {
    float x, y, z, w;
    V() {}
    /* lq/sq: 128-bit quadword move has no C equivalent (asm). */
    V& operator=(const V& o) { void* d = this; __int128 q; const void* s = &o; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct XY { float x, y; };
struct IdV { int v; };
struct SRec {
    XY xy;
    IdV id;
    V v10;
    signed char b20;
    float f24, f28, f2C, f30, f34;
    unsigned char b38, b39, b3A, b3B, b3C;
};
struct Obj { char p0[0xC]; int id; };
struct Handle { Obj* object; int id; };
struct SNode { int pad; SNode* next; SRec* value; };
struct It { SNode* p; It() {} It(const It& o) { p = o.p; } It& operator=(const It& o) { p = o.p; return *this; } };
struct SWord { int v; };
struct AiRec { char p0[0x30]; char list[0x10]; Handle h; };
extern "C" {
Obj* cSafePtr_cGOBJ_opCast_cGOBJPtr(Handle* h);
SWord std_list_deleter_voidPtr_begin_void_2(void* list);
It std_list_cTargetAwarenessPtr_generic_iterator_1_ctor(int v);
SWord std_list_cTargetAwarenessPtr_end_void_2(void* list);
It cConstLListIterator_cTargetAwarenessPtr_ctor(const SWord& w);
void cAiTargetTransfer_Get(void* dst, AiRec* src, int* id, SRec* recs);
/* function-local static "invalid id" (-1) and its first-use guard; the
 * storage lives in retail .data/.bss, so the guarded init is spelled out. */
extern int D_0049C588;
extern signed char D_004EE558;
}
/* quadword/byte block copy macro (asm: lq/sq and the alignment test) */
static inline void QCopy(void* dst0, void* src0, int n0)
{
    int n = n0; int t; int m; void* src = src0; void* dst = dst0;
    asm {
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
static inline int IsNullNV(void* p) { return (p != 0) ^ 1; }
static inline int EqNV(int a, int b) { return (unsigned)(a ^ b) < 1; }
static inline Obj* WGet(Handle* h) { bool ok = 1; if (!IsNullNV(h->object) && !EqNV(h->object->id, h->id)) ok = 0; unsigned char k = ok; return k ? h->object : 0; }

void cAiTargetTransfer_Get(void* dst, AiRec* src, int* id, SRec* recs)
{
    It it;
    QCopy(dst, src, 0x30);
    if (WGet(&src->h)) *id = cSafePtr_cGOBJ_opCast_cGOBJPtr(&src->h)->id; else { volatile int t = -1; *id = t; }
    it = std_list_cTargetAwarenessPtr_generic_iterator_1_ctor(std_list_deleter_voidPtr_begin_void_2(src->list).v);
    if (!D_004EE558) {
        D_0049C588 = -1;
        D_004EE558 = 1;
    }
    for (int i = 0; i < 4; i++) {
        It end = cConstLListIterator_cTargetAwarenessPtr_ctor(std_list_cTargetAwarenessPtr_end_void_2(src->list));
        if (it.p != end.p) {
            recs[i] = *it.p->value;
            it.p = it.p->next;
        } else {
            recs[i].id.v = D_0049C588;
        }
    }
}
