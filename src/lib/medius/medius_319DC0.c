extern float D_004E1BF8;
extern float D_004E1BFC;
extern void WindowKernel(int a, float x, float y);
void HammingWindowNormSC(int a, int n)
{
    float s = 2.0f / (float)n;
    WindowKernel(a, s * D_004E1BF8, s * D_004E1BFC);
}
