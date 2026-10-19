#pragma cplusplus on
#include "types.h"
#pragma bool off
/* Physical_SetChildOffsets: apply an orientation to every child root and mark it dirty */
typedef struct { char** p; } It_1E5120;
typedef struct { char pad[0xB4]; int vec; int count; } O_1E5120;
extern "C" {
char** func_001E5250(int* v);
char** func_001E5220(int* v);
void func_001E5240(It_1E5120* out, int* v, char*** p);
char* Root_IdentityAccessor(char* r);
void Transform_SetOrientation(char* t, void* q);
void Root_PropagateChildren(char* r);
void Physical_SetChildOffsets(O_1E5120* self, void* q);
}
static inline int Eq_1E5120(char** a, char** b) { return a == b; }
static inline int EqI_1E5120(int a, int b) { return a == b; }
static inline void SetDirty_1E5120(char* c, unsigned char f) { Root_IdentityAccessor(c)[0xA0] = f; }
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
        t0 = func_001E5250(v);
        func_001E5240(&b, &self->vec, &t0);
        it = b.p;
        t1 = func_001E5220(v);
        func_001E5240(&e, v, &t1);
        end = e.p;
        /* volatile read: retail reloads e.p for the loop guard separately from end */
        if (Eq_1E5120(it, *(char** volatile*)&e.p) ^ 1) {
            do {
                char* c = *it;
                Transform_SetOrientation(Root_IdentityAccessor(c) + 0x50, q);
                SetDirty_1E5120(c, 1);
                Root_PropagateChildren(c);
                it++;
            } while (Eq_1E5120(it, end) ^ 1);
        }
    }
}
