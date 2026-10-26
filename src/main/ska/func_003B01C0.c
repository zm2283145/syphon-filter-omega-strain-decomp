#pragma cplusplus on

#include "types.h"

/* Find the list entry whose data starts with key. */
typedef struct { int key; } Data_3B01C0;
typedef struct Node_3B01C0 { int pad0; struct Node_3B01C0* next; Data_3B01C0* data; } Node_3B01C0;
typedef struct { Node_3B01C0* p; } It_3B01C0;
typedef struct { int w[1]; } Raw_3B01C0;
typedef struct { unsigned char pad[0x6C]; int list; } Obj_3B01C0;

extern "C" {
void List_Begin(Raw_3B01C0* out, void* list);
void std_list_cSkaTransPlaybackPtr_generic_iterator_ctor(It_3B01C0* out, Raw_3B01C0* raw);
void std_list_cSkaTransPlaybackPtr_end(Raw_3B01C0* out, void* list);
void cLListIterator_cSkaTransPlaybackPtr_ctor(It_3B01C0* out, Raw_3B01C0* raw);
}

extern "C" Data_3B01C0* cSkaParams_GetTransPlayback(Obj_3B01C0* o, int key)
{
    It_3B01C0 last;
    It_3B01C0 first;
    Raw_3B01C0 rawFirst;
    Raw_3B01C0 rawEnd;
    Node_3B01C0* n;
    List_Begin(&rawFirst, &o->list);
    std_list_cSkaTransPlaybackPtr_generic_iterator_ctor(&first, &rawFirst);
    for (n = first.p; (std_list_cSkaTransPlaybackPtr_end(&rawEnd, &o->list), cLListIterator_cSkaTransPlaybackPtr_ctor(&last, &rawEnd), n != last.p); n = n->next) {
        if (n->data->key == key)
            return n->data;
    }
    return 0;
}