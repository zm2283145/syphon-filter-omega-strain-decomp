#include "types.h"
typedef struct { char pad[0x40A]; short f40A; char p40C[0xB]; signed char f417; char p418; unsigned char f419; } BlkV;
typedef struct { char p0[0x11C]; BlkV *f11C; char p120[0x18]; unsigned char f138; char p139[3]; BlkV *f13C; } Ent;
typedef struct { char p0[0x14]; Ent *f14; } Wpn;
extern void func_0038CD90(BlkV* b, int x);
extern void func_001468E0(Wpn* w, BlkV* name, BlkV* src);
extern void func_00146460(Wpn* w, BlkV* b);
void func_00146FC0(Wpn* w, BlkV* b, int x)
{
    short idx = b->f40A;
    unsigned char kind = b->f419;
    if (idx == -1) {
        if (b->f417 == -1) {
            func_0038CD90(b, x);
            func_001468E0(w, b, b);
        } else {
            func_00146460(w, b);
        }
        return;
    }
    {
        Ent* e = &w->f14[idx];
        if (!kind) {
            if (e->f13C) {
                if (e->f13C->f417 == -1) {
                    func_0038CD90(e->f13C, x);
                    func_001468E0(w, b, b);
                } else {
                    func_00146460(w, e->f13C);
                    e->f13C = 0;
                }
            }
        } else {
            if (e->f11C && e->f138) {
                if (e->f11C->f417 == -1) {
                    func_0038CD90(e->f11C, x);
                    func_001468E0(w, b, b);
                } else {
                    func_00146460(w, e->f11C);
                    e->f11C = 0;
                }
            }
        }
    }
}


