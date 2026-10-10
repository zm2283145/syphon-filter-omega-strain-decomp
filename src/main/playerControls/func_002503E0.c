#include "types.h"
typedef struct { float x, y, z; } E7V3;
typedef struct { float x, y; } E7V2;
extern float D_0048AE78;
extern float D_0048AE70;
void PlayerInput_GetLookOffset(E7V3* out, E7V2* in, int invX, int invY) {
    float a, b, x, y, z;
    a = 0.017453292f * D_0048AE78;
    x = in->x;
    b = 0.017453292f * D_0048AE70;
    z = (invX ? -1.0f : 1.0f) * (a * -x);
    y = in->y;
    out->x = (invY ? -1.0f : 1.0f) * (b * -y);
    out->y = 0.0f;
    out->z = z;
}
