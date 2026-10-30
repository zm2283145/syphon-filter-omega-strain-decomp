typedef unsigned int u_int;
typedef unsigned long u_long;
typedef int u_long128 __attribute__((mode(TI)));

#define D_ENABLER ((volatile u_int *)0x1000F520)
#define D_ENABLEW ((volatile u_int *)0x1000F590)
#define D3_CHCR ((volatile u_int *)0x1000B000)
#define D3_MADR ((volatile u_int *)0x1000B010)
#define D3_QWC ((volatile u_int *)0x1000B020)
#define D4_CHCR ((volatile u_int *)0x1000B400)
#define D4_MADR ((volatile u_int *)0x1000B410)
#define D4_QWC ((volatile u_int *)0x1000B420)
#define D4_TADR ((volatile u_int *)0x1000B430)
#define IPU_CMD ((volatile u_int *)0x10002000)
#define IPU_CTRL ((volatile u_int *)0x10002010)

typedef struct {
    u_int d4madr;
    u_int d4tadr;
    u_int d4qwc;
    u_int d4chcr;
    u_int d3madr;
    u_int d3qwc;
    u_int d3chcr;
    u_int ipubp;
    u_int ipuctrl;
} sceIpuDmaEnv;

typedef struct TimeStamp TimeStamp;

typedef struct {
    u_long128 *data;
    u_long128 *tag;
    int n;
    int dmaStart;
    int dmaN;
    int readBytes;
    int buffSize;
    sceIpuDmaEnv env;
    int sema;
    int isActive;
    long totalBytes;
    TimeStamp *ts;
    int n_ts;
    int count_ts;
    int wt_ts;
} ViBuf;

extern void WaitSema(int sema);
extern void SignalSema(int sema);
extern void DIntr(void);
extern void EIntr(void);

#define VIBUF_ELM_SIZE 2048
#define DmaAddr(val) ((u_int)(val) & 0x0FFFFFFF)
#define IsInRegion(i, s, l, n) (!(0 > ((i) + (n) - (s)) % (n) || ((i) + (n) - (s)) % (n) >= (l)))

int viBufRestartDMA(ViBuf *f)
{
    int bp;
    u_int d4madr_next;
    u_int d4qwc_next;
    u_int d4tadr_next;
    u_int d4chcr_next;

    WaitSema(f->sema);
    bp = f->env.ipubp & 0x7F;
    d4madr_next = f->env.d4madr - ((((f->env.ipubp >> 16) & 0x3) + ((f->env.ipubp >> 8) & 0xF)) << 4);
    d4qwc_next = f->env.d4qwc + (((f->env.ipubp >> 16) & 0x3) + ((f->env.ipubp >> 8) & 0xF));
    d4tadr_next = f->env.d4tadr;
    d4chcr_next = f->env.d4chcr | 0x100;

    if (d4madr_next < (u_int)f->data) {
        int id;
        d4qwc_next = ((u_int)f->data - d4madr_next) >> 4;
        d4madr_next += f->n * VIBUF_ELM_SIZE;
        d4tadr_next = DmaAddr(f->tag);
        id = (f->env.d4madr == (u_int)f->data || f->env.d4madr == (u_int)f->data + f->n * VIBUF_ELM_SIZE) ? 0 : 3;
        d4chcr_next = (DmaAddr(f->env.d4chcr) | (id << 28)) | 0x100;
        if (!IsInRegion(0, f->dmaStart, f->dmaN, f->n)) {
            f->dmaStart = f->n - 1;
            f->dmaN++;
        }
    } else {
        int ptr;
        int ptr_next;
        if (f->env.d4madr == DmaAddr(f->tag + (f->n + 1)))
            ptr = 0;
        else
            ptr = (f->env.d4madr - (u_int)f->data) / VIBUF_ELM_SIZE;
        if (d4madr_next == DmaAddr(f->tag + (f->n + 1)))
            ptr_next = 0;
        else
            ptr_next = (d4madr_next - (u_int)f->data) / VIBUF_ELM_SIZE;
        if (ptr != ptr_next) {
            int id;
            d4tadr_next = DmaAddr(f->tag + ptr);
            d4qwc_next = ((u_int)f->data + ptr * VIBUF_ELM_SIZE - d4madr_next) >> 4;
            if ((u_int)f->data + (f->env.d4madr - (u_int)f->data) % (f->n * VIBUF_ELM_SIZE)
                == (u_int)f->data + ((f->dmaStart + f->dmaN) % f->n) * VIBUF_ELM_SIZE)
                id = 0;
            else
                id = 3;
            d4chcr_next = (DmaAddr(f->env.d4chcr) | (id << 28)) | 0x100;
            if (!IsInRegion(ptr_next, f->dmaStart, f->dmaN, f->n)) {
                f->dmaStart = ptr_next;
                f->dmaN++;
            }
        }
    }

    if (f->env.d3madr && f->env.d3qwc) {
        *D3_MADR = f->env.d3madr;
        *D3_QWC = f->env.d3qwc;
        {
            u_int val = f->env.d3chcr | 0x100;
            DIntr();
            *D_ENABLEW = *D_ENABLER | 0x10000;
            *D3_CHCR = val;
            *D_ENABLEW = *D_ENABLER & ~0x10000;
            EIntr();
        }
    }
    if (f->dmaN) {
        while ((int)*IPU_CTRL < 0)
            ;
        *IPU_CMD = bp;
        while ((int)*IPU_CTRL < 0)
            ;
    }
    *D4_MADR = d4madr_next;
    *D4_TADR = d4tadr_next;
    *D4_QWC = d4qwc_next;
    if (f->dmaN) {
        DIntr();
        *D_ENABLEW = *D_ENABLER | 0x10000;
        *D4_CHCR = d4chcr_next;
        *D_ENABLEW = *D_ENABLER & ~0x10000;
        EIntr();
    }
    *IPU_CTRL = f->env.ipuctrl;
    f->isActive = 1;
    SignalSema(f->sema);
    return 1;
}
