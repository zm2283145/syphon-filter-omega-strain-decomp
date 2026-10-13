#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#pragma mpwc_relax on

struct VC003EC4C0 { char vpad[12]; unsigned char dead; char pad[7]; virtual void v0(int); virtual void v1(float); };
extern "C" {
int func_00138DA0(...);
int func_0013B180(...);
int func_0015AF40(...);
int func_003EC3B0(...);
int func_003EC3C0(...);
int func_003EC3D0(...);
extern char D_0055C0A8;
}
extern "C" void func_003EC4C0(float dt) {
    int sp5C;
    char * sp58;
    char * sp54;
    int sp50;
    int sp4C;
    int sp48;
    int sp44;
    VC003EC4C0 * obj;
    char * temp_v0;
    char * var_s0;

    func_0013B180(&sp48, &D_0055C0A8);
    func_003EC3D0(&sp58, &sp48);
    var_s0 = sp58;
    func_003EC3C0(&sp44, &D_0055C0A8);
    func_003EC3B0(&sp5C, &sp44);
    if ((int)(var_s0) != (int)(sp5C)) {
        do {
            obj = F_(var_s0, 0x8, VC003EC4C0 *);
            obj->v1(dt);
            if (obj->dead) {
                if (obj != 0) {
                    obj->v0(1);
                }
                temp_v0 = var_s0;
                var_s0 = (char *)(F_(var_s0, 0x4, int));
                sp54 = temp_v0;
                func_0015AF40(&sp4C, &sp54);
                func_00138DA0(&sp50, &D_0055C0A8, &sp4C);
            } else {
                var_s0 = (char *)(F_(var_s0, 0x4, int));
            }
            func_003EC3C0(&sp44, &D_0055C0A8);
            func_003EC3B0(&sp5C, &sp44);
        } while ((int)(var_s0) != (int)(sp5C));
    }
}
