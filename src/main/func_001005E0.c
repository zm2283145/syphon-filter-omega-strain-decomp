#pragma cplusplus on
typedef void (*CD_001005E0)(void*, short);
#pragma define_section DROPDTOR ".dtors_drop" far_absolute RX
class PAD_001005E0 {
public:
    void* p; unsigned int size; unsigned int n; CD_001005E0 dtor; unsigned int i;
    PAD_001005E0(void* a, unsigned int s, unsigned int c, CD_001005E0 d) { p = a; size = s; n = c; dtor = d; i = n; }
    __declspec(weak) __declspec(DROPDTOR) ~PAD_001005E0() {
        if (i < n && dtor) {
            char* cptr = (char*)p + size * i;
            for (; i > 0; i--) { cptr -= size; dtor(cptr, -1); }
        }
    }
};
extern "C" void* func_001005E0(void* block, CD_001005E0 ctor, CD_001005E0 dtor, unsigned int size, unsigned int n)
{
    char* ptr;
    if ((ptr = (char*)block) != 0) {
        unsigned int* p = (unsigned int*)ptr;
        p[0] = size;
        p[1] = n;
        ptr += 16;
        if (ctor) {
            PAD_001005E0 pad(ptr, size, n, dtor);
            char* cp = ptr;
            for (pad.i = 0; pad.i < n; pad.i++, cp += size)
                ctor(cp, 1);
        }
    }
    return ptr;
}
