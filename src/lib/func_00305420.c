typedef struct { int state; char pad[0x24]; } Slot5420;
typedef struct { char pad[0x184]; Slot5420 *slots; int count; } Owner5420;
int func_00305420(Owner5420 *o, int *out)
{
    int i;
    if (out == 0) return 2;
    *out = -2;
    for (i = 0; i < o->count; i++) {
        if (o->slots[i].state == 3) {
            *out = i;
            o->slots[i].state = 4;
            break;
        }
        if (o->slots[i].state == 6) {
            *out = i;
            o->slots[i].state = 7;
            break;
        }
    }
    return 0;
}
