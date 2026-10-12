#include "v4_asm_copy.h"
#include "vc_copy.h"
#include "vu0_ops.h"

typedef struct { float x, y, z, w; } V4_385420;
typedef struct { V4_385420 r[4]; } Mtx_385420;
typedef struct { V4_385420 trans; float m[3][4]; char pad[0x10]; } Attach_385420;
typedef struct {
    char pad0[0x14];
    unsigned char flag14;
    char pad15[3];
    char nodes[0x10];
    void* xform;
} Skel_385420;
typedef struct {
    char pad0[0x2450];
    unsigned char node[0x10];
    Attach_385420 attach[0x10];
    char pad[0x2C04 - 0x2460 - 0x10 * 0x50];
    Skel_385420* skel;
} Actor_385420;

extern void* Skeleton_NodeAt(void*, int);
extern void* func_0019F420(void*);
extern Mtx_385420* Transform_GetUpdated(void*);
extern void Actor_ShotFrameNodeWorld(Mtx_385420*, Mtx_385420*, Mtx_385420*);
extern void Mtx_Copy(Mtx_385420*, Mtx_385420*);

/* Indexing through an unsized-array view emits idx*0x50 + base (retail addu order). */
#define ATT(a, i) (*(Attach_385420(*)[])(a)->attach)[i]

void ActorRender_GetAttachPoint(Actor_385420* a, Mtx_385420* out, int i)
{
    Mtx_385420 node;
    Mtx_385420 m;
    Skel_385420* s = a->skel;
    int n = a->node[i];
    Attach_385420* at;
    Mtx_385420* pm;
    V4_385420* d;
    V4_385420* src;
    Mtx_385420* pn;

    if (s->flag14) {
        Mtx_385420* t = Transform_GetUpdated(func_0019F420(Skeleton_NodeAt(s->nodes, n)));
        Actor_ShotFrameNodeWorld(&node, t, Transform_GetUpdated(s->xform));
    } else {
        Mtx_Copy(&node, Transform_GetUpdated(s->xform));
    }
    d = &m.r[3];
    pm = &m;
    src = &ATT(a, i).trans;
    m.r[0].x = ATT(a, i).m[0][0];
    m.r[0].y = ATT(a, i).m[0][1];
    m.r[0].z = ATT(a, i).m[0][2];
    m.r[1].x = ATT(a, i).m[1][0];
    m.r[1].y = ATT(a, i).m[1][1];
    m.r[1].z = ATT(a, i).m[1][2];
    m.r[2].x = ATT(a, i).m[2][0];
    m.r[2].y = ATT(a, i).m[2][1];
    m.r[2].z = ATT(a, i).m[2][2];
    m.r[0].w = ATT(a, i).m[0][3];
    m.r[1].w = ATT(a, i).m[1][3];
    m.r[2].w = ATT(a, i).m[2][3];
    { __int128 q = V4Load(src); pn = &node; V4Store(d, q); }
    VU0_MulMtx44(out, pn, pm);
}






