typedef struct { char pad[0x24]; int serve; char pad2[0x18]; } RpcCd;
typedef struct { int x0; int x4; int x8; int xC; char name[0x100]; char name2[0x100]; } McArg;
extern RpcCd D_00504080;
extern McArg D_005040C0;
extern int func_0027C3D0(void);
extern int func_0027D3A8(RpcCd *, McArg *, int);
extern void String_Copy(char *, const char *);
int func_0027C690(const char *name, int a1, int a2, int a3)
{
    McArg *p = &D_005040C0;
    func_0027C3D0();
    String_Copy(p->name, name);
    p->x0 = a3;
    p->x8 = a1;
    p->xC = a2;
    return func_0027D3A8(&D_00504080, p, 1);
}