#ifndef NPC_INFO_REC_H
#define NPC_INFO_REC_H
/* NPCInfoObject record (func_004361C0) and the 0x14-byte update message copied
   from it before per-player flags are changed (0x00433xxx handlers). */
typedef struct { int key; unsigned char b4; unsigned char state; unsigned char a6[4]; unsigned char aA[4]; } NpcInfoRec;
typedef struct { int key; unsigned char b4; unsigned char state; unsigned char a6[4]; unsigned char aA[4]; char pad[2]; int f10; } NpcInfoMsg;
void func_004355D0(int self);
NpcInfoRec* func_004361C0(int key, int* out);
void func_00434920(int self, int h);
/* member copy: b4, key, state, then both per-player arrays interleaved */
#define NPC_INFO_COPY(m, r) { int ci_; (m).b4 = (r)->b4; (m).key = (r)->key; (m).state = (r)->state; \
    for (ci_ = 0; ci_ < 4; ci_++) { (m).a6[ci_] = (r)->a6[ci_]; (m).aA[ci_] = (r)->aA[ci_]; } }
#endif