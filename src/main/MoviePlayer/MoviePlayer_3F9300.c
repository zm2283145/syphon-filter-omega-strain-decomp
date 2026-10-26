/*
 * main/MoviePlayer: 3 files, 003F9300-003F9470
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003F9300 */
#pragma push /* merge_units */
#include "types.h"
extern void cMoviePlayer_Purge(void* self);
extern void MoviePlayer_FreeBuffers(void* self);
extern void FileMan_Release(void* p, int del);
extern void operator_delete(void* p);
void* MoviePlayer_Destroy(void* self, short del)
{
    if (self) {
        void* m;
        cMoviePlayer_Purge(self);
        MoviePlayer_FreeBuffers(self);
        FileMan_Release((char*)self + 0x190, -1);
        m = (char*)self + 0x58;
        if (m)
            FileMan_Release((char*)self + 0x6C, -1);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F9300 */

/* merge_units: begin func_003F9380 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet (calls into MoviePlayer.cc);
 * functions are named by address until real names are known.
 */

#include "loose04_types.h"

extern int cFileMan_EncodeFilename_charP_cFileManR(void*, void*, int*);
extern int Resource_Construct(void*);
extern int MoviePlayer_Start(Unk3F9380*);
extern int MoviePlayer_AllocBuffers(Unk3F9380*);

/* Constructor: clears the object, copies *src into the second sub-object, then runs two setup passes. */
Unk3F9380* MoviePlayer_ctor(Unk3F9380* self, int* src, int arg) {
    self->unk00[0] = 0;
    self->unk00[1] = 0;
    self->unk00[2] = 0;
    self->unk00[3] = 0;
    self->unk00[4] = 0;
    self->unk00[5] = 0;
    self->unk00[6] = 0;
    self->unk00[7] = 0;
    self->unk00[8] = 0;
    self->unk00[9] = 0;
    self->unk00[10] = 0;
    self->unk00[11] = 0;
    self->unk00[12] = 0;
    self->unk00[13] = 0;
    self->unk00[14] = 0;
    self->unk00[15] = 0;
    self->unk00[16] = 0;
    self->unk00[17] = 0;
    self->unk00[18] = 0;
    self->unk00[19] = 0;
    Resource_Construct(self->unk6C);
    self->unk188 = 0;
    self->unk18C = 0;
    Resource_Construct(self->unk190);
    self->unk22C = arg;
    self->unk230 = 0;
    self->unk231 = 0;
    self->unk232 = 0;
    self->unk233 = 0;
    self->unk234 = 0;
    self->unk235 = 0;
    self->unk236 = 1;
    cFileMan_EncodeFilename_charP_cFileManR(self->unk190, src + 1, src);
    MoviePlayer_AllocBuffers(self);
    MoviePlayer_Start(self);
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F9380 */

/* merge_units: begin func_003F9470 */
#pragma push /* merge_units */
typedef struct { char pad[0x14C]; unsigned char active; } O9470;
typedef struct N9470 { int m0; struct N9470* next; O9470 obj; char pad[0x170 - 0x8 - sizeof(O9470)]; unsigned char keep; } N9470;
typedef struct { int m0; int list; } T9470;
extern N9470* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11(void* list);
extern void Hog_Unload(O9470* o);
extern void std_list_deleter_cHogFile_erase_listdeleter(N9470** out, T9470* self, N9470** pos);
void Archive_ReleaseAll(T9470* self)
{
    N9470* end;
    N9470* n = details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11(&self->list)->next;
    end = details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11(&self->list);
    while (n != end) {
        O9470* o = &n->obj;
        if (!n->keep || !o->active) {
            N9470* r;
            N9470* pos;
            if (o->active)
                Hog_Unload(o);
            pos = n;
            std_list_deleter_cHogFile_erase_listdeleter(&r, self, &pos);
            n = r;
        } else {
            n = n->next;
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003F9470 */
