#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "guiManager.h"
/* Widget seen through its virtual destructor (first vtable slot). */
struct VC_9270 { virtual int v0(int); };
/* List iterator returned by value (begin/end). */
struct NodeIter { GuiPtrNode* node; };
extern "C" {
void Mem_Free(int, void*, char*, int);
void ObjectList_EraseRange(int*, GuiPtrList*, GuiPtrNode**, GuiPtrNode**);
NodeIter func_0013B180(GuiPtrList*);                 /* begin() */
NodeIter func_0028C0A0(GuiPtrList*);                 /* end() */
void func_0028C0B0(GuiPtrNode**, const NodeIter&);   /* iterator copy */
void func_0028C090(GuiPtrNode**, const NodeIter&);   /* iterator copy */
void GuiManager_RemoveWidget(GuiScreenList*, VC_9270*);
extern char D_004BF138; /* "guiManager.cc" */
}
#pragma opt_common_subs off
/* Remove, destroy and free every widget queued in pendingDelete, then empty the list. */
extern "C" void GuiManager_FlushDeleted(GuiScreenList* self) {
    if (self->pendingDelete.count != 0) {
        GuiPtrNode* end;
        {
            GuiPtrNode* n;
            GuiPtrNode* it;
            func_0028C0B0(&it, func_0013B180(&self->pendingDelete));
            n = it;
            while ((func_0028C090(&end, func_0028C0A0(&self->pendingDelete)), n != end)) {
                VC_9270* w;
                GuiManager_RemoveWidget(self, (VC_9270*)n->item);
                w = (VC_9270*)n->item;
                {
                    AllocGuard g;
                    w->v0(-1);
                    Mem_Free(0, w, &D_004BF138, 0x53);
                }
                n = n->next;
            }
        }
        {
            int res;
            GuiPtrNode* first;
            GuiPtrNode* last;
            last = (GuiPtrNode*)&self->pendingDelete.last; /* sentinel node */
            first = self->pendingDelete.first;
            ObjectList_EraseRange(&res, &self->pendingDelete, &first, &last);
        }
    }
}
