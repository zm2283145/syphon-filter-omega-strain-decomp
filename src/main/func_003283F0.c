#pragma cplusplus on
extern "C" void operator_delete(void*);
extern "C" void func_00138B70(void*, short);
extern "C" void func_0032A110(void*, short);
extern "C" void* func_003283F0(void* self, short del)
{
    if (self) {
        char* m = (char*)self + 0xC;
        if (m) {
            if (m) {
                if (m) func_0032A110(m, 0);
            }
        }
        if (self) func_00138B70(self, 0);
        if (del > 0) operator_delete(self);
    }
    return self;
}