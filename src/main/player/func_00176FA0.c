/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

/* Virtual-call view of Part: only the slots used here are named (vtable offset in comments). */
struct Part {
    virtual void v00();
    virtual void Update(void* arg); /* +0xC */
};

typedef struct PlayerBody {
    char pad[0x2E0];
    Part partA; /* +0x2E0 */
    char pad2E4[0x3A0 - 0x2E4];
    Part partB; /* +0x3A0 */
} PlayerBody;

typedef struct cPlayer { char pad[0x1A0]; PlayerBody* body; /* +0x1A0 */ } cPlayer;

/* Player virtual 0x12: forwards arg to the two body parts' virtual +0xC. */
extern "C" void cPlayer_v12(cPlayer* self, void* arg)
{
    PlayerBody* body = self->body;
    body->partA.Update(arg);
    body->partB.Update(arg);
}
