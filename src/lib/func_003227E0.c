extern float D_004B64C0[];
extern float D_004B6640[];
extern void func_00322738(float *re, float *im, int n);
void func_003227E0(float *re, float *im, int n)
{
    int nb = 1;
    float *tw;
    float *pr, *pi;
    int q, b, k, j;
    float r0, r1, r2, r3, i0, i1, i2, i3;
    float rs02, rs13, rd02, rd13, is02, is13, id02, id13;
    float a, c, d, e, f, g;
    float c1, s1, c2, s2, c3, s3;
    if (n == 256)
        tw = D_004B64C0;
    else
        tw = D_004B6640;
    do {
        q = n >> 2;
        pr = re + q * (nb * 4 - 4) + q - 4;
        pi = im + q * (nb * 4 - 4) + q - 4;
        for (b = 0; b < nb; b++) {
            tw -= (n >> 4) * 24;
            for (k = q - 4; k >= 0; k -= 4) {
                for (j = 0; j < 4; j++) {
                    r0 = pr[j]; r1 = pr[q + j]; r2 = pr[2 * q + j]; r3 = pr[3 * q + j];
                    i0 = pi[j]; i1 = pi[q + j]; i2 = pi[2 * q + j]; i3 = pi[3 * q + j];
                    rs02 = r0 + r2; rd02 = r0 - r2; rs13 = r1 + r3; rd13 = r1 - r3;
                    is02 = i0 + i2; id02 = i0 - i2; is13 = i1 + i3; id13 = i1 - i3;
                    c1 = tw[0]; s1 = tw[4]; c2 = tw[8]; s2 = tw[12]; c3 = tw[16]; s3 = tw[20];
                    a = rs02 - rs13; c = is02 - is13;
                    d = rd02 + id13; e = id02 - rd13;
                    f = rd02 - id13; g = id02 + rd13;
                    pr[j] = rs02 + rs13;
                    pi[j] = is02 + is13;
                    pr[q + j] = a * c1 - c * s1;
                    pi[q + j] = c * c1 + a * s1;
                    pr[2 * q + j] = d * c2 - e * s2;
                    pi[2 * q + j] = e * c2 + d * s2;
                    pr[3 * q + j] = f * c3 - g * s3;
                    pi[3 * q + j] = g * c3 + f * s3;
                    tw++;
                }
                pr -= 4;
                pi -= 4;
                tw += 20;
            }
            pr -= 3 * q;
            pi -= 3 * q;
        }
        n /= 4;
        nb *= 4;
        tw += (n >> 4) * 24;
    } while (n > 4);
    pr = re + nb * 4 - 4;
    pi = im + nb * 4 - 4;
    for (b = 0; b < nb; b++) {
        r0 = pr[0]; r1 = pr[1]; r2 = pr[2]; r3 = pr[3];
        i0 = pi[0]; i1 = pi[1]; i2 = pi[2]; i3 = pi[3];
        rs02 = r0 + r2; rd02 = r0 - r2; rs13 = r1 + r3; rd13 = r1 - r3;
        is02 = i0 + i2; id02 = i0 - i2; is13 = i1 + i3; id13 = i1 - i3;
        pr[0] = rs02 + rs13;
        pi[0] = is02 + is13;
        pr[2] = rd02 + id13;
        pi[2] = id02 - rd13;
        pr[1] = rs02 - rs13;
        pi[1] = is02 - is13;
        pr[3] = rd02 - id13;
        pi[3] = id02 + rd13;
        pr -= 4;
        pi -= 4;
    }
    func_00322738(re, im, nb * 4);
}



