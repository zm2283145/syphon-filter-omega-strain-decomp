/*
 * Libs/SFOLib/Source/interface_model: 5 files, 003F0490-003F0BD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003F0490 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "owned_buffer8_dtor_deep.h"

extern "C" { char D_004BE190[] = "allocator.hh"; }
DEFINE_OWNED_BUFFER8_DTOR_DEEP(func_003F0490, D_004BE190)
static inline void merge_flush_func_003F0490(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F0490 */

/* merge_units: begin func_003F0580 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Rel* func_003F0580(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_003F0580(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F0580 */

/* merge_units: begin func_003F05A0 */
#pragma push /* merge_units */
#include "sso_string.h"
typedef struct { char pad[0x9C]; } FileMan05A0;
typedef struct { signed char len; char text[0x80]; } PStr05A0;
typedef struct Obj05A0 {
    char pad0[0xC];
    SsoString name;
    int f18;
    char pad1C[0x6E - 0x1C];
    unsigned short count;
    char pad70[0x84 - 0x70];
    struct Obj05A0** kids;
} Obj05A0;
extern int g_TextureMgr;
extern char D_004BE048[];
extern void cFileMan_ctor_void(FileMan05A0* f);
extern void cFileMan_EncodeFilename_charP_cFileManR(FileMan05A0* f, char* name, int a);
extern void cFileMan_dtor(FileMan05A0* f, int flag);
extern int cTexMan_AddTextureFromFile_cFileManR(int mgr, FileMan05A0* f);

static inline void Copy(PStr05A0* buf, char* t, const char* s)
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

static inline void Append(char* buf, const char* s)
{
    char* d;
    const char* p;
    int n;
    n = buf[0];
    d = buf + n + 1;
    p = s;
    if (n < 0x7E) {
        while ((*d++ = *p++) != 0) {
            if (++n >= 0x7E) {
                n++;
                d[0] = '\n';
                d[1] = 0;
                break;
            }
        }
    }
    buf[0] = n;
}

static inline int Len05A0(SsoString* s) { return SSO_IS_LONG(s) ? s->longLen : (unsigned char)s->h.s.len; }

void cInterfaceModel_Refresh(Obj05A0* o, int arg1)
{
    PStr05A0 s;
    FileMan05A0 fm;
    int i;

    if (Len05A0(&o->name) > 0) {
        Copy(&s, s.text, std_basic_string_char_char_traits_char_c_str(&o->name));
        Append((char*)&s, D_004BE048);
        cFileMan_ctor_void(&fm);
        cFileMan_EncodeFilename_charP_cFileManR(&fm, (char*)&s + 1, arg1);
        o->f18 = cTexMan_AddTextureFromFile_cFileManR(g_TextureMgr, &fm);
        cFileMan_dtor(&fm, -1);
    }
    for (i = 0; i < o->count; i++) {
        cInterfaceModel_Refresh(o->kids[i], arg1);
    }
}
static inline void merge_flush_func_003F05A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F05A0 */

/* merge_units: begin func_003F0770 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"

/* CreateFeature: interface-model chunk reader for the two direction tags - a line (two points read
 * from the stream, second point zeroed when the segment is degenerate) or a single point. */

typedef struct { signed char len; char text[0x80]; } PStr0770;
struct V4 {
    float x, y, z, w;
    V4() {}
    /* quadword copies; the unused xx reproduces retail's duplicated destination address */
    V4(const V4& o) { void* xx = this; __int128 q; V4* pd = this; const V4* ps = &o; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    V4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V4& operator=(const V4& o) { void* xx = this; V4* pd = this; const V4* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));
typedef struct { char pad[0xD0]; V4* line; V4* point; } Self0770;

extern "C" {
extern char D_004BE030[];
extern char D_004BE050[];
extern char D_004BE058[];
extern int D_0055C0B8;
extern void* cMemMan_Allocate(int pool, int size, char* file, int line);
extern int strcmp(const char* a, const char* b);
int CreateFeature(Self0770* self, char** cursor);
}

static inline void Copy_003F0770(PStr0770* buf, char* t, const char* s)
{
    const char* p;
    int n;
    char* d;
    n = 0;
    d = t;
    p = s;
    if (n < 0x7E) {
        while ((*d++ = *p++) != 0) {
            if (++n >= 0x7E) {
                n++;
                *d++ = '\n';
                *d = 0;
                break;
            }
        }
    }
    buf->len = n;
}

static inline float ReadF(char** c) { float f = *(float*)*c; *c += 4; return f; }
static inline int ReadI(char** c) { return *(*(int**)c)++; }
/* point stored with y and z swapped (file is z-up) */
static inline void SetPt(V4* p, float x, float y, float z) { if (p) { p->x = x; p->y = z; p->z = y; p->w = 1.0f; } }

static inline void SubV(V4* r, V4* a, V4* b)
{
    __asm__ volatile("lqc2 $vf1, 0x0(%1)\n\tlqc2 $vf2, 0x0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory");
}
static inline V4 Sub(V4* a, V4* b)
{
    V4 r;
    SubV(&r, a, b);
    return r;
}
/* squared length (VU0 macro mode); by-value parameter like retail */
static inline float LenSq(V4 v)
{
    V4* p = &v;
    int rv;
    float ret = 0.0f;
    asm {
        lqc2 vf1, 0x0(p)
        vaddw.x vf3, vf0, vf0w
        vmul.xyz vf2, vf1, vf1
        vmulax.x ACC, vf3, vf2x
        vmadday.x ACC, vf3, vf2y
        vmaddz.x vf4, vf3, vf2z
        qmfc2.ni rv, vf4
        mtc1 rv, ret
    }
    return ret;
}

extern "C" int CreateFeature(Self0770* self, char** cursor)
{
    PStr0770 s;
    char* start = *cursor;
    while (*(*cursor)++) ;
    Copy_003F0770(&s, s.text, start);
    *cursor = (char*)(((int)*cursor + 3) & ~3);
    if (strcmp(s.text, D_004BE050) == 0) {
        V4* a;
        V4* v;
        int n;
        { AllocGuard g; a = (V4*)cMemMan_Allocate(0, 0x20, D_004BE030, 0xC4); }
        self->line = a;
        v = self->line;
        if (D_0055C0B8 > 1) n = ReadI(cursor);
        else n = 1;
        {
            float x = ReadF(cursor);
            float y = ReadF(cursor);
            float z = ReadF(cursor);
            SetPt(v, x, y, z);
        }
        if (n > 1) {
            int i;
            {
                V4* q = (V4*)((char*)v + 16);
                float x = ReadF(cursor);
                float y = ReadF(cursor);
                float z = ReadF(cursor);
                SetPt(q, x, y, z);
            }
            if (0.0f == LenSq(Sub(&v[1], &v[0]))) v[1] = V4(0.0f, 0.0f, 0.0f, 0.0f);
            for (i = 2; i < n; i++) {
                *cursor += 4;
                *cursor += 4;
                *cursor += 4;
            }
        } else {
            v[1] = V4(0.0f, 0.0f, 0.0f, 0.0f);
        }
    } else if (strcmp(s.text, D_004BE058) == 0) {
        V4* v;
        float x = ReadF(cursor);
        float y = ReadF(cursor);
        float z = ReadF(cursor);
        { AllocGuard g; v = (V4*)cMemMan_Allocate(0, 0x10, D_004BE030, 0xE6); }
        SetPt(v, x, y, z);
        self->point = v;
    } else {
        return 0;
    }
    return 1;
}
static inline void merge_flush_func_003F0770(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F0770 */

/* merge_units: begin func_003F0BD0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
typedef struct { signed char len; char text[0x80]; } PStr_0BD0;
typedef struct { int unk0; int count; void* data; char unk0C; } Vec_0BD0;
typedef struct { char pad[0xC]; } Ent_0BD0;
typedef struct { float x, y; } V2_0BD0;
typedef struct { float f[4]; } V4_0BD0;
typedef struct { char pad[0x70]; Ent_0BD0* p70; } Self_0BD0;
typedef struct { void* vtable; char pad4[0x14]; Vec_0BD0 vec; } ObjA_0BD0;
typedef struct { void* vtable; char pad4[0x14]; int f18; void* f1C; Vec_0BD0 vec; } ObjB_0BD0;
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
extern void* opNew_uint_int_charP_int(int size, int pool, char* file, int line);
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

static inline void Copy_003F0BD0(PStr_0BD0* buf, char* t, const char* s)
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
    Copy_003F0BD0(&s, s.text, start);
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
static inline void merge_flush_func_003F0BD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F0BD0 */
