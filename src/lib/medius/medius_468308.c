/* same-unit callee stub: weak, in a section the link discards (the real function is defined elsewhere); restores retail delay-slot choices */
extern int D_00497CC4, D_00598564, D_0059857C;
extern int MediusGetProcessingState(void);
extern void MediusSetProcessingState(int);
extern void MediusGetQueuedRequestType(int *);
void __attribute__((weak, section(".dtors_drop"))) MediusGetQueuedRequest(void * a0) { }
extern void MediusGetClientAddrList(void *);
extern int Net_SendLocked(int, int, int, int, int, int, void *);
int MediusCheckRequestQueue(void)
{
    char a[0xC4];
    char b[0xEC];
    int t[1];
    int r = 0;
    if (MediusGetProcessingState() == 2) {
        MediusSetProcessingState(0);
        return -0xA;
    }
    if (MediusGetProcessingState() == 1) {
        MediusSetProcessingState(0);
        MediusGetQueuedRequestType(t);        switch (t[0]) {
        case 0x2C:
            MediusGetQueuedRequest(a);
            MediusGetClientAddrList(a + 0x94);
            r = Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_0059857C, 0xC4, a);
            break;
        case 0x12:
            MediusGetQueuedRequest(b);
            MediusGetClientAddrList(b + 0xBC);
            r = Net_SendLocked(0x40, D_00497CC4, 0xFFFF, 1, D_00598564, 0xEC, b);
            break;
        }
    }
    if (r) return -0xA;
    return 0;
}
