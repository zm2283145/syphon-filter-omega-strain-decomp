typedef struct { int w[32]; } B_002EFEE0;
extern void func_002F2124(B_002EFEE0 *, int);
void func_002EFEE0(B_002EFEE0 *out, B_002EFEE0 *in, int c)
{
    B_002EFEE0 t;
    t = *in;
    func_002F2124(&t, c);
    *out = t;
}
