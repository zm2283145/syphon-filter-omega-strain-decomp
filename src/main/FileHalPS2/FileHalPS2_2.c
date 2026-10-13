/*
 * main/FileHalPS2: 4 files, 003695C0-00369820
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003695C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "FileHalPS2_types.h"
extern "C" {
extern char D_004BBDD0[];                           /* "FileHalPS2.cc" */
void Cd_Break(FileHalFile* s);                 /* Cd_Break */
void Mem_Free(int pool, void* p, char* file, int line);
void operator_delete(void* p);
}
/* Abort any read, free an owned buffer and reset to the closed state. */
static inline void FileHal_CloseInline(FileHalFile* s)
{
    if (s->handle >= 0) {
        Cd_Break(s);
        if (s->ownsBuf) {
            void* p = s->buf;
            if (p) {
                {
                    AllocGuard g;
                    Mem_Free(0, p, D_004BBDD0, 0x1DD);
                }
                s->bufSize = 0;
            }
        }
        s->handle = -1;
        s->mode = 0;
        s->buf = 0;
        s->path[0] = 0;
        s->ownsBuf = 0;
        s->bufSize = 0;
    }
}
/* Close the file. */
extern "C" void FileHal_Close(FileHalFile* s)
{
    FileHal_CloseInline(s);
}
#pragma pop /* merge_units */
/* merge_units: end func_003695C0 */

/* merge_units: begin func_003696B0 */
#pragma push /* merge_units */
int FileHal_Open(FileHalFile* f, char* name, int mode);

/* Open name unless already open (then only the mode changes); returns 1 on success. */
int FileHal_Reopen(FileHalFile* f, char* name, int mode) {
    int ret;
    int closed;

    /* the goto shape reproduces the original's unoptimised branch layout */
    ret = f->handle;
    closed = ret < 0;
    if (closed) goto open;
    f->mode = mode;
    goto already_open;
open:;
    ret = FileHal_Open(f, name, mode);
    goto done;
already_open:;
    ret = 0 + 1;
done:;
    goto out;
out:
    return ret;
}
#pragma pop /* merge_units */
/* merge_units: end func_003696B0 */

/* merge_units: begin func_00369700 */
#pragma push /* merge_units */
#pragma cplusplus on
/* Destructor: close, then delete when del > 0. */
extern "C" FileHalFile* FileHal_Dtor(FileHalFile* self, short del)
{
    if (self) {
        FileHal_CloseInline(self);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00369700 */

/* merge_units: begin func_00369820 */
#pragma push /* merge_units */
extern int g_CdReadStatus;                          /* read status (see FileHal_StartRead) */

/* Construct a closed handle, then open name with mode. */
FileHalFile* FileHal_Ctor(FileHalFile* file, char* name, int mode) {
    file->handle = -1;
    file->mode = 0;
    file->buf = 0;
    file->path[0] = 0;
    file->ownsBuf = 0;
    file->bufSize = 0;
    FileHal_Open(file, name, mode);
    return file;
}

/* Default constructor: closed handle with cleared state. */
FileHalFile* FileHal_CtorDefault(FileHalFile* file) {
    file->handle = -1;
    file->mode = 0;
    file->buf = 0;
    file->path[0] = 0;
    file->ownsBuf = 0;
    file->bufSize = 0;
    return file;
}

/* Cd_SetCallback hook: records the completion reason. */
void FileHal_CdCallback(int reason) {
    g_CdReadStatus = reason;
}
#pragma pop /* merge_units */
/* merge_units: end func_00369820 */