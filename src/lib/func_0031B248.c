/* the codec's butterfly outputs live in fixed FP regs (global register vars keep the dead-looking copies alive) */
register float g2 asm("$f2"), g4 asm("$f4"), g6 asm("$f6"), g7 asm("$f7");
extern float* D_004E1D24;
extern float* D_004E1D28;

void Fft(float* data, int bits)
{
    int n = 1 << bits;
    int i, j, k, s, m, step, cnt;
    float* p;
    float *pi, *qr, *qi;
    float* cs;
    float* sn;

    p = data;
    for (i = n >> 1; i > 0; i--) {
        register float a asm("$f3"), b asm("$f1"), c asm("$f0");
        pi = p + 1; qr = p + 2; qi = p + 3;
        a = *p; b = *qr; g2 = *pi; c = *qi;
        g4 = a - b;
        g7 = a + b;
        g6 = g2 + c;
        g2 = g2 - c;
        *qr = g4;
        *p = g7;
        *qi = g2;
        *pi = g6;
        p += 4;
    }
    p = data;
    for (i = n >> 2; i > 0; i--) {
        register float a asm("$f3"), b asm("$f1"), c asm("$f0");
        pi = p + 1; qr = p + 4; qi = p + 5;
        a = *p; b = *qr; g2 = *pi; c = *qi;
        g4 = a - b;
        g7 = a + b;
        g6 = g2 + c;
        g2 = g2 - c;
        *qr = g4;
        *p = g7;
        *qi = g2;
        *pi = g6;
        p += 2;
        pi = p + 1; qr = p + 4; qi = p + 5;
        g2 = *p; c = *qi; a = *pi; b = *qr;
        g4 = g2 - c;
        g7 = g2 + c;
        g6 = a - b;
        g2 = a + b;
        *qr = g4;
        *p = g7;
        *qi = g2;
        *pi = g6;
        p += 6;
    }
    cnt = n >> 3;
    step = 0x40;
    m = 4;
    sn = D_004E1D28;
    k = 0;
    cs = D_004E1D24;
    if (bits >= 3) {
        s = bits - 2;
        do {
            p = data;
            for (j = 0; j < cnt; j++) {
                    for (i = m >> 1; i > 0; i--) {
                        register float c1 asm("$f4"), d1 asm("$f6"), x1 asm("$f3"), y1 asm("$f0");
                        register float x0 asm("$f5"), y0 asm("$f2"), tr asm("$f7"), ti asm("$f4");
                        register float p2 asm("$f1"), p3 asm("$f0");
                        qr = p + m * 2; qi = qr + 1; pi = p + 1;
                        d1 = sn[-k]; c1 = cs[k];
                        k += step;
                        x1 = *qr; y1 = *qi;
                        tr = x1 * c1;
                        p2 = y1 * d1;
                        p3 = y1 * c1;
                        ti = x1 * d1;
                        tr = tr - p2;
                        ti = ti + p3;
                        x0 = *p; y0 = *pi;
                        g6 = y0 + tr;
                        g7 = y0 - tr;
                        g2 = x0 - ti;
                        g4 = ti + x0;
                        *qr = g2;
                        *p = g4;
                        *qi = g6;
                        *pi = g7;
                        p += 2;
                    }
                    for (i = m >> 1; i > 0; i--) {
                        register float c1 asm("$f4"), d1 asm("$f6"), x1 asm("$f3"), y1 asm("$f0");
                        register float x0 asm("$f5"), y0 asm("$f2"), tr asm("$f7"), ti asm("$f4");
                        register float p2 asm("$f1"), p3 asm("$f0");
                        qr = p + m * 2; qi = qr + 1; pi = p + 1;
                        d1 = sn[-k]; c1 = cs[k];
                        k -= step;
                        x1 = *qr; y1 = *qi;
                        tr = x1 * c1;
                        p2 = y1 * d1;
                        p3 = y1 * c1;
                        ti = x1 * d1;
                        tr = tr + p2;
                        ti = ti - p3;
                        x0 = *p; y0 = *pi;
                        g6 = y0 + tr;
                        g7 = y0 - tr;
                        g2 = x0 + ti;
                        g4 = x0 - ti;
                        *qr = g2;
                        *p = g4;
                        *qi = g6;
                        *pi = g7;
                        p += 2;
                    }
                p += m * 2;
            }
            m *= 2;
            step >>= 1;
            cnt >>= 1;
        } while (--s != 0);
    }
}
