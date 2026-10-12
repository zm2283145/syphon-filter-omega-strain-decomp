typedef struct { int w[32]; } B_002F08D8;
extern void func_002F2364(B_002F08D8 *, B_002F08D8 *);
extern int func_002EFCD0(B_002F08D8 *);
void func_002F08D8(B_002F08D8 *out, B_002F08D8 *x, B_002F08D8 *y)
{
    B_002F08D8 a;
    B_002F08D8 b;
    a = *x;
    b = *y;
    for (;;) {
        func_002F2364(&a, &b);
        if (func_002EFCD0(&a)) {
            *out = b;
            return;
        }
        func_002F2364(&b, &a);
        if (func_002EFCD0(&b)) {
            *out = a;
            return;
        }
    }
}
