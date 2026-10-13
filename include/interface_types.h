#ifndef INTERFACE_TYPES_H
#define INTERFACE_TYPES_H

/*
 * Interface (interface.cc): a loaded interface model plus its optional
 * "preview" element.
 */

#define INTERFACE_MODEL_SIZE 0xE0

/* Interface model root (0xE0 bytes; built by func_003EF660). */
typedef struct InterfaceModel {
    char pad0[0x60];
    unsigned char unk60;        /* 0x60 set to 1 on the root */
} InterfaceModel;

typedef struct Interface {
    InterfaceModel* model;      /* 0x00 */
    void* preview;              /* 0x04 "preview" element instance, or NULL */
} Interface;

#endif