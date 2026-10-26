#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
/* cAiTargetTransfer_Put: load an AI record: copy its 48-byte header in, resolve the
 * target handle (registering it for visibility when it has no controller),
 * and re-create up to four queued entries whose objects still exist. */
struct V {
    float x, y, z, w;
    V() {}
    /* lq/sq: 128-bit quadword move has no C equivalent (asm). */
    V& operator=(const V& o) { void* d = this; __int128 q; const void* s = &o; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct IdV { int v; };
struct Obj;
struct Handle { Obj* object; int id; };
struct SRec {
    Handle h;
    IdV id;
    V v10;
    signed char b20;
    float f24, f28, f2C, f30, f34;
    unsigned char b38, b39, b3A, b3B, b3C;
};
struct Obj { char p0[0xC]; int id; char p10[0x58 - 0x10]; void* ctrl; };
struct SNode { int pad; SNode* next; SRec* value; };
struct It { SNode* p; It() {} It(const It& o) { p = o.p; } It& operator=(const It& o) { p = o.p; return *this; } };
struct SWord { int v; };
struct AiRec { char p0[0x30]; char list[0x10]; Handle h; };
extern "C" {
Obj* ActorRef_Copy(Handle* h);
Obj* Object_LookupById(int* id);
void TargetVis_Register(void* mgr, Obj* o);
void Alloc_Lock(int);
void Alloc_Unlock(int);
void* Mem_Alloc(int, int, void*, int);
void List_PushBack_16CEE0(void* list, SRec* const* v);
extern char D_0049C650[];
extern char g_TargetVisMgr[];
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
void cAiTargetTransfer_Put(void* src, AiRec* dst, int* hid, SRec* recs);
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
static inline const int& IdOf(Obj* p) { if (p) return p->id; int m = -1; return m; }
static inline void Set(Handle* h, Obj* o) { h->object = o; h->id = IdOf(o); }
static inline SRec* NewRec() {
    void* m;
    if (g_ProfileLockEnabled) Alloc_Lock(9);
    g_ProfileLockDepth++;
    m = Mem_Alloc(0, 0x40, D_0049C650, 0xF6);
    if (g_ProfileLockEnabled) Alloc_Unlock(9);
    g_ProfileLockDepth--;
    if (m) { SRec* r = (SRec*)m; r->h.id = -2; r->h.object = 0; r->id.v = -1; }
    return (SRec*)m;
}
static inline int IsNullNV(void* p) { return (p != 0) ^ 1; }
static inline int EqNV(int a, int b) { return (unsigned)(a ^ b) < 1; }
static inline Obj* WGet(Handle* h) { bool ok = 1; if (!IsNullNV(h->object) && !EqNV(h->object->id, h->id)) ok = 0; unsigned char k = ok; return k ? h->object : 0; }

void cAiTargetTransfer_Put(void* src, AiRec* dst, int* hid, SRec* recs)
{
    QCopy(dst, src, 0x30);
    if (*hid != -1) {
        Obj* o = Object_LookupById(hid);
        Set(&dst->h, o);
        if (WGet(&dst->h) && !WGet(&dst->h)->ctrl)
            TargetVis_Register(g_TargetVisMgr, WGet(&dst->h));
    } else {
        Set(&dst->h, 0);
    }
    SRec* e;
    /* dead address-taken local: retail reserves an unused slot below e */
    int u;
    int* pu = &u;
    for (int i = 0; i < 4; i++) {
        if (recs[i].id.v != -1) {
            Obj* o = Object_LookupById(&recs[i].id.v);
            if (o) {
                e = NewRec();
                *e = recs[i];
                Set(&e->h, o);
                List_PushBack_16CEE0(dst->list, &e);
            }
        }
    }
}
