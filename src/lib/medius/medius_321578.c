/*
 * lib/medius: 2 files, 00321578-003215C8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00321578 */
#include "types.h"
typedef struct { long magic; char pad08[0x10]; unsigned char state; char pad19[3]; void* inner; } Handle_00321578;
extern void func_0031FC10(void* p);
int func_00321578(Handle_00321578* h)
{
    if (h == 0 || h->magic != 0xFACE) return 0x17D4;
    if (h->state != 11) return 0x17E3;
    func_0031FC10(h->inner);
    return 0;
}
/* merge_units: end func_00321578 */

/* merge_units: begin func_003215C8 */
typedef struct { long magic; char pad08[0x10]; unsigned char state; char pad19[3]; void* inner; } Handle_003215C8;
extern void func_0031FC18(void* p);
int func_003215C8(Handle_003215C8* h)
{
    if (h == 0 || h->magic != 0xFACE) return 0x17D4;
    if (h->state != 11) return 0x17E3;
    func_0031FC18(h->inner);
    return 0;
}
/* merge_units: end func_003215C8 */
