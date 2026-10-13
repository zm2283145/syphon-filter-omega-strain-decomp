#pragma cplusplus on
#include "types.h"
#define V5(a) virtual void a##0(); virtual void a##1(); virtual void a##2(); virtual void a##3(); virtual void a##4();
#define V25(a) V5(a##a) V5(a##b) V5(a##c) V5(a##d) V5(a##e)
struct Tgt {
    V25(x) V25(y) V5(za) V5(zb) virtual void q0(); virtual void q1(); virtual void q2(); virtual void q3();
    virtual unsigned char State();
    int pad4[2]; int id;
};
struct Hnd { Tgt* p; int id; };
struct LNode { LNode* prev; LNode* next; Hnd h; };
struct Gen;
extern "C" {
LNode* func_0021EDE0(LNode* n);
LNode* func_0021E000(void* l);
LNode** func_0021DFE0(LNode** it, LNode* n);
void func_0043B190(void* ctx);
int func_0043AA40(void* ctx, void* key);
int func_0042B1A0(int);
int NpcAi_CountThinking(void);
unsigned char Generator_SpawnTest(Gen* g, Gen* s);
void Generator_Spawn(Gen* g, Gen* s, int i);
extern int D_004EA350;
extern int D_004F56B8;
extern unsigned char D_005721C8;
void cGenerator_v10(Gen* self, float dt);
}
struct Gen {
    V5(a) V5(b) V5(c) V5(d) V5(e)
    virtual int CanSpawn();
    char pad4[8]; char key[0x78 - 0xC]; int n78; Gen** arr; int pad80; float f84; int n88; int n8C;
    int list90; LNode head; char padA4[0x18]; float fBC; int nC0; int nC4; int nC8; char padCC[4]; unsigned char bD0; unsigned char bD1;
};
static inline bool Valid(Hnd* h) {
    return !h->p || h->p->id == h->id;
}
static inline Tgt* HGet(Hnd* h) {
    return Valid(h) ? h->p : 0;
}
void cGenerator_v10(Gen* self, float dt)
{
    char ctx[4];
    LNode* end;
    int cnt = 0;
    LNode* n = func_0021EDE0(&self->head)->next;
    self->fBC += dt;
    func_0021DFE0(&end, func_0021E000(&self->list90));
    while (n != end) {
        Hnd* h = &n->h;
        Tgt* t = HGet(h);
        if (t && t->State() != 3) cnt++;
        n = n->next;
        func_0021DFE0(&end, func_0021E000(&self->list90));
    }
    func_0043B190(ctx);
    if (self->bD1) return;
    if (D_005721C8) {
        if (!func_0043AA40(ctx, self->key)) return;
        if (!(D_004F56B8 < func_0042B1A0(1))) return;
    }
    if (!(D_004EA350 > NpcAi_CountThinking())) return;
    if (!self->CanSpawn()) return;
    if (!(self->nC0 < self->n8C)) return;
    if (self->fBC <= self->f84) return;
    if (!(cnt < self->n88)) return;
    Gen* s;
    int nn = self->n78;
    if (nn == 0) {
        s = self;
    } else {
        if (!self->bD0) {
            int c = self->nC4 + 1;
            self->nC4 = c;
            self->nC4 = c % nn;
        }
        s = self->arr[self->nC4];
    }
    unsigned char r = Generator_SpawnTest(self, s);
    if (r == 1) {
        Generator_Spawn(self, s, self->n78 ? self->nC4 : -1);
        D_004F56B8 = func_0042B1A0(1) + 250;
    } else if (r == 0) {
        if (self->nC8 == self->nC4) self->fBC = self->f84 - 1.0f;
    }
}