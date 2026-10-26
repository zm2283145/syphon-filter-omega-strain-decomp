extern char D_005227F0[];
extern void* memset(void* s, int c, unsigned int n);
int NetInitializeMultiPacketList(void)
{
    memset(D_005227F0, 0, 0x2C00);
    return 0;
}
