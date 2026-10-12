typedef struct { int w[21]; int tail[3]; } Blk3A20;
static Blk3A20 D_004913D0 = { { 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0 }, { 0, 0, 0 } };
extern void func_00313D90(int *p);
void func_00313A20(Blk3A20 *p)
{
    *p = D_004913D0;
    func_00313D90(p->tail);
}
