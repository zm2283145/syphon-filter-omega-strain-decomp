#include "types.h"
typedef struct { unsigned char flag; char pad[7]; } D2_FxFlag;
typedef struct { int a; int b; } D2_FxEntry;
extern D2_FxFlag D_004F7A54[];
extern D2_FxEntry D_004F7A50[];
static inline D2_FxEntry* d2_get(int id) {
    if ((unsigned int)id < 41) return &D_004F7A50[id];
    return 0;
}
D2_FxEntry* func_00236F20(signed char id) {
    if (!D_004F7A54[id].flag) return 0;
    return d2_get(id);
}