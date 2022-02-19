#ifndef SIGNALHANDLER_H_
#define SIGNALHANDLER_H_

#include "common.h"
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

// structure for storing our original terminal settings
extern struct termios oldt;

// handle exiting, most times from signals
void handle_exit(int signum);

#endif
