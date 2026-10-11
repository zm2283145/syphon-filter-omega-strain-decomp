typedef struct { unsigned char a; unsigned char b; } EE0A8;
typedef struct { int x0; int x4; EE0A8 e[0x200]; } QE0A8;
extern int D_00486198;
extern QE0A8 D_004E2408;
extern int D_004E2400;
extern void func_0010D190(int);
int func_0010E0A8(unsigned int c)
{
    int i;
    if (c >= 0x80 || D_00486198 == 0) return -1;
    i = D_004E2408.x4 & 0x1FF;
    D_004E2408.x4 = i + 1;
    D_004E2408.e[i].a = 1;
    D_004E2408.e[i].b = c;
    func_0010D190(D_004E2400);
    return c;
}