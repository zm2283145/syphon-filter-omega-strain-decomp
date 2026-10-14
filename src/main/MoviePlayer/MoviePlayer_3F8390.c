/*
 * main/MoviePlayer: 2 files, 003F8390-003F8450
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
extern void func_003F7830(void* device);
extern void func_003F6030(void* obj);
extern void TerminateThread(int sema);
extern void DeleteThread(int sema);
extern void func_0010DD10(int channel);
extern void func_0010CE90(int channel, int handler);
extern void func_00103AC0(int arg);
extern void func_003F5D00(void* obj);
extern void func_003F6EB0(void* obj);
extern void func_003F78F0(void* part);
extern void func_003A6C60(void);
extern void func_00412320(void* obj);

/* Shuts the subsystem down: stops the device, releases semaphores and handlers, clears the DMA flag. */
void func_003F8390(Sys3F83* sys) {
    func_003F7830(sys->device);
    func_003F6030(D_0055C460);
    TerminateThread(sys->sema50);
    DeleteThread(sys->sema50);
    TerminateThread(sys->sema54);
    DeleteThread(sys->sema54);
    func_0010DD10(2);
    func_0010CE90(2, D_0055C530);
    func_00103AC0(0);
    func_003F5D00(D_0055C480);
    func_003F6EB0(D_0055C540);
    func_003F78F0(sys->part58);
    *(volatile unsigned int*)0x1000E000 &= ~2;
    func_003A6C60();
    func_00412320(D_00571CF0);
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
extern int D_005381F0;
extern unsigned char D_0055C740;
extern int D_00539248;
extern char D_004BE1D8[];
extern char D_0055C230[];
extern int D_00538200;
extern int D_00538204;
extern int D_0055C748;
extern int D_0055C750;
extern char D_004E9B70[];
extern void func_003F79F0(int a, int b, int c, int d);
extern void func_00382ED0(int a, int b, int c, int d);
extern int strlen(const char* s);
extern char* strncpy(char* d, const char* s, int n);
extern void String_Copy(char* d, const char* s);
extern void func_0036E310(Obj8450* o, char* path, void* p);
extern void func_0036E220(Obj8450* o, int f);
extern void func_00412600(void* a, Obj8450* o, int b);
extern void Alloc_Lock(int id);
extern int func_0010D050(void);
extern void ChangeThreadPriority(int tid, int prio);
extern void func_00103418(void* db, int psm, short w, short h, int ztest, int zpsm, int clear);
extern void FlushCache(int a);
extern void func_003F7840(int a);
extern void func_0010AF48(void);
extern void func_003F5D80(void* a, int b, int c, int d, int e, int f, int g, int h);
extern void func_003F6ED0(void* a, int b, int c, int d);
extern void func_003F5D60(void* a, int b, int c, void* d, int e);
extern void func_003F6040(void* a, unsigned int b, int c, int d);
extern int CreateThread(ThreadParam8450* tp);
extern void StartThread(int tid, void* arg);
#if 0 /* merge_units */
extern void func_00103AC0(void* f);
#endif /* merge_units */
#define func_00103AC0(a0) (func_00103AC0((int)(a0))) /* merge_units */

extern int func_0010CE70(int a, void* f, int b);
extern void func_0010DD78(int a);
extern int func_003F7950(void* a, void* b);
extern void func_003F7D90(void);
extern void func_003F7BD0(void);
extern void func_003F7F80(void);
extern void func_003F5A10(void);
extern void MoviePlayer_PresentVblank(void);
extern void func_003F7010(void);
void func_003F8450(Sys8450* s)
{
    char path[0x80];
    Obj8450 obj;
    ThreadParam8450 tp;
    int len;
    char* name;
    int n;
    D_0055C740 = (D_005381F0 & 4) != 0;
    func_003F79F0(0, 0, 0, 0x80);
    func_00382ED0(D_00539248, 0x2D0, 0x240, 0x20);
    name = s->name;
    len = strlen(name);
    strncpy(path, name, len);
    String_Copy(path + len - 3, D_004BE1D8);
    func_0036E310(&obj, path, s->part190);
    func_00412600(D_00571CF0, &obj, s->f22C);
    *(volatile int*)0x10003010 = 0;
    Alloc_Lock(5);
    ChangeThreadPriority(func_0010D050(), 5);
    if (D_0055C740) {
        func_00103418(D_0055C230, 0, D_00538200, D_00538204, 0, 0, 1);
    } else {
        func_00103418(D_0055C230, 0, D_00538200, D_00538204 / 2, 0, 0, 1);
    }
    FlushCache(0);
    *(volatile unsigned int*)0x1000E000 |= 3;
    *(volatile unsigned int*)0x1000E010 = 4;
    func_003F7840(s->f30);
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
    func_0010AF48();
    func_003F5D80(D_0055C480, s->f18, 0x1CA200, s->f38, s->f10, 0x100, s->f48, 0x200);
    func_003F6ED0(D_0055C540, s->f20, 0xC000, n);
    func_003F5D60(D_0055C480, 0, 0, func_003F7D90, s->f30);
    if (s->f236) {
        func_003F5D60(D_0055C480, (unsigned char)n, D_0055C750, func_003F7BD0, s->f30);
    }
    func_003F6040(D_0055C460, (s->f0 & 0x0FFFFFFF) | 0x20000000, s->f8, 2);
    tp.entry = func_003F7F80;
    tp.stack = s->f28;
    tp.stackSize = 0x800;
    tp.initPriority = 5;
    tp.gpReg = D_004E9B70;
    tp.option = 0;
    s->f54 = CreateThread(&tp);
    StartThread(s->f54, 0);
    tp.entry = func_003F5A10;
    tp.stack = s->f40;
    tp.stackSize = 0x4000;
    tp.initPriority = 5;
    tp.gpReg = D_004E9B70;
    tp.option = 0;
    s->f50 = CreateThread(&tp);
    StartThread(s->f50, D_0055C480);
    func_00103AC0(MoviePlayer_PresentVblank);
    D_0055C530 = func_0010CE70(2, func_003F7010, 0);
    func_0010DD78(2);
    if (!func_003F7950(s->part58, s->part190)) {
        s->f235 = 1;
    }
    s->f188 = s->f60;
    s->f18C = s->f60;
    s->f230 = 0;
    func_0036E220(&obj, -1);
}
#undef func_00103AC0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F8450 */
