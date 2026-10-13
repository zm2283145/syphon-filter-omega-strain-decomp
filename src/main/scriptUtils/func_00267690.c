#include "types.h"
typedef struct { int a[3]; } Str_7690;
typedef struct { Str_7690 name; int fc; int f10; Str_7690 s14; Str_7690 s20; int f2c; float f30; unsigned char b34; } Mat_7690;
extern Mat_7690* func_004095A0(Mat_7690* o, char* a, int b, char* c, char* d, float f, unsigned char g);
extern unsigned char func_004085A0(void* reg, int a, int b, Mat_7690* m);
extern void func_00138B70(Str_7690* s, int f);
extern char D_0053BB90[];
static inline void Dt_7690(Str_7690* p) { if (p) func_00138B70(p, 0); }
unsigned char Global_AddMaterialProperties(int p0, int p1, char* a, signed char b, char* c, char* d, float f, unsigned char g)
{
    Mat_7690 m;
    unsigned char r;
    func_004095A0(&m, a, b, c, d, f, g);
    r = func_004085A0(D_0053BB90, p0, p1, &m);
    Dt_7690(&m.s20);
    Dt_7690(&m.s14);
    func_00138B70(&m.name, 0);
    return r;
}

