#include "SFOLobby.h"

/* Looks like a Medius game-list filter: field, comparison operator, value. */
typedef struct {
    char messageId[0x15];
    char sessionKey[0x13];
    int field;
    int compare;
    int value;
} Request;
extern void* memset(void* p, int c, int n);
extern int sprintf(char* buf, const char* fmt, ...);
extern char* String_Copy(char* dst, const char* src);
extern void func_0046AC78(Request* req, void (*cb)(void));
extern void func_00446CA0(void);

/* Submits two filter requests: field 4 compared (2) against `value`, and
 * field 7 compared (2) against 1. */
void func_0044E1A0(SFOLobby* self, int value)
{
    Request b;
    Request a;
    memset(&a, 0, sizeof(Request));
    sprintf(a.messageId, "%d", 4);
    String_Copy(a.sessionKey, self->sessionKey);
    a.field = 4;
    a.compare = 2;
    a.value = value;
    func_0046AC78(&a, func_00446CA0);
    memset(&b, 0, sizeof(Request));
    sprintf(b.messageId, "%d", 7);
    String_Copy(b.sessionKey, self->sessionKey);
    b.field = 7;
    b.compare = 2;
    b.value = 1;
    func_0046AC78(&b, func_00446CA0);
}
