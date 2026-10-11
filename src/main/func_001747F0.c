#pragma cplusplus on
struct O_47F0 { void* vt; char pad[0x1F0]; char m1F4[0x10]; char m204[0x10]; char m214[4]; };
extern "C" { extern char D_004D9BE0[]; void func_00175240(void* m, short f); void func_001363C0(void* m, short f); void cVUM_GOBJ_dtor(void* p, short f); void operator_delete(void* p); }
extern "C" O_47F0* func_001747F0(O_47F0* self, short del)
{
    if (self) {
        self->vt = D_004D9BE0;
        if (self->m214) func_001363C0(self->m214, -1);
        if (self->m204) { if (self->m204) { if (self->m204) func_00175240(self->m204, 0); } }
        if (self->m1F4) func_001363C0(self->m1F4, -1);
        cVUM_GOBJ_dtor(self, 0);
        if (del > 0) operator_delete(self);
    }
    return self;
}