#ifndef NET_TRANSFER_TYPES_H
#define NET_TRANSFER_TYPES_H

#include "NetObjectMgr_types.h"
#include "gobj_types.h"

struct TransferController {
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
    virtual bool can_create_message(); /* +0x44 */
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual bool is_ready();           /* +0x58 */
    virtual bool manages_transfer();   /* +0x5C */
};

struct TransferObjectMethods {
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
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void set_state(int state); /* +0x60 */
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual bool is_registered();      /* +0x7C */
};

/* Transfer maps share the retail node header and store their payload at +0x10. */
struct TransferTimerNode {
    char links[0xC];
    GobjId id;
    unsigned int deadline;
};

struct TransferTimerIterator { TransferTimerNode* node; };
struct TransferTimerValue { GobjId id; unsigned int deadline; };
struct TransferInsertResult { TransferTimerIterator position; unsigned char inserted; };

struct TransferReference { cGOBJ* object; GobjId id; };
struct TransferReferenceNode { char links[0xC]; GobjId id; TransferReference* reference; };
struct TransferReferenceIterator { TransferReferenceNode* node; };
struct TransferReferenceValue { GobjId id; TransferReference* reference; };
struct TransferReferenceInsertResult { TransferReferenceIterator position; unsigned char inserted; };
struct TransferNotice {
    void* vtable;
    int header[7];
    unsigned char enabled;
    char pad21[3];
    unsigned char action;
    char pad25[3];
};

#endif
