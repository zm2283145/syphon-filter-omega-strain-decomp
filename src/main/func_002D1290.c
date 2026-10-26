#pragma cplusplus on
struct V4 {
    float x, y, z, w;
    V4() {}
    V4& operator=(const V4& o) { V4* d = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(&o) : "memory"); return *this; }
};
struct P3 : V4 { P3(float a, float b, float c) { x = a; y = b; z = c; } };
struct P4 : V4 { P4(float a, float b, float c) { x = a; y = b; z = c; w = 1.0f; } };
struct Src2D1290 { char p0[8]; int a; int b; int c; float px, py, pz; float qx, qy, qz; int d; int e; };
struct Evt2D1290 { void* vt; char p4[0x2C]; V4 v30; V4 v40; int a50, a54, a58, a5C, a60; };
extern "C" {
extern char D_0051F058[];
extern char D_004DE240[];
void Event_Construct(Evt2D1290* e, void* type);
Evt2D1290* cNetGeneratorCreateMsg_ctor(Evt2D1290* self, Src2D1290* s);
}
extern "C" Evt2D1290* cNetGeneratorCreateMsg_ctor(Evt2D1290* self, Src2D1290* s) {
    Event_Construct(self, D_0051F058);
    self->vt = D_004DE240;
    self->a50 = s->a;
    self->a54 = s->b;
    self->a58 = s->c;
    self->v40 = P3(s->px, s->py, s->pz);
    self->v30 = P4(s->qx, s->qy, s->qz);
    self->a5C = s->d;
    self->a60 = s->e;
    return self;
}



