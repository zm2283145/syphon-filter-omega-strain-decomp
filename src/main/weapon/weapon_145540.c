/*
 * main/weapon: range (3 files, 00145540-00145710)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "buf_holder_dtor.h"
#pragma pop
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int strlen(const char *);

/* merge_units: begin func_00145540 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(func_00145540)
#pragma pop /* merge_units */
/* merge_units: end func_00145540 */

/* merge_units: begin func_00145630 */
#pragma push /* merge_units */
typedef struct { char pad[0x41C]; int refs; } R_5630;
typedef struct { char pad[0xE0]; char xE0[0x40]; char name[0x18]; unsigned char count; char mode; char pad4[2]; R_5630* res; } E_5630;
typedef struct { char pad[0x14]; E_5630* e; } S_5630;
extern int strstr(char* a, char* b);
extern void String_CompareNoCase(char* a, char* b);
extern void WeaponDb_FreeModel(S_5630* self, R_5630* r);
void WeaponDb_Unload(S_5630* self, int idx, int release)
{
    E_5630* e = &self->e[idx];
    e->count--;
    if (e->count == 0) {
        if (strlen(e->name) && !strstr(e->name, ".skl"))
            strstr(e->name, ".SKL");
        String_CompareNoCase(e->xE0, "na");
        if (e->res) {
            e->res->refs--;
            if (release && e->res->refs <= 0)
                WeaponDb_FreeModel(self, e->res);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00145630(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00145630 */

/* merge_units: begin func_00145710 */
#pragma push /* merge_units */
typedef struct { char pad[0x41C]; int refs; } R_5710;
typedef struct { char pad[0xCC]; unsigned char cc; char pad2[0x108 - 0xCD]; unsigned char x108; char pad3[0x138 - 0x109]; unsigned char count; char mode; char pad4[2]; R_5710* res; } E_5710;
typedef struct { char pad[0x14]; E_5710* e; } S_5710;
extern void WeaponDb_LoadModel(S_5710* self, E_5710* e, R_5710** out, int idx, int z, int cc, int x108);
void WeaponDb_Preload(S_5710* self, int idx, char mode)
{
    E_5710* e = &self->e[idx];
    e->count++;
    if (e->res)
        e->res->refs++;
    if (e->count < 2) {
        e->mode = mode;
        if (!e->res) {
            WeaponDb_LoadModel(self, e, &e->res, idx, 0, e->cc, e->x108);
            if (e->res)
                e->res->refs++;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00145710(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00145710 */
