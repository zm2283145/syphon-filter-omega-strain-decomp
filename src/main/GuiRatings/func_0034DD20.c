#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct QCol { float r, g, b, a; QCol(float r_, float g_, float b_, float a_) { r = r_; g = g_; b = b_; a = a_; } } __attribute__((aligned(16)));
class W {
public:
    VPAD16(a) VPAD4(b)
    virtual bool IsA(void* type);
    char pad4[0xC];
    int idx;
    unsigned short flags;
    char pad16[0x60 - 0x16];
    float r, g, b, a;
    void SetColor(QCol c) { r = c.r; g = c.g; b = c.b; a = c.a; }
};
typedef struct { char pad[8]; unsigned char used; char pad9[0xB]; } Entry;
struct RList { int f0; int count; Entry *entries; int Count() { return count; } Entry &operator[](unsigned int i) { return entries[i]; } };
struct Self {
    char pad[0x64];
    int f64;
    char pad68[4];
    W *items[24];
    RList list;
};
struct G { char pad[0x25C]; int f25C; };
extern "C" {
extern char *D_00492BB8;
extern char D_004B88F0[];
extern char D_004FFB50[];
extern G *D_004FFC04;
void func_00356CD0(Self *self);
void func_00299510(void *p);
int Agent_GetSelected(void *a, int i);
void func_00333600(int agent, void *p);
W *GuiWidget_FindChildByName(void *self, char *name);
void func_0043C890(W *w, char *s, int f);
int sprintf(char *buf, const char *fmt, ...);
}
static inline W *Cast(W *w, char *type) { return (w && w->IsA(type)) ? w : 0; }
static inline float Alpha(RList *l, int n) { float a = 1.0f; if (n < l->Count()) a = (*l)[n].used ? 1.0f : 0.3f; return a; }
extern "C" void func_0034DD20(Self *self)
{
    W *grp;
    int i;
    char name[16];
    char text[64];

    func_00356CD0(self);
    func_00299510(&self->list);
    func_00333600(Agent_GetSelected(D_004FFB50, -1), &self->list);
    grp = GuiWidget_FindChildByName(self, D_00492BB8);
    if (grp == 0)
        return;
    for (i = 0; i < 24; i++) {
        sprintf(name, "%2.2d", i + 1);
        self->items[i] = Cast(GuiWidget_FindChildByName(grp, name), D_004B88F0);
        if (self->items[i]) {
            float alpha;
            sprintf(text, "0_%d_%ds.tdx", self->f64, i + 1);
            func_0043C890(self->items[i], text, D_004FFC04->f25C);
            self->items[i]->idx = i;
            self->items[i]->flags |= 0x80;
            alpha = Alpha(&self->list, i);
            self->items[i]->SetColor(QCol(1.0f, 1.0f, 1.0f, alpha));
        }
    }
}




