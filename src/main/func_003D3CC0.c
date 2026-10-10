#include "types.h"

typedef struct E3ShRec {
    int key;            /* 0x00 */
    char pad04[0x64 - 0x04];
    int valid;          /* 0x64 */
    char pad68[0x80 - 0x68];
} E3ShRec;

typedef struct E3ShMgr {
    char pad0[0x4D0];
    E3ShRec recs[512];
    char pad104D0[8];
    int count;          /* 0x104D8 */
    char pad104DC[0x1176C - 0x104DC];
    E3ShRec* sel;       /* 0x1176C */
    int unk11770;
    int unk11774;
} E3ShMgr;

/* Selects the shadow receiver record whose key matches. */
void func_003D3CC0(E3ShMgr* m, int key)
{
    int i;
    m->sel = 0;
    m->unk11774 = 0;
    m->unk11770 = 0;
    for (i = 0; i < m->count; i++) {
        if (m->recs[i].key == key) {
            if (m->recs[i].valid) {
                m->sel = &m->recs[i];
            }
            break;
        }
    }
}