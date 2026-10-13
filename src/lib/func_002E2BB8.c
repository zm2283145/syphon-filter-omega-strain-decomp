typedef struct { int f0; int f4; int f8; } Q;
typedef struct { char pad[0x400]; int f400; } P;
extern unsigned int D_0048C450;
extern int D_00598404;
extern int D_005983E0;
extern int func_002E51B8(unsigned int, P **);
extern int func_002DD968(Q **, unsigned int);
extern void func_002DE950(int, unsigned int, int);
extern unsigned char func_002E6090(unsigned int);
extern int func_002DE880(int, unsigned int, int, int, int, void *);

/* weak never-linked stub: steers reorg delay-slot fill (bnel) */
int __attribute__((weak, section(".dtors_drop"))) func_002DE880(int a, unsigned int b, int c, int d, int e, void *f) { return 0; }
int func_002E2BB8(unsigned int id)
{
    struct { unsigned char st; short id; } msg2;
    struct { short id; } msg;
    Q *q;
    P *p;
    int r;

    q = 0;
    p = 0;
    if (id >= 0x1000) return 0x17;
    if (D_0048C450 >= 4) return 8;
    r = func_002E51B8(D_0048C450, &p);
    if (r) return r;
    if (p == 0) return 0;
    func_002DD968(&q, id);
    if (q == 0) return 8;
    if (q->f8 != p->f400) {
        if (q->f4 == -1) {
            msg.id = id;
            func_002DE880(0x50, D_0048C450, q->f8, D_00598404, 2, &msg);
        } else return 0xB;
    } else {
        if (q->f4 == -1) {
            q->f4 = q->f8;
            func_002DE950(q->f4, id, -2);
            msg2.id = id;
            msg2.st = func_002E6090(q->f4);
            func_002DE880(0x50, D_0048C450, -1, D_005983E0, 4, &msg2);
        } else return 0xB;
    }
    return 0;
}
