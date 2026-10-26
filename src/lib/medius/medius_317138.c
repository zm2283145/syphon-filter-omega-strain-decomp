extern float D_004B36D0[];
extern float ScalarLUT(float *tbl, int n, int idx, float x);
void UnQuanPvSC3(int v, float *a, float *b, float x)
{
    int hi = v & 8;
    float r = ScalarLUT(D_004B36D0, 8, v - hi, x);
    *b = r;
    if (hi == 0) *a = x;
    else *a = r;
}
