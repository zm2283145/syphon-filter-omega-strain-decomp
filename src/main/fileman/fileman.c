/*
 * main/fileman: fileman.cc (15 files, 0036D680-0036E220)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0036D680 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct S36D680 { unsigned int flags; char name[0x94]; int* f; };
extern "C" {
extern char D_004BBF90[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void Mem_Free(int pool, void* p, char* file, int line);
int FileHal_Reopen(void* f, void* name, int mode);
void FileHal_Dtor(void* f, int how);
int* FileHal_CtorDefault(void* p);
}
static inline void* New36D680()
{
    AllocGuard g;
    return Mem_Alloc(0, 0xC8, D_004BBF90, 0x21A);
}
static inline void Del36D680(int* f)
{
    AllocGuard g;
    FileHal_Dtor(f, -1);
    Mem_Free(0, f, D_004BBF90, 0x235);
}
extern "C" int func_0036D680(S36D680* o)
{
    unsigned char open = 1;
    int err = 0;
    if (!o->f) {
        int* p = (int*)New36D680();
        if (p) p = FileHal_CtorDefault(p);
        o->f = p;
        o->flags |= 0x10;
    } else if (*o->f >= 0) {
        open = 0;
    }
    if (open) {
        if (o->flags & 4) {
            FileHal_Reopen(o->f, o->name, 0x8000);
            err = 3;
        } else if (!FileHal_Reopen(o->f, o->name, 1)) {
            err = 3;
        }
    }
    if ((unsigned char)err && (o->flags & 0x10)) {
        Del36D680(o->f);
        o->flags &= ~0x10;
    }
    return err;
}
#pragma pop /* merge_units */
/* merge_units: end func_0036D680 */

/* merge_units: begin func_0036D880 */
#pragma push /* merge_units */
typedef struct { char pad[0x14C]; unsigned char a14C; } C36D880;
typedef struct { unsigned int flags; char pad[0x94]; C36D880* a98; } S36D880;
int func_0036D880(S36D880* o)
{
    if (o->flags & 2) {
        if (o->a98->a14C == 2) return 1;
    } else if (o->flags & 1) {
        return 1;
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0036D880 */

/* merge_units: begin func_0036D8E0 */
#pragma push /* merge_units */
typedef struct { unsigned int flags; char pad[0x94]; char* a98; } S36D8E0;
extern int FileHal_PollRead(char* p);
int FileMan_PollRead(S36D8E0* o)
{
    int r = 1;
    if (o->flags & 4) {
        if (o->flags & 2) r = FileHal_PollRead(o->a98 + 0x80);
        else if (o->flags & 1) r = FileHal_PollRead(o->a98);
        else r = 1;
    }
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_0036D8E0 */

/* merge_units: begin func_0036D950 */
#pragma push /* merge_units */
extern int func_0036CAC0(void* target, int id, int value, int flag);

typedef struct { unsigned int flags; char pad[0x80]; short id; char pad2[0x12]; void* target; } Obj;

/* If flag bit 1 is set, forwards *value to the target and returns true. */
unsigned char FileMan_ReadMember(Obj* self, int* value)
{
    unsigned char result = 0;
    if (self->flags & 2) {
        func_0036CAC0(self->target, self->id, *value, 1);
        result = 1;
    }
    return result;
}
#pragma pop /* merge_units */
/* merge_units: end func_0036D950 */

/* merge_units: begin func_0036D990 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char* p0; int p4; char* p8; unsigned char c; } H36D990;
typedef struct { unsigned int flags; char pad[0x80]; short idx; H36D990 h; char* a98; } S36D990;
extern "C" {
int FileHal_Read(void* f, void* buf, int size, int off);
#if 0 /* merge_units */
int func_0036CAC0(void* f, int idx, void* buf, int off);
#endif /* merge_units */
#define func_0036CAC0(a0, a1, a2, a3) (func_0036CAC0((a0), (a1), (int)(a2), (a3))) /* merge_units */

int Hog_GetEntrySize(void* f, int idx);
char* Hog_GetMemberInPlace(void* f, int idx);
}
static inline char* Get(H36D990* h) { return h->p8 ? h->p8 : h->p0; }
static inline int GetSize(S36D990* o)
{
    unsigned int f = o->flags;
    if (f & 2) return Hog_GetEntrySize(o->a98, o->idx);
    if (f & 1) return (*(int*)(o->a98 + 0x2C) / 0x800) * 0x800 + 0x800;
    return 0;
}
static inline void* Alloc36D990(int size, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, D_004BBF90, line);
}
extern "C" int FileMan_LoadMemberSync(S36D990* o, char** out, int size)
{
    unsigned int f;
    int err;
    H36D990* h;
    int sz;
    if (size) sz = size; else sz = GetSize(o);
    f = o->flags;
    err = 0;
    h = &o->h;
    if ((f & 4) && h->c) {
        *out = Get(h);
    } else if (f & 2) {
        char* d = o->a98;
        if (*(unsigned char*)(d + 0x14C) == 2) {
            if (h->c) {
                *out = Get(h);
            } else {
                if (!*out) *out = (char*)Alloc36D990(sz, 0x176);
                if (func_0036CAC0(o->a98, o->idx, *out, 0)) err = 4;
            }
        } else {
            *out = Hog_GetMemberInPlace(d, o->idx);
        }
    } else if (f & 1) {
        if (!*out) *out = (char*)Alloc36D990(sz, 0x18F);
        if (!FileHal_Read(o->a98, *out, sz, 0)) err = 4;
    } else {
        err = 5;
    }
    return err;
}
#undef func_0036CAC0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036D990 */

/* merge_units: begin func_0036DC60 */
#pragma push /* merge_units */
typedef struct { char* p0; int p4; char* p8; unsigned char c; } H36DC60;
typedef struct { char pad[0x14C]; unsigned char mode; } D36DC60;
typedef struct { unsigned int flags; char pad[0x80]; short idx; H36DC60 h; char* a98; } S36DC60;
int FileHal_ReadAll(void*, void*);
char* func_0036CAB0(void*);
void Hog_ReadEntry(void*, int, int);
#if 0 /* merge_units */
char* Hog_GetMemberInPlace(void*, int);
#endif /* merge_units */
#define Hog_GetMemberInPlace(a0, a1) (Hog_GetMemberInPlace((a0), (a1))) /* merge_units */

static inline char* Get_0036DC60(H36DC60* h) { return h->p8 ? h->p8 : h->p0; }
char* FileMan_ReadData(S36DC60* o)
{
    unsigned int f = o->flags;
    H36DC60* h = &o->h;
    if ((f & 4) && h->c) return Get_0036DC60(h);
    if (f & 2) {
        D36DC60* d = (D36DC60*)o->a98;
        if (d->mode == 2) {
            if (h->c) return Get_0036DC60(h);
            Hog_ReadEntry(d, o->idx, 0);
            return func_0036CAB0(o->a98);
        }
        return Hog_GetMemberInPlace(d, o->idx);
    }
    if (f & 1) return FileHal_ReadAll(o->a98, h) ? *(char**)(o->a98 + 0xC4) : 0;
    return 0;
}
#undef Hog_GetMemberInPlace /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036DC60 */

/* merge_units: begin func_0036DD80 */
#pragma push /* merge_units */
typedef struct { unsigned int flags; char pad[0x94]; char* a98; } S36DD80;
char* func_0036DD80(S36DD80* o)
{
    if (o->flags & 2) return o->a98 + 0x80;
    if (o->flags & 1) return o->a98;
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0036DD80 */

/* merge_units: begin func_0036DDC0 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Hdr_36DDC0 { char pad[0x10]; int f10; };
struct Arc_36DDC0 { char pad0[4]; int f4; char pad8[0x7C]; int f84; char pad88[0xC0]; Hdr_36DDC0* f148; };
struct FME_36DDC0 { int flags; char name[128]; short h84; int a88; int a8C; int a90; unsigned char b94; Arc_36DDC0* a98; };

extern "C" int Hog_GetMemberOffset(Arc_36DDC0*, int);

static inline int Off(Arc_36DDC0* a, int idx) { return a->f148->f10 + Hog_GetMemberOffset(a, idx); }

extern "C" int func_0036DDC0(FME_36DDC0* f)
{
    if (f->flags & 2) {
        int s = Off(f->a98, f->h84) / 2048;
        const int b = f->a98->f84;
        return b + s;
    }
    if (f->flags & 1) return f->a98->f4;
    return -1;
}
#pragma pop /* merge_units */
/* merge_units: end func_0036DDC0 */

/* merge_units: begin func_0036DE50 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#if 0 /* merge_units */
int Hog_GetEntrySize(int, int);
#endif /* merge_units */
#define Hog_GetEntrySize(a0, a1) (Hog_GetEntrySize((void *)(a0), (a1))) /* merge_units */

int FileMan_GetSize(char * arg0) {
    int f = F_(arg0, 0x0, int);
    if (f & 2) {
        return Hog_GetEntrySize(F_(arg0, 0x98, int), F_(arg0, 0x84, short));
    }
    if (f & 1) {
        return (F_(F_(arg0, 0x98, int), 0x2C, int) / 0x800) * 0x800 + 0x800;
    }
    return 0;
}
#undef Hog_GetEntrySize /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036DE50 */

/* merge_units: begin func_0036DEC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * fileman.cc
 */

#include "fileman_types.h"

extern int FileHal_Close(int halFile);

/* If the entry has an open file (flag bit 0), pass its HAL file to FileHal_Close. */
void func_0036DEC0(FileManEntry* entry) {
    if (entry->flags & 1) {
        FileHal_Close(entry->halFile);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0036DEC0 */

/* merge_units: begin func_0036DEF0 */
#pragma push /* merge_units */
typedef struct { char p0[0x14C]; unsigned char ready; } Y36DEF0;
typedef struct { unsigned int flags; char p4[0x80]; short h84; char p86[0x12]; Y36DEF0* y; } X36DEF0;
extern short Hog_FindFileNoCase(Y36DEF0* y, void* p, int z);
#if 0 /* merge_units */
extern int func_0036D680(X36DEF0* x);
#endif /* merge_units */
#define func_0036D680(a0) ((int)func_0036D680((void *)(a0))) /* merge_units */

/* Polls the stream state: 1 idle, 2 not ready, 3 failed open, 0 opened, 5 nothing to do. */
int FileMan_FindMember(X36DEF0* x)
{
    if (x->flags == 0) return 1;
    if (x->flags & 2) {
        int r;
        if (!x->y->ready) r = 2;
        else {
            x->h84 = Hog_FindFileNoCase(x->y, (char*)x + 4, 0);
            if (x->h84 == -1) r = 3;
            else r = 0;
        }
        return r;
    }
    if (x->flags & 1) { int r = func_0036D680(x); return r; }
    return 5;
}
#undef func_0036D680 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036DEF0 */

/* merge_units: begin func_0036DFB0 */
#pragma push /* merge_units */
typedef struct { unsigned int flags; char name[0x80]; char pad[0x14]; char* a98; } F36DFB0;
char* strncpy(char*, const char*, int);
static inline int Kind(F36DFB0* f)
{
    if (f->flags & 2) return 2;
    if (f->flags & 1) return 1;
    return 0;
}
static inline char* Data(F36DFB0* f)
{
    if (*(int*)f & 2) return f->a98 + 0x80;
    if (*(int*)f & 1) return f->a98;
    return 0;
}
int func_0036DFB0(F36DFB0* d, const char* name, F36DFB0* s)
{
    if ((unsigned char)Kind(s) == 1) {
        int c = (*(int*)s & 4) != 0;
        char* p = Data(s);
        d->flags = 0;
        strncpy(d->name, name, 0x80);
        d->a98 = p;
        d->flags |= 1;
        if (c) d->flags |= 4;
    } else if ((unsigned char)Kind(s) == 2) {
        int c = (*(int*)s & 4) != 0;
        strncpy(d->name, name, 0x80);
        d->a98 = s->a98;
        d->flags = 0;
        d->flags |= 2;
        if (c) d->flags |= 4;
    } else return 5;
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0036DFB0 */

/* merge_units: begin func_0036E140 */
#pragma push /* merge_units */
typedef struct {
    unsigned int flags;
    char name[0x94];
    int f98;
} Hog_36E1B0;
#if 0 /* merge_units */
extern char* strncpy(char* d, const char* s, unsigned int n);
#endif /* merge_units */
#define strncpy(a0, a1, a2) (strncpy((a0), (a1), (int)(a2))) /* merge_units */

int func_0036E140(Hog_36E1B0* h, const char* name, int arg, int opt) {
    h->flags = 0;
    strncpy(h->name, name, 0x80);
    h->f98 = arg;
    h->flags |= 1;
    if (opt)
        h->flags |= 4;
    return 0;
}
#undef strncpy /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036E140 */

/* merge_units: begin func_0036E1B0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern char* strncpy(char* d, const char* s, unsigned int n);
#endif /* merge_units */
#define strncpy(a0, a1, a2) (strncpy((a0), (a1), (int)(a2))) /* merge_units */

int Hog_Register(Hog_36E1B0* h, const char* name, int arg, int opt) {
    h->flags = 0;
    strncpy(h->name, name, 0x80);
    h->f98 = arg;
    h->flags |= 2;
    if (opt)
        h->flags |= 4;
    return 0;
}
#undef strncpy /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036E1B0 */

/* merge_units: begin func_0036E220 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma exceptions off
extern "C" {
#if 0 /* merge_units */
void FileHal_Dtor(void* p, int n);
#endif /* merge_units */
#define FileHal_Dtor(a0, a1) (FileHal_Dtor((a0), (a1))) /* merge_units */

void operator_delete(void* p);
}
typedef struct { int flags; char pad4[0x94]; void* p98; } F8Obj_36E;
extern "C" F8Obj_36E* FileMan_Release(F8Obj_36E* o, short del)
{
    if (o) {
        if (o->flags & 0x10) {
            void* p = o->p98;
            AllocGuard g;
            FileHal_Dtor(p, -1);
            Mem_Free(0, p, D_004BBF90, 0x4C);
        }
        if (del > 0)
            operator_delete(o);
    }
    return o;
}
#undef FileHal_Dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036E220 */
