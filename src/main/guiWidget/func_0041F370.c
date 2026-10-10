#pragma cplusplus on

#include "gui_traversal_types.h"
#include "alloc_guard.h"

struct GuiOwnedObject {
    virtual ~GuiOwnedObject();
};

extern "C" {
extern char D_004E0B40[];
extern char D_004E09B0[];
extern char D_004BF3D0[];
extern int D_00572130;
ChildIterator func_0013B180(ChildList* list);
void func_0028C0B0(ChildIterator* result, const ChildIterator& source);
ChildIterator func_0028C0A0(ChildList* list);
void func_0028C090(ChildIterator* result, const ChildIterator& source);
void func_002CCD80(ChildList* list, int flags);
void func_00138B70(void* string, int flags);
void Mem_Free(int pool, void* allocation, char* file, int line);
void operator_delete(void* allocation);
}

static inline void destroy_owned(GuiOwnedObject* object, int line)
{
    object->~GuiOwnedObject();
    Mem_Free(0, object, D_004BF3D0, line);
}

static inline bool has_child(ChildNode* node, ChildList* list, ChildIterator* end)
{
    func_0028C090(end, func_0028C0A0(list));
    return node != end->node;
}

static inline void destroy_children(ChildList* list)
{
    if (list)
        func_002CCD80(list, 0);
}

static inline void destroy_name(void* name)
{
    if (name)
        func_00138B70(name, 0);
}

static inline void destroy_base(TraversalWidget* self)
{
    if (self) {
        *(void**)self = D_004E09B0;
        D_00572130--;
    }
}

/* Destroy owned children and a separate handler under the allocator guard. */
extern "C" TraversalWidget* func_0041F370(TraversalWidget* self, short deleteFlag)
{
    if (self) {
        ChildIterator end;
        ChildIterator begin;
        GuiOwnedObject* child;
        ChildNode* node;
        *(void**)self = D_004E0B40;
        func_0028C0B0(&begin, func_0013B180(&self->children));
        node = begin.node;
        while (has_child(node, &self->children, &end)) {
            child = (GuiOwnedObject*)node->widget;
            {
                AllocGuard guard;
                destroy_owned(child, 0x58);
            }
            node = node->next;
        }
        GuiOwnedObject* handler = (GuiOwnedObject*)self->handler;
        if (handler != (GuiOwnedObject*)self) {
            AllocGuard guard;
            destroy_owned(handler, 0x5C);
        }
        destroy_children(&self->children);
        destroy_name(self->name);
        destroy_base(self);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
