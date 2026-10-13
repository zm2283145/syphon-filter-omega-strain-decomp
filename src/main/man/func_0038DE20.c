extern char D_004BC3B0[];
extern unsigned int D_005712F0[];
extern __int128* D_005712F8[];
extern void String_Copy(void* d, const char* s);
static inline int ks0038DE20eq(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
static inline __int128 ks0038DE20and(__int128 a, __int128 b) {
    __int128 r;
    asm { pand r, a, b }
    return r;
}
static inline __int128 ks0038DE20from(__int128 v) {
    __int128 r;
    asm { pcpyld r, zero, v }
    return r;
}
static inline int ks0038DE20meq(__int128 m, __int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pand t, m, a
        pand b, m, b
        pceqw t, t, b
        ppach r, t, t
    }
    return r == -1;
}
int func_0038DE20(int idx)
{
    __int128 mask = ks0038DE20from(0xFFFFFFFFFFFFLL);
    __int128 key;
    __int128* e;
    unsigned int i;
    int n;
    String_Copy(&key, D_004BC3B0);
    e = D_005712F8[idx];
    n = 0;
    for (i = 0; i < D_005712F0[idx]; i++) {
        if (ks0038DE20meq(mask, key, e[i]))
            n++;
    }
    return n;
}



