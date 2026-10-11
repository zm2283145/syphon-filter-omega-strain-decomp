typedef struct { int a; int op; int x8; int xC; } R2B5160;
extern int D_0048BD88;
extern R2B5160 D_00506640;
extern int func_002BB898(void);
extern void func_002BC7E8(void);
int func_002B5160(int a)
{
    if (D_0048BD88 == 0) return 0x81018001;
    if (!func_002BB898()) return 0x81018002;
    if (D_00506640.op) return 0x81010010;
    D_00506640.a = a;
    D_00506640.op = 4;
    func_002BC7E8();
    return 0;
}
