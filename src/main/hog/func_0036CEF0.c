#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "hog_types.h"

extern "C" {
extern char D_004BBF88[];                           /* "hog.cc" */
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
void Mem_Free(int pool, void* p, char* file, int line);
void String_Copy(char* d, char* s);
int FileHal_Reopen(FileHalFile* f, char* name, int mode);   /* FileHal_Reopen */
void FileHal_Close(FileHalFile* f);                         /* FileHal_Close */
int FileHal_Read(FileHalFile* f, void* buf, int size, int pos); /* FileHal_Read */
}
static inline void* Hog_Alloc(int pool, unsigned int n, int line) { AllocGuard g; return Mem_Alloc(pool, n, D_004BBF88, line); }

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
        self->buf = Hog_Alloc(pool, n, 0xE2);
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
        self->hdr = (HogHeader*)Hog_Alloc(pool, h.headerSize, 0x104);
        FileHal_Read(&self->file, self->hdr, h.headerSize, 0);
        self->names = (char*)self->hdr + self->hdr->namesOff;
        self->offsets = (int*)((char*)self->hdr + self->hdr->offsetsOff);
    }
    self->cursor = 0;
    self->cursorName = self->names;
    self->pool = pool;
    return 0;
}