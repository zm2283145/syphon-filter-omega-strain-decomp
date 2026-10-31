#pragma cplusplus on
#include "types.h"
#include "sso_string.h"
#include "alloc_guard.h"
extern "C" {

typedef struct { char pad[0x9C]; } FileMan_EF660;
typedef struct { signed char len; char text[0x80]; } PStr_EF660;
typedef struct { float x, y, z, w; } V4_EF660;
typedef struct { float x, y, z; } V3_EF660;
typedef struct { float x, y; } V2_EF660;
typedef struct { int x, y, z; } I3_EF660;
typedef struct { short m[9]; } S9_EF660;
typedef struct { unsigned char b[4]; } C4_EF660;
typedef struct { int a, b, c; unsigned char owned; } Vec_EF660;
typedef struct { char pad[0x48]; int flags; } Tex_EF660;
typedef struct { char pad[8]; Tex_EF660** tex; } TexMgr_EF660;

typedef struct Self_EF660 {
    SsoString name;
    SsoString file;
    int f18;
    char pad1C[4];
    char mtx[0x40];
    unsigned char b60, b61, b62, b63;
    unsigned short n64, n66, n68, n6A, n6C, n6E;
    V3_EF660* a70;
    V2_EF660* a74;
    C4_EF660* a78;
    S9_EF660* a7C;
    void** a80;
    struct Self_EF660** a84;
    char* a88;
    char l8C[0xC];
    struct Self_EF660* parent;
    char pad9C[4];
    float fA0, fA4, fA8, fAC;
    float fB0, fB4, fB8;
    char padBC[4];
    float fC0, fC4, fC8, fCC;
    void* pD0;
    void* pD4;
} Self_EF660;

extern char D_004BE030[];
extern char D_004BE048[];
extern TexMgr_EF660* g_TextureMgr;
extern void* cMemMan_Allocate(int pool, int size, char* file, int line);
extern void cMemMan_Deallocate(int pool, void* p, char* file, int line);
extern void* memcpy(void* d, const void* s, unsigned int n);
extern void std_list_deleter_voidPtr_ctor_void(void* c);
extern void cMatrix_SetAxes(void* m, V4_EF660* a, V4_EF660* b, V4_EF660* c);
extern void cMatrix_SetTranslation(void* m, V4_EF660* t);
extern void cFileMan_ctor_void(FileMan_EF660* f);
extern void cFileMan_EncodeFilename_charP_cFileManR(FileMan_EF660* f, char* name, int a);
extern void cFileMan_dtor(FileMan_EF660* f, int flag);
extern int cTexMan_AddTextureFromFile_cFileManR(TexMgr_EF660* mgr, FileMan_EF660* f);
extern void func_003F0580(Vec_EF660* v);
extern void std_vector_pod_AnimType_reserve(Vec_EF660* v, int n);
extern void* CreateAnimation(Self_EF660* self, char** cursor, Vec_EF660* types);
extern void CreateFeature(Self_EF660* self, char** cursor);
extern void PatchAnimation(Self_EF660* self, Vec_EF660* types);
extern void func_003F0490(Vec_EF660* v, int f);
Self_EF660* cInterfaceModel_ctor(Self_EF660* self, char** cursor, int arg, Self_EF660* parent);
}


static inline void Copy(PStr_EF660* buf, char* t, const char* s)
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

static inline int Len_EF660(SsoString* s) { return SSO_IS_LONG(s) ? s->longLen : (unsigned char)s->h.s.len; }

static inline float ReadF(char** c)
{
    float* p = (float*)*c;
    *c = (char*)(p + 1);
    return *p;
}

static inline int ReadI(char** c)
{
    int v = *(int*)*c;
    *c += 4;
    return v;
}

static inline void Set4(V4_EF660* v, float x, float y, float z, float w)
{
    v->x = x;
    v->w = w;
    v->y = y;
    v->z = z;
}

typedef struct { int v[3]; } A3_EF660; typedef struct { A3_EF660 xyz, uv, rgb; } FR_EF660;
typedef struct { unsigned short xyz[3]; unsigned short uv[3]; unsigned short rgb[3]; } Face_EF660;
static inline char* AllocB(int size, int line) { char* r; { AllocGuard g; r = (char*)cMemMan_Allocate(0, size, D_004BE030, line); } return r; }
extern "C" Self_EF660* cInterfaceModel_ctor(Self_EF660* self, char** cursor, int arg, Self_EF660* parent)
{
    char* start;
    SsoString str;
    PStr_EF660 s;
    FileMan_EF660 fm;
    V4_EF660 a, b, c, d;
    FR_EF660 fr;
    Vec_EF660 types;
    char* buf;
    char* p;
    int n;
    int size;

    start = *cursor;
    while (*(*cursor)++) {
    }
    std_basic_string_char_char_traits_char_ctor_charP(&self->name, start);
    self->file.h.word = 0;
    self->file.longLen = 0;
    self->file.longData = 0;
    self->f18 = -1;
    self->b60 = 0;
    self->b61 = 0;
    self->b62 = 0;
    self->b63 = 0;
    self->a70 = 0;
    self->a74 = 0;
    self->a78 = 0;
    self->a7C = 0;
    self->a80 = 0;
    self->a84 = 0;
    self->a88 = 0;
    std_list_deleter_voidPtr_ctor_void(self->l8C);
    self->parent = parent;
    self->fA0 = 1.0f;
    self->fA4 = 1.0f;
    self->fA8 = 1.0f;
    self->fAC = 1.0f;
    self->fB0 = 0.0f;
    self->fB4 = 0.0f;
    self->fB8 = 0.0f;
    self->fC0 = 0.0f;
    self->fC4 = 0.0f;
    self->fC8 = 1.0f;
    self->fCC = 1.0f;
    self->pD0 = 0;
    self->pD4 = 0;

    start = *cursor;
    while (*(*cursor)++) {
    }
    std_basic_string_char_char_traits_char_ctor_charP(&str, start);
    std_basic_string_char_char_traits_char_assign_basicstringR(&self->file, &str);
    String_Dtor(&str, 0);

    if (Len_EF660(&self->file) > 0) {
        Copy(&s, s.text, std_basic_string_char_char_traits_char_c_str(&self->file));
        Append((char*)&s, D_004BE048);
        cFileMan_ctor_void(&fm);
        cFileMan_EncodeFilename_charP_cFileManR(&fm, (char*)&s + 1, arg);
        self->f18 = cTexMan_AddTextureFromFile_cFileManR(g_TextureMgr, &fm);
        cFileMan_dtor(&fm, -1);
    }

    *cursor = (char*)(((int)*cursor + 3) & ~3);
    { float x = ReadF(cursor); float y = ReadF(cursor); float z = ReadF(cursor); Set4(&a, x, y, z, 0.0f); }
    { float x = ReadF(cursor); float y = ReadF(cursor); float z = ReadF(cursor); Set4(&b, x, y, z, 0.0f); }
    { float x = ReadF(cursor); float y = ReadF(cursor); float z = ReadF(cursor); Set4(&c, x, y, z, 0.0f); }
    { float x = ReadF(cursor); float y = ReadF(cursor); float z = ReadF(cursor); Set4(&d, x, y, z, 1.0f); }
    cMatrix_SetAxes(self->mtx, &a, &b, &c);
    cMatrix_SetTranslation(self->mtx, &d);

    buf = AllocB(0x8000, 0x13B);
    p = buf;

    n = ReadI(cursor);
    self->n64 = n;
    for (int i = 0; i < n; i++) {
        float* f = (float*)*cursor;
        ((float*)p)[0] = f[0];
        ((float*)p)[1] = f[1];
        ((float*)p)[2] = f[2];
        *cursor += sizeof(V3_EF660);
        p += sizeof(V3_EF660);
    }
    n = *(int*)*cursor; *cursor += 4;
    self->n66 = n;
    for (int i = 0; i < n; i++) {
        float* f = (float*)*cursor;
        ((float*)p)[0] = f[0];
        ((float*)p)[1] = f[1];
        *cursor += sizeof(V2_EF660);
        p += sizeof(V2_EF660);
    }
    n = ReadI(cursor);
    self->n68 = n;
    for (int i = 0; i < n; i++) {
        float* f = (float*)*cursor;
        float x = f[0], y = f[1], z = f[2], w = f[3];
        *cursor += sizeof(V4_EF660);
        ((C4_EF660*)p)->b[0] = 255.0f * x;
        ((C4_EF660*)p)->b[1] = 255.0f * y;
        ((C4_EF660*)p)->b[2] = 255.0f * z;
        ((C4_EF660*)p)->b[3] = 255.0f * w;
        p += sizeof(C4_EF660);
    }
    n = ReadI(cursor);
    self->n6A = n;
    { int i = 0; if (i < n) do {
        FR_EF660* src = (FR_EF660*)*cursor;
        Face_EF660* o = (Face_EF660*)p;
        int* pu = fr.uv.v; int* pr = fr.rgb.v;
        fr.xyz = src->xyz; fr.uv = src->uv; fr.rgb = src->rgb;
        *cursor += sizeof(FR_EF660);
        { int j; for (j = 0; j < 3; j++) { o->xyz[j] = fr.xyz.v[j]; o->uv[j] = pu[j]; o->rgb[j] = pr[j]; } }

        p += sizeof(S9_EF660);
    } while (++i < n); }
    p = (char*)(((int)p + 3) & ~3);

    func_003F0580(&types);
    types.owned = 1;
    n = *(int*)*cursor; *cursor += 4;
    self->n6C = n;
    std_vector_pod_AnimType_reserve(&types, n);
    for (int i = 0; i < n; i++) {
        *(void**)p = CreateAnimation(self, cursor, &types);
        p += 4;
    }
    n = ReadI(cursor);
    for (int i = 0; i < n; i++) {
        CreateFeature(self, cursor);
    }
    n = *(int*)*cursor; *cursor += 4;
    self->n6E = n;
    for (int i = 0; i < n; i++) {
        *(void**)p = 0;
        p += 4;
    }

    p -= (int)buf;
    if (p) {
        char* q;
        { AllocGuard g; q = (char*)cMemMan_Allocate(0, (int)p, D_004BE030, 0x1B1); }
        self->a88 = q;
        memcpy(self->a88, buf, (int)p);
        p = self->a88;
        if (self->n64) { self->a70 = (V3_EF660*)p; p += self->n64 * sizeof(V3_EF660); }
        if (self->n66) { self->a74 = (V2_EF660*)p; p += self->n66 * sizeof(V2_EF660); }
        if (self->n68) { self->a78 = (C4_EF660*)p; p += self->n68 * sizeof(C4_EF660); }
        if (self->n6A) { self->a7C = (S9_EF660*)p; p += self->n6A * sizeof(S9_EF660); }
        p = (char*)(((int)p + 3) & ~3);
        if (self->n6C) { self->a80 = (void**)p; p += self->n6C * sizeof(void*); }
        if (self->n6E) { self->a84 = (Self_EF660**)p; }
        if (self->n6C) PatchAnimation(self, &types);
    }
    { AllocGuard g; cMemMan_Deallocate(0, buf, D_004BE030, 0x1C6); }

    for (int i = 0; i < self->n6E; i++) {
        Self_EF660* o;
        { AllocGuard g; o = (Self_EF660*)cMemMan_Allocate(0, 0xE0, D_004BE030, 0x1CA); }
        if (o) o = cInterfaceModel_ctor(o, cursor, arg, self);
        self->a84[i] = o;
    }
    func_003F0490(&types, -1);

    if (self->f18 >= 0 && (g_TextureMgr->tex[self->f18]->flags & 0x100)) {
        self->b63 = 1;
    } else {
        for (int i = 0; i < self->n68; i++) {
            if (self->a78[i].b[3] != 0xFF) {
                self->b63 = 1;
                break;
            }
        }
    }
    return self;
}
