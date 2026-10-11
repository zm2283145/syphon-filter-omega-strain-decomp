typedef struct { int w[32]; } B_002F01E0;
extern void func_002F2364(B_002F01E0 *, int);
void func_002F01E0(B_002F01E0 *out, B_002F01E0 *in, int c)
{
    B_002F01E0 t;
    t = *in;
    func_002F2364(&t, c);
    *out = t;
}
