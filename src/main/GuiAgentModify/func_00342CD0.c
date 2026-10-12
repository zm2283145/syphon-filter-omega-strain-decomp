extern int D_0055A44C;

typedef struct {
    char pad0[0xCC];
    float angle;
    char padD0[0xE0 - 0xD0];
    int locked;
} Obj;

void func_0041E3B0(Obj *o, float dt);

#pragma push
#pragma opt_propagation off
void func_00342CD0(Obj *o, float dt)
{
    int flags;
    float step;
    func_0041E3B0(o, dt);
    flags = D_0055A44C;
    step = 3.1415927f * (dt / 30.0f);
    if (o->locked == 0) {
        if (flags & 1) {
            o->angle += step;
            if (o->angle > 3.1415927f) {
                o->angle -= 6.2831855f;
            }
        }
        if (flags & 2) {
            o->angle -= step;
            if (o->angle < -3.1415927f) {
                o->angle += 6.2831855f;
            }
        }
    }
}
#pragma pop
