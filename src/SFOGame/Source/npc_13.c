/*
 * SFOGame/Source/npc: 9 files, 0014AB70-0014AFC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0014AB70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (container helpers instantiated for cNPC).
 */

#include "npc_types.h"

extern Iter* std_list_deleter_voidPtr_insert(Iter* out, Tree* t, Iter* hint, int value);

Word* cLListIterator_cActiveListItemPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cActiveListItemPtr_end_void(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* map insert(value): inserts with an end() hint, result iterator in out[1]. */
Iter* std_list_cNPCPtr_push_back(Tree* t, int value) {
    Iter it[2];

    it[0].p = &t->header;
    return std_list_deleter_voidPtr_insert(&it[1], t, &it[0], value);
}

Word* std_list_cActiveListItemPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

Word* cLListIterator_cNPCPtr_ctor_listR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cNPCPtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

Word* cLListIterator_cNPCPtr_ctor_cLListIteratorR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Iterator inequality. */
int opNe_cLListIteratorR_cLListIteratorR(Word* a, Word* b) {
    return (0U < (unsigned int)(a->value ^ b->value));
}

void cLList_cNPCPtr_End(Iter* out, Tree* t) {
    out->p = &t->header;
}

/* Linked-list iterator increment: follow node->next (+4). */
Iter* cLListIterator_cNPCPtr_opInc(Iter* it) {
    it->p = (int*)it->p[1];
    return it;
}

/* Address of the node payload (+8). */
int* cLListIterator_cNPCPtr_opMul(Iter* it) {
    return it->p + 2;
}

float* cLListIterator_cNPCPtr_opAssign(float* dst, float* src) {
    *dst = *src;
    return dst;
}

void cLList_cNPCPtr_Begin(Iter* out, PtrVec* v) {
    out->p = v->data;
}

void* cLListIterator_cNPCPtr_ctor_void(void* self) {
    return self;
}
static inline void merge_flush_func_0014AB70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014AB70 */

/* merge_units: begin func_0014AC90 */
#pragma push /* merge_units */
#include "types.h"
#include "vslot_pad.h"

typedef struct { char pad[0x2C]; unsigned char x2C; unsigned char x2D; unsigned char x2E; char pad2[0x3469 - 0x2F]; unsigned char disguise; } Ctl_AC90;
typedef struct { char pad[0x30]; Ctl_AC90* ctl; } NPC_AC90;
extern unsigned char g_IsMultiplayer;
extern void cNetNPCMsgs_SendMessage(Ctl_AC90* c, int id, int kind, int v, int a, int b, int d);
void cNPC_SetHasDisguise(NPC_AC90* self, unsigned char v, int send)
{
    Ctl_AC90* c = self->ctl;
    unsigned char cur = c->x2D && c->x2C && !c->x2E && c->disguise;
    if (v != cur) {
        c->disguise = v;
        if (g_IsMultiplayer && send)
            cNetNPCMsgs_SendMessage(self->ctl, 0x39, 4, v, 0, 0, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014AC90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014AC90 */

/* merge_units: begin func_0014AD30 */
#pragma push /* merge_units */
typedef struct {
    char pad00[0x30];
    void* owner;
    char pad34[0x98 - 0x34];
    float f98;
    char pad9C[0x141 - 0x9C];
    unsigned char lo7 : 7;
    unsigned char flag : 1;
} NPC_AD30;
extern unsigned char D_005721C0;
#if 0 /* merge_units */
extern void cNetNPCMsgs_SendMessage(void* owner, int type, int size, int a, int b, int c, int d);
#endif /* merge_units */
#define cNetNPCMsgs_SendMessage(a0, a1, a2, a3, a4, a5, a6) (cNetNPCMsgs_SendMessage((Ctl_AC90 *)(a0), (a1), (a2), (a3), (a4), (a5), (a6))) /* merge_units */


void cNPC_ActivateByRadius(NPC_AD30* self, float f)
{
    if (g_IsMultiplayer) {
        if (g_IsMultiplayer ? D_005721C0 : 1)
            cNetNPCMsgs_SendMessage(self->owner, 0x33, 4, (unsigned int)f, 0, 0, 0);
    }
    if (f < 1e-5f) self->f98 = 0.0f;
    else self->f98 = f * f;
    self->flag = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014AD30(void) {}
#undef cNetNPCMsgs_SendMessage /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014AD30 */

/* merge_units: begin func_0014AE30 */
#pragma push /* merge_units */
typedef struct { char pad0[0x30]; int netId; char pad1[0x64]; int timer; char pad2[0xA5]; unsigned char rest : 7; unsigned char active : 1; } NpcB;
#if 0 /* merge_units */
extern void cNetNPCMsgs_SendMessage(int id, int ev, int a, int b, int c, int d, int e);
#endif /* merge_units */
#define cNetNPCMsgs_SendMessage(a0, a1, a2, a3, a4, a5, a6) (cNetNPCMsgs_SendMessage((Ctl_AC90 *)(a0), (a1), (a2), (a3), (a4), (a5), (a6))) /* merge_units */


static inline int NpcIsHost(void) { return g_IsMultiplayer ? D_005721C0 : 1; }
void cNPC_ActivateByRadiusOff(NpcB* self)
{
    if (g_IsMultiplayer && NpcIsHost()) {
        cNetNPCMsgs_SendMessage(self->netId, 0x34, 4, 0, 0, 0, 0);
    }
    self->timer = 0;
    self->active = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014AE30(void) {}
#undef cNetNPCMsgs_SendMessage /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014AE30 */

/* merge_units: begin func_0014AEC0 */
#pragma push /* merge_units */
#pragma cplusplus on
class NPC_AEC0 {
public:
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e)
    virtual void AddItem(int w);
};
extern "C" int cNetObj_GetPlayer(int i);
extern "C" void cNPC_AddAwarenessOfPlayers(NPC_AEC0* self)
{
    int i = 0;
    do {
        int w = cNetObj_GetPlayer(i);
        if (w)
            self->AddItem(w);
        i++;
    } while (i < 4);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014AEC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014AEC0 */

/* merge_units: begin func_0014AF30 */
#pragma push /* merge_units */
typedef struct { int pad[2]; void** items; } Reg_0014AF30;
typedef struct { char pad[0x58]; int id; } Ai_0014AF30;
typedef struct { char pad[0x1B0]; Ai_0014AF30* ai; } NPC_0014AF30;
extern Reg_0014AF30* D_004FFBE0;
void* cNPC_GetDestinationNode(NPC_0014AF30* self)
{
    int id = self->ai->id;
    void* r = 0;
    if (id >= 0)
        r = D_004FFBE0->items[id];
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014AF30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014AF30 */

/* merge_units: begin func_0014AF60 */
#pragma push /* merge_units */
typedef struct { int pad[2]; void** items; } Reg_0014AF60;
typedef struct { char pad[0x50]; int id; } Ai_0014AF60;
typedef struct { char pad[0x1B0]; Ai_0014AF60* ai; } NPC_0014AF60;
#if 0 /* merge_units */
extern Reg_0014AF60* D_004FFBE0;
#endif /* merge_units */
#define D_004FFBE0 (*(Reg_0014AF60 **)&D_004FFBE0) /* merge_units */


void* cNPC_GetNextNode(NPC_0014AF60* self)
{
    int id = self->ai->id;
    void* r = 0;
    if (id >= 0)
        r = D_004FFBE0->items[id];
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014AF60(void) {}
#undef D_004FFBE0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014AF60 */

/* merge_units: begin func_0014AF90 */
#pragma push /* merge_units */
typedef struct { int pad[2]; void** items; } Reg_0014AF90;
typedef struct { char pad[0x4C]; int id; } Ai_0014AF90;
typedef struct { char pad[0x1B0]; Ai_0014AF90* ai; } NPC_0014AF90;
#if 0 /* merge_units */
extern Reg_0014AF90* D_004FFBE0;
#endif /* merge_units */
#define D_004FFBE0 (*(Reg_0014AF90 **)&D_004FFBE0) /* merge_units */


void* cNPC_GetCurrentNode(NPC_0014AF90* self)
{
    int id = self->ai->id;
    void* r = 0;
    if (id >= 0)
        r = D_004FFBE0->items[id];
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014AF90(void) {}
#undef D_004FFBE0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014AF90 */

/* merge_units: begin func_0014AFC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */


extern int cAITarget_TestGobjInViewCone(NpcAi* ai, int gobj, int a2);
extern int cGOBJ_GetClosestPlayer(NpcActor* actor, int a1);

/* vtable slot 0x60: InViewCone. */
int cNPC_InViewCone(cNPC* self, int gobj) {
    return cAITarget_TestGobjInViewCone(self->ai, gobj, 1);
}

/* vtable slot 0x3A: GetClosestPlayer. */
int cNPC_GetClosestPlayer(cNPC* self) {
    return cGOBJ_GetClosestPlayer(self->actor, 0);
}
static inline void merge_flush_func_0014AFC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014AFC0 */
