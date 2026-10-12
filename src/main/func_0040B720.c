#include "types.h"

typedef struct RegNode { struct RegNode* parent; char pad[0x10]; int list; int index; int* items; } RegNode;
extern void KeyVector_PushBack(int* list, int* where, int n, void* item);

/* Inserts the item into this node's list and every ancestor's. */
void func_0040B720(RegNode* self, char* item)
{
    if (item) {
        KeyVector_PushBack(&self->list, self->items + self->index, 1, item + 0xC);
        if (self->parent) {
            func_0040B720(self->parent, item);
        }
    }
}
