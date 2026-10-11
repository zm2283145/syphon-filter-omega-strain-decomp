#pragma cplusplus on
extern "C" void __destroy_array(void* block, void (*dtor)(void*, short), unsigned int size, unsigned int n)
{
    char* p = (char*)block + size * n;
    while (n) {
        p -= size;
        dtor(p, -1);
        n--;
    }
}