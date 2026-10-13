#include "types.h"

typedef struct { char pad[0x22]; unsigned short count; } Clip;
typedef struct { char pad[0x44]; Clip* clip; char pad48[4]; int frame; char pad50[0x10]; unsigned char b60, b61; } Anim;
typedef struct { char pad[8]; Anim** anims; } AnimTbl;
typedef struct {
    int idx;
    char pad4[0x10];
    unsigned int range;
    int min;
    int max;
    int mode;
    float period;
    int value;
    int step;
    float timer;
} Seq;
extern AnimTbl* D_00539248;
int Random_Next(void);
static inline float RandF() { return (float)Random_Next() / 2147483648.0f; }

void func_003D1960(Seq* s, float dt)
{
    Anim* a;
    int v;
    s->timer += dt;
    if (!(s->timer <= s->period)) {
        s->timer -= s->period;
        s->value += s->step;
        switch (s->mode) {
        case 0:
            if (s->value > s->max) {
                s->value = s->max;
                s->step = 0;
            }
            break;
        case 1:
            if (s->value < s->min) {
                s->value = s->min;
                s->step = 0;
            }
            break;
        case 2:
            if (s->value > s->max)
                s->value = s->min;
            break;
        case 3:
            if (s->value < s->min)
                s->value = s->max;
            break;
        case 4:
            if (s->value < s->min || s->value > s->max) {
                s->step = -s->step;
                s->value += s->step;
            }
            break;
        case 5:
            { int r = Random_Next(); s->value = (int)((float)s->range * ((float)r / 2147483648.0f)); }
            break;
        }
    }
    { int i = s->idx; v = s->value; a = D_00539248->anims[i]; }
    if (v != a->frame && (unsigned int)v < a->clip->count) {
        a->b60 = 0;
        a->b61 = 0;
        a->frame = v;
    }
}