#include "types.h"
typedef struct { char pad[0xA8]; int* cursor; } Writer;
typedef struct { void* key; } KeyRef;
typedef struct { char* name; KeyRef* ref; } NamedRef;
extern int strlen(const char* s); /* strlen */
extern char* String_Copy(char* dst, const char* src);
extern void func_003D6580(Writer* w, int size);
extern int func_003D6570(Writer* w, int size);
extern void func_003D63C0(Writer* w, int words);
extern char* func_003D7510(void* key);
static inline void Writer_PutString(Writer* w, char* s)
{
    int size = strlen(s) + 1;
    int words;
    func_003D6580(w, size);
    words = func_003D6570(w, size);
    func_003D63C0(w, words);
    String_Copy((char*)w->cursor, s);
    w->cursor += words;
}
/* Serialises the name and the key's name as padded strings. */
void func_003D62D0(NamedRef* r, Writer* w)
{
    Writer_PutString(w, r->name);
    Writer_PutString(w, func_003D7510(r->ref->key));
}
