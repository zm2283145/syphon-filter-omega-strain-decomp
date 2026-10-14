float func_00323660(float);


void func_00317D08(float* out, int count, float step)
{
    float buf[328];
    float* vals;
    float* pos;
    int* idx;
    int last = count - 1;
    int n;
    int i;
    float t;
    n = (int)((float)last / step);
    n++;
    if (n > 80) n = 80;
    vals = buf;
    pos = &buf[n + 4];
    idx = (int*)&buf[(n + 4) * 2];
    t = 0.0f;
    for (i = 0; i < n; i++) {
        int k = (int)(t + 0.5f);
        vals[i] = func_00323660(out[k]);
        idx[i] = k;
        pos[i] = t;
        t += step;
    }
    vals[n] = func_00323660(out[count - 1]);
    idx[n] = count;
    pos[n] = (float)(count - 1);
    for (i = 1; i < n + 1; i++) {
        int j;
        for (j = idx[i - 1]; j < idx[i]; j++) {
            out[j] = vals[i - 1] + (vals[i] - vals[i - 1]) * ((float)j - pos[i - 1]) / (pos[i] - pos[i - 1]);
        }
    }
}