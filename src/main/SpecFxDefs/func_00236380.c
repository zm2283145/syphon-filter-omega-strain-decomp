#pragma cplusplus on
struct V4 {
    float x, y, z, w;
    V4& operator=(const V4& o) { V4* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(&o) : "memory"); return *this; }
};
struct M4 { V4 r[3]; V4 t; };
struct Ent236380 { void* obj; char p4[0xC]; V4 pos; };
struct Sub236380 { char p0[0x38]; int x38; };
struct Self236380 {
    char p0[0x74];
    Sub236380* x74;
    char p78[4];
    Ent236380** x7C;
    char p80[4];
    int x84;
};
extern "C" {
void cParticle_Render(void* obj, int a, M4* m);
void cHumanParticleGroup_Render(Self236380* self);
}
static inline void UM(void* m) { void* p = m; int t; __asm__ volatile("sqc2 $vf0, 0x30(%1); qmfc2.ni %0, $vf0; pcpyud %0, %0, $zero; sq %0, 0x10(%1); pexcw %0, %0; sq %0, 0x20(%1); pcpyud %0, %0, $zero; sq %0, 0x0(%1)" : "=&r"(t) : "r"(p) : "memory"); }
extern "C" void cHumanParticleGroup_Render(Self236380* self) {
    int i;
    for (i = 0; i < self->x84; i++) {
        if (self->x7C[i]->obj) {
            M4 m;
            UM(&m);
            m.t = self->x7C[i]->pos;
            { Sub236380* s = self->x74; cParticle_Render(self->x7C[i]->obj, s->x38, &m); }
        }
    }
}


