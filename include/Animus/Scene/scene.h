#ifndef SCENE
#define SCENE

struct Scene
{
    void (*Initialize)(SDL_Renderer *pRenderer);
    void (*LoadContent)(void);
    void (*Update)(void);
    void (*Draw)(void);
    void (*Quit)(void);
};

typedef struct Scene Scene;

#endif