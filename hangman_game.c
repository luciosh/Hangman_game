/************************************************
This code uses must basic concepts of the C
language for implement a hangman game
author: sergio lucio
github: srg-lc
email: sergiolucio.ns@gmail.com

See hangman_game.h for function details.
For compile this code, running:
LINUX: ~$./hangman_game

If you want to add a new word, add it in a words.txt
and update the first line with the new quantity
of words.
*************************************************/
#include "hangman_game.h"

int main() {
  int hits = 0, wrongs = 0;
  // Show game opening.
  printf("=================================\n");
  printf("====>     HANGMAN GAME      <====\n");
  printf("=================================\n");
  choiceWord();
  hideWord();
  showHang(&hits, &wrongs);

  // Game repeat loop, continues until player wins or loses.
  do {
    makeGuess();
    showHang(&hits,& wrongs);
  } while (!win() && !lose(&wrongs));

  return 0;
}
