#pragma cplusplus on
#include "types.h"

struct Pair390570 {
    __int128 a;
    __int128 b;
};

struct Self390570 {
    char pad[0x80];
    Pair390570 pairs[0x20];
    char padX[0x22C0 - 0x80 - 0x20 * 0x20];
    short x22C0[0x20];
    short x2300[0x60];
    short x23C0;
    char pad23C2[0x2DB0 - 0x23C2];
    unsigned char x2DB0[0x20];
    unsigned char x2DD0[0x20];
};

struct Entry390570 {
    __int128 key;
    int val;
    char pad[0x1C];
};

struct Cache390570 {
    char pad[0x11C10];
    Entry390570 e[1];
};

extern "C" {
extern Cache390570 D_0055DDA0;
extern __int128 D_0055DDD0;
extern __int128 D_0055DDE0;
extern __int128 D_0055DE00;
extern __int128 D_0055DE10;
extern int D_0055DE8C;
void Appearance_ReorderParts(Self390570* self);
}

static inline bool Eq390570(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
static inline __int128 And390570(__int128 a, __int128 b) {
    __int128 r;
    asm { pand r, a, b }
    return r;
}
static inline __int128 From390570(__int128 v) {
    __int128 r;
    asm { pcpyld r, zero, v }
    return r;
}

extern "C" void Appearance_ReorderParts(Self390570* self)
{
    int which[0x20];
    int score[0x20];
    int i = 0;
    int k;
    __int128 mask = From390570(0xFFFFFFFF00LL);
    int n;
    int j;
    __int128 ta, tb;
    short s0, s1;
    int found;
    int best;
    int bi;

    for (k = 0; self->pairs[k].a; k++) {
        which[k] = 0xFA00;
        score[k] = 0;
    }
    n = k;
    self->x23C0 = n;
    for (j = 0; j < D_0055DE8C; j++) {
        for (k = 0; k < n; k++) {
            if (Eq390570(And390570(mask, self->pairs[k].b), And390570(mask, D_0055DDA0.e[j].key))) {
                __int128 ek;
                __int128 pa;
                pa = self->pairs[k].a;
                ek = D_0055DDA0.e[j].key;
                int s = 1;
                if (Eq390570(And390570(D_0055DE00, pa), And390570(D_0055DE00, ek))) s += 2;
                if (Eq390570(And390570(D_0055DE10, pa), And390570(D_0055DE10, ek))) s += 1;
                if (Eq390570(And390570(D_0055DDD0, pa), And390570(D_0055DDD0, ek))) s += 8;
                if (Eq390570(And390570(D_0055DDE0, pa), And390570(D_0055DDE0, ek))) s += 4;
                if (score[k] < s) {
                    which[k] = j;
                    score[k] = s;
                }
            }
        }
    }
    do {
        found = 0;
        best = 0xFA00;
        for (k = i; k < n; k++) {
            if (which[k] < best && which[k] != 0xFA00) {
                best = which[k];
                bi = k;
                found = 1;
            }
        }
        if (found) {
            which[bi] = which[i];
            ta = self->pairs[i].a;
            tb = self->pairs[i].b;
            s0 = self->x22C0[i];
            s1 = self->x2300[i];
            self->pairs[i].a = self->pairs[bi].a;
            self->pairs[i].b = self->pairs[bi].b;
            self->x22C0[i] = self->x22C0[bi];
            self->x2300[i] = self->x2300[bi];
            self->pairs[bi].a = ta;
            self->pairs[bi].b = tb;
            self->x22C0[bi] = s0;
            self->x2300[bi] = s1;
            self->x2DB0[i] = best;
            self->x2DD0[i] = D_0055DDA0.e[best].val;
            i++;
        }
    } while (found);
    for (; i < 0x20; i++) {
        if (self->pairs[i].a) {
            self->x2DB0[i] = 0;
            self->x2DD0[i] = 1;
        } else {
            self->x2DB0[i] = D_0055DE8C - 1;
            self->x2DD0[i] = D_0055DDA0.e[D_0055DE8C - 1].val;
        }
    }
}
