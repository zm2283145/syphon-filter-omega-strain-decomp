/*
 * main/guiMLTextWidget: 2 files, 0043DB80-0043DCE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0043DB80 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "guiMLTextWidget.h"
/* List iterator returned by value (begin/end). */
struct LineIter { MLTextLine* node; };
extern "C" {
void Mem_Free(int, void*, char*, int);
void ObjectList_EraseRange(int*, MLTextLineList*, MLTextLine**, MLTextLine**);
LineIter func_0013B180(MLTextLineList*);                 /* begin() */
LineIter func_0043DB60(MLTextLineList*);                 /* end() */
void func_0043DB70(MLTextLine**, const LineIter&);       /* iterator copy */
void func_0043DB50(MLTextLine**, const LineIter&);       /* iterator copy */
void func_0043BC70(void*, int, int, int, int);           /* scroll bar: set position/range */
}
/* Free every line's text, erase all nodes, scroll to the top. */
extern "C" void MLTextWidget_Clear(MLTextWidget* self) {
    {
        MLTextLine* end;
        {
            MLTextLine* n;
            MLTextLine* it;
            func_0043DB70(&it, func_0013B180(&self->lines));
            n = it;
            while ((func_0043DB50(&end, func_0043DB60(&self->lines)), n != end)) {
                void* text = n->text;
                {
                    AllocGuard g;
                    Mem_Free(0, text, "guiMLTextWidget.cc", 0xCB);
                }
                n = n->next;
            }
        }
        {
            int res;
            MLTextLine* first;
            MLTextLine* last;
            last = (MLTextLine*)&self->lines.last; /* sentinel node */
            first = self->lines.first;
            ObjectList_EraseRange(&res, &self->lines, &first, &last);
        }
    }
    self->scrollPos = 0;
    if (self->scrollBar) func_0043BC70(self->scrollBar, 0, self->scrollPos, 0, self->lines.count - self->visibleLines);
}
#pragma pop /* merge_units */
/* merge_units: end func_0043DB80 */

/* merge_units: begin func_0043DCE0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guiMLTextWidget.h"
extern "C" {
extern char D_004C0110[]; /* "guiMLTextWidget.cc" */
void* Mem_Alloc(int pool, int size, char* file, int line);
void Mem_Free(int pool, void* p, char* file, int line);
int func_0036AA50(void* font, const char* s, int n);     /* text width in pixels */
void MLTextLineList_PushBack(MLTextLineList* list, char* const& text);
void func_00138DA0(void* res, MLTextLineList* list, MLTextLine* const& it); /* erase */
char* strncpy(char*, const char*, int);
}

/*
 * Append text, word-wrapping it to the widget width: lines break at '\n' or at
 * the last space before the width is exceeded. Each new line is prefixed with
 * the colour code in effect; colour codes inside the text update colorIndex.
 * Drops the oldest lines beyond maxLines, then refreshes the scroll bar.
 */
extern "C" void MLTextWidget_AddText(MLTextWidget* self, char* text)
{
    char* cur;
    char* lineStart;
    char* wrapAt;
    int width;
    char* line;
    char* tail;
    if (text == 0 || *text == 0) return;
    cur = text;
    lineStart = text;
    width = (int)self->width;
    wrapAt = 0;
    while (*cur) {
        if (*cur == '\n' || func_0036AA50(self->font, lineStart, cur - lineStart + 1) >= width) {
            if (*cur == '\n') {
                wrapAt = cur;
                cur++;
            } else {
                wrapAt = wrapAt ? wrapAt : cur - 1;
                if (!(lineStart < wrapAt)) return;
            }
            {
                int n = wrapAt - lineStart;
                char* p;
                int i;
                {
                    AllocGuard g;
                    p = (char*)Mem_Alloc(0, n + 2, D_004C0110, 0x93);
                }
                line = p;
                strncpy(p + 1, lineStart, n);
                line[0] = self->colorIndex + MLTEXT_COLOR_CODE_FIRST;
                line[n + 1] = 0;
                for (i = 0; i < n + 1; i++) {
                    char c = line[i];
                    if (c >= MLTEXT_COLOR_CODE_FIRST && c < MLTEXT_COLOR_CODE_END)
                        self->colorIndex = c - MLTEXT_COLOR_CODE_FIRST;
                }
                MLTextLineList_PushBack(&self->lines, line);
                lineStart = wrapAt + 1;
                wrapAt = 0;
            }
        } else {
            if (*cur == ' ') wrapAt = cur;
            cur++;
        }
    }
    if (lineStart < cur) {
        int n = cur - lineStart;
        char* p;
        {
            AllocGuard g;
            p = (char*)Mem_Alloc(0, n + 1, D_004C0110, 0xB1);
        }
        tail = p;
        strncpy(p, lineStart, n);
        tail[n] = 0;
        MLTextLineList_PushBack(&self->lines, tail);
    }
    if (self->maxLines) {
        while (self->lines.count > self->maxLines) {
            char* s = self->lines.first->text;
            {
                AllocGuard g;
                Mem_Free(0, s, D_004C0110, 0xBF);
            }
            {
                int res;
                MLTextLine* it = self->lines.first;
                func_00138DA0(&res, &self->lines, it);
            }
        }
    }
    if (self->scrollBar) func_0043BC70(self->scrollBar, 0, self->scrollPos, 0, self->lines.count - self->visibleLines);
}
#pragma pop /* merge_units */
/* merge_units: end func_0043DCE0 */
