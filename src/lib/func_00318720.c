extern float D_004B3A90[8];
extern float D_004B3AB0[6];
extern float D_004B3AC8[6][6];
float powerpoly_125(float x)
{
    float v[1];
    float *p;
    float r;
    int i;
    v[0] = x;
    if (x <= D_004B3A90[6])
        v[0] = D_004B3A90[6];
    if (v[0] > D_004B3A90[3]) {
        if (v[0] > D_004B3A90[2]) {
            if (v[0] > D_004B3A90[1])
                i = 0;
            else
                i = 1;
        } else
            i = 2;
    } else {
        if (v[0] <= D_004B3A90[4]) {
            if (v[0] <= D_004B3A90[5])
                i = 5;
            else
                i = 4;
        } else
            i = 3;
    }
    v[0] = v[0] * D_004B3AB0[i];
    p = D_004B3AC8[i];
    { float c0 = *p++, c1 = *p++, c2 = *p++, c3 = *p++, c4 = *p++, c5 = *p;
    r = ((((c0 * v[0] + c1) * v[0] + c2) * v[0] + c3) * v[0] + c4) * v[0] + c5; }
    return r;
}
