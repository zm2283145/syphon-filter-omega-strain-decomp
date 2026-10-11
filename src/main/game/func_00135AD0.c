#pragma cplusplus on
struct O_00135AD0 { void* vt; char pad[0x1C]; char m20[0x10]; char m30[0xC]; char m3C[4]; };
extern "C" { extern char D_004D90A0[]; void func_00135B90(void* m, short f); void func_0013A130(void* m, short f); void Receiver_Destruct(void* p, short f); void operator_delete(void* p); }
extern "C" O_00135AD0* func_00135AD0(O_00135AD0* self, short del)
{
    if (self) {
        self->vt = D_004D90A0;
        if (self->m3C) func_00135B90(self->m3C, 0);
        if (self->m30) func_00135B90(self->m30, 0);
        if (self->m20) { if (self->m20) { if (self->m20) func_0013A130(self->m20, 0); } }
        Receiver_Destruct(self, 0);
        if (del > 0) operator_delete(self);
    }
    return self;
}