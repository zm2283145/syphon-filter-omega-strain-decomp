/*
 * main/scriptBase: 2 files, 003D6B40-003D6BE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D6B40 */
#pragma push /* merge_units */
#include "types.h"

typedef struct NamedNode {
    char* name;            /* 0x00 */
    char pad04[0x41];
    unsigned char kind;    /* 0x45 */
} NamedNode;

typedef struct Writer {
    char pad00[0xA8];
    int* cursor;           /* 0xA8 */
} Writer;

extern int strlen(const char* s); /* strlen */
extern void ScriptFileBuff_put(Writer* w, int value);
extern int ScriptFileBuff_charsToInts(Writer* w, int size);
extern void ScriptFileBuff_expand(Writer* w, int words);
extern void String_Copy(char* dst, const char* src);

/* Serializes the node name (length, padded string) and its kind byte. */
void ClassDef_exportNames(NamedNode* node, Writer* w) {
    int n;
    char* name;
    name = node->name;
    n = strlen(name) + 1;
    ScriptFileBuff_put(w, n);
    n = ScriptFileBuff_charsToInts(w, n);
    ScriptFileBuff_expand(w, n);
    String_Copy((char*)w->cursor, name);
    w->cursor += n;
    ScriptFileBuff_put(w, node->kind);
}
#pragma pop /* merge_units */
/* merge_units: end func_003D6B40 */

/* merge_units: begin func_003D6BE0 */
#pragma push /* merge_units */
typedef struct { const char* name; } E6BE0;
typedef struct { int m0; int m4; int m8; int* mC; } T6BE0;
extern E6BE0** std_vector_FieldDefPtr_opIndex_uint(int* list, int i);
extern int String_CompareNoCase(const char* a, const char* b);
int ClassDef_findField(T6BE0* self, const char* name)
{
    int n = self->m8;
    int i;
    for (i = 0; i < n; i++) {
        if (!String_CompareNoCase((*std_vector_FieldDefPtr_opIndex_uint(&self->m4, i))->name, name))
            return self->mC[i];
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D6BE0 */
