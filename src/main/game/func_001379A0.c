#pragma cplusplus on
struct O_001379A0 { void* vt; char pad[0x24]; char m[4]; };
extern "C" { extern char D_004D9960[]; void func_00137A20(void* m, short f); void Receiver_Destruct(void* p, short f); void operator_delete(void* p); }
extern "C" O_001379A0* func_001379A0(O_001379A0* self, short del)
{
    if (self) {
        self->vt = D_004D9960;
        if (self->m) func_00137A20(self->m, 0);
        Receiver_Destruct(self, 0);
        if (del > 0) operator_delete(self);
    }
    return self;
}