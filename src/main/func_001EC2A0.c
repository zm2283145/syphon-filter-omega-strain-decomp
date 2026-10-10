#include "types.h"
typedef struct { float mass; float invMass; } PhysMass_b6;
void PhysState_SetMass(PhysMass_b6* p, float m)
{
    if (m == -1.0f || m > 0.0f) {
        float inv;
        p->mass = m;
        if (m == -1.0f) {
            inv = 0.0f;
        } else {
            inv = 1.0f / m;
        }
        p->invMass = inv;
    }
}