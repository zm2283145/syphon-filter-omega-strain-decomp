/*
 * main/NPCInfoObject: 3 files, 00437BF0-00437F90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00437BF0 */
#pragma push /* merge_units */
#define LOCALID_(X) { int ld_a = D_005721A8; /* read before the flag test: retail loads it ahead of the branch */ if (g_IsMultiplayer) { if (D_00494178 == -1) NetGame_InitLocalSlot(&D_00494178, ld_a); X = D_00494178; } else X = 0; }
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int NetGetObject(void **, int);
int NetGame_InitLocalSlot(int *, int);
int NetReleaseObjectPrivateOwnership(int);
int NetStreamMediaQuitChannel(int, int);
int lgAudStopRecording(int);
int Net_GetClock(int);
int func_0042BF90();
int cNellyMoser_nmsDestroy();
int lgAudClose(int);
int lgAudStopPlayback(int);
extern int D_00494178;
extern int D_00497548;
unsigned int D_00497550[2] = { 0xFFFFFFFF, 0x0 };
unsigned int D_00497558[2] = { 0xFFFFFFFF, 0x0 };
extern int D_005721A8;
extern unsigned char g_IsMultiplayer;
extern unsigned char D_00582B88;
extern signed char D_00582D00;
extern int D_00582D08;
extern int D_00582D10;
extern int D_00582D18;
extern signed char D_00582D28;
extern signed char D_00583860;
extern int D_00583870;

void cHeadSet_ShutdownAudio(void) {
    int sp2C;
    int var_s0;
    int var_v0;

    if (D_00582B88 != 0) {
        NetGetObject(&sp2C, D_00583870);
        var_s0 = -1;
        if (sp2C != NULL) {
            var_s0 = F_(sp2C, 0x4, int);
        }
        LOCALID_(var_v0)
        if (var_s0 == var_v0) {
            NetReleaseObjectPrivateOwnership(D_00583870);
            D_00582D28 = 1;
        }
        if (D_00582B88 != 0) {
            if (lgAudStopRecording(D_00497548) == 0x80000006) {
                D_00582B88 = 0;
            }
            D_00582D08 = Net_GetClock(1) + 0x7D0;
        }
        D_00583860 = 0;
        if (D_00582B88 != 0) {
            if (lgAudStopRecording(D_00497548) == 0x80000006) {
                D_00582B88 = 0;
            }
            D_00582D08 = Net_GetClock(1) + 0x7D0;
        }
        lgAudStopPlayback(D_00497548);
        D_00582B88 = 0;
        lgAudClose(D_00497548);
        NetStreamMediaQuitChannel((*(int*)D_00497550), *(volatile int*)&(*(int*)D_00497558));
        D_00582D00 = 0;
        (*(int*)D_00497550) = -1;
        (*(int*)D_00497558) = -1;
        func_0042BF90();
        cNellyMoser_nmsDestroy();
        D_00582D18 = 0;
        D_00497548 = -1;
        D_00582D10 = 0;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00437BF0 */

/* merge_units: begin func_00437DB0 */
#pragma push /* merge_units */
#include "types.h"

extern char D_00583060[];
extern int lgAudWrite(int h, int mode, void* buf, int* len);

static inline void Copy_7DB0(void* d0, void* s0, int n0)
{
    int n = n0;
    int t;
    int m;
    void* d = d0;
    void* s = s0;
    asm {
        .set noreorder
        blez n, done
        andi m, s, 0xF
        andi t, d, 0xF
        or m, m, t
        andi t, n, 0xF
        or m, m, t
        nop
        bgtz m, bytes
        nop
    quads:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -0x10
        addiu s, s, 0x10
        bgtz n, quads
        sq t, -0x10(d)
        b done
        nop
    bytes:
        lb t, 0(s)
        addiu d, d, 1
        addi n, n, -1
        addiu s, s, 1
        bgtz n, bytes
        sb t, -1(d)
    done:
        .set reorder
    }
}

static inline int Samples_7DB0(int l, int b) { return l / b; }
#pragma opt_propagation off
int cHeadSet_AudioOutput(char* src, int count)
{
    int total = 0;
    int len = 0;
    int bps = 2;
    while (count > 0) {
        char* s;
        char* d;
        int i;
        len = count;
        if (0x400 / bps < len)
            len = 0x400 / bps;
        s = src;
        d = D_00583060;
        for (i = 0; i < len; i++) {
            Copy_7DB0(d, s, bps);
            Copy_7DB0(d + bps, s, bps);
            s += bps;
            d += bps * 2;
        }
        len = len * 2;
        lgAudWrite(D_00497548, 1, D_00583060, &len);
        if (len <= 0)
            break;
        {
            int q = Samples_7DB0(len, bps);
            src += q;
            total += q;
        }
        count -= len / bps;
    }
    return total;
}
#pragma opt_propagation reset
#pragma pop /* merge_units */
/* merge_units: end func_00437DB0 */

/* merge_units: begin func_00437F90 */
#pragma push /* merge_units */
#include "net_local_id.h"
#pragma inline_depth(10)
#pragma opt_rebuildconditionals off
typedef struct { int f0; int f4; } P_437F90;
typedef struct { int f0; char* buf; int f8; int len; } Pkt_437F90;
extern unsigned char D_00497540;
extern int D_00582CF8;
#if 0 /* merge_units */
extern void* D_00583870;
#endif /* merge_units */
#define D_00583870 (*(void **)&D_00583870) /* merge_units */

#if 0 /* merge_units */
extern unsigned char D_00583860;
#endif /* merge_units */
#define D_00583860 (*(unsigned char*)&D_00583860) /* merge_units */

extern int D_00582D48;
extern int D_00582D40;
extern int D_00582D38;
extern char D_00582D50[];
extern char D_00582E90[];
#if 0 /* merge_units */
void NetGetObject(P_437F90** out, void* s);
#endif /* merge_units */
#define NetGetObject(a0, a1) ((void)NetGetObject((void * *)(a0), (int)(a1))) /* merge_units */

#if 0 /* merge_units */
int Net_GetClock(int v);
#endif /* merge_units */
#define Net_GetClock(a0) (Net_GetClock((a0))) /* merge_units */

int lgAudRead(int h, int mode, void* buf, int* len);
int cNellyMoser_nmsEncode(char* in, char* out, char* flag);

static inline int LocalIdX_7F90(void)
{
    int r = 0;
    int a = D_005721A8;
    if (g_IsMultiplayer) {
        if (D_00494178 == -1) NetGame_InitLocalSlot(&D_00494178, a);
        r = D_00494178;
    } else { asm { .set reorder } } /* scheduling barrier: keeps the empty else block (b + nop) */
    return r;
}
static inline void Copy_7F90(void* d0, void* s0, int n0)
{
    int n = n0;
    int t;
    int m;
    void* d = d0;
    void* s = s0;
    asm {
        .set noreorder
        blez n, done
        andi m, s, 0xF
        andi t, d, 0xF
        or m, m, t
        andi t, n, 0xF
        or m, m, t
        nop
        bgtz m, bytes
    quads:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -0x10
        addiu s, s, 0x10
        bgtz n, quads
        sq t, -0x10(d)
        b done
        nop
    bytes:
        lb t, 0(s)
        addiu d, d, 1
        addi n, n, -1
        addiu s, s, 1
        bgtz n, bytes
        sb t, -1(d)
    done:
        .set reorder
    }
}

static inline int Owner_437F90(void)
{
    P_437F90* p;
    NetGetObject(&p, D_00583870);
    return p ? p->f4 : -1;
}


void cHeadSet_AudioRecordCallback(Pkt_437F90* pkt)
{
    char flag;
    int len;
    int t0 = Net_GetClock(1);
    if (pkt && D_00582B88 && D_00497540) {
        char* dst;
        unsigned char t;
        pkt->len = 0;
        pkt->f0 = D_00582CF8;
        t = Owner_437F90() == LocalIdX_7F90();
        if (!t) t = D_00583860;
        if (!t) {
            D_00582D48 = 0;
            D_00582D40 = 0;
            return;
        }
        dst = pkt->buf;
        do {
            if (D_00582D48 < 0x140) {
                int n;
                char* b;
                len = 0;
                n = 0x140 - D_00582D48;
                b = D_00582D50 + D_00582D48;
                if (n > 0 && b) {
                    int r;
                    len = n;
                    r = lgAudRead(D_00497548, 1, b, (int*)&len);
                    if (r) {
                        len = 0;
                        if (r == 0x80000006) D_00582B88 = 0;
                    }
                }
                D_00582D48 = D_00582D48 + (int)len;
            }
            if (D_00582D48 < 0x140) {
                D_00582D38 = Net_GetClock(1) - t0;
                return;
            }
            {
                int k = cNellyMoser_nmsEncode(D_00582D50, D_00582E90 + D_00582D40, &flag);
                D_00582D48 = 0;
                D_00582D40 += k;
            }
        } while (D_00582D40 < 0xC0);
        Copy_7F90(dst, D_00582E90, 0xC0);
        pkt->len = D_00582D40;
        D_00582D40 = 0;
    }
    D_00582D38 = Net_GetClock(1) - t0;
}
#undef D_00583870 /* merge_units */
#undef D_00583860 /* merge_units */
#undef NetGetObject /* merge_units */
#undef Net_GetClock /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00437F90 */
