extern int D_004F8640[];
extern char D_004F85C8[];
extern int func_00110528(void* cd, unsigned int fno, int mode, void* send, int ssize, void* recv, int rsize, void* end, void* param);
extern void func_0026B1C8(const char* fmt, ...);int func_0026A2D0(void)
{
    func_00110528(D_004F85C8, 0x80001363, 0, D_004F8640, 0x280, D_004F8640, 0x280, 0, 0);
    return D_004F8640[0];
}