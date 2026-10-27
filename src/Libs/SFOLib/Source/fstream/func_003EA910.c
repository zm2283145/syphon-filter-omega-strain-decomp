#include "types.h"
typedef struct { int m0; char name[0x94]; int m98; } YA910;
typedef struct { int m0; unsigned char type; char pad[3]; YA910* y; } XA910;
typedef struct NA910 { int m0; struct NA910* next; XA910* data; } NA910;
extern void std_list_deleter_voidPtr_begin_void(int* out, void* list);
extern void std_list_cFSDataPtr_generic_iterator_ctor(NA910** out, int* in);
extern void std_list_cFSDataPtr_end(int* out, void* list);
extern void cLListIterator_cFSDataPtr_ctor(NA910** out, int* in);
extern int String_CompareNoCase(const char* a, const char* b);
XA910* cFileStreamMan_FindStreamData(void* self, YA910* key, int type)
{
    XA910* found = 0;
    NA910* e;
    NA910* it;
    int t1;
    int t2;
    XA910* x;
    int b;
    int a;
    NA910* n;
    std_list_deleter_voidPtr_begin_void(&t1, self);
    std_list_cFSDataPtr_generic_iterator_ctor(&it, &t1);
    for (n = it; std_list_cFSDataPtr_end(&t2, self), cLListIterator_cFSDataPtr_ctor(&e, &t2), n != e; n = n->next) {
        YA910* y;
        x = n->data;
        y = x->y;
        a = y->m98;
        b = key->m98;
        if ((unsigned char)type == x->type
            && !String_CompareNoCase(key->name, y ? y->name : 0)
            && (!b || !a || b == a)) {
            found = x;
            break;
        }
    }
    return found;
}