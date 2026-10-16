#include "types.h"
typedef struct { char pad[0x94]; int mods; } Kb_32C860;
typedef struct {
    char p0[0x9C];
    unsigned char b9C;
    char p9D[0x44];
    unsigned char bE1;
    char pE2[2];
    unsigned int flags;
    unsigned int mods;
} Self_32C860;
extern unsigned char D_0055A701;
extern Kb_32C860 D_0055A700;
extern void func_0041E3B0(Self_32C860* self);
extern void func_0032B5F0(Self_32C860* self, unsigned int flags);
extern void GuiKeyboard_RefreshSpecialKeys(Self_32C860* self);

void GuiKeyboard_Update(Self_32C860* self)
{
    Kb_32C860* k;
    func_0041E3B0(self);
    k = &D_0055A700;
    if (D_0055A701) {
        int m = k->mods;
        unsigned int f = 0;
        unsigned char changed;
        if (self->b9C && ((m & 4) || (m & 0x40))) f |= 4;
        if ((m & 2) || (m & 0x20)) f |= 1;
        changed = 0;
        if ((f & self->flags) != f) {
            if (f & 1) self->bE1 = 0;
            self->flags |= f;
            changed = 1;
        }
        if (self->mods != f) {
            if (!(f & 1) && (self->mods & 1)) {
                self->bE1 = 0;
                self->flags &= ~1;
                changed = 1;
            }
            if (!(f & 4) && (self->mods & 4)) {
                self->flags &= ~4;
                changed = 1;
            }
        }
        self->mods = f;
        if (changed) func_0032B5F0(self, self->flags);
    }
    GuiKeyboard_RefreshSpecialKeys(self);
}
