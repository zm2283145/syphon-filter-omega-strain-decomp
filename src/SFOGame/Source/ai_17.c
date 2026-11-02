/*
 * SFOGame/Source/ai: 7 files, 0016E040-0016E860
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0016E040 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(cLList_cTargetAwarenessPtr_dtor, func_00135C90)
static inline void merge_flush_func_0016E040(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016E040 */

/* merge_units: begin func_0016E0A0 */
#pragma push /* merge_units */
typedef struct {
    char pad[0x18];
    int unk18;
    int unk1C;
    unsigned char lo : 4;
    unsigned char f4 : 1;
    unsigned char f5 : 1;
    unsigned char hi : 2;
    unsigned char f0 : 1;
    unsigned char rest : 7;
    char pad22[0xE];
    char coll[0xC];
    int owner;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
} Obj;
extern void std_list_deleter_voidPtr_ctor_void(void* coll);
extern void cAITarget_SetTarget(Obj* self, int a, int b);
extern void cAITarget_dtor(Obj* self);

/* Constructor: initialises the collection, ids and flag bits, then resets state. */
Obj* cAITarget_ctor(Obj* self, int owner)
{
    unsigned char off = 0;
    std_list_deleter_voidPtr_ctor_void(self->coll);
    self->owner = owner;
    self->unk44 = -2;
    self->unk40 = 0;
    self->unk4C = -2;
    self->unk48 = 0;
    self->unk1C = -1;
    cAITarget_SetTarget(self, 0, 0);
    self->f4 = off;
    self->f5 = off;
    self->f0 = off;
    self->unk18 = -1;
    cAITarget_dtor(self);
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016E0A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016E0A0 */

/* merge_units: begin func_0016E160 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Copies the second word of a pair over the first.
 */


typedef struct WordPair {
    int first;
    int second;
} WordPair;

void cStateMachine_ExitStateMessageReceived(WordPair* p) {
    p->first = p->second;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016E160(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016E160 */

/* merge_units: begin func_0016E170 */
#pragma push /* merge_units */
#include "sfo_ai_types.h"
#include "sfo_actor_types.h"
#include "hotbox_types.h"
#include "vslot_pad.h"

typedef struct { int x0; int x4; int x8; unsigned char xC; } Req16E170;
unsigned char cStateMachine_ChangeState(Req16E170* p, int v, int pri) {
    unsigned char r = 0;
    if (pri >= p->x8) {
        p->x4 = v;
        p->xC = 1;
        r = 1;
        p->x8 = pri;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016E170(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016E170 */

/* merge_units: begin func_0016E1A0 */
#pragma push /* merge_units */
#pragma cplusplus on
union NextIter {HotboxListNode* p;};
struct ObjectV { VPAD32(a) VPAD32(b) virtual int Life(); };
struct ControllerV { VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsPlayer(); VPAD4(d) VPAD2(e) virtual int Enemy(SfGameObject*); VPAD4(f) VPAD1(g) virtual int Kind(); };
extern "C" {
    SfAwarenessRecord* cAITarget_GetAwareness(SfAiPerception*,SfGameObject*);
    SfGameObject* cNetObj_GetPlayer(int);
    void std_list_cActiveListItemPtr_end_void_2(void*,void*);
    void cConstLListIterator_cActiveListItemPtr_ctor(void*,void*);
    void std_list_cActiveListItemPtr_begin_void_2(void*,void*);
    
#if 0 /* merge_units */
void std_list_cActiveListItemPtr_generic_iterator_1_ctor(void*,int);
#endif /* merge_units */
Word* std_list_cActiveListItemPtr_generic_iterator_1_ctor(Word* self, int value); /* merge_units */
#define std_list_cActiveListItemPtr_generic_iterator_1_ctor(a0, a1) ((void)std_list_cActiveListItemPtr_generic_iterator_1_ctor((Word *)(a0), (a1))) /* merge_units */

    
#if 0 /* merge_units */
void std_list_deleter_voidPtr_begin_void_2(void*,void*);
#endif /* merge_units */
void std_list_deleter_voidPtr_begin_void_2(Iter* out, PtrVec* v); /* merge_units */
#define std_list_deleter_voidPtr_begin_void_2(a0, a1) (std_list_deleter_voidPtr_begin_void_2((Iter *)(a0), (PtrVec *)(a1))) /* merge_units */

    extern void* g_HumanActorClassKey;
    extern char g_NpcThinkList[];
    extern SfAiComponent* g_LocalPlayer;
    extern unsigned char g_IsMultiplayer;
}
#pragma push
#pragma bool off
static inline int Active(SfGameObject* p) { return p->activated && p->enabled && !p->removed; }
#pragma pop
#pragma push
#pragma opt_common_subs off
extern "C" SfGameObject* cAITarget_GetNextNpcToTest(SfAiPerception* arg0, SfGameObject* arg1) {
    NextIter spCC;
    HotboxListNode* spC8;
    HotboxListNode* spC4;
    NextIter spC0;
    HotboxListNode* spBC;
    HotboxListNode* spB8;
    NextIter spB4;
    HotboxListNode* spB0;
    HotboxListNode* spAC;
    int spA8;
    void* spA4;
    void* spA0;
    void* sp9C;
    void* sp98;
    void* sp94;
    void* sp90;
    void* sp8C;
    NextIter sp88;
    bool var_a0_2;
    bool var_a0_3;
    bool var_a2;
    int var_s6;
    int var_v0_2;
    int var_v0_3;
    ControllerV* temp_a0;
    ControllerV* temp_a0_2;
    ControllerV* temp_a0_3;
    ControllerV* temp_a0_4;
    ControllerV* temp_a0_5;
    ControllerV* temp_a0_6;
    ControllerV* temp_a0_7;
    ControllerV* temp_a0_8;
    SfWeakHandle* temp_a1;
    SfGameObject* var_s3;
    void* container;
    bool var_s1;
    int var_s1_2;
    SfGameObject* temp_s0;
    SfGameObject* temp_s0_2;
    SfGameObject* temp_s0_3;
    SfGameObject* temp_s0_4;
    SfGameObject* temp_v0;
    SfAwarenessRecord* temp_v0_2;
    SfGameObject* temp_v0_3;
    SfAwarenessRecord* temp_v0_4;
    SfWeakHandle* temp_v1;
    SfWeakHandle* temp_v1_2;
    SfGameObject* var_a0;
    SfGameObject* var_v0;

    container = g_NpcThinkList;
    var_s3 = 0;
    std_list_deleter_voidPtr_begin_void_2(&spA8, container);
    std_list_cActiveListItemPtr_generic_iterator_1_ctor(&spAC, spA8);
    spCC.p = spAC;
    if (arg1 != 0) {
        temp_a0 = (ControllerV*)arg1->controller;
        if (temp_a0 != 0) {
            if ((temp_a0->Kind() & 255) == 1 || (((ControllerV*)arg1->controller)->Kind() & 255) == 2) {
                goto candidate_test;
            candidate_body:
                temp_a1 = (SfWeakHandle*)spCC.p->value;
                var_a0 = (SfGameObject*)temp_a1->object;
                { bool nil = !var_a0; var_a2 = true;
                    if(!nil) if(var_a0->id != temp_a1->id) var_a2=false; }
                var_v0 = var_a2 ? var_a0 : 0;
                if (var_v0 != 0) {
                    if (var_a0 && var_a0->id != temp_a1->id) var_a0=0;
                    if (var_a0 == arg1) goto candidate_found;
                }
                spCC.p = spCC.p->next;
            candidate_test:
                std_list_cActiveListItemPtr_end_void_2(&spA4, container);
                cConstLListIterator_cActiveListItemPtr_ctor(&spC8, &spA4);
                if (spCC.p != spC8) goto candidate_body;
            candidate_found:
                std_list_cActiveListItemPtr_end_void_2(&spA0, container);
                cConstLListIterator_cActiveListItemPtr_ctor(&spC4, &spA0);
                if (spCC.p == spC4) {
                    std_list_cActiveListItemPtr_begin_void_2(&sp9C, container);
                    cConstLListIterator_cActiveListItemPtr_ctor(&spC0, &sp9C);
                    spCC = spC0;
                } else {
                    spCC.p = spCC.p->next;
                }
            } else if (g_IsMultiplayer) {
                temp_a0_3=(ControllerV*)arg1->controller;
                if(temp_a0_3->IsPlayer()) {
                    var_s1=0;var_s6=0;
                    do {
                        temp_v0=cNetObj_GetPlayer(var_s6);
                        if(temp_v0) {
                            if(temp_v0->id == arg1->id) var_s1=1;
                            else if(var_s1 && ((ControllerV*)arg0->component)->Enemy(temp_v0)) {
                                var_s3=temp_v0;break;
                            }
                        }
                        var_s6++;
                    } while(var_s6<4);
                }
            }
        }
    }
    if (var_s3 == 0) {
        std_list_cActiveListItemPtr_end_void_2(&sp98, container);
        cConstLListIterator_cActiveListItemPtr_ctor(&spBC, &sp98);
        if (spCC.p != spBC) {
        loop_37:
            temp_v1 = (SfWeakHandle*)spCC.p->value;
            temp_s0 = (SfGameObject*)temp_v1->object;
            var_a0_2 = 1;
            bool null_temp_s0 = !temp_s0;
            if (!null_temp_s0 && (temp_s0->id != temp_v1->id)) {
                var_a0_2 = 0;
            }
            temp_s0_2 = var_a0_2 ? temp_s0 : 0;
            if ((temp_s0_2 != 0) && (((SfAiComponent*)arg0->component)->actor != temp_s0_2)) {
                if ((((ObjectV*)temp_s0_2)->Life() & 0xFF) != 3) {
                    temp_a0_5 = (ControllerV*)arg0->component;
                    if (temp_a0_5->Enemy(temp_s0_2) != 0) {
                        var_s3 = temp_s0_2;
                    } else {
                        goto block_56;
                    }
                } else if (temp_s0_2->classWord == g_HumanActorClassKey) {
                    var_v0_2 = Active(temp_s0_2);
                    if (var_v0_2 != 0) {
                        var_v0_2 = ((SfActor*)temp_s0_2)->pickupable != 0;
                    }
                    if ((var_v0_2 != 0) && ((temp_v0_2 = cAITarget_GetAwareness(arg0, temp_s0_2), (temp_v0_2 == 0)) || (temp_v0_2->deadBodyNoticeSent == 0))) {
                        var_s3 = temp_s0_2;
                    } else {
                        goto block_56;
                    }
                } else {
                    goto block_56;
                }
            } else {
            block_56:
                spCC.p = spCC.p->next;
                std_list_cActiveListItemPtr_end_void_2(&sp98, container);
                cConstLListIterator_cActiveListItemPtr_ctor(&spBC, &sp98);
                if (spCC.p == spBC) {

                } else {
                    goto loop_37;
                }
            }
        }
        std_list_cActiveListItemPtr_end_void_2(&sp94, container);
        cConstLListIterator_cActiveListItemPtr_ctor(&spB8, &sp94);
        if ((spCC.p == spB8) && (var_s3 == 0)) {
            if (g_IsMultiplayer != 0) {
                var_s1_2 = 0;
            loop_62:
                temp_v0_3 = cNetObj_GetPlayer(var_s1_2);
                if ((temp_v0_3 != 0) && ((temp_a0_6 = (ControllerV*)arg0->component, (temp_a0_6->Enemy(temp_v0_3) != 0)) || (arg0->flags2 & 1))) {
                    var_s3 = temp_v0_3;
                } else {
                    var_s1_2 += 1;
                    if (var_s1_2 >= 4) {

                    } else {
                        goto loop_62;
                    }
                }
            } else {
                temp_a0_7 = (ControllerV*)arg0->component;
                if (temp_a0_7->Enemy((SfGameObject*)g_LocalPlayer->actor) == 0) {
                    if (arg0->flags2 & 1) {
                        goto block_71;
                    }
                } else {
                block_71:
                    var_s3 = (SfGameObject*)g_LocalPlayer->actor;
                }
            }
            if (var_s3 == 0) {
                std_list_cActiveListItemPtr_begin_void_2(&sp90, container);
                cConstLListIterator_cActiveListItemPtr_ctor(&spB4, &sp90);
                sp88 = spB4;
                std_list_cActiveListItemPtr_end_void_2(&sp8C, container);
                cConstLListIterator_cActiveListItemPtr_ctor(&spB0, &sp8C);
                if (sp88.p != spB0) {
                loop_74:
                    temp_v1_2 = (SfWeakHandle*)sp88.p->value;
                    temp_s0_3 = (SfGameObject*)temp_v1_2->object;
                    var_a0_3 = 1;
                    bool null_temp_s0_3 = !temp_s0_3;
                    if (!null_temp_s0_3 && (temp_s0_3->id != temp_v1_2->id)) {
                        var_a0_3 = 0;
                    }
                    temp_s0_4 = var_a0_3 ? temp_s0_3 : 0;
                    if ((temp_s0_4 != 0) && (((SfAiComponent*)arg0->component)->actor != temp_s0_4)) {
                        if ((((ObjectV*)temp_s0_4)->Life() & 0xFF) != 3) {
                            temp_a0_8 = (ControllerV*)arg0->component;
                            if (temp_a0_8->Enemy(temp_s0_4) != 0) {
                                var_s3 = temp_s0_4;
                            } else {
                                goto block_93;
                            }
                        } else if (temp_s0_4->classWord == g_HumanActorClassKey) {
                            var_v0_3 = Active(temp_s0_4);
                            if (var_v0_3 != 0) {
                                var_v0_3 = ((SfActor*)temp_s0_4)->pickupable != 0;
                            }
                            if ((var_v0_3 != 0) && ((temp_v0_4 = cAITarget_GetAwareness(arg0, temp_s0_4), (temp_v0_4 == 0)) || (temp_v0_4->deadBodyNoticeSent == 0))) {
                                var_s3 = temp_s0_4;
                            } else {
                                goto block_93;
                            }
                        } else {
                            goto block_93;
                        }
                    } else {
                    block_93:
                        sp88.p = sp88.p->next;
                        std_list_cActiveListItemPtr_end_void_2(&sp8C, container);
                        cConstLListIterator_cActiveListItemPtr_ctor(&spB0, &sp8C);
                        if (sp88.p == spB0) {

                        } else {
                            goto loop_74;
                        }
                    }
                }
            }
        }
        if (var_s3 == 0) {
            var_s3 = arg1;
        }
    }
    return var_s3;
}

#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016E1A0(void) {}
#undef std_list_cActiveListItemPtr_generic_iterator_1_ctor /* merge_units */
#undef std_list_deleter_voidPtr_begin_void_2 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016E1A0 */

/* merge_units: begin func_0016E860 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Iterator constructors.
 */


/* volatile mirrors the original stack temporary. */
Word* std_list_cActiveListItemPtr_generic_iterator_1_ctor(Word* self, int value) {
    volatile int tmp = value;
    self->value = tmp;
    return self;
}

void std_list_deleter_voidPtr_begin_void_2(Iter* out, PtrVec* v) {
    out->p = v->data;
}
static inline void merge_flush_func_0016E860(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016E860 */

/* merge_units: begin func_0016E890 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
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
struct Obj_0016E890;
struct Handle { Obj_0016E890* object; int id; };
struct SRec {
    Handle h;
    IdV id;
    V v10;
    signed char b20;
    float f24, f28, f2C, f30, f34;
    unsigned char b38, b39, b3A, b3B, b3C;
};
struct Obj_0016E890 { char p0[0xC]; int id; char p10[0x58 - 0x10]; void* ctrl; };
struct SNode { int pad; SNode* next; SRec* value; };
struct It { SNode* p; It() {} It(const It& o) { p = o.p; } It& operator=(const It& o) { p = o.p; return *this; } };
struct SWord { int v; };
struct AiRec { char p0[0x30]; char list[0x10]; Handle h; };
extern "C" {
Obj_0016E890* cSafePtr_cGOBJ_opCast_cGOBJPtr(Handle* h);
Obj_0016E890* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
void cTargetManager_AddGobj(void* mgr, Obj_0016E890* o);
void Alloc_Lock(int);
void EnableIntc(int);
void* cMemMan_Allocate(int, int, void*, int);
void std_list_cTargetAwarenessPtr_push_front(void* list, SRec* const* v);
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
static inline const int& IdOf(Obj_0016E890* p) { if (p) return p->id; int m = -1; return m; }
static inline void Set(Handle* h, Obj_0016E890* o) { h->object = o; h->id = IdOf(o); }
static inline SRec* NewRec() {
    void* m;
    if (g_ProfileLockEnabled) Alloc_Lock(9);
    g_ProfileLockDepth++;
    m = cMemMan_Allocate(0, 0x40, D_0049C650, 0xF6);
    if (g_ProfileLockEnabled) EnableIntc(9);
    g_ProfileLockDepth--;
    if (m) { SRec* r = (SRec*)m; r->h.id = -2; r->h.object = 0; r->id.v = -1; }
    return (SRec*)m;
}
static inline int IsNullNV(void* p) { return (p != 0) ^ 1; }
static inline int EqNV(int a, int b) { return (unsigned)(a ^ b) < 1; }
static inline Obj_0016E890* WGet(Handle* h) { bool ok = 1; if (!IsNullNV(h->object) && !EqNV(h->object->id, h->id)) ok = 0; unsigned char k = ok; return k ? h->object : 0; }

void cAiTargetTransfer_Put(void* src, AiRec* dst, int* hid, SRec* recs)
{
    QCopy(dst, src, 0x30);
    if (*hid != -1) {
        Obj_0016E890* o = nGobjManager_LookupGOBJ_cObjectIdR(hid);
        Set(&dst->h, o);
        if (WGet(&dst->h) && !WGet(&dst->h)->ctrl)
            cTargetManager_AddGobj(g_TargetVisMgr, WGet(&dst->h));
    } else {
        Set(&dst->h, 0);
    }
    SRec* e;
    /* dead address-taken local: retail reserves an unused slot below e */
    int u;
    int* pu = &u;
    for (int i = 0; i < 4; i++) {
        if (recs[i].id.v != -1) {
            Obj_0016E890* o = nGobjManager_LookupGOBJ_cObjectIdR(&recs[i].id.v);
            if (o) {
                e = NewRec();
                *e = recs[i];
                Set(&e->h, o);
                std_list_cTargetAwarenessPtr_push_front(dst->list, &e);
            }
        }
    }
}
static inline void merge_flush_func_0016E890(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016E890 */
