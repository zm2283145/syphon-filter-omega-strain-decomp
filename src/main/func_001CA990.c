#include "types.h"
#include "vu0_scale_eq.h"
typedef struct { char pad[0x10]; VSE4 v; } E20;
typedef struct { char pad[0x40]; float f40; } Obj;
typedef struct { VSE4 a; VSE4 b; signed char c; } Src;
typedef struct { E20 e[2]; float w; float inv; char pad48[8]; Obj* obj; float e4; char pad58[0x78]; } LayerA;
typedef struct { E20 e[2]; float w; float inv; char pad48[8]; Obj* obj; float e4; } LayerB;
typedef struct {
    VSE4 a; VSE4 b; signed char c; char pad21[0x6F];
    LayerA la; LayerB lb;
} SA;
E20* cHermiteSpline_cQuaternion_ControlPoint(E20* base, int index);
char* cHermiteSpline_cVector_ControlPoint(char* base, int i);
#pragma push
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
static inline void LayerA_SetWeight(LayerA* l, float t)
{
    float k; float r;
    if (t < 0.0f) return;
    k = t * l->inv;
    VU0_ScaleEq(&cHermiteSpline_cQuaternion_ControlPoint(l->e, 0)->v, k);
    VU0_ScaleEq(&cHermiteSpline_cQuaternion_ControlPoint(l->e, 1)->v, k);
    l->w = t;
    r = 0.0f; if (r != t) r = 1.0f / t; else asm { .set reorder } l->inv = r;
    l->e4 = l->obj->f40;
}
static inline void LayerB_SetWeight(LayerB* l, float t)
{
    float k; float r;
    if (t < 0.0f) return;
    k = t * l->inv;
    VU0_ScaleEq(&((E20*)cHermiteSpline_cVector_ControlPoint((char*)l->e, 0))->v, k);
    VU0_ScaleEq(&((E20*)cHermiteSpline_cVector_ControlPoint((char*)l->e, 1))->v, k);
    l->w = t;
    r = 0.0f; if (r != t) r = 1.0f / t; else asm { .set reorder } l->inv = r;
    l->e4 = l->obj->f40;
}
void SecondaryAim_SetLayerSource(SA* self, float w, Src* src)
{
    asm { .set reorder } /* barrier: keeps the copy below the prologue, as in retail */
    self->a = src->a;
    self->b = src->b;
    self->c = src->c;
    LayerA_SetWeight(&self->la, w);
    LayerB_SetWeight(&self->lb, w);
}
#pragma pop




