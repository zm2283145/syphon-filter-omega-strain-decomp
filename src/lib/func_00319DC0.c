extern float D_004E1BF8;
extern float D_004E1BFC;
extern void func_00319E00(int a, float x, float y);
void func_00319DC0(int a, int n)
{
    float s = 2.0f / (float)n;
    func_00319E00(a, s * D_004E1BF8, s * D_004E1BFC);
}
