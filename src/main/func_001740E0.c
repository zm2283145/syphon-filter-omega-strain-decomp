#pragma bool off
#pragma cplusplus on
#include "types.h"
struct IdVec_40E0;
extern "C" int** std_vector_deleter_cObjectId_data_void(IdVec_40E0* v);
extern "C" 
struct IdVec_40E0 { int cap; int count; int* data; int size() const { return count; } int* begin() { return *std_vector_deleter_cObjectId_data_void(this); } int* end() { return *std_vector_deleter_cObjectId_data_void(this) + count; } };
struct It_40E0 {
    int* p;
};
static inline int NotEq(int* a, int* b) { return !(a == b); }
extern "C" {

void PtrVec_Reserve(void* list, int n);
int Object_LookupById(int* id);
void PtrVec_PushBack_171C70(void* list, int* obj);
void Actor_VirtualLeaf175230(IdVec_40E0* v);
}
typedef struct { char pad[0x1F4]; int list[4]; IdVec_40E0 ids; char pad2[0x250 - 0x210]; unsigned char resolved; } T_40E0;
extern "C" void Terrain_ResolveIdList(T_40E0* self)
{
    int* it = self->ids.begin();
    int* end = self->ids.end();
    PtrVec_Reserve(self->list, self->ids.size());
    while (NotEq(it, end)) {
        int id = *it;
        int obj;
        it++;
        obj = Object_LookupById(&id);
        PtrVec_PushBack_171C70(self->list, &obj);
    }
    Actor_VirtualLeaf175230(&self->ids);
    self->resolved = 1;
}