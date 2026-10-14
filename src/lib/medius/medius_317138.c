extern float D_004B36D0[];
extern float func_00319C88(float *tbl, int n, int idx, float x);
void func_00317138(int v, float *a, float *b, float x)
{
    int hi = v & 8;
    float r = func_00319C88(D_004B36D0, 8, v - hi, x);
    *b = r;
    if (hi == 0) *a = x;
    else *a = r;
}
