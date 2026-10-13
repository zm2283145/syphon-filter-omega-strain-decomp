extern volatile int D_00487890;
extern char D_00489400[];
extern int scePrintf(const char *, ...);
extern int sceSifCheckStatRpc(void *);
extern void DelayThread(int);

int func_00118FA0(int mode)
{
    if (mode == 0) {
        if (D_00487890 > 0) scePrintf("S cmd wait
");
        while (sceSifCheckStatRpc(D_00489400)) DelayThread(0xFA0);
        return 0;
    }
    return sceSifCheckStatRpc(D_00489400);
}