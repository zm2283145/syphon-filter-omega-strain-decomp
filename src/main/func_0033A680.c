typedef struct { int cap; unsigned int size; char* buf; } V3A680;
extern void* memcpy(void* d, const void* s, unsigned int n);
char* func_0033A680(V3A680* v, char* first, char* last)
{
    unsigned int n;
    if (first == last)
        return first;
    n = (v->buf + v->size) - last;
    if (n)
        memcpy(first, last, n);
    v->size -= last - first;
    return first;
}