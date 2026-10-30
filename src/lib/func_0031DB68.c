extern float D_004B5628[];

float VoicingLD(float *re, float *im, int n, float ratio)
{
    float step;
    int istep;
    int count;
    int pos;
    int end;
    float sum;
    int k;
    float *tab = D_004B5628;

    step = 512.0f / ratio;
    istep = (int)(step * 32768.0f + 0.5f);
    count = (int)((float)n / step);
    sum = 0.0f;
    pos = 0;
    end = ((istep >> 1) + 0x4000) >> 15;
    for (k = 0; k < count; k++) {
        float cr, ci, e, num, a, b;
        // Keep the center-sample addresses and scan cursors in the same registers.
        register float *pr asm("$6");
        register float *pi asm("$7");
        register int j asm("$5");
        int w;
        register int c asm("$3");
        pos += istep;
        j = end;
        c = (pos + 0x4000) >> 15;
        w = (j << 5) - ((pos + 0x200) >> 10);
        pr = (float*)((int)re + (c << 2));
        pi = (float*)((int)im + (c << 2));
        cr = *pr;
        ci = *pi;
        pr = (float*)((int)re + (j << 2));
        pi = (float*)((int)im + (j << 2));
        e = 1e-16f;
        end = (pos + (istep >> 1) + 0x4000) >> 15;
        while (w < -111) {
            a = *pr++;
            b = *pi++;
            w += 32;
            j++;
            e += a * a + b * b;
        }
        num = e;
        while (w < 112 && j < end) {
            float t = tab[w];
            a = *pr++;
            b = *pi++;
            w += 32;
            j++;
            e += a * a + b * b;
            num += (a - cr * t) * (a - cr * t) + (b - ci * t) * (b - ci * t);
        }
        // The tail scans the remaining samples with a countdown cursor.
        if (j < end) {
            register int rem asm("$5") = end - j;
            do {
            register float x asm("$f0");
            a = *pr++;
            b = *pi++;
            rem--;
            x = a * a + b * b;
            e += x;
            num += x;
            } while (rem);
        }
        sum += num / e;
    }
    return 1.0f - sum / (float)count;
}
