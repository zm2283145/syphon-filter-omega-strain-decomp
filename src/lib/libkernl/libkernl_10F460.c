#define R(a) (*(volatile unsigned int *)(a))
typedef struct { void (*func)(void *, void *); void *data; int pad; } SysH;
typedef struct { void *pkt; void *buf; int iop; SysH *sys; int nsys; void *usr; int nusr; int *sregs; } CmdData;
typedef struct { int x0; int x4; int x8; int xC; void *x10; } CmdPkt;
extern int D_004861A8;
extern char D_004E2C80[];
extern char D_004E2D00[];
extern CmdPkt D_004E2D40;
extern int D_004E2D54;
extern CmdData D_004E2D58;
extern SysH D_004E2D80[32];
extern int D_004E2F00[32];
extern int DIntr(void);
extern int EIntr(void);
extern void FlushCache(int);
extern void sceSifSetDChain(void);
extern int sceSifSetReg(unsigned int, unsigned int);
extern unsigned int sceSifGetReg(unsigned int);
extern int AddDmacHandler(int, void *, int);
extern int EnableDmac(int);
extern int func_0010F948(unsigned int, void *, int, void *, void *, int);
extern void func_0010F408(void *, void *);
extern void func_0010F3E8(void *, void *);
extern int func_0010F9C8(int);
void func_0010F460(void)
{
    int i;
    unsigned int v;
    DIntr();
    if (D_004861A8) {
        EIntr();
        return;
    }
    D_004861A8 = 1;
    D_004E2D58.pkt = (void *)((unsigned int)D_004E2C80 | 0x20000000);
    D_004E2D58.buf = (void *)((unsigned int)D_004E2D00 | 0x20000000);
    D_004E2D58.iop = 0;
    D_004E2D58.sys = D_004E2D80;
    D_004E2D58.nsys = 32;
    D_004E2D58.usr = 0;
    D_004E2D58.nusr = 0;
    D_004E2D58.sregs = D_004E2F00;
    for (i = 0; i < 32; i++) {
        D_004E2D80[i].func = 0;
        D_004E2D80[i].data = 0;
    }
    for (i = 0; i < 32; i++)
        D_004E2F00[i] = 0;
    D_004E2D80[0].func = func_0010F408;
    D_004E2D80[0].data = &D_004E2D58;
    D_004E2D80[1].func = func_0010F3E8;
    D_004E2D80[1].data = &D_004E2D58;
    EIntr();
    FlushCache(0);
    if (R(0x1000E010) & 0x20)
        R(0x1000E010) = 0x20;
    if (!(R(0x1000C000) & 0x100))
        sceSifSetDChain();
    D_004E2D54 = AddDmacHandler(5, func_0010F9C8, 0);
    EnableDmac(5);
    v = sceSifGetReg(0x80000000);
    D_004E2D58.iop = v;
    if (v) {
        D_004E2D40.x10 = D_004E2C80;
        func_0010F948(0x80000000, &D_004E2D40, 0x14, 0, 0, 0);
        return;
    }
    while (!(sceSifGetReg(4) & 0x20000))
        ;
    v = sceSifGetReg(2);
    D_004E2D58.iop = v;
    sceSifSetReg(0x80000000, v);
    sceSifSetReg(0x80000001, (unsigned int)&D_004E2D58);
    D_004E2D40.x10 = D_004E2C80;
    D_004E2D40.xC = 0;
    func_0010F948(0x80000002, &D_004E2D40, 0x14, 0, 0, 0);
}

