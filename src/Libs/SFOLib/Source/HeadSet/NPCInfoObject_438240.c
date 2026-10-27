/*
 * main/NPCInfoObject: 4 files, 00438240-00438770
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00438240 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[8]; char* data; unsigned int len; unsigned int pos; } Buf_8240;
int cDME_GetTime(int);
int cNellyMoser_nmsAddBlockToBuffer(int, char*);
int NetGetMyClientIndex(int*, int);
extern int D_00494178;
extern int D_00497550;
extern int D_005721A8;
extern unsigned char g_IsMultiplayer;
extern unsigned char D_00582B88;
extern int D_00582D30;
void cHeadSet_AudioPlayCallback(Buf_8240* b)
{
    int t0 = cDME_GetTime(1);
    if (D_00582B88 && b && b->len) {
        unsigned int n;
        char* p = b->data;
        int a = D_00497550;
        n = 0;
        if (a == -1) a = D_005721A8;
        if (g_IsMultiplayer && D_00494178 == -1) NetGetMyClientIndex(&D_00494178, a);
        if (n < b->len) {
            do {
                int k = cNellyMoser_nmsAddBlockToBuffer(1, p + n);
                n += k;
                if (!k) break;
            } while (n < b->len);
        }
        b->pos = n;
    }
    D_00582D30 = cDME_GetTime(1) - t0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00438240 */

/* merge_units: begin func_00438340 */
#pragma push /* merge_units */
typedef struct { char pad[0x1C]; int f1C; } P_438340;
extern unsigned char D_005721C0;
extern unsigned char D_005721D0;
extern int D_00582CF0;
extern int D_00583868;
extern int D_00583870;
extern char D_004BFD20[];
extern unsigned char D_00497568;
extern int D_00497548;
extern unsigned char D_00582B90;
extern char sfo_free;
extern char Sfo_Malloc;
int NetCreateObject(int* key, int a, int b, int c, int d, int e, int f, int g, char* h, int i);
int NetGetObject(P_438340** out, int key);
int lgAudInit(void* a, void* b);
int lgAudEnumHint(int* hint);
unsigned char cHeadSet_DetectAndSetupUSB(void);

static inline int NetOk_438340(void) { return g_IsMultiplayer ? D_005721C0 : 1; }

unsigned char func_00438340(void)
{
    int hint;
    int key;
    P_438340* p;
    unsigned char ok = 1;
    if (NetOk_438340() && D_00582CF0 == 0) {
        int v = 0;
        if (D_005721D0) {
            if (!NetCreateObject(&key, 2, 4, 1000, 0, 0, 0, 0, D_004BFD20, D_00583868)) {
                D_00583870 = key;
                if (!NetGetObject(&p, key)) v = p->f1C;
            }
        }
        D_00582CF0 = v;
    }
    if (D_00497568) {
        D_00497568 = 0;
        D_00497548 = -1;
        D_00582B88 = 0;
        if (!lgAudInit(&Sfo_Malloc, &sfo_free)) D_00582B90 = 1;
    }
    if (D_00582B90) {
        lgAudEnumHint(&hint);
        if (hint == 1 || !D_00582B88) {
            if (!cHeadSet_DetectAndSetupUSB()) ok = 0;
        }
    }
    return ok;
}
#pragma pop /* merge_units */
/* merge_units: end func_00438340 */

/* merge_units: begin func_004384C0 */
#pragma push /* merge_units */
#include "net_local_id.h"
#pragma inline_depth(10)
typedef struct { int f0; int f4; } P_4384C0;
typedef struct {
    unsigned char a; unsigned char b; unsigned char c; unsigned char d; unsigned short e; unsigned short f;
    unsigned char g; unsigned char h; unsigned short i; unsigned short j;
} Cfg_4384C0;
#if 0 /* merge_units */
extern void* D_00583870;
#endif /* merge_units */
#define D_00583870 (*(void **)&D_00583870) /* merge_units */

extern unsigned char D_00582D28;
extern int D_00582D08;
extern unsigned char D_00583860;
extern char D_00582BA0[];
extern int D_00582CF8;
extern int D_00497558;
extern unsigned char D_00582D00;
extern int D_00582D18;
extern int D_00582D10;
#if 0 /* merge_units */
void NetGetObject(P_4384C0** out, void* s);
#endif /* merge_units */
#define NetGetObject(a0, a1) ((void)NetGetObject((P_438340 * *)(a0), (int)(a1))) /* merge_units */

void NetReleaseObjectPrivateOwnership(void* s);
int lgAudStopRecording(int h);
#if 0 /* merge_units */
int cDME_GetTime(int v);
#endif /* merge_units */
#define cDME_GetTime(a0) (cDME_GetTime((a0))) /* merge_units */

int lgAudEnumerate(int a, char* b);
int lgAudOpen(int a, Cfg_4384C0* c, int* h);
void lgAudSetPlaybackVolume(int h, int a, int b);
void lgAudSetRecordingVolume(int h, int a, int b);
void cNellyMoser_nmsCreate(void);
void lgAudStartPlayback(int h);
void lgAudStopPlayback(int h);
void lgAudClose(int h);
void NetStreamMediaQuitChannel(int a, int b);
void func_0042BF90(void);
void cNellyMoser_nmsDestroy(void);

static inline int Owner_4384C0(void)
{
    P_4384C0* p;
    NetGetObject(&p, D_00583870);
    return p ? p->f4 : -1;
}
static inline void Stop_4384C0(void)
{
    if (D_00582B88) {
        if (lgAudStopRecording(D_00497548) == 0x80000006) D_00582B88 = 0;
        D_00582D08 = cDME_GetTime(1) + 2000;
    }
}
static inline void Free_4384C0(int a, int b) { NetStreamMediaQuitChannel(a, b); }
static inline void Release_4384C0(void)
{
    int o = Owner_4384C0();
    if (o == NetLocalId()) {
        NetReleaseObjectPrivateOwnership(D_00583870);
        D_00582D28 = 1;
    }
    Stop_4384C0();
    D_00583860 = 0;
}

unsigned char cHeadSet_DetectAndSetupUSB(void)
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
            lgAudSetPlaybackVolume(D_00497548, 0, 0x58);
            lgAudSetRecordingVolume(D_00497548, 0, 0x15);
            cNellyMoser_nmsCreate();
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
        cNellyMoser_nmsDestroy();
        D_00582D18 = 0;
        D_00497548 = -1;
        D_00582D10 = 0;
    }
    return ok;
}
#undef D_00583870 /* merge_units */
#undef NetGetObject /* merge_units */
#undef cDME_GetTime /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004384C0 */

/* merge_units: begin func_00438770 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int func_00438340(void);
#endif /* merge_units */
#define func_00438340() ((int)func_00438340()) /* merge_units */

extern int NetStreamMediaJoinChannel(int, int);
extern int cDME_GetTime(int);
extern int cNellyMoser_nmsMultiDecode(void*);
extern void cHeadSet_AudioOutput(void*, int);
extern unsigned char D_00582D20;
extern char D_00494230[];
extern char D_00495710[];
extern char* D_00497560;

void cHeadSet_NextFrame(int force)
{
    char buf[0x140];
    int now;
    int acc;
    int n;

    if (!func_00438340()) return;
    if (!D_00582B88) return;
    if (!D_005721D0 && !force) return;
    if (!D_00582D00 && D_005721D0 && !force) {
        if (!NetStreamMediaJoinChannel(D_005721A8, 0)) D_00582D00 = 1;
        D_00497558 = 0;
        D_00497550 = D_005721A8;
    }
    if (!D_00582D00) return;
    now = cDME_GetTime(1);
    acc = D_00582D18 + (now - D_00582D10);
    if (acc < 20) return;
    D_00582D18 = acc % 20;
    n = acc / 20;
    if (n > 8) n = 1;
    if (n > 0) {
    do {
        int r;
        if ((r = cNellyMoser_nmsMultiDecode(buf)) > 0) {
            cHeadSet_AudioOutput(buf, r);
        } else if (D_00582D20) {
            int len = 0x200;
            if ((int)D_00494230 + 0x14DE - (int)D_00497560 < 0x200) len = (int)D_00494230 + 0x14DE - (int)D_00497560;
            cHeadSet_AudioOutput(D_00497560, len);
            D_00497560 += len;
            if (D_00497560 - D_00494230 >= 0x14DE) {
                D_00582D20 = 0;
                D_00497560 = D_00495710;
            }
        } else if (D_00582D28) {
            int len = 0x200;
            if ((int)D_00495710 + 0x1E2E - (int)D_00497560 < 0x200) len = (int)D_00495710 + 0x1E2E - (int)D_00497560;
            cHeadSet_AudioOutput(D_00497560, len);
            D_00497560 += len;
            if (D_00497560 - D_00495710 >= 0x1E2E) {
                D_00582D28 = 0;
                D_00497560 = D_00494230;
            }
        } else {
            break;
        }
    } while (--n > 0);
    }
    D_00582D10 = now;
}
#undef func_00438340 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00438770 */
