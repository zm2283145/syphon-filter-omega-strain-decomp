typedef struct { int type; char pad[0x1C]; char f20[0x48]; char q[4]; } C;
extern unsigned char D_004908EC;
extern int D_004908F8;
extern int func_002FE8B0(void);
extern int func_002F5840(void *, int *);
extern int func_002F59F8(void *, unsigned char *);
extern int func_002F5748(void *, int, int);
extern int func_002F5918(void *, unsigned char **);
extern int func_002F53B8(void *, unsigned short);
extern int func_003060C0(void *);
extern int Socket_Write(C *, unsigned char *, int, unsigned short *);
int NetConn_Drain(C *c)
{
    unsigned char flag;
    unsigned short wrote;
    int avail;
    unsigned char *data;
    void *q;
    int r;
    data = 0;
    avail = 0;
    wrote = 0;
    if (D_004908EC != 1) return 5;
    if (func_002FE8B0() != 1) return 2;
    q = c->q;
    if ((q != 0) != 1) return 2;
    if (func_002F5840(q, &avail) != 0) return 0x15;
    if (avail == 0) goto done;
    if (c->type == 1) {
        flag = 1;
        if (func_002F59F8(q, &flag) != 0) return 0x15;
        if (flag == 1) {
            if (func_002F5748(q, 1, D_004908F8) != 0) return 0x15;
            if (func_002F5840(q, &avail) != 0) return 0x15;
        }
    }
    do {
        if (func_002F5918(q, &data) != 0) return 0x15;
        wrote = 0;
        r = Socket_Write(c, data, avail, &wrote);
        if (r != 0) return r;
        if (wrote != 0) {
            if (func_003060C0(c->f20) != 0) return 0x18;
        }
        if (func_002F53B8(q, wrote) != 0) return 0x15;
        if (func_002F5840(q, &avail) != 0) return 0x15;
    } while (avail != 0 && wrote != 0);
done:
    return 0;
}


