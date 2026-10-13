typedef struct { int w[32]; } B2F1058;
extern void func_002EFE68(B2F1058 *, int);
extern int func_002EFCC0(B2F1058 *);
extern void func_002F1EA0(B2F1058 *, int);
extern void func_002F14E8(B2F1058 *, int, B2F1058 *, B2F1058 *);
extern int LargeInt_IsOne(B2F1058 *);
extern void LargeInt_MulMod(B2F1058 *, B2F1058 *, B2F1058 *, B2F1058 *);
int func_002F1058(B2F1058 *in, int arg)
{
    B2F1058 out;
    B2F1058 tmp;
    tmp = *in;
    func_002EFE68(&tmp, 1);
    if (func_002EFCC0(&tmp)) {
        func_002F1EA0(&tmp, 1);
        func_002F14E8(&out, arg, &tmp, in);
        if (LargeInt_IsOne(&out)) return 0;
        LargeInt_MulMod(&out, &out, &out, in);
        if (LargeInt_IsOne(&out)) return 1;
    }
    return 0;
}