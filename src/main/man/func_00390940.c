/* func_00390940 (main/man): merge a new appearance into the man's current one
 * (release attached meshes, back up the old appearance, swap body-kind tags,
 * fix up the head/hair pairs, reload changed meshes, append new pairs).
 * Compiler: mwcc 3.0b38 (also matches b50). The odd lvalue forms
 * (casts, `(unsigned)i`, `s5 << 1`, the reused `t`) control CSE, evaluation
 * order and register numbering; see build/agents/c56lg/NOTES.md. */
#pragma cplusplus on
#pragma optimization_level 3
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_dead_code off
#include "types.h"
#include "alloc_guard.h"

struct Pair390940 {
    __int128 a;
    __int128 b;
};

struct App390940 {
    __int128 q0;
    __int128 q10;
    __int128 q20;
    __int128 q30;
    Pair390940 pairs[0x20];
};

struct Self390940 {
    char pad[0x20];
    char x20[0x20];
    App390940 app;
    char pad480[0x1EC0 - 0x480];
    char x1EC0[0x2340 - 0x1EC0];
    void* x2340[0x20];
    unsigned short x23C0;
    char pad23C2[0x2BDB - 0x23C2];
    unsigned char x2BDB;
    char pad2BDC[0x2C0C - 0x2BDC];
    unsigned char x2C0C;
    signed char x2C0D;
    char pad2C0E[0x2C14 - 0x2C0E];
    App390940* x2C14;
};

extern "C" {
extern char D_0055DDA0[];
extern __int128 D_0055DDD0;
extern __int128 D_0055DE40;
extern char D_0057124C[];
extern char D_004BC310[];
extern char D_004BC3C8[];
extern char D_004BC3D0[];
extern char D_004BC3D8[];
extern char D_004BC3E0[];
extern char D_004BC3E8[];

void func_0036CA70(void* p);
void* Mem_Alloc(int pool, int size, char* file, int line);
int Appearance_GetBodyKind(App390940* app);
int Appearance_GetToneDigit(App390940* app);
int Appearance_GetPairCount(App390940* app);
int Appearance_FindPairByType(App390940* app, char* type);
int String_CompareN(char* a, char* b, int n);
void String_Copy(char* d, char* s);
int strcmp(char* a, char* b);
int MeshCache_FindSlot(char* cache, __int128 name);
void MeshCache_Load(char* cache, __int128 name, char* ctx, char* arg);
void func_00401290(char* cache, App390940* app, char* x, __int128 a, __int128 b, int kind, int tone);
void func_00390940(Self390940* self, App390940* src);
}

static inline void QMove_390940(void* d0, void* s, int n0) {
    int n = n0; __int128 t; void* d = d0;
    asm {
        .set noreorder
    lp:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}

static inline void QMove2_390940(void* d0, void* s0, int n0) {
    int n = n0; void* s = s0; __int128 t; void* d = d0;
    asm {
        .set noreorder
    lp:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}

static inline bool Eq390940(__int128 a, __int128 b) {
    __int128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r == -1;
}
static inline __int128 And390940(__int128 a, __int128 b) {
    __int128 r;
    asm { pand r, a, b }
    return r;
}
static inline __int128 Or390940(__int128 a, __int128 b) {
    __int128 r;
    asm { por r, a, b }
    return r;
}
static inline __int128 Not390940(__int128 a) {
    __int128 r;
    asm { pnor r, a, a }
    return r;
}
static inline __int128 From390940(__int128 v) {
    __int128 r;
    asm { pcpyld r, zero, v }
    return r;
}

static inline void Swap390940(__int128* p, __int128 from, __int128 to) {
    __int128 v;
    __int128 m;
    m = D_0055DDD0;
    v = *p;
    if (Eq390940(And390940(m, v), And390940(m, from))) {
        __int128 b = And390940(to, m);
        __int128 nm = Not390940(m);
        *p = Or390940(And390940(v, nm), b);
    }
}
static inline void MeshP390940(Self390940* self, __int128* name) {
    if (MeshCache_FindSlot(D_0055DDA0, *name) == -1) {
        self->x2BDB = 1;
        MeshCache_Load(D_0055DDA0, *name, D_0057124C, self->x20);
    }
}

extern "C" void func_00390940(Self390940* self, App390940* src)
{
    int i = 0;
    int s5;
    int j;
    int s4;
    int s3;
    __int128 tmp;
    char* t;
    Pair390940* p;

    for (; i < self->x23C0; i++) {
        void* e = ((void**)self->x2340)[(unsigned)i];
        if (e) {
            func_0036CA70(e);
            ((int*)self->x2340)[i] = 0;
        }
    }
    if (self->x2C14) {
        QMove_390940(&self->app, self->x2C14, 0x44);
    } else {
        App390940* a;
        {
            AllocGuard g;
            a = (App390940*)Mem_Alloc(0, 0x440, D_004BC310, 0x313);
        }
        self->x2C14 = a;
        QMove2_390940(self->x2C14, &self->app, 0x44);
    }
    self->x2C0C = Appearance_GetBodyKind(&self->app);
    self->x2C0D = Appearance_GetToneDigit(&self->app);
    self->x23C0 = Appearance_GetPairCount(&self->app);
    s3 = Appearance_GetBodyKind(src);
    if (self->x2C0C != s3) {
        __int128 from;
        __int128 to;
        if (self->x2C0C == 1) {
            from = From390940('2');
            to = From390940('1');
        } else {
            from = From390940('1');
            to = From390940('2');
        }
        for (p = src->pairs; p->a; p++) {
            Swap390940((__int128*)p, from, to);
            Swap390940(&p->b, from, to);
        }
        Swap390940(&src->q20, from, to);
    }
    s5 = Appearance_FindPairByType(&self->app, D_004BC3C8);
    if (s5 != -1) {
        j = Appearance_FindPairByType(src, D_004BC3C8);
        if (j != -1) {
            ((__int128*)self->app.pairs)[s5 * 2] = src->pairs[j].a;
            func_00401290(D_0055DDA0, &self->app, self->x1EC0, self->app.pairs[s5].a, src->pairs[j].a,
                          self->x2C0C, self->x2C0D);
        } else {
            j = Appearance_FindPairByType(src, D_004BC3D0);
            if (j != -1) {
                s4 = Appearance_FindPairByType(&self->app, D_004BC3D0);
                t = (char*)&src->pairs[j];
                s3 = String_CompareN(t + 6, D_004BC3D8, 3);
                tmp = ((__int128*)self->app.pairs)[s5 << 1];
                t = (char*)&tmp;
                if (s4 != -1) {
                    p = &self->app.pairs[s4];
                    if (!String_CompareN((char*)p + 0xA, D_004BC3E0, 4)) {
                        s4 = -1;
                    }
                }
                if (s4 == -1 && s3) {
                    String_Copy(t + 0xA, D_004BC3E8);
                    MeshP390940(self, &tmp);
                    ((__int128*)self->app.pairs)[s5 * 2] = tmp;
                    func_00401290(D_0055DDA0, &self->app, self->x1EC0, self->app.pairs[s5].a, tmp,
                                  self->x2C0C, self->x2C0D);
                } else if (s4 != -1 && !s3) {
                    String_Copy(t + 0xA, D_004BC3E0);
                    MeshP390940(self, &tmp);
                    ((__int128*)self->app.pairs)[s5 * 2] = tmp;
                    func_00401290(D_0055DDA0, &self->app, self->x1EC0, self->app.pairs[s5].a, tmp,
                                  self->x2C0C, self->x2C0D);
                }
            }
        }
    }
    if (strcmp((char*)&self->app.q20, (char*)&src->q20)) {
        MeshP390940(self, &src->q20);
        self->app.q20 = src->q20;
    }
    for (p = src->pairs; p->a; p++) {
        int found = 0;
        __int128 x;
        __int128 m = D_0055DE40;
        for (i = 0; i < self->x23C0; i++) {
            x = self->app.pairs[i].a;
            if (Eq390940(And390940(m, p->a), And390940(m, x))) {
                found = 1;
                break;
            }
        }
        if (!found) {
            self->app.pairs[self->x23C0 + 2].a = self->app.pairs[self->x23C0 + 1].a;
            self->app.pairs[self->x23C0 + 2].b = self->app.pairs[self->x23C0 + 1].b;
            self->app.pairs[self->x23C0 + 1].a = self->app.pairs[self->x23C0].a;
            self->app.pairs[self->x23C0 + 1].b = self->app.pairs[self->x23C0].b;
            self->x23C0++;
        }
        self->app.pairs[i].b = p->b;
        self->app.pairs[i].a = p->a;
    }
    if (p->b) {
        self->app.pairs[self->x23C0].b = p->b;
    }
}
