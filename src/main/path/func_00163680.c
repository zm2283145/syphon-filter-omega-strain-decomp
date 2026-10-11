#include "types.h"
extern char D_004D9750[];
extern char D_004D9740[];
extern char D_004D9730[];
extern char D_004D9720[];
extern void operator_delete(void* p);
typedef struct { void* vt; } V_3680;
V_3680* func_00163680(V_3680* self, short flag)
{
    if (self) {
        self->vt = D_004D9750;
        if (self) {
            V_3680* m;
            self->vt = D_004D9740;
            m = (V_3680*)((char*)self + 0x10);
            if (m) {
                self[4].vt = D_004D9730;
                if (m)
                    self[4].vt = D_004D9720;
            }
            m = (V_3680*)((char*)self + 0x4);
            if (m) {
                self[1].vt = D_004D9730;
                if (m)
                    self[1].vt = D_004D9720;
            }
        }
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}