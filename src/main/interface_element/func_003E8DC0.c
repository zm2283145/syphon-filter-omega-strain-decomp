/*
 * Matched functions (byte-identical with the retail executable).
 * interface_element.cc
 */

#include "types.h"
#include "interface_element_types.h"

extern int IeElement_Draw(int owner, IfElement* elem, int a2);

/* Forward (elem, a1) to IeElement_Draw on the element's owner. */
int cInterfaceElement_Render(IfElement* elem, int a1) {
    return IeElement_Draw(elem->owner, elem, a1);
}
