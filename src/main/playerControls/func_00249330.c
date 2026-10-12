#pragma cplusplus on
#include "types.h"
#include "curve_count_down.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
extern "C" int Player_ClearRecentTargets(int *, char *, int *, char **);
typedef struct { int v; } H;
typedef struct { char pad[0xC8]; int c8; H cc; char padD0[0xE4-0xD0]; CurveCountDown cd; char list[4]; char* sent; int first; } T;
/* .word 0x46000006 is mov.s $f0,$f0: CW deletes the self-move of the max.s idiom after a branch. */
static inline float Max3_(float a, float b) { float r; asm { .word 0x46000006
 max.s r, b, a } return r; }
static inline int CD(CurveCountDown* p, float dt) { float old = p->remaining; p->remaining -= dt; p->remaining = Max3_(p->remaining, 0.0f); return old > 0.0f && p->remaining == 0.0f; }
static inline char* Identity(char*a){return a;}
static inline void clr0(char*a){int r;int f;char*l;l=Identity(a+0xF0);f=F_(a,0xF4,int);Player_ClearRecentTargets(&r,a+0xEC,&f,&l);}
static inline void setH(H* d, int v) { H h; H* hp; h.v = v; hp = &h; *d = *hp; }
#pragma push
#pragma opt_propagation off
extern "C" void Targeting_LockTimer(T* o, float dt)
{
    if (o->cd.remaining > 0.0f) {
        CD(&o->cd, dt);
    } else {
        clr0((char*)o);
        o->c8 = 0;
        setH(&o->cc, -1);
        o->cd.pad0 = -1;
    }
}
#pragma pop





