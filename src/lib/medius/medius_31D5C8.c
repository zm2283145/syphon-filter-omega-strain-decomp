extern float func_0031D558(float x);
void func_0031D5C8(float *in, int n, float *out, float scale)
{
    float prev, x, y;
    prev = *in++ * scale; *out++ = func_0031D558(prev); n--; while (n-- > 0) {
        x = *in++ * scale;
        if (x != prev) y = func_0031D558(x);
        else y = out[-1];
        prev = x;
        *out++ = y;
    }
}
