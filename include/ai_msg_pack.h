#ifndef AI_MSG_PACK_H
#define AI_MSG_PACK_H
/*
 * Network Pack() (vtable slot 2) of the AI message classes.
 * Signature: (self, a1, outType, a3, t0, bufLen, buf); returns the packed size or -1.
 *   AIMSG_PACK_BEGIN(name, minLen)  ...  AIMSG_PACK_END(retLen, typeSym)
 * Inline base packers: AIMsg_PackBase (owner id), AINodeMsg_PackBase (two node ids).
 */
typedef struct AIMsgOwner { int pad[3]; int id; } AIMsgOwner;
typedef struct AIMsgNode { int pad[30]; int id; } AIMsgNode;
typedef struct AIMsgPackObj {
    void* vt;
    int pad04[6];
    int size;          /* 0x1C */
    int pad20;
    void* p24;         /* 0x24 */
    void* p28;         /* 0x28 */
} AIMsgPackObj;
extern void Event_PackHeader(AIMsgPackObj* self, int a1, int* type, int a3, int t0, unsigned int len, int* buf);

static inline void AIMsg_PackBase(AIMsgPackObj* self, int a1, int* type, int a3, int t0, unsigned int len, int* buf) {
    if (len >= 0xC && buf != 0) {
        Event_PackHeader(self, a1, type, a3, t0, len, buf);
        self->size = 0x40;
        buf[2] = ((AIMsgOwner*)self->p24)->id;
    }
}
static inline void AINodeMsg_PackBase(AIMsgPackObj* self, int a1, int* type, int a3, int t0, unsigned int len, int* buf) {
    if (len >= 0x10 && buf != 0) {
        Event_PackHeader(self, a1, type, a3, t0, len, buf);
        if (self->p24) buf[2] = ((AIMsgNode*)self->p24)->id; else buf[2] = -1;
        if (self->p28) buf[3] = ((AIMsgNode*)self->p28)->id; else buf[3] = -1;
        self->size = 0x40;
    }
}
#define AIMSG_PACK_BEGIN(name, minLen) \
    int name(AIMsgPackObj* self, int a1, int* type, int a3, int t0, unsigned int len, int* buf) { \
        int r = -1; \
        if (len >= (minLen) && buf != 0) {
#define AIMSG_PACK_END(retLen, typeSym) \
            if (type != 0) { r = (retLen); *type = typeSym; } \
        } \
        return r; \
    }
#endif
