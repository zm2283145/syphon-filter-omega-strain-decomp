#include "SFOLobby.h"
typedef struct { char pad[0x18]; int kind; char name[1]; } Request;
typedef struct { int type; int pad; int kind; char name[0xA0]; } Record;
extern SFOLobby* D_00585E60;
extern int SFOLobby_NoInstance(void* a0, void* a1, void* a2);
extern void* memset(void* p, int c, int n);
extern char* String_Copy(char* dst, const char* src);
extern void LobbyArray_Append(LobbyArray* list, Record* rec);
/* Reply callback: queues a type-1 inbox entry built from the message. */
void func_00446640(void* a0, void* a1, void* a2, Request* req)
{
    Record rec;
    if (SFOLobby_NoInstance(a0, a1, a2) == 0) {
        memset(&rec, 0, sizeof(rec));
        rec.type = 1;
        rec.kind = req->kind;
        String_Copy(rec.name, req->name);
        LobbyArray_Append(&D_00585E60->inbox, &rec);
    }
}
