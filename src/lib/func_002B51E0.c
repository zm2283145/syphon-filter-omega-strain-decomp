/* op and xC volatile: keeps retail store order (and the s0/s1 parameter assignment) */
typedef struct { int a; volatile int op; int x8; volatile int xC; } R2B51E0;
extern int D_0048BD88;
extern R2B51E0 D_00506640;
extern int func_002BB898(void);
extern void func_002BC7E8(void);
int sceMc2GetInfoAsync(int a, int c)
{
    if (D_0048BD88 == 0) return 0x81018001;
    if (!func_002BB898()) return 0x81018002;
    if (D_00506640.op) return 0x81010010;
    D_00506640.xC = c;
    D_00506640.op = 2;
    D_00506640.a = a;
    func_002BC7E8();
    return 0;
}
