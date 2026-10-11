#pragma cplusplus on
typedef struct { char pad0[0x3C]; char x3C[0x26]; unsigned char b62; char pad1[0xB4-0x63]; void* pB4; } Obj_0012FC30;
extern "C" {
void EventQueue_ClearAll(void);
void func_002CB160(void* p);
void MsgQueue_ClearPending(void);
void func_003F9470(void* p);
}
extern "C" void func_0012FC30(Obj_0012FC30* o)
{
    EventQueue_ClearAll();
    if (o->b62) func_002CB160(o->pB4);
    MsgQueue_ClearPending();
    func_003F9470(o->x3C);
}