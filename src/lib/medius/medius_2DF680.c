/*
 * lib/medius: 7 files, 002DF680-002DFAE8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002DF680 */
extern unsigned int strlen(const char *);
extern unsigned char D_0048C4AC;
extern char D_0058DF80[];
extern int D_0058D17C;
extern int func_002DF708(void);
extern int func_002DD380(char *, char *);
int func_002DF680(char *name, int b)
{
    int r;
    if (name == 0) return 0x17;
    if (strlen(name) == 0) return 0x17;
    if (b == 0) return 0x17;
    if (D_0048C4AC == 0) {
        r = func_002DF708();
        if (r) return r;
    }
    func_002DD380(D_0058DF80, name);
    D_0058D17C = b;
    return 0;
}
/* merge_units: end func_002DF680 */

/* merge_units: begin func_002DF708 */
typedef struct {
    unsigned short port; short pad;
    int a; int b; int c; int d; int e; int f;
    void *g;
    void *f0; void *f1; void *f2; void *f3; void *f4; void *f5;
} Cfg;
extern unsigned char D_0048C4B5;
extern unsigned short D_0058C0B0;
extern int D_0048C49C;
extern int D_0048C4A0;
extern int D_0048C460;
extern int D_0048C4B0;
extern char D_00522760[];
extern void func_002E6178(void);
extern void func_002E6230(void);
extern void func_002E63F0(void);
extern void func_002E64E0(void);
extern void func_002E6590(void);
extern void func_002E6600(void);
extern int func_00302698(Cfg *, int *);
extern int func_003028E8(int);
int func_002DF708(void)
{
    Cfg c;
    if (D_0048C4AC == 0) {
    c.port = D_0058C0B0;
    c.a = 8;
    c.b = 0x200;
    c.c = D_0048C49C;
    c.d = D_0048C4A0;
    c.e = 0x1E;
    c.f = D_0048C460;
    c.f0 = func_002E6178;
    c.f1 = func_002E6230;
    c.f2 = func_002E63F0;
    c.f3 = func_002E64E0;
    c.f4 = func_002E6590;
    c.f5 = func_002E6600;
    if (D_0048C4B5) c.g = D_00522760; else c.g = 0;
    if (func_00302698(&c, &D_0048C4B0)) {
        func_003028E8(D_0048C4B0);
        D_0048C4B0 = 0;
        return 0x25;
    }
    D_0048C4AC = 1;
    }
    return 0;
}
/* merge_units: end func_002DF708 */

/* merge_units: begin func_002DF828 */
extern int D_0058DF84;
extern int D_0058D180;
extern int D_0059841C;
extern int func_002FC118(char *);
extern int func_002E5008(int, int);
extern int String_CompareN(char *, char *, int);
extern int func_002DDFF8(int, char *, int, int, int, int *);
int func_002DF828(int a)
{
    char buf[16];
    char buf2[16];
    int x;
    int r;
    if (D_0048C4AC == 0) {
        r = func_002DF708();
        if (r) return r;
    }
    r = func_002E5008(func_002FC118(buf), 0x18);
    if (r) return r;
    D_0058DF84 = a;
    x = D_0058D180;
    if (String_CompareN(buf, "0.0.0.0", 0x10) == 0) return 0x23;
    func_002DD380(buf2, buf);
    return func_002DDFF8(0, buf2, 0, D_0059841C, 4, &x);
}
/* merge_units: end func_002DF828 */

/* merge_units: begin func_002DF8E8 */
extern signed char D_0058C178[];
extern void func_002DEA68(int);
int func_002DF8E8(void)
{
    int i;
    for (i = 0; i < 0x1000; i++) {
        if (D_0058C178[i] == 2) func_002DEA68(i);
        D_0058C178[i] = 0;
    }
    return 0;
}
/* merge_units: end func_002DF8E8 */

/* merge_units: begin func_002DF958 */
extern unsigned short D_0058D178;
extern char D_005880A0[];
extern unsigned int func_002DCD20(unsigned short);
extern int func_002DD280(void);
extern void Net_DispatchRecv(int, int, int, int, unsigned short);
void func_002DF958(unsigned short a, unsigned short b, int c, unsigned short d)
{
    unsigned int h = func_002DCD20(a);
    if (h >= 4) return;
    if (c == 0) return;
    if (d == 0) return;
    D_005880A0[0] = 0;
    D_0058D178 = 0;
    Net_DispatchRecv(func_002DD280(), h, b, c, d);
}
/* merge_units: end func_002DF958 */

/* merge_units: begin func_002DFA08 */
int func_002DFA08(int* out, unsigned int v)
{
    if (out == 0)
        return 0x17;
    switch (v) {
    case 0: *out = 0; break;
    case 2: *out = 2; break;
    case 3: *out = 3; break;
    case 4: *out = 4; break;
    case 5: *out = 5; break;
    case 6: *out = 6; break;
    case 7: *out = 7; break;
    case 8: *out = 8; break;
    case 9: *out = 9; break;
    case 1: *out = 1; break;
    default: return 0x17;
    }
    return 0;
}
/* merge_units: end func_002DFA08 */

/* merge_units: begin func_002DFAE8 */
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
/* merge_units: end func_002DFAE8 */
