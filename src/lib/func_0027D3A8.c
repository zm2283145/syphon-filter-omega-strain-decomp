extern int sce_create_sema();
extern int scePrintf(char* fmt, ...);
extern void sce_cbfunc(void* p);
extern int sceSifCallRpc(void* cd, int fno, int mode, void* send, int ssize, void* recv, int rsize, void (*end)(void*), void* param);
int sce_call_rpc(void* cd, void* buf, int fno)
{
    int r = sce_create_sema();
    if (r < 0) {
        scePrintf("[fatal error] c_sema in netcnfif(type=%d)
", fno);
        return r;
    }
    return sceSifCallRpc(cd, fno, 1, buf, 0x1000, buf, 0x1000, sce_cbfunc, (void*)r);
}