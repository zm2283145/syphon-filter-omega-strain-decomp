/*
 * main/MoviePlayer: 4 files, 003F8390-003F8840
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003F8390 */
#pragma push /* merge_units */
#include "types.h"

typedef struct Sys3F83 {
    char pad00[0x30];
    void* device;      /* 0x30 */
    char pad34[0x1C];
    int sema50;        /* 0x50 */
    int sema54;        /* 0x54 */
    char part58[4];    /* 0x58 */
} Sys3F83;

extern char D_0055C460[];
extern char D_0055C480[];
extern char D_0055C540[];
extern char D_00571CF0[];
extern int D_0055C530;
extern void readBufDelete(void* device);
extern void voBufDelete(void* obj);
extern void TerminateThread(int sema);
extern void DeleteThread(int sema);
extern void DisableDmac(int channel);
extern void RemoveDmacHandler(int channel, int handler);
extern void sceGsSyncVCallback(int arg);
extern void videoDecDelete(void* obj);
extern void audioDecDelete(void* obj);
extern void strFileClose(void* part);
extern void snd_CloseMovieSound(void);
extern void SubtitleTrack_Destroy(void* obj);

/* Shuts the subsystem down: stops the device, releases semaphores and handlers, clears the DMA flag. */
void cMoviePlayer_Purge(Sys3F83* sys) {
    readBufDelete(sys->device);
    voBufDelete(D_0055C460);
    TerminateThread(sys->sema50);
    DeleteThread(sys->sema50);
    TerminateThread(sys->sema54);
    DeleteThread(sys->sema54);
    DisableDmac(2);
    RemoveDmacHandler(2, D_0055C530);
    sceGsSyncVCallback(0);
    videoDecDelete(D_0055C480);
    audioDecDelete(D_0055C540);
    strFileClose(sys->part58);
    *(volatile unsigned int*)0x1000E000 &= ~2;
    snd_CloseMovieSound();
    SubtitleTrack_Destroy(D_00571CF0);
}
#pragma pop /* merge_units */
/* merge_units: end func_003F8390 */

/* merge_units: begin func_003F8450 */
#pragma push /* merge_units */
typedef struct {
    int status;
    void* entry;
    void* stack;
    int stackSize;
    void* gpReg;
    int initPriority;
    int currentPriority;
    unsigned int attr;
    unsigned int option;
} ThreadParam8450;
typedef struct { char pad[0xA0]; } Obj8450;
typedef struct Sys8450 {
    unsigned int f0;
    int pad4;
    int f8;
    int padC;
    int f10;
    int pad14;
    int f18;
    int pad1C;
    int f20;
    int pad24;
    void* f28;
    int pad2C;
    int f30;
    int pad34;
    int f38;
    int pad3C;
    void* f40;
    int pad44;
    int f48;
    int pad4C;
    int f50;
    int f54;
    char part58[8];
    int f60;
    char pad64[0x188 - 0x64];
    int f188;
    int f18C;
    char part190[4];
    char name[0x22C - 0x194];
    int f22C;
    unsigned char f230;
    char pad231[4];
    unsigned char f235;
    unsigned char f236;
} Sys8450;
extern int g_Video;
extern unsigned char D_0055C740;
extern int g_TextureMgr;
extern char D_004BE1D8[];
extern char D_0055C230[];
extern int D_00538200;
extern int D_00538204;
extern int D_0055C748;
extern int D_0055C750;
extern char D_004E9B70[];
extern void ClearVram(int a, int b, int c, int d);
extern void cTexMan_AllocStaticVram(int a, int b, int c, int d);
extern int strlen(const char* s);
extern char* strncpy(char* d, const char* s, int n);
extern void String_Copy(char* d, const char* s);
extern void cFileMan_ctor_charP_cFileManR(Obj8450* o, char* path, void* p);
extern void FileMan_Release(Obj8450* o, int f);
extern void MovieSubtitles_Load(void* a, Obj8450* o, int b);
extern void Alloc_Lock(int id);
extern int GetThreadId(void);
extern void ChangeThreadPriority(int tid, int prio);
extern void sceGsSetDefDBuff(void* db, int psm, short w, short h, int ztest, int zpsm, int clear);
extern void FlushCache(int a);
extern void readBufCreate(int a);
extern void sceMpegInit(void);
extern void videoDecCreate(void* a, int b, int c, int d, int e, int f, int g, int h);
extern void func_003F6ED0(void* a, int b, int c, int d);
extern void videoDecSetStream(void* a, int b, int c, void* d, int e);
extern void voBufCreate(void* a, unsigned int b, int c, int d);
extern int CreateThread(ThreadParam8450* tp);
extern void StartThread(int tid, void* arg);
#if 0 /* merge_units */
extern void sceGsSyncVCallback(void* f);
#endif /* merge_units */
#define sceGsSyncVCallback(a0) (sceGsSyncVCallback((int)(a0))) /* merge_units */


extern int AddDmacHandler(int a, void* f, int b);
extern void EnableDmac(int a);
extern int strFileOpen(void* a, void* b);
extern void cMoviePlayer_VideoCallback(void);
extern void cMoviePlayer_PcmCallback(void);
extern void cMoviePlayer_DefMain(void);
extern void videoDecMain(void);
extern void MoviePlayer_PresentVblank(void);
extern void handler_endimage(void);
void MoviePlayer_Start(Sys8450* s)
{
    char path[0x80];
    Obj8450 obj;
    ThreadParam8450 tp;
    int len;
    char* name;
    int n;
    D_0055C740 = (g_Video & 4) != 0;
    ClearVram(0, 0, 0, 0x80);
    cTexMan_AllocStaticVram(g_TextureMgr, 0x2D0, 0x240, 0x20);
    name = s->name;
    len = strlen(name);
    strncpy(path, name, len);
    String_Copy(path + len - 3, D_004BE1D8);
    cFileMan_ctor_charP_cFileManR(&obj, path, s->part190);
    MovieSubtitles_Load(D_00571CF0, &obj, s->f22C);
    *(volatile int*)0x10003010 = 0;
    Alloc_Lock(5);
    ChangeThreadPriority(GetThreadId(), 5);
    if (D_0055C740) {
        sceGsSetDefDBuff(D_0055C230, 0, D_00538200, D_00538204, 0, 0, 1);
    } else {
        sceGsSetDefDBuff(D_0055C230, 0, D_00538200, D_00538204 / 2, 0, 0, 1);
    }
    FlushCache(0);
    *(volatile unsigned int*)0x1000E000 |= 3;
    *(volatile unsigned int*)0x1000E010 = 4;
    readBufCreate(s->f30);
    n = 2;
    switch (D_0055C748) {
    case 0:
        n = 2;
        break;
    case 1:
        n = 3;
        break;
    case 2:
        n = 4;
        break;
    }
    sceMpegInit();
    videoDecCreate(D_0055C480, s->f18, 0x1CA200, s->f38, s->f10, 0x100, s->f48, 0x200);
    func_003F6ED0(D_0055C540, s->f20, 0xC000, n);
    videoDecSetStream(D_0055C480, 0, 0, cMoviePlayer_VideoCallback, s->f30);
    if (s->f236) {
        videoDecSetStream(D_0055C480, (unsigned char)n, D_0055C750, cMoviePlayer_PcmCallback, s->f30);
    }
    voBufCreate(D_0055C460, (s->f0 & 0x0FFFFFFF) | 0x20000000, s->f8, 2);
    tp.entry = cMoviePlayer_DefMain;
    tp.stack = s->f28;
    tp.stackSize = 0x800;
    tp.initPriority = 5;
    tp.gpReg = D_004E9B70;
    tp.option = 0;
    s->f54 = CreateThread(&tp);
    StartThread(s->f54, 0);
    tp.entry = videoDecMain;
    tp.stack = s->f40;
    tp.stackSize = 0x4000;
    tp.initPriority = 5;
    tp.gpReg = D_004E9B70;
    tp.option = 0;
    s->f50 = CreateThread(&tp);
    StartThread(s->f50, D_0055C480);
    sceGsSyncVCallback(MoviePlayer_PresentVblank);
    D_0055C530 = AddDmacHandler(2, handler_endimage, 0);
    EnableDmac(2);
    if (!strFileOpen(s->part58, s->part190)) {
        s->f235 = 1;
    }
    s->f188 = s->f60;
    s->f18C = s->f60;
    s->f230 = 0;
    FileMan_Release(&obj, -1);
}
#undef sceGsSyncVCallback /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F8450 */

/* merge_units: begin func_003F8840 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
#include "movie_player.h"
extern "C" {
void Mem_Free(int heap, void* p, char* file, int line);
}
/* Mem_Free from heap 1 under the allocator lock; line is the MoviePlayer.cc source line. */
static inline void MovieFree(void* p, int line) { AllocGuard g; Mem_Free(1, p, "MoviePlayer.cc", line); }
/* Releases the ten work buffers allocated by MoviePlayer_AllocBuffers. */
extern "C" void MoviePlayer_FreeBuffers(MovieBuffers* self)
{
    MovieFree(self->buf[0].raw, 0x7E);
    MovieFree(self->buf[1].raw, 0x7F);
    MovieFree(self->buf[2].raw, 0x80);
    MovieFree(self->buf[3].raw, 0x82);
    MovieFree(self->buf[4].raw, 0x83);
    MovieFree(self->buf[5].raw, 0x85);
    MovieFree(self->buf[6].raw, 0x86);
    MovieFree(self->buf[7].raw, 0x87);
    MovieFree(self->buf[8].raw, 0x88);
    MovieFree(self->buf[9].raw, 0x89);
}
#pragma pop /* merge_units */
/* merge_units: end func_003F8840 */

/* merge_units: begin func_003F8D20 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern char MoviePlayer_srcFile[];
void* Mem_Alloc(int heap, int size, char* file, int line);
}
/* Mem_Alloc from heap 1 under the allocator lock; line is the MoviePlayer.cc source line. */
static inline char* MovieAlloc(int size, int line) { AllocGuard g; return (char*)Mem_Alloc(1, size, MoviePlayer_srcFile, line); }
/* Allocates the ten work buffers (64-byte aligned except the last). */
extern "C" void MoviePlayer_AllocBuffers(MovieBuffers* self)
{
    self->buf[0].raw = MovieAlloc(MOVIE_BUF_SIZE_0, 0x51);
    self->buf[0].aligned = MOVIE_ALIGN64(self->buf[0].raw);
    self->buf[1].raw = MovieAlloc(MOVIE_BUF_SIZE_1, 0x55);
    self->buf[1].aligned = MOVIE_ALIGN64(self->buf[1].raw);
    self->buf[2].raw = MovieAlloc(MOVIE_BUF_SIZE_2, 0x59);
    self->buf[2].aligned = MOVIE_ALIGN64(self->buf[2].raw);
    self->buf[3].raw = MovieAlloc(MOVIE_BUF_SIZE_3, 0x5E);
    self->buf[3].aligned = MOVIE_ALIGN64(self->buf[3].raw);
    self->buf[4].raw = MovieAlloc(MOVIE_BUF_SIZE_4, 0x62);
    self->buf[4].aligned = MOVIE_ALIGN64(self->buf[4].raw);
    self->buf[5].raw = MovieAlloc(MOVIE_BUF_SIZE_5, 0x67);
    self->buf[5].aligned = MOVIE_ALIGN64(self->buf[5].raw);
    self->buf[6].raw = MovieAlloc(MOVIE_BUF_SIZE_6, 0x6B);
    self->buf[6].aligned = MOVIE_ALIGN64(self->buf[6].raw);
    self->buf[7].raw = MovieAlloc(MOVIE_BUF_SIZE_7, 0x6F);
    self->buf[7].aligned = MOVIE_ALIGN64(self->buf[7].raw);
    self->buf[8].raw = MovieAlloc(MOVIE_BUF_SIZE_8, 0x73);
    self->buf[8].aligned = MOVIE_ALIGN64(self->buf[8].raw);
    self->buf[9].raw = MovieAlloc(MOVIE_BUF_SIZE_9, 0x77);
    self->buf[9].aligned = self->buf[9].raw;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F8D20 */
