/*
 * main/hog: 2 files, 0036CB90-0036CD80
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
void FileHal_Reopen(FileHalFile* f, char* name, int mode); /* FileHal_Reopen */
void FileHal_Read(FileHalFile* f, void* buf, int size, int off); /* FileHal_Read */
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