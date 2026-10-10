#include "types.h"

/* compiler: ee-gcc 2.95 -O2 (check.py --gcc) */

typedef struct BNode { struct BNode* next; int bucket; } BNode;
typedef struct { char pad[0x4C]; BNode** buckets; } Table;

/* Pushes a node onto the head of its bucket list. */
void func_00126328(Table* table, BNode* node)
{
    if (node != 0) {
        BNode** buckets = table->buckets;
        int b = node->bucket;
        node->next = buckets[b];
        buckets[b] = node;
    }
}