/*
 * Libs/SFOLib/Source/hog: 12 files, 0036CB90-0036D630
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0036CB90 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "hog_types.h"
extern "C" {
extern char D_004BBF88[];                           /* "hog.cc" */
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void cFileIO_Close(FileHalFile* f);                 /* cFileIO_Close */
int cFileIO_Open(FileHalFile* f, char* name, int mode); /* cFileIO_Open */
int cFileIO_Read_charP_int_int(FileHalFile* f, void* buf, int size, int off); /* cFileIO_Read_charP_int_int */
}
static inline int Hog_EntrySize(Hog* s, int i)
{
    if (!s->mode) return 0;
    return s->offsets[i + 1] - s->offsets[i];
}
static inline void* Hog_Alloc(int pool, int size)
{
    AllocGuard g;
    return cMemMan_Allocate(pool, size, D_004BBF88, 0x16C);
}
/*
 * Streamed hogs: read entry idx into the shared entry buffer (allocated on
 * first use at the largest entry size). Returns 0 on success, 4 when the hog
 * is not streamed, 3 when the buffer cannot be allocated.
 */
extern "C" int cHogFile_Stream_int_bool(Hog* s, int idx, int direct)
{
    if (*(volatile unsigned char*)&s->mode != HOG_STREAMED) return 4;
    if (!s->buf) {
        int max = 0;
        int i;
        for (i = 0; i < s->hdr->count; i++) {
            int n = Hog_EntrySize(s, i);
            max = max < n ? n : max;
        }
        s->buf = Hog_Alloc(s->pool, max);
        if (!s->buf) {
            cFileIO_Close(&s->file);
            return 3;
        }
    }
    if (direct)
        cFileIO_Open(&s->file, s->name, FILEHAL_MODE_DIRECT);
    else
        cFileIO_Open(&s->file, s->name, 1);
    {
        int off = s->offsets[idx];
        cFileIO_Read_charP_int_int(&s->file, s->buf, s->mode ? s->offsets[idx + 1] - off : 0, s->hdr->headerSize + off);
    }
    return 0;
}
static inline void merge_flush_func_0036CB90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036CB90 */

/* merge_units: begin func_0036CD80 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
}
static inline void Hog_Free(void* p, int pool, int line)
{
    AllocGuard g;
    cMemMan_Deallocate(pool, p, D_004BBF88, line);
}
/* Close the file and free the buffers; the hog returns to the unloaded state. */
extern "C" int cHogFile_CloseHog(Hog* s)
{
    if (!s->mode)
        return 0;
    cFileIO_Close(&s->file);
    if (s->buf) {
        Hog_Free(s->buf, s->pool, 0x122);
        s->buf = 0;
    }
    if (s->mode == HOG_STREAMED) {
        Hog_Free(s->hdr, s->pool, 0x128);
    }
    s->hdr = 0;
    s->names = 0;
    s->offsets = 0;
    s->pool = 0;
    s->mode = 0;
    return 0;
}
static inline void merge_flush_func_0036CD80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036CD80 */

/* merge_units: begin func_0036CEF0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
#if 0 /* merge_units */
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
#endif /* merge_units */
#define cMemMan_Allocate(a0, a1, a2, a3) (cMemMan_Allocate((a0), (int)(a1), (a2), (a3))) /* merge_units */



void Libc_Strcpy(char* d, char* s);
#if 0 /* merge_units */
int cFileIO_Read_charP_int_int(FileHalFile* f, void* buf, int size, int pos); /* cFileIO_Read_charP_int_int */
#endif /* merge_units */
#define cFileIO_Read_charP_int_int(a0, a1, a2, a3) (cFileIO_Read_charP_int_int((a0), (a1), (a2), (a3))) /* merge_units */



}
static inline void* Hog_Alloc_0036CEF0(int pool, unsigned int n, int line) { AllocGuard g; return cMemMan_Allocate(pool, n, D_004BBF88, line); }

/*
 * Open the archive name. Resident (stream == 0): load the whole file.
 * Streamed: load only the header. Returns 0 on success, 1 when the file is
 * missing, 2 on a read error, 3 when out of memory (0 too if already open).
 */
extern "C" int cHogFile_OpenHog(Hog* self, char* name, int stream, int pool)
{
    int n;
    if (self->file.handle >= 0) return 0;
    if (!cFileIO_Open(&self->file, name, 1)) return 1;
    Libc_Strcpy(self->name, name);
    n = (self->file.size / CD_SECTOR_SIZE) * CD_SECTOR_SIZE + CD_SECTOR_SIZE;
    if (!stream) {
        self->mode = HOG_RESIDENT;
        self->buf = Hog_Alloc_0036CEF0(pool, n, 0xE2);
        if (!self->buf) {
            cFileIO_Close(&self->file);
            return 3;
        }
        if (!cFileIO_Read_charP_int_int(&self->file, self->buf, n, 0)) {
            { void* b = self->buf; AllocGuard g; cMemMan_Deallocate(pool, b, D_004BBF88, 0xF2); }
            cFileIO_Close(&self->file);
            return 2;
        }
        self->hdr = (HogHeader*)self->buf;
        self->names = (char*)self->buf + self->hdr->namesOff;
        self->offsets = (int*)((char*)self->buf + self->hdr->offsetsOff);
        cFileIO_Close(&self->file);
    } else {
        HogHeader h;
        self->mode = HOG_STREAMED;
        cFileIO_Read_charP_int_int(&self->file, &h, sizeof(HogHeader), 0);
        self->hdr = (HogHeader*)Hog_Alloc_0036CEF0(pool, h.headerSize, 0x104);
        cFileIO_Read_charP_int_int(&self->file, self->hdr, h.headerSize, 0);
        self->names = (char*)self->hdr + self->hdr->namesOff;
        self->offsets = (int*)((char*)self->hdr + self->hdr->offsetsOff);
    }
    self->cursor = 0;
    self->cursorName = self->names;
    self->pool = pool;
    return 0;
}
#undef cMemMan_Allocate /* merge_units */
#undef cFileIO_Read_charP_int_int /* merge_units */
static inline void merge_flush_func_0036CEF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036CEF0 */

/* merge_units: begin func_0036D200 */
#pragma push /* merge_units */
typedef struct { char pad[0x14C]; unsigned char on; char p1[3]; unsigned int idx; char* cur; char p2[4]; char* base; } SL36D2;
#pragma opt_rotateloops off
char* cHogFile_GetBlockName(SL36D2* p, int n) {
    int i;
    char* s;
    char* r;
    if (!p->on) return 0;
    s = p->base;
    i = 0;
    if (!(n < p->idx)) { s = p->cur; i = p->idx; }
    while (i < n) { while (*s++) ; i++; }
    p->idx = i;
    r = s;
    while (*s++) ;
    p->cur = r;
    return p->cur;
}
#pragma opt_rotateloops reset
static inline void merge_flush_func_0036D200(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036D200 */

/* merge_units: begin func_0036D2A0 */
#pragma push /* merge_units */
typedef struct { int pad0; int count; } H36D2A0;
typedef struct { char pad[0x148]; H36D2A0* hdr; unsigned char loaded; char pad14D[0xF]; char* names; } S36D2A0;
extern int String_CompareNoCase(char* a, char* b);
int cHogFile_GetBlockIndex(S36D2A0* o, char* name)
{
    int i;
    char* s;
    if (!o->loaded) return 0;
    s = o->names;
    for (i = 0; i < o->hdr->count; i++) {
        char* cur = s;
        while (*s++) ;
        if (String_CompareNoCase(name, cur) == 0) break;
    }
    if (i >= o->hdr->count) i = -1;
    return i;
}
static inline void merge_flush_func_0036D2A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036D2A0 */

/* merge_units: begin func_0036D380 */
#pragma push /* merge_units */
typedef struct { char pad[0x14C]; unsigned char a14C; char pad2[0x13]; int* a160; } S36D380;
int cHogFile_GetBlockSize(S36D380* o, int k)
{
    if (!o->a14C) return 0;
    return o->a160[k + 1] - o->a160[k];
}
static inline void merge_flush_func_0036D380(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036D380 */

/* merge_units: begin func_0036D3C0 */
#pragma push /* merge_units */
typedef struct { int pad0; int count; int pad8; int padC; int dataOffset; } H36D3C0;
typedef struct {
    char pad[0x148]; H36D3C0* hdr; unsigned char loaded; char pad14D[0xB];
    char* base; char* names; int* offsets;
} S36D3C0;
char* cHogFile_GetBlock_charP_bool(S36D3C0* o, char* name)
{
    int i;
    char* s;
    H36D3C0* h;
    if (!o->loaded) return 0;
    s = o->names;
    for (i = 0; i < o->hdr->count; i++) {
        char* cur = s;
        while (*s++) ;
        if (String_CompareNoCase(name, cur) == 0) break;
    }
    h = o->hdr;
    if (i >= h->count) i = -1;
    if (i == -1) return 0;
    if (!o->loaded) return 0;
    return o->base + h->dataOffset + o->offsets[i];
}
static inline void merge_flush_func_0036D3C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036D3C0 */

/* merge_units: begin func_0036D4E0 */
#pragma push /* merge_units */
typedef struct { char pad[0x10]; int base; } B;
typedef struct { char pad[0x148]; B* b; unsigned char on; char p2[0x158-0x14D]; int off; char p3[4]; int* tbl; } S;
/* Returns offset + base + table[i] when enabled, else 0. */
int cHogFile_GetBlock_int(S* s, int i) { if (!s->on) return 0; return s->off + s->b->base + s->tbl[i]; }
static inline void merge_flush_func_0036D4E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036D4E0 */

/* merge_units: begin func_0036D520 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

int cHogFile_GetBlockOffset(Obj36D630* self, int index) {
    return self->unk160[index];
}
static inline void merge_flush_func_0036D520(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036D520 */

/* merge_units: begin func_0036D540 */
#pragma push /* merge_units */
typedef struct ChunkHdr {
    int unk00;
    int unk04;
    int dataOffset;  /* 0x08 */
    int startOffset; /* 0x0C */
} ChunkHdr;

typedef struct ChunkReader {
    char name[0x148];      /* 0x000 */
    ChunkHdr* hdr;         /* 0x148 */
    unsigned char loaded;  /* 0x14C */
    char pad14D[3];
    int pos;               /* 0x150 */
    char* cursor;          /* 0x154 */
    char* base;            /* 0x158 */
    char* start;           /* 0x15C */
    char* data;            /* 0x160 */
    int user;              /* 0x164 */
} ChunkReader;

#if 0 /* merge_units */
extern void Libc_Strcpy(char* dst, const char* src);
#endif /* merge_units */
#define Libc_Strcpy(a0, a1) (Libc_Strcpy((a0), (char *)(a1))) /* merge_units */


/* Binds a loaded chunk buffer to the reader; returns 0. */
int cHogFile_Open(ChunkReader* r, const char* name, char* buffer, int user) {
    Libc_Strcpy(r->name, name);
    r->loaded = 1;
    r->base = buffer;
    r->hdr = (ChunkHdr*)r->base;
    r->start = r->base + r->hdr->startOffset;
    r->data = r->base + r->hdr->dataOffset;
    r->pos = 0;
    r->user = user;
    r->cursor = r->start;
    return 0;
}
#undef Libc_Strcpy /* merge_units */
static inline void merge_flush_func_0036D540(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036D540 */

/* merge_units: begin func_0036D5D0 */
#pragma push /* merge_units */
typedef struct { char pad[0x80]; char m80[4]; } O36D5D0;
extern void cFileIO_dtor(void* p, int f);
extern void operator_delete(void* p);
O36D5D0* cHogFile_dtor(O36D5D0* self, short del)
{
    if (self) {
        cFileIO_dtor(self->m80, -1);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
static inline void merge_flush_func_0036D5D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036D5D0 */

/* merge_units: begin func_0036D630 */
#pragma push /* merge_units */
extern int cFileIO_ctor_void(void*);

/* Constructor: builds the sub-object at +0x80 and clears the remaining state. */
Obj36D630* cHogFile_ctor(Obj36D630* self) {
    cFileIO_ctor_void(self->unk80);
    self->unk148 = 0;
    self->unk158 = 0;
    self->unk15C = 0;
    self->unk164 = 0;
    self->unk168 = 0;
    self->unk14C = 0;
    return self;
}
static inline void merge_flush_func_0036D630(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036D630 */
