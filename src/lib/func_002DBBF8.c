typedef struct {
    char pad0[0x14];
    enum { S0, S1, S2, S3, S4, S5 } state;
    char pad18[0x24 - 0x18];
    int f24;
} Player;

typedef struct {
    unsigned int slot;
    int id;
    int ctx;
} Msg;

extern void (*D_0048C488)(Msg *);
extern int D_0048C48C;
extern int func_002E6088(int);
extern int func_002E52D8(unsigned int, int, Player **);
extern int func_002E5550(unsigned int, int);

int func_002DBBF8(unsigned int slot, int self, int *out)
{
    Msg m;
    Player *pl = 0;
    int best = 0x0FFFFFFF;
    int i;
    int r, t;
    if (slot >= 4)
        return 0x17;
    if (func_002E6088(self) != 1)
        return 0x17;
    if (out == 0)
        return 0x17;
    *out = 0x100;
    for (i = 0; i < 0x100; i++) {
        if (self == i)
            continue;
        r = func_002E52D8(slot, i, &pl);
        if (r)
            return r;
        if (pl && pl->state == 4 && (t = pl->f24) > 0 && t < best) {
            *out = i;
            best = t;
        }
    }
    if (*out != 0x100) {
        r = func_002E52D8(slot, *out, &pl);
        if (r)
            return r;
        if (pl == 0)
            return 0;
        pl->state = 5;
        func_002E5550(slot, *out);
        if (D_0048C488) {
            m.slot = slot;
            m.id = *out;
            m.ctx = D_0048C48C;
            D_0048C488(&m);
        }
    }
    return 0;
}



