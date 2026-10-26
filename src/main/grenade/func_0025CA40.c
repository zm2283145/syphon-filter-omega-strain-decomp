#include "types.h"
typedef struct V4_0025CA40 { float x, y, z, w; } V4_0025CA40;
typedef struct Blk_0025CA40 { char pad[0x80]; int idx[12]; char padB0[0x10]; } Blk_0025CA40;
typedef struct Ent_0025CA40 {
    char pad[0x24];
    Blk_0025CA40* blocks;
    V4_0025CA40* pos;
    V4_0025CA40* c2C;
    V4_0025CA40* c30;
    V4_0025CA40* c34;
    char pad38[0x38 - 0x38];
} Ent_0025CA40;
typedef struct Strip_0025CA40 {
    char pad0[8];
    long long flags;
    char pad10[0xFB0 - 0x10];
    Ent_0025CA40 ents[1];
    char padFE8[0x1020 - 0xFE8];
    int cur;
    int pad1024;
    int pad1028;
    int n102C;
    int nBlocks;
    int nVerts;
    int n1038;
    int* list;
    int run;
    int n1044;
    int n1048;
    int maxRun;
} Strip_0025CA40;
extern void Vec4_Copy(V4_0025CA40* dst, V4_0025CA40* src);
extern void tIRGBA_opAssign_tIRGBAR(V4_0025CA40* dst, V4_0025CA40* src);
void XLib_NextBatchVert(Strip_0025CA40* s)
{
    if (s->run == s->maxRun) {
        int v;
        int i;
        Blk_0025CA40* p;
        Ent_0025CA40* e;
        if (s->nBlocks > 0)
            s->list[s->nBlocks - 1] = s->run;
        v = s->n1048 - 1;
        p = &s->ents[s->cur].blocks[s->nBlocks];
        for (i = 0; i < 12; i++)
            p->idx[i] = v;
        s->n1038++;
        s->nBlocks++;
        s->run = 0;
        s->n1044 = 0;
        e = &s->ents[s->cur];
        Vec4_Copy(&e->pos[s->nVerts], &e->pos[s->nVerts - 2]);
        Vec4_Copy(&e->pos[s->nVerts + 1], &e->pos[s->nVerts - 1]);
        if (s->flags & 0x200000000LL) {
            tIRGBA_opAssign_tIRGBAR(&e->c30[s->nVerts], &e->c30[s->nVerts - 2]);
            tIRGBA_opAssign_tIRGBAR(&e->c30[s->nVerts + 1], &e->c30[s->nVerts - 1]);
        }
        if (s->flags & 0x400000000LL) {
            Vec4_Copy(&e->c34[s->nVerts], &e->c34[s->nVerts - 2]);
            Vec4_Copy(&e->c34[s->nVerts + 1], &e->c34[s->nVerts - 1]);
        }
        if (s->flags & 0x100000000LL) {
            Vec4_Copy(&e->c2C[s->nVerts], &e->c2C[s->nVerts - 2]);
            Vec4_Copy(&e->c2C[s->nVerts + 1], &e->c2C[s->nVerts - 1]);
        }
        s->run += 2;
        s->nVerts += 2;
        s->n102C += 2;
    }
    s->run++;
    s->nVerts++;
    s->n102C++;
}