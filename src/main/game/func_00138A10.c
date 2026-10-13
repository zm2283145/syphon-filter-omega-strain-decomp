extern int* Event_GetType(void*);
extern int Receiver_HandleEventBase(void*, void*);
extern int LosMgr_Update(void*);
extern int LosReceiver_HandleRequest(void*, void*);
extern int D_005435A0;
extern int D_005436B0;
int LosReceiver_HandleEvent(void* self, void* event)
{
    int type = *Event_GetType(event);
    if (type == D_005436B0)
        return LosMgr_Update(self);
    type = *Event_GetType(event);
    if (type == D_005435A0)
        return LosReceiver_HandleRequest(self, event);
    return Receiver_HandleEventBase(self, event);
}
