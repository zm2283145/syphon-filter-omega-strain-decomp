#pragma cplusplus on
typedef void (*CD_001004B0)(void*, short);
#pragma define_section DROPDTOR ".dtors_drop" far_absolute RX
class PAD_001004B0 {
public:
    void* p; unsigned int size; unsigned int n; CD_001004B0 dtor; unsigned int i;
    PAD_001004B0(void* a, unsigned int s, unsigned int c, CD_001004B0 d) { p = a; size = s; n = c; dtor = d; i = n; }
    __declspec(weak) __declspec(DROPDTOR) ~PAD_001004B0() {
        if (i < n && dtor) {
            char* cptr = (char*)p + size * i;
            for (; i > 0; i--) { cptr -= size; dtor(cptr, -1); }
        }
    }
};
extern "C" void __construct_array(void* block, CD_001004B0 ctor, CD_001004B0 dtor, unsigned int size, unsigned int n)
{
    PAD_001004B0 pad(block, size, n, dtor);
    char* cp = (char*)block;
    for (pad.i = 0; pad.i < n; pad.i++, cp += size)
        ctor(cp, 1);
}
