#pragma cplusplus on
struct O_001384E0 { void* vt; char pad[0x1C]; char m20[0x10]; char m30[0xC]; char m3C[4]; };
extern "C" { extern char D_004D9100[]; extern char D_004D90A0[]; void func_00135F50(void* m, short f); void func_00135FB0(void* m, short f); void Receiver_Destruct(void* p, short f); void operator_delete(void* p); }
extern "C" O_001384E0* func_001384E0(O_001384E0* self, short del)
{
    if (self) {
        self->vt = D_004D9100;
        if (self) {
            self->vt = D_004D90A0;
            func_00135F50(self->m3C, -1);
            func_00135F50(self->m30, -1);
            func_00135FB0(self->m20, -1);
            Receiver_Destruct(self, 0);
        }
        if (del > 0) operator_delete(self);
    }
    return self;
}