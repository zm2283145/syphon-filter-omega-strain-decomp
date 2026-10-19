/*
 * main/mem: 3 files, 0036AB80-0036AFC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0036AB80 */
#pragma push /* merge_units */
#pragma opt_propagation off
#include "types.h"
typedef struct {
    char pad[0x9C];
} FileMan;
typedef struct {
    signed char len;
    char text[0x80];
} PStr;
typedef struct {
    int f0;
    char pad4[0x8C];
    unsigned char f90;
    char pad91[3];
    float f94;
    unsigned char f98;
    signed char f99;
    char pad9A[2];
    int f9C;
    char fA0[0xB40];
    unsigned char fBE0;
    char fBE1[1];
} ObjAB80;
extern int g_TextureMgr;
extern void Resource_Construct(FileMan* f);
extern void Hog_Register(FileMan* f, char* name, int a, int b);
extern void FileMan_FindMember(FileMan* f);
extern int FileMan_GetSize(FileMan* f);
extern int FileMan_LoadMemberSync(FileMan* f, unsigned char** out, int size);
extern void func_0036DEC0(FileMan* f);
extern void FileMan_Release(FileMan* f, int flag);
extern int TexMan_FindOrLoad(int mgr, FileMan* f);
extern void* memcpy(void* d, const void* s, unsigned int n);
extern long long SoftFloat_FloatToDouble(float f);
extern long long SoftFloat_DoubleMultiply(long long a, long long b);
extern float SoftFloat_DoubleToFloat(long long a);

static inline void Copy(PStr* buf, char* t, const char* s)
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

static inline unsigned char Rd(unsigned char** pp) { return *(*pp)++; }
void Font_LoadFnt(ObjAB80* obj, int arg1, char* name)
{
    FileMan fm;
    PStr s;
    FileMan fm2;
    unsigned char* data;
    unsigned char flags;
    unsigned char* p;
    unsigned char ver;
    unsigned char nlen;
    int i;
    char* t;

    Resource_Construct(&fm);
    t = s.text;
    s.len = 0;
    Copy(&s, t, name);
    Hog_Register(&fm, (char*)&s + 1, arg1, 0);
    FileMan_FindMember(&fm);
    data = 0;
    FileMan_LoadMemberSync(&fm, &data, FileMan_GetSize(&fm));
    func_0036DEC0(&fm);
    p = data;
    ver = p[0];
    flags = p[1];
    p += 2;
    nlen = p[0];
    p += 1;
    Copy(&s, t, (char*)p);
    for (i = s.len; i > 0; i--, t++) {
        if (*t >= 'a' && *t <= 'z') *t -= 0x20;
    }
    p += nlen;
    obj->f98 = ((signed char*)p)[0];
    obj->f99 = ((signed char*)p)[1];
    p += 2;
    if (ver == 3) {
        obj->f9C = *p++;
    } else {
        obj->f9C = 0x8E;
    }
    if (obj->f9C > 0xB4) {
        FileMan_Release(&fm, -1);
        return;
    }
    memcpy(obj->fA0, p, obj->f9C << 4);
    p += obj->f9C << 4;
    if ((ver == 2 && flags >= 4) || ver > 2) {
        obj->f94 = *(signed char*)p++;
    } else {
        obj->f94 = SoftFloat_DoubleToFloat(SoftFloat_DoubleMultiply((long long)0x3FE00000 << 0x20, SoftFloat_FloatToDouble(obj->f98 / 2.0f * obj->f90)));
    }
    if ((ver == 2 && flags != 0) || ver > 2) {
        obj->fBE0 = *(signed char*)p != 0;
        if (obj->fBE0) {
            memcpy(obj->fBE1, p + 1, obj->f9C * obj->f9C);
        }
    } else {
        obj->fBE0 = 0;
    }
    Resource_Construct(&fm2);
    Hog_Register(&fm2, (char*)&s + 1, arg1, 0);
    obj->f0 = TexMan_FindOrLoad(g_TextureMgr, &fm2);
    FileMan_Release(&fm2, -1);
    FileMan_Release(&fm, -1);
}
#pragma pop /* merge_units */
/* merge_units: end func_0036AB80 */

/* merge_units: begin func_0036AF40 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Deleting destructor: restore the vtable of the subobject at +0x8A74, release the handle at +0. */
extern "C" {
extern void * const D_004DF630[];
void operator_delete(void* allocation);
void Tex_Release(int mgr, int handle, int flags);
}
struct O36AF40 { int handle; char pad[0x8A70]; void* vtable; };
extern "C" O36AF40* func_0036AF40(O36AF40* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DF630);
        Tex_Release(g_TextureMgr, self->handle, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DF630[4] = { (void*)0x0, (void*)0x0, (void*)func_0036AF40, (void*)0x0 };
#pragma pop /* merge_units */
/* merge_units: end func_0036AF40 */

/* merge_units: begin func_0036AFC0 */
#pragma push /* merge_units */
typedef struct Scale4 {
    float x, y, z, w;
} Scale4;

typedef struct Obj36A {
    char pad[0x10];
    Scale4 scales[8];
    unsigned char enabled;
    char pad2[0xB];
    int unk9C;
    char pad3[0x8A74 - 0xA0];
    void* vtable;
} Obj36A;

#if 0 /* merge_units */
extern char D_004DF630[]; /* vtable */
#endif /* merge_units */
#define D_004DF630 ((char*)&D_004DF630) /* merge_units */


/* Constructor: sets the vtable, eight (0.5, 0.5, 0.5, 1) entries, enabled = 1. */
Obj36A* Font_ctor(Obj36A* self) {
    int i;
    self->vtable = D_004DF630;
    for (i = 0; i < 8; i++) {
        self->scales[i].x = 0.5f;
        self->scales[i].y = 0.5f;
        self->scales[i].z = 0.5f;
        self->scales[i].w = 1.0f;
    }
    self->enabled = 1;
    self->unk9C = 0;
    return self;
}
#undef D_004DF630 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036AFC0 */
