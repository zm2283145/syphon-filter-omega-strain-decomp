#include "types.h"
#include "scriptUtils_types.h"

extern void Voice_PlayQuip(int speaker, int quip, int flags);

/* Script native: PlayQuip(speaker, quip).
 * volatile mirrors the original stack temporaries. */
int Script_PlayQuip(ScriptArg* args) {
    volatile int quipSlot;
    volatile int speakerSlot;
    int speaker;
    int quip;

    quipSlot = args[1].i;
    speaker = args[0].i;
    quip = quipSlot;
    speakerSlot = speaker;
    Voice_PlayQuip(speakerSlot, quip, 0);
    return 0;
}
