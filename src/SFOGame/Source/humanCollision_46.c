/*
 * SFOGame/Source/humanCollision: 1 file, 001E7F40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001E7F40 */
#pragma push /* merge_units */
/* cHumanCollisionRoutine::DetectForAndHandleCollisionWithOtherHumans(cVector&, const cVector&, float) (humanCollision.cc) */
#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
#include "vslot_pad.h"

struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(const cVector& o) { const cVector* s = &o; cVector* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
    cVector& operator=(const cVector& o) { const cVector* s = &o; cVector* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); return *this; }
} __attribute__((aligned(16)));
static inline void SubV(cVector* r, const cVector* a, const cVector* b)
{
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory");
}
static inline cVector operator-(const cVector& a, const cVector& b) { cVector r; SubV(&r, &a, &b); return r; }

struct cMatrix { float m[16]; } __attribute__((aligned(16)));
struct cBox {
    cVector min, max;
    cBox(const cBox& o) : min(o.min), max(o.max) {}
};
extern "C" {
cVector* cVector_ctor_cVectorR(cVector* d, const cVector* s);
void cVector_WSet1(cVector* v);
void cBox_Empty(cBox* b);
cVector cVector_GetTransformed(const cVector* v, const cMatrix* m);
cVector* cVector_Transform_cMatrixR(cVector* v, const cMatrix* m);
cVector* cVector_ctor_float_float_float_float(cVector* o, float x, float y, float z, float w);
void cBox_Include(cBox* b, const cVector* v);
}
static inline void TB0(cBox* b, const cMatrix* m)
{
    cVector mn; cVector_ctor_cVectorR(&mn, &b->min); cVector_WSet1(&mn);
    cVector mx; cVector_ctor_cVectorR(&mx, &b->max); cVector_WSet1(&mx);
    cBox_Empty(b);
    { cVector t = cVector_GetTransformed(&mn, m); cBox_Include(b, &t); }
    { cVector t; cBox_Include(b, cVector_Transform_cMatrixR(cVector_ctor_float_float_float_float(&t, mn.x, mn.y, mx.z, 1.0f), m)); }
    { cVector t; cBox_Include(b, cVector_Transform_cMatrixR(cVector_ctor_float_float_float_float(&t, mn.x, mx.y, mn.z, 1.0f), m)); }
    { cVector t; cBox_Include(b, cVector_Transform_cMatrixR(cVector_ctor_float_float_float_float(&t, mn.x, mx.y, mx.z, 1.0f), m)); }
    { cVector t; cBox_Include(b, cVector_Transform_cMatrixR(cVector_ctor_float_float_float_float(&t, mx.x, mn.y, mn.z, 1.0f), m)); }
    { cVector t; cBox_Include(b, cVector_Transform_cMatrixR(cVector_ctor_float_float_float_float(&t, mx.x, mn.y, mx.z, 1.0f), m)); }
    { cVector t; cBox_Include(b, cVector_Transform_cMatrixR(cVector_ctor_float_float_float_float(&t, mx.x, mx.y, mn.z, 1.0f), m)); }
    { cVector t = cVector_GetTransformed(&mx, m); cBox_Include(b, &t); }
}
static inline void TB1(cBox* b, const cMatrix* m) { TB0(b, m); }
static inline void TB(cBox* b, const cMatrix* m) { TB1(b, m); }
struct cXform {
    VPAD16(a) VPAD4(b)
    virtual void Update();
    char pad4[0xC];
    cMatrix mMatrix;
    unsigned char mDirty;
    const cMatrix& GetMatrix() { if (mDirty) Update(); return mMatrix; }
};
struct cController {
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual unsigned char IsActive();
    virtual unsigned char Is58();
    virtual unsigned char Is5C();
};
struct cSkaAnimAnchor { char pad[0xD0]; float weight; };
struct cSkaAnimAnchorList;
extern "C" cSkaAnimAnchor* cSkaAnimAnchorList_Find(cSkaAnimAnchorList* l, const void* name);
struct cSkaSystem { char pad[0xB0]; char anchors[4]; cSkaAnimAnchor& Find(const void* n) { return *cSkaAnimAnchorList_Find((cSkaAnimAnchorList*)anchors, n); } };
struct cObjectId { int id; };

class cSKM_GOBJ {
public:
    VPAD32(a)
    virtual cBox& GetBox();
    VPAD16(b) VPAD4(c) VPAD1(d)
    virtual cVector GetPosition() const;
    VPAD8(e) VPAD1(f)
    virtual unsigned char GetState();
    int pad4[2];
    cObjectId mId;               /* 0x0C */
    int pad10;
    unsigned char b14;           /* 0x14 */
    char pad15[0x49 - 0x15];
    unsigned char b49;           /* 0x49 */
    char pad4A[2];
    void* classKey;              /* 0x4C */
    cXform* mXform;              /* 0x50 */
    int pad54;
    cController* mController;    /* 0x58 */
    char pad5C[0x2EC0 - 0x5C];
    cSkaSystem mSkaSystem;       /* 0x2EC0 */
    cSkaSystem* GetSkaSystem() const { return (cSkaSystem*)&mSkaSystem; }
    char pad[0x3204 - 0x2EC0 - sizeof(cSkaSystem)];
    int mStateBits[8];           /* 0x3204 */
};
struct cGobjController { char pad[0x30]; cSKM_GOBJ* gobj; };
struct cNpc { char pad[0xC]; int id; char pad10[0x58 - 0x10]; cGobjController* controller; };
struct cHandle { cNpc* obj; int id; };
struct cLLNode { int pad0; cLLNode* next; cHandle* value; };
struct LIt;
struct cConstLListIterator { cLLNode* p; cConstLListIterator(const LIt& i); };

struct cHumanCollisionRoutine {
    void* vt;
    cSKM_GOBJ* mGobj;
    void* skeleton;
    cSkaSystem* animationSystem;
    char pad10[0x20 - 0x10];
    int mMode;                   /* 0x20 */
    char pad24[0x3D0 - 0x24];
    unsigned char mDoCollisionWithHumans;
};
struct cSystem;
struct cMessage { void* vt; char pad[0x4C]; };
extern "C" {
struct DelIt { cLLNode* p; };
struct LIt { cLLNode* p; };
DelIt std_list_deleter_voidPtr_begin_void_2(void*);
DelIt std_list_deleter_voidPtr_end_void_2(void*);
LIt std_list_cActiveListItemPtr_generic_iterator_1_ctor(cLLNode*);
extern void* g_HumanActorClassKey;
extern char g_NpcThinkList[];
extern char g_Game[];
extern char D_004EE5C0[];
extern char D_004D92A0[];
extern char D_004A03D0[];
extern char D_004A03D8[];
cSystem* cSystemContainer_GetSystem(void*, void*);
void cAISoundSystemGobjToGobjMessage_ctor(cMessage*, cObjectId*, cObjectId*, int);
void QueueMessage_cMessageR_cSystemP_int(cMessage*, cSystem*, int);
void cMessage_dtor(cMessage*, int);
cSKM_GOBJ* cNetObj_GetPlayer(int);
unsigned char cHumanCollisionRoutine_DetectForAndHandleCollisionWithHuman(cHumanCollisionRoutine* self, cVector& pos, const cBox& box, cSKM_GOBJ& g, float scale);
}

inline cConstLListIterator::cConstLListIterator(const LIt& i) { p = i.p; }
static inline LIt LBegin(char* l) { return std_list_cActiveListItemPtr_generic_iterator_1_ctor(std_list_deleter_voidPtr_begin_void_2(l).p); }
static inline LIt LEnd(char* l) { return std_list_cActiveListItemPtr_generic_iterator_1_ctor(std_list_deleter_voidPtr_end_void_2(l).p); }
static inline float MinF(float a, float b) { float r = 0.0f; asm { min.s r, a, b } return r; }
static inline float MA(float a, float b) { float r = 0.0f; float aa = a; float bb = b; asm volatile { .set reorder; min.s r, aa, bb } return r; }
static inline float MB(float a, float b) { float r = 0.0f; asm volatile { min.s r, a, b } return r; }
static inline float MinF2(float b, float a) { float r = 0.0f; asm volatile { .set reorder; min.s r, a, b } return r; }
static inline unsigned char IsHuman(cSKM_GOBJ* g) { void* k = g_HumanActorClassKey; return g->classKey == k; }
static inline unsigned char CheckState(cSKM_GOBJ* g, unsigned char i) { return ((g->mStateBits[(unsigned int)i >> 5] >> (i & 0x1F)) & 1) != 0; }
static inline unsigned char IsPlayerHuman(cSKM_GOBJ* g)
{
    unsigned char r = 0;
    if (IsHuman(g) && CheckState(g, 0)) r = 1;
    return r;
}
static inline unsigned char IsActive(cSKM_GOBJ* g)
{
    unsigned char r = 0;
    cController* c = g->mController;
    if (c && c->IsActive()) r = 1;
    return r;
}
static inline unsigned char Is58(cSKM_GOBJ* g)
{
    unsigned char r = 0;
    cController* c = g->mController;
    if (c && c->Is58()) r = 1;
    return r;
}
static inline unsigned char Is5C(cSKM_GOBJ* g)
{
    unsigned char r = 0;
    cController* c = g->mController;
    if (c && c->Is5C()) r = 1;
    return r;
}
static inline unsigned char IsDying(cSKM_GOBJ* g)
{
    bool r; unsigned char s = g->GetState();
    r = 1;
    if (s != 3 && s != 2) r = 0;
    return r;
}
static inline cNpc* Deref(cHandle* h) { unsigned char ok = !h->obj || (unsigned char)(h->obj->id == h->id); return ok ? h->obj : 0; }

static inline bool OnLedge(cSkaSystem* sys) { bool r = 1; if (sys->Find(D_004A03D0).weight <= 0.0f && sys->Find(D_004A03D8).weight <= 0.0f) r = 0; return r; }
static inline bool IsHumanB(cSKM_GOBJ* g) { void* k = g_HumanActorClassKey; return g->classKey == k; }
static inline unsigned char IsHumanU(cSKM_GOBJ* g) { return IsHumanB(g); }
/* int return with an unsigned char flag: gives retail's single andi into s8. */
static inline int IsPH(cSKM_GOBJ* g) { unsigned char r = 0; if (IsHumanU(g) && CheckState(g, 0)) r = 1; return r; }
/* mtc1 zero kept inside the asm: a C `r = 0.0f` is dropped by MW's dataflow on `.set reorder` asm */
/* min.s has no C equivalent; the C zero init of r is kept and scheduled freely (retail's early mtc1 zero). */
static inline float MZ(float a, float b) { float r = 0.0f; float aa = a; float bb = b; asm { min.s r, aa, bb } return r; }
extern "C" unsigned char cHumanCollisionRoutine_DetectForAndHandleCollisionWithOtherHumans(cHumanCollisionRoutine* self, cVector& collisionResponse, const cVector& originalPosition, float timeStep)
{


    unsigned char collisionDetected = 0;
    cVector newPosition = originalPosition;
    int isPlayerHuman = IsPH(self->mGobj);
    float k15 = 15.0f, k22 = 22.0f;
    float rate = MZ(1.0f, k15 * timeStep);
    float rateHuman = MZ(1.0f, k22 * timeStep);
    if (self->mGobj->GetState() != 3 && !(IsDying(self->mGobj) && !IsActive(self->mGobj)) && self->mMode != 9 && self->mDoCollisionWithHumans) {
        cBox& box = self->mGobj->GetBox();
        cBox box_WorldSpace = box;
        TB(&box_WorldSpace, &self->mGobj->mXform->GetMatrix());
        {
            char* npcActiveList = g_NpcThinkList;
            cConstLListIterator curr(LBegin(npcActiveList));
            cConstLListIterator end(LEnd(npcActiveList));
            for (; curr.p != end.p; curr.p = curr.p->next) {
                if (!Deref(curr.p->value)) continue;
                cGobjController* gobjController = Deref(curr.p->value)->controller;
                if (!gobjController) continue;
                cSKM_GOBJ* gobj = gobjController->gobj;
                if (!gobj) continue;
                if (gobj->b49 != 2) continue;
                {
                    unsigned char otherIsPlayerHuman = IsPlayerHuman(gobj);
                    unsigned char collisionDetectedWithCurrGobj = cHumanCollisionRoutine_DetectForAndHandleCollisionWithHuman(self, newPosition, box_WorldSpace, *gobj,
                        IsActive(self->mGobj) ? (otherIsPlayerHuman ? rateHuman : rate) : rate);
                    collisionDetected = collisionDetectedWithCurrGobj || collisionDetected;
                    if (collisionDetectedWithCurrGobj && self->mGobj->b14 && (Is58(gobj) || Is5C(gobj))) {
                        cSystem* aiSoundSystem = cSystemContainer_GetSystem(g_Game, D_004EE5C0);
                        cMessage msg;
                        cAISoundSystemGobjToGobjMessage_ctor(&msg, &self->mGobj->mId, &gobj->mId, 7);
                        QueueMessage_cMessageR_cSystemP_int(&msg, aiSoundSystem, 0);
                        msg.vt = D_004D92A0;
                        cMessage_dtor(&msg, 0);
                    }
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            cSKM_GOBJ* gobj = cNetObj_GetPlayer(i);
            if (!gobj) continue;
            if (gobj->b49 != 2) continue;
            {
                cSKM_GOBJ& skmGobj = *gobj;
                unsigned char onLedge = OnLedge(skmGobj.GetSkaSystem());
                unsigned char collisionDetectedWithCurrGobj = cHumanCollisionRoutine_DetectForAndHandleCollisionWithHuman(self, newPosition, box_WorldSpace, skmGobj,
                    IsActive(self->mGobj) ? rate : (isPlayerHuman ? (onLedge ? rate : 0.0f) : rate));
                collisionDetected = collisionDetectedWithCurrGobj || collisionDetected;
            }
        }
    }
    collisionResponse = newPosition - originalPosition;
    return collisionDetected;
}
static inline void merge_flush_func_001E7F40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E7F40 */
