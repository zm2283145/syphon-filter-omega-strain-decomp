extern int D_0051FEE8[];
extern void DmeFree(int *);
int NetCleanupClientPingInfoArray(void)
{
    unsigned int i;
    int *p = D_0051FEE8;
    for (i = 0; i < 0x100; i++, p++) {
        if (*p) {
            DmeFree(p);
            *p = 0;
        }
    }
    return 0;
}