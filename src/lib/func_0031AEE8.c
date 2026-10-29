extern float* D_004E1D5C;
extern float* D_004E1D58;
extern const float D_004E1D60;

void NellyDFT(float* x, int n, int count, float* re, float* im, float step)
{
    register float f asm("$f7") = 0.0f;
    register float sr asm("$f5");
    register float si asm("$f6");
    register float a asm("$f0");
    register float b asm("$f1");
    register float c asm("$f3");
    register float s asm("$f4");
    float* pr;
    float* pl;
    register int ph asm("$9");
    int inc, i;

    for (; count != 0; count--) {
        f += step;
        pr = &x[n >> 1];
        pl = pr;
        sr = *pr++;
        si = 0.0f;
        pl--;
        inc = (int)(D_004E1D60 * f + 0.5f);
        ph = inc & 0xFF;
        i = n >> 1;
        while (--i) {
            a = *pr++;
            b = *pl--;
            s = D_004E1D5C[ph];
            c = D_004E1D58[ph];
            ph = (ph + inc) & 0xFF;
            {
                register float t asm("$f2");
                t = a * c;
                a = a * s;
                c = b * c;
                b = b * s;
                si -= t;
                sr += a;
                si += c;
                sr += b;
            }
        }
        b = *pl;
        {
            register int o asm("$2");
            o = ph << 2;
            s = *(float*)(o + (int)D_004E1D5C);
            c = *(float*)(o + (int)D_004E1D58);
        }
        a = b * s;
        b = b * c;
        sr += a;
        si += b;
        if (n & 1) {
            a = *pr;
            b = a * c;
            a = a * s;
            si -= b;
            sr += a;
        }
        *re++ = sr;
        *im++ = si;
    }
}