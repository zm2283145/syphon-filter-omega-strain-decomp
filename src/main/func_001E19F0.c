#include "types.h"
typedef struct { char pad[0xB0]; } B4Coll;
typedef struct { char pad0[0xC]; B4Coll* c; char pad1[0x990 - 0x10]; float f990; float f994; float f998; char b99C; char b99D; } B4Obj1;
extern void* RootCollection_FindByKey(void*, void*);
extern void* Root_GetWorldPlacement(void*);
extern float* Placement_GetPosition(void*);
extern char D_004A03D8[];
void func_001E19F0(B4Obj1* p) {
    float* pos = Placement_GetPosition(Root_GetWorldPlacement(RootCollection_FindByKey((char*)p->c + 0xB0, D_004A03D8)));
    p->b99D = p->f990 - pos[2] < 0.5f;
}