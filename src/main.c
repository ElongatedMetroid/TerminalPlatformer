#include "../include/common.h"
#include <pthread.h>
#include <stdio.h>

int main() {
  pthread_t input_thread_id = 0;

  if (pthread_create(&input_thread_id, NULL, input_thread, NULL) == 0) {
    ERROR("Could not create input thread!\n");
  }

  printf("test\n");
}
