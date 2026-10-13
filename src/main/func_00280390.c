typedef struct {
    char pad0[0x320C];
    int x320C;
    char pad3210[0x3248 - 0x3210];
    int x3248;
} O_280390;
void func_00280390(float* out, O_280390* o, signed char mode, int flag)
{
    switch (mode) {
    case 0:
        break;
    case 1:
        if (o->x320C == 16) {
            if ((o->x3248 >> 29) & 1)
                *out = -3.0f;
            else
                *out = -6.3f;
        } else if (flag) {
            *out = -0.5f;
        } else if (o->x320C == 1) {
            *out = -3.0f;
        } else if (o->x320C == 8 || o->x320C == 7) {
            *out = -7.0f;
        } else {
            return;
        }
        break;
    case 2:
        *out = -6.3f;
        break;
    case 3:
        break;
    }
}

