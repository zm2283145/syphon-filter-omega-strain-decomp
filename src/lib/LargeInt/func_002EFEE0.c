typedef struct { int w[32]; } B_002EFEE0;
extern void lintAddIP(B_002EFEE0 *, int);
void lintAdd(B_002EFEE0 *out, B_002EFEE0 *in, int c)
{
    B_002EFEE0 t;
    t = *in;
    lintAddIP(&t, c);
    *out = t;
}
