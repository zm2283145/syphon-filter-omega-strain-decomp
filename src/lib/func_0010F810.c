typedef struct { unsigned int psize : 8; unsigned int dsize : 24; void *dest; int cid; unsigned int opt; } CmdHdr;
typedef struct { unsigned int src; unsigned int dest; unsigned int size; unsigned int attr; } DmaT;
extern void *D_004E2D60;
extern void func_0010FB10(void *, int);
extern unsigned int func_0010D520(DmaT *, int);
extern unsigned int func_0010D530(DmaT *, int);
unsigned int func_0010F810(int cid, int mode, CmdHdr *pkt, int pktsize, void *src, void *dest, int size)
{
    DmaT dmat[2];
    int count;
    if (pktsize < 16 || pktsize > 112)
        return 0;
    count = 0;
    if (size > 0) {
        dmat[count].src = (unsigned int)src;
        dmat[count].dest = (unsigned int)dest;
        dmat[count].size = size;
        dmat[count].attr = 0;
        count++;
        pkt->dest = dest;
        pkt->dsize = size;
        if (mode & 4)
            func_0010FB10(src, size);
    } else {
        pkt->dest = 0;
        pkt->dsize = 0;
    }
    dmat[count].src = (unsigned int)pkt;
    dmat[count].dest = (unsigned int)D_004E2D60;
    dmat[count].size = pktsize;
    pkt->cid = cid;
    pkt->psize = pktsize;
    dmat[count].attr = 0x44;
    func_0010FB10(pkt, pktsize);
    count++;
    if (mode & 1)
        return func_0010D530(dmat, count);
    else
        return func_0010D520(dmat, count);
}



