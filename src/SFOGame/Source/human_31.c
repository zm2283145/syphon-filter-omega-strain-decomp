/*
 * SFOGame/Source/human: 5 files, 0018C620-0018C770
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0018C620 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { void* p; int id; } H_18C620;
typedef struct { int pad0; unsigned char state; char pad5[0x3B]; int id; } O_18C620;
static inline void Make_18C620(H_18C620* h, O_18C620* o)
{
    int* id = &o->id;
    h->p = (*id == -1) ? o : 0;
    h->id = *id;
}
void nSka_GetPlaybackGroupId(H_18C620* out, O_18C620* o)
{
    H_18C620 a;
    H_18C620 b;
    H_18C620* r;
    unsigned char ok = 1;
    if (o->state != 0 && o->state != 1) ok = 0;
    if (ok) {
        Make_18C620(&a, o);
        r = &a;
    } else {
        b.p = 0;
        b.id = -1;
        r = &b;
    }
    out->p = r->p;
    out->id = r->id;
}
static inline void merge_flush_func_0018C620(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0018C620 */

/* merge_units: begin func_0018C6A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* func_0018C6A0(char* self) {
    return self + 52;
}

int cSkaAnimationSet_GetNode_int(char* self, int i) {
    return (*(int**)(self + 60))[i];
}
static inline void merge_flush_func_0018C6A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0018C6A0 */

/* merge_units: begin func_0018C6D0 */
#pragma push /* merge_units */
typedef struct { Q a; Q b; Q c; } MR_18C6D0;
static inline void QCopy_18C6D0(void* d0, void* s0) { int n = 3; void* d = d0; void* s = s0;
    asm {
        .set noreorder
    lp:
        lq $v1, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq $v1, -0x10(d)
        .set reorder
    }
}
MR_18C6D0* cString16N_3_ctor_cString16NR(MR_18C6D0* d, MR_18C6D0* s)
{
    QCopy_18C6D0(d, s);
    return d;
}
static inline void merge_flush_func_0018C6D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0018C6D0 */

/* merge_units: begin func_0018C700 */
#pragma push /* merge_units */
#include "human_types.h"

extern void std_tree_pair_cString16N_value_compare_cAllocator_pair_find_cString16NR(int*, int, int);

/* Tree iterator dereference: value stored at node +0x40. */
char* cAssocArray_cString16N_3_int_ConstIterator_opMul(Iter* it) {
    return (char*)it->p + 64;
}

int cAssocArray_cString16N_3_int_ConstIterator_opNe(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

void cAssocArray_cString16N_3_int_End(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* Tree lookup wrapper returning the found iterator through out. */
void cAssocArray_cString16N_3_int_Find(int* out) {
    int it[1];
    int a1, a2;

    std_tree_pair_cString16N_value_compare_cAllocator_pair_find_cString16NR(it, a1, a2);
    *out = it[0];
}
static inline void merge_flush_func_0018C700(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0018C700 */

/* merge_units: begin func_0018C770 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" int sprintf(void *, const void *, ...);
struct H_18C770 { int v; };
struct Act_18C770 {
    int id;
    char pad04[0xC];
    __int128 mask;
    int w20;
    H_18C770 h24;
    char pad28[8];
    int w30, w34, w38;
    char pad3C[0x0C];
    char memberA[0x9C];
    char memberB[0x9C];
    int w180;
    short h184;
    unsigned char b186;
};
struct Msg_18C770 {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag;
    char pad021[0x57];
    char partA[0x9C];
    char partB[0xAC];
};
struct Ctl_18C770 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); 
    virtual int v19();
};
struct Actor_18C770 {
    char pad00[0xC];
    unsigned int flags;
    char pad10[0x58 - 0x10];
    Ctl_18C770* ctl;
};
extern "C" {
extern char g_Game[];
extern char D_004DAE10[];
extern char D_0049DC10[];
extern char g_LevelDirName[];
extern unsigned char g_IsMultiplayer;
void cFileMan_ctor_void(void* m);
void cFileMan_dtor(void* part, int flags);
void cMessage_dtor(void* msg, int flags);
void QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int flags);
int cAgentData_GetCommander(void* o);
void cSndFx_SetSndFx(void* action, int kind, char* name, int a, int b);
void SoundMsg_WrapAction(Msg_18C770* msg, void* action);
}
static inline bool HasCtl(Actor_18C770* a)
{
    bool ok = false;
    if (a->ctl && a->ctl->v19()) ok = true;
    return ok;
}
#pragma opt_propagation off
extern "C" void cHuman_PlayQuip(Actor_18C770* actor, int b)
{
    Act_18C770 act;
    char buf[32];
    Act_18C770* p; int n; char* pb; char* pa;
    p = &act;
    act.h24.v = -2;
    act.w20 = 0;
    pa = act.memberA;
    cFileMan_ctor_void(pa);
    pb = act.memberB;
    cFileMan_ctor_void(pb);
    p->id = -1;
    p->mask = -1;
    p->w20 = 0;
    { H_18C770 h; H_18C770* hp = &h; h.v = -1; p->h24 = *hp; }
    p->w30 = 0;
    p->w34 = 0;
    p->w38 = 0;
    p->h184 = -1;
    p->w180 = 0;
    p->b186 = 0;
    n = cAgentData_GetCommander(g_LevelDirName);
    if (n > 0) {
        Msg_18C770 m;
        int idx;
        if (g_IsMultiplayer) {
            if (HasCtl(actor)) idx = ((actor->flags & 0x7F000000) >> 24) - 1;
            else idx = -1;
        } else {
            idx = 0;
        }
        sprintf(buf, D_0049DC10, n, b, idx + 1);
        cSndFx_SetSndFx(&act, 4, buf, 0, 0);
        SoundMsg_WrapAction(&m, &act);
        m.flag = 1;
        QueueMessage_cMessageR_cSystemP_int(&m, g_Game, 1);
        m.vtbl = D_004DAE10;
        cFileMan_dtor(m.partB, -1);
        cFileMan_dtor(m.partA, -1);
        cMessage_dtor(&m, 0);
    }
    cFileMan_dtor(pb, -1);
    cFileMan_dtor(pa, -1);
}
static inline void merge_flush_func_0018C770(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0018C770 */
