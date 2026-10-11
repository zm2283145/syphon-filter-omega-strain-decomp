#pragma cplusplus on

#include "types.h"

/* Deleting destructor of an animated root: restore placement, detach children. */
struct V4_396DF0 { __int128 q; };
struct VP_396DF0 { V4_396DF0 a, b; };
struct Root_396DF0 { unsigned char pad[0xB4]; int list; };

extern "C" {
int func_001A0280(Root_396DF0* r);
VP_396DF0* Root_GetWorldPlacement(Root_396DF0* r);
V4_396DF0* Root_GetWorldMotion(Root_396DF0* r);
VP_396DF0* func_001A0110(Root_396DF0* r);
void VecPair_Copy(VP_396DF0* dst, VP_396DF0* src);
void Vec4_Assign(V4_396DF0* dst, V4_396DF0* src);
void func_001A0080(Root_396DF0* r);
void Root_SetWorldPlacement(Root_396DF0* r, VP_396DF0* p);
void func_0019FFC0(Root_396DF0* r, V4_396DF0* m);
void func_0019FE90(Root_396DF0* r, VP_396DF0* p);
void* func_001913D0(Root_396DF0* r);
int func_0019FDE0(void* v);
int* PtrVec_Back(void* v);
void func_0019FDF0(Root_396DF0* r, int child);
void func_00397080(Root_396DF0* r);
void* func_00396F30(void* p, short deleteFlag);
void operator_delete(void* allocation);
}

extern "C" Root_396DF0* func_00396DF0(Root_396DF0* self, short deleteFlag)
{
    if (self) {
        if (func_001A0280(self)) {
            VP_396DF0 place;
            V4_396DF0 motion;
            VP_396DF0 other;
            VecPair_Copy(&place, Root_GetWorldPlacement(self));
            Vec4_Assign(&motion, Root_GetWorldMotion(self));
            VecPair_Copy(&other, func_001A0110(self));
            func_001A0080(self);
            Root_SetWorldPlacement(self, &place);
            func_0019FFC0(self, &motion);
            func_0019FE90(self, &other);
        }
        while (!func_0019FDE0(func_001913D0(self)))
            func_0019FDF0(self, *PtrVec_Back(func_001913D0(self)));
        if (self) {
            func_001A0080(self);
            func_00397080(self);
            func_00396F30(&self->list, -1);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}