typedef struct { int type; int f4; int f8; unsigned char bC, bD, bE, bF; unsigned char b10, b11; char addr[16]; unsigned short port; int f24; } UpnpEnt;
typedef struct { int h; int a; int b; } UpnpSlot;
typedef struct {
    UpnpSlot slot[32]; void *h180; UpnpEnt *ent; int count; int f18C; int f190;
} UpnpObj;
extern int func_003071E8(void *h, int key, int dir, int *a, int *b, int *c);
int func_00302C00(UpnpObj *o, unsigned int *a, unsigned int *b, unsigned int *c, unsigned int *d)
{
    int x = 0;
    int y = 0;
    int z = 0;
    unsigned int t1 = 0;
    unsigned int t3 = 0;
    unsigned int t4 = 0;
    unsigned int t0 = 0;
    int i;
    int rv = 2;

    if (o == 0)
        return rv;
    if (a == 0)
        return rv;
    if (b == 0)
        return rv;
    if (c == 0)
        return rv;
    if (d == 0)
        return rv;
    {
        *b = 0;
        *a = 0;
        *d = 0;
        *c = 0;
        for (i = 0; i < o->count; i++) {
            if (o->ent[i].f4 != -1) {
                if (func_003071E8(o->h180, o->ent[i].f4, 0, &x, &y, &z) != 0)
                    { rv = 0; goto out; }
                t3 += x;
                t4 += y;
                if (func_003071E8(o->h180, o->ent[i].f4, 1, &x, &y, &z) != 0)
                    { rv = 0; goto out; }
                t1 += x;
                t1 += y;
            }
            if (o->ent[i].f8 != -1) {
                if (func_003071E8(o->h180, o->ent[i].f8, 0, &x, &y, &z) != 0)
                    { rv = 0; goto out; }
                t3 += x;
                t4 += y;
                if (func_003071E8(o->h180, o->ent[i].f8, 1, &x, &y, &z) != 0)
                    { rv = 0; goto out; }
                t1 += x;
                t1 += y;
            }
        }
        *a = t4;
        *b = t0;
        if (t3 != 0)
            *c = t4 / t3 * 100;
        else
            *c = 0;
        if (t1 != 0)
            *d = t0 / t1 * 100;
        else
            *d = 0;
        rv = 0;
    }
out:
    return rv;
}