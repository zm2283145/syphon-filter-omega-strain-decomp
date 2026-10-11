#pragma cplusplus on
extern "C" unsigned char* func_00100BC0(unsigned char* p, unsigned int* out);
extern "C" void func_001024A0(signed char* p)
{
    unsigned int v;
    int f = p[0] & 0x40;
    unsigned char* q = func_00100BC0((unsigned char*)p + 1, &v);
    q = func_00100BC0(q, &v);
    if (f) func_00100BC0(q, &v);
}