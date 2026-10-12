#include "types.h"
typedef struct { char pad[0x7C]; float angle; char pad80[0x4E0 - 0x80]; float speed; } S362D00;
extern void func_0041E3B0(S362D00* self, float dt);
#pragma opt_propagation off
void func_00362D00(S362D00* self, float dt) {
    func_0041E3B0(self, dt);
    self->angle += 3.1415927f * (dt / 30.0f) * self->speed;
    if (self->angle > 3.1415927f) self->angle -= 6.2831855f;
    else if (self->angle < -3.1415927f) self->angle += 6.2831855f;
}
