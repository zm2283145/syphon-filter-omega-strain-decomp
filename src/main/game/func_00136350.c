#pragma cplusplus on
struct O_00136350 { void* vt; char m[4]; };
extern "C" { extern char D_004D9140[]; void func_001363C0(void* m, short f); void operator_delete(void* p); }
extern "C" O_00136350* func_00136350(O_00136350* self, short del)
{
    if (self) {
        self->vt = D_004D9140;
        if (self->m) func_001363C0(self->m, -1);
        if (del > 0) operator_delete(self);
    }
    return self;
}