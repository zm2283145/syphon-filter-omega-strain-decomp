#include "types.h"
typedef struct { int key; unsigned char b4; unsigned char state; unsigned char a6[4]; unsigned char aA[4]; } NpcInfoRec;
typedef struct { int key; unsigned char b4; unsigned char state; unsigned char a6[4]; unsigned char aA[4]; char pad[2]; int f10; } NpcInfoMsg;
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
extern unsigned char D_00582780;
void func_004355D0(int self);
NpcInfoRec* func_004361C0(int* key, int* out);
void func_00434920(int self, int h);
void func_00434AA0(int self, NpcInfoMsg* m);

void func_00435F30(int self, int* key, unsigned char v)
{
    func_004355D0(self);
    if (D_00582780) {
        NpcInfoMsg m;
        int j;
        m.key = -1;
        m.b4 = 0xFF;
        m.state = 0xFF;
        for (j = 0; j < 4; j++) { m.a6[j] = 0; m.aA[j] = 1; }
        m.f10 = 0;
        m.key = *key;
        m.b4 = v;
        func_00434AA0(self, &m);
        func_00434920(self, D_00582A78);
        func_00434920(self, D_00582A80);
        func_00434920(self, D_00582A88);
        func_00434920(self, D_00582A90);
        func_00434920(self, D_00582A98);
    } else {
        int i = 0;
        NpcInfoRec* r = func_004361C0(key, 0);
        if (!r) {
            for (i = 0; i != 29; i++) if (D_005827F0[i].key == -1) { r = &D_005827F0[i]; break; }
            if (i == 29) {
                for (i = 0; i != 29; i++) if (D_005827F8[i].key == -1) { r = &D_005827F8[i]; break; }
                if (i == 29)
                    for (i = 0; i != 29; i++) if (D_00582800[i].key == -1) { r = &D_00582800[i]; break; }
                if (i == 29)
                    for (i = 0; i != 29; i++) if (D_00582808[i].key == -1) { r = &D_00582808[i]; break; }
                if (i == 29)
                    for (i = 0; i != 29; i++) if (D_00582810[i].key == -1) { r = &D_00582810[i]; break; }
            }
        }
        if (i < 29) r->key = *key;
    }
}

