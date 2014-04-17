#ifndef __MASTERMIND_H__
#define __MASTERMIND_H__

#include "defines.h"

void init();
void readPassword(char password[]);
int checkPassword(char password[], char guess[], char feedback[]);
void showFeedback(char feedback[]);
void loser();
void winner();

#endif // __MASTERMIND_H__
