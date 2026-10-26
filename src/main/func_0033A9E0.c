#pragma cplusplus on
struct Tag3A9E0 {};
struct V3A9E0 { int cap; int size; char* buf; };
extern "C" void std_vector_pod_eRequirementState_do_assign(V3A9E0* self, char* b, char* e, Tag3A9E0 t);
extern "C" V3A9E0* std_vector_pod_eRequirementState_opAssign(V3A9E0* self, V3A9E0* o)
{
    if (self != o) {
        Tag3A9E0 t;
        std_vector_pod_eRequirementState_do_assign(self, o->buf, o->buf + o->size, t);
    }
    return self;
}