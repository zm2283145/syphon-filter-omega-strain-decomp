#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
typedef struct { signed char len; char text[0x80]; } PStr_0BD0;
typedef struct { int unk0; int count; void* data; char unk0C; } Vec_0BD0;
typedef struct { char pad[0xC]; } Ent_0BD0;
typedef struct { float x, y; } V2_0BD0;
typedef struct { float f[4]; } V4_0BD0;
typedef struct { char pad[0x70]; Ent_0BD0* p70; } Self_0BD0;
typedef struct { void* vtable; char pad4[0x14]; Vec_0BD0 vec; } ObjA_0BD0;
typedef struct { void* vtable; char pad4[0x14]; int f18; void* f1C; Vec_0BD0 vec; } ObjB_0BD0;

extern char D_004BE030[];
extern char D_004BE1A0[];
extern char D_004E0820[];
extern char D_004E07E0[];
extern char D_004E07C0[];
extern char D_004BE060[];
extern char D_004BE068[];
extern char D_004BE070[];
extern char D_004BE078[];
extern char D_004BE080[];
extern char D_004BE088[];
extern char D_004BE090[];
extern char D_004BE098[];
extern char D_004BE0A0[];
extern char D_004BE0A8[];
extern char D_00493998[];
extern char D_004939A0[];
extern char D_004939A8[];
extern char D_004939B0[];
extern char D_004939B8[];
extern char D_004939C0[];
extern char D_004939C8[];
extern char D_004939D0[];
extern char D_004939D8[];
extern char D_004939E0[];
extern void* cMemMan_Allocate(int pool, int size, char* file, int line);
extern void* opNew_uint_int_charP_int(int size, int pool, char* file, int line);
extern int strcmp(const char* a, const char* b);
extern void std_vector_AnimType_push_back(void* v, char* value);
extern void* cAnimator_ctor(void* self);
extern void cArray_cAnimatorPtr_ctor(Vec_0BD0* v);
extern void cStreamingBuffer_opShr(char** cursor, int* out);
extern void cArray_cAnimatorPtr_ReserveActual(Vec_0BD0* v, int n);
extern void* cKeyframeAnimation_cXyz_ctor(void* self, Ent_0BD0* e, char** cursor);
extern void cArray_cAnimatorPtr_PushBackActual(Vec_0BD0* v, void** p);
extern void cArray_cKeyframe_tRGB_ctor(Vec_0BD0* v);
extern void cArray_cKeyframe_tRGB_ReserveActual(Vec_0BD0* v, int n);
extern V4_0BD0* func_003F3E30(V4_0BD0* out, char** cursor);
extern void cArray_cKeyframe_tRGB_PushBackActual(Vec_0BD0* v, V4_0BD0* p);
extern void cArray_cKeyframe_float_ctor(Vec_0BD0* v);
extern void cArray_cKeyframe_float_ReserveActual(Vec_0BD0* v, int n);
extern V2_0BD0* cKeyframe_float_ctor(V2_0BD0* out, char** cursor);
extern void cArray_cKeyframe_float_PushBackActual(Vec_0BD0* v, V2_0BD0* p);
}

static inline void Copy(PStr_0BD0* buf, char* t, const char* s)
{
    char* d;
    const char* p;
    int n;
    n = 0;
    d = t;
    p = s;
    while ((*d++ = *p++) != 0) {
        if (++n >= 0x7E) {
            n++;
            d[0] = '\n';
            d[1] = 0;
            break;
        }
    }
    buf->len = n;
}

static inline ObjA_0BD0* ObjA_Ctor(ObjA_0BD0* o, Ent_0BD0* e, char** cursor)
{
    int n;
    int i;
    cAnimator_ctor(o);
    o->vtable = D_004E0820;
    cArray_cAnimatorPtr_ctor(&o->vec);
    cStreamingBuffer_opShr(cursor, &n);
    cArray_cAnimatorPtr_ReserveActual(&o->vec, n);
    for (i = 0; i < n; i++) {
        void* c;
        void* m = opNew_uint_int_charP_int(0x30, 0, D_004BE1A0, 0x90);
        c = m ? cKeyframeAnimation_cXyz_ctor(m, e++, cursor) : m;
        cArray_cAnimatorPtr_PushBackActual(&o->vec, &c);
    }
    return o;
}

static inline ObjB_0BD0* ObjB_Ctor(ObjB_0BD0* o, void* a, char** cursor)
{
    int n;
    int i;
    cAnimator_ctor(o);
    o->vtable = D_004E07E0;
    o->f18 = 0;
    o->f1C = a;
    cArray_cKeyframe_tRGB_ctor(&o->vec);
    cStreamingBuffer_opShr(cursor, &n);
    cArray_cKeyframe_tRGB_ReserveActual(&o->vec, n);
    for (i = 0; i < n; i++) {
        V4_0BD0 t;
        cArray_cKeyframe_tRGB_PushBackActual(&o->vec, func_003F3E30(&t, cursor));
    }
    return o;
}

static inline ObjB_0BD0* ObjC_Ctor(ObjB_0BD0* o, void* a, char** cursor)
{
    int n;
    int i;
    cAnimator_ctor(o);
    o->vtable = D_004E07C0;
    o->f18 = 0;
    o->f1C = a;
    cArray_cKeyframe_float_ctor(&o->vec);
    cStreamingBuffer_opShr(cursor, &n);
    cArray_cKeyframe_float_ReserveActual(&o->vec, n);
    for (i = 0; i < n; i++) {
        V2_0BD0 t;
        cArray_cKeyframe_float_PushBackActual(&o->vec, cKeyframe_float_ctor(&t, cursor));
    }
    return o;
}

#define CASEC(str, code, line, off) \
    if (strcmp(s.text, str) == 0) { \
        ObjB_0BD0* o; \
        std_vector_AnimType_push_back(names, code); \
        { AllocGuard g; o = (ObjB_0BD0*)cMemMan_Allocate(0, 0x30, D_004BE030, line); } \
        if (o) o = ObjC_Ctor(o, (char*)self + off, cursor); \
        return o; \
    }

extern "C" void* CreateAnimation(Self_0BD0* self, char** cursor, void* names)
{
    PStr_0BD0 s;
    char* start = *cursor;
    while (*(*cursor)++) ;
    Copy(&s, s.text, start);
    *cursor = (char*)(((int)*cursor + 3) & ~3);
    if (strcmp(s.text, D_004BE060) == 0) {
        ObjA_0BD0* o;
        std_vector_AnimType_push_back(names, D_00493998);
        { AllocGuard g; o = (ObjA_0BD0*)cMemMan_Allocate(0, 0x28, D_004BE030, 0x84); }
        if (o) o = ObjA_Ctor(o, self->p70, cursor);
        return o;
    }
    if (strcmp(s.text, D_004BE068) == 0) {
        ObjB_0BD0* o;
        std_vector_AnimType_push_back(names, D_004939A0);
        { AllocGuard g; o = (ObjB_0BD0*)cMemMan_Allocate(0, 0x30, D_004BE030, 0x89); }
        if (o) o = ObjB_Ctor(o, (char*)self + 0xA0, cursor);
        return o;
    }
    CASEC(D_004BE070, D_004939A8, 0x8E, 0xAC)
    CASEC(D_004BE078, D_004939B0, 0x93, 0xB0)
    CASEC(D_004BE080, D_004939B8, 0x98, 0xB4)
    CASEC(D_004BE088, D_004939C0, 0x9D, 0xB8)
    CASEC(D_004BE090, D_004939C8, 0xA2, 0xC0)
    CASEC(D_004BE098, D_004939D0, 0xA7, 0xC4)
    CASEC(D_004BE0A0, D_004939D8, 0xAC, 0xC8)
    CASEC(D_004BE0A8, D_004939E0, 0xB1, 0xCC)
    return 0;
}
