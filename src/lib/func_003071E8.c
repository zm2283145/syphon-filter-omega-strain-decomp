typedef struct {
    int type;
    char pad4[0x20];
    unsigned int total0;
    unsigned int used0;
    char pad2C[0x10];
    unsigned int total1;
    unsigned int used1;
    char pad44[0x90 - 0x44];
} Ent71e8;

typedef struct {
    int pad0;
    Ent71e8 *ents;
    char pad8[0x24];
    unsigned int count;
} Mgr71e8;

int func_003071E8(Mgr71e8 *m, unsigned int idx, int which,
                  unsigned int *total, unsigned int *used, unsigned int *pct)
{
    Ent71e8 *e;
    unsigned int v;

    if (m == 0) return 2;
    if (idx >= m->count) return 3;
    if (m->ents == 0) return 3;
    e = &m->ents[idx];
    if (e->type != 12) return 3;
    if (which == 0) {
        if (total != 0) *total = e->total0;
        if (used != 0) *used = e->used0;
        if (pct != 0) {
            v = e->used0 * 100 / e->total0;
            *pct = v;
            if (v > 100) *pct = 100;
        }
        return 0;
    }
    if (which == 1) {
        if (total != 0) *total = e->total1;
        if (used != 0) *used = e->used1;
        if (pct != 0) {
            v = e->used1 * 100 / e->total1;
            *pct = v;
            if (v > 100) *pct = 100;
        }
        return 0;
    }
    return 1;
}
