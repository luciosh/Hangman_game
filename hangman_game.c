#include <stdio.h>
#include <string.h>

char secretWord[20], try = ' ', tries[20], aux_word[20];
int win = 0, lose = 0, i = 0, qtTries = 0;

void choiceWord(){
  printf("=================================\n");
  printf("====>     HANGMAN GAME      <====\n");
  printf("=================================\n");
  sprintf(secretWord, "palavrateste");

}

void hideWord(){
  for (i = 0; i < strlen(secretWord); i++) {
    aux_word[i] = '_';
  }
  aux_word[i]='\0';
}

int showHang(){
  for(int i = 0; i < strlen(secretWord); i++){
    if(secretWord[i]==try){
      aux_word[i] = try;
    }
    if(try != ' ' && tries[i] == try){
      printf("\nRepeated letter, try other: \n");
      printf("-> %c <-\n",try);
      printf("WORD --->  %s \n", aux_word);
      return 0;
    }
  }
  tries[qtTries] = try;
  qtTries++;
  printf("WORD --->  %s \n", aux_word);
}

int makeGuess(){
  setbuf(stdin, NULL);
  scanf(" %c", &try);
}

int main() {
  choiceWord();
  hideWord();
  showHang();

  do {
    makeGuess();
    showHang();
  } while (!win && !lose);

  return 0;
}
