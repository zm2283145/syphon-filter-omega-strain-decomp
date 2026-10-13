float func_003236D8(float);
void func_00322168(int n, float *a, float *b, float x, float y)
{
    int i;
    int k = (int)(y * 0.1875f);
    float acc = x;
    float c = 0.31830987334251404f;
    for (i = 0; i < n; i++) {
        float t = a[i] + acc;
        acc += x;
        a[i] = t;
        if (i >= k) c += 0.01591549255f;
        if (!(i & 1)) a[i] = t + c;
        b[i] = func_003236D8(b[i]);
    }
}
