/*
 * Matched functions (byte-identical with the retail executable).
 * Runtime support: global destructor chain registration.
 */

#include "types.h"
#include "loose00_types.h"

extern DestructorChain* D_004E1DB0; /* head of the global destructor chain */

/* Register a global object for destruction at exit (Metrowerks runtime
 * __register_global_object pattern): link node, store destructor and object. */
void* __register_global_object(void* object, void* destructor, DestructorChain* node) {
    DestructorChain* head;

    head = D_004E1DB0;
    node->next = head;
    node->destructor = destructor;
    node->object = object;
    D_004E1DB0 = node;
    return object;
}
