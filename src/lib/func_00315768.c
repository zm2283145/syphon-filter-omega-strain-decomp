typedef struct {
    char pad0[0x18];
    unsigned int count;
    char pad1[0xFC - 0x1C];
    int ids[1];
} Obj5768;
extern int func_00314FE0(Obj5768 *o);
int func_00315768(Obj5768 *o, int id, unsigned int *out)
{
    unsigned int i;
    if (func_00314FE0(o) != 1) return 0x17;
    if (out == 0) return 0x17;
    for (i = 0; i < o->count; i++) {
        if (id == o->ids[i]) {
            *out = i;
            return 0;
        }
    }
    return 0x29;
}

