typedef struct { float x, y, z; } Vec3;
static inline float WrapPi(float a)
{
    for (;;) {
        if (a > 3.1415927f) { a += -6.2831855f; continue; }
        if (a < -3.1415927f) { a += 6.2831855f; continue; }
        break;
    }
    return a;
}
void func_0024FDE0(Vec3* out, Vec3* in)
{
    float x = WrapPi(in->x);
    float y = WrapPi(in->y);
    float z = WrapPi(in->z);
    out->x = x;
    out->y = y;
    out->z = z;
}
