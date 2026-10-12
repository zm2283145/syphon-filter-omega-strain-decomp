#include "types.h"
#include "npc_auth.h"
#include "npc_info_rec.h"
void Alloc_Lock(int);
void Alloc_Unlock(int);
void* Mem_Alloc(int, int, char*, int);
void func_00434BB0(char*, NpcInfoMsg**);
extern char D_004BFCA0[];
extern unsigned char D_00533880;
extern int D_00533888;
extern char D_00582B30[];

void func_00435D80(int self, int key, unsigned char v)
{
    int h;
    NpcInfoMsg* m;
    NpcInfoRec* r;
    if (NpcAuth_IsLocal()) {
        r = func_004361C0(key, &h);
        if (r) {
            NpcInfoMsg* t;
            if (D_00533880) Alloc_Lock(9);
            D_00533888++;
            t = (NpcInfoMsg*)Mem_Alloc(0, 0x14, D_004BFCA0, 0x20E);
            if (D_00533880) Alloc_Unlock(9);
            D_00533888--;
            if (t) NPC_INFO_COPY(*t, r)
            m = t;
            if (m) {
                m->a6[r->b4] = 0;
                m->state = r->b4;
                m->b4 = v;
                m->f10 = h;
                r->a6[r->b4] = 0;
                r->b4 = v;
                func_00434BB0(D_00582B30, &m);
                func_00434920(self, h);
            }
        }
    }
}
