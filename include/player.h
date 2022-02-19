#ifndef PLAYER_H_
#define PLAYER_H_

#include <stdint.h>

// where your player character is at, in consideration of the whole map data, it
// will be calculated with the index(+50 (middle)) variable in draw.c.
extern _Atomic int32_t player_pos;

#endif
