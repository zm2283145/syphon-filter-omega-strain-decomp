#pragma cplusplus on
#pragma exceptions on
extern "C" void Libc_Free(void *p);
extern "C" void operator_delete(void *p) throw()
{
    Libc_Free(p);
}
