#include "types.h"
extern unsigned char* D_005061D0;
static inline void W8_002539B0(int v) { *D_005061D0++ = v; }
static inline void W16_002539B0(int v) { short s = v; *D_005061D0++ = s; *D_005061D0++ = s >> 8; }
typedef struct { int a[4]; int b[4]; int x; int n; } Sub_002539B0;
typedef struct { unsigned char id; char pad[3]; Sub_002539B0 s[5]; int count; unsigned char flag; char pad2[3]; } Ent_002539B0;
typedef struct { char pad[0x64]; Ent_002539B0 e[3]; int count; int b; int c; int d; char pad2f0; unsigned char f; } S_002539B0;
void cBackpack_Pack(S_002539B0* p) {
    int i; Ent_002539B0* e; int j; Sub_002539B0* s; int k;
    W8_002539B0(p->count);
    W8_002539B0(p->b);
    W16_002539B0(p->c);
    W16_002539B0(p->d);
    W8_002539B0(p->f);
    for (i = 0; i < p->count; i++) {
        e = &p->e[i];
        W8_002539B0(e->id);
        W8_002539B0(e->count);
        W8_002539B0(e->flag);
        for (j = 0; j < e->count; j++) {
            s = &e->s[j];
            W8_002539B0(s->x);
            W8_002539B0(s->n);
            for (k = 0; k < s->n; k++) {
                W16_002539B0(s->a[k]);
                W8_002539B0(s->b[k]);
            }
        }
    }
}