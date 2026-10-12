typedef struct Msg {
    void* vtable;
    char base[0x20];
    int a;   /* 0x24 */
    char b;  /* 0x28 */
    int c;   /* 0x2C */
    char d;  /* 0x30 */
    int e;   /* 0x34 */
    char pad[8];
} Msg;
extern char D_00542B60[];
extern char D_004DA930[];
extern void Event_Construct(Msg* m, void* type);
extern void cMessage_dtor(Msg* m, int flags);
extern void AnimCtl_InstallMotion(void* ctl, int id, int a2, int a3, void* p, Msg* m1, Msg* m2, int a7, float f0, float f1);
/* Installs a motion on the actor's anim controller (self+0x34) with two empty stack messages. */
void func_001A13F0(char* self, int* motion, int a2, int a3, int a4)
{
    Msg m1;
    Msg m2;
    Event_Construct(&m1, D_00542B60);
    m1.vtable = D_004DA930;
    m1.a = 0; m1.b = 0; m1.c = 0; m1.d = 0; m1.e = 0;
    Event_Construct(&m2, D_00542B60);
    m2.vtable = D_004DA930;
    m2.a = 0; m2.b = 0; m2.c = 0; m2.d = 0; m2.e = 0;
    AnimCtl_InstallMotion(self + 0x34, motion[0], a2, a3, motion + 1, &m1, &m2, a4, -1.0f, 0.0f);
    m2.vtable = D_004DA930;
    cMessage_dtor(&m2, 0);
    m1.vtable = D_004DA930;
    cMessage_dtor(&m1, 0);
}
