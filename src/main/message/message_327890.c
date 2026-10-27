typedef struct { char p0[0x10]; int active; char p14[8]; int arg; } E27890;
typedef struct { char pad[0x4C]; int count; E27890* items; char p54[4]; int cur; } T27890;
extern void GuiSlideShow_SetCurrentSlide(T27890* self, int idx, int arg);
extern void GuiSlideShow_NextSlide(T27890* self, int flag);
static inline E27890* At27890(T27890* self, int i)
{
    if (i < 0 || self->count <= i) return 0;
    return &self->items[i];
}
void GuiSlideShow_UpdateCurrentSlide(T27890* self)
{
    int i = self->cur;
    E27890* e = At27890(self, i);
    if (e && e->active)
        GuiSlideShow_SetCurrentSlide(self, i, e->arg);
    else
        GuiSlideShow_NextSlide(self, 1);
}