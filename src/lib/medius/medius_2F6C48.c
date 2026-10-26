extern unsigned char D_004908A0;
extern int D_004908D4;
extern char D_00525600[];
extern char D_00525640[];
extern int sceLibnetUnregisterHandler(char *, char *);
extern int sceLibnetTerminate(char *);
int rt_comm_platform2_shutdown(void)
{
    if (D_004908A0 != 1) return 5;
    if (sceLibnetUnregisterHandler(D_00525600, D_00525640) < 0) return 1;
    sceLibnetTerminate(D_00525600);
    D_004908A0 = 0;
    D_004908D4 = -1;
    return 0;
}
