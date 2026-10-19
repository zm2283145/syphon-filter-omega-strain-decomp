/* libmpeg: motion-compensation reference fetch (the tag-building tail of _motionComp0 in the SDK 2.2 mpc.c,
   split into its own function in this SDK). Builds the SPR-to DMA chain in uncached D_004E1E00 and kicks ch.9.
   i is pinned to t3: the source order otherwise gives tag t3 / i t2 (global-alloc priority). */
typedef struct {
    int refBuf;
    int pad4;
    int srcAddr[2][4];
    char pad28[0x12C - 0x28];
    int count;
    char pad130[0x140 - 0x130];
} MCRec;

typedef struct {
    char pad0[0x5A8];
    MCRec rec[2];
    char pad828[0x828 - 0x5A8 - 0x280];
    int cur;
} Mpeg9590;

extern char D_004E1E00[];
extern int DIntr(void);
extern void EIntr(void);

#define D9_CHCR ((volatile unsigned int *)0x1000D400)
#define D9_QWC  ((volatile unsigned int *)0x1000D420)
#define D9_TADR ((volatile unsigned int *)0x1000D430)
#define D9_SADR ((volatile unsigned int *)0x1000D480)

void func_00109590(Mpeg9590 *mp)
{
    long *tag;
    int cnt;
    register int i asm("$11");
    int s;

    tag = (long *)(((unsigned int)D_004E1E00 & 0x0FFFFFFF) | 0x20000000);
    cnt = mp->rec[mp->cur].count;
    for (i = 0; i < cnt; i++) {
        int id;
        long b;
        tag[0] = ((long)(mp->rec[mp->cur].srcAddr[0][i] & 0x0FFFFFFF) << 32) | (3 << 28) | 0x30;
        b = (long)(mp->rec[mp->cur].srcAddr[1][i] & 0x0FFFFFFF) << 32;
        id = i == cnt - 1 ? 0 : 3;
        tag[2] = b | ((long)id << 28) | 0x30;
        tag += 4;
    }
    s = DIntr();
    asm volatile("sync");
    *D9_SADR = mp->rec[mp->cur].refBuf;
    *D9_TADR = (unsigned int)D_004E1E00;
    *D9_QWC = 0;
    *D9_CHCR = 0x105;
    if (s) EIntr();
}