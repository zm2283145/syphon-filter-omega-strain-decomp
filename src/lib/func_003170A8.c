extern float D_004B36D0[8];
int func_003170A8(float a, float b, float c)
{
    int hi = 0, best = 0, i;
    float bd = c - D_004B36D0[0];
    bd = bd * bd;
    for (i = 1; i < 8; i++) {
        float d = c - D_004B36D0[i];
        d = d * d;
        if (d < bd) { bd = d; best = i; }
    }
    if ((D_004B36D0[best] - b) * (D_004B36D0[best] - b) < (a - b) * (a - b)) hi = 1;
    return best + hi * 8;
}