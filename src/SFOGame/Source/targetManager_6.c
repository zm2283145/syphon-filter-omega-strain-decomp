/*
 * SFOGame/Source/targetManager: 4 files, 0022C440-0022C720
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0022C440 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int cScriptBase_registerField(int, char *, int, int);                
extern int D_00493888;
extern int D_00493890;
extern int D_004F78F0;

void TargSettings_SOBJ_init(int arg0) {
    cScriptBase_registerField(D_004F78F0, "maxDist", arg0, D_00493890);
    cScriptBase_registerField(D_004F78F0, "distFactor", arg0 + 4, D_00493890);
    cScriptBase_registerField(D_004F78F0, "freshFactor", arg0 + 8, D_00493890);
    cScriptBase_registerField(D_004F78F0, "angFactor", arg0 + 0xC, D_00493890);
    cScriptBase_registerField(D_004F78F0, "pitchFactor", arg0 + 0x10, D_00493890);
    cScriptBase_registerField(D_004F78F0, "zoneFactor", arg0 + 0x14, D_00493890);
    cScriptBase_registerField(D_004F78F0, "zone1MaxDist", arg0 + 0x18, D_00493890);
    cScriptBase_registerField(D_004F78F0, "zone1MinAng", arg0 + 0x1C, D_00493890);
    cScriptBase_registerField(D_004F78F0, "zone2MinAng", arg0 + 0x20, D_00493890);
    cScriptBase_registerField(D_004F78F0, "zone3MinAng", arg0 + 0x24, D_00493890);
    cScriptBase_registerField(D_004F78F0, "extraLosFrames", arg0 + 0x28, D_00493888);
    cScriptBase_registerField(D_004F78F0, "autoMinAng", arg0 + 0x2C, D_00493890);
    cScriptBase_registerField(D_004F78F0, "autoMaxDist", arg0 + 0x30, D_00493890);
    cScriptBase_registerField(D_004F78F0, "autoPrevClamp", arg0 + 0x34, D_00493890);
    cScriptBase_registerField(D_004F78F0, "debugDisplay", arg0 + 0x38, D_00493888);
}
static inline void merge_flush_func_0022C440(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022C440 */

/* merge_units: begin func_0022C640 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern char D_004F78E8[];

int TargSettings_SOBJ_getClassId(void) {
    return (int)D_004F78E8;
}
static inline void merge_flush_func_0022C640(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022C640 */

/* merge_units: begin func_0022C650 */
#pragma push /* merge_units */
#pragma cplusplus on
/* cTargetManager_AddGobj: add an actor to the visibility registry (30 slots + handle list) */
struct Pt1TvActor { char pad0[0xC]; int serial; };
struct Pt1TvHandle { Pt1TvActor* target; int serial; };
struct Pt1TvIt { void* p; };
struct Pt1TvReg {
    char pad0[0x98];
    Pt1TvActor* slots[30];
    char pad110[0x11C - 0x110];
    char list[4];
    char sentinel[4];
};
extern "C" void std_list_deleter_cSafePtr_cGOBJ_insert(Pt1TvIt* out, void* list, Pt1TvIt* pos, Pt1TvHandle* h);
extern "C" int cTargetManager_AddGobj(Pt1TvReg* r, Pt1TvActor* a)
{
    for (int i = 0; i < 30; i++)
        if (r->slots[i] == a)
            return 0;
    for (int i = 0; i < 30; i++) {
        if (!r->slots[i]) {
            Pt1TvIt res;
            Pt1TvIt pos;
            int none;
            Pt1TvHandle h;
            r->slots[i] = a;
            h.serial = -1;
            h.target = a;
            h.serial = *(a ? &a->serial : (none = -1, &none));
            pos.p = r->sentinel;
            std_list_deleter_cSafePtr_cGOBJ_insert(&res, r->list, &pos, &h);
            return 1;
        }
    }
    return 0;
}
static inline void merge_flush_func_0022C650(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022C650 */

/* merge_units: begin func_0022C720 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)

struct Tgt { char p[0xC]; int id; };
static inline int IdOf(Tgt* a) { int none; return *(a ? &a->id : (none = -1, &none)); }
struct HndT {
    Tgt* p; int id;
    HndT(Tgt* a) { id = -1; p = a; id = IdOf(a); }
};
struct Eq {};
struct Pred { Eq op; HndT* value; Pred(const Eq& o, const HndT& v) : op(o) { value = (HndT*)&v; } };
struct RList { int count; void* head; };

struct Pair { char p[8]; int a; int b; };
struct PNode { PNode* prev; PNode* next; Pair v; };
struct PIt { PNode* n; };
struct PList { int size; PNode* sprev; PNode* first; };
struct NEq {};
struct NPred { NEq op; Pair* value; NPred(const NEq& o, Pair& v) : op(o) { value = &v; } };

struct Cell { int a; int b; char p8[5]; unsigned char flag; char pE[2];
    void Clear() { b = 0; a = 0; flag = 0; } };

struct TVis {
    char p0[0x20];
    Cell* rows[30];
    int slots[30];
    PList pairs;
    RList recent;
};

extern "C" {
int cTargetManager_FindGobj(TVis* s, Tgt* t);
void std_list_imp_cSafePtr_cGOBJ_remove_if(RList* l, Pred p);
PIt* std_list_deleter_LosReqElem_generic_iterator_ctor(PIt* it, PNode* n);
PNode* std_list_deleter_LosReqElem_tail(PList* l);
PNode* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_5(void* n);
void std_list_imp_LosReqElem_remove_if(PList* l, NPred p);
}

static inline PNode* PBegin(PList* l) { return details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_5(&l->sprev)->next; }
static inline PNode* PEnd(PList* l) { PIt t; std_list_deleter_LosReqElem_generic_iterator_ctor(&t, std_list_deleter_LosReqElem_tail(l)); return t.n; }

extern "C" int cTargetManager_RemoveGobj(TVis* self, Tgt* t)
{
    int slot = cTargetManager_FindGobj(self, t);
    if (slot >= 0) {
    {
        int n = 0x1D - slot;
        Cell* c = self->rows[slot];
        for (int j = 0; j < n; j++) { c->Clear(); c++; }
    }
    for (int i = 0; i < slot; i++) self->rows[i][slot - i - 1].Clear();
    self->slots[slot] = 0;
    { Eq eq; HndT h(t); std_list_imp_cSafePtr_cGOBJ_remove_if(&self->recent, Pred(eq, h)); }
    for (PNode* it = PBegin(&self->pairs); it != PEnd(&self->pairs); it = it->next) {
        if (slot == it->v.a || slot == it->v.b) {
            { NEq eq; std_list_imp_LosReqElem_remove_if(&self->pairs, NPred(eq, it->v)); }
            break;
        }
    }
    return 1;
    }
    return 0;
}
static inline void merge_flush_func_0022C720(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022C720 */
