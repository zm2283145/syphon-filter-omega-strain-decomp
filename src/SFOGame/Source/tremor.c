/*
 * SFOGame/Source/tremor: 5 files, 002722B0-002728F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002722B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(10)
#include "types.h"

struct cVector {
    union { struct { float x, y, z, w; } f; __int128 q; } u;
    cVector() {}
    cVector(const cVector& s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(this), "r"(&s) : "memory"); }
    cVector& operator=(const cVector& s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(this), "r"(&s) : "memory"); return *this; }
} __attribute__((aligned(16)));

static inline cVector operator-(const cVector& a, const cVector& b)
{
    cVector r;
    __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline float Length(const cVector& v)
{
    float r = 0.0f;
    __asm__ volatile("lqc2 vf1, 0x0(%1); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; qmfc2.ni %0, vf4" : "=r"(r) : "r"(&v));
    return r;
}
static inline float Min(float a, float b) { float r = 0.0f; __asm__ ("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

struct cSafeObj { char pad[0xC]; int mId; };
struct cGOBJ {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual cVector GetPosition(); /* +0xE4 */
};
struct cSafePtr {
    cSafeObj* mPtr;
    int mId;
    bool IsNull() const { return !mPtr; }
    bool Same() const { return mPtr->mId == mId; }
    bool IsValid() const { return !mPtr || Same(); }
    cSafeObj* Peek() const { return IsValid() ? mPtr : 0; }
};

struct cTremorObj {
    float mDuration;
    float mElapsedTime;
    float mInnerRad;
    float mOuterRad;
    float mIntensity;
    char pad14[0xC];
    cVector mLoc;
    cSafePtr mGobj;
};

struct TNode;
struct DIt { TNode* p; };
struct LIt : DIt {};
union UBlk { TNode* p; int i; };
struct cLListIterator : LIt { cLListIterator() {} cLListIterator(const LIt& g) { p = g.p; } void Set(const cLListIterator& o) { cLListIterator t; cLListIterator* pt = &t; *(UBlk*)this = *(UBlk*)&o; } cLListIterator& operator=(const cLListIterator& o) { Set(o); return *this; } };
struct TNode { TNode* prev; TNode* next; cTremorObj* data; };
struct cLList { int a, b, c; };

extern "C" {
extern cGOBJ* D_004FFC10;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern char D_004A8EF0[];
extern float D_0048B2D0;
extern int D_0048B2D8;
extern int D_0048B2E0;
extern float D_0048B2E8;
void std_list_deleter_voidPtr_begin_void(DIt* out, cLList* l);
Word* std_list_cTremorObjPtr_generic_iterator_ctor(Word* d, Word* s);
void std_list_cTremorObjPtr_end(Iter* out, Tree* l);
Word* cLListIterator_cTremorObjPtr_ctor(Word* d, Word* s);
DIt* std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(LIt* d, cLListIterator* s);
void std_list_cTremorObjPtr_generic_iterator_opCast(int out, int s);
void std_list_deleter_voidPtr_erase_listdeleter(DIt* out, cLList* l, DIt* pos);
cGOBJ* cSafePtr_cGOBJ_GetPtr_void(cSafePtr* p);
void Alloc_Lock(int);
void EnableIntc(int);
void cMemMan_Deallocate(int, void*, char*, int);
int Libc_Rand(void);
struct Ch_D640;
void cCameraShake_SetBackgroundShake(Ch_D640* c, float x, float d);
void nRumbleManager_Start(int a, int b, int c, float d, int e);
}

static inline void Free(void* p)
{
    if (g_ProfileLockEnabled) Alloc_Lock(9);
    g_ProfileLockDepth++;
    cMemMan_Deallocate(0, p, D_004A8EF0, 0x6C);
    if (g_ProfileLockEnabled) EnableIntc(9);
    g_ProfileLockDepth--;
}

static inline void Begin3(cLList* l, LIt* b) { DIt a; std_list_deleter_voidPtr_begin_void(&a, l); std_list_cTremorObjPtr_generic_iterator_ctor((Word*)b, (Word*)&a); }
static inline void Begin2(cLList* l, LIt* b) { Begin3(l, b); }
static inline void Begin1(cLList* l, cLListIterator* out) { LIt b; Begin2(l, &b); out->p = b.p; }
static inline void Begin0(cLList* l, cLListIterator* out) { Begin1(l, out); }
static inline void End4(cLList* l, cLListIterator* f);
static inline void End3(cLList* l, cLListIterator* f) { End4(l, f); }
static inline void End4(cLList* l, cLListIterator* f) { LIt e; std_list_cTremorObjPtr_end((Iter*)&e, (Tree*)l); cLListIterator_cTremorObjPtr_ctor((Word*)f, (Word*)&e); }
static inline void End2(cLList* l, cLListIterator* f) { End3(l, f); }
static inline TNode* End1(cLList* l) { cLListIterator f; End2(l, &f); return f.p; }
static inline void Erase3(cLList* l, LIt* c, LIt* g) { DIt r; DIt d; LIt* pc = c; std_list_cTremorObjPtr_generic_iterator_opCast((int)&d, (int)pc); std_list_deleter_voidPtr_erase_listdeleter(&r, l, &d); std_list_cTremorObjPtr_generic_iterator_ctor((Word*)g, (Word*)&r); }
static inline void Erase2(cLList* l, cLListIterator* cur, cLListIterator* h) { LIt g; LIt c; std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&c, cur); Erase3(l, &c, &g); h->p = g.p; }
static inline cLListIterator Erase0(cLList* l, cLListIterator* cur);
static inline cLListIterator Erase1(cLList* l, cLListIterator* cur) { return Erase0(l, cur); }
static inline cLListIterator Erase0(cLList* l, cLListIterator* cur) { LIt g; LIt c; std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&c, cur); Erase3(l, &c, &g); return cLListIterator(g); }
static inline bool Expired(cTremorObj* o, float dt) { o->mElapsedTime += dt; return (o->mElapsedTime > o->mDuration) ? true : false; }

static inline float Len0(const cVector& v) { return Length(v); }
static inline bool NotEnd(cLList* l, cLListIterator& c) { cLListIterator f; End2(l, &f); return c.p != f.p; }
static inline cTremorObj*& Deref(cLListIterator& it) { return it.p->data; }
extern "C" void cTremorManager_NextFrame(cLList* self, float timeStep)
{
    cGOBJ* cam = D_004FFC10;
    cVector loc = cam->GetPosition();
    float intensity;
    cLListIterator curr;
    cTremorObj* obj;
    float rnd;

    intensity = 0.0f;
    for (Begin0(self, &curr); NotEnd(self, curr); ) {
        obj = curr.p->data;
        if (obj->mGobj.Peek()) {
            cVector p = cSafePtr_cGOBJ_GetPtr_void(&obj->mGobj)->GetPosition(); obj->mLoc = p;
        }
        if (Expired(obj, timeStep)) {            obj = curr.p->data;
            curr = Erase1(self, &curr);
            Free(obj);
        } else {
            cTremorObj* o = Deref(curr);
            float in;
            cVector diff = loc - o->mLoc;
            float dist = Len0(diff);
            in = o->mIntensity;
            float remain = o->mDuration - o->mElapsedTime;
            float fade = o->mDuration / 3.0f;
            if (remain < fade) in *= remain / fade;
            {
                float inner = o->mInnerRad;
                if (dist < inner) {
                    in = in;
                } else {
                    float outer = o->mOuterRad;
                    if (dist < outer) { float range = outer - inner; in *= (outer - dist) / range; }
                    else in = 0.0f;
                }
            }
            intensity += in;
            curr.p = curr.p->next;
        }
    }
    intensity = Min(intensity, 1.0f);
    cCameraShake_SetBackgroundShake((Ch_D640*)((char*)cam + 0xB20), intensity * D_0048B2D0, 0.35f);
    if (intensity > 0.0f) {
        float m = 2147483648.0f;
        rnd = intensity * D_0048B2E8;
        intensity += rnd * (Libc_Rand() / (1.0f + m)) - rnd;
        nRumbleManager_Start(0, 0, (int)(D_0048B2D8 + intensity * (D_0048B2E0 - D_0048B2D8)), 0.01f, 1);
    }
}
static inline void merge_flush_func_002722B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002722B0 */

/* merge_units: begin func_002726F0 */
#pragma push /* merge_units */
typedef struct { char pad[0x10]; float f10; } Src_D640;
typedef struct Ch_D640 {
    char pad[0x1C]; float f1C; float f20; float f24; float f28; float f2C; Src_D640* p30; float f34;
} Ch_D640;

void cCameraShake_SetBackgroundShake(Ch_D640* c, float x, float d) {
    float s;
    *(float*)((char*)c + 0x10) = x;
    if (d >= 0.0f) {
        s = d * c->f2C;
        c->f1C = c->f1C * s;
        c->f24 = c->f24 * s;
        c->f28 = d;
        c->f2C = d != 0.0f ? 1.0f / d : 0.0f;
        c->f34 = c->p30->f10;
    }
}
static inline void merge_flush_func_002726F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002726F0 */

/* merge_units: begin func_00272770 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Word* cLListIterator_cTremorObjPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_cTremorObjPtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

void std_list_cTremorObjPtr_generic_iterator_opCast(int a0, int a1) {
    *(int*)((char*)a0) = *(int*)(char*)a1;
}

Word* std_list_cTremorObjPtr_generic_iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
static inline void merge_flush_func_00272770(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00272770 */

/* merge_units: begin func_002727B0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
static inline void QC(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
extern "C" {
void* cMemMan_Allocate(int, int, char*, int);
int std_list_cTremorObjPtr_push_back(int, int);
}
struct Obj { char pad[0xC]; int id; };
static inline const int& GetId(Obj* o) { int tmp; if (o) return o->id; tmp = -1; return tmp; }
static inline int GetId2(Obj* o) { const int* p; int tmp; if (o) p = &o->id; else { tmp = -1; p = &tmp; } return *p; }
struct Flash {
    float a; float zero; float c; float d; float b; char pad14[0xC];
    V4 col; int f30; int f34;
};
extern "C" void cTremorManager_AddTremor(void* list, V4* col, float a, float b, float c, float d)
{
    Flash* f;
    Flash* q;
    Obj* const o = 0;
    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    f = (Flash*)cMemMan_Allocate(0, 0x40, D_004A8EF0, 0x59);
    if (g_ProfileLockEnabled != 0) {
        EnableIntc(9);
    }
    g_ProfileLockDepth -= 1;
    if (f != 0) {
        f->f34 = -2;
        f->f30 = 0;
        f->a = a;
        f->b = b;
        QC(&f->col, col);
        f->c = c;
        f->d = d;
        f->zero = 0.0f;
        f->f30 = 0;
{ int tmp[2]; const int* p; if (o) p = &o->id; else { tmp[1] = -1; p = &tmp[1]; } f->f34 = *p; }
    }
    q = f;
    std_list_cTremorObjPtr_push_back((int)list, (int)&q);
}
static inline void merge_flush_func_002727B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002727B0 */

/* merge_units: begin func_002728F0 */
#pragma push /* merge_units */
extern int std_list_deleter_voidPtr_insert(int, int, int, int);

int std_list_cTremorObjPtr_push_back(int a0, int a1) {
    int loc[2];
    int a2, a3, v0;

    a3 = a1;
    v0 = a0 + 4;
    a1 = a0;
    *(int*)(char*)loc = v0;
    a0 = (int)((char*)loc + 4);
    a2 = (int)loc;
    v0 = std_list_deleter_voidPtr_insert(a0, a1, a2, a3);
    goto ret;
ret:
    return v0;
}
static inline void merge_flush_func_002728F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002728F0 */
