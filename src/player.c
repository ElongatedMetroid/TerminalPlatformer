#include "../include/player.h"

_Atomic int32_t player_y_level = 21;
_Atomic int32_t player_pos = 0;
int32_t player_ground_row = 21;

int8_t jump_height = 6;
int32_t jump_fall_speed = 1200000;
bool isJumping = false;

int16_t current_level_number = 1;

// TODO find a good and effiecient way to return levels
char *return_current_level(int level_number) { return level_1_1; }

void *player_jump_thread(void *ptr) {
  while (1) {
    sleep(0);
    // if the isJumping flag is true
    if (isJumping) {
      // make the player jump up 2 rows
      player_y_level -= jump_height;

      // wihle jump_height is not greater than i
      for (int i = 0; i < jump_height; i++) {
        // sleep for half of fall speed each incrementation
        usleep(jump_fall_speed / 2);
        // check if we are at the ground row, if we are we do not want to
        // continue falling so we break from the loop
        if (player_y_level == player_ground_row)
          break;
        // fall half of jump_heigh each incrementation
        player_y_level += jump_height / 2;
      }

      // we are done with our jump "function"
      isJumping = false;
    }
  }
}
