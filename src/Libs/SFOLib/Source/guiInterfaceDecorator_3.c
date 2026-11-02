/*
 * Libs/SFOLib/Source/guiInterfaceDecorator: 8 files, 00416F30-004172E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00416F30 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

void func_00416F30(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

/* end() of the element vector. */
L4Elem18* func_00416F40(L4Elem18Vec* v) {
    return v->data + v->count;
}

void* func_00416F60(char* self) {
    return self + 8;
}
static inline void merge_flush_func_00416F30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00416F30 */

/* merge_units: begin func_00416F70 */
#pragma push /* merge_units */
typedef struct { int a, b, c; } Str_416F70;
typedef struct { float x, y, z, w; } V4_416F70;
typedef struct { Str_416F70 name; unsigned char b; char pad[3]; int c; int d; } E_416F70;
typedef struct {
    char pad[8]; Str_416F70 s8; Str_416F70 s14; char pad20[8]; unsigned char b28; char pad29[7];
    char m30[0x40]; char v70[4]; int n74; E_416F70* v78;
} O_416F70;
void* Gui_Manager(void);
char* std_basic_string_char_char_traits_char_c_str(void* s);
void std_basic_string_char_char_traits_char_ctor_charP(Str_416F70* s, char* c);
void std_basic_string_char_char_traits_char_assign_basicstringR(Str_416F70* d, Str_416F70* s);
#if 0 /* merge_units */
void String_Dtor(void* s, int f);
#endif /* merge_units */
void* String_Dtor(void* self, short deleteFlag); /* merge_units */
#define String_Dtor(a0, a1) ((void)String_Dtor((a0), (short)(a1))) /* merge_units */

void cMatrix_SetAxes(void* m, V4_416F70* a, V4_416F70* b, V4_416F70* c);
void cMatrix_SetTranslation(void* m, V4_416F70* t);
void cString_ctor_void(E_416F70* e);
void std_vector_imp_GuiAnimationTrack_insert(void* v, E_416F70* pos, int n, E_416F70* e);

static inline float RdF_416F70(char** c) { float* p = (float*)*c; *c = (char*)(p + 1); return *p; }
static inline unsigned short Rd16_416F70(char** c) { unsigned short* p = (unsigned short*)*c; unsigned short v = *p; *c = (char*)(p + 1); return v; }
static inline void RdV_416F70(char** c, V4_416F70* v, float w)
{
    float x = RdF_416F70(c);
    float y = RdF_416F70(c);
    float z = RdF_416F70(c);
    v->x = x; v->y = y; v->z = z; v->w = w;
}

int GuiInterfaceDecorator_Load(O_416F70* o, char** cur)
{
    V4_416F70 a;
    V4_416F70 b;
    V4_416F70 c;
    V4_416F70 d;
    Str_416F70 t1;
    Str_416F70 t2;
    Str_416F70 t3;
    E_416F70 e;
    char* s;
    int i;
    unsigned short n;
    s = *cur;
    while (*(*cur)++ != 0);
    if (s == 0 || *s == 0) s = std_basic_string_char_char_traits_char_c_str((char*)Gui_Manager() + 0x2C);
    else o->b28 = 1;
    std_basic_string_char_char_traits_char_ctor_charP(&t1, s);
    std_basic_string_char_char_traits_char_assign_basicstringR(&o->s8, &t1);
    String_Dtor(&t1, 0);
    s = *cur;
    while (*(*cur)++ != 0);
    if (s != 0 && *s != 0) {
        std_basic_string_char_char_traits_char_ctor_charP(&t2, s);
        std_basic_string_char_char_traits_char_assign_basicstringR(&o->s14, &t2);
        String_Dtor(&t2, 0);
    }
    *cur = (char*)(((int)*cur + 3) & ~3);
    RdV_416F70(cur, &a, 0.0f);
    RdV_416F70(cur, &b, 0.0f);
    RdV_416F70(cur, &c, 0.0f);
    RdV_416F70(cur, &d, 1.0f);
    cMatrix_SetAxes(o->m30, &a, &b, &c);
    cMatrix_SetTranslation(o->m30, &d);
    n = Rd16_416F70(cur);
    for (i = 0; i < n; i++) {
        cString_ctor_void(&e);
        s = *cur;
        while (*(*cur)++ != 0);
        std_basic_string_char_char_traits_char_ctor_charP(&t3, s);
        std_basic_string_char_char_traits_char_assign_basicstringR(&e.name, &t3);
        String_Dtor(&t3, 0);
        *cur = (char*)(((int)*cur + 3) & ~3);
        e.b = Rd16_416F70(cur);
        e.c = Rd16_416F70(cur);
        e.d = Rd16_416F70(cur);
        std_vector_imp_GuiAnimationTrack_insert(o->v70, o->v78 + o->n74, 1, &e);
        String_Dtor(&e, 0);
    }
    return 1;
}
#undef String_Dtor /* merge_units */
static inline void merge_flush_func_00416F70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00416F70 */

/* merge_units: begin func_004172E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(GuiAnimationTrack_dtor, String_Dtor)
static inline void merge_flush_func_004172E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004172E0 */

/* merge_units: begin func_00417340 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_classes.h"

typedef struct { char pad[4]; VSlots67* ctl; char p1[0x1C]; void* res; } Obj_417340;
extern "C" void cInterfaceElement_Activate(void*, int);
extern "C" void cInterfaceElement_Render(void*, int);

extern "C" void GuiInterfaceDecorator_onRender(Obj_417340* o)
{
    if (o->res) {
        cInterfaceElement_Activate(o->res, 1);
        cInterfaceElement_Render(o->res, 0);
        cInterfaceElement_Activate(o->res, 0);
    }
    o->ctl->slot10();
}
static inline void merge_flush_func_00417340(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00417340 */

/* merge_units: begin func_004173B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
#include "vc_copy.h"

typedef struct E_4173B0 { char name[0xC]; unsigned char kind; char pad[3]; int x; int y; } E_4173B0;
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_4173B0;
struct Inst_4173B0 {
    VPAD1(p)
    virtual float Time();
    float t;
};
struct Base_4173B0 {
    VPAD8(p) VPAD4(q) VPAD1(r)
    virtual bool Handle(int a1, unsigned short msg, int p1, int p2);
    char pad4[0x3C - 4];
    float w;
    float h;
    float& W() { return w; }
    float& H() { return h; }
};
struct Self_4173B0 {
    char pad0[4];
    Base_4173B0* base;
    char pad8[0x24 - 8];
    Inst_4173B0* inst;
    char pad28[0x30 - 0x28];
    V4_4173B0 v30;
    char pad40[0x60 - 0x40];
    V4_4173B0 v60;
    char pad70[0x80 - 0x70];
    E_4173B0* cur;
};

extern "C" {
E_4173B0* GuiInterfaceDecorator_FindEvent(Self_4173B0* o, char* name);
int GuiInterfaceDecorator_StartAnimation(Self_4173B0* o, char* name);
#if 0 /* merge_units */
void cAnimator_NextFrame(Inst_4173B0* i, float t);
#endif /* merge_units */
void cAnimator_NextFrame(void*, float); /* merge_units */
#define cAnimator_NextFrame(a0, a1) (cAnimator_NextFrame((void *)(a0), (a1))) /* merge_units */

void cAnimator_SetFrame(Inst_4173B0* i, float t);
void cAnimator_AnimateTo(Inst_4173B0* i, float t);
void cAnimator_StartAnimation(Inst_4173B0* i, float a, float b, int f);
#if 0 /* merge_units */
void cInterfaceElement_SetView(Inst_4173B0* i, V4_4173B0* v);
#endif /* merge_units */
void cInterfaceElement_SetView(void* i, void* p); /* merge_units */
#define cInterfaceElement_SetView(a0, a1) (cInterfaceElement_SetView((void *)(a0), (void *)(a1))) /* merge_units */

}

/* GCC-style volatile asm quad copies (lq/sq only): MW does not CSE across them, so the
   dead address local after the first copy and the repeated 2.0f / &base->w loads stay
   as in retail. GC1L declares its source local first to get retail's register order. */
static inline void GC1(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
static inline void GC1L(void* d, const void* s) { const void* ss = s; void* dd = d; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(dd), "r"(ss) : "memory"); }
static inline float Yv(E_4173B0* e) { return e->y; }
static inline float Tm(Inst_4173B0* i) { return i->t; }
extern "C" bool GuiInterfaceDecorator_onMessage(Self_4173B0* self, int a1, unsigned short msg, int p1, int p2)
{
    switch (msg - 4) {
    case 11: {
        E_4173B0* e = self->cur;
        Inst_4173B0* inst;
        bool r;
        if (e == 0 || (inst = self->inst) == 0 || e->kind != 1 || Yv(e) == Tm(inst)) r = 1; else r = 0;
        return r;

    }
    case 2:
        GuiInterfaceDecorator_StartAnimation(self, (char*)p1);
        return 0;
    case 1:
        if (p1) *(Inst_4173B0**)p1 = self->inst;
        return 1;
    case 3:
        if (p1 == 0 || 0.0f == *(float*)p1) return 1;
        if (self->inst) cAnimator_NextFrame(self->inst, *(float*)p1);
        return 0;
    case 5:
        if (p1 && self->inst) *(float*)p1 = self->inst->t;
        return 1;
    case 4:
        if (p1 && self->inst) *(float*)p1 = self->inst->Time();
        return 1;
    case 0: {
        E_4173B0* e = GuiInterfaceDecorator_FindEvent(self, (char*)p1);
        if (e && p2) {
            *(E_4173B0**)p2 = e;
            return 1;
        }
        return 0;
    }
    case 6:
    case 7:
    case 8:
    case 9:
    case 10: {
        if (self->inst == 0) break;
        switch (msg) {
        case 10:
            cAnimator_SetFrame(self->inst, p1);
        case 11:
            cAnimator_AnimateTo(self->inst, p1);
            break;
        case 12:
            cAnimator_SetFrame(self->inst, p1);
            cAnimator_AnimateTo(self->inst, p2);
            break;
        case 13:
            if (self->inst->t < p1 || self->inst->t > p2) { Inst_4173B0* volatile* pv = &self->inst; cAnimator_SetFrame(*pv, p1); }
            cAnimator_StartAnimation(self->inst, p1, p2, 0);
            break;
        case 14:
            if (self->inst->t < p1 || self->inst->t > p2) { Inst_4173B0* volatile* pv = &self->inst; cAnimator_SetFrame(*pv, p1); }
            cAnimator_StartAnimation(self->inst, p1, p2, 1);
            break;
        }
        self->cur = 0;
        return 0;
    }
    case 14: {
        V4_4173B0 v;
        GC1L(&v, &self->v60);
        void* xx = &self->v60; /* dead on purpose */
        v.x = (float)p1 + self->base->W() / 2.0f;
        v.z = (float)p2 - self->base->H() / 2.0f;
        GC1(&self->v60, &v);
        if (self->inst) cInterfaceElement_SetView(self->inst, &self->v30);
        return 1;
    }
    }
    return self->base->Handle(a1, msg, p1, p2);
}
#undef cAnimator_NextFrame /* merge_units */
#undef cInterfaceElement_SetView /* merge_units */
static inline void merge_flush_func_004173B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004173B0 */

/* merge_units: begin func_00417790 */
#pragma push /* merge_units */
#pragma cplusplus on

struct E_417790 { char name[0xC]; unsigned char kind; char pad[3]; int x; int y; };
struct I_417790 { int f0; float t; };
struct W_417790 {
    VPAD8(p) VPAD4(q)
    virtual void Update(float dt);
    char pad[0x10];
    unsigned short flags;
};
struct O_417790 {
    int f0;
    W_417790* w;
    char pad[0x1C];
    I_417790* inst;
    char pad28[0x58];
    E_417790* cur;
    bool Done();
};
#if 0 /* merge_units */
extern "C" void cAnimator_NextFrame(I_417790* i, float dt);
#endif /* merge_units */
#define cAnimator_NextFrame(a0, a1) (cAnimator_NextFrame((void *)(a0), (a1))) /* merge_units */



inline bool O_417790::Done()
{
    if (cur == 0 || inst == 0 || cur->kind != 1 || (float)cur->y == inst->t) return true;
    return false;
}

extern "C" void GuiInterfaceDecorator_onAdvanceTime(O_417790* o, float dt)
{
    if (o->inst) cAnimator_NextFrame(o->inst, dt);
    {
        unsigned short& f = o->w->flags;
        if ((f & 0x10) && (f & 8)) {
            if (o->Done()) f &= ~8;
        }
    }
    o->w->Update(dt);
}
#undef cAnimator_NextFrame /* merge_units */
static inline void merge_flush_func_00417790(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00417790 */

/* merge_units: begin func_00417870 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

struct WidgetChild {
    virtual void v00(); virtual void v01();
    virtual void Method10(); /* +0x10 */
};

typedef struct GuiWidget_00417870 {
    int unk0;
    WidgetChild* child; /* +0x04 */
    char pad08[0x20 - 8];
    int handle;  /* +0x20 */
    void* unk24; /* +0x24 */
} GuiWidget_00417870;

extern char D_00571DC0[];
extern "C" void cInterfaceElement_Destroy(void* p);
extern "C" void cInterfaceManager_RemoveInterface(void* mgr, int handle);

/* Notifies the child (virtual +0x10); if a handle (+0x20) is held, releases it (cInterfaceElement_Destroy on +0x24, cInterfaceManager_RemoveInterface) and resets it to -1. */
extern "C" void GuiInterfaceDecorator_onRemove(GuiWidget_00417870* self)
{
    self->child->Method10();
    if (self->handle != -1) {
    if (self->unk24)
    cInterfaceElement_Destroy(self->unk24);
    cInterfaceManager_RemoveInterface(D_00571DC0, self->handle);
    self->handle = -1;
    }
}
static inline void merge_flush_func_00417870(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00417870 */

/* merge_units: begin func_004178E0 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Str_4178E0 { int w0; int len; char* data; };
struct PStr_4178E0 {
    signed char len;
    char text[0x80];
};
static inline void Cat_4178E0(PStr_4178E0* p, const char* s)
{
    char* d;
    const char* t;
    int n;
    t = s;
    n = p->len;
    d = &p->text[n];
    if (n < 0x7E) {
        while ((*d++ = *t++) != 0) {
            if (++n >= 0x7E) {
                n++;
                d[0] = '\n';
                d[1] = 0;
                break;
            }
        }
    }
    p->len = n;
}
struct W_4178E0 {
    VPAD1(p)
    virtual void Reset();
    Str_4178E0 name;
    char pad10[0xC];
    int f1C;
};
struct O_4178E0 {
    int f0;
    W_4178E0* w;
    Str_4178E0 file;
    Str_4178E0 text;
    int id;
    void* inst;
    char pad28[8];
    char f30[4];
};
extern "C" {
#if 0 /* merge_units */
char* std_basic_string_char_char_traits_char_c_str(Str_4178E0* s);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_c_str(a0) (std_basic_string_char_char_traits_char_c_str((void *)(a0))) /* merge_units */

int cString_Length(Str_4178E0* s);
int cInterfaceManager_AddInterface(void* db, char* name);
int* cInterfaceManager_GetInterface(void* db, int id);
void* cInterfaceModel_FindChild(int scene, char* name);
void* cInterfaceModel_CreateInstance(void* n);
#if 0 /* merge_units */
void cInterfaceElement_Activate(void* i, int a);
#endif /* merge_units */
#define cInterfaceElement_Activate(a0, a1) (cInterfaceElement_Activate((a0), (a1))) /* merge_units */


void cInterfaceElement_SetView(void* i, void* p);

extern char D_004BF070[];
}
static inline bool Empty_4178E0(Str_4178E0* s) { return cString_Length(s) == 0; }

extern "C" void GuiInterfaceDecorator_onAdd(O_4178E0* o)
{
    int* rec;
    o->w->Reset();
    o->id = cInterfaceManager_AddInterface(D_00571DC0, std_basic_string_char_char_traits_char_c_str(&o->file));
    if (o->id == -1) return;
    rec = cInterfaceManager_GetInterface(D_00571DC0, o->id);
    if (rec && *rec) {
        PStr_4178E0 buf;
        void* n;
        const char* s;
        Empty_4178E0(&o->text) ? (s = std_basic_string_char_char_traits_char_c_str(&o->w->name)) : (s = std_basic_string_char_char_traits_char_c_str(&o->text));
        {
            char* d = buf.text;
            int n = 0;
            while ((*d++ = *s++) != 0) {
                if (++n >= 0x7E) {
                    n++;
                    d[0] = '\n';
                    d[1] = 0;
                    break;
                }
            }
            buf.len = n;
        }
        if (o->w->f1C == 0) Cat_4178E0(&buf, D_004BF070);
        n = cInterfaceModel_FindChild(*rec, (char*)&buf + 1);
        if (n) {
            o->inst = cInterfaceModel_CreateInstance(n);
            cInterfaceElement_Activate(o->inst, 0);
            cInterfaceElement_SetView(o->inst, o->f30);
        }
    }
}
#undef std_basic_string_char_char_traits_char_c_str /* merge_units */
#undef cInterfaceElement_Activate /* merge_units */
static inline void merge_flush_func_004178E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004178E0 */
