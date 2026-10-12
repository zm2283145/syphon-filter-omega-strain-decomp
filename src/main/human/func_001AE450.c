#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct Act {
    char pad0[0x2C];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0x58 - 0x2F];
    void* p58;
    char pad5C[0x2C3D - 0x5C];
    unsigned char b2C3D;
    char pad2C3E[0x31FC - 0x2C3E];
    unsigned char b31FC;
    char pad31FD[0x339C - 0x31FD];
    int w339C;
    int w33A0;
};
extern "C" {

extern char D_0049D8D0[];
extern unsigned char D_005721C8;
extern int StartingArmor;

void* Mem_Alloc(int, int, char*, int);
void func_003CCF30(Act*);
void func_003FB9C0(Act*);
void Actor_AttachComponent(Act*, void*);
void* PlayerComponent_Construct(void*);
void* AiComponent_Construct(void*, Act*, int, int);
void* AiComponent_ConstructAlt(void*, Act*);
}
static inline bool Ready(Act* a)
{
    return a->b2D && a->b2C && !a->b2E;
}
static inline void Detach(Act* a)
{
    if (a->b31FC) {
        func_003CCF30(a);
        a->b31FC = 0;
    }
}
static inline void* Alloc(int size, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, D_0049D8D0, line);
}
extern "C" void Actor_InitComponents(Act* a, unsigned char kind, int* ai, void* comp)
{
    if (D_005721C8 && a->p58) {
        if (Ready(a)) {
            a->b2D = 0;
            Detach(a);
            a->b2D = 1;
        } else {
            Detach(a);
        }
    }
    switch (kind) {
    case 0:
    case 3:
        if (comp) {
            Actor_AttachComponent(a, comp);
            a->b31FC = 1;
            func_003FB9C0(a);
        }
        {
            int v = StartingArmor;
            a->w339C = v;
            a->w33A0 = v;
        }
        break;
    case 1:
        {
            void* m = Alloc(0x1D0, 0xBCE);
            if (m) m = PlayerComponent_Construct(m);
            Actor_AttachComponent(a, m);
            a->b31FC = 1;
            a->b2C3D = 1;
            {
                int v = StartingArmor;
                a->w339C = v;
                a->w33A0 = v;
            }
            func_003FB9C0(a);
        }
        break;
    case 2:
        if (ai) {
            void* m = Alloc(0x1E0, 0xBD8);
            if (m) m = AiComponent_Construct(m, a, ai[0], ai[1]);
            Actor_AttachComponent(a, m);
        } else {
            void* m = Alloc(0x1E0, 0xBDE);
            if (m) m = AiComponent_ConstructAlt(m, a);
            Actor_AttachComponent(a, m);
        }
        a->b31FC = 1;
        break;
    case 4:
        if (comp) {
            Actor_AttachComponent(a, comp);
            a->b31FC = 1;
        }
        break;
    }
}

