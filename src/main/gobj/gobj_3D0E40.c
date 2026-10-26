#include "types.h"

typedef struct { int words[3]; } String;
typedef struct { float x, y, z, w; } Vec4f;
typedef struct { String name; int id; Vec4f v; float a; float b; int extra[4]; } Entry;
typedef struct { int unk0; int list; int head; } Obj;
extern void String_CtorCStr_13B480(String* s, const char* text);
extern void std_list_deleter_cText_insert(void* result, void* list, int* where, Entry* entry);
extern void String_Dtor(String* s, int flags);

/* Appends a named entry (id, vector, two floats) to the object's list. */
void cTextSystem_Print_charP_cFontR_tRGBAR_float_etc(Obj* self, const char* name, int id, Vec4f* v, float a, float b)
{
    int where;
    int result;
    Entry entry;
    String_CtorCStr_13B480(&entry.name, name);
    entry.id = id;
    entry.v.x = v->x;
    entry.v.y = v->y;
    entry.v.z = v->z;
    entry.v.w = v->w;
    entry.a = a;
    entry.b = b;
    where = (int)&self->head;
    std_list_deleter_cText_insert(&result, &self->list, &where, &entry);
    String_Dtor(&entry.name, 0);
}
