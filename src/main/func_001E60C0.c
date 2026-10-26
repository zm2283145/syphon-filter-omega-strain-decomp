#include "types.h"
typedef struct { char pad00[3]; unsigned char version; char pad04[0x14]; int dataOffset; char pad1C[0x10]; int key; } Hdr_60C0;
typedef struct { Hdr_60C0* hdr; } Ref_60C0;
typedef struct { int unk00; Ref_60C0* ref; } Owner_60C0;
typedef struct { unsigned char a, b, c, d; } Surf_60C0;
typedef struct { int index; Owner_60C0* owner; } Src_60C0;
extern signed char D_004E9F98;
extern int D_004F4FD0;
extern Surf_60C0 D_004E9FA0;
extern unsigned char D_004E9FA2;
extern void cCollisionModel_FaceProperties_dtor(void);
extern void __register_global_object(void*, void*, void*);
extern char* cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_3(Hdr_60C0* owner, int* key);
extern unsigned char* cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_5(Hdr_60C0* hdr, int* offset);
extern void GatherRecords_Append(void* out, unsigned char* rec, int index, Surf_60C0* surf, Owner_60C0* owner);
extern void Col_CalcTriangleNormal(void* out);
static inline Surf_60C0* GetSurf_60C0(Owner_60C0* ctx, int index) {
    int key[1];
    Hdr_60C0* owner = ctx->ref->hdr;
    if (owner->version < 3) {
        if (D_004E9F98 == 0) {
            D_004E9FA0.a = 0;
            D_004E9FA2 = 0;
            __register_global_object(&D_004E9FA0, cCollisionModel_FaceProperties_dtor, &D_004F4FD0);
            D_004E9F98 = 1;
        }
        return &D_004E9FA0;
    }
    key[0] = owner->key;
    return (Surf_60C0*)(cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_3(owner, key) + index * 16);
}
void Col_ReconstructSourceTriangle(void* out, Src_60C0* src) {
    unsigned char* rec;
    int surf;
    Owner_60C0* owner;
    int index;
    int offset64;
    int offset32;
    int offset16;
    Hdr_60C0* hdr;
    owner = src->owner;
    index = src->index;
    hdr = owner->ref->hdr;
    if (hdr->version < 4) {
        offset64 = hdr->dataOffset;
        rec = cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_5(hdr, &offset64) + index * 64;
    } else if (hdr->version < 5) {
        offset32 = hdr->dataOffset;
        rec = cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_5(hdr, &offset32) + index * 32;
    } else {
        offset16 = hdr->dataOffset;
        rec = cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_5(hdr, &offset16) + index * 16;
    }
    surf = (unsigned char)(rec[10] >> 1);
    GatherRecords_Append(out, rec, index, GetSurf_60C0(owner, surf), owner);
    Col_CalcTriangleNormal(out);
}