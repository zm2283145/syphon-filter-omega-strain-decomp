extern float* D_004E1D28;
extern float* D_004E1D24;
void Unpack(float* a, int bits)
{
    int n = 1 << bits;
    int h = n >> 1;
    float* sn;
    float* cs;
    unsigned int step;
    int i;
    float p0, p1, q0, q1, dr, si, sr, di, s, c, x, y;
    x = a[0] - a[1];
    y = a[0] + a[1];
    a[n] = x;
    a[0] = y;
    a[n + 1] = 0.0f;
    a[1] = 0.0f;
    step = 512u >> bits;
    sn = D_004E1D28;
    cs = D_004E1D24;
    for (i = 2; i < h; i += 2) {
        sn -= step;
        cs += step;
        q0 = a[n - i];
        p0 = a[i];
        p1 = a[i + 1];
        q1 = a[n - i + 1];
        dr = p0 - q0;
        si = p1 + q1;
        sr = p0 + q0;
        di = p1 - q1;
        dr *= 0.5f;
        si *= 0.5f;
        sr *= 0.5f;
        di *= 0.5f;
        s = *sn;
        c = *cs;
        x = s * si - c * dr;
        y = s * dr + c * si;
        a[i] = sr + x;
        a[n - i] = sr - x;
        x = di - y;
        y = y + di;
        a[i + 1] = x;
        a[n - i + 1] = -y;
    }
    a[i + 1] = -a[i + 1];
}
