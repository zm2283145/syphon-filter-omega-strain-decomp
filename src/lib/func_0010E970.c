typedef struct { int size; volatile int count; unsigned char *rd; unsigned char *wr; } Ring;
typedef struct { volatile int fd; volatile int x4; volatile unsigned int x8; volatile int xC; char *x10; unsigned char *x14; Ring *x18; } Ctx;
extern Ctx D_004E2950;
extern char D_004E2980[];
extern char D_004E2AC0[];
extern void func_0010D3E0(int);
extern int func_0010E2B0(int, void *, void (*)(int, int, Ctx *));
extern void func_0010E590(int, int, Ctx *);
extern Ring *func_0010E4E8(int);
int func_0010E970(void)
{
    char *b;
    func_0010D3E0(0);
    D_004E2950.fd = func_0010E2B0(0x210, &D_004E2950, func_0010E590);
    if (D_004E2950.fd < 0)
        return 0;
    D_004E2950.xC = 0;
    D_004E2950.x4 = 0;
    D_004E2950.x8 = 0;
    D_004E2950.x14 = (unsigned char *)((unsigned int)D_004E2AC0 | 0x20000000);
    b = (char *)((unsigned int)D_004E2980 | 0x20000000);
    D_004E2950.x10 = b;
    *(short *)(b + 4) = 0x210;
    b[6] = 0x45;
    b[7] = 0x48;
    *(short *)(b + 2) = 0;
    *(int *)(b + 8) = 0;
    D_004E2950.x18 = func_0010E4E8(0x100);
    return 1;
}

