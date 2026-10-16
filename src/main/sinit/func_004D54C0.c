#include "types.h"
typedef struct { float x, y, z, w; } V4_4D54C0;
extern V4_4D54C0 D_004BC550;
extern V4_4D54C0 D_0053B660;
extern V4_4D54C0 D_0053B670;
extern struct { int n; float v[0x103]; } D_0053B6A0;
extern char D_0053B544[], D_0053B540[], D_0053B528[];
extern char func_003A6240[];
extern void ScalarCollection_Init(void* p);
extern void __register_global_object(void* obj, void* dtor, void* link);
extern int Random_Next(void);
void StaticInit_ParticleRandomTable(void)
{
    int i;
    ScalarCollection_Init(D_0053B544);
    __register_global_object(D_0053B540, func_003A6240, D_0053B528);
    D_004BC550.x = 0.0f;
    D_004BC550.y = 0.0f;
    D_004BC550.z = 1.0f;
    D_004BC550.w = 1.0f;
    D_0053B660.x = 3.4028234663852886e38f;
    D_0053B660.y = 3.4028234663852886e38f;
    D_0053B660.z = 3.4028234663852886e38f;
    D_0053B660.w = 1.0f;
    D_0053B670.w = 1.0f;
    D_0053B670.x = -3.4028234663852886e38f;
    D_0053B670.y = -3.4028234663852886e38f;
    D_0053B670.z = -3.4028234663852886e38f;
    D_0053B6A0.n = 0;
    for (i = 0; i < 0x103; i++) {
        D_0053B6A0.v[i] = (float)Random_Next();
        D_0053B6A0.v[i] = D_0053B6A0.v[i] * 4.656612873077393e-10f;
    }
}