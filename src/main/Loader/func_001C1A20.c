#include "types.h"
typedef struct G4PopReader {
    int unk0;
    int size;
    unsigned int base;
    int* cur;
} G4PopReader;
extern char D_0049EFE0[];
extern char D_00535D20[];
extern void* func_001698C0(void);
extern void func_00165E60(void* h, void* s, int f);
extern int Pop_FindTag(G4PopReader* r, int tag);
extern void func_00374270(void* pool, int type, int count);
static inline void G4_Align(G4PopReader* r)
{
    int m = (unsigned long long)(unsigned int)r->cur % 4;
    if (m) {
        r->cur = (int*)((int)r->cur + (4 - m));
    }
}
void Loader_AllocateLights(void* level, G4PopReader* r)
{
    int n;
    if (r->cur == 0) {
        return;
    }
    func_00165E60(func_001698C0(), D_0049EFE0, 0);
    G4_Align(r);
    if (!(unsigned char)Pop_FindTag(r, 0x3A544E50)) {
        return;
    }
    n = *r->cur;
    r->cur++;
    func_00374270(D_00535D20, 16, n);
    G4_Align(r);
    if (!(unsigned char)Pop_FindTag(r, 0x3A524944)) {
        return;
    }
    n = *r->cur;
    r->cur++;
    func_00374270(D_00535D20, 2, n);
    func_00374270(D_00535D20, 4, 0x18);
    func_00374270(D_00535D20, 1, 1);
}