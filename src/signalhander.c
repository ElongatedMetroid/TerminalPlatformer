#include "../include/signalhandler.h"
#include <stdlib.h>

void handle_exit(int signum) {
  if ((signum = SIGINT)) {
    printf("Recived Ctrl+C, Saving and Exiting........\n");
  } else if ((signum = SIGSEGV)) {
    printf("Recived Segmentation Fault, Now Saving and Exiting.....\n");
  }

  // properly save the game here

  exit(EXIT_SUCCESS);
}
