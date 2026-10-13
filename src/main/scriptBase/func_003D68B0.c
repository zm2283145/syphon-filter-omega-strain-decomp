#include "types.h"
typedef struct { char pad[0xA8]; int* cursor; } Writer;
typedef struct { char* name; int pad4; int key; } Item;
typedef struct {
    char pad0[8]; int nItems; Item** items; char pad10[0x18];
    int nKeys; int* keys; char pad30[0x10]; int key40;
} Obj;
extern int strlen(const char* s);
extern char* String_Copy(char* dst, const char* src);
extern void func_003D6580(Writer* w, int size);
extern int func_003D6570(Writer* w, int size);
extern void func_003D63C0(Writer* w, int words);
extern char* func_003D7510(int key);
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
static inline void Writer_PutInt(Writer* w, int v)
{
    func_003D63C0(w, 1);
    *w->cursor++ = v;
}
#pragma opt_strength_reduction off
/* Serialises the name key, the item name/key pairs and the key list. */
void func_003D68B0(Obj* o, Writer* w)
{
    int n;
    int i;
    if (o->key40 >= 0)
        Writer_PutString(w, func_003D7510(o->key40));
    else
        Writer_PutInt(w, 0);
    n = o->nItems;
    Writer_PutInt(w, n);
    for (i = 0; i < n; i++) {
        Writer_PutString(w, o->items[i]->name);
        Writer_PutString(w, func_003D7510(o->items[i]->key));
    }
    n = o->nKeys;
    Writer_PutInt(w, n);
    for (i = 0; i < n; i++)
        Writer_PutString(w, func_003D7510(o->keys[i]));
}
