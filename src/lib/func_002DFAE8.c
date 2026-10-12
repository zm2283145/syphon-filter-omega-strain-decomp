typedef struct {
    char pad0[0x400];
    int x400;
    char pad404[0x34];
    int x438;
    int pad43C;
    int x440;
} Ctx2DFAE8;

typedef struct {
    char pad0[0x14];
    int x14;
    int x18;
    int x1C;
    char pad20[8];
    char x28;
} Ent2DFAE8;

typedef struct {
    int port;
    int state;
    int arg;
    int err;
    int user;
} Info2DFAE8;

extern int func_002E51B8(unsigned int port, Ctx2DFAE8** ctx);
extern int func_002E6088(int slot);
extern int func_002E5360(unsigned int port, int slot, Ent2DFAE8** ent);
extern void func_002F84A0(int a, int b, int c, int d);
extern int func_00314CB0(unsigned int port);
extern int func_00314B40(unsigned int port, int slot, Ent2DFAE8* ent);
extern void func_00314A98(unsigned int port);
extern int func_00302B28(int h, int a, Ent2DFAE8* ent, void* p);
extern void* memset(void* d, int c, unsigned int n);
extern int D_0048C4B0;
extern void (*D_0048C468)(Info2DFAE8* info);
extern int D_0048C46C;

void func_002DFAE8(unsigned int port, int slot, unsigned char flag, unsigned short n, int arg)
{
    Info2DFAE8 info;
    Ctx2DFAE8* ctx = 0;
    Ent2DFAE8* ent = 0;
    int err;

    if (port >= 4) return;
    if (func_002E51B8(port, &ctx) != 0) return;
    if (ctx == 0) return;
    if (ctx->x438 == 1) return;
    if (flag) {
        register int m asm("$6");
        register int k asm("$7");
        if (func_002E6088(slot) != 1) return;
        err = func_002E5360(port, slot, &ent);
        if (err != 0) return;
        if (ent == 0) return;
        m = n - 1;
        k = 2;
        ctx->x438 = 1;
        ctx->x400 = slot;
        ctx->x440 = m;
        ent->x14 = k;
        ent->x18 = 0;
        ent->x1C = 0;
        ent->x28 = 1;
        func_002F84A0(-1, slot, m, k);
        if (func_00314CB0(port) == 1) {
            err = func_00314B40(port, slot, ent);
            if (err != 0) return;
        }
        if (func_00302B28(D_0048C4B0, 1, ent, (char*)ent + 0x10) != 0) return;
    } else {
        err = 3;
        ctx->x400 = 0x100;
        ctx->x438 = 3;
        if (func_00314CB0(port) == 1) {
            func_00314A98(port);
        }
    }
    if (D_0048C468 != 0) {
        memset(&info, 0, sizeof(info));
        info.state = ctx->x438;
        info.port = port;
        info.arg = arg;
        info.err = err;
        info.user = D_0048C46C;
        D_0048C468(&info);
        D_0048C468 = 0;
        D_0048C46C = 0;
    }
}
