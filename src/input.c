#include "../include/common.h"

void *input_thread(void *ptr) {
  char ch = '\0';
  while (1) {
    ch = fgetc(stdin);
    if ((ch = 'a')) { // move left
      for (int i = 0; i < MAP_DATA_PRINT_SIZE; i++) {
      }
    }
    if ((ch = 'd')) { // move right
      for (int i = 0; i < MAP_DATA_PRINT_SIZE; i++) {
      }
    }
  }
}
