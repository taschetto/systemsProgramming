/*
  Guilherme Taschetto (c) 2014

  All rights reserved.
*/

#ifndef __MASTERMIND_H__
#define __MASTERMIND_H__

void init();
void readPassword(char label[], char password[]);
void inc(char* c);
int checkPassword(char password[], char guess[], char feedback[2]);
void showFeedback(char feedback[2]);
void loser();
void winner();

#endif // __MASTERMIND_H__
