#ifndef SYSTEM_TYPES_H
#define SYSTEM_TYPES_H

/*
 * Types for the system directory (Receiver base class, system.cc/system.hh).
 * Layouts are inferred from the constructors and destructors in this
 * directory.
 */

#define RECEIVER_MAGIC 0xbebaafde
#define RECEIVER_DEAD_ID 0xF0FFFFF0 /* id written by the destructor */

/* Heap buffer owned by a Receiver (freed with "system.hh" line 0x34). */
typedef struct ReceiverBuf {
    void* data;                 /* 0x00 */
} ReceiverBuf;

/* Base event receiver (cSystem_ctor, 0x003CB4B0). */
typedef struct Receiver {
    void* vtable;               /* 0x00 */
    unsigned int magic;         /* 0x04: RECEIVER_MAGIC, 0 once destroyed */
    void* owner;                /* 0x08: returned by cSystem_GetName */
    int id;                     /* 0x0C: -1 when unset */
    int unk10;                  /* 0x10: -1 when unset */
    unsigned char enabled;      /* 0x14: 1 after construction */
    char pad15[3];
    ReceiverBuf* buf;           /* 0x18: owned buffer (may be NULL) */
} Receiver;                     /* size 0x1C (assumed) */

/* Receiver subclass with a scalar collection at +0x20 (0x003CB090 / 0x003CB110). */
typedef struct ListReceiver {
    Receiver base;              /* 0x00 */
    int unk1C;                  /* 0x1C */
    char list[0x10];            /* 0x20: object list (ObjList) */
} ListReceiver;

/*
 * Queued timed event that deletes its target when it fires
 * (vtable D_004DFE20, built by cSystem_ActualScheduleDelete).
 */
typedef struct DeleteLaterEvent {
    int timeMs;                 /* 0x00: delay in milliseconds */
    unsigned char b4;           /* 0x04 */
    unsigned char b5;           /* 0x05 */
    char pad6[2];
    void* vtable;               /* 0x08 */
    void* target;               /* 0x0C: object to delete */
} DeleteLaterEvent;             /* size 0x10 */

#endif