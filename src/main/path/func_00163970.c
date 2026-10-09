/*
 * Matched functions (byte-identical with the retail executable).
 * PathLinkedPair constructor: two sub-objects that point at each other.
 */

#include "types.h"
#include "path_types.h"

extern char D_004D9720[]; /* sub-object base vtable */
extern char D_004D9730[]; /* sub-object vtable */
extern char D_004D9740[]; /* base vtable */
extern char D_004D9750[]; /* PathLinkedPair vtable */

/*
 * Base constructors are inlined: each vtable slot is written with the base
 * class vtable first, then the derived one. Locals keep the original
 * load order.
 */
PathLinkedPair* func_00163970(PathLinkedPair* self) {
    void* subVtable;
    void* subBaseVtable;
    void* vtable;
    PathLinkedSub* second;
    PathLinkedSub* first;

    self->vtable = D_004D9740;
    subVtable = D_004D9730;
    second = &self->second;
    subBaseVtable = D_004D9720;
    first = &self->first;
    self->first.vtable = subBaseVtable;
    vtable = D_004D9750;
    self->first.vtable = subVtable;
    self->second.vtable = subBaseVtable;
    self->second.vtable = subVtable;
    self->first.unk04 = second;
    self->first.unk08 = first;
    self->second.unk04 = second;
    self->second.unk08 = first;
    self->unk1C = 0;
    self->vtable = vtable;
    return self;
}
