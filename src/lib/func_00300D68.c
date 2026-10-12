typedef struct {
    int type;
    char pad4;
    unsigned char ready;
    char pad6[2];
    char addr[0x10];
    unsigned short port;
    char pad1a[2];
    int h;
    char pad20[8];
    char f28[0x28];
    char q[4];
} R;
extern unsigned char D_004908EC;
extern int func_002FE8B0(void);
extern int func_002F5748(void *, int, int);
extern int func_002F58C8(void *, unsigned int *);
extern int func_002F5988(void *, unsigned char **);
extern int func_002F6090(int, unsigned char *, unsigned short, unsigned short *);
extern int func_002F61A0(int, char *, unsigned short *, unsigned char *, int, unsigned short *);
extern int func_003010C8(int);
extern int func_003060C0(void *);
extern int NetRing_Commit(void *, unsigned short);
extern int strcmp(const char *, const char *);
int func_00300D68(R *c)
{
    volatile unsigned short got;
    char addr[0x10];
    unsigned short port;
    unsigned int avail;
    unsigned char *data;
    void *q;
    unsigned short n;
    int more;
    int r;
    data = 0;
    avail = 0;
    got = 0;
    if (D_004908EC != 1) return 5;
    if (func_002FE8B0() != 1) return 2;
    if (c->ready != 1) return 2;
    q = c->q;
    if ((q != 0) != 1) return 2;
    if (func_002F5748(q, 0, 0) != 0) return 0x15;
    if (func_002F58C8(q, &avail) != 0) return 0x15;
    if (avail == 0) goto done;
    do {
        got = 0;
        more = 0;
        if (func_002F5988(q, &data) != 0) return 0x15;
        if (c->type == 0) {
            n = 0x1000;
            if (avail <= 0x1000) n = avail;
            r = func_003010C8(func_002F6090(c->h, data, n, &got));
            if (r != 0) return r;
            if (got == n) more = 1;
        } else if (c->type == 1) {
            if (avail >= 0x248) {
                r = func_003010C8(func_002F61A0(c->h, addr, &port, data, 0x248, &got));
                if (r != 0) return r;
                if (got != 0) {
                    if (port != c->port || strcmp(addr, c->addr) != 0) got = 0;
                    more = 1;
                }
            }
        } else {
            return 3;
        }
        if (got != 0) {
            if (func_003060C0(c->f28) != 0) return 0x18;
            if (NetRing_Commit(q, got) != 0) return 0x15;
        }
        if (func_002F58C8(q, &avail) != 0) return 0x15;
    } while (avail != 0 && more == 1);
done:
    return 0;
}

