typedef struct { char pad[0x19C]; int f19C; int f1A0; char pad1a4[0x14]; int f1B8; } Msg_0A38;
extern short D_0048C414;
extern int D_0048C3D8;
extern int D_0048C3BC;
extern int D_0048C3F8;
extern int func_002D0EB8(void *, int);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
extern int func_002CEBC0(void);
extern void func_002CE840(int *);
int func_002D0A38(Msg_0A38 *a, int b)
{
    int r;
    func_002D0EB8(a, 0x15);
    func_002D0EB8((char *)a + 0x15, 0x40);
    func_002D0EB8((char *)a + 0x155, 0x20);
    func_002D0EB8((char *)a + 0x55, 0x100);
    a->f19C = func_002CEBC0();
    if (D_0048C414 != 1) return -0xC;
    if (func_002CEBC0() == 1 || func_002CEBC0() == 2) {
        func_002CE840(&a->f1A0);
    } else if (func_002CEBC0() == 0 || func_002CEBC0() == 4) {
        a->f1A0 = 0;
        a->f1B8 = 0;
    } else {
        return -0xD;
    }
    r = Net_SendLocked(0x40, D_0048C3D8, 0xFFFF, 3, D_0048C3BC, 0x1D4, a);
    D_0048C3F8 = b;
    return r ? -5 : 0;
}
