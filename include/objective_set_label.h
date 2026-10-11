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

extern unsigned char D_005721C8;
extern char D_0051F0B0[];
extern char D_004DE4F0[];
extern void* Loc_LookupText(char* key);
extern int func_00228B20(ObjLabelObjective* self, void* text);
extern void Event_Construct(ObjLabelMsg* msg, void* name);
extern void Transport_Send(int target, ObjLabelMsg* msg, int a, int b);
extern void cMessage_dtor(ObjLabelMsg* msg, int flags);
extern char* strncpy(char* dst, const char* src, unsigned int n);

#define DEFINE_OBJECTIVE_SET_LABEL(name, labelOffset, msgKind)                \
    void name(ObjLabelObjective* self, char* key, int quiet)                  \
    {                                                                         \
        ObjLabelMsg msg;                                                      \
        ObjLabelMsg* m;                                                       \
        *(int*)((char*)self + (labelOffset)) =                                \
            func_00228B20(self, Loc_LookupText(key));                         \
        if (D_005721C8 && !quiet) {                                           \
            int id = self->id;                                                \
            m = &msg;                                                         \
            Event_Construct(m, D_0051F0B0);                                   \
            m->vtable = D_004DE4F0;                                           \
            m->objectiveId = id;                                              \
            m->kind = (msgKind);                                              \
            if (key)                                                          \
                strncpy(m->key, key, 16);                                     \
            m->flags = 0x40;                                                  \
            Transport_Send(self->id, &msg, -1, -1);                           \
            msg.vtable = D_004DE4F0;                                          \
            cMessage_dtor(&msg, 0);                                           \
        }                                                                     \
    }

#endif /* OBJECTIVE_SET_LABEL_H */