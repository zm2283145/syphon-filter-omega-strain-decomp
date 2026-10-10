#include "SFOLobby_Account_types.h"

extern char* strncpy(char* destination, const char* source, unsigned int count);
extern int func_00445420(LobbyAccount* self);
extern void func_004452F0(LobbyAccount* self);

/* Submit the two account fields, then clear their first bytes after use. */
unsigned char func_004459D0(LobbyAccount* self, const char* first, const char* second)
{
    unsigned char result;
    strncpy(self->first, first, 32);
    strncpy(self->second, second, 32);
    result = func_00445420(self);
    if (result)
        func_004452F0(self);
    self->first[0] = 0;
    self->second[0] = 0;
    return result;
}
