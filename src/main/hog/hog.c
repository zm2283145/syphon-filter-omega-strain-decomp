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
void* Mem_Alloc(int pool, int size, char* file, int line);
void FileHal_Close(FileHalFile* f);                 /* FileHal_Close */
int FileHal_Reopen(FileHalFile* f, char* name, int mode); /* FileHal_Reopen */
int FileHal_Read(FileHalFile* f, void* buf, int size, int off); /* FileHal_Read */
}
static inline int Hog_EntrySize(Hog* s, int i)
{
    if (!s->mode) return 0;
    return s->offsets[i + 1] - s->offsets[i];
}
static inline void* Hog_Alloc(int pool, int size)
{
    AllocGuard g;
    return Mem_Alloc(pool, size, D_004BBF88, 0x16C);
}
/*
 * Streamed hogs: read entry idx into the shared entry buffer (allocated on
 * first use at the largest entry size). Returns 0 on success, 4 when the hog
 * is not streamed, 3 when the buffer cannot be allocated.
 */
extern "C" int Hog_ReadEntry(Hog* s, int idx, int direct)
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
            FileHal_Close(&s->file);
            return 3;
        }
    }
    if (direct)
        FileHal_Reopen(&s->file, s->name, FILEHAL_MODE_DIRECT);
    else
        FileHal_Reopen(&s->file, s->name, 1);
    {
        int off = s->offsets[idx];
        FileHal_Read(&s->file, s->buf, s->mode ? s->offsets[idx + 1] - off : 0, s->hdr->headerSize + off);
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0036CB90 */

/* merge_units: begin func_0036CD80 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
void Mem_Free(int pool, void* p, char* file, int line);
}
static inline void Hog_Free(void* p, int pool, int line)
{
    AllocGuard g;
    Mem_Free(pool, p, D_004BBF88, line);
}
/* Close the file and free the buffers; the hog returns to the unloaded state. */
extern "C" int Hog_Unload(Hog* s)
{
    if (!s->mode)
        return 0;
    FileHal_Close(&s->file);
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
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
#endif /* merge_units */
#define Mem_Alloc(a0, a1, a2, a3) (Mem_Alloc((a0), (int)(a1), (a2), (a3))) /* merge_units */


void String_Copy(char* d, char* s);
#if 0 /* merge_units */
int FileHal_Read(FileHalFile* f, void* buf, int size, int pos); /* FileHal_Read */
#endif /* merge_units */
#define FileHal_Read(a0, a1, a2, a3) (FileHal_Read((a0), (a1), (a2), (a3))) /* merge_units */


}
static inline void* Hog_Alloc_0036CEF0(int pool, unsigned int n, int line) { AllocGuard g; return Mem_Alloc(pool, n, D_004BBF88, line); }

/*
 * Open the archive name. Resident (stream == 0): load the whole file.
 * Streamed: load only the header. Returns 0 on success, 1 when the file is
 * missing, 2 on a read error, 3 when out of memory (0 too if already open).
 */
extern "C" int Hog_Load(Hog* self, char* name, int stream, int pool)
{
    int n;
    if (self->file.handle >= 0) return 0;
    if (!FileHal_Reopen(&self->file, name, 1)) return 1;
    String_Copy(self->name, name);
    n = (self->file.size / CD_SECTOR_SIZE) * CD_SECTOR_SIZE + CD_SECTOR_SIZE;
    if (!stream) {
        self->mode = HOG_RESIDENT;
        self->buf = Hog_Alloc_0036CEF0(pool, n, 0xE2);
        if (!self->buf) {
            FileHal_Close(&self->file);
            return 3;
        }
        if (!FileHal_Read(&self->file, self->buf, n, 0)) {
            { void* b = self->buf; AllocGuard g; Mem_Free(pool, b, D_004BBF88, 0xF2); }
            FileHal_Close(&self->file);
            return 2;
        }
        self->hdr = (HogHeader*)self->buf;
        self->names = (char*)self->buf + self->hdr->namesOff;
        self->offsets = (int*)((char*)self->buf + self->hdr->offsetsOff);
        FileHal_Close(&self->file);
    } else {
        HogHeader h;
        self->mode = HOG_STREAMED;
        FileHal_Read(&self->file, &h, sizeof(HogHeader), 0);
        self->hdr = (HogHeader*)Hog_Alloc_0036CEF0(pool, h.headerSize, 0x104);
        FileHal_Read(&self->file, self->hdr, h.headerSize, 0);
        self->names = (char*)self->hdr + self->hdr->namesOff;
        self->offsets = (int*)((char*)self->hdr + self->hdr->offsetsOff);
    }
    self->cursor = 0;
    self->cursorName = self->names;
    self->pool = pool;
    return 0;
}
#undef Mem_Alloc /* merge_units */
#undef FileHal_Read /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0036CEF0 */

/* merge_units: begin func_0036D200 */
#pragma push /* merge_units */
typedef struct { char pad[0x14C]; unsigned char on; char p1[3]; unsigned int idx; char* cur; char p2[4]; char* base; } SL36D2;
#pragma opt_rotateloops off
char* Archive_GetMemberName(SL36D2* p, int n) {
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
int Hog_FindFileNoCase(S36D2A0* o, char* name)
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
int Hog_GetEntrySize(S36D380* o, int k)
{
    if (!o->a14C) return 0;
    return o->a160[k + 1] - o->a160[k];
}
#pragma pop /* merge_units */
/* merge_units: end func_0036D380 */
