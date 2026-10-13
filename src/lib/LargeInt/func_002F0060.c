typedef struct { int w[32]; } B_002F0060;
extern void LargeInt_Sub(B_002F0060 *, int);
void LargeInt_Sub3(B_002F0060 *out, B_002F0060 *in, int c)
{
    B_002F0060 t;
    t = *in;
    LargeInt_Sub(&t, c);
    *out = t;
}
