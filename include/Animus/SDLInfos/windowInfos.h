#ifndef WINDOWINFOS
#define WINDOWINFOS

#include <stdint.h>

extern int iScreenWidth, iScreenHeight;

int x;
int y;

int32_t windowInitFlags;

struct WindowInfo {
    int32_t windowInitFlags;
    int iScreenWidth, iScreenHeight;
    int x;
    int y;
};
typedef struct WindowInfo WindowInfo;

extern WindowInfo _WindowInfo;

void Init_WindowInfos();

#endif