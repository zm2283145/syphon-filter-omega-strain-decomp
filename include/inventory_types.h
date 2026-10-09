#ifndef INVENTORY_TYPES_H
#define INVENTORY_TYPES_H

/* Network inventory message (serialized by cNetInventoryMsg_v04). */
typedef struct cNetInventoryMsg {
    char pad00[0x24];
    short unk24;                    /* 0x24 written little-endian */
    signed char unk26;              /* 0x26 */
    signed char unk27;              /* 0x27 */
} cNetInventoryMsg;

#endif
