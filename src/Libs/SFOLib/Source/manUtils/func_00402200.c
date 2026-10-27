typedef struct {
    char pad0[0x30];
    __int128 m30;
    char pad40[0x10];
    __int128 m50;
    char pad60[0x10];
    __int128 m70;
    char pad80[0x40];
    unsigned int count;
    char padC4[0x2C10 - 0xC4];
    __int128 keys[1];
} KS00402200;
static inline int ks00402200eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
static inline __int128 ks00402200and(__int128 a, __int128 b) {
    __int128 r;
    asm { pand r, a, b }
    return r;
}
static inline __int128 ks00402200or(__int128 a, __int128 b) {
    __int128 r;
    asm { por r, a, b }
    return r;
}
static inline __int128 ks00402200from(__int128 v) {
    __int128 r;
    asm { pcpyld r, zero, v }
    return r;
}
static inline int ks00402200meq(__int128 m, __int128 a, __int128 b) {
    return ks00402200eq(ks00402200and(m, a), ks00402200and(m, b));
}
int Monster_CountPartsByName(KS00402200* s, __int128 key, int* out, int mode, __int128 cmp)
{
    __int128 mask = s->m50;
    unsigned int i;
    int n = 0;
    if (cmp)
        mask = ks00402200or(s->m70, mask);
    if (mode == 1)
        cmp = ks00402200from(50);
    if (mode == 0)
        cmp = ks00402200from(49);
    for (i = 0; i < s->count; i++) {
        if (!ks00402200meq(s->m30, s->keys[i], cmp)
            && ks00402200meq(mask, s->keys[i], key)) {
            if (ks00402200eq(key, s->keys[i]))
                *out = n;
            n++;
        }
    }
    return n;
}

