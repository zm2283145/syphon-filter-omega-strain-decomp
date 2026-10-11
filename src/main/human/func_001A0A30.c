#include "types.h"
typedef struct { Q a; Q b; } VP_1A0A30;
typedef struct { Q a; } V4_1A0A30;
extern int func_001A0280(void* self);
extern VP_1A0A30* Root_GetWorldPlacement(void* self);
extern V4_1A0A30* Root_GetWorldMotion(void* self);
extern VP_1A0A30* func_001A0110(void* self);
extern void VecPair_Copy(VP_1A0A30* d, VP_1A0A30* s);
extern void Vec4_Assign(V4_1A0A30* d, V4_1A0A30* s);
extern void func_001A0080(void* self);
extern void Root_SetWorldPlacement(void* self, VP_1A0A30* p);
extern void func_0019FFC0(void* self, V4_1A0A30* m);
extern void func_0019FE90(void* self, VP_1A0A30* p);
void func_001A0A30(void* self)
{
    VP_1A0A30 place;
    V4_1A0A30 motion;
    VP_1A0A30 other;
    if (func_001A0280(self)) {
        VecPair_Copy(&place, Root_GetWorldPlacement(self));
        Vec4_Assign(&motion, Root_GetWorldMotion(self));
        VecPair_Copy(&other, func_001A0110(self));
        func_001A0080(self);
        Root_SetWorldPlacement(self, &place);
        func_0019FFC0(self, &motion);
        func_0019FE90(self, &other);
    }
}