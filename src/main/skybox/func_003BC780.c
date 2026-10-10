#include "types.h"

typedef struct cSKYBOX_GOBJ {
    void* vtbl;
    char pad04[0x2B];
    unsigned char visible;  /* 0x2F */
    char pad30[0x38];
    int unk68;              /* 0x68 */
    char data6C[0x20];      /* 0x6C */
} cSKYBOX_GOBJ;

extern char D_004DFC70[];
extern void IdMgr_Allocate(int* outId, int type);
extern void cGOBJ_ctor(cSKYBOX_GOBJ* self, int* id, int kind, int* parent);
extern void memset(void* dst, int value, int size);

/* cSKYBOX_GOBJ constructor. */
cSKYBOX_GOBJ* cSKYBOX_GOBJ_ctor(cSKYBOX_GOBJ* self) {
    int parent;
    int id;
    parent = 0;
    IdMgr_Allocate(&id, 0xDC);
    cGOBJ_ctor(self, &id, 5, &parent);
    self->vtbl = D_004DFC70;
    self->visible = 1;
    self->unk68 = 0;
    memset(self->data6C, 0, 0x20);
    return self;
}
