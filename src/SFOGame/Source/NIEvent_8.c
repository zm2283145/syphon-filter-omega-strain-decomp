/*
 * SFOGame/Source/NIEvent: 13 files, 0023C100-0023D180
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0023C100 */
#pragma push /* merge_units */
#include "types.h"
#include "vslot_pad.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#include "v4_asm_copy.h"
#include "q4r.h"
#include "vc_copy.h"
#include "net_local_id.h"

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
int sprintf(void *, const void *, ...);

typedef struct B5hObj { char pad[0x94]; struct B5hObj* next; } B5hObj;
extern void cNIEventOBJ_ActivateChildren(B5hObj* o);
void cNIEventOBJ_Activate(B5hObj* o) {
    B5hObj* n = o->next;
    while (n) {
        o = n;
        n = n->next;
    }
    cNIEventOBJ_ActivateChildren(o);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023C100(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0023C100 */

/* merge_units: begin func_0023C140 */
#pragma push /* merge_units */
int cNIEventOBJ_GetPAR(int a0) {
    int v0, v1;
    int cond;

    v1 = *(int*)((char*)a0 + 96);
    v0 = 0 + 2;
    cond = v1 != v0;
    if (cond) goto L0023C168;
    v0 = *(unsigned char*)((char*)a0 + 220);
    cond = v0 == 0;
    if (cond) goto L0023C168;
    v0 = *(int*)((char*)a0 + 320);
    goto L0023C170;
L0023C168:;
    v0 = 0;
L0023C170:;
    goto ret;
ret:
    return v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023C140(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0023C140 */

/* merge_units: begin func_0023C180 */
#pragma push /* merge_units */
int cNIEventOBJ_GetVUM(int a0) {
    int v0, v1;
    int cond;

    v1 = *(int*)((char*)a0 + 96);
    v0 = 0 + 1;
    cond = v1 == v0;
    v0 = 0 + 3;
    if (cond) goto L0023C1A8;
    cond = v1 == v0;
    if (cond) goto L0023C1A8;
    v0 = 0 + 6;
    cond = v1 != v0;
    if (cond) goto L0023C1B0;
L0023C1A8:;
    v0 = *(int*)((char*)a0 + 320);
    goto L0023C1B8;
L0023C1B0:;
    v0 = 0;
L0023C1B8:;
    goto ret;
ret:
    return v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023C180(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0023C180 */

/* merge_units: begin func_0023C1C0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V4_23C1C0 {
    float x, y, z, w;
    V4_23C1C0() {}
    V4_23C1C0(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));
struct M4_23C1C0;
extern "C" M4_23C1C0* cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(M4_23C1C0* o, const V4_23C1C0& a, const V4_23C1C0& b, const V4_23C1C0& c, const V4_23C1C0& d);
struct M4_23C1C0 { __int128 q[4];
    M4_23C1C0() {}
    M4_23C1C0(const V4_23C1C0& a, const V4_23C1C0& b, const V4_23C1C0& c, const V4_23C1C0& d) { const V4_23C1C0* pa = &a; cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(this, *pa, b, c, d); }
};
struct X_23C1C0 {
    V4_23C1C0 pos;
    M4_23C1C0 m;
    X_23C1C0(const V4_23C1C0& p, const M4_23C1C0& mm) {
        V4_23C1C0* pd = &pos;
        const V4_23C1C0* ps = &p;
        __int128 tt = V4Load(ps);
        M4_23C1C0* d = &m;
        __int128 qa;
        __int128 qb;
        const M4_23C1C0* s = &mm;
        V4Store(pd, tt);
        Q4COPY_N(d, s, qa, qb)
    }
};
typedef struct { int version; int size; unsigned int base; char* cur; } Pop_23C1C0;
struct Name_23C1C0 { char* p; Name_23C1C0(char* s) : p(s) {} };
static inline char* ReadStr_23C1C0(Pop_23C1C0* r)
{
    char* s = r->cur;
    int mis;
    while (*r->cur++)
        ;
    mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
    if (mis)
        r->cur += 4 - mis;
    return s;
}
class Tgt_23C1C0 {
public:
    VPAD8(a) VPAD4(b) VPAD2(c)
    virtual void SetXform(const X_23C1C0& x);
    virtual void SetName(const struct Name_23C1C0& n);
};
struct Self_23C1C0 {
    char pad0[0x2F];
    unsigned char b2F;
    char pad30[0x140 - 0x30];
    Tgt_23C1C0* tgt;
};
extern "C" {
extern char D_004A6FA8[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
Tgt_23C1C0* cGameParticle_ctor_cObjectIdR_int(void* p, int* desc, int v);
}
extern "C" void cNIEventOBJ_InitPAR(Self_23C1C0* self, Pop_23C1C0* r)
{
    int mis;
    X_23C1C0 x(V4_23C1C0(0.0f, 0.0f, 0.0f, 0.0f), M4_23C1C0(V4_23C1C0(1.0f, 0.0f, 0.0f, 1.0f), V4_23C1C0(0.0f, 1.0f, 0.0f, 1.0f),
                  V4_23C1C0(0.0f, 0.0f, 1.0f, 1.0f), V4_23C1C0(0.0f, 0.0f, 0.0f, 1.0f)));
    const Name_23C1C0& name = Name_23C1C0(ReadStr_23C1C0(r));
    Tgt_23C1C0* t;
    int zero;
    {
        AllocGuard g;
        t = (Tgt_23C1C0*)cMemMan_Allocate(0, 0x74, D_004A6FA8, 0x37B);
    }
    if (t) {
        zero = 0;
        t = cGameParticle_ctor_cObjectIdR_int(t, &zero, -1);
    }
    self->tgt = t;
    self->tgt->SetXform(x);
    self->tgt->SetName(name);
    self->b2F = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023C1C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0023C1C0 */

/* merge_units: begin func_0023C3C0 */
#pragma push /* merge_units */
#pragma always_inline on
#pragma cplusplus on
typedef struct { int version; int size; unsigned int base; char* cur; } Pop_23C3C0;
struct Obj_23C3C0 { char pad[0xA0]; };
struct Self_23C3C0;
struct Info_23C3C0 {
    Obj_23C3C0* a;
    Obj_23C3C0* b;
    int c;
    int d;
    char* name;
    Info_23C3C0(Obj_23C3C0* o, int cc, int dd, char* n) : a(o), b(o), c(cc), d(dd), name(n) {}
};
struct D_23C3C0 { int v; D_23C3C0(int x) : v(x) {} };
extern "C" void* cMemMan_Allocate(int pool, int size, char* file, int line);
class Tgt_23C3C0 {
public:
    VPAD8(a) VPAD4(b) VPAD2(c)
    virtual void Set40(int v);
    virtual void Set44(const Info_23C3C0& i);
    static void* operator new(unsigned int sz, char* file, int line) { AllocGuard g; return cMemMan_Allocate(0, sz, file, line); }
    char pad4[0x68];
    Self_23C3C0* owner;
    char padE[0x1F4 - 0x70];
};
struct Self_23C3C0 {
    char pad0[0x2F];
    unsigned char b2F;
    char pad30[0x140 - 0x30];
    Tgt_23C3C0* tgt;
};
static inline char* ReadStr_23C3C0(Pop_23C3C0* r)
{
    char* s = r->cur;
    int mis;
    while (*r->cur++)
        ;
    mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
    if (mis)
        r->cur += 4 - mis;
    return s;
}
extern "C" {
extern char g_Game[];
void cFileMan_ctor_void(Obj_23C3C0* o);
void cFileMan_dtor(Obj_23C3C0* o, int f);
void cFileMan_EncodeFilename_charP_cHogFileR_bool(Obj_23C3C0* o, char* path, int a, int b);
int cFileMan_Open(Obj_23C3C0* o);
void cFileMan_Close(Obj_23C3C0* o);
int cGameSystem_FindVUMGOBJ_charP_charP_cVUMGOBJPP(char* mgr, char* name, char* buf, int* out);
void cGameSystem_FindVUMGOBJ_charP_cVUMGOBJPP(char* mgr, char* buf, int* out);
void cGameSystem_AddVUMGOBJ(char* mgr, Tgt_23C3C0* t, char* name, char* buf);
void* cVUM_GOBJ_ctor_cObjectIdR(void* p, const D_23C3C0& d);
}
static inline Tgt_23C3C0* NewTgt_23C3C0() { void* m = Tgt_23C3C0::operator new(0x1F4, D_004A6FA8, 0x350); if (m) m = cVUM_GOBJ_ctor_cObjectIdR(m, D_23C3C0(0)); return (Tgt_23C3C0*)m; }
extern "C" void cNIEventOBJ_InitVUM(Self_23C3C0* self, int mode, Pop_23C3C0* r, int id)
{
    int a;
    int b;
    Obj_23C3C0 obj;
    char buf[0x40];
    char* name;
    cFileMan_ctor_void(&obj);
    name = ReadStr_23C3C0(r);
    sprintf(buf, "%s.HOG", id);
    cFileMan_EncodeFilename_charP_cHogFileR_bool(&obj, buf, mode, 1);
    if (!(unsigned char)cFileMan_Open(&obj)) {
        unsigned char found;
        a = 0;
        b = 0;
        found = cGameSystem_FindVUMGOBJ_charP_charP_cVUMGOBJPP(g_Game, name, buf, &a);
        cGameSystem_FindVUMGOBJ_charP_cVUMGOBJPP(g_Game, buf, &b);
        self->tgt = NewTgt_23C3C0();
        self->tgt->owner = self;
        if (!found) {
            cGameSystem_AddVUMGOBJ(g_Game, self->tgt, name, buf);
            a = 0;
        }
        self->tgt->Set40(0);
        self->tgt->Set44(Info_23C3C0(&obj, a, b, name));
        self->b2F = 1;
        cFileMan_Close(&obj);
    } else {
        self->tgt = 0;
    }
    cFileMan_dtor(&obj, -1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023C3C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0023C3C0 */

/* merge_units: begin func_0023C610 */
#pragma push /* merge_units */
#pragma opt_rotateloops off
#pragma opt_dead_assignments off
#pragma opt_unroll_loops off
#pragma opt_strength_reduction off
#pragma cplusplus on
#pragma inline_depth(10)
extern "C" {}
struct V4_C610 { float x, y, z, w; V4_C610() {} V4_C610(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {} } __attribute__((aligned(16)));
struct V4P_C610 { float x, y, z, w; } __attribute__((aligned(16)));
struct Mat_C610 { V4P_C610 r[4]; };
struct E64_C610 { float a; float pad4[3]; V4_C610 pos; float b[4]; float c[4]; };
struct E8_C610 { float t; unsigned char on; };
struct V64_C610 { int cap; int count; E64_C610* data; };
struct V8_C610 { int cap; int count; E8_C610* data; E8_C610& operator[](int i) { return data[i]; } };
struct OwnedVec_C610 { int w[4]; };
struct Track_C610 { float cur; OwnedVec_C610 vec; char pad14[0xC]; };
struct EvSub_C610 { int w[4]; };
struct Events_C610 { char pad0[0xC]; EvSub_C610 sub; };
struct Reader_C610 { int version; int a, b; char* cur; };
struct Self_C610;
struct Child_C610 { char pad0[0x4C]; int kind; char pad50[0x44]; Self_C610* parent; };
struct ChildVec_C610 { int cap; int count; Child_C610** data; };
struct Zero_C610 { int v; Zero_C610(int x) : v(x) {} };
class Cam_C610 {
public:
    VPAD32(a) VPAD2(b)
    virtual void SetFrame(Mat_C610* m, int f); /* +0x90 */
    static void* operator new(unsigned int sz, char* file, int line) { AllocGuard g; return cMemMan_Allocate(0, sz, file, line); }
    char pad4[0xCE0];
    unsigned char bCE4;
};
struct Self_C610 {
    VPAD16(a) VPAD4(b) VPAD2(c)
    virtual void v60(int on, V4_C610* pos);   /* +0x60 */
    VPAD8(d) VPAD2(e) VPAD1(f)
    virtual void SetFrame(Mat_C610* m, int f); /* +0x90 */
    VPAD32(g)
    virtual void v114();                      /* +0x114 */
    char pad4[8];
    int idC;
    int id10;
    char pad14[0x1C];
    int f30;
    char pad34[0x2C];
    int f60;
    char name[0x30];
    int f94;
    int pad98;
    ChildVec_C610 children;
    int padA8;
    V64_C610 keys;
    int fB8;
    int fBC;
    int fC0;
    V8_C610 flags;
    int fD0;
    int fD4;
    int fD8;
    unsigned char bDC;
    char padDD[3];
    V4_C610 posE0;
    Mat_C610 mF0;
    unsigned char b130;
    char pad131[0xF];
    Cam_C610* f140;
    Track_C610 t144;
    Track_C610 t164;
    Track_C610 t184;
    Events_C610 ev;
};
extern "C" {
extern int D_004F7C60;
extern int D_004F7C98;
extern char cNIEventOBJ_vtable[];
void cNIEventBase_ctor(Self_C610* self, int kind, void* info);
void cArray_FloatKey_ctor(OwnedVec_C610* v);
#if 0 /* merge_units */
void cArray_cFXKeyPtr_ctor(EvSub_C610* v);
#endif /* merge_units */
struct NIEventOwnedVec; /* merge_units */
NIEventOwnedVec* cArray_cFXKeyPtr_ctor(NIEventOwnedVec* self); /* merge_units */
#define cArray_cFXKeyPtr_ctor(a0) ((void)cArray_cFXKeyPtr_ctor((NIEventOwnedVec *)(a0))) /* merge_units */

void cNetObj_AddSystem(int id, int owner, Self_C610* o);
#if 0 /* merge_units */
void cNIEventOBJ_InitVUM(Self_C610* self, int mode, Reader_C610* r, char* name);
#endif /* merge_units */
#define cNIEventOBJ_InitVUM(a0, a1, a2, a3) (cNIEventOBJ_InitVUM((Self_23C3C0 *)(a0), (a1), (Pop_23C3C0 *)(a2), (int)(a3))) /* merge_units */


#if 0 /* merge_units */
void cNIEventOBJ_InitPAR(Self_C610* self, Reader_C610* r);
#endif /* merge_units */
#define cNIEventOBJ_InitPAR(a0, a1) (cNIEventOBJ_InitPAR((Self_23C1C0 *)(a0), (Pop_23C1C0 *)(a1))) /* merge_units */


Cam_C610* Camera_ConstructFov(void* p, float fov, const Zero_C610& z, Self_C610* owner);
void cNIEventFloatTrack_Init_cPopulationR(Track_C610* t, Reader_C610* r);
void std_vector_imp_VectorKey_resize(V64_C610* v, int n, const E64_C610& fill);
static inline void Assign64_C610(V64_C610* v, int n, const E64_C610& fill) { E64_C610 t; std_vector_imp_VectorKey_resize(v, 0, t); std_vector_imp_VectorKey_resize(v, n, fill); }
void std_vector_imp_VisKey_resize(V8_C610* v, int n, const E8_C610& fill);
static inline void Assign8_C610(V8_C610* v, int n, const E8_C610& fill) { std_vector_imp_VisKey_resize(v, 0, E8_C610()); std_vector_imp_VisKey_resize(v, n, fill); }
void cNIEventFXTrack_Init(Events_C610* e, Self_C610* self, Reader_C610* r);
int nGobjManager_LookupGOBJ_int_int(int region, int id);
void cTerrain_AddActivation(int found, Self_C610* o, int a, int b);
void std_vector_pod_int_resize(ChildVec_C610* v, int n, Child_C610* const& value);
static inline void AssignP_C610(ChildVec_C610* v, int n, Child_C610* const& fill) { Child_C610* z = 0; std_vector_pod_int_resize(v, 0, z); std_vector_pod_int_resize(v, n, fill); }
void cGOBJ_DestroyXform(Self_C610* o);
void cGOBJ_CreateMovementInfo_void(Self_C610* o);
void cNIEventOBJ_UpdateChildren(Self_C610* o);
float cVector_X_void(V4_C610* v);
float cVector_Y_void(V4_C610* v);
float cVector_Z_void(V4_C610* v);
void cMatrix_SetWithAxisAngle(Mat_C610* m, float x, float y, float z, float a);
void cMatrix_ctor_void(Mat_C610* m);
void cMatrix_Rotate(Mat_C610* a, Mat_C610* b);
}
static inline int RdI_C610(Reader_C610* r) { int t = *(int*)r->cur; r->cur += 4; return t; }
static inline float RdF_C610(Reader_C610* r) { float t = *(float*)r->cur; r->cur += 4; return t; }
static inline void ReadF_C610(Reader_C610* r, float* out) { *out = *(float*)r->cur; r->cur += 4; }
static inline void ReadI_C610(Reader_C610* r, int* out) { *out = *(int*)r->cur; r->cur += 4; }
static inline void ReadId_C610(Reader_C610* r, int* out)
{
    int hi = RdI_C610(r);
    int lo = RdI_C610(r);
    *out = lo | (hi << 16);
}
static inline void Align_C610(Reader_C610* r)
{
    int rem;
    char* ptr = r->cur;
    rem = (int)((unsigned long long)(unsigned int)ptr & 3);
    if (rem) r->cur = ptr + (4 - rem);
}
static inline char* ReadStr_C610(Reader_C610* r)
{
    char* s = r->cur;
    while (*r->cur++)
        ;
    Align_C610(r);
    return s;
}
static inline Cam_C610* NewCam_C610(Self_C610* self)
{
    void* m = Cam_C610::operator new(0xCF0, D_004A6FA8, 0x32D);
    if (m) m = Camera_ConstructFov(m, 1.134464f, Zero_C610(0), self);
    return (Cam_C610*)m;
}
static inline void MCopy_C610(void* d, const void* s) {
    __int128 qa, qb;
    __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory");
}
static inline void VCX_C610(void* d0, const void* s0) { const void* s = s0; void* d = d0; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
static inline E8_C610* Fl_C610(V8_C610* v) { E8_C610** pd = &v->data; return *pd; }
static inline float D2R_C610(float d) { return d * 0.017453292f; }
static inline void MakeRot_C610(Mat_C610* m, const V4_C610& ax, float ang)
{
    cMatrix_SetWithAxisAngle(m, cVector_X_void((V4_C610*)&ax), cVector_Y_void((V4_C610*)&ax), cVector_Z_void((V4_C610*)&ax), ang);
}
static inline void RotMul_C610(Mat_C610* a, const V4_C610& ax, float ang)
{
    Mat_C610 rot;
    cMatrix_ctor_void(&rot);
    cMatrix_SetWithAxisAngle(&rot, ax.x, ax.y, ax.z, ang);
    cMatrix_Rotate(a, &rot);
}
extern "C" Self_C610* cNIEventOBJ_ctor(Self_C610* self, int mode, Reader_C610* r)
{
    volatile int id;
    char* name;
    int n;
    int i;
    cNIEventBase_ctor(self, 0x10, &D_004F7C60);
    *(void**)self = cNIEventOBJ_vtable;
    { Track_C610* t = &self->t144; cArray_FloatKey_ctor(&t->vec); }
    { Track_C610* t = &self->t164; cArray_FloatKey_ctor(&t->vec); }
    { Track_C610* t = &self->t184; cArray_FloatKey_ctor(&t->vec); }
    { Events_C610* t = &self->ev; cArray_cFXKeyPtr_ctor(&t->sub); }
    if (r->version >= 0x3F) {
        name = ReadStr_C610(r);
        Libc_Strcpy(self->name, name);
    } else {
        name = 0;
    }
    ReadId_C610(r, (int*)&id);
    self->idC = id;
    if (g_IsMultiplayer) {
        self->id10 = self->idC;
        {
            int t = self->id10;
            int a = D_005721A8; int rr = 0;
            if (*(volatile unsigned char*)&g_IsMultiplayer) { if (D_00494178 == -1) NetGetMyClientIndex(&D_00494178, a); rr = D_00494178; } else { asm { .set reorder } }
            cNetObj_AddSystem(t, rr, self);
        }
    }
    ReadI_C610(r, &self->f60);
    switch (self->f60) {
    case 1:
        cNIEventOBJ_InitVUM(self, mode, r, name);
        break;
    case 3:
    case 6:
        cNIEventOBJ_InitVUM(self, mode, r, name);
        break;
    case 2:
        cNIEventOBJ_InitPAR(self, r);
        break;
    case 5: {
        Cam_C610* c;
        ReadStr_C610(r);
        c = NewCam_C610(self);
        c->bCE4 = 1;
        self->f140 = c;
        break;
    }
    case 4:
        self->f140 = 0;
        ReadStr_C610(r);
        break;
    }
    n = RdI_C610(r);
    if (n)
        self->fBC = (int)(RdF_C610(r) - 1.0f);
    Assign64_C610(&self->keys, n, E64_C610());
    for (i = 0; i < n; i++) {
        ReadF_C610(r, &self->keys.data[i].a);
        ReadF_C610(r, &self->keys.data[i].pos.x);
        ReadF_C610(r, &self->keys.data[i].pos.y);
        ReadF_C610(r, &self->keys.data[i].pos.z);
        *(int*)&self->keys.data[i].pos.w = 0x3F800000;
        ReadF_C610(r, &self->keys.data[i].b[0]);
        ReadF_C610(r, &self->keys.data[i].b[1]);
        ReadF_C610(r, &self->keys.data[i].b[2]);
        ReadF_C610(r, &self->keys.data[i].c[0]);
        ReadF_C610(r, &self->keys.data[i].c[1]);
        ReadF_C610(r, &self->keys.data[i].c[2]);
    }
    cNIEventFloatTrack_Init_cPopulationR(&self->t144, r);
    cNIEventFloatTrack_Init_cPopulationR(&self->t164, r);
    cNIEventFloatTrack_Init_cPopulationR(&self->t184, r);
    n = RdI_C610(r);
    if (n) {
        self->fD4 = (int)(RdF_C610(r) - 1.0f);
        {
            Assign8_C610(&self->flags, n, E8_C610());
        }
        int j;
        for (j = 0; j < n; j++) {
            ReadF_C610(r, &self->flags.data[j].t);
            self->flags[j].on = RdF_C610(r) != 0.0f;
        }
    } else {
        self->fD4 = -1;
        {
            Assign8_C610(&self->flags, 1, E8_C610());
        }
        self->flags[0].t = 0.0f;
        self->flags[0].on = 1;
    }
    if (r->version >= 0x38)
        cNIEventFXTrack_Init(&self->ev, self, r);
    {
    int k;
    int cnt = RdI_C610(r);
    for (k = 0; k < cnt; k++) {
        int a = RdI_C610(r);
        int b = RdI_C610(r);
        int found = nGobjManager_LookupGOBJ_int_int(a, b);
        if (found)
            cTerrain_AddActivation(found, self, 1, found);
    }
    }
    self->f94 = 0;
    {
    int j;
    int cn = RdI_C610(r);
    AssignP_C610(&self->children, cn, 0);
    for (j = 0; j < cn; j++) {
        int a = RdI_C610(r);
        int b = RdI_C610(r);
        Child_C610* c = (Child_C610*)nGobjManager_LookupGOBJ_int_int(a, b);
        if (c->kind == D_004F7C60) {
            self->children.data[j] = c;
            c->parent = self;
        } else if (c->kind == D_004F7C98) {
            self->children.data[j] = c;
            c->parent = self;
        }
    }
    }
    V4_C610* pp = &self->posE0;
    VCX_C610(pp, &self->keys.data[0].pos);
    self->bDC = Fl_C610(&self->flags)->on;
    self->v60(1, pp);
    cGOBJ_DestroyXform(self);
    {
        Mat_C610 m;
        MakeRot_C610(&m, V4_C610(1.0f, 0.0f, 0.0f, 0.0f), D2R_C610(self->t144.cur));
        RotMul_C610(&m, V4_C610(0.0f, 1.0f, 0.0f, 0.0f), D2R_C610(self->t164.cur));
        RotMul_C610(&m, V4_C610(0.0f, 0.0f, 1.0f, 0.0f), D2R_C610(self->t184.cur));
        VCX_C610(&m.r[3], &self->posE0);
        { Mat_C610* dst = &self->mF0; Mat_C610* src = &m; MCopy_C610(dst, src); }
        self->SetFrame(&m, 0);
        if (self->f60 == 1) {
            cGOBJ_CreateMovementInfo_void(self);
            self->f30 = 0;
        }
        if (*(Cam_C610* volatile*)&self->f140) {
            int k = self->f60;
            if (k == 1 || k == 3 || k == 6)
                self->f140->SetFrame(&m, 0);
        }
    }
    if (r->version >= 0x44) {
        self->b130 = *(unsigned char*)r->cur;
        r->cur++;
        Align_C610(r);
    } else {
        self->b130 = 0;
    }
    if (self->b130)
        self->v114();
    self->fC0 = 0;
    self->fD8 = 0;
    cNIEventOBJ_UpdateChildren(self);
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023C610(void) {}
#undef cArray_cFXKeyPtr_ctor /* merge_units */
#undef cNIEventOBJ_InitVUM /* merge_units */
#undef cNIEventOBJ_InitPAR /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023C610 */

/* merge_units: begin func_0023D180 */
#pragma push /* merge_units */
#include "NIEvent_types.h"

/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern NIEventVec3* std_vector_imp_cFXKeyPtr_1_ctor(NIEventVec3* vec);

/* Constructs an empty vector that owns its storage. */
NIEventOwnedVec* cArray_cFXKeyPtr_ctor(NIEventOwnedVec* self) {
    std_vector_imp_cFXKeyPtr_1_ctor(&self->vec);
    self->owned = 1;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023D180(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0023D180 */

/* merge_units: begin func_0023D1B0 */
#pragma push /* merge_units */
/* Constructs an empty vector. */
NIEventVec3* std_vector_imp_cFXKeyPtr_1_ctor(NIEventVec3* vec) {
    vec->begin = 0;
    vec->end = 0;
    vec->cap = 0;
    return vec;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023D1B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0023D1B0 */

/* merge_units: begin func_0023D1D0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Rebuilds the cached transform: row 3 takes the position, rows 0-2 are left as they were on the stack. */

typedef struct Q16 { __int128 q; } Q16;
typedef struct M64 { __int128 r[3]; Q16 t; } M64;

class Obj {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
    virtual void Update(); /* 0x120 */
    virtual void v47(); virtual void v48();
    virtual unsigned char TestA(float dt); /* 0x12C */
    virtual unsigned char TestB(float dt); /* 0x130 */

    char pad04[0x5C];
    int state;          /* 0x60 */
    char pad64[0x7C];
    Q16 pos;            /* 0xE0 */
    M64 mtx;            /* 0xF0 */
};

extern "C" void cNIEventBase_UpdateAll(Obj* self, float dt)
{
    unsigned char a = self->TestA(dt);
    unsigned char b = self->TestB(dt);
    if (a || b) {
        if (self->state != 3) {
            M64 m; __int128 t; __int128 qa; M64* d; M64* s; __int128 qb; Q16* pt;
            pt = &m.t; t = VLoadF(&self->pos); s = &m; d = &self->mtx; VStoreN(pt, t);
            Q4COPY_N(d, s, qa, qb)
        }
        self->Update();
    }
}
static inline void merge_flush_func_0023D1D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023D1D0 */

/* merge_units: begin func_0023D290 */
#pragma push /* merge_units */
// cNIEventBase::UpdatePos(float) (NIEvent.cc). Inline nesting depth (Eval2->Eval1->Eval, At->At1->At0, Scl/Neg2 wrappers) controls MW's
// stack-temp order and register coloring; VP members (no ctor) + explicit do-while give the array-ctor loop on t=this.
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
/*PRAGMAS*/
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(&o) : "memory"); }
    V& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); return *this; }
    void Set128(const V& o) { V* d = this; __int128 t; __asm__("lq %0, 0x0(%0)" : "=r"(t) : "0"(&o)); void* xx = (void*)&o; __asm__("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
    V operator-(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory");
        return c;
    }
    V operator+(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory");
        return c;
    }
    V operator*(float s) const {
        V c; __int128 t = 0; V* q = &c; const V* v = this;
        __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory");
        return c;
    }
    float Dot(const V& b) const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this), "r"(&b) : "memory");
        return r;
    }
    void Normalize() {
        __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(this) : "memory");
    }
    V Unit() const { V r = *this; r.Normalize(); return r; }
} __attribute__((aligned(16)));
static inline float Sqrt(float x) { float r = 0.0f; __asm__ volatile("sqrt.s %0, %1" : "+f"(r) : "f"(x)); return r; }
static inline float Max(float a, float b) { float r = 0.0f; __asm__ volatile("max.s %0, %1, %2" : "+f"(r) : "f"(a), "f"(b)); return r; }
struct cBox { V mn; V mx; };
extern "C" {
void cBox_Empty(cBox* b);
void cBox_Include(cBox* b, const V* v);
void cBox_Grow(cBox* b, float f);
V cVector_opAdd(const V* a, const V* b);
}
struct VectorKey { float time; char pad[12]; V value; V inTangent; V outTangent; };
struct VKArray { int cap; int count; VectorKey* data; int f; VectorKey& operator[](int i) { return data[i]; } VectorKey& At0(int i) { VectorKey*& d = data; return d[i]; } VectorKey& At1(int i) { return At0(i); } VectorKey& At(int i) { return At1(i); } };
struct VP { float x, y, z, w; VP& operator=(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); return *this; } } __attribute__((aligned(16))); struct CP { VP pos; VP tan; };
struct cHermiteSpline {
    CP mControlPoints[2];
    cHermiteSpline(const V& p0, const V& t0, const V& p1, const V& t1) { cHermiteSpline* t = this; CP* p = t->mControlPoints; do { p++; } while (p != t->mControlPoints + 2);  t->mControlPoints[0].pos = p0; t->mControlPoints[0].tan = t0; CP* b = &t->mControlPoints[1]; t->mControlPoints[1].pos = p1; b->tan = t1; }
};
extern "C" {
#if 0 /* merge_units */
VectorKey* std_vector_VectorKey_opIndex(VKArray* v, unsigned int i);
#endif /* merge_units */
char* std_vector_VectorKey_opIndex(char* self, int i); /* merge_units */
#define std_vector_VectorKey_opIndex(a0, a1) ((VectorKey *)std_vector_VectorKey_opIndex((char *)(a0), (int)(a1))) /* merge_units */


CP* cArray_FixedSize_cHermiteSplineControlPoint_cVector_2_opIndex(const cHermiteSpline* s, unsigned int i);
const V* cHermiteSplineControlPoint_cVector_Position(const CP* c);
const V* cHermiteSplineControlPoint_cVector_Tangent(const CP* c);
V opMul(float f, const V* v);
}
static inline V operator*(float s, V v) { V* p = &v; return *p * s; }
static inline V Neg(const V& a) { V c; __asm__ volatile("lqc2 $vf1, 0x0(%1); vmulax.xyzw $ACC, $vf0, $vf0x; vmsubw.xyzw $vf1, $vf1, $vf0w; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(&a) : "memory"); return c; }
static inline V Eval(const cHermiteSpline* s, float t) {
    float t2 = t * t;
    float t3 = t2 * t;
    float h00 = 1.0f + (2.0f * t3 - 3.0f * t2);
    float h01 = -2.0f * t3 + 3.0f * t2;
    float h10 = t + (t3 - 2.0f * t2);
    float h11 = t3 - t2;
    return cVector_opAdd(&cVector_opAdd(&cVector_opAdd(&opMul(h00, cHermiteSplineControlPoint_cVector_Position(cArray_FixedSize_cHermiteSplineControlPoint_cVector_2_opIndex(s, 0))), &opMul(h01, cHermiteSplineControlPoint_cVector_Position(cArray_FixedSize_cHermiteSplineControlPoint_cVector_2_opIndex(s, 1)))), &opMul(h10, cHermiteSplineControlPoint_cVector_Tangent(cArray_FixedSize_cHermiteSplineControlPoint_cVector_2_opIndex(s, 0)))), &opMul(h11, cHermiteSplineControlPoint_cVector_Tangent(cArray_FixedSize_cHermiteSplineControlPoint_cVector_2_opIndex(s, 1))));
}
static inline V Scl(const V& v, float s) { return v * s; } static inline V Neg2(const V& a) { return Neg(a); } static inline V Eval1(const cHermiteSpline* s, float t) { return Eval(s, t); } static inline V Eval2(const cHermiteSpline* s, float t) { return Eval1(s, t); }
struct cNIEventBase {
    char gobj[0xAC];
    VKArray mPosKeys;
    int mPosORT;
    float mPosTime;
    char pad_c4[0x1C];
    V mPos;
};
extern "C" unsigned char cNIEventBase_UpdatePos(cNIEventBase* self, float timeStep) {
    int posKey = self->mPosKeys.count - 1;
    float posScalar;
    float timeSpan;
    int i;
    if (posKey == 0) return 0;
    posScalar = 0.0f;
    self->mPosTime += timeStep;
    for (i = 0; i < self->mPosKeys.count - 1; i++) {
        if (!(self->mPosTime < self->mPosKeys[i].time) && self->mPosTime < self->mPosKeys[i + 1].time) {
            timeSpan = self->mPosKeys[i + 1].time - self->mPosKeys[i].time;
            posKey = i;
            posScalar = (self->mPosTime - self->mPosKeys[i].time) / timeSpan;
            break;
        }
    }
    if (posKey == self->mPosKeys.count - 1) {
        if (self->mPosORT == -1) {
            self->mPosTime = self->mPosKeys[posKey].time;
            self->mPos = self->mPosKeys[posKey].value;
            return 1;
        }
        int ort = self->mPosORT;
        float leftOver = self->mPosTime - self->mPosKeys[posKey].time;
        self->mPosTime = leftOver + self->mPosKeys[ort].time;
        posKey = ort;
        self->mPosTime = self->mPosKeys[posKey].time;
        timeSpan = self->mPosKeys[posKey + 1].time - self->mPosKeys[posKey].time;
        posScalar = self->mPosTime / timeSpan;
    }
    cHermiteSpline PosSpline(self->mPosKeys.At(posKey).value, Scl(std_vector_VectorKey_opIndex(&self->mPosKeys, posKey)->outTangent, timeSpan), self->mPosKeys.At(posKey + 1).value, timeSpan * Neg2(std_vector_VectorKey_opIndex(&self->mPosKeys, posKey + 1)->inTangent));
    self->mPos.Set128(Eval2(&PosSpline, posScalar));
    self->mPos.w = 1.0f;
    bool ok = true;
    return ok;
}
#undef std_vector_VectorKey_opIndex /* merge_units */
static inline void merge_flush_func_0023D290(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023D290 */

/* merge_units: begin func_0023D6C0 */
#pragma push /* merge_units */
/* Address of element i in an array of 0x40-byte records whose base pointer is at +8. */
char* std_vector_VectorKey_opIndex(char* self, int i) {
    return *(char**)(self + 8) + (i << 6);
}
static inline void merge_flush_func_0023D6C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023D6C0 */

/* merge_units: begin func_0023D6D0 */
#pragma push /* merge_units */
#pragma cplusplus on
/* cNIEventBase::UpdateVis: advances the visibility track time, finds the active key
 * (wrapping to the out-of-range-type key when the track has run past its last key)
 * and reports whether the visibility flag changed. */
struct VisKey { float time; unsigned char visible; };
template <class T> struct cArray {
    int x0;
    int size;
    T* data;
    int xC;
    int Size() const { return size; }
    T& operator[](unsigned int i) { return data[i]; } /* std::vector::operator[](unsigned int) */
};
class cNIEventBase_0023D6D0 {
public:
    char pad0[0xC4];
    cArray<VisKey> mVisKeys;
    int mVisORT;
    float mVisTime;
    unsigned char mVisible;
};
extern "C" bool cNIEventBase_UpdateVis(cNIEventBase_0023D6D0* self, float timeStep)
{
    int visKey = self->mVisKeys.Size() - 1;
    int i;
    float leftOver;
    unsigned char oldVis;
    if (visKey == 0) return false;
    self->mVisTime += timeStep;
    for (i = 0; i < self->mVisKeys.Size() - 1; i++) {
        if (self->mVisTime >= self->mVisKeys[i].time && self->mVisTime < self->mVisKeys[i + 1].time) {
            visKey = i;
            break;
        }
    }
    if (visKey == self->mVisKeys.Size() - 1) {
        if (self->mVisORT == -1) {
            self->mVisTime = self->mVisKeys[visKey].time;
            self->mVisible = self->mVisKeys[visKey].visible;
            return true;
        }
        leftOver = self->mVisTime - self->mVisKeys[visKey].time;
        visKey = self->mVisORT;
        self->mVisTime = leftOver + self->mVisKeys[visKey].time;
    }
    oldVis = self->mVisible;
    self->mVisible = self->mVisKeys[visKey].visible;
    return self->mVisible != oldVis;
}
static inline void merge_flush_func_0023D6D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023D6D0 */

/* merge_units: begin func_0023D810 */
#pragma push /* merge_units */
typedef struct Node Node_;
typedef struct NodeObj {
    char pad00[0x2C];
    unsigned char f2C;  /* 0x2C */
    unsigned char f2D;  /* 0x2D */
    unsigned char f2E;  /* 0x2E */
    char pad2F[0x60 - 0x2F];
    int state;          /* 0x60 */
    char pad64[0x9C - 0x64];
    PtrVec kids;        /* 0x9C */
} NodeObj;

extern int std_vector_cNIEventBasePtr_size(PtrVec* v);
extern int cArray_cNIEventBasePtr_Size(PtrVec* v);
extern int* cArray_cNIEventBasePtr_opIndex(PtrVec* v, int i);
extern int* std_vector_imp_cNIEventBasePtr_1_opIndex(PtrVec* v, int i);
extern int cGOBJ_IsStreaming(NodeObj* o);
extern int cGOBJ_IsActive(NodeObj* o);

#define COUNTS(o, flag) (!(flag) || (o)->state == 3 || (o)->state == 1 || (o)->state == 6)
#pragma push
#pragma opt_strength_reduction off

int cNIEventBase_NumChildrenActive(NodeObj* self, int flag)
{
    int total = 0; int ok;
    int i;
    ok = self->f2D != 0 && self->f2C != 0 && !(self->f2E != 0); if (ok) {
        if (COUNTS(self, flag)) total++;
    }
    for (i = 0; i < self->kids.count; i++) {
        NodeObj* c = (NodeObj*)self->kids.data[i];
        int n = 0;
        int j;
        ok = c->f2D != 0 && c->f2C != 0 && !(cGOBJ_IsStreaming(c) != 0); if (ok) {
            if (COUNTS(c, flag)) n++;
        }
        for (j = 0; j < std_vector_cNIEventBasePtr_size(&c->kids); j++) {
            NodeObj* g = *(NodeObj**)std_vector_imp_cNIEventBasePtr_1_opIndex(&c->kids, j);
            int m = 0;
            int k;
            if (cGOBJ_IsActive(g)) {
                if (COUNTS(g, flag)) m++;
            }
            for (k = 0; k < cArray_cNIEventBasePtr_Size(&g->kids); k++) {
                m += cNIEventBase_NumChildrenActive(*(NodeObj**)cArray_cNIEventBasePtr_opIndex(&g->kids, k), flag);
            }
            n += m;
        }
        total += n;
    }
    return total;
}
#pragma pop
static inline void merge_flush_func_0023D810(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0023D810 */
