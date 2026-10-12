#include "types.h"
typedef struct { int key; unsigned char b4; unsigned char state; unsigned char a6[4]; unsigned char aA[4]; } NpcInfoRec;
extern NpcInfoRec* D_005827F0;
extern NpcInfoRec* D_005827F8;
extern NpcInfoRec* D_00582800;
extern NpcInfoRec* D_00582808;
extern NpcInfoRec* D_00582810;
extern int D_00582A78;
extern int D_00582A80;
extern int D_00582A88;
extern int D_00582A90;
extern int D_00582A98;

static inline int Eq_61C0(int* a, int* b) { return *a == *b; }
NpcInfoRec* func_004361C0(int* key, int* out)
{
    int i;
    for (i = 0; i != 29; i++) {
        if (D_005827F0 && Eq_61C0(&D_005827F0[i].key, key)) {
            if (out) *out = D_00582A78;
            return &D_005827F0[i];
        }
        if (D_005827F8 && Eq_61C0(&D_005827F8[i].key, key)) {
            if (out) *out = D_00582A80;
            return &D_005827F8[i];
        }
        if (D_00582800 && Eq_61C0(&D_00582800[i].key, key)) {
            if (out) *out = D_00582A88;
            return &D_00582800[i];
        }
        if (D_00582808 && Eq_61C0(&D_00582808[i].key, key)) {
            if (out) *out = D_00582A90;
            return &D_00582808[i];
        }
        if (D_00582810 && Eq_61C0(&D_00582810[i].key, key)) {
            if (out) *out = D_00582A98;
            return &D_00582810[i];
        }
    }
    if (out) *out = -1;
    return 0;
}



