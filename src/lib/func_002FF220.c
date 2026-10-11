typedef struct { char pad[0x68]; char q[4]; } C;
extern unsigned char D_004908EC;
extern int D_004908F8;
extern int func_002FE8B0(C *);
extern int func_002F58C8(void *, unsigned int *);
extern int NetConn_Drain(C *);
extern int func_002F5748(void *, int, int);
int func_002FF220(C *c, unsigned int sz)
{
    unsigned int x[1];
    void *q;
    int r;
    x[0] = 0;
    if (D_004908EC != 1) return 5;
    if (func_002FE8B0(c) != 1) return 2;
    q = c->q;
    if ((q != 0) != 1) return 2;
    if (func_002F58C8(q, x)) return 0x15;
    if (x[0] < sz) {
        r = NetConn_Drain(c);
        if (r) return r;
        if (func_002F5748(q, 1, D_004908F8)) return 0x15;
        if (func_002F58C8(q, x)) return 0x15;
        if (x[0] < sz) return 0x14;
    }
    return 0;
}

