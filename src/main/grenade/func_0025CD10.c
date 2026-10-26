#include "types.h"
typedef struct { char pad[0x80]; int v[12]; char pad2[0xC0 - 0xB0]; } Rec_CD10;
typedef struct { char pad[0x34]; Rec_CD10* recs; } Ent_CD10;
typedef struct {
    char pad[0xFA0];
    Ent_CD10 ent[1];
    char pad1[0x1020 - 0xFA0 - 0x38];
    int cur;        /* 0x1020 */
    char pad1024[0xC];
    int n;          /* 0x1030 */
    int pad1034;
    int count;      /* 0x1038 */
    int* arr;       /* 0x103C */
    int val;        /* 0x1040 */
    int val2;       /* 0x1044 */
    int x1048;      /* 0x1048 */
} S_CD10;
void XLib_NewStrip(S_CD10* s)
{
    int v;
    int i;
    Rec_CD10* r;
    if (s->n > 0) s->arr[s->n - 1] = s->val;
    v = s->x1048 - 1;
    r = &s->ent[s->cur].recs[s->n];
    for (i = 0; i < 12; i++) r->v[i] = v;
    s->count++;
    s->n++;
    s->val = 0;
    s->val2 = 0;
}

