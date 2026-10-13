typedef struct TdxMgr {
    char pad0[8];
    __int128** names;
    char pad0c[4];
    int count;
} TdxMgr;

static inline int qeq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}

int func_00381F30(TdxMgr* m, __int128 key)
{
    int i;
    int idx = -1;
    i = 0;
    if (i < m->count) do {
        if (m->names[i] && qeq(key, *m->names[i])) break;
        i++;
    } while (i < *(volatile int*)&m->count);
    if (i < m->count) idx = i;
    return idx;
}
