typedef struct { char pad[0x24]; int serve; char pad2[0x18]; } RpcCd;
typedef struct { int x0; int x4; int x8; int xC; char name[0x100]; char name2[0x100]; } McArg;
extern RpcCd D_00504080;
extern McArg D_005040C0;
extern int sceNetcnfifInit(void);
extern int sce_call_rpc(RpcCd *, McArg *, int);
extern void String_Copy(char *, const char *);
int sceNetcnfifGetList(const char *name, int a1, int a2, int a3)
{
    McArg *p = &D_005040C0;
    sceNetcnfifInit();
    String_Copy(p->name, name);
    p->x0 = a3;
    p->x8 = a1;
    p->xC = a2;
    return sce_call_rpc(&D_00504080, p, 1);
}