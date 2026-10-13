extern int func_0027D2F8();
extern int scePrintf(char* fmt, ...);
extern void func_0027D2D0(void* p);
extern int sceSifCallRpc(void* cd, int fno, int mode, void* send, int ssize, void* recv, int rsize, void (*end)(void*), void* param);
int func_0027D3A8(void* cd, void* buf, int fno)
{
    int r = func_0027D2F8();
    if (r < 0) {
        scePrintf("[fatal error] c_sema in netcnfif(type=%d)
", fno);
        return r;
    }
    return sceSifCallRpc(cd, fno, 1, buf, 0x1000, buf, 0x1000, func_0027D2D0, (void*)r);
}