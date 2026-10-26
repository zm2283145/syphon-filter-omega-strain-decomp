extern int SoftFloat_UnpackAndCompare(double, double);
extern double SoftFloat_DoubleSub(double, double);
extern double SoftFloat_DoubleMultiply(double, double);
extern double SoftFloat_DoubleDivide(double, double);
extern unsigned long func_0011B970(double);
extern int ftoi(unsigned long);
extern int kprintf(const char *, ...);
extern void (*D_004861A4)(int);
void printfloat(double x)
{
    int e = 0;
    int n;
    if (SoftFloat_UnpackAndCompare(x, 0.0) < 0) {
        x = SoftFloat_DoubleSub(0.0, x);
        D_004861A4('-');
    }
    if (SoftFloat_UnpackAndCompare(x, 0.1) < 0) {
        while (SoftFloat_UnpackAndCompare(x, 0.1) < 0) {
            x = SoftFloat_DoubleMultiply(x, 10.0);
            e--;
        }
    } else if (SoftFloat_UnpackAndCompare(x, 1.0) >= 0) {
        while (SoftFloat_UnpackAndCompare(x, 1.0) >= 0) {
            x = SoftFloat_DoubleDivide(x, 10.0);
            e++;
        }
    }
    n = ftoi(func_0011B970(SoftFloat_DoubleMultiply(x, 1000000.0)));
    kprintf("0.%d", n);
    if (e >= 0)
        kprintf("e+%d", e);
    else
        kprintf("e%d", e);
}


