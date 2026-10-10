#include "types.h"
#pragma cplusplus on
class AiChk { public: virtual void c0(); virtual void c1(); virtual void c2(); virtual void c3(); virtual void c4(); virtual void c5(); virtual void c6(); virtual void c7(); virtual void c8(); virtual void c9(); virtual void c10(); virtual void c11(); virtual void c12(); virtual void c13(); virtual void c14(); virtual void c15(); virtual void c16(); virtual void c17(); virtual void c18(); virtual unsigned char IsReady(); };
struct AiSpawn { char p[0x58]; AiChk* chk; };
class AiSelf { public: virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void SetMode(int m); };
struct AiTimer { int a; int b; int c; unsigned char done; };
struct AiData { void* vt; char p4[0x40]; AiTimer t; char p54[4]; float f58; unsigned char b5c, b5d; };
extern "C" void Component_BaseInit(AiData*);
extern "C" int func_003CC950(AiSpawn*);
extern "C" char D_004D9890[];
inline int AiTimer_Pos(AiTimer* t) { return t->c > 0; }
inline void AiTimer_Init(AiTimer* t) { t->a = 0; t->c = 0; if (!AiTimer_Pos(t)) { t->b = 0; t->done = 1; t->c = 0; } }
inline unsigned char AiSpawn_Ready(AiSpawn* s) { unsigned char r = 0; if (s->chk && s->chk->IsReady()) r = 1; return r; }
extern "C" AiData* cAI_ctor(AiData* self, AiSpawn* s)
{
    int mode;
    Component_BaseInit(self);
    AiTimer_Init(&self->t);
    self->vt = D_004D9890;
    if (s && AiSpawn_Ready(s)) mode = func_003CC950(s);
    else mode = 4;
    ((AiSelf*)self)->SetMode(mode);
    self->f58 = -1.0f;
    self->b5c = 0;
    self->b5d = 0;
    return self;
}