/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "types.h"

List* List_Construct(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
