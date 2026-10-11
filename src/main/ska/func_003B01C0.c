#pragma cplusplus on

#include "types.h"

/* Find the list entry whose data starts with key. */
typedef struct { int key; } Data_3B01C0;
typedef struct Node_3B01C0 { int pad0; struct Node_3B01C0* next; Data_3B01C0* data; } Node_3B01C0;
typedef struct { Node_3B01C0* p; } It_3B01C0;
typedef struct { int w[1]; } Raw_3B01C0;
typedef struct { unsigned char pad[0x6C]; int list; } Obj_3B01C0;

extern "C" {
void func_0013B180(Raw_3B01C0* out, void* list);
void func_00392FF0(It_3B01C0* out, Raw_3B01C0* raw);
void func_00392FE0(Raw_3B01C0* out, void* list);
void func_00392FD0(It_3B01C0* out, Raw_3B01C0* raw);
}

extern "C" Data_3B01C0* func_003B01C0(Obj_3B01C0* o, int key)
{
    It_3B01C0 last;
    It_3B01C0 first;
    Raw_3B01C0 rawFirst;
    Raw_3B01C0 rawEnd;
    Node_3B01C0* n;
    func_0013B180(&rawFirst, &o->list);
    func_00392FF0(&first, &rawFirst);
    for (n = first.p; (func_00392FE0(&rawEnd, &o->list), func_00392FD0(&last, &rawEnd), n != last.p); n = n->next) {
        if (n->data->key == key)
            return n->data;
    }
    return 0;
}