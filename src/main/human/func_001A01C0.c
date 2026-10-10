#include "types.h"
typedef struct { float m[4][4]; } Mtx_e1;
typedef struct { char pad[0x20]; float pos[4]; char pad30[0x40]; float wpos[4]; char pad80[0x21]; unsigned char dirty; char padA2[0xE]; void* motion; } RootIdn_e1;
extern RootIdn_e1* Root_Identity(void*);
extern void* Root_GetParent(void*);
extern void* Root_GetWorldPlacement(void*);
extern void Vec4_Copy(float*, float*);
extern Mtx_e1* Placement_ToMatrix(Mtx_e1*, void*);
extern void Mtx_TransformByTranspose(float*, Mtx_e1*);
float* Root_GetWorldMotion(RootIdn_e1* self)
{
    Mtx_e1 m;
    void* pl;
    if (self->motion != 0) {
        if (Root_Identity(self)->dirty) {
            pl = Root_GetWorldPlacement(Root_GetParent(self));
            Vec4_Copy(Root_Identity(self)->pos, Root_Identity(self)->wpos);
            Mtx_TransformByTranspose(Root_Identity(self)->pos, Placement_ToMatrix(&m, pl));
            Root_Identity(self)->dirty = 0;
        }
        return self->pos;
    }
    return self->wpos;
}