#include "types.h"

/* Relocate the texture's image data and build its GS registers. */
typedef struct { int data; int pad; int altData; } Tex_3809E0;
extern void* D_00539248;
extern int Tdx_Relocate(void* tdx, int data, int* extra);
extern void Tex_BuildGsRegisters(void* out, void* out2, int data, int extra);

void func_003809E0(Tex_3809E0* t, void* out)
{
    int extra = 0;
    int d = t->altData ? t->altData : t->data;
    {
        int r = Tdx_Relocate(D_00539248, d, &extra);
        Tex_BuildGsRegisters(out, out, r, extra);
    }
}