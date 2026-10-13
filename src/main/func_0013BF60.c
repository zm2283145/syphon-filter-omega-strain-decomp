#pragma cplusplus on
extern "C" { void* func_0013BE20(void); void func_0013C270(void* a, void* b, void* c); void String_Dtor(void* p, short f); void operator_delete(void* p); }
extern "C" void* func_0013BF60(void* self, short del)
{
    if (self) {
        if (self) {
            func_0013C270(func_0013BE20(), self, self);
            if (self) String_Dtor(self, 0);
        }
        if (del > 0) operator_delete(self);
    }
    return self;
}