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
 *   Resource_Construct(&e);                      default ctor (flags = 0)
 *   func_0036E4B0(&e, name, handle, extra); ctor, flags |= 1 (|4 if extra)
 *   func_0036E540(&e, name, handle, extra); ctor, flags |= 2 (|4 if extra)
 *   FileMan_Release(&e, -1);         dtor: frees halFile when flags & 0x10,
 *                                  deletes when flag > 0 (-1 = in place)
 * Destroy embedded entries in reverse order (b then a), as the game does.
 * Prototypes take void*; #define FILEMAN_ENTRY_NO_PROTOS to keep typed
 * local declarations instead. Some loaders use a 0xA0 aligned(16) local
 * buffer for the same object (SkaRegistry_LoadAnimation) - keep that as a local type.
 */
#include "fileman_types.h"
#include "layout_assert.h"

LAYOUT_SIZE(FileManEntry, 0x9C);

#ifndef FILEMAN_ENTRY_NO_PROTOS
#ifdef __cplusplus
extern "C" {
#endif
void* Resource_Construct(void* entry);
void* func_0036E4B0(void* entry, const char* name, void* handle, int extra);
void* func_0036E540(void* entry, const char* name, void* handle, int extra);
void* FileMan_Release(void* entry, int flags); /* flags really short */
#ifdef __cplusplus
}
#endif
#endif

#endif /* FILEMAN_ENTRY_H */
