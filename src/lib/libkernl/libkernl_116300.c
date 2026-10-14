unsigned int D_004868B8[2] = { 0x0, 0x0 };
extern void func_00116268(void* dst, void* src, int n);
int func_00116300(int i)
{
    int v;
    func_00116268(&v, (*(char**)D_004868B8) + i * 4, 4);
    return v;
}