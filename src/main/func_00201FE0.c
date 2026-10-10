#include "types.h"
typedef struct { char data[0x30]; } Name;
typedef struct { char data[0x50]; } Binding;
typedef struct { int unused; } Handle;
extern char D_004A2F90[];
extern char D_004A2FA0[];
extern char D_004A2FB0[];
extern char D_004A2FC8[];
extern Name* CanonicalKey_Construct(Name* n, const char* s);
extern void func_003B3CC0(Binding* b, Name* n, void* obj, int a);
extern void MotionSlider_RegisterNode(Handle* h, void* obj, Name* n, Binding* b);
extern void func_003B28F0(Binding* b, int flags);
/* Registers two named bindings on the object. */
#pragma optimization_level 1
void func_00201FE0(void* obj)
{
    Binding bindY;
    Name nameC;
    Name nameD;
    Binding bindX;
    Name nameA;
    Name nameB;
    Handle h2;
    Handle h1;
    func_003B3CC0(&bindX, CanonicalKey_Construct(&nameA, D_004A2F90), obj, 1);
    MotionSlider_RegisterNode(&h1, obj, CanonicalKey_Construct(&nameB, D_004A2FA0), &bindX);
    func_003B28F0(&bindX, -1);
    func_003B3CC0(&bindY, CanonicalKey_Construct(&nameC, D_004A2FB0), obj, 1);
    MotionSlider_RegisterNode(&h2, obj, CanonicalKey_Construct(&nameD, D_004A2FC8), &bindY);
    func_003B28F0(&bindY, -1);
}
#pragma optimization_level reset
