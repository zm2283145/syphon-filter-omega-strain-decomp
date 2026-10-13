extern int func_0010CEE0(unsigned short t, void (*cb)(), int arg);
extern int func_0010D050(void);
extern void SleepThread(void);
extern void func_00306D70();
extern double SoftFloat_FloatToDouble(float);
extern int SoftFloat_UnpackAndCompare(double, double);
int func_00306630(unsigned int ms)
{
    float t = ms * 0.015734f;
    unsigned short n;
    while (SoftFloat_UnpackAndCompare(SoftFloat_FloatToDouble(t), 0.0) > 0) {
        if (t > 65535.0f) {
            n = 0xFFFF;
            t -= 65535.0f;
        } else {
            n = (unsigned int)t;
            t = 0.0f;
        }
        func_0010CEE0(n, func_00306D70, func_0010D050());
        SleepThread();
    }
    return 0;
}

