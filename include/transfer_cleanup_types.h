#ifndef TRANSFER_CLEANUP_TYPES_H
#define TRANSFER_CLEANUP_TYPES_H

#include "net_transfer_types.h"
#include "transfer_ownership_types.h"

struct TransferObjectEntry { TransferReference* reference; };
struct TransferObjectNode { char links[0xC]; GobjId id; TransferObjectEntry* entry; };

struct TransferMessage {
    virtual ~TransferMessage();
};

struct PendingTransferController : TransferController {
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual TransferMessage* create_message(); /* +0x90 */
    virtual void slot35();
    virtual void set_transferring(int value); /* +0x98 */
    virtual void apply_message(TransferMessage* message); /* +0x9C */
};

struct PendingTransferNode { char links[0xC]; GobjId id; TransferMessage* message; };
/* Preserve the raw iterator copy instead of scalarizing its pointer assignment. */
union PendingTransferIterator { PendingTransferNode* node; };

#endif
