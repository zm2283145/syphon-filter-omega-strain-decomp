/* volatile on D_004E1C64 keeps reorg from hoisting its load into the shared bc1f delay slot (retail loads it in each branch). */
extern volatile float D_004E1C64;
extern float D_004E1C68;
extern float D_004E1C6C;
extern float Math_Powf(float, float);
typedef struct { int pad0; float y; } S;

short nemAgcCalc(S* s, short h)
{
    float d, e, r;
    int v = (h > 0) ? h : 0xB0;

    d = (float)v - s->y;
    if (d <= 16.0f && d >= -16.0f)
        e = 0.0f;
    else if (d < -16.0f)
        e = d + 16.0f;
    else
        e = d - 16.0f;
    if (e == 0.0f)
        return 0;
    if (e < 0.0f) {
        r = -Math_Powf(10.0f, -e * D_004E1C64);
        if (r < D_004E1C68)
            r = D_004E1C68;
        return (short)(int)((r + 1.0f) * 4000.0f);
    } else {
        r = Math_Powf(10.0f, e * D_004E1C64);
        if (D_004E1C6C < r)
            r = D_004E1C6C;
        return (short)(int)((r - 1.0f) * 4000.0f);
    }
}

