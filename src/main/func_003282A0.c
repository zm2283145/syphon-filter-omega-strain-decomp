#pragma cplusplus on
extern "C" void operator_delete(void*);
extern "C" void String_Dtor(void*, short);
extern "C" void* func_003282A0(void* self, short del)
{
    if (self) {
        char* m = (char*)self + 0x10;
        if (m) String_Dtor(m, 0);
        if (self) String_Dtor(self, 0);
        if (del > 0) operator_delete(self);
    }
    return self;
}