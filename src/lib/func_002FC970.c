extern void *memset(void *, int, unsigned int);
typedef struct { unsigned char flag; char pad[3]; int x4; int x8; } S2FC970;
extern unsigned char D_004908EC;
extern S2FC970 D_005297E0;
extern int func_002F5C98(int *, int, int, int *);
extern int func_003010C8(int);
int func_002FC970(int *x)
{
    int m[3];
    int r;
    unsigned char st = D_004908EC;
    if (st != 1) return 5;
    if (x == 0) return 2;
    if (D_005297E0.flag) return 1;
    memset(m, 0, 0xC);
    m[0] = 3;
    r = func_003010C8(func_002F5C98(&D_005297E0.x4, 0, 0, m));
    if (r) return r;
    D_005297E0.x8 = *x;
    D_005297E0.flag = st;
    return r;
}
