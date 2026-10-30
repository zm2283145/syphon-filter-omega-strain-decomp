extern char D_00506198[];
extern char D_00506150[];
extern char D_00505140[];
extern void sceSifInitRpc(int);
extern int GetThreadId(void);
extern void sceSifSetRpcQueue(void *, int);
extern void sceSifRegisterRpc(void *, unsigned int, void *, void *, void *, void *, void *);
extern void sceSifRpcLoop(void *);
extern void sce_callback(void);

void sce_callback_function(void)
{
    sceSifInitRpc(0);
    sceSifSetRpcQueue(D_00506198, GetThreadId());
    sceSifRegisterRpc(D_00506150, 0x80001101, sce_callback, D_00505140, 0, 0, D_00506198);
    sceSifRpcLoop(D_00506198);
}