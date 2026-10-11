#pragma cplusplus on
/* Keep reference validity and iterator values distinct across callbacks. */
#pragma opt_propagation off

#include "net_transfer_types.h"
#include "alloc_guard.h"

struct TransferUpdateController : TransferController {
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
    virtual unsigned char transfer_mode(); /* +0x88 */
    virtual void slot33();
    virtual void slot34();
    virtual bool ready_to_release(); /* +0x94 */
};

struct TransferUpdateObject {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void release_transfer(); /* +0x20 */
};

extern "C" {
extern RbTree D_00582700;
extern char D_004BFB00[];
void func_0042EAF0(TransferReferenceIterator* result, RbTree* tree);
TransferReferenceIterator func_0042DA20(RbTree* tree);
void func_0042DA10(TransferReferenceIterator* result, const TransferReferenceIterator& source);
void Tree_Successor(TransferReferenceIterator* position);
void func_0042F510(RbTree* tree, TransferReferenceIterator* position);
void Mem_Free(int pool, void* allocation, char* file, int line);
void func_0042CF30(void);
}

static inline cGOBJ* referenced_object(const TransferReference* reference)
{
    cGOBJ* object = reference->object;
    int missing = (object != 0) ^ 1;
    bool valid = true;
    if (!missing && ((GobjEntry*)object)->id.word != reference->id.word)
        valid = false;
    return valid ? object : 0;
}

static inline bool transfer_active(cGOBJ* object)
{
    return object->unk2D != 0 && object->unk2C != 0 && !(object->unk2E != 0);
}

static inline TransferUpdateController* controller(cGOBJ* object)
{
    return (TransferUpdateController*)object->attached;
}

static inline bool release_transfer(cGOBJ* object)
{
    bool released = false;
    if (controller(object)->can_create_message()) {
        ((TransferUpdateObject*)object)->release_transfer();
        released = true;
    }
    return released;
}

static inline void erase_reference(TransferReferenceNode* node)
{
    TransferReferenceIterator erased;
    erased.node = node;
    func_0042F510(&D_00582700, &erased);
}

static inline void assign_end(TransferReferenceIterator* result, RbTree* tree)
{
    func_0042DA10(result, func_0042DA20(tree));
}

static inline void reference_end(TransferReferenceIterator* result)
{
    assign_end(result, &D_00582700);
}

/* Release completed transfers and stale references, then process transfer timers. */
extern "C" void func_0042EB20(void)
{
    TransferReferenceIterator position;
    TransferReferenceIterator end;
    TransferReferenceIterator begin;
    cGOBJ* object;
    TransferReferenceNode* node;
    func_0042EAF0(&begin, &D_00582700);
    position.node = begin.node;
    while (reference_end(&end),
           node = position.node, (node == end.node) ^ 1) {
        object = referenced_object(node->reference);
        Tree_Successor(&position);
        if (object) {
            if (!transfer_active(object) && object->attached &&
                controller(object)->transfer_mode() == 2 &&
                controller(object)->ready_to_release() && release_transfer(object)) {
                TransferReference* reference = node->reference;
                {
                    AllocGuard guard;
                    Mem_Free(0, reference, D_004BFB00, 0x40);
                }
                erase_reference(node);
            }
        } else {
            TransferReference* reference = node->reference;
            {
                AllocGuard guard;
                Mem_Free(0, reference, D_004BFB00, 0x4A);
            }
            erase_reference(node);
        }
    }
    func_0042CF30();
}
