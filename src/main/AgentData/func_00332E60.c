#pragma cplusplus on
struct E32E60 { int id; int a; unsigned char stat; char p9[7]; int need; int p14; };
struct A32E60 { int p0, p4; int stats[1]; };
extern "C" {
extern char D_00532AD0[];
extern int D_00532AD4;
E32E60** func_00330820(void* v);
int Loc_FindKeyThunk(const char* key);
}
static inline bool Neq32E60(E32E60* a, E32E60* b) { return !(a == b); }
extern "C" bool cAgentData_HasRating(A32E60* self, const char* key)
{
    E32E60* first = *func_00330820(D_00532AD0);
    E32E60* last = *func_00330820(D_00532AD0) + D_00532AD4;
    int k = Loc_FindKeyThunk(key);
    for (; Neq32E60(first, last); first++) {
        if (k == first->id)
            return !(self->stats[first->stat] < first->need);
    }
    return false;
}