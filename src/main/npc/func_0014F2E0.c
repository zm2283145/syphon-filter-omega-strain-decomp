#include "types.h"

typedef struct { int unk0; int unk4; int unk8; } Container;
typedef struct {
    char pad[0x15C];
    int unk15C;
    int priority;
    unsigned char a;
    unsigned char b;
    unsigned char unk166;
    char pad167;
    unsigned char unk168;
    char pad169[0x4F];
    Container* list;
} Npc14F;

extern void func_0015B860(int* out, Container* self, int* value, int** where);

/* Sets a new request if its priority is at least the current one, clearing the pending list. */
void func_0014F2E0(Npc14F* self, unsigned char a, unsigned char b, int priority)
{
    if (priority >= self->priority) {
        Container* list = self->list;
        if (list) {
            int* where;
            int value;
            int result;
            where = &list->unk4;
            value = list->unk8;
            func_0015B860(&result, list, &value, &where);
        }
        self->unk15C = 0;
        self->a = a;
        self->b = b;
        self->unk166 = 0;
        self->priority = priority;
        self->unk168 = 0;
    }
}
