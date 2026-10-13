extern float D_004E1C8C;
extern float D_004E1C90;
extern float D_004E1C94;
extern float D_004B3968[];
extern void func_0031BB28(float *x, int start, int *pos, float *val);

int func_0031CC50(float *x, int *out, int *best)
{
    int pos;
    float val;
    float prev = -1.0f;
    int n = 0;
    int b = 0;
    int lag = 0x49;
    float thr;

    while (n < 5) {
        func_0031BB28(x, lag + 1, &pos, &val);
        if (val < prev * D_004E1C8C)
            break;
        {
            float t = prev * D_004E1C90;
            *out = pos;
            if (t <= val)
                b = n;
        }
        lag = pos;
        out++;
        n++;
        prev = val;
        thr = D_004B3968[lag] * D_004E1C94;
        if (thr < D_004B3968[0])
            break;
        while (thr < D_004B3968[lag])
            lag--;
        while (lag >= 0 && x[lag] < x[lag + 1])
            lag--;
        if (lag < 0)
            break;
    }
    *best = b;
    return n;
}




