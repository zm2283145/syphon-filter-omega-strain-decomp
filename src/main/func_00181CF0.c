#include "types.h"
typedef struct { int h; } H_181CF0;
typedef struct { char pad[0x20]; int child[8]; } N_181CF0;
typedef struct { char pad0[2]; signed char kind; char pad3; int count; int root; char padC[4]; int leaf; } T_181CF0;
extern N_181CF0* func_00182260(T_181CF0* t, H_181CF0* h);
extern int func_001821E0(N_181CF0* n, void* b);
extern int func_001821D0(int* c, int f);
extern void func_001821C0(H_181CF0* out, int* c);
extern unsigned char ColTree_IsLeaf(T_181CF0* t, H_181CF0* h);
extern void func_00182150(H_181CF0* h, int f);
extern void* func_00182120(T_181CF0* t, H_181CF0* h);
extern void* func_00181E90(T_181CF0* t, H_181CF0* h);
extern void* func_00181E80(T_181CF0* t, H_181CF0* h);
extern void ColTree_VisitNode(T_181CF0* t, void* a, void* n, void* b);
extern void ColTree_VisitLeaf(T_181CF0* t, void* a, void* n, void* b);
void ColTree_VisitRootNode(T_181CF0* t, void* a, void* b)
{
    H_181CF0 h8C;
    H_181CF0 h88;
    H_181CF0 h84;
    H_181CF0 h80;
    H_181CF0 h7C;
    if (t->kind != 'F') return;
    if (t->count > 0) {
        N_181CF0* n;
        h8C.h = t->root;
        n = func_00182260(t, &h8C);
        if (func_001821E0(n, b)) {
            int* c = n->child;
            unsigned int i;
            for (i = 0; i < 8; i++, c++) {
                if (func_001821D0(c, 0)) {
                    unsigned char leaf;
                    func_001821C0(&h84, c);
                    leaf = ColTree_IsLeaf(t, &h84);
                    func_00182150(&h84, -1);
                    if (!leaf) {
                        func_001821C0(&h80, c);
                        ColTree_VisitNode(t, a, func_00182120(t, &h80), b);
                        func_00182150(&h80, -1);
                    } else {
                        func_001821C0(&h7C, c);
                        ColTree_VisitLeaf(t, a, func_00181E90(t, &h7C), b);
                        func_00182150(&h7C, -1);
                    }
                }
            }
        }
    } else {
        h88.h = t->leaf;
        ColTree_VisitLeaf(t, a, func_00181E80(t, &h88), b);
    }
}