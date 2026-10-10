typedef struct NPCInfoObject NPCInfoObject;

extern unsigned char D_00582778;
extern int D_00582A68;
extern void func_004355D0(NPCInfoObject* self);

/* Ensure shared NPC information is initialized and increment its user count. */
NPCInfoObject* func_00436C00(NPCInfoObject* self) {
    if (D_00582778 == 0) {
        func_004355D0(self);
    }
    D_00582A68++;
    return self;
}
