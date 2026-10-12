extern float D_004B3720[];
extern float D_004E1CD0;
extern void func_0031A1E0(void *in, int a, int n, float *out);
extern void func_00319D30(float *a, float *b, float *out, int n);
extern float func_00317780(float *a, float *b, int n);
extern int func_00323250(void);
extern void func_00323330(float *x, int n, int m, float *a, float *b);
extern void func_00322518(float *x, int n, int m, float *a, float *b);
extern void func_00318848(float *a, float *b, void *out);
void func_00317B40(void *in, void *out, float *energy)
{
    float buf[0x124];
    float a[0x104];
    float b[0x104];
    func_0031A1E0(in, 0x91, 0x123, buf);
    func_00319D30(buf, D_004B3720, buf, 0x123);
    *energy = func_00317780(buf, buf, 0x123) * D_004E1CD0;
    if (func_00323250())
        func_00323330(buf, 0x123, 9, a, b);
    else
        func_00322518(buf, 0x123, 9, a, b);
    func_00318848(a, b, out);
}
