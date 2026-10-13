#include "types.h"
#include "net_local_id.h"
#pragma inline_depth(10)
typedef struct { int f0; int f4; } P_4384C0;
typedef struct {
    unsigned char a; unsigned char b; unsigned char c; unsigned char d; unsigned short e; unsigned short f;
    unsigned char g; unsigned char h; unsigned short i; unsigned short j;
} Cfg_4384C0;
extern unsigned char D_00582B88;
extern void* D_00583870;
extern unsigned char D_00582D28;
extern int D_00497548;
extern int D_00582D08;
extern unsigned char D_00583860;
extern char D_00582BA0[];
extern int D_00582CF8;
extern int D_00497550;
extern int D_00497558;
extern unsigned char D_00582D00;
extern int D_00582D18;
extern int D_00582D10;
void func_002EB650(P_4384C0** out, void* s);
void func_002EC460(void* s);
int lgAudStopRecording(int h);
int func_0042B1A0(int v);
int lgAudEnumerate(int a, char* b);
int lgAudOpen(int a, Cfg_4384C0* c, int* h);
void lgAudSetLevel0D(int h, int a, int b);
void lgAudSetLevel0E(int h, int a, int b);
void func_0042C1E0(void);
void lgAudStartPlayback(int h);
void lgAudStopPlayback(int h);
void lgAudClose(int h);
void func_002EC878(int a, int b);
void func_0042BF90(void);
void func_0042C1D0(void);

static inline int Owner_4384C0(void)
{
    P_4384C0* p;
    func_002EB650(&p, D_00583870);
    return p ? p->f4 : -1;
}
static inline void Stop_4384C0(void)
{
    if (D_00582B88) {
        if (lgAudStopRecording(D_00497548) == 0x80000006) D_00582B88 = 0;
        D_00582D08 = func_0042B1A0(1) + 2000;
    }
}
static inline void Free_4384C0(int a, int b) { func_002EC878(a, b); }
static inline void Release_4384C0(void)
{
    int o = Owner_4384C0();
    if (o == NetLocalId()) {
        func_002EC460(D_00583870);
        D_00582D28 = 1;
    }
    Stop_4384C0();
    D_00583860 = 0;
}

unsigned char func_004384C0(void)
{
    unsigned char ok = 0;
    if (lgAudEnumerate(0, D_00582BA0) == 0) {
        Cfg_4384C0 c;
        c.g = 2;
        c.a = 3;
        c.j = 400;
        c.h = 0x10;
        c.i = 8000;
        c.c = 1;
        c.d = 0x10;
        c.f = 200;
        c.e = 8000;
        if (lgAudOpen(0, &c, &D_00497548) == 0) {
            lgAudSetLevel0D(D_00497548, 0, 0x58);
            lgAudSetLevel0E(D_00497548, 0, 0x15);
            func_0042C1E0();
            if (D_00582B88) lgAudStartPlayback(D_00497548);
            D_00582B88 = 1;
            ok = 1;
            D_00582CF8 = 1;
        }
    } else if (D_00582B88) {
        Release_4384C0();
        Stop_4384C0();
        lgAudStopPlayback(D_00497548);
        D_00582B88 = 0;
        lgAudClose(D_00497548);
        Free_4384C0(D_00497550, *(volatile int*)&D_00497558);
        D_00582D00 = 0;
        D_00497550 = -1;
        D_00497558 = -1;
        func_0042BF90();
        func_0042C1D0();
        D_00582D18 = 0;
        D_00497548 = -1;
        D_00582D10 = 0;
    }
    return ok;
}