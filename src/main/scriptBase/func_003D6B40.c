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
extern void func_003D6580(Writer* w, int value);
extern int func_003D6570(Writer* w, int size);
extern void func_003D63C0(Writer* w, int words);
extern void String_Copy(char* dst, const char* src);

/* Serializes the node name (length, padded string) and its kind byte. */
void func_003D6B40(NamedNode* node, Writer* w) {
    int n;
    char* name;
    name = node->name;
    n = strlen(name) + 1;
    func_003D6580(w, n);
    n = func_003D6570(w, n);
    func_003D63C0(w, n);
    String_Copy((char*)w->cursor, name);
    w->cursor += n;
    func_003D6580(w, node->kind);
}
