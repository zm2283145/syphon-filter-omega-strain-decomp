#pragma opt_unroll_loops off
#pragma opt_strength_reduction off
#pragma cplusplus on
typedef struct { char p0[0x10]; int n; char p14[0xC]; } E27960;
typedef struct { unsigned short type; unsigned short mod; unsigned short p4; unsigned short x6; unsigned short key; } Ev27960;
typedef struct { char pad[0x4C]; int count; E27960* items; char p54[0x18]; char s6C[0xC]; char s78[0xC]; int x84; } T27960;
extern "C" int GuiSlideShow_NextSlide(T27960* self, int flag);
extern "C" int Gui_Canvas(void);
extern "C" int Gui_Manager(void);
extern "C" void GuiWidget_SendMessage(T27960* self, int v, int f, int a, int b);
extern "C" int std_basic_string_char_char_traits_char_c_str(void* s);
extern "C" int GuiManager_OpenGui(int a, int b, int c);
extern "C" void GuiCanvas_Transition(int a, T27960* self, int b);

static inline int Total(T27960* self)
{
    int total = 0;
    int i;
    int j;
    E27960* d;
    int n;
    i = 0;
    if (0 < *(volatile int*)&self->count) {
        d = self->items;
        do {
            n = d[i].n;
            for (j = 0; j < n; j++) total++;
            i++;
        } while (i < *(volatile int*)&self->count);
    }
    return total;
}

static inline bool IsKey(Ev27960* e, unsigned short key)
{
    return e->type == 1 && e->mod == 0 && e->key == key && e->x6 == 0;
}

extern "C" int GuiSlideShow_onInput(T27960* self, Ev27960* e)
{
    if (IsKey(e, 0x2000)) {
        if (Total(self) > 1 && GuiSlideShow_NextSlide(self, 1))
            GuiWidget_SendMessage(self, Gui_Canvas(), 0x10, 2, 0);
        return 1;
    }
    if (IsKey(e, 0x8000)) {
        if (Total(self) > 1 && GuiSlideShow_NextSlide(self, 0))
            GuiWidget_SendMessage(self, Gui_Canvas(), 0x10, 2, 0);
        return 1;
    }
    if (IsKey(e, 0x10)) {
        int b = std_basic_string_char_char_traits_char_c_str(self->s78);
        int a = std_basic_string_char_char_traits_char_c_str(self->s6C);
        int r = GuiManager_OpenGui(Gui_Manager(), a, b);
        if (r) {
            GuiWidget_SendMessage(self, r, 0x3000, self->x84, 0);
            GuiCanvas_Transition(Gui_Canvas(), self, r);
        }
        return 1;
    }
    return 0;
}
