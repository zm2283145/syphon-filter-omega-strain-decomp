extern float D_004B35D0[64];
int func_00317020(float x)
{
    int best = 0;
    int i;
    float d;
    float bd = x - D_004B35D0[0];
    bd = bd * bd;
    for (i = 1; i < 64; i++) {
        d = (x - D_004B35D0[i]) * (x - D_004B35D0[i]);
        if (d < bd) { bd = d; best = i; }
    }
    return best;
}