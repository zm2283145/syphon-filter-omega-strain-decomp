/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

struct Obj {
    virtual void v00();
    virtual int GetValue(); /* +0xC */
};

typedef struct Pair { int key; int value; } Pair;

typedef struct InsertResult { void* it; unsigned char inserted; } InsertResult;

extern char D_005826E0[];
extern "C" void func_0042F400(InsertResult* out, void* map, Pair* p);

/* Inserts the pair (self key, value from obj virtual +0xC) into the D_005826E0 map. */
extern "C" void func_0042D310(int* self, Obj* obj)
{
    Pair p;
    InsertResult result;
    int value = obj->GetValue();
    p.key = *self;
    p.value = value;
    func_0042F400(&result, D_005826E0, &p);
}
