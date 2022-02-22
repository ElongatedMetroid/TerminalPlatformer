#include "../include/common.h"
#include "../include/draw.h"
#include "../include/input.h"
#include "../include/player.h"
#include "../include/signalhandler.h"
#include <pthread.h>
#include <signal.h>
#include <stdio.h>

int main() {
  // thread ID's for input and draw
  pthread_t input_thread_id = 0, draw_thread_id = 0, jump_thread_id = 0;

  // if we recive Ctrl+C purpously save and exit
  signal(SIGINT, handle_exit);
  // if we recive a Segmentation Fault save and exit
  signal(SIGSEGV, handle_exit);

  // create thread for checking input
  if (pthread_create(&input_thread_id, NULL, input_thread, NULL) != 0)
    ERROR("Could not create input thread!\n");

  // create thread for drawing mapdata
  if (pthread_create(&draw_thread_id, NULL, draw_thread, NULL) != 0)
    ERROR("Could not create draw thread!\n");

  // create thread for the player jumping this is for pauses between jumping and
  // falling this thread allows you to move while already having jumped
  if (pthread_create(&jump_thread_id, NULL, player_jump_thread, NULL) != 0)
    ERROR("Could not create jump thread!\n");

  // the program will never exit from here since our thread our infinite, the
  // only way to exit is from an error, catching a signal, or getting the key q
  pthread_join(input_thread_id, NULL);
  pthread_join(draw_thread_id, NULL);
  pthread_join(jump_thread_id, NULL);
  pthread_exit(NULL);
}
