#include "types.h"

typedef struct { int a; int b; } Pair;
typedef struct { char pad[0xC]; unsigned char flag; } Tail;
typedef struct {
    unsigned char kind;
    char pad[3];
    Pair pairs[7];
    Tail tail;
} Obj;
extern void __construct_array(void* array, void (*ctor)(void*), void (*dtor)(void*), int size, int count);
extern void func_0018A210(void* p);
extern void func_0018A870(void* p);
extern void func_0018A810(Tail* dst, Tail* src);

/* Copy constructor. */
Obj* func_0018A710(Obj* self, Obj* src)
{
    int i;
    Tail* tail;
    Pair* dst;
    self->kind = src->kind;
    dst = self->pairs;
    __construct_array(dst, func_0018A870, func_0018A210, 8, 7);
    for (i = 0; i < 7; i++) {
        dst[i].a = src->pairs[i].a;
        dst[i].b = src->pairs[i].b;
    }
    tail = &self->tail;
    func_0018A810(tail, &src->tail);
    tail->flag = src->tail.flag;
    return self;
}
