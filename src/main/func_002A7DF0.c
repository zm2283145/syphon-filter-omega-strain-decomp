#include "types.h"

typedef struct Label14 {
    int unk00;
    void* title;   /* 0x04 */
    void* body;    /* 0x08 */
    int pad[2];
} Label14;

typedef struct LabelSet {
    char pad00[0x54];
    int current;           /* 0x54 */
    Label14 labels[4];     /* 0x58 */
} LabelSet;

const unsigned int D_004AB580[4] = { 0x0, 0x0, 0x0, 0x0 };
extern void func_0041BEB0(void* widget, const char* text, int flags);

/* Sets the title/body text of the current label, using "" for null strings. */
void func_002A7DF0(LabelSet* set, const char* title, const char* body) {
    Label14* label = &set->labels[set->current];
    if (label->title) {
        func_0041BEB0(label->title, title ? title : ((char*)D_004AB580), 0);
    }
    if (label->body) {
        func_0041BEB0(label->body, body ? body : ((char*)D_004AB580), 0);
    }
}
