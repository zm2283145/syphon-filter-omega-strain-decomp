#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_004BFCA0[];
extern unsigned char D_005721B8;
extern unsigned char D_005721C0;
extern unsigned char D_005721C8;
extern unsigned char D_005721D0;
extern unsigned char D_00582778;
extern unsigned char D_00582780;
void* Mem_Alloc(int heap, int size, char* file, int line);
void Mem_Free(int heap, void* p, char* file, int line);
void func_00433A60(int a);
void func_00434740(int a);
}
struct E_004355D0 {
    int id;
    unsigned char a, b;
    unsigned char c[4];
    unsigned char d[4];
    char pad[2];
    void Init() { id = -1; a = 0xFF; b = 0xFF; c[0] = 0; d[0] = 1; c[1] = 0; d[1] = 1; c[2] = 0; d[2] = 1; c[3] = 0; d[3] = 1; }
};
extern "C" {
extern E_004355D0* D_005827F0;
extern E_004355D0* D_005827F8;
extern E_004355D0* D_00582800;
extern E_004355D0* D_00582808;
extern E_004355D0* D_00582810;
}
inline void* operator new(unsigned int, void* p) { return p; }
static inline void* New_004355D0(int size, int line) { AllocGuard g; return Mem_Alloc(0, size, D_004BFCA0, line); }
static inline void Del_004355D0(void* p, int line) { if (p) { AllocGuard g; Mem_Free(0, p, D_004BFCA0, line); } }
#define NEWARR(dst, line) { E_004355D0* p = (E_004355D0*)New_004355D0(sizeof(E_004355D0) * 29, line); if (p) { E_004355D0* q = p; do { q->Init(); q++; } while (q != p + 29); } dst = p; }
extern "C" void func_004355D0(int arg)
{
    if (D_005721B8) return;
    if (D_005721D0) {
        if (D_00582778 && !D_00582780) {
            if (D_005721C8 ? D_005721C0 : 1) {
                E_004355D0* p0 = D_005827F0;
                E_004355D0* p1 = D_005827F8;
                E_004355D0* p2 = D_00582800;
                E_004355D0* p3 = D_00582808;
                E_004355D0* p4 = D_00582810;
                func_00433A60(arg);
                Del_004355D0(p0, 0x24E);
                Del_004355D0(p1, 0x251);
                Del_004355D0(p2, 0x254);
                Del_004355D0(p3, 0x257);
                Del_004355D0(p4, 0x25A);
                D_00582780 = 1;
            }
        }
        func_00434740(arg);
        return;
    }
    if (!D_00582778 && D_005721C8) {
        NEWARR(D_005827F0, 0x269);
        NEWARR(D_005827F8, 0x26A);
        NEWARR(D_00582800, 0x26B);
        NEWARR(D_00582808, 0x26C);
        NEWARR(D_00582810, 0x26D);
        D_00582778 = 1;
    }
}