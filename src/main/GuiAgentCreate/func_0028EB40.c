extern int g_Pad0HeldMask;

typedef struct {
    char pad0[0xAC];
    float angle;
    char padD0[0xC0 - 0xB0];
    int locked;
} Obj;

#pragma push
#pragma opt_propagation off
void func_0028EB40(Obj *o, float dt)
{
    int flags = g_Pad0HeldMask;
    float step = 3.1415927f * (dt / 30.0f);
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
