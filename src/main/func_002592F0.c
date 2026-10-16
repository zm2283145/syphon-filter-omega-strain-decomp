#include "types.h"
typedef struct { float x, y, z, w; } V4_92F0;
typedef struct { V4_92F0 mn; V4_92F0 mx; } Box_92F0;
extern signed char D_004F7FB0;
extern Box_92F0 D_004F7FC0;
extern char* D_004FFD30;
typedef struct { char pad[0x60]; char* p; unsigned char idx; } Self_92F0;
void* WeaponPreview_GetBounds(Self_92F0* self)
{
    char* p;
    if (!D_004F7FB0) {
        D_004F7FC0.mn.x = 3.4028235e38f; D_004F7FC0.mn.y = 3.4028235e38f; D_004F7FC0.mn.z = 3.4028235e38f; D_004F7FC0.mn.w = 1.0f;
        D_004F7FC0.mx.x = -3.4028235e38f; D_004F7FC0.mx.y = -3.4028235e38f; D_004F7FC0.mx.z = -3.4028235e38f; D_004F7FC0.mx.w = 1.0f;
        D_004F7FB0 = 1;
    }
    p = self->p;
    if (!p && self->idx != 7) p = ((char**)(D_004FFD30 + 0xB8))[self->idx];
    return p ? (void*)(p + 0x3E0) : (void*)&D_004F7FC0;
}
