#ifndef PICKUP_MENU_TYPES_H
#define PICKUP_MENU_TYPES_H

/* Despite the name: the text object of an interface model (model +0x74) that
 * pickup_menu's PickupMenuEntry_SetPickupColor recolours; TextObj_SetColour sets its colour. */
typedef struct PickupMenu {
    char pad00[0x10];
    char unk10;                     /* 0x10 */
    char unk11;                     /* 0x11 */
} PickupMenu;

#endif
