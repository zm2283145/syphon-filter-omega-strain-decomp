unsigned int D_004868B8[2] = { 0x0, 0x0 };
extern void Copy_void_2(void* dst, void* src, int n);
int GetSystemCallEntry(int i)
{
    int v;
    Copy_void_2(&v, (*(char**)D_004868B8) + i * 4, 4);
    return v;
}