#pragma cplusplus on
extern "C" void operator_delete(void*);
extern "C" void func_00138B70(void*, short);
extern "C" void* func_003282A0(void* self, short del)
{
    if (self) {
        char* m = (char*)self + 0x10;
        if (m) func_00138B70(m, 0);
        if (self) func_00138B70(self, 0);
        if (del > 0) operator_delete(self);
    }
    return self;
}