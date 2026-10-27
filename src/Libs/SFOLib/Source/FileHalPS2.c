/*
 * main/FileHalPS2: 11 files, 00368F60-003698B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00368F60 */
#pragma push /* merge_units */
#include "types.h"
#include "FileHalPS2_types.h"
/* sceCdRMode */
typedef struct CdReadMode { unsigned char retries; unsigned char speed; unsigned char pattern; unsigned char pad; } CdReadMode;
extern int g_FrameCounter;
extern int g_CdReadStatus;                              /* read status: -1 busy, else callback reason */
extern int snd_StreamSafeCdSync(int mode);                 /* snd_StreamSafeCdSync: nonzero while busy */
extern int snd_StreamSafeCdRead(int lsn, int sectors, void* buf, CdReadMode* mode); /* snd_StreamSafeCdRead */
extern void snd_StreamSafeCdCallback(void* cb);                /* snd_StreamSafeCdCallback */
extern void CdCallback(int reason);
/* Issue an async read of bufSize bytes at byte offset pos into buf. */
int cFileIO_ReadFile(FileHalFile* o, int pos)
{
    CdReadMode mode;
    int sector;
    int i;
    mode.retries = 0xFF;
    mode.pattern = 0;
    sector = pos / CD_SECTOR_SIZE;
    mode.speed = 1;
    i = 0;
    while (snd_StreamSafeCdSync(0) && i++ < 10000) ;
    snd_StreamSafeCdRead(o->info.lsn + sector, o->bufSize / CD_SECTOR_SIZE, o->buf, &mode);
    snd_StreamSafeCdCallback(CdCallback);
    o->startFrame = o->pollFrame = g_FrameCounter;
    o->timeoutFrames = FILEHAL_TIMEOUT_FRAMES;
    g_CdReadStatus = -1;
    if (o->mode != FILEHAL_MODE_DIRECT) snd_StreamSafeCdSync(0);
    return o->bufSize;
}
#pragma pop /* merge_units */
/* merge_units: end func_00368F60 */

/* merge_units: begin func_00369050 */
#pragma push /* merge_units */
extern int sprintf(char*, const char*, ...);
extern char Libc_Toupper(int);                     /* toupper */
extern int sceCdDiskReady(int);                      /* disk ready: 2 when ready */
extern int snd_StreamSafeCdSearchFile(FileHalCdInfo*, char*);    /* snd_StreamSafeCdSearchFile */
/* Look up "\NAME;1" on the disc; returns 1 when found. */
int cFileIO_OpenFile(FileHalFile* f, char* name, int mode) {
    int i, r;
    f->mode = mode;
    f->buf = 0;
    f->bufSize = 0;
    f->size = 0;
    sprintf(f->path, "\\%s;1", name);
    for (i = 0; f->path[i]; i++) f->path[i] = Libc_Toupper(f->path[i]);
    i = 0;
    r = 0;
    while (i++ < 0xFF && r != 2) r = sceCdDiskReady(0);
    f->handle = snd_StreamSafeCdSearchFile(&f->info, f->path);
    f->size = f->info.size;
    if (!f->handle) f->handle = -1;
    if (f->handle < 0) {
        f->size = 0;
        return 0;
    }
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00369050 */

/* merge_units: begin func_00369160 */
#pragma push /* merge_units */
char D_004BBDE8[] = "CD Timeout";
char D_004BBDF8[] __attribute__((aligned(8))) = "%s\n"; /* 8-aligned in the original data */
char D_004BBE00[] = "CD ERROR: 0%x";
extern int snd_StreamSafeCdGetError(void);                     /* snd_StreamSafeCdGetError */
extern void snd_StreamSafeCdBreak(void);                    /* snd_StreamSafeCdBreak */
extern int sprintf(char* buf, const char* fmt, ...);
extern void printf(char* tag, char* msg);
/* Poll the current read: 1 done, 0 still busy, -1 error or timeout (read aborted). */
int cFileIO_IsReadDone(FileHalFile* o)
{
    char msg2[128];
    char msg1[128];
    int r = 1;
    int err = snd_StreamSafeCdGetError();
    int busy = snd_StreamSafeCdSync(r);
    o->pollFrame = g_FrameCounter;
    if (busy) {
        if (g_FrameCounter - o->startFrame > o->timeoutFrames) {
            sprintf(msg2, D_004BBDE8);
            printf(D_004BBDF8, msg2);
            r = -1;
        } else {
            r = 0;
        }
    } else if (err) {
        sprintf(msg1, D_004BBE00, err);
        printf(D_004BBDF8, msg1);
        r = -1;
    }
    if (r == -1) {
        snd_StreamSafeCdBreak();
        snd_StreamSafeCdSync(0);
    }
    if (r) g_CdReadStatus = 0;
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_00369160 */

/* merge_units: begin func_00369270 */
#pragma push /* merge_units */
#pragma inline_depth(8)
#pragma opt_propagation off
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
void* cMemMan_Allocate(int, int, char*, int);
void cMemMan_Deallocate(int, void*, char*, int);
extern char D_004BBDD0[];                           /* "FileHalPS2.cc" */
}

/* 128-bit copy when everything is 16-byte aligned, else bytewise. */
static inline void FileHal_Copy(void* d0, void* s0, int n0)
{
    int n = n0;
    __int128 u;
    int t;
    void* d = d0;
    void* s = s0;
    asm {
        .set noreorder
        blez n, done
        andi t, s, 0xF
        andi u, d, 0xF
        or t, t, u
        andi u, n, 0xF
        or t, t, u
        nop
        bgtz t, bytes
    quads:
        lq u, 0(s)
        addiu d, d, 0x10
        addi n, n, -0x10
        addiu s, s, 0x10
        bgtz n, quads
        sq u, -0x10(d)
        b done
        nop
    bytes:
        lb u, 0(s)
        addiu d, d, 1
        addi n, n, -1
        addiu s, s, 1
        bgtz n, bytes
        sb u, -1(d)
        .set reorder
    done:
    }
}

static inline int RoundUpToSector(int n)
{
    if (n % CD_SECTOR_SIZE == 0)
        return n;
    n = (n / CD_SECTOR_SIZE) * CD_SECTOR_SIZE + CD_SECTOR_SIZE;
    asm { .set reorder }
    return n;
}

/*
 * Reads that are not a whole number of sectors go through a temporary
 * sector-rounded buffer (unless the file is in direct mode).
 */
static inline int FileHal_ReadInline(FileHalFile* o, void* dst, int size, int pos)
{
    int ret = 0;
    int r;
    if (!o->size)
        return ret;
    r = RoundUpToSector(size);
    if (size < r && o->mode != FILEHAL_MODE_DIRECT) {
        void* p;
        o->bufSize = r;
        {
            int n = o->bufSize;
            AllocGuard g;
            p = cMemMan_Allocate(0, n, D_004BBDD0, 0xAA);
        }
        o->buf = p;
        ret = cFileIO_ReadFile(o, pos);
        if (ret) {
            FileHal_Copy(dst, o->buf, size);
            ret = size;
        }
        {
            void* q = o->buf;
            AllocGuard g;
            cMemMan_Deallocate(0, q, D_004BBDD0, 0xB3);
        }
        o->bufSize = 0;
    } else {
        o->bufSize = size;
        o->buf = dst;
        ret = cFileIO_ReadFile(o, pos);
    }
    return ret;
}

/* Read size bytes at pos into dst. */
extern "C" int cFileIO_Read_charP_int_int(FileHalFile* o, void* dst, int size, int pos)
{
    int ret = FileHal_ReadInline(o, dst, size, pos);
    o->ownsBuf = 0;
    return ret;
}
#pragma pop /* merge_units */
/* merge_units: end func_00369270 */

/* merge_units: begin func_003694D0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" int cFileIO_Read_void(FileHalFile* o);
/* Allocate a buffer for the whole file (rounded up to a sector) and start reading it. */
int cFileIO_Read_void(FileHalFile* o)
{
    void* p;
    int cap;
    if (o->size != 0) {
        o->bufSize = o->size / CD_SECTOR_SIZE * CD_SECTOR_SIZE + CD_SECTOR_SIZE;
        cap = o->bufSize;
        {
            AllocGuard guard;
            p = cMemMan_Allocate(0, cap, D_004BBDD0, 0x87);
        }
        o->buf = p;
        o->ownsBuf = 1;
        return cFileIO_ReadFile(o, 0);
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003694D0 */

/* merge_units: begin func_003695C0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
void cMemMan_Deallocate(int pool, void* p, char* file, int line);

void operator_delete(void* p);
}
/* Abort any read, free an owned buffer and reset to the closed state. */
static inline void FileHal_CloseInline(FileHalFile* s)
{
    if (s->handle >= 0) {
        snd_StreamSafeCdBreak(); /* sceCdBreak takes no arguments (block cFileIO_IsReadDone declares it) */
        if (s->ownsBuf) {
            void* p = s->buf;
            if (p) {
                {
                    AllocGuard g;
                    cMemMan_Deallocate(0, p, D_004BBDD0, 0x1DD);
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
extern "C" void cFileIO_Close(FileHalFile* s)
{
    FileHal_CloseInline(s);
}
#pragma pop /* merge_units */
/* merge_units: end func_003695C0 */

/* merge_units: begin func_003696B0 */
#pragma push /* merge_units */
int cFileIO_OpenFile(FileHalFile* f, char* name, int mode);

/* Open name unless already open (then only the mode changes); returns 1 on success. */
int cFileIO_Open(FileHalFile* f, char* name, int mode) {
    int ret;
    int closed;

    /* the goto shape reproduces the original's unoptimised branch layout */
    ret = f->handle;
    closed = ret < 0;
    if (closed) goto open;
    f->mode = mode;
    goto already_open;
open:;
    ret = cFileIO_OpenFile(f, name, mode);
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
extern "C" FileHalFile* cFileIO_dtor(FileHalFile* self, short del)
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
/* Construct a closed handle, then open name with mode. */
FileHalFile* cFileIO_ctor_charP_int(FileHalFile* file, char* name, int mode) {
    file->handle = -1;
    file->mode = 0;
    file->buf = 0;
    file->path[0] = 0;
    file->ownsBuf = 0;
    file->bufSize = 0;
    cFileIO_OpenFile(file, name, mode);
    return file;
}

/* Default constructor: closed handle with cleared state. */
FileHalFile* cFileIO_ctor_void(FileHalFile* file) {
    file->handle = -1;
    file->mode = 0;
    file->buf = 0;
    file->path[0] = 0;
    file->ownsBuf = 0;
    file->bufSize = 0;
    return file;
}

/* snd_StreamSafeCdCallback hook: records the completion reason. */
void CdCallback(int reason) {
    g_CdReadStatus = reason;
}
#pragma pop /* merge_units */
/* merge_units: end func_00369820 */

/* merge_units: begin func_003698B0 */
#pragma push /* merge_units */
long long SoftFloat_FloatToDouble(float f);
int SoftFloat_DoubleSub(int a, long long b);
long long SoftFloat_DoubleMultiply(long long a, long long b);
int SoftFloat_IntToDouble(int v);
long long SoftFloat_DoubleToInt(int v);
extern int D_00572538;

/* Soft-float double helper chain on D_00572538 (constant 0x3FB0000000000000 = 0.0625). */
long long cTimer_GetMillisecondTime(void) {
    int v = D_00572538;
    int n = SoftFloat_IntToDouble(v);
    return (long long)(SoftFloat_DoubleToInt(SoftFloat_DoubleSub(n, SoftFloat_DoubleMultiply((long long)0x3FB00000 << 0x20, SoftFloat_FloatToDouble((float)v)))) << 0x20) >> 0x20;
}
#pragma pop /* merge_units */
/* merge_units: end func_003698B0 */

/* merge_units: begin func_00369920 */
#pragma push /* merge_units */
typedef struct Dev100 {
    char pad000[0x100];
    void* port; /* 0x100 */
} Dev100;

extern void sceVibSetActParam(void* port, int count, unsigned char* cmd, int len, unsigned char* data);

/* Sends command 3 with two data bytes built from the flags. */
void cJoyPad_SetVibration(Dev100* dev, int on, int mode) {
    unsigned char data[3];
    unsigned char cmd;
    cmd = 3;
    data[0] = (on != 0) + ((mode << 1) & 0xFE);
    data[1] = (mode & 0x80) != 0;
    sceVibSetActParam(dev->port, 1, &cmd, 2, data);
}
#pragma pop /* merge_units */
/* merge_units: end func_00369920 */
