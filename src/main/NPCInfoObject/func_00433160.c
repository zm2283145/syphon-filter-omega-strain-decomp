#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

typedef struct { int key; unsigned char b4; } Ent_433160;
typedef struct { char pad[0x1C]; Ent_433160* ent; } Obj_433160;
typedef struct { int v; } Res_433160;
extern "C" {
extern char D_004BFCA0[];
extern unsigned char D_005721C0;
extern unsigned char D_005721C8;
extern unsigned char D_005723C8;
extern char D_00582778;
extern unsigned char D_00582780;
extern unsigned char D_00582788;
extern unsigned char D_00582790;
extern unsigned char D_00582798;
extern Ent_433160* D_005827F0;
extern Ent_433160* D_005827F8;
extern Ent_433160* D_00582800;
extern Ent_433160* D_00582808;
extern Ent_433160* D_00582810;
extern int D_00582A68;
extern int D_00582A78;
extern int D_00582A80;
extern int D_00582A88;
extern int D_00582A90;
extern int D_00582A98;
void Mem_Free(int pool, void* p, char* file, int line);
int func_002EB650(Obj_433160** out, int key);
void func_00434600(Res_433160* r, int* key, unsigned char b);
void func_00435F30(Res_433160* r, int* key, unsigned char b);
}
struct Busy_433160 {
    Busy_433160() { D_00582A68++; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Busy_433160() { D_00582A68--; }
};
struct Reent_433160 {
    Reent_433160() { if (!D_005723C8) D_005723C8 = 1; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Reent_433160() { D_005723C8 = 0; }
};
static inline unsigned char IsHost_433160() { if (D_005721C8) return D_005721C0; return 1; }
static inline void Free_433160(Ent_433160* p, int line) { AllocGuard g; Mem_Free(0, p, D_004BFCA0, line); }

extern "C" void func_00433160(void* self, int key)
{
    Reent_433160 re;
    Obj_433160* o;
    if (func_002EB650(&o, key) == 0) {
        if (!D_00582780) {
            Ent_433160* old = 0;
            if (D_005827F0 && !D_00582780) old = D_005827F0;
            D_005827F0 = o->ent;
            D_00582778 = 1;
            D_00582780 = 1;
            if (!IsHost_433160() && old) {
                Res_433160 r;
                int k[1];
                Busy_433160 busy;
                k[0] = old->key;
                func_00435F30(&r, k, old->b4);
                func_00434600(&r, k, old->b4);
                Free_433160(old, 0x620);
            }
            D_00582A78 = key;
        } else if (!D_00582788) {
            if (D_005827F8) Free_433160(D_005827F8, 0x629);
            D_005827F8 = o->ent;
            D_00582A80 = key;
            D_00582788 = 1;
        } else if (!D_00582790) {
            if (D_00582800) Free_433160(D_00582800, 0x635);
            D_00582800 = o->ent;
            D_00582A88 = key;
            D_00582790 = 1;
        } else if (!D_00582798) {
            if (D_00582808) Free_433160(D_00582808, 0x640);
            D_00582808 = o->ent;
            D_00582A90 = key;
            D_00582798 = 1;
        } else {
            if (D_00582810) Free_433160(D_00582810, 0x64A);
            D_00582810 = o->ent;
            D_00582A98 = key;
        }
    }
}