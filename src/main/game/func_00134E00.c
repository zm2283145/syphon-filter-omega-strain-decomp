#pragma cplusplus on
struct O_00134E00 { void* vt; char m4[0x10]; char m14[4]; };
extern "C" { extern char D_004DA2F0[]; extern char D_004D9140[]; void func_00134FD0(void* m, short f); void func_00134E80(void* m, short f); void operator_delete(void* p); }
extern "C" O_00134E00* func_00134E00(O_00134E00* self, short del)
{
    if (self) {
        self->vt = D_004DA2F0;
        if (self) {
            self->vt = D_004D9140;
            func_00134FD0(self->m14, -1);
            func_00134E80(self->m4, -1);
        }
        if (del > 0) operator_delete(self);
    }
    return self;
}