#include "types.h"
extern int func_0031DE38(float);
extern int func_00318400(void* a, void* b, int n, int m, float* buf);
extern void func_0031A1E0(void* b, int n, int m, float* buf);
extern void func_0031BAF0(float* a, int m, float* b, float x);
extern void func_00319DC0(float* a, int m);
extern int func_00323250(void);
extern void func_00323330(float* a, int m, int n, void* c, void* d);
extern void func_00322518(float* a, int m, int n, void* c, void* d);
void func_00317C08(void* a, void* b, float x, void* c, void* d, int* outm, int* outn)
{
    float buf[264];
    int m = func_0031DE38(x);
    int n = func_00318400(a, b, 0x91, m, buf);
    *outn = n;
    func_0031A1E0(b, n + 0x91, m, buf);
    func_0031BAF0(buf, m, buf, 2.0f);
    func_00319DC0(buf, m);
    if (func_00323250())
        func_00323330(buf, m, 9, c, d);
    else
        func_00322518(buf, m, 9, c, d);
    *outm = m;
}