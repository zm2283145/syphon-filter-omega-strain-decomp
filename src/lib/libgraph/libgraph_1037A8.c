/*
 * lib/libgraph: 5 files, 001037A8-00103C58
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001037A8 */
extern int scePrintf(const char *fmt, ...);

#define D1_CHCR   (*(volatile unsigned int *)0x10009000)
#define D2_CHCR   (*(volatile unsigned int *)0x1000A000)
#define VIF1_STAT (*(volatile unsigned int *)0x10003C00)
#define GIF_STAT  (*(volatile unsigned int *)0x10003020)

/* sceGsSyncPath (libgraph). Register dump reads are plain (non-volatile) loads through a
 * materialized address so they fill the printf delay slots; the empty asm emits no code. */
#define R(a) ({ register unsigned int *p_ asm("$2") = (unsigned int *)(a); __asm__("" : "=r"(p_) : "0"(p_)); *p_; })
#define MAX_CNT 0x1000000

static char D_00498178[] = "sceGsSyncPath: DMA Ch.1 does not terminate\r\n";
static char D_004981A8[] = "\t<D1_CHCR=%08x:";
static char D_004981B8[] = "D1_TADR=%08x:";
static char D_004981C8[] = "D1_MADR=%08x:";
static char D_004981D8[] = "D1_QWC=%08x>\r\n";
static char D_004981E8[] = "\t<D2_CHCR=%08x:";
static char D_004981F8[] = "D2_TADR=%08x:";
static char D_00498208[] = "D2_MADR=%08x:";
static char D_00498218[] = "D2_QWC=%08x>\r\n";
static char D_00498228[] = "\t<VIF1_STAT=%08x:";
static char D_00498240[] = "GIF_STAT=%08x>\r\n";
static char D_00498258[] = "sceGsSyncPath: DMA Ch.2 does not terminate\r\n";
static char D_00498288[] = "sceGsSyncPath: VIF1 does not terminate\r\n";
static char D_004982B8[] = "sceGsSyncPath: VU1 does not terminate\r\n";
static char D_004982E0[] = "sceGsSyncPath: GIF does not terminate\r\n";


/* VU1 status (vi29) has no C spelling; .set noreorder only suppresses gas's hazard nop. */
int sceGsSyncPath(int mode)
{
    unsigned int cnt = 0;
    register char *msg asm("$4");
    unsigned int vpu;

    if (mode == 0) {
        while (D1_CHCR & 0x100) {
            if (cnt++ > MAX_CNT)
                goto e1;
        }
        while (D2_CHCR & 0x100) {
            if (cnt++ > MAX_CNT)
                goto e2;
        }
        while (VIF1_STAT & 0x1F000003) {
            if (cnt++ > MAX_CNT)
                goto e3;
        }
        __asm__ volatile(".set noreorder\n\tcfc2.ni %0, $vi29\n\t.set reorder" : "=r"(vpu));
        if (vpu & 0x100) do {
            if (cnt++ > MAX_CNT)
                goto e4;
            __asm__ volatile(".set noreorder\n\tcfc2.ni %0, $vi29\n\t.set reorder" : "=r"(vpu));
        } while (vpu & 0x100);
        while (GIF_STAT & 0xC00) {
            if (cnt++ > MAX_CNT)
                goto e5;
        }
        return 0;
    e1:
        msg = D_00498178;
        goto err;
    e2:
        msg = D_00498258;
        goto err;
    e3:
        msg = D_00498288;
        goto err;
    e4:
        msg = D_004982B8;
        goto err;
    e5:
        msg = D_004982E0;
    err:
        scePrintf(msg);
        scePrintf(D_004981A8, R(0x10009000));
        scePrintf(D_004981B8, R(0x10009030));
        scePrintf(D_004981C8, R(0x10009010));
        scePrintf(D_004981D8, R(0x10009020));
        scePrintf(D_004981E8, R(0x1000A000));
        scePrintf(D_004981F8, R(0x1000A030));
        scePrintf(D_00498208, R(0x1000A010));
        scePrintf(D_00498218, R(0x1000A020));
        scePrintf(D_00498228, R(0x10003C00));
        scePrintf(D_00498240, R(0x10003020));
        return -1;
    } else {
        int ret = 0;
        if (D1_CHCR & 0x100) ret |= 1;
        if (D2_CHCR & 0x100) ret |= 2;
        if (VIF1_STAT & 0x1F000003) ret |= 4;
        __asm__ volatile(".set noreorder\n\tcfc2.ni %0, $vi29\n\t.set reorder" : "=r"(vpu));
        if (vpu & 0x100) ret |= 8;
        if (GIF_STAT & 0xC00) ret |= 0x10;
        return ret;
    }
}
/* merge_units: end func_001037A8 */

/* merge_units: begin func_00103AC0 */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);
int Alloc_Unlock(int);
int sceGsGetGParam();
int AddIntcHandler(int, int, int);
int RemoveIntcHandler(int, int);

int sceGsSyncVCallback(int arg0) {
    int temp_s2;
    int temp_s0;

    temp_s0 = sceGsGetGParam();
    temp_s2 = F_(temp_s0, 0x8, int);
    if (arg0 == 0) {
        Alloc_Lock(2);
        RemoveIntcHandler(2, F_(temp_s0, 0xC, int));
        F_(temp_s0, 0xC, int) = 0;
        F_(temp_s0, 0x8, int) = 0;
    } else {
        if (temp_s2 != 0) {
            Alloc_Lock(2);
            RemoveIntcHandler(2, F_(temp_s0, 0xC, int));
        }
        F_(temp_s0, 0x8, int) = arg0;
        F_(temp_s0, 0xC, int) = AddIntcHandler(2, arg0, -1);
        Alloc_Unlock(2);
    }
    return temp_s2;
}
/* merge_units: end func_00103AC0 */

/* merge_units: begin func_00103B60 */
typedef unsigned long u_long __attribute__((mode(DI)));
typedef long s_long __attribute__((mode(DI)));

typedef struct {
    u_long SCAX0:11; u_long pad11:5;
    u_long SCAX1:11; u_long pad27:5;
    u_long SCAY0:11; u_long pad43:5;
    u_long SCAY1:11; u_long pad59:5;
} sceGsScissor;

typedef struct {
    u_long frame1; u_long frame1addr;
    u_long zbuf1; u_long zbuf1addr;
    u_long xyoffset1; u_long xyoffset1addr;
    sceGsScissor scissor1; u_long scissor1addr;
} sceGsDrawEnv1;

void func_00103B60(sceGsDrawEnv1 *draw, short centerx, short centery, short halfoff)
{
    s_long ofy = ((s_long)centery - ((u_long)(int)(draw->scissor1.SCAY1 + 1) >> 1)) << 4;
    s_long ofx = ((s_long)centerx - ((u_long)(int)(draw->scissor1.SCAX1 + 1) >> 1)) << 4;
    if (halfoff)
        draw->xyoffset1 = (u_long)ofx | ((u_long)(ofy + 8) << 32);
    else
        draw->xyoffset1 = (u_long)ofx | ((u_long)ofy << 32);
}
/* merge_units: end func_00103B60 */

/* merge_units: begin func_00103BE8 */
typedef struct { volatile int chcr; } DmaChan3BE8;
extern int scePrintf(const char *, ...);
extern unsigned int func_00104380(DmaChan3BE8 *);

void sceDmaSync(DmaChan3BE8 *d)
{
    int cnt = 0x1000000;
    while (d->chcr & 0x100) {
        if (--cnt < 0) {
            scePrintf("libdma: sync timeout
");
            func_00104380(d);
        }
    }
}
/* merge_units: end func_00103BE8 */

/* merge_units: begin func_00103C58 */
typedef struct { volatile int chcr; int p0[3]; volatile unsigned int madr; } DmaChan3C58;
extern char D_00498308[];
#if 0 /* merge_units */
extern unsigned int func_00104380(DmaChan3C58 *);
#endif /* merge_units */
#define func_00104380(a0) (func_00104380((DmaChan3BE8 *)(a0))) /* merge_units */


void func_00103C58(DmaChan3C58 *d, unsigned int a, int n)
{
    int cnt = n ? n : 0x1000000;
    while (d->madr < a) {
        if (--cnt < 0) {
            scePrintf(D_00498308);
            func_00104380(d);
        }
    }
}
#undef func_00104380 /* merge_units */
/* merge_units: end func_00103C58 */
