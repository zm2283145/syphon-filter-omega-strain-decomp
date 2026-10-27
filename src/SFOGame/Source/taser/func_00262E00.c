#include "types.h"
#pragma cplusplus on
struct A2V262 { virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B(); virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void f64(void*, int, int); };
typedef struct { char pad[0x58]; A2V262* v; } A2P262;
typedef struct { int pad0; A2P262* p; char b8; char pad9[7]; int f10; int n14; } A2S262;
extern int D_0048B168;
static const float dat_0048B140[2] = { 50.0f, 0.0f };
extern "C" void* details_compressed_pair_imp_cAllocator_TaserPoint_int_1_first(void* p);
extern "C" void cAirTaser_PointsToLocal(A2S262* s, void* b);
extern "C" void cAirTaser_AddWhipAction(A2S262* s, float dt);
extern "C" void cAirTaser_PointsToWorld(A2S262* s, void* b);
extern "C" void cAirTaser_SmoothLine(A2S262* s, float f, int x);
extern "C" void cAirTaser_UpdateRetract(A2S262* s, float dt) {
    int n = s->n14;
    int i = 0;
    int* po;
    int out[4];
    int buf[12];
    while (!!n && i < D_0048B168) {
        s->n14--;
        details_compressed_pair_imp_cAllocator_TaserPoint_int_1_first(&s->f10);
        i++;
        n--;
    }
    if (n > 1) {
        s->p->v->f64(buf, 0, 0);
        po = out;
        cAirTaser_PointsToLocal(s, po);
        if ((float)n < (*(float*)dat_0048B140)) cAirTaser_AddWhipAction(s, dt);
        cAirTaser_PointsToWorld(s, po);
    }
    cAirTaser_SmoothLine(s, 1.0f, 1);
    if (n == 0) s->b8 = 0;
}




