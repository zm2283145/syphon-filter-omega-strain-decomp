/* viBufGetTs (Sony ezmpeg sample vibuf.c), mw38. Retail asm unit 2F45A0 starts with cAnimator_SetFrame (0x18 + 8 pad); viBufGetTs proper starts at 003F45C0. */
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
#define IPU_BP ((volatile u_int *)0x10002020)

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

typedef struct {
    long pts;
    long dts;
    int pos;
    int len;
} TimeStamp;

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

extern int WaitSema(int sema);
extern int SignalSema(int sema);

#define VIBUF_ELM_SIZE 2048
#define TS_NONE (-1)
#define min(a, b) ((a) < (b) ? (a) : (b))
#define DGET_IPU_BP() (*IPU_BP)

extern inline u_int IsPtsInRegion(int tgt, int pos, int len, int size)
{
    int tgt1 = (tgt + size - pos) % size;
    return tgt1 < len;
}

int viBufGetTs(ViBuf *f, TimeStamp *ts)
{
    u_int d4madr = *D4_MADR;
    u_int ipubp = DGET_IPU_BP();
    int bp;
    int fp;
    int ifc;
    u_int d4madr_next;
    u_int stop;
    int datasize;
    int isEnd = 0;
    int tscount;
    int wt;
    int i;

    WaitSema(f->sema);

    bp = f->env.ipubp & 0x7f;
    fp = (ipubp >> 16) & 0x3;
    ifc = (ipubp >> 8) & 0xf;
    d4madr_next = d4madr - ((fp + ifc) << 4);
    datasize =  VIBUF_ELM_SIZE * f->n;

    ts->pts = TS_NONE;
    ts->dts = TS_NONE;

    stop = (d4madr_next + (bp >> 3) + datasize - (u_int)f->data)
    							% datasize;

    tscount = f->count_ts;
    wt = f->wt_ts;

    for (i = 0; i < tscount && !isEnd; i++) {

	int rd = (wt - tscount + f->n_ts + i) % f->n_ts;

	if (IsPtsInRegion(stop,
		f->ts[rd].pos, f->ts[rd].len, datasize)) {

	    ts->pts = f->ts[rd].pts;
	    ts->dts = f->ts[rd].dts;
	    f->ts[rd].pts = TS_NONE;
	    f->ts[rd].dts = TS_NONE;

	    isEnd = 1;
	    f->count_ts -= min(1, f->count_ts);
	}
    }

    SignalSema(f->sema);

    return 1;
}

