/*
 * main/man: range (2 files, 0038B8D0-0038B990)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0038B8D0 */
#pragma push /* merge_units */
typedef struct { unsigned char pad[7]; unsigned char count; unsigned char* data; unsigned char pad2[4]; } Grp_B8D0;
typedef struct {
    unsigned char pad0[0x1EC0];
    Grp_B8D0 groups[0x48];
    unsigned char* bufs[0x20];
    unsigned short numGroups;
} Model_B8D0;
void ManModel_SaturateGore(Model_B8D0* m)
{
    unsigned int i;
    unsigned int n;
    unsigned char* d;
    unsigned char* buf;
    unsigned int j;
    unsigned char* p;
    unsigned int c;
    unsigned int k;
    for (i = 0; i < m->numGroups; i++) {
        buf = m->bufs[i];
        if (buf != 0) {
            n = m->groups[i].count;
            d = m->groups[i].data; d += 2;
            for (j = 0; j < n; j++) {
                c = d[1];
                d += 2;
                p = buf;
                buf += 0x20;
                for (k = 0; k < c; k++) {
                    if (*p != 0) *p = 0x5A;
                    p++;
                }
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0038B8D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0038B8D0 */

/* merge_units: begin func_0038B990 */
#pragma push /* merge_units */
typedef struct { unsigned char a; unsigned char n; } HgPair;
typedef struct { char pad0[2]; HgPair p[1]; } HgDef;
typedef struct {
    char pad0[7];
    unsigned char count;
    HgDef* def;
    char padC[4];
} HgEnt;
typedef struct {
    char pad0[0x1EC0];
    HgEnt ents[32];
    char pad20C0[0x2340 - 0x20C0];
    unsigned char* items[32];
    unsigned short count;
    char pad23c2[0x2C08 - 0x23C2];
    unsigned int age;
} HitGore;

void HitGore_Age(HitGore* self)
{
    unsigned int i;
    unsigned int cnt;
    HgPair* pr;
    unsigned char* p;
    unsigned int k;
    unsigned char* q;
    unsigned int n;
    unsigned int b;
    unsigned char* buf;
    if (self->age) {
        for (i = 0; i < self->count; i++) {
            p = self->items[i];
            buf = p;
            if (buf) {
                cnt = self->ents[i].count;
                pr = (HgPair*)self->ents[i].def; pr++;
                for (k = 0; k < cnt; k++) {
                    n = pr->n;
                    q = buf;
                    buf += 0x20;
                    pr++;
                    for (b = 0; b < n; b++, q++) {
                        unsigned int v = *q;
                        if (v) {
                            v += self->age;
                            if (v > 0x5A) v = 0x5A;
                            *q = v;
                        }
                    }
                }
            }
        }
        self->age = 1;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0038B990(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0038B990 */
