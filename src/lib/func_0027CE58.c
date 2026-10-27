typedef struct { char pad[0x24]; int serve; char pad2[0x18]; } RpcCd;
typedef struct { int x0; int x4; int x8; int xC; char name[0x400]; } McArg;
extern RpcCd D_00504080;
extern McArg D_005040C0;
extern int sceNetcnfifInit(void);
extern int sce_call_rpc(RpcCd *, McArg *, int);
extern void Libc_Strcpy(char *, const char *);
int sceNetcnfifCheckAdditionalAT(const char *name)
{
    McArg *p;
    sceNetcnfifInit();
    p = &D_005040C0;
    Libc_Strcpy(p->name, name);
    return sce_call_rpc(&D_00504080, p, 9);
}