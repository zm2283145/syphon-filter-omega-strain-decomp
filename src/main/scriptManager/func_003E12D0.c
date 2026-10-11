#include "types.h"
typedef struct { char pad[0x80]; const char* path; } S12D0;
typedef struct N12D0 { int m0; struct N12D0* next; S12D0* data; } N12D0;
typedef struct { char pad[0xC]; int list; } T12D0;
extern void func_0013B180(int* out, void* list);
extern void func_003E13D0(N12D0** out, int* in);
extern void func_003E13C0(int* out, void* list);
extern void func_003E13B0(N12D0** out, int* in);
extern const char* Path_GetBaseName(const char* p);
extern void String_Copy(char* d, const char* s);
extern int func_00128E80(const char* a, const char* b);
S12D0* func_003E12D0(T12D0* self, const char* path)
{
    N12D0* e;
    N12D0* it;
    int t1;
    int t2;
    char buf[256];
    S12D0* s;
    N12D0* n;
    String_Copy(buf, Path_GetBaseName(path));
    func_0013B180(&t1, &self->list);
    func_003E13D0(&it, &t1);
    for (n = it; func_003E13C0(&t2, &self->list), func_003E13B0(&e, &t2), n != e; n = n->next) {
        s = n->data;
        if (!func_00128E80(Path_GetBaseName(s->path), buf))
            return s;
    }
    return 0;
}