#include "types.h"
typedef struct { char pad[0xC]; unsigned char ready; } Obj_4D0910;
extern char D_004F8350[], D_004F8338[];
extern char cArray_cAirTaserPtr_dtor[];
extern signed char D_004EA0C8;
extern char* g_LosCheckService;
extern void std_vector_cAirTaserPtr_ctor(void* p);
extern void std_vector_cAirTaserPtr_reserve(void* p, int n);
extern int cArrayCapacity_Int(int* n);
extern void __register_global_object(void* obj, void* dtor, void* link);
void StaticInit_taser(void)
{
    {
        int n[1];
        Obj_4D0910* o = (Obj_4D0910*)D_004F8350;
        n[0] = 4;
        std_vector_cAirTaserPtr_ctor(o);
        std_vector_cAirTaserPtr_reserve(o, cArrayCapacity_Int(n));
        o->ready = 1;
        __register_global_object(o, cArray_cAirTaserPtr_dtor, D_004F8338);
    }
    if (!D_004EA0C8) {
        g_LosCheckService = "LOS Manager";
        D_004EA0C8 = 1;
    }
}