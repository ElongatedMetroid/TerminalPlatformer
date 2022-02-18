#ifndef INPUT_H_
#define INPUT_H_

#include "common.h"
#include "movescreen.h"
#include "signalhandler.h" //for oldt settings to restore at exit
#include <termios.h>
#include <unistd.h>

void *input_thread(void *ptr);

#endif
