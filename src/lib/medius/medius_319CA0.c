static const float dat_004E1D20[1] = { 1e+38f };
int func_00319CA0(float *p, float *pts, int n)
{
    int best = 0;
    int i;
    float d, dx, dy;
    float bd = (*(float*)dat_004E1D20);
    for (i = 0; i < n; i++) {
        dx = *pts++ - p[0];
        d = dx * dx;
        dx = *pts++ - p[1];
        d += dx * dx;
        if (d < bd) { bd = d; best = i; }
    }
    return best;
}