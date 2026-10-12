#pragma cplusplus on
/* ActorObj_BuildNodeMatrix: rotation about +Z by the node angle, translated to the node position */
#include "types.h"
#include "v4_asm_copy.h"
#include "q4r.h"
struct NmV4 { float x, y, z, w; } __attribute__((aligned(16)));
struct NmMtx { NmV4 r[4]; };
struct NmNode { char pad[0x80]; float tx, ty, tz, angle; };
extern "C" {
float func_0015C280(NmV4* v);
float func_0015C290(NmV4* v);
float func_0015C2A0(NmV4* v);
float func_0015C2B0(NmV4* v);
NmMtx* Mtx_MakeAxisRotation(NmMtx* out, float x, float y, float z, float angle);
}
static inline void SetAA(NmV4* aa, NmV4* axis) {
    {
         float x; float z; float y; x = axis->x; z = axis->z; y = axis->y;
         aa->x = x; aa->y = y; aa->z = z;
    }
}
static inline void Set4(NmV4* o, float x, float y, float z, float w) { o->x = x; o->y = y; o->z = z; o->w = w; }
static inline void GetT(NmV4* out, NmNode* node) { float x; float y; float z; z = node->tz; y = node->ty; x = node->tx; Set4(out, x, y, z, 1.0f); }
#pragma opt_common_subs off
extern "C" void ActorObj_BuildNodeMatrix(NmMtx* out, NmNode* n)
{
    NmV4 aa;
    NmMtx m;
    NmV4 axis;
    NmV4 pos;
    aa.w = n->angle;
    axis.x = 0.0f; axis.y = 0.0f; axis.z = 1.0f; axis.w = 0.0f;
    SetAA(&aa, &axis);
    {
        float x = func_0015C2B0(&aa);
        float y = func_0015C2A0(&aa);
        float z = func_0015C290(&aa);
        float w = func_0015C280(&aa);
        Mtx_MakeAxisRotation(&m, x, y, z, w);
    }
    GetT(&pos, n);
    {   __int128 qa; NmMtx* src; __int128 qb; NmV4* pd; NmV4* ps; __int128 t; ps = &pos; pd = &m.r[3]; asm { .set noreorder; lq t, 0(ps); .set reorder } src = &m; asm { .set noreorder; sq t, 0(pd); lq qa, 0x0(src); lq qb, 0x10(src); sq qa, 0x0(out); lq qa, 0x20(src); sq qb, 0x10(out); lq qb, 0x30(src); sq qa, 0x20(out); sq qb, 0x30(out); .set reorder } }
}