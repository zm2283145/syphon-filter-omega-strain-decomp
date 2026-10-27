#ifndef FILEMAN_ENTRY_H
#define FILEMAN_ENTRY_H

/*
 * FileManEntry API (fileman.cc): the 0x9C-byte file/stream object that is
 * embedded twice in every SoundRequest and opened on the stack by loaders.
 * Layout is FileManEntry from fileman_types.h (flags +0, halFile +0x98);
 * this header adds the size check and the shared prototypes.
 * Plain C or C++; any MW kind.
 *
 * Known fields: flags +0, name[128] +4 (strncpy'd), sub-object +0x88,
 * halFile/handle +0x98.
 *   cFileMan_ctor_void(&e);                      default ctor (flags = 0)
 *   cFileMan_ctor_charP_cFileIOP_bool(&e, name, handle, extra); ctor, flags |= 1 (|4 if extra)
 *   cFileMan_ctor_charP_cHogFileR_bool(&e, name, handle, extra); ctor, flags |= 2 (|4 if extra)
 *   cFileMan_dtor(&e, -1);         dtor: frees halFile when flags & 0x10,
 *                                  deletes when flag > 0 (-1 = in place)
 * Destroy embedded entries in reverse order (b then a), as the game does.
 * Prototypes take void*; #define FILEMAN_ENTRY_NO_PROTOS to keep typed
 * local declarations instead. Some loaders use a 0xA0 aligned(16) local
 * buffer for the same object (cLoader_LoadSingleAnimation_FromHogWithLevelSpecificAnimations) - keep that as a local type.
 */
#include "fileman_types.h"
#include "layout_assert.h"

LAYOUT_SIZE(FileManEntry, 0x9C);

#ifndef FILEMAN_ENTRY_NO_PROTOS
#ifdef __cplusplus
extern "C" {
#endif
void* cFileMan_ctor_void(void* entry);
void* cFileMan_ctor_charP_cFileIOP_bool(void* entry, const char* name, void* handle, int extra);
void* cFileMan_ctor_charP_cHogFileR_bool(void* entry, const char* name, void* handle, int extra);
void* cFileMan_dtor(void* entry, int flags); /* flags really short */
#ifdef __cplusplus
}
#endif
#endif

#endif /* FILEMAN_ENTRY_H */
