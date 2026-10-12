#include "types.h"
typedef struct { char pad[4]; unsigned short w; unsigned short h; } Pt2_Dim;
typedef struct { char pad[0x44]; Pt2_Dim* dim; } Pt2_Tex;
typedef struct { char pad[8]; Pt2_Tex** tex; } Pt2_TexTbl;
extern Pt2_TexTbl* D_00539248;
extern char D_005381F0[];
extern void Renderer_ClearRect(void*, int, int, int, int, int);
void RenderTarget_Clear(int* id, int arg1) {
    Pt2_Dim* d = (*(Pt2_Tex**)((int)D_00539248->tex + *id * 4))->dim;
    Renderer_ClearRect(D_005381F0, d->w, d->h, arg1, 1, 0);
}