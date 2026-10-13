typedef struct { int w[32]; } B_002EFEE0;
extern void LargeInt_Add(B_002EFEE0 *, int);
void LargeInt_Add3(B_002EFEE0 *out, B_002EFEE0 *in, int c)
{
    B_002EFEE0 t;
    t = *in;
    LargeInt_Add(&t, c);
    *out = t;
}
