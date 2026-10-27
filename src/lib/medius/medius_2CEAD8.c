extern int D_0048C3D8;
extern int D_0048C384;
extern int MGCLGetProcessingState(void);
extern void MGCLSetProcessingState(int);
extern void MGCLGetQueuedRequestType(int *);
extern void MGCLGetQueuedRequest(char *);
extern void MGCLGetClientAddrList(char *);
extern int NetSendMessage(int, int, int, int, int, int, void *);
int MGCLCheckRequestQueue(void)
{
    char buf[0x50];
    int st;
    int r = 0;
    if (MGCLGetProcessingState() == 1) {
        MGCLSetProcessingState(0);
        MGCLGetQueuedRequestType(&st);
        if (st == 0) {
            MGCLGetQueuedRequest(buf);
            MGCLGetClientAddrList(buf + 0x1C);
            r = NetSendMessage(0x40, D_0048C3D8, 0xFFFF, 3, D_0048C384, 0x4C, buf);
        }
        if (r != 0) return -5;
    } else if (MGCLGetProcessingState() == 3) return -0xE;
    else if (MGCLGetProcessingState() == 2) return -5;
    return 0;
}

