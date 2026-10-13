extern volatile int D_00487890;
extern volatile int D_004878B4;
extern char D_00488A50[];
extern int scePrintf(const char *, ...);
extern int sceSifCheckStatRpc(void *);
extern void DelayThread(int);

int sceCdSync(int mode)
{
    if (mode == 0) {
        if (D_00487890 > 0) scePrintf("N cmd wait
");
        while (D_004878B4 || sceSifCheckStatRpc(D_00488A50)) DelayThread(0xFA0);
        return 0;
    }
    if (D_004878B4 || sceSifCheckStatRpc(D_00488A50)) return 1;
    return 0;
}