#ifndef PLAYER_H_
#define PLAYER_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

// where your player character is at, in consideration of the whole map data, it
// will be calculated with the index(+50 (middle)) variable in draw.c.
extern _Atomic int32_t player_pos;

// this variable is the players heigh on the whole map data, the heigh is in
// rows player_height = 20 meaning player is on row 20:
extern _Atomic int32_t player_height_row;

// this variable is the where the player will stop falling
extern int32_t player_ground_row;

// how high the player will jump in rows this number has to be even
extern int8_t jump_height;

// how fast you will fall in microseconds this number has to be even
extern int32_t jump_fall_speed;

// if it is set to true the if statment in the jump thread
extern bool isJumping;

void *player_jump_thread(void *ptr);

#endif
