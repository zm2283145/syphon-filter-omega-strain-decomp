extern int D_004F8640[];
extern char D_004F85C8[];
extern int func_00110528(void* cd, unsigned int fno, int mode, void* send, int ssize, void* recv, int rsize, void* end, void* param);
extern void func_0026B1C8(const char* fmt, ...);extern char D_004A8660[];
int func_0026AB10(int* p)
{
    D_004F8640[2] = 2;
    D_004F8640[4] = p[2];
    D_004F8640[5] = p[3];
    if (func_00110528(D_004F85C8, 0x8000131D, 0, D_004F8640, 0x280, D_004F8640, 0x280, 0, 0) < 0) {
        func_0026B1C8(D_004A8660);
        return -1;
    }
    return D_004F8640[1];
}