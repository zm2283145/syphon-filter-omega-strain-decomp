typedef struct { int w[32]; } B_002F01E0;
extern void MODIP(B_002F01E0 *, int);
void MOD(B_002F01E0 *out, B_002F01E0 *in, int c)
{
    B_002F01E0 t;
    t = *in;
    MODIP(&t, c);
    *out = t;
}
