#include "../include/signalhandler.h"

struct termios oldt;

void handle_exit(int signum) {
  if (signum == SIGINT)
    printf("Recived Ctrl+C, Saving and Exiting........\n");
  if (signum == SIGSEGV)
    printf("Recived Segmentation Fault, Now Saving and Exiting.....\n");

  // properly save the game here

  // restore the old terminal settings
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  exit(EXIT_SUCCESS);
}
