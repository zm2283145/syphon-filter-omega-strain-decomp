typedef struct {
    int type;
    int x04;
    char pad08[0xA4 - 0x08];
    int xA4;
    int xA8;
    int xAC;
    int xB0;
    char *xB4;
    void *xB8;
    char *xBC;
    void *xC0;
    char padC4[0xCC - 0xC4];
    int xCC;
    int xD0;
    char padD4[0x120 - 0xD4];
    int x120;
    unsigned short x124;
} Req;

typedef enum { KT0, KT1 } KType;
typedef enum { CS0, CS1 } CState;

typedef struct {
    KType type;
    int x04;
    char name[0x10];
    unsigned short x18;
    unsigned short pad1A;
    int x1C;
    char pad20[0x34 - 0x20];
    int x34;
    char x38[0x78 - 0x38];
    char s78[0x11];
    char s89[0x11];
} Key;

typedef struct {
    int mode;
    char name[0x10];
    unsigned short x14;
    unsigned short x16;
    unsigned short x18;
    void *x1C;
    int x20;
    int x24;
    int x28;
    int x2C;
    char *x30;
    unsigned short x34;
    void *x38;
    void *x3C;
    void *x40;
    void *x44;
    void *x48;
} Params;

typedef struct {
    int port;
    int state;
    int arg;
    int err;
    int user;
} Info;

typedef struct {
    char pad0[0x428];
    char *x428;
    void *x42C;
    char *x430;
    void *x434;
    CState x438;
    int x43C;
    int pad440;
    int x444;
    int x448;
    KType x44C;
} Ctx;

extern void (*D_0048C468)(Info *);
extern int D_0048C46C;
extern int D_0048C470;
extern int D_0048C474;
extern int D_0048C49C;
extern int D_0048C4A0;

extern void String_Copy(char *, const char *);
extern int func_002DCD20(int);
extern int func_002E0F00(int *);
extern int func_002E5008(int, int);
extern int func_002E51F0(unsigned int, Ctx **);
extern int func_002E54E8(unsigned int, const char *);
extern int func_002E5550(unsigned int, int);
extern int func_002FB9F8(void *, void *);
extern int func_002FBA98(unsigned short);
extern int func_002FBBA0(unsigned short, unsigned char);
extern int func_002FC568(void *);
extern int func_003060C0(void *);
extern int func_003060F0(void *, unsigned int *);
extern int func_00314550(int, int, int *);
extern void *memset(void *, int, unsigned int);
extern unsigned int strlen(const char *);
extern char *strncpy(char *, const char *, unsigned int);

extern void func_002DFCD8();
extern void func_002DF1B8();
extern void func_002DF958();
extern void func_002DFFE8();
extern void func_002E6640();

int func_002E0210(Req *req0, Key *k0, int *res0)
{
    register Req *req asm("$17");
    register Key *k asm("$19");
    register int *res asm("$18");
    Params prm;
    int timer[4];
    char buf[0x100];
    unsigned short handle;
    unsigned int elapsed = 0;
    Ctx *ctx = 0;
    unsigned short len = 0;
    register char *bufp asm("$22") = 0;
    int ret = 0x17;
    register int one asm("$20") = 1;
    int h;
    int slot;
    char *p;

    req = req0;
    k = k0;
    res = res0;
    if (res == 0) return ret;
    res[1] = 3;
    res[2] = -1;
    res[0] = one;
    if (req == 0 || k == 0) goto bad;
    if (req->type != one) {
        res[1] = 0x26;
        return 0x26;
    }
    if (req->x04 <= 0) goto bad;
    if (k->type != one && k->type != 3 && k->type != 4) goto bad;
    if (k->x1C == 3) func_002E0F00(&k->x1C);
    D_0048C468 = (void (*)(Info *))req->xA4;
    D_0048C46C = req->xA8;
    D_0048C470 = req->xAC;
    D_0048C474 = req->xB0;
    if (strlen(k->s78) != 0 && strlen(k->s89) != 0) {
        memset(buf, 0, 0x100);
        bufp = buf;
        strncpy(bufp, k->s78, 0x11);
        bufp += 0x11;
        strncpy(bufp, k->s89, 0x11);
        bufp += 0x11;
        len = bufp - buf;
        bufp = buf;
    }
    ret = func_002E5008(func_002FC568(&prm), 0x18);
    if (ret != 0) return ret;
    if (k->type == 1 || k->type == 4) {
        prm.mode = 0;
    } else if (k->type == 3) {
        prm.mode = 1;
        prm.x18 = req->x124;
    } else {
    bad:
        res[1] = 0x17;
        return 0x17;
    }
    String_Copy(prm.name, k->name);
    prm.x14 = k->x18;
    prm.x16 = k->x34;
    prm.x1C = k->x38;
    prm.x20 = 15000;
    prm.x28 = D_0048C49C;
    prm.x2C = D_0048C4A0;
    prm.x30 = bufp;
    prm.x34 = len;
    prm.x38 = func_002DFCD8;
    prm.x44 = func_002DFFE8;
    prm.x3C = func_002DF1B8;
    prm.x40 = func_002DF958;
    prm.x48 = func_002E6640;
    h = func_002FB9F8(&handle, &prm);
    if (h != 0) {
        func_002FBA98(handle);
        if (D_0048C468 != 0) {
            Info info;
            memset(&info, 0, sizeof(info));
            info.port = -1;
            info.arg = 1;
            info.state = 3;
            info.err = 3;
            info.user = D_0048C46C;
            D_0048C468(&info);
        }
        ret = func_002E5008(h, 3);
        res[1] = ret;
        if (ret != 0) return ret;
    }
    slot = func_002DCD20(handle);
    res[2] = slot;
    res[1] = func_002E51F0(slot, &ctx);
    if (res[1] == 0) {
        if (req->xD0 == 1) res[1] = func_00314550(slot, req->x04, &req->xCC);
    }
    if (res[1] != 0 || ctx == 0) {
        func_002FBA98(handle);
        if (D_0048C468 != 0) {
            Info info;
            memset(&info, 0, sizeof(info));
            info.port = -1;
            info.arg = 1;
            info.state = 3;
            info.err = 3;
            info.user = D_0048C46C;
            D_0048C468(&info);
        }
        return res[1];
    }
    func_002E5550(slot, 0x100);
    ctx->x428 = req->xB4;
    ctx->x42C = req->xB8;
    ctx->x430 = req->xBC;
    ctx->x434 = req->xC0;
    ctx->x438 = 2;
    ctx->x43C = k->x34;
    ctx->x444 = req->x04;
    ctx->x448 = req->x120;
    ctx->x44C = k->type;
    ret = func_002E54E8(slot, k->name);
    res[1] = ret;
    if (ret != 0) {
        ctx->x438 = 3;
        return ret;
    }
    if (D_0048C468 == 0) {
        func_003060C0(timer);
        while (ctx->x438 == 2) {
            int h2 = func_002FBBA0(handle, 1);
            if (h2 != 0) {
                ctx->x438 = 3;
                ret = func_002E5008(h2, 3);
                res[1] = ret;
                if (ret != 0) return ret;
            }
            func_003060F0(timer, &elapsed);
            if (elapsed > 30000) {
                ctx->x438 = 3;
                res[1] = 3;
                return 3;
            }
        }
        if (ctx->x438 != 1) {
            ctx->x438 = 3;
            res[1] = 3;
            return 3;
        }
    }
    res[1] = 0;
    return 0;
}
