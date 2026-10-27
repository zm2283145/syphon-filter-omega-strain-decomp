#ifndef OBJECTIVE_SET_LABEL_H
#define OBJECTIVE_SET_LABEL_H

/*
 * cObjective label setters: resolve the localized text for `key`, store the
 * handle at labelOffset, and (when networking is active and not quiet)
 * broadcast an objective-label message of the given kind carrying the key.
 */
typedef struct ObjLabelMsg {
    void* vtable;
    char base04[0x18];
    int flags;
    char pad20[0x0C];
    unsigned char kind;
    char pad2D[7];
    int objectiveId;
    char key[16];
} ObjLabelMsg;

typedef struct ObjLabelObjective {
    char pad00[0x0C];
    int id;
} ObjLabelObjective;

extern unsigned char g_IsMultiplayer;
extern char D_0051F0B0[];
extern char D_004DE4F0[];
extern void* nGlobalization_GetString_charP(char* key);
extern int cObjective_CopyStr(ObjLabelObjective* self, void* text);
extern void cMessage_ctor_cMessageNameR(ObjLabelMsg* msg, void* name);
extern void cNetObj_SendMessage_int_cMessageR_int_int(int target, ObjLabelMsg* msg, int a, int b);
extern void cMessage_dtor(ObjLabelMsg* msg, int flags);
extern char* strncpy(char* dst, const char* src, unsigned int n);

#define DEFINE_OBJECTIVE_SET_LABEL(name, labelOffset, msgKind)                \
    void name(ObjLabelObjective* self, char* key, int quiet)                  \
    {                                                                         \
        ObjLabelMsg msg;                                                      \
        ObjLabelMsg* m;                                                       \
        *(int*)((char*)self + (labelOffset)) =                                \
            cObjective_CopyStr(self, nGlobalization_GetString_charP(key));                         \
        if (g_IsMultiplayer && !quiet) {                                           \
            int id = self->id;                                                \
            m = &msg;                                                         \
            cMessage_ctor_cMessageNameR(m, D_0051F0B0);                                   \
            m->vtable = D_004DE4F0;                                           \
            m->objectiveId = id;                                              \
            m->kind = (msgKind);                                              \
            if (key)                                                          \
                strncpy(m->key, key, 16);                                     \
            m->flags = 0x40;                                                  \
            cNetObj_SendMessage_int_cMessageR_int_int(self->id, &msg, -1, -1);                           \
            msg.vtable = D_004DE4F0;                                          \
            cMessage_dtor(&msg, 0);                                           \
        }                                                                     \
    }

#endif /* OBJECTIVE_SET_LABEL_H */