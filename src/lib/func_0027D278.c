#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int DeleteThread(int);                               
int TerminateThread(int);                               
int sceSifRemoveRpc(int *, int *);                          
int sceSifRemoveRpcQueue(int *);                               
extern int D_00506150;
extern int D_00506198;

void sce_delete_callback_thread(int arg0) {
    sceSifRemoveRpc(&D_00506150, &D_00506198);
    sceSifRemoveRpcQueue(&D_00506198);
    TerminateThread(arg0);
    DeleteThread(arg0);
}
