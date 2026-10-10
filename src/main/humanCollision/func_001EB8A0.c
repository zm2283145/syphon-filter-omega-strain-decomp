#include "types.h"
#define FLT_MAX 3.4028235e38f
typedef struct { int v; } Ref;
typedef struct {
    signed char id;         /* 0x00 */
    char pad1[3];
    Ref refs[4];            /* 0x04..0x10 */
    float minX, maxX;       /* 0x14 */
    float minY, maxY;       /* 0x1C */
    float minZ, maxZ;       /* 0x24 */
    unsigned char b2C;      /* 0x2C */
    char pad2D[3];
    unsigned char b30, b31, b32; /* 0x30 */
    char pad33[0x3D];
    unsigned char b70;      /* 0x70 */
    char pad71[0x1F];
    int i90, i94, i98;      /* 0x90 */
    int pad9C;
    int iA0;                /* 0xA0 */
    char padA4[0x3C];
    float fE0;              /* 0xE0 */
    int iE4;                /* 0xE4 */
} HumanColPreset;
extern void func_001EB2C0(Ref* r, int v);
extern void func_001EB960(Ref* r, int v);
/* Constructor: clears references and sets empty bounds. */
HumanColPreset* HumanColPreset_Ctor(HumanColPreset* p)
{
    Ref* refs;
    p->id = -1;
    refs = p->refs;
    func_001EB2C0(&refs[0], 0);
    func_001EB2C0(&refs[1], 0);
    func_001EB960(&refs[2], 0);
    func_001EB960(&refs[3], 0);
    p->minX = -FLT_MAX;
    p->maxX = FLT_MAX;
    p->minY = -FLT_MAX;
    p->maxY = FLT_MAX;
    p->minZ = -FLT_MAX;
    p->maxZ = FLT_MAX;
    p->b2C = 0;
    p->b30 = 0;
    p->b31 = 0;
    p->b32 = 0;
    p->b70 = 0;
    p->i90 = -1;
    p->i94 = -1;
    p->i98 = 0;
    p->iA0 = 0;
    p->fE0 = -FLT_MAX;
    p->iE4 = 0;
    return p;
}
