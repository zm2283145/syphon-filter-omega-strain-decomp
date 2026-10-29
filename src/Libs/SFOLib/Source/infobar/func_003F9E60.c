#pragma enumsalwaysint off
enum TS_9E60 { TS0, TS1, TS2, TS3, TSMAX = 0x7F };
#pragma cplusplus on
struct Col_9E60 { float r, g, b, a; };
struct Item_9E60 {
    char text[0x80];
    Col_9E60 col;
    unsigned char pri;
    unsigned char active;
    char pad92[2];
    float shown;
    float age;
    char pad9C[4];
};
struct Text_9E60 {
    char pad0[0x10]; TS_9E60 state; char pad11[0x2B]; float x3C; char pad40[0x10]; float x50; char pad54[6]; unsigned char x5A;
    bool Done() { return state == TS3 && x5A; }
};
struct Ticker_9E60 {
    Item_9E60 items[8];
    Item_9E60* cur;
    unsigned char minPri;
    char pad505[7];
    Text_9E60* text;
    unsigned char fadingIn;
    unsigned char fadeOut1;
    unsigned char fadeOut2;
    char pad513;
    float fadeInTime;
    float fade1Time;
    float fade2Time;
    float limit1;
    float limit2;
};
extern "C" {
extern char D_004BE220[];
void cTextArea_SetText(Text_9E60* t, const char* s);
void cTextArea_SetColor(Text_9E60* t, Col_9E60* c);
void cTextArea_FadeTo(Text_9E60* t, float a, float b);
}

extern "C" void cInfoBar_NextFrame(Ticker_9E60* self, float dt)
{
    Item_9E60* best;
    float bestAge = -1.0f;
    Item_9E60* it;
    int bestPri = -1;
    int i;

    for (it = self->items, best = 0, i = 0; i < 8; i++, it++) {
        if (it != self->cur && it->active) {
            it->age += dt;
            if (it->pri >= self->minPri) {
                if (it->pri > bestPri || (it->pri == bestPri && it->age > bestAge)) {
                    bestPri = (unsigned char)it->pri;
                    bestAge = it->age;
                    best = it;
                }
            }
        }
    }
    for (it = self->items, i = 0; i < 8; i++, it++) {
        if (it != self->cur && it->active && it->pri == 0) {
            it->active = 0;
            if (best == it && self->cur)
                best = 0;
        }
    }
    if (!self->cur) {
        if (best) {
            Col_9E60 c;
            self->cur = best;
            c = best->col;
            *(int*)&c.a = 0;
            cTextArea_SetText(self->text, best->text);
            cTextArea_SetColor(self->text, &c);
            cTextArea_FadeTo(self->text, best->col.a, self->fadeInTime);
            self->fadingIn = 1;
        }
    } else {
    if (!self->fadingIn)
        self->cur->shown += dt;
    TS_9E60 st = self->text->state;
    if (st == TS3) {
        if (self->text->Done()) {
            self->cur->active = 0;
            self->cur = 0;
            cTextArea_SetText(self->text, D_004BE220);
        }
    } else if (best && self->cur->shown > self->limit1 && !self->fadeOut2) {
        self->fadeOut2 = 1;
        cTextArea_FadeTo(self->text, 0.0f, self->fade2Time);
    } else if (self->limit2 > 0.0f && self->cur->shown > self->limit2 && !self->fadeOut1) {
        self->fadeOut1 = 1;
        cTextArea_FadeTo(self->text, 0.0f, self->fade1Time);
    }
    if (self->fadingIn || self->fadeOut2 || self->fadeOut1) {
        if (self->text->x3C == self->text->x50) {
            self->fadingIn = 0;
            if (self->fadeOut2 || self->fadeOut1) {
                self->fadeOut2 = 0;
                self->fadeOut1 = 0;
                self->cur->active = 0;
                self->cur = 0;
                cTextArea_SetText(self->text, D_004BE220);
            }
        }
    }
    }
}
