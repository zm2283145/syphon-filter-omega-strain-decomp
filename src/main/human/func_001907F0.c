#include "types.h"

typedef struct Quat {
    float x, y, z, w;
} Quat;

extern float Math_Cos(float); /* Math_Cos */
extern float Math_Sin(float); /* Math_Sin */

/* Builds a quaternion from an axis (xyz) and angle (w). */
Quat* Quat_FromYaw(Quat* q, Quat* axisAngle) {
    float half = 0.5f * axisAngle->w;
    float c;
    float s;
    c = Math_Cos(half); /* cos */
    s = Math_Sin(half); /* sin */
    q->w = c;
    q->x = s * axisAngle->x;
    q->y = s * axisAngle->y;
    q->z = s * axisAngle->z;
    return q;
}
