#pragma cplusplus on
#include "types.h"
extern "C" {
extern unsigned char D_005723C8;
int func_002EB650(void* out);
void* Object_LookupById(int*);
}
#pragma define_section GUARD_DTOR ".dtors_drop" far_absolute RX
struct Guard210780 {
    Guard210780() { if (!D_005723C8) D_005723C8 = 1; }
    __declspec(weak) __declspec(GUARD_DTOR) ~Guard210780() { D_005723C8 = 0; }
};
typedef struct { char pad[0x1C]; int* ids; } R210780;
extern "C" void func_00210780(void) {
    Guard210780 g;
    R210780* r;
    if (func_002EB650(&r) == 0) {
        int id = *r->ids;
        char* o = (char*)Object_LookupById(&id);
        if (o) *(int*)(o + 0x790) = 0;
    }
}