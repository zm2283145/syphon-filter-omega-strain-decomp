extern int func_0027D2F8();
extern int func_0010F388(char* fmt, ...);
extern void func_0027D2D0(void* p);
extern int func_00110528(void* cd, int fno, int mode, void* send, int ssize, void* recv, int rsize, void (*end)(void*), void* param);
int func_0027D3A8(void* cd, void* buf, int fno)
{
    int r = func_0027D2F8();
    if (r < 0) {
        func_0010F388("[fatal error] c_sema in netcnfif(type=%d)
", fno);
        return r;
    }
    return func_00110528(cd, fno, 1, buf, 0x1000, buf, 0x1000, func_0027D2D0, (void*)r);
}