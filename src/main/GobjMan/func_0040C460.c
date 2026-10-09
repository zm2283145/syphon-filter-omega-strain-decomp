/*
 * Matched functions (byte-identical with the retail executable).
 * GobjMan.cc: scope chain accessors used by the script object lookup.
 */

#include "types.h"
#include "GobjMan_types.h"

GobjScope* Scope_GetParent(GobjScope* self) {
    return self->parent;
}

GobjScope* Object_GetScope(GobjEntry* self) {
    return self->scope;
}
