/*
 * Matched functions (byte-identical with the retail executable).
 * interface_element.cc
 */

#include "types.h"
#include "interface_element_types.h"

extern int func_003EE740(int owner);

/* Forward to func_003EE740 on the element's owner. */
int func_003E7ED0(IfElement* elem) {
    return func_003EE740(elem->owner);
}
