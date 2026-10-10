#include "types.h"
typedef struct {
    char pad[0x150];
    float fogNear;
    float fogFar;
    float zNear;
    float zFar;
    char pad2[0x20];
    float a180;
    char pad3[0xC];
    float a190;
    char pad4[0xC];
    float q1A0;
    float q1A4;
    float q1A8;
    float q1AC;
} F6Fog;
void func_001339B0(F6Fog* r)
{
    float a = 255.0f * (1.0f - r->fogNear);
    float b = 255.0f * (1.0f - r->fogFar);
    r->a180 = ((a + b) + (b - a) * (r->zFar + r->zNear) / (r->zFar - r->zNear)) / 2.0f;
    r->a190 = r->zFar * r->zNear * (a - b) / (r->zFar - r->zNear);
    {
        float n;
        float f;
        float d1;
        float d0;
        float dz;
        n = r->zNear;
        f = r->zFar;
        d0 = r->fogNear;
        d1 = r->fogFar;
        r->q1A0 = 8388608.0f + 16.0f * r->a180;
        dz = f - n;
        r->q1A4 = ((d0 + d1) + (d1 - d0) * (f + n) / dz) / 2.0f - 1.0f;
        r->q1A8 = f * n * (d0 - d1) / dz;
    }
    r->q1AC = 16.0f * r->a190;
}