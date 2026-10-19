/*
 * main/NIEvent: range (6 files, 0023C100-0023C610)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
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

/* merge_units: begin func_0023C100 */
#pragma push /* merge_units */
typedef struct B5hObj { char pad[0x94]; struct B5hObj* next; } B5hObj;
extern void NiEvent_SetTreePresence(B5hObj* o);
void cNIEventOBJ_v15(B5hObj* o) {
    B5hObj* n = o->next;
    while (n) {
        o = n;
        n = n->next;
    }
    NiEvent_SetTreePresence(o);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023C100(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0023C100 */

/* merge_units: begin func_0023C140 */
#pragma push /* merge_units */
int func_0023C140(int a0) {
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
int cNIEventOBJ_v47(int a0) {
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
extern "C" M4_23C1C0* Mtx_FromRowsAndTranslation(M4_23C1C0* o, const V4_23C1C0& a, const V4_23C1C0& b, const V4_23C1C0& c, const V4_23C1C0& d);
struct M4_23C1C0 { __int128 q[4];
    M4_23C1C0() {}
    M4_23C1C0(const V4_23C1C0& a, const V4_23C1C0& b, const V4_23C1C0& c, const V4_23C1C0& d) { const V4_23C1C0* pa = &a; Mtx_FromRowsAndTranslation(this, *pa, b, c, d); }
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
void* Mem_Alloc(int pool, int size, char* file, int line);
Tgt_23C1C0* ParticleGob_Create(void* p, int* desc, int v);
}
extern "C" void NiEvent_LoadParticleAsset(Self_23C1C0* self, Pop_23C1C0* r)
{
    int mis;
    X_23C1C0 x(V4_23C1C0(0.0f, 0.0f, 0.0f, 0.0f), M4_23C1C0(V4_23C1C0(1.0f, 0.0f, 0.0f, 1.0f), V4_23C1C0(0.0f, 1.0f, 0.0f, 1.0f),
                  V4_23C1C0(0.0f, 0.0f, 1.0f, 1.0f), V4_23C1C0(0.0f, 0.0f, 0.0f, 1.0f)));
    const Name_23C1C0& name = Name_23C1C0(ReadStr_23C1C0(r));
    Tgt_23C1C0* t;
    int zero;
    {
        AllocGuard g;
        t = (Tgt_23C1C0*)Mem_Alloc(0, 0x74, D_004A6FA8, 0x37B);
    }
    if (t) {
        zero = 0;
        t = ParticleGob_Create(t, &zero, -1);
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
extern "C" void* Mem_Alloc(int pool, int size, char* file, int line);
class Tgt_23C3C0 {
public:
    VPAD8(a) VPAD4(b) VPAD2(c)
    virtual void Set40(int v);
    virtual void Set44(const Info_23C3C0& i);
    static void* operator new(unsigned int sz, char* file, int line) { AllocGuard g; return Mem_Alloc(0, sz, file, line); }
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
void Resource_Construct(Obj_23C3C0* o);
void FileMan_Release(Obj_23C3C0* o, int f);
void Hog_Register(Obj_23C3C0* o, char* path, int a, int b);
int FileMan_FindMember(Obj_23C3C0* o);
void func_0036DEC0(Obj_23C3C0* o);
int func_00131010(char* mgr, char* name, char* buf, int* out);
void Game_FindNamedResource(char* mgr, char* buf, int* out);
void func_00130D10(char* mgr, Tgt_23C3C0* t, char* name, char* buf);
void* cVUM_GOBJ_ctor2(void* p, const D_23C3C0& d);
}
static inline Tgt_23C3C0* NewTgt_23C3C0() { void* m = Tgt_23C3C0::operator new(0x1F4, D_004A6FA8, 0x350); if (m) m = cVUM_GOBJ_ctor2(m, D_23C3C0(0)); return (Tgt_23C3C0*)m; }
extern "C" void NiEvent_LoadModelAsset(Self_23C3C0* self, int mode, Pop_23C3C0* r, int id)
{
    int a;
    int b;
    Obj_23C3C0 obj;
    char buf[0x40];
    char* name;
    Resource_Construct(&obj);
    name = ReadStr_23C3C0(r);
    sprintf(buf, "%s.HOG", id);
    Hog_Register(&obj, buf, mode, 1);
    if (!(unsigned char)FileMan_FindMember(&obj)) {
        unsigned char found;
        a = 0;
        b = 0;
        found = func_00131010(g_Game, name, buf, &a);
        Game_FindNamedResource(g_Game, buf, &b);
        self->tgt = NewTgt_23C3C0();
        self->tgt->owner = self;
        if (!found) {
            func_00130D10(g_Game, self->tgt, name, buf);
            a = 0;
        }
        self->tgt->Set40(0);
        self->tgt->Set44(Info_23C3C0(&obj, a, b, name));
        self->b2F = 1;
        func_0036DEC0(&obj);
    } else {
        self->tgt = 0;
    }
    FileMan_Release(&obj, -1);
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
    static void* operator new(unsigned int sz, char* file, int line) { AllocGuard g; return Mem_Alloc(0, sz, file, line); }
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
void func_0023F350(Self_C610* self, int kind, void* info);
void func_00238940(OwnedVec_C610* v);
void func_0023D180(EvSub_C610* v);
void NetMap_BindReceiver(int id, int owner, Self_C610* o);
#if 0 /* merge_units */
void NiEvent_LoadModelAsset(Self_C610* self, int mode, Reader_C610* r, char* name);
#endif /* merge_units */
#define NiEvent_LoadModelAsset(a0, a1, a2, a3) (NiEvent_LoadModelAsset((Self_23C3C0 *)(a0), (a1), (Pop_23C3C0 *)(a2), (int)(a3))) /* merge_units */

#if 0 /* merge_units */
void NiEvent_LoadParticleAsset(Self_C610* self, Reader_C610* r);
#endif /* merge_units */
#define NiEvent_LoadParticleAsset(a0, a1) (NiEvent_LoadParticleAsset((Self_23C1C0 *)(a0), (Pop_23C1C0 *)(a1))) /* merge_units */

Cam_C610* Camera_ConstructFov(void* p, float fov, const Zero_C610& z, Self_C610* owner);
void NiEvent_ReadKeyedTrack4(Track_C610* t, Reader_C610* r);
void func_002401C0(V64_C610* v, int n, const E64_C610& fill);
static inline void Assign64_C610(V64_C610* v, int n, const E64_C610& fill) { E64_C610 t; func_002401C0(v, 0, t); func_002401C0(v, n, fill); }
void func_00240230(V8_C610* v, int n, const E8_C610& fill);
static inline void Assign8_C610(V8_C610* v, int n, const E8_C610& fill) { func_00240230(v, 0, E8_C610()); func_00240230(v, n, fill); }
void NiEvent_ReadEvents(Events_C610* e, Self_C610* self, Reader_C610* r);
int IdMgr_FindCollision(int region, int id);
void ZoneMgr_Associate(int found, Self_C610* o, int a, int b);
void PtrVector_Resize(ChildVec_C610* v, int n, Child_C610* const& value);
static inline void AssignP_C610(ChildVec_C610* v, int n, Child_C610* const& fill) { Child_C610* z = 0; PtrVector_Resize(v, 0, z); PtrVector_Resize(v, n, fill); }
void Node_ClearLocalMatrix(Self_C610* o);
void func_003CD5C0(Self_C610* o);
void func_0023B120(Self_C610* o);
float Vec4_GetX(V4_C610* v);
float Vec4_GetY(V4_C610* v);
float Vec4_GetZ(V4_C610* v);
void Mtx_MakeAxisRotation(Mat_C610* m, float x, float y, float z, float a);
void func_001D3E20(Mat_C610* m);
void Mtx_Multiply(Mat_C610* a, Mat_C610* b);
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
    Mtx_MakeAxisRotation(m, Vec4_GetX((V4_C610*)&ax), Vec4_GetY((V4_C610*)&ax), Vec4_GetZ((V4_C610*)&ax), ang);
}
static inline void RotMul_C610(Mat_C610* a, const V4_C610& ax, float ang)
{
    Mat_C610 rot;
    func_001D3E20(&rot);
    Mtx_MakeAxisRotation(&rot, ax.x, ax.y, ax.z, ang);
    Mtx_Multiply(a, &rot);
}
extern "C" Self_C610* cNIEventOBJ_ctor(Self_C610* self, int mode, Reader_C610* r)
{
    volatile int id;
    char* name;
    int n;
    int i;
    func_0023F350(self, 0x10, &D_004F7C60);
    *(void**)self = cNIEventOBJ_vtable;
    { Track_C610* t = &self->t144; func_00238940(&t->vec); }
    { Track_C610* t = &self->t164; func_00238940(&t->vec); }
    { Track_C610* t = &self->t184; func_00238940(&t->vec); }
    { Events_C610* t = &self->ev; func_0023D180(&t->sub); }
    if (r->version >= 0x3F) {
        name = ReadStr_C610(r);
        String_Copy(self->name, name);
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
            if (*(volatile unsigned char*)&g_IsMultiplayer) { if (D_00494178 == -1) NetGame_InitLocalSlot(&D_00494178, a); rr = D_00494178; } else { asm { .set reorder } }
            NetMap_BindReceiver(t, rr, self);
        }
    }
    ReadI_C610(r, &self->f60);
    switch (self->f60) {
    case 1:
        NiEvent_LoadModelAsset(self, mode, r, name);
        break;
    case 3:
    case 6:
        NiEvent_LoadModelAsset(self, mode, r, name);
        break;
    case 2:
        NiEvent_LoadParticleAsset(self, r);
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
    NiEvent_ReadKeyedTrack4(&self->t144, r);
    NiEvent_ReadKeyedTrack4(&self->t164, r);
    NiEvent_ReadKeyedTrack4(&self->t184, r);
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
        NiEvent_ReadEvents(&self->ev, self, r);
    {
    int k;
    int cnt = RdI_C610(r);
    for (k = 0; k < cnt; k++) {
        int a = RdI_C610(r);
        int b = RdI_C610(r);
        int found = IdMgr_FindCollision(a, b);
        if (found)
            ZoneMgr_Associate(found, self, 1, found);
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
        Child_C610* c = (Child_C610*)IdMgr_FindCollision(a, b);
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
    Node_ClearLocalMatrix(self);
    {
        Mat_C610 m;
        MakeRot_C610(&m, V4_C610(1.0f, 0.0f, 0.0f, 0.0f), D2R_C610(self->t144.cur));
        RotMul_C610(&m, V4_C610(0.0f, 1.0f, 0.0f, 0.0f), D2R_C610(self->t164.cur));
        RotMul_C610(&m, V4_C610(0.0f, 0.0f, 1.0f, 0.0f), D2R_C610(self->t184.cur));
        VCX_C610(&m.r[3], &self->posE0);
        { Mat_C610* dst = &self->mF0; Mat_C610* src = &m; MCopy_C610(dst, src); }
        self->SetFrame(&m, 0);
        if (self->f60 == 1) {
            func_003CD5C0(self);
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
    func_0023B120(self);
    return self;
}
#undef NiEvent_LoadModelAsset /* merge_units */
#undef NiEvent_LoadParticleAsset /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023C610(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0023C610 */
