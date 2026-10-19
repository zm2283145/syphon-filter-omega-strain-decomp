/* sceGsResetGraph (libgraph). sceGsGetGParam = sceGsGetGParam, GsPutIMR = GsPutIMR, Alloc_Lock = DisableIntc,
 * RemoveIntcHandler = RemoveIntcHandler, SetGsCrt = SetGsCrt (syscall stubs). */
typedef struct {
    short sceGsInterMode;
    short sceGsOutMode;
    short sceGsFFMode;
    short sceGsVersion;
    int (*sceGsVSCfunc)(int);
    int sceGsVSCid;
} sceGsGParam;

extern sceGsGParam *sceGsGetGParam(void);
extern int GsPutIMR(unsigned long);
extern int Alloc_Lock(int);
extern int RemoveIntcHandler(int, int);
extern void SetGsCrt(short, short, short);

#define GS_CSR (*(volatile unsigned long *)0x12001000)

void sceGsResetGraph(short mode, short inter, short omode, short ffmode)
{
    sceGsGParam *gp;

    switch (mode) {
    case 0:
        gp = sceGsGetGParam();
        GS_CSR = 0x200;
        gp->sceGsInterMode = inter;
        gp->sceGsOutMode = omode;
        gp->sceGsVersion = (unsigned short)((GS_CSR >> 16) & 0xff);
        GsPutIMR(0xff00);
        gp->sceGsFFMode = (ffmode != 0);
        if (gp->sceGsVSCfunc) {
            Alloc_Lock(2);
            RemoveIntcHandler(2, gp->sceGsVSCid);
            gp->sceGsVSCfunc = 0;
            gp->sceGsVSCid = 0;
        }
        SetGsCrt(inter & 1, omode & 0xff, ffmode & 1);
        break;
    case 1:
        GS_CSR = 0x100;
        break;
    case 5:
        gp = sceGsGetGParam();
        gp->sceGsInterMode = inter;
        gp->sceGsOutMode = omode;
        gp->sceGsFFMode = (ffmode != 0);
        gp->sceGsVersion = (unsigned short)((GS_CSR >> 16) & 0xff);
        SetGsCrt(inter & 1, omode & 0xff, ffmode & 1);
        break;
    }
}


