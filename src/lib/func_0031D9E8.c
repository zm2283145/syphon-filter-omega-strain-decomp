extern float func_00121B18(float x);
float func_0031D9E8(float lo, float hi, float p)
{
    float v;
    float r;
    if (p <= 0.0f) p = 0x1.0c6f7ap-20f;
    if (p >= 1.0f) p = 0x1.ffffdep-1f;
    v = func_00121B18(1.0f - p) * -10.0f;
    if (v < lo) r = 0.0f;
    else if (v > hi) r = 1.0f;
    else r = (v - lo) / (hi - lo);
    return r;
}
