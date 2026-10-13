#include "types.h"

typedef struct { int unk0; int count; char* data; } BV_61E0;
typedef struct { unsigned char flag; char pad[3]; BV_61E0 v; int pad10; } E20_61E0;
typedef struct { int unk0; int count; E20_61E0* data; int pad; } V16_61E0;
typedef struct { int w[8]; } Lvl_61E0;
typedef struct { int capacity; unsigned int count; Lvl_61E0* data; } LvlVec_61E0;

typedef struct {
    char pad00[0x08];
    int stats[31];
    unsigned int objectiveBits[8];
    unsigned int missionBits[8];
    LvlVec_61E0 levels;
    char padD0[0xD8 - 0xD0];
    int unkD8;
    char padDC[0xAA8 - 0xDC];
    V16_61E0 lists[5];
    BV_61E0 bytes;
    int padB04;
    int unkB08[9];
    int unkB2C[9];
    int unkB50;
    char padB54[0xB68 - 0xB54];
    unsigned char unkB68;
    char padB69[3];
    int unkB6C;
    unsigned char unkB70;
    unsigned char unkB71;
    unsigned char unkB72;
    unsigned char padB73;
    unsigned char unkB74;
} Agent_61E0;

extern int D_00532AF4;
int func_00336440(BV_61E0* v);
char* func_00336450(BV_61E0* v, int i);
void AgentLevelVec_Resize(LvlVec_61E0* v, unsigned int n, const Lvl_61E0* value);

void AgentData_Reset(Agent_61E0* a)
{
    int i;
    int k;
    int n;
    Lvl_61E0 e1;
    Lvl_61E0 e0;
    for (i = 0; i < 31; i++) a->stats[i] = 0;
    for (k = 0; k < 5; k++) {
        int j;
        for (j = 0; j < a->lists[k].count; j++) {
            E20_61E0* e = &a->lists[k].data[(unsigned)j];
            int m;
            e->flag = 0;
            for (m = 0; m < func_00336440(&e->v); m++) *func_00336450(&e->v, m) = 0;
        }
    }
    for (i = 0; i < a->bytes.count; i++) a->bytes.data[i] = 0;
    for (i = 0; i < 8; i++) a->objectiveBits[i] = 0;
    for (i = 0; i < 8; i++) a->missionBits[i] = 0;
    { int j; for (j = 0; j < 9; j++) a->unkB08[j] = 0; }
    { int j; for (j = 0; j < 9; j++) a->unkB2C[j] = 0; }
    a->unkD8 = 0;
    a->unkB50 = 0;
    a->unkB71 = 0;
    a->unkB70 = 0;
    n = D_00532AF4;
    e1.w[1] = -1;
    e1.w[0] = -1;
    e1.w[3] = 0;
    e1.w[2] = 0;
    e1.w[4] = -1;
    e1.w[5] = -1;
    e0.w[1] = -1;
    e0.w[0] = -1;
    e0.w[3] = 0;
    e0.w[2] = 0;
    e0.w[4] = -1;
    e0.w[5] = -1;
    AgentLevelVec_Resize(&a->levels, 0, &e0);
    AgentLevelVec_Resize(&a->levels, n, &e1);
    a->unkB72 = 0;
    a->unkB74 = 0;
    a->unkB6C = -1;
    a->unkB68 = 0;
}
