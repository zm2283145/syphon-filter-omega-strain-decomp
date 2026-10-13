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
extern void* Mem_Alloc(int pool, int size, char* file, int line);
extern void* func_0013D5C0(int size, int pool, char* file, int line);
extern int strcmp(const char* a, const char* b);
extern void func_003F1C40(void* v, char* value);
extern void* func_003F1C10(void* self);
extern void func_003F1AD0(Vec_0BD0* v);
extern void func_003F1AB0(char** cursor, int* out);
extern void func_003F1AA0(Vec_0BD0* v, int n);
extern void* func_003F1980(void* self, Ent_0BD0* e, char** cursor);
extern void func_003F1960(Vec_0BD0* v, void** p);
extern void func_003F1910(Vec_0BD0* v);
extern void func_003F1900(Vec_0BD0* v, int n);
extern V4_0BD0* func_003F3E30(V4_0BD0* out, char** cursor);
extern void func_003F18E0(Vec_0BD0* v, V4_0BD0* p);
extern void func_003F1890(Vec_0BD0* v);
extern void func_003F1880(Vec_0BD0* v, int n);
extern V2_0BD0* func_003F1FF0(V2_0BD0* out, char** cursor);
extern void func_003F1860(Vec_0BD0* v, V2_0BD0* p);
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
    func_003F1C10(o);
    o->vtable = D_004E0820;
    func_003F1AD0(&o->vec);
    func_003F1AB0(cursor, &n);
    func_003F1AA0(&o->vec, n);
    for (i = 0; i < n; i++) {
        void* c;
        void* m = func_0013D5C0(0x30, 0, D_004BE1A0, 0x90);
        c = m ? func_003F1980(m, e++, cursor) : m;
        func_003F1960(&o->vec, &c);
    }
    return o;
}

static inline ObjB_0BD0* ObjB_Ctor(ObjB_0BD0* o, void* a, char** cursor)
{
    int n;
    int i;
    func_003F1C10(o);
    o->vtable = D_004E07E0;
    o->f18 = 0;
    o->f1C = a;
    func_003F1910(&o->vec);
    func_003F1AB0(cursor, &n);
    func_003F1900(&o->vec, n);
    for (i = 0; i < n; i++) {
        V4_0BD0 t;
        func_003F18E0(&o->vec, func_003F3E30(&t, cursor));
    }
    return o;
}

static inline ObjB_0BD0* ObjC_Ctor(ObjB_0BD0* o, void* a, char** cursor)
{
    int n;
    int i;
    func_003F1C10(o);
    o->vtable = D_004E07C0;
    o->f18 = 0;
    o->f1C = a;
    func_003F1890(&o->vec);
    func_003F1AB0(cursor, &n);
    func_003F1880(&o->vec, n);
    for (i = 0; i < n; i++) {
        V2_0BD0 t;
        func_003F1860(&o->vec, func_003F1FF0(&t, cursor));
    }
    return o;
}

#define CASEC(str, code, line, off) \
    if (strcmp(s.text, str) == 0) { \
        ObjB_0BD0* o; \
        func_003F1C40(names, code); \
        { AllocGuard g; o = (ObjB_0BD0*)Mem_Alloc(0, 0x30, D_004BE030, line); } \
        if (o) o = ObjC_Ctor(o, (char*)self + off, cursor); \
        return o; \
    }

extern "C" void* func_003F0BD0(Self_0BD0* self, char** cursor, void* names)
{
    PStr_0BD0 s;
    char* start = *cursor;
    while (*(*cursor)++) ;
    Copy(&s, s.text, start);
    *cursor = (char*)(((int)*cursor + 3) & ~3);
    if (strcmp(s.text, D_004BE060) == 0) {
        ObjA_0BD0* o;
        func_003F1C40(names, D_00493998);
        { AllocGuard g; o = (ObjA_0BD0*)Mem_Alloc(0, 0x28, D_004BE030, 0x84); }
        if (o) o = ObjA_Ctor(o, self->p70, cursor);
        return o;
    }
    if (strcmp(s.text, D_004BE068) == 0) {
        ObjB_0BD0* o;
        func_003F1C40(names, D_004939A0);
        { AllocGuard g; o = (ObjB_0BD0*)Mem_Alloc(0, 0x30, D_004BE030, 0x89); }
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
