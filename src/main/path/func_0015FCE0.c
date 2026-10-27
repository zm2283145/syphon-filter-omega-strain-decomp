#pragma opt_propagation off
#include "types.h"
/* cPathNavigator_PathFloorZ: height along the current path segment (node height, interpolated, or clamped) */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) Pt1PhV4;
typedef struct Pt1PhPath {
    char pad0[0x8];
    float fromHeight;
    char padC[0x28 - 0xC];
    float toHeight;
    char pad2C[0x40 - 0x2C];
    float dist;
    float length;
    char pad48[0x4C - 0x48];
    int node;
    int segB;
    int segA;
} Pt1PhPath;
extern void* cAIPathData_GetNode(int node);
extern void cNode_GetLoc(Pt1PhV4* out, void* node);
static inline float Pt1Ph_Min(float a, float b) { float r; asm { min.s r, a, b } return r; }
#pragma fp_contract off
static inline float Mul(float x,float y) {return x*y;}
float cPathNavigator_PathFloorZ(Pt1PhPath* p, int clamp, int useNode)
{
    float r;
    if (p->node >= 0 && !useNode) {
        Pt1PhV4 v;
        cNode_GetLoc(&v, cAIPathData_GetNode(p->node));
        r = v.z;
    } else if (p->segA >= 0 && p->segB >= 0) {
        float d;
        float len;
        if (clamp || !((len = p->length, d = p->dist) <= 1.0f + len) || useNode)
            r = Pt1Ph_Min(p->toHeight, p->fromHeight);
        else
        {
            r = p->toHeight * d;
            r = r + Mul(p->fromHeight,(len-d));
            r = r / len;
        }
    } else {
        r = p->toHeight;
    }
    return r;
}