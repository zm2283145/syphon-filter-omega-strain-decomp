#include "types.h"

extern void func_00206B50(void* self);
extern void func_00206830(void* self);
extern void func_002064D0(void* self);
extern void func_002060A0(void* self);
extern void func_00205C30(void* self);
extern void func_002057F0(void* self);
extern void func_00204FC0(void* self);
extern void func_00204C90(void* self);
extern void func_00203DD0(void* self);
extern void func_002020E0(void* self);
extern void func_00201FE0(void* self);
extern void MotionGraph_BuildCore(void* self);
extern void func_001F4530(void* self);
extern void func_001F1360(void* self);
extern void func_001F05F0(void* self);
extern void func_001EFE70(void* self);
extern void func_001EFC50(void* self);

/* Runs every registration step on self in order. */
#pragma optimization_level 1
void func_001EFB60(void* self)
{
    func_00206B50(self);
    func_00206830(self);
    func_002064D0(self);
    func_002060A0(self);
    func_00205C30(self);
    func_002057F0(self);
    func_00204FC0(self);
    func_00204C90(self);
    func_00203DD0(self);
    func_002020E0(self);
    func_00201FE0(self);
    MotionGraph_BuildCore(self);
    func_001F4530(self);
    func_001F1360(self);
    func_001F05F0(self);
    func_001EFE70(self);
    func_001EFC50(self);
}
#pragma optimization_level reset
