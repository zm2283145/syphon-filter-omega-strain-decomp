typedef struct { int f0; char pad4[0x18]; char f1C[0x18]; char f34[0x5C]; } RtPeer;
typedef struct {
    int f0; RtPeer *peers; int f8; char q[0x20]; int npeers; int f30; int f34; int f38; int f3C; int f40;
    short f44; unsigned short port; int f48; int f4C; int f50;
} RtUdp;
extern void func_0030B220(RtUdp *r);
extern int func_002FA550(void *q);
extern void func_002FB3C0(void *pp);
int func_00306F98(RtUdp *arg)
{
    RtUdp *r = 0;
    unsigned int i = 0;
    if (arg == 0) return 2;
    r = arg;
    if (r->f0 != 0) func_0030B220(r);
    if (r->peers != 0) {
        for (i = 0; i < r->npeers; i++) {
            if (r->peers[i].f0 != 0) {
                func_002FA550(r->peers[i].f1C);
                func_002FA550(r->peers[i].f34);
                r->peers[i].f0 = 0;
            }
        }
        func_002FB3C0(&r->peers);
    }
    func_002FA550(r->q);
    func_002FB3C0(&r);
    return 0;
}

