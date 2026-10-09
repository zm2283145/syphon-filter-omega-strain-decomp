#ifndef SYSTEM_TYPES_H
#define SYSTEM_TYPES_H

/*
 * Types for the system directory (Receiver base class). Layouts are
 * provisional and inferred from the constructors in this directory.
 */

#define RECEIVER_MAGIC 0xbebaafde

/* Base event receiver (Receiver_Construct, 0x003CB4B0). */
typedef struct Receiver {
    void* vtable;               /* 0x00 */
    unsigned int magic;         /* 0x04: RECEIVER_MAGIC */
    void* owner;                /* 0x08 */
    int unk0C;                  /* 0x0C: -1 when unset */
    int unk10;                  /* 0x10: -1 when unset */
    unsigned char enabled;      /* 0x14: 1 after construction */
    char pad15[3];
    int unk18;                  /* 0x18 */
} Receiver;                     /* size 0x1C (assumed) */

/* Receiver subclass with a scalar collection at +0x20 (0x003CB090 / 0x003CB110). */
typedef struct ListReceiver {
    Receiver base;              /* 0x00 */
    int unk1C;                  /* 0x1C */
    char list[12];              /* 0x20: scalar collection */
} ListReceiver;

#endif
