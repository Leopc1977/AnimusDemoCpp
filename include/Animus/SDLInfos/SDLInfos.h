#ifndef SDLINFOS
#define SDLINFOS

#include <stdint.h>

int32_t SDLInitFlags;

int frequency;
int16_t format;
int channels;
int chunksizes;

_Bool showCursor;

struct SDLInfos {
    int32_t SDLInitFlags;
    int frequency;
    int16_t format;
    int channels;
    int chunksizes;
    _Bool showCursor;
};
typedef struct SDLInfos SDLInfos;

extern SDLInfos _SDLInfos;

void Init_SDLInfos();

#endif