#ifndef __MASTERMIND_H__
#define __MASTERMIND_H__

#include "defines.h"

void readPassword(byte password[]);
int check(byte password[], byte guess[], char feedback[]);

#endif // __MASTERMIND_H__
