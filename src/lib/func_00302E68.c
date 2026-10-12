typedef struct { int type; int f4; int f8; unsigned char bC, bD, bE, bF; unsigned char b10, b11; char addr[16]; unsigned short port; int f24; } UpnpEnt;
typedef struct { int h; int a; int b; } UpnpSlot;
typedef struct {
    UpnpSlot slot[32]; void *h180; UpnpEnt *ent; int count; int f18C; int f190;
} UpnpObj;
extern int func_003071E8(void *h, int key, int dir, int *a, int *b, int *c);
int func_00302E68(UpnpObj *o, int idx, int *a, int *b, int *c, int *d)
{
    int x = 0;
    int y = 0;
    int z = 0;
    int rv = 2;

    if (o == 0)
        return rv;
    if (o->count < idx)
        return rv;
    if (a == 0)
        return rv;
    if (c == 0)
        return rv;
    if (b == 0)
        return rv;
    if (d == 0)
        return rv;
    {
        *b = 0;
        *a = 0;
        *d = 0;
        *c = 0;
        if (o->ent[idx].f4 != -1) {
            if (func_003071E8(o->h180, o->ent[idx].f4, 0, &x, &y, &z) != 0) return 0;
            *b += x;
            *a += y;
            if (func_003071E8(o->h180, o->ent[idx].f4, 1, &x, &y, &z) != 0) return 0;
            *d += x;
            *c += y;
        }
        if (o->ent[idx].f8 != -1) {
            if (func_003071E8(o->h180, o->ent[idx].f8, 0, &x, &y, &z) != 0) return 0;
            *b += x;
            *a += y;
            if (func_003071E8(o->h180, o->ent[idx].f8, 1, &x, &y, &z) != 0) return 0;
            *d += x;
            *c += y;
        }
        rv = 0;
    }
out:
    return rv;
}
