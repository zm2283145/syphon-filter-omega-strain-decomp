#pragma cplusplus on
struct O_47F0 { void* vt; char pad[0x1F0]; char m1F4[0x10]; char m204[0x10]; char m214[4]; };
extern "C" { extern char D_004D9BE0[]; void std_vector_deleter_cObjectId_dtor(void* m, short f); void std_vector_cGOBJPtr_dtor(void* m, short f); void cVUM_GOBJ_dtor(void* p, short f); void operator_delete(void* p); }
extern "C" O_47F0* cTerrain_dtor(O_47F0* self, short del)
{
    if (self) {
        self->vt = D_004D9BE0;
        if (self->m214) std_vector_cGOBJPtr_dtor(self->m214, -1);
        if (self->m204) { if (self->m204) { if (self->m204) std_vector_deleter_cObjectId_dtor(self->m204, 0); } }
        if (self->m1F4) std_vector_cGOBJPtr_dtor(self->m1F4, -1);
        cVUM_GOBJ_dtor(self, 0);
        if (del > 0) operator_delete(self);
    }
    return self;
}