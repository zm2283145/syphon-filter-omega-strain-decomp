#include "types.h"
#pragma cplusplus on
#define B8V8(p) virtual void p##0(); virtual void p##1(); virtual void p##2(); virtual void p##3(); virtual void p##4(); virtual void p##5(); virtual void p##6(); virtual void p##7();
struct B8_NPC {
    B8V8(a) B8V8(b) B8V8(c) B8V8(d) B8V8(e) B8V8(f) B8V8(g) B8V8(h) B8V8(i) B8V8(j) B8V8(k) B8V8(l)
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6();
    virtual int GetWeapon();      /* +0x1A4 */
    virtual void m8();
    virtual void SetWeapon(int w); /* +0x1AC */
    char pad4[0x8C - 4];
    float f8C;
    char pad90[0x12C - 0x90];
    int prevWeapon;
    int fireMode;
    int fireTime;
};
extern "C" void cNPC_ForceWeaponFire(B8_NPC* npc, int mode, int weapon, float time) {
    if (weapon < 0 || weapon == npc->GetWeapon()) {
        npc->prevWeapon = -1;
    } else {
        npc->prevWeapon = npc->GetWeapon();
        npc->SetWeapon(weapon);
    }
    npc->fireMode = mode;
    if (time == 0.0f) {
        npc->fireTime = (int)npc->f8C;
    } else {
        npc->fireTime = (int)time;
    }
}