typedef struct { int w[32]; } B_002F0060;
extern void lintSubIP(B_002F0060 *, int);
void lintSub(B_002F0060 *out, B_002F0060 *in, int c)
{
    B_002F0060 t;
    t = *in;
    lintSubIP(&t, c);
    *out = t;
}
