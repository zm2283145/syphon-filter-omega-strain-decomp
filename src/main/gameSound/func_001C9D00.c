#pragma cplusplus on
extern "C" {
int* Event_GetType(void* msg);
extern int D_004F5370, D_004F5378, D_005436B0, D_004F53B8, D_004F53C8, D_004F53D8, D_004F53E8;
void func_001C9BF0(void*);
void func_001C98D0(void*);
void func_001C8E10(void*);
void SoundMgr_ProcessAction(void*, void*);
void GameSound_StopSound(void*, void*);
void func_001C7E00(void*, unsigned char);
int Receiver_HandleEventBase(void*, void*);
}
struct Msg { char pad[0x24]; unsigned char b24; char pad2[0xB]; char data[1]; };
extern "C" unsigned char SoundMgr_OnMessage(void* self, Msg* msg)
{
    unsigned char r = 1;
    int t = *Event_GetType(msg);
    if (t == D_004F5370) {
        func_001C9BF0(self);
    } else if (t = *Event_GetType(msg), t == D_004F5378) {
        func_001C98D0(self);
    } else if (t = *Event_GetType(msg), t == D_005436B0) {
        func_001C8E10(self);
    } else if (t = *Event_GetType(msg), t == D_004F53B8) {
        SoundMgr_ProcessAction(self, msg->data);
    } else if (t = *Event_GetType(msg), t == D_004F53C8) {
        SoundMgr_ProcessAction(self, msg->data);
    } else if (t = *Event_GetType(msg), t == D_004F53D8) {
        GameSound_StopSound(self, msg->data);
    } else if (t = *Event_GetType(msg), t == D_004F53E8) {
        func_001C7E00(self, msg->b24);
    } else {
        r = Receiver_HandleEventBase(self, msg);
    }
    return r;
}
