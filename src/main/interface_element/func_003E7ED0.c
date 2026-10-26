/*
 * Matched functions (byte-identical with the retail executable).
 * interface_element.cc
 */

#include "types.h"
#include "interface_element_types.h"

extern int cInterfaceModel_NumFrames(int owner);

/* Forward to cInterfaceModel_NumFrames on the element's owner. */
int cInterfaceElement_NumFrames(IfElement* elem) {
    return cInterfaceModel_NumFrames(elem->owner);
}
