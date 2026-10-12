const float D_004B36D0[8] = { 0.0f, 0.142999992f, 0.28599999f, 0.429f, 0.571f, 0.714f, 0.857f, 1.0f };
int func_003170A8(float a, float b, float c)
{
    int hi = 0, best = 0, i;
    float bd = c - ((float*)D_004B36D0)[0];
    bd = bd * bd;
    for (i = 1; i < 8; i++) {
        float d = c - ((float*)D_004B36D0)[i];
        d = d * d;
        if (d < bd) { bd = d; best = i; }
    }
    if ((((float*)D_004B36D0)[best] - b) * (((float*)D_004B36D0)[best] - b) < (a - b) * (a - b)) hi = 1;
    return best + hi * 8;
}