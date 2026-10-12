extern int SoftFloat_UnpackAndCompare(double, double);
extern double func_0011C200(double, double);
extern double func_0011C268(double, double);
extern double func_0011C4F0(double, double);
extern unsigned long func_0011B970(double);
extern int func_0010EB58(unsigned long);
extern int func_0010F350(const char *, ...);
extern void (*D_004861A4)(int);
void func_0010EBF0(double x)
{
    int e = 0;
    int n;
    if (SoftFloat_UnpackAndCompare(x, 0.0) < 0) {
        x = func_0011C200(0.0, x);
        D_004861A4('-');
    }
    if (SoftFloat_UnpackAndCompare(x, 0.1) < 0) {
        while (SoftFloat_UnpackAndCompare(x, 0.1) < 0) {
            x = func_0011C268(x, 10.0);
            e--;
        }
    } else if (SoftFloat_UnpackAndCompare(x, 1.0) >= 0) {
        while (SoftFloat_UnpackAndCompare(x, 1.0) >= 0) {
            x = func_0011C4F0(x, 10.0);
            e++;
        }
    }
    n = func_0010EB58(func_0011B970(func_0011C268(x, 1000000.0)));
    func_0010F350("0.%d", n);
    if (e >= 0)
        func_0010F350("e+%d", e);
    else
        func_0010F350("e%d", e);
}


