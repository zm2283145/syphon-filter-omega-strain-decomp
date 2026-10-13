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
int func_001037A8(int mode)
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
