extern int g_Pad0HeldMask;
extern unsigned char D_004FFBB8;

typedef struct {
    char pad0[0x59D];
    unsigned char flag;
} Game59D;
extern Game59D *g_MemCard;

typedef struct {
    char pad0[0xAC];
    float angle;
    char padD0[0xC0 - 0xB0];
    int locked;
} Obj;

void GuiWidget_onAdvanceTime(Obj *o, float dt);

#pragma push
#pragma opt_propagation off
void GuiAgentCreate_onAdvanceTime(Obj *o, float dt)
{
    int flags;
    float step;
    GuiWidget_onAdvanceTime(o, dt);
    flags = g_Pad0HeldMask;
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
    D_004FFBB8 = g_MemCard->flag != 0;
}
#pragma pop
