typedef struct { int w[32]; } B_002F0060;
extern void func_002F2244(B_002F0060 *, int);
void func_002F0060(B_002F0060 *out, B_002F0060 *in, int c)
{
    B_002F0060 t;
    t = *in;
    func_002F2244(&t, c);
    *out = t;
}
