#pragma cplusplus on
struct O_001379A0 { void* vt; char pad[0x4C]; char m[4]; };
extern "C" { extern char D_004E0FC0[]; void func_00138B70(void* m, short f); void func_0041F370(void* p, short f); void operator_delete(void* p); }
extern "C" O_001379A0* func_0043C030(O_001379A0* self, short del)
{
    if (self) {
        self->vt = D_004E0FC0;
        if (self->m) func_00138B70(self->m, 0);
        func_0041F370(self, 0);
        if (del > 0) operator_delete(self);
    }
    return self;
}