/*
 * SFOGame/Source/NIEvent: 5 files, 002397F0-00239CF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002397F0 */
#pragma push /* merge_units */
#include "types.h"
#include "vslot_pad.h"

#pragma cplusplus on
struct H_2397F0 { int v; };
struct P_2397F0 {
    int id;
    char pad04[0xC];
    __int128 mask;
    int w20;
    H_2397F0 h24;
    char pad28[8];
    int w30, w34, w38;
    char pad3C[0x0C];
    char memberA[0x9C];
    char memberB[0x9C];
    int w180;
    short h184;
    unsigned char b186;
};
struct Track_2397F0 {
    void* vtable;
    float time;
    int kind;
    int pad0C;
    P_2397F0 snd;
};
struct Reader_2397F0 { int version; int size; unsigned int base; char* cur; };
struct Owner_2397F0 { char pad[0xC]; unsigned int flags; };
extern "C" {
extern char D_004DC038[];
extern void * const D_004DC018[];
void cSoundFXKey_Execute();
extern char** D_004F7C70;
extern int D_004F7C78;
extern int D_004F7C80;
extern int D_0048AE28;
void cFileMan_ctor_void(void* m);
void cSndFx_SetSndFx(void* action, int kind, char* name, Owner_2397F0* owner, int x);
}
static inline float RdF(Reader_2397F0* r){ float t = *(float*)r->cur; r->cur += 4; return t; }
#pragma push
#pragma opt_propagation off
extern "C" Track_2397F0* cSoundFXKey_ctor(Track_2397F0* self, Reader_2397F0* r, Owner_2397F0* o)
{
    P_2397F0* p;
    int id;
    char* name;
    self->vtable = D_004DC038;
    self->kind = 2;
    self->time = RdF(r);
    self->vtable = (void*)D_004DC018;
    *(int*)((char*)self + 0x34) = -2;
    *(int*)((char*)self + 0x30) = 0;
    p = &self->snd;
    cFileMan_ctor_void(p->memberA);
    cFileMan_ctor_void(p->memberB);
    p->id = -1;
    p->mask = -1;
    p->w20 = 0;
    { H_2397F0 h; H_2397F0* hp = &h; h.v = -1; p->h24 = *hp; }
    p->w30 = 0;
    p->w34 = 0;
    p->w38 = 0;
    p->h184 = -1;
    p->w180 = 0;
    p->b186 = 0;
    id = (int)*(float*)r->cur;
    r->cur += 4;
    if ((o->flags & 0xFF0000) >> 16 != D_0048AE28)
        id += D_004F7C80;
    name = id < D_004F7C78 ? D_004F7C70[id] : 0;
    {
        int k = (int)*(float*)r->cur;
        r->cur += 4;
        cSndFx_SetSndFx(&self->snd, k, name, o, 0);
    }
    return self;
}
#pragma pop
extern "C" void * const D_004DC018[3] = { (void*)0x0, (void*)0x0, (void*)cSoundFXKey_Execute };
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002397F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002397F0 */

/* merge_units: begin func_00239960 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; float c; float d; float a; float b; } S239960;
extern void Blast_Prepare(int, int, int, int, int, int, float, float, float);
void cBlastFXKey_Execute(S239960* s, int x)
{
    Blast_Prepare(x, (int)s->a, 1, 0, 0, 0, s->b, s->c, s->d);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00239960(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00239960 */

/* merge_units: begin func_002399A0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Obj2399A0 { VPAD32(a) VPAD32(b) VPAD4(c) virtual void Enable(int on); };
struct Msg2399A0 { void* vtable; char base[0x20]; int f24; char p28[8]; };
struct Ev2399A0 { char p[8]; int kind; };
extern "C" {
extern char D_004F7C30[];
extern char D_004DBEB0[];
void cMessage_ctor_cMessageNameR(void* m, void* type);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
}
extern "C" void cFXKey_Execute(Ev2399A0* ev, Obj2399A0* o) {
    switch (ev->kind) {
    case 0: {
        Msg2399A0 m;
        o->Enable(0);
        cMessage_ctor_cMessageNameR(&m, D_004F7C30);
        m.vtable = D_004DBEB0;
        m.f24 = 1;
        QueueMessage_cMessageR_cSystemP_int(&m, o, 0);
        m.vtable = D_004DBEB0;
        cMessage_dtor(&m, 0);
        break;
    }
    case 3: {
        Msg2399A0 m;
        cMessage_ctor_cMessageNameR(&m, D_004F7C30);
        m.vtable = D_004DBEB0;
        m.f24 = 0;
        QueueMessage_cMessageR_cSystemP_int(&m, o, 0);
        m.vtable = D_004DBEB0;
        cMessage_dtor(&m, 0);
        break;
    }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002399A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002399A0 */

/* merge_units: begin func_00239A90 */
#pragma push /* merge_units */
// cNIEventFloatTrack::Update. cHermiteSpline built via default ctor + Init() member (array-ctor do-while in Init) and
// `cHermiteSpline* hp = &FloatSpline; hp->Init(...)` so the this-pointer vreg is created before the arg vregs (fixes t1/t2 coloring).
#pragma cplusplus on

struct Key { float time; float value; float inTan; float outTan; };
struct cArray { int cap; int count; Key* data; int pad; int Count() const { return count; } Key& operator[](unsigned int i) { return data[i]; } };
struct CP { float value; float tangent; CP() {} };
struct cHermiteSpline {
    CP mControlPoints[2];
    void Init(const float& p0, float m0, const float& p1, float m1) { cHermiteSpline* t = this; CP* p = t->mControlPoints; do { p++; } while (p != t->mControlPoints + 2); t->mControlPoints[0].value = p0; t->mControlPoints[0].tangent = m0; t->mControlPoints[1].value = p1; t->mControlPoints[1].tangent = m1; }
    cHermiteSpline() {}
    cHermiteSpline(const float& p0, float m0, const float& p1, float m1)
    {
        cHermiteSpline* t = this; CP* p = t->mControlPoints; do { p++; } while (p != t->mControlPoints + 2);
        t->mControlPoints[0].value = p0;
        t->mControlPoints[0].tangent = m0;
        t->mControlPoints[1].value = p1;
        t->mControlPoints[1].tangent = m1;
    }
    float Evaluate(float t)
    {
        float t2 = t * t;
        float t3 = t2 * t;
        CP* a = &mControlPoints[0];
        CP* b = &mControlPoints[1];
        float h00 = 2.0f * t3 - 3.0f * t2 + 1.0f; float h01 = -2.0f * t3 + 3.0f * t2; float h10 = t3 - 2.0f * t2 + t; float h11 = t3 - t2; return h00 * a->value + h01 * b->value + h10 * a->tangent + h11 * b->tangent;
    }
};
struct cNIEventFloatTrack {
    float mValue;
    cArray mFloatKeys;
    int mFloatORT;
    float mFloatTime;
    unsigned char mPlaying;
    Key& K(int i) { return mFloatKeys[i]; }
    cArray& Keys() { return mFloatKeys; }
};
extern "C" unsigned char cNIEventFloatTrack_Update(cNIEventFloatTrack* self, float timeStep);

unsigned char cNIEventFloatTrack_Update(cNIEventFloatTrack* self, float timeStep)
{
    int floatKey = self->mFloatKeys.Count() - 1;
    float floatScalar;
    float timeSpan;
    int i;
    if (!self->mPlaying || floatKey == 0)
        return 0;
    floatScalar = 0.0f;
    self->mFloatTime += timeStep;
    for (i = 0; i < self->mFloatKeys.Count() - 1; i++) {
        if (self->mFloatTime >= self->mFloatKeys[i].time && self->mFloatTime < self->mFloatKeys[i + 1].time) {
            floatKey = i;
            timeSpan = self->Keys()[i + 1].time - self->Keys()[i].time;
            floatScalar = (self->mFloatTime - self->Keys()[i].time) / timeSpan;
            break;
        }
    }
    if (floatKey == self->mFloatKeys.Count() - 1) {
        if (self->mFloatORT == -1) {
            self->mFloatTime = self->mFloatKeys[floatKey].time;
            self->mValue = self->mFloatKeys[floatKey].value;
            self->mPlaying = 0;
            return 1;
        }
        floatKey = self->mFloatORT;
        self->mFloatTime = self->mFloatKeys[floatKey].time;
        timeSpan = self->mFloatKeys[floatKey + 1].time - self->mFloatKeys[floatKey].time;
        floatScalar = self->mFloatTime / timeSpan;
    }
    cHermiteSpline FloatSpline;
    cHermiteSpline* hp = &FloatSpline;
    hp->Init(self->mFloatKeys[floatKey].value, timeSpan * self->mFloatKeys[floatKey].outTan,
                               self->mFloatKeys[floatKey + 1].value, timeSpan * -self->mFloatKeys[floatKey + 1].inTan);
    self->mValue = FloatSpline.Evaluate(floatScalar);
    return 1;
}
static inline void merge_flush_func_00239A90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00239A90 */

/* merge_units: begin func_00239CF0 */
#pragma push /* merge_units */
/* NiEvent float track init: one key {0, f, 0, 0}; value-initialised Key temporaries give the byte-zero loops. */
#pragma cplusplus on
struct Key_239CF0 { float a; float t; float c; float d; };
struct Vec_239CF0 {
    int capacity; int count; Key_239CF0* data;
};
struct Track_239CF0 {
    float cur;
    Vec_239CF0 keys;
    int pad10;
    int w14;
    int w18;
    unsigned char b1C;
};
extern "C" void std_vector_imp_FloatKey_resize(Vec_239CF0* v, unsigned int n, const Key_239CF0& value);
static inline void Assign_239CF0(Vec_239CF0* v, unsigned int n, const Key_239CF0& fill = Key_239CF0()) { std_vector_imp_FloatKey_resize(v, 0, Key_239CF0()); std_vector_imp_FloatKey_resize(v, n, fill); }
extern "C" void cNIEventFloatTrack_Init_float(Track_239CF0* self, float f)
{
    Assign_239CF0(&self->keys, 1);
    self->keys.data[0].a = 0;
    self->keys.data[0].t = f;
    self->keys.data[0].c = 0;
    self->keys.data[0].d = 0;
    self->w14 = -1;
    self->b1C = 0;
    self->cur = f;
    self->w18 = 0;
    {
        Key_239CF0** pd = &self->keys.data;
        if (self->keys.count > 0)
            self->cur = (*pd)[0].t;
    }
}
static inline void merge_flush_func_00239CF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00239CF0 */
