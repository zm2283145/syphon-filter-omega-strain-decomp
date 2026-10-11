typedef struct { char pad[0x24]; int serve; char pad2[0x18]; } RpcCd;
typedef struct { int x0; int x4; int x8; int xC; char name[0x100]; char name2[0x100]; char name3[0x100]; } McArg;
extern RpcCd D_00504080;
extern McArg D_005040C0;
extern int D_0048B370;
extern int func_0027C3D0(void);
extern int func_0027D3A8(RpcCd *, McArg *, int);
int func_0027CF70(int x)
{
    func_0027C3D0();
    D_005040C0.x0 = x;
    return func_0027D3A8(&D_00504080, &D_005040C0, 0x65);
}
