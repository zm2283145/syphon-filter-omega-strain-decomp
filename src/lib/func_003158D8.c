typedef struct {
    char pad0[0xFC];
    int ids[0x40];
    char pad1FC[0x208 - 0x1FC];
    unsigned char state;
    char pad209[7];
    unsigned int idx;
    int x214;
} Obj58D8;
extern int func_003150D0(int id, Obj58D8 **out);
int func_003158D8(int id, int unused, unsigned short *msg)
{
    Obj58D8 *o = 0;
    Obj58D8 *p;
    unsigned int i;
    if (msg == 0) return 0;
    if (func_003150D0(id, &o) != 0) return 0;
    p = o;
    i = p->idx;
    if (i >= 0x40) return 0;
    if (p->state != 1) return 1;
    if (p->ids[i] == msg[0]) {
        p->x214 = msg[1];
        p->state = 0;
        return 0;
    }
    return 1;
}

