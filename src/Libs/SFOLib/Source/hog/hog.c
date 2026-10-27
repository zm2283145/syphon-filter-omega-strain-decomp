/*
 * main/hog: 6 files, 0036CB90-0036D200
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
#pragma pop /* merge_units */
/* merge_units: end func_0036D380 */
