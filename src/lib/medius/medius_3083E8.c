typedef struct { int state; char pad04[0x18]; char sub[0x58]; int f74; char pad78[0x18]; } RtPeer;
typedef struct { int f0; RtPeer *peers; } RtUdp;
typedef struct { int a; int b; int pad[2]; } RtInfo;
extern int func_003076E0(RtUdp *h, void *a, int *out);
extern int func_002FABD0(char *o, int *out);
extern int func_00308F58(int s, RtInfo *i);
extern int func_00308FB8(int s, RtInfo *i);
int func_003083E8(RtUdp *h, void *a, int *out)
{
    int s = 0;
    RtInfo info;
    RtPeer *p;
    int r;
    if (out == 0) return 1;
    *out = -1;
    if (h == 0) return 2;
    if (a == 0) return 1;
    r = func_003076E0(h, a, out);
    if (r != 0) return r;
    p = &h->peers[*out];
    p->f74 = 0;
    if (func_002FABD0(p->sub, &s) != 0) {
        p->state = 6;
        return 10;
    }
    if (func_00308F58(s, &info) != 0) {
        p->state = 6;
        return 11;
    }
    info.b = 0;
    if (func_00308FB8(s, &info) != 0) {
        p->state = 6;
        return 11;
    }
    return 0;
}
