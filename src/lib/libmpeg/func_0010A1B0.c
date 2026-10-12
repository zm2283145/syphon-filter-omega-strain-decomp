typedef struct {
    unsigned long code;
    unsigned long mask;
} VlcEnt;

extern VlcEnt D_00485FB0[];

int func_0010A1B0(int *idx, int *val, unsigned long x)
{
    VlcEnt *e = D_00485FB0;
    int found = 0;
    unsigned int i = 0;
    unsigned long t;
    unsigned long bits;

    for (; i < 10 && !found; i++, e++) {
        switch (e->mask) {
        case 0xFFFFFFFFFF:
            t = x & 0xFFFFFF0000;
            if (t == e->code) {
                *idx = i;
                *val = (int)(x & 0xFFFF);
                found = 1;
            }
            break;
        case 0xFFFF000000:
            switch (e->code) {
            case 0xBD20000000:
                t = x & 0xFFE0000000;
                bits = 0x1F;
                break;
            case 0xBD80000000:
            case 0xBD88000000:
            case 0xBD90000000:
            case 0xBDA0000000:
                t = x & 0xFFF8000000;
                bits = 7;
                break;
            default:
                t = x & 0xFFFF000000;
                bits = 0;
                break;
            }
            if (t == e->code) {
                *idx = i;
                *val = (x >> 24) & bits;
                found = 1;
            }
            break;
        case 0xFF00000000:
            if (e->code == 0xE000000000) {
                t = x & 0xF000000000;
                bits = 0xF;
            } else if (e->code == 0xC000000000) {
                t = x & 0xE000000000;
                bits = 0x1F;
            } else {
                t = x & e->mask;
                bits = 0;
            }
            if (t == e->code) {
                *idx = i;
                *val = (x >> 32) & bits;
                found = 1;
            }
            break;
        }
    }
    return found;
}

