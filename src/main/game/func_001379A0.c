#pragma cplusplus on
struct O_001379A0 { void* vt; char pad[0x24]; char m[4]; };
extern "C" {
extern "C" void func_0012ECE0();
extern "C" void func_0012ECF0();
extern "C" void func_0012ED00();
extern "C" void func_0012ED10();
extern "C" void func_0012ED20();
extern "C" void func_0012ED30();
extern "C" void func_0012ED40();
extern "C" void func_0012ED50();
extern "C" void func_001383D0();
extern "C" void func_00171600();
extern "C" void func_003CB1E0();
extern "C" void func_003CB1F0();
extern void * const D_004D9960[];
void func_00137A20(void* m, short f);
void Receiver_Destruct(void* p, short f);
void operator_delete(void* p);
}
extern "C" O_001379A0* func_001379A0(O_001379A0* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004D9960);
        if (self->m) func_00137A20(self->m, 0);
        Receiver_Destruct(self, 0);
        if (del > 0) operator_delete(self);
    }
    return self;
}
void * const D_004D9960[16] = { (void*)0x0, (void*)0x0, (void*)func_001379A0, (void*)func_00171600, (void*)func_0012ECE0, (void*)func_0012ECF0, (void*)func_001383D0, (void*)func_0012ED00, (void*)func_0012ED10, (void*)func_0012ED20, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)func_003CB1E0, (void*)func_003CB1F0, (void*)0x0 };
