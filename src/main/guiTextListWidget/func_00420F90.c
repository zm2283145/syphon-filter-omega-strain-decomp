#include "types.h"
typedef struct Mtx { __int128 r[4]; } Mtx;
typedef struct Render {
    char pad0[0xA80];
    Mtx mtx[0x14];
} Render;
extern char D_005381F0[];
extern int D_00538C64;
extern char D_00538C68;
void func_00423670(void* self);
static inline Mtx* MtxAt(int i) { return &((Render*)D_005381F0)->mtx[i]; }
static inline void GQR(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void UM(void* p) { int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }

void GuiTextListWidget_Draw(void* self)
{
    { int i = D_00538C64; GQR(MtxAt(i + 1), MtxAt(i)); }
    D_00538C64++;
    UM(MtxAt(D_00538C64));
    D_00538C68 = 1;
    func_00423670(self);
    D_00538C64--;
    D_00538C68 = 1;
}
