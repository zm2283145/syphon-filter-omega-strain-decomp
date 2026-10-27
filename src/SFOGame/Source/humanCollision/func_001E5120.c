#pragma cplusplus on
#include "types.h"
#pragma bool off
/* Physical_SetChildOffsets: apply an orientation to every child root and mark it dirty */
typedef struct { char** p; } It_1E5120;
typedef struct { char pad[0xB4]; int vec; int count; } O_1E5120;
extern "C" {
char** std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_begin(int* v);
char** std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_end(int* v);
void std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_pointer2iterator(It_1E5120* out, int* v, char*** p);
char* cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(char* r);
void cQuatVec_opAssign(char* t, void* q);
void cSkaAnimAnchor_TreeNode_TellChildrenNeedToUpdate(char* r);
void Physical_SetChildOffsets(O_1E5120* self, void* q);
}
static inline int Eq_1E5120(char** a, char** b) { return a == b; }
static inline int EqI_1E5120(int a, int b) { return a == b; }
static inline void SetDirty_1E5120(char* c, unsigned char f) { cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(c)[0xA0] = f; }
void Physical_SetChildOffsets(O_1E5120* self, void* q)
{
    It_1E5120 b;
    It_1E5120 e;
    char** t0;
    char** t1;
    char** it;
    char** end;
    if (EqI_1E5120(self->count, 0) ^ 1) {
        int* v = &self->vec;
        t0 = std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_begin(v);
        std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_pointer2iterator(&b, &self->vec, &t0);
        it = b.p;
        t1 = std_vector_imp_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_1_end(v);
        std_vector_cTreeNode_cSkaAnimAnchor_TreeNodeDataPtr_pointer2iterator(&e, v, &t1);
        end = e.p;
        /* volatile read: retail reloads e.p for the loop guard separately from end */
        if (Eq_1E5120(it, *(char** volatile*)&e.p) ^ 1) {
            do {
                char* c = *it;
                cQuatVec_opAssign(cTreeNode_cSkaAnimAnchor_TreeNodeData_Data_void_2(c) + 0x50, q);
                SetDirty_1E5120(c, 1);
                cSkaAnimAnchor_TreeNode_TellChildrenNeedToUpdate(c);
                it++;
            } while (Eq_1E5120(it, end) ^ 1);
        }
    }
}
