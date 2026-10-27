typedef struct { char pad[0x24]; int serve; char pad2[0x18]; } RpcCd;
typedef struct { int x0; int x4; int x8; int xC; char name[0x100]; char name2[0x100]; char name3[0x100]; } McArg;
extern RpcCd D_00504080;
extern McArg D_005040C0;
extern int D_0048B370;
extern int sceNetcnfifInit(void);
extern int sce_call_rpc(RpcCd *, McArg *, int);
extern char *Libc_Strcpy(char *, const char *);
int sceNetcnfifCheckSpecialProvider(const char *name, int a1, const char *name2)
{
    McArg *p;
    sceNetcnfifInit();
    p = &D_005040C0;
    Libc_Strcpy(p->name, name);
    p->x8 = a1;
    Libc_Strcpy(p->name2, name2);
    p->x4 = D_0048B370;
    return sce_call_rpc(&D_00504080, p, 0xA);
}
