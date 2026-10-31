typedef struct { int x0; int x4; int x8; } Fld2E76D0;
typedef struct {
    int size;
    int cnt;
    char pad8[0x20];
    Fld2E76D0* fld[64];
    int off[64];
    char pad228[0x228 - 0x228];
} Tbl2E76D0;
typedef struct {
    unsigned char x0; unsigned char x1; unsigned char x2; unsigned char x3;
    unsigned char x4; char x5; short x6;
    unsigned short x8; short xA;
    int xC; int x10;
    char x14[0x10];
} Msg2E76D0;
typedef struct {
    unsigned char x0; unsigned char x1; unsigned char x2; unsigned char x3;
    int x4; int x8;
    char xC[0x10];
    char* x1C; char* x20;
    int x24; int x28;
    int x2C; int x30; int x34;
    int* x38; int* x3C;
} Ent2E76D0;
typedef struct { char pad[0x400]; unsigned int x400; char pad404[0x40]; int x444; } Ctx2E76D0;
extern unsigned int D_0048C450;
extern int D_0048C464;
extern int D_0058806C;
extern Ent2E76D0* D_005880B0[];
extern signed char D_0058C178[];
extern Tbl2E76D0 D_0058DF98[];
extern int NetGetConnInfo(unsigned int, Ctx2E76D0**);
extern int LocalObjectName2Index(char*, unsigned int, unsigned int);
extern int FindFreeLocalObject(void);
extern void NetIGetObject(Ent2E76D0**, int);
extern void* DMEmalloc(int);
extern void DmeFree(void*);
extern void Libc_Strcpy(char*, char*);
extern void* memcpy(void*, const void*, unsigned int);
extern void RemoteObjectCreation(int, int);
extern void RemoteObjectUpdate(int, int, int);

int NetObjectFullUpdatePacketHandler(unsigned int slot, int unused, unsigned int id, Msg2E76D0* m)
{
    Ctx2E76D0* ctx;
    Ent2E76D0* e;
    int flag;
    Tbl2E76D0* t;
    int idx;
    signed char old;
    int savedCnt;
    int total;
    int i;
    char* data;
    int ret = -1;
    Fld2E76D0* f;
    int sz;

    e = 0;
    ctx = 0;
    flag = 0;
    if (m == 0) return ret;
    if (D_0048C450 >= 4) return ret;
    if (slot >= 4) return ret;
    if (id >= 0x100) return ret;
    if (NetGetConnInfo(D_0048C450, &ctx) != 0 || ctx == 0)
        return -1;
    t = &D_0058DF98[m->x1];
    idx = m->x8;
    if (m->x0 == ctx->x400) {
        if (D_0058C178[idx] == 2)
            goto have;
        e = 0;
        if (LocalObjectName2Index(m->x14, slot, m->x0) < 0) {
            idx = FindFreeLocalObject();
            if (idx >= 0)
                NetIGetObject(&e, idx);
        } else {
            total = 0x24;
            for (i = 0; i < t->cnt; i++) {
                f = t->fld[i];
                total += f->x4 * f->x8;
            }
            return total;
        }
    }
    old = D_0058C178[idx];
    if (old == 2)
        goto have;
    savedCnt = D_0048C464;
    e = DMEmalloc(0x44);
    if (e == 0)
        return 0x24;
    D_0058C178[idx] = 2;
    D_005880B0[idx] = e;
    if (D_0048C464 < idx + 1)
        D_0048C464 = idx + 1;
    e->x8 = m->x0;
    e->x2C = m->xC;
    e->x30 = m->x10;
    e->x34 = 0;
    e->x1C = DMEmalloc(t->size);
    e->x20 = DMEmalloc(t->size);
    e->x38 = DMEmalloc(ctx->x444 * 4);
    e->x3C = DMEmalloc(t->cnt * 4);
    if (e->x1C && e->x20 && e->x38 && (flag = 1, e->x3C))
        goto fill;
    if (e->x1C) { DmeFree(&e->x1C); e->x1C = 0; }
    if (e->x20) { DmeFree(&e->x20); e->x20 = 0; }
    if (e->x38) { DmeFree(&e->x38); e->x38 = 0; }
    if (e->x3C) { DmeFree(&e->x3C); e->x3C = 0; }
    DmeFree(&e);
    D_0048C464 = savedCnt;
    D_005880B0[idx] = 0;
    D_0058C178[idx] = old;
    return 0x24;
have:
    NetIGetObject(&e, idx);
fill:
    if (e == 0)
        return 0x24;
    total = 0x24;
    e->x4 = m->x6;
    e->x0 = m->x1;
    Libc_Strcpy(e->xC, m->x14);
    e->x1 = m->x2;
    e->x2 = m->x4;
    e->x3 = m->x3;
    data = (char*)m + total;
    for (i = 0; i < t->cnt; i++) {
        f = t->fld[i];
        sz = f->x4 * f->x8;
        if (e)
            memcpy(e->x1C + t->off[i], data, sz);
        data += sz;
        total += sz;
        e->x3C[i] = D_0058806C;
    }
    memcpy(e->x20, e->x1C, t->size);
    e->x34 = D_0058806C;
    if (flag)
        RemoteObjectCreation(e->x8, idx);
    else
        RemoteObjectUpdate(e->x8, idx, -1);
    return total;
}

