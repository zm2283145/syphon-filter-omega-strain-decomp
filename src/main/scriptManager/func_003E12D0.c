#include "types.h"
typedef struct { char pad[0x80]; const char* path; } S12D0;
typedef struct N12D0 { int m0; struct N12D0* next; S12D0* data; } N12D0;
typedef struct { char pad[0xC]; int list; } T12D0;
extern void std_list_deleter_voidPtr_begin_void(int* out, void* list);
extern void std_list_SymbolTablePtr_generic_iterator_ctor(N12D0** out, int* in);
extern void std_list_SymbolTablePtr_end(int* out, void* list);
extern void cLListIterator_SymbolTablePtr_ctor(N12D0** out, int* in);
extern const char* stripPathAndExt(const char* p);
extern void Libc_Strcpy(char* d, const char* s);
extern int String_CompareNoCase(const char* a, const char* b);
S12D0* cScriptInterpreter_findContext(T12D0* self, const char* path)
{
    N12D0* e;
    N12D0* it;
    int t1;
    int t2;
    char buf[256];
    S12D0* s;
    N12D0* n;
    Libc_Strcpy(buf, stripPathAndExt(path));
    std_list_deleter_voidPtr_begin_void(&t1, &self->list);
    std_list_SymbolTablePtr_generic_iterator_ctor(&it, &t1);
    for (n = it; std_list_SymbolTablePtr_end(&t2, &self->list), cLListIterator_SymbolTablePtr_ctor(&e, &t2), n != e; n = n->next) {
        s = n->data;
        if (!String_CompareNoCase(stripPathAndExt(s->path), buf))
            return s;
    }
    return 0;
}