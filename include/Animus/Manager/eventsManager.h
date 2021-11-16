#ifndef EVENTSMANAGER
#define EVENTSMANAGER

extern bool runApp;

extern bool bUp;
extern bool bDown;
extern bool bLeft;
extern bool bRight;
extern bool bMouseClick;
extern bool bMousePress;

extern int iMouseX;
extern int iMouseY;

void EventsManagerUpdate(SDL_Event event);

#endif