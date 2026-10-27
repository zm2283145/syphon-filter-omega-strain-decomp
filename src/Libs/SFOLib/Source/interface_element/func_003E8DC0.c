/*
 * Matched functions (byte-identical with the retail executable).
 * interface_element.cc
 */

#include "types.h"
#include "interface_element_types.h"

extern int cInterfaceModel_RenderInstance(int owner, IfElement* elem, int a2);

/* Forward (elem, a1) to cInterfaceModel_RenderInstance on the element's owner. */
int cInterfaceElement_Render(IfElement* elem, int a1) {
    return cInterfaceModel_RenderInstance(elem->owner, elem, a1);
}
