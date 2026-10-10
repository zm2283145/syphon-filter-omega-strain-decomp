#include "types.h"

typedef struct { float x, y; } Vec2;
typedef struct { char pad[0x12C]; char left[8]; char right[8]; } Pad;
extern void Pad_GetStickDeadzone(Vec2* out, Pad* pad, void* stick, int deadzone);

/* Reads both analog sticks of the pad into *left and *right. */
void Pad_GetSticks(Pad* self, Vec2* left, Vec2* right, int deadzone)
{
    Vec2 r;
    Vec2 l;
    Pad_GetStickDeadzone(&l, self, self->left, deadzone);
    left->x = l.x;
    left->y = l.y;
    Pad_GetStickDeadzone(&r, self, self->right, deadzone);
    right->x = r.x;
    right->y = r.y;
}
