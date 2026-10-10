#include "types.h"

typedef struct Angles {
    char pad[0x18];
    float pitch;
    float yaw;
} Angles;

typedef struct AngleOwner {
    char pad[0x6C];
    Angles* angles;
} AngleOwner;

/* Stores two angles given in degrees as radians into the attached angle block. */
void func_002853B0(AngleOwner* self, float pitchDeg, float yawDeg) {
    Angles* angles = self->angles;
    if (angles) {
        angles->pitch = 0.017453292f * pitchDeg;
        angles->yaw = 0.017453292f * yawDeg;
    }
}
