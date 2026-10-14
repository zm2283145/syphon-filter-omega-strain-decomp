typedef struct { int floor; } St_00213FE0;
typedef struct { char pad0[0x68]; int x68; char pad6C[0x98 - 0x6C]; int x98; char pad9C[0xD0 - 0x9C]; int* xD0; char padD4[0xDC - 0xD4]; unsigned char xDC; } Door_00213FE0;
typedef struct { char pad0[0xEC]; int nDoors; Door_00213FE0** doors; char padF4[0x128 - 0xF4]; St_00213FE0* st; } Lift_00213FE0;
#pragma opt_strength_reduction off
#pragma opt_unroll_loops off
unsigned char func_00213FE0(Lift_00213FE0* l)
{
    int i;
    int floor = l->st->floor;
    unsigned char r = 1;
    if (floor < 0)
        return 0;
    floor = floor * 2;
    i = floor;
    floor++;
    for (; i < l->nDoors && i <= floor; i++) {
        Door_00213FE0* d = l->doors[i];
        if (d->x68 == 2) {
            int f = d->x98 - 1;
            if (!d->xDC || f != *d->xD0) {
                r = 0; break; }
        }
    }
    return r;
}
