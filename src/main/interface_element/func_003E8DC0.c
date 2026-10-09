/*
 * Matched functions (byte-identical with the retail executable).
 * interface_element.cc
 */

#include "types.h"
#include "interface_element_types.h"

extern int func_003ECD60(int owner, IfElement* elem, int a2);

/* Forward (elem, a1) to func_003ECD60 on the element's owner. */
int func_003E8DC0(IfElement* elem, int a1) {
    return func_003ECD60(elem->owner, elem, a1);
}
