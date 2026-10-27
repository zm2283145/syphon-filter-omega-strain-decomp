static inline float FABS(float x) { float r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
extern float Libc_Tanf(float x);
void BuildProjection(float m[4][4], float* lo, float* hi, float fov, float x0, float x1, float y0, float y1, float zn, float zf, float aspect, float ay, float depth)
{
    float ta = Libc_Tanf(fov);
    float tb = Libc_Tanf(fov);
    float h;
    float w;
    m[0][0] = (2.0f * zn) / (aspect * ((2.0f * zn) * ta));
    m[1][0] = 0.0f;
    m[2][0] = 0.0f;
    m[3][0] = 0.0f;
    m[0][1] = 0.0f;
    m[1][1] = (2.0f * zn) / (ay * ((2.0f * zn) * tb));
    m[2][1] = 0.0f;
    m[3][1] = 0.0f;
    m[0][2] = 0.0f;
    m[1][2] = 0.0f;
    m[2][2] = (zf + zn) / (zf - zn);
    m[3][2] = -(2.0f * zf * zn) / (zf - zn);
    m[0][3] = 0.0f;
    m[1][3] = 0.0f;
    m[2][3] = 1.0f;
    m[3][3] = 0.0f;
    w = FABS(x1 - x0); h = FABS(y1 - y0);
    lo[0] = 0.5f * w;
    lo[1] = 0.5f * -h;
    lo[2] = -64.0f;
    lo[3] = 1.0f;
    hi[0] = 0.5f * w;
    hi[1] = 0.5f * h;
    hi[2] = 64.0f;
    hi[3] = 0.0f;
    if (depth > 0.0f) {
        lo[2] = 0.0f;
        hi[2] = 128.0f * depth;
    }
}





