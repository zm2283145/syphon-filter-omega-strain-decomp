int func_00319C28(float *t, int n, float x)
{
    int best = 0;
    int i;
    float d;
    float bd = x - t[0];
    bd = bd * bd;
    for (i = 1; i < n; i++) {
        d = (x - t[i]) * (x - t[i]);
        if (d < bd) { bd = d; best = i; }
    }
    return best;
}