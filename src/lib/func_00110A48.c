typedef struct { int src; int dest; int size; int attr; } DmaT;
typedef struct { int x0; int (*func)(int, int, int); int buf; int size; int x10; int x14; int x18; void *client; int pkt_addr; int rpc_number; int receive; int rsize; int rmode; unsigned int rid; } Srv;
typedef struct { int x0[4]; int rec_id; int x14; int rpc_id; void *client; int cid; } Rend;
extern char D_004E4780[];
extern void func_0010FB10(int, int);
extern int func_001161A0(void);
extern int func_001161F8(void);
extern Rend *func_0010FE80(void *, int);
extern Rend *func_0010FE50(void *);
extern int func_0010F948(unsigned int, void *, int, int, int, int);
extern unsigned int sceSifSetDma(DmaT *, int);
void func_00110A48(Srv *sd)
{
    DmaT dmat[2];
    Rend *rend;
    int rec;
    int index, sz = 0, id, i;

    rec = sd->func(sd->rpc_number, sd->buf, sd->size);
    if (rec)
        sz = sd->rsize;
    if (sd->size > 0)
        func_0010FB10(sd->buf, sd->size);
    if (sz > 0)
        func_0010FB10(rec, sz);
    func_001161A0();
    if (sd->rid & 4)
        rend = func_0010FE80(D_004E4780, sd->rid >> 16);
    else
        rend = func_0010FE50(D_004E4780);
    func_001161F8();
    rend->cid = 0x8000000A;
    rend->client = sd->client;
    if (sd->rmode) {
        while (!func_0010F948(0x80000008, rend, 0x40, rec, sd->receive, sz))
            ;
        return;
    }
    rend->rpc_id = 0;
    rend->rec_id = 0;
    index = 0;
    if (sz > 0) {
        dmat[index].src = rec;
        dmat[index].dest = sd->receive;
        dmat[index].size = sz;
        dmat[index].attr = 0;
        index++;
    }
    dmat[index].src = (int)rend;
    dmat[index].dest = sd->pkt_addr;
    dmat[index].size = 0x40;
    dmat[index].attr = 0;
    index++;
    do {
        id = sceSifSetDma(dmat, index);
        if (id == 0) {
            i = 0x100000; while (i--) ;
        }
    } while (id == 0);
}




