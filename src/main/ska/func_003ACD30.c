#pragma cplusplus on

#include "types.h"

/* Set the flag byte of every node's target in a list. */
typedef struct { unsigned char pad[0x33]; unsigned char flag; } Tgt_3ACD30;
typedef struct Node_3ACD30 { int pad0; struct Node_3ACD30* next; Tgt_3ACD30* target; } Node_3ACD30;
typedef struct { Node_3ACD30* p; } It_3ACD30;
typedef struct { int w[1]; } Raw_3ACD30;

extern "C" {
void func_003ACDC0(Raw_3ACD30* out, void* list);
void func_00396AF0(It_3ACD30* out, Raw_3ACD30* raw);
void func_00396B00(Raw_3ACD30* out, void* list);
}

extern "C" void func_003ACD30(void* list, int flag)
{
    It_3ACD30 first;
    It_3ACD30 last;
    Raw_3ACD30 rawFirst;
    Raw_3ACD30 rawLast;
    Node_3ACD30* n;
    Node_3ACD30* end;
    func_003ACDC0(&rawFirst, list);
    func_00396AF0(&first, &rawFirst);
    n = first.p;
    func_00396B00(&rawLast, list);
    func_00396AF0(&last, &rawLast);
    end = last.p;
    unsigned char f = flag;
    for (; n != end; n = n->next)
        n->target->flag = f;
}