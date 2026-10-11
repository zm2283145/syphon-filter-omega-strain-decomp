#ifndef TRANSFER_OWNERSHIP_TYPES_H
#define TRANSFER_OWNERSHIP_TYPES_H

#include "NetObjectMgr_types.h"
#include "gobj_types.h"

/* The ownership lookup only inspects iterator identity, not the node payload. */
struct TransferObjectNode;
struct TransferObjectIterator { TransferObjectNode* node; };

struct TransferRequestNotice {
    void* vtable;
    int header[6];
    unsigned int flags;
    unsigned char state;
    char pad21[3];
    GobjId id;
    short peer;
    char pad2A[2];
};

struct TransferReleaseNotice {
    void* vtable;
    char payload[0x2C];
};

struct TransferOwnerObjectMethods {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void release_transfer(); /* +0x24 */
};

struct TransferOwnerControllerMethods {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void release_transfer(); /* +0x4C */
};

#endif
