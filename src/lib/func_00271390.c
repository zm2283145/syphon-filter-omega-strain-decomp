#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int sceSifRemoveCmdHandler(int);                                 
int sceSifRemoveRebootNotifyHandler(int);                                 
extern int D_0048B2C8;

void sceSifMExitRpc(void) {
    D_0048B2C8 = 0;
    sceSifRemoveCmdHandler(0x80000018);
    sceSifRemoveRebootNotifyHandler(0x80000014);
}
