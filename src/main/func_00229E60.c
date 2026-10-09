/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern void* D_004DB810;
extern int func_001391E0(int*);
extern int func_003CB110(Unk229E60*);
extern int func_0040F650(void);

Unk229E60* func_00229E60(Unk229E60* self) {
    func_003CB110(self);
    self->vtable = &D_004DB810;
    func_001391E0(&self->unk2C);
    func_0040F650();
    return self;
}
