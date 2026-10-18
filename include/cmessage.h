#ifndef CMESSAGE_H
#define CMESSAGE_H

/*
 * CMsg: the 0x24-byte cMessage base shared by every stack message
 * (~200 src files re-derive it). Base vtable D_004DFD80 (slot +8 dtor,
 * +0xC Clone). Plain C or C++ (MW); payload of derived messages starts at
 * +0x24 (typical sizes 0x28/0x2C/0x30/0x3C; sound events 0x1C0/0x1D0).
 *
 * Usual stack idiom (keep the statement order of the target!):
 *   Event_Construct(&m, D_typeDesc);   vtable=D_004DFD80, type, stampKind=0,
 *                                      flags=0, kind=5, time if net active
 *   m.vtable = D_derivedVtable;  ...payload...;  Event_Send(&m, target, 0/1);
 *   m.vtable = D_baseVtable;     cMessage_dtor(&m, 0);
 *
 * Derived messages: in C embed the fields flat with CMSG_HEADER, e.g.
 *   typedef struct { CMSG_HEADER; int key; } MyMsg;           (key at +0x24)
 * or in C++ derive: struct MyMsg : CMsg { int key; };  (CMsg has no virtuals,
 * so no hidden vptr is added.)
 *
 * The byte at +0x20 is read signed in some functions and unsigned in others
 * (lb vs lbu). Default unsigned; #define CMSG_KIND_T signed char before the
 * include when the target loads it with lb.
 *
 * Prototypes take void* so any message pointer converts in C and C++. If a
 * file must keep its own typed declarations, #define CMSG_NO_PROTOS first.
 * Do not mix this header with ai_types.h/game_types.h cMessage, human_types.h
 * Message or sfo_common_types.h SfMessage in one file (different names, so no
 * clash, but pick one view).
 */
#include "layout_assert.h"

#ifndef CMSG_KIND_T
#define CMSG_KIND_T unsigned char
#endif

#define CMSG_MAGIC 0xBEBAAFDE /* stored at +8 by MsgQueue_QueueClone */

#define CMSG_HEADER                                                         \
    void* vtable;            /* +0x00 D_004DFD80 for the base */            \
    void* type;              /* +0x04 type descriptor (Event_GetType) */    \
    unsigned int magic;      /* +0x08 CMSG_MAGIC once queued */             \
    unsigned int time;       /* +0x0C Net_GetClock(0) timestamp */         \
    int unk10;               /* +0x10 */                                    \
    void* target;            /* +0x14 */                                    \
    unsigned int stampKind;  /* +0x18 0..3, packed by Event_PackHeader */   \
    int flags;               /* +0x1C 0x40 for hotbox/link/net messages */  \
    CMSG_KIND_T kind;        /* +0x20 5 after Event_Construct */            \
    unsigned char pad21[3]   /* +0x21 */

typedef struct CMsg {
    CMSG_HEADER;
} CMsg; /* 0x24 */
LAYOUT_SIZE(CMsg, 0x24);
LAYOUT_OFFSET(CMsg, kind, 0x20);

#ifndef CMSG_NO_PROTOS
#ifdef __cplusplus
extern "C" {
#endif
void Event_Construct(void* msg, void* type);              /* 0x003C9E30 */
void Event_Send(void* msg, void* target, int immediate);  /* 0x003C9420 */
void cMessage_dtor(void* msg, int flags);                 /* 0x003C9D60, flags really short */
#ifdef __cplusplus
}
#endif
#endif

#endif /* CMESSAGE_H */
