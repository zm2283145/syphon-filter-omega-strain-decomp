#include "types.h"
typedef struct { int m0; char name[0x94]; int m98; } YA910;
typedef struct { int m0; unsigned char type; char pad[3]; YA910* y; } XA910;
typedef struct NA910 { int m0; struct NA910* next; XA910* data; } NA910;
extern void List_Begin(int* out, void* list);
extern void func_003EA900(NA910** out, int* in);
extern void func_003EA8F0(int* out, void* list);
extern void func_003EA8E0(NA910** out, int* in);
extern int String_CompareNoCase(const char* a, const char* b);
XA910* func_003EA910(void* self, YA910* key, int type)
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
    List_Begin(&t1, self);
    func_003EA900(&it, &t1);
    for (n = it; func_003EA8F0(&t2, self), func_003EA8E0(&e, &t2), n != e; n = n->next) {
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