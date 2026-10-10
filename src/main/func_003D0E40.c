#include "types.h"

typedef struct { int words[3]; } String;
typedef struct { float x, y, z, w; } Vec4f;
typedef struct { String name; int id; Vec4f v; float a; float b; int extra[4]; } Entry;
typedef struct { int unk0; int list; int head; } Obj;
extern void String_CtorCStr_13B480(String* s, const char* text);
extern void func_003D1280(void* result, void* list, int* where, Entry* entry);
extern void func_00138B70(String* s, int flags);

/* Appends a named entry (id, vector, two floats) to the object's list. */
void func_003D0E40(Obj* self, const char* name, int id, Vec4f* v, float a, float b)
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
    func_003D1280(&result, &self->list, &where, &entry);
    func_00138B70(&entry.name, 0);
}
