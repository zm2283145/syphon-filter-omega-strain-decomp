#pragma cplusplus on
extern "C" void operator_delete(void*);
extern "C" void String_Dtor(void*, short);
extern "C" void std_vector_deleter_Slide_dtor(void*, short);
extern "C" void* GuiSlideShow_Section_dtor(void* self, short del)
{
    if (self) {
        char* m = (char*)self + 0xC;
        if (m) {
            if (m) {
                if (m) std_vector_deleter_Slide_dtor(m, 0);
            }
        }
        if (self) String_Dtor(self, 0);
        if (del > 0) operator_delete(self);
    }
    return self;
}