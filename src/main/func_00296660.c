#include "types.h"
typedef struct Col_00296660 { float r, g, b, a; } Col_00296660;
typedef struct W_00296660 { char pad[0x10]; int kind; unsigned short flags; } W_00296660;
typedef struct Ag_00296660 { char pad[0xB68]; unsigned char bB68; } Ag_00296660;
typedef struct S_00296660 {
    char pad0[0x198]; W_00296660* w198[6]; float f1B0; char pad1B4[0x1CC - 0x1B4]; int f1CC; char pad1D0[4];
    unsigned char state; char pad1D5[0x2EC - 0x1D5]; W_00296660* p2EC; W_00296660* p2F0; char pad2F4[0x2FC - 0x2F4];
    W_00296660* w2FC[10];
} S_00296660;
extern float D_004AA1F8;
extern char D_004FFB50[];
extern Col_00296660 D_00587B80;
extern Col_00296660 D_00587B90;
void func_00296A80(S_00296660* self);
void func_0033D310(S_00296660* self, float dt);
float Math_FMod(float x, float y);
void func_002986B0(float t, Col_00296660* out, Col_00296660* a, Col_00296660* b);
Ag_00296660* Agent_GetSelected(void* a, int b);
int func_00332860(Ag_00296660* ag, int a, int b);
int func_00332950(Ag_00296660* ag, int a, int b, int c);
void func_0041C070(W_00296660* w, Col_00296660* c);
/* abs.s has no C spelling in MW */
static inline float Fabs_00296660(float x) { float r; asm { abs.s r, x } return r; }

/* Per-frame update of a menu page: pulses the highlight colour of the enabled entries. */
void func_00296660(S_00296660* self, float dt)
{
    Col_00296660 col;
    Ag_00296660* ag;
int n;
int i;
    unsigned char st;
    func_00296A80(self);
    func_0033D310(self, dt);
    st = self->state;
    if (!(st == 1 || (unsigned int)(st - 3) <= 1 || st == 5))
        return;
    self->f1B0 += 33.333332f * dt;
    self->f1B0 = Math_FMod(self->f1B0, D_004AA1F8);
    func_002986B0(Fabs_00296660(1.0f - 2.0f * self->f1B0 / D_004AA1F8), &col, &D_00587B90, &D_00587B80);
    ag = Agent_GetSelected(D_004FFB50, -1);
    if (self->state == 4) {
        n = -1;
        if (self->f1CC < 0x11)
            n = self->f1CC + 1;
        else if (self->f1CC == 0x14)
            n = 0x12;
        if (n != -1) {
            for (i = 0; i < 6; i++) {
                if (self->w198[i]) {
                    if (func_00332860(ag, n, i))
                        func_0041C070(self->w198[i], &col);
                    else
                        func_0041C070(self->w198[i], &D_00587B80);
                }
            }
        } else {
            int j;
            for (j = 0; j < 6; j++) {
                if (self->w198[j])
                    func_0041C070(self->w198[j], &D_00587B80);
            }
        }
    }
    if (self->state == 3 && self->p2F0) {
        if (Agent_GetSelected(D_004FFB50, -1)->bB68)
            func_0041C070(self->p2F0, &col);
        else
            func_0041C070(self->p2F0, &D_00587B80);
    }
    if (self->state == 1 && self->p2EC) {
        if (self->f1CC < 0x11) {
            if (func_00332860(ag, self->f1CC + 1, -1))
                func_0041C070(self->p2EC, &col);
            else
                func_0041C070(self->p2EC, &D_00587B80);
        } else {
            func_0041C070(self->p2EC, &D_00587B80);
        }
    }
    if (self->state == 5) {
        int k;
        for (k = 0; k < 10; k++) {
            unsigned char on;
            W_00296660* w = self->w2FC[k];
            if (w && (w->flags & 2)) {
                on = 0;
                if (w->flags & 4) {
                    if (self->f1CC == 0x14) {
                        on = !func_00332950(ag, 0x12, 5, k);
                    } else {
                        switch (w->kind) {
                        case 2:
                            on = !func_00332950(ag, self->f1CC + 1, 5, 0);
                            break;
                        case 3:
                            on = !func_00332950(ag, self->f1CC + 1, 5, 2);
                            break;
                        case 4:
                        case 1:
                            on = !func_00332950(ag, self->f1CC + 1, 5, 1);
                            break;
                        }
                    }
                }
                if (on)
                    func_0041C070(self->w2FC[k], &col);
                else
                    func_0041C070(self->w2FC[k], &D_00587B80);
            }
        }
    }
}