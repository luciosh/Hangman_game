// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Globals variables
char secretWord[20], try = ' ', tries[20], aux_word[20];
int i = 0, qtTries = 0, discoveredLetters = 0;

// Functions declaration
void choiceWord();
int lose(int *wrongs);
void hideWord();
int showHang(int *hits, int *wrongs);
int makeGuess();
int win();
int lose(int *wrongs);

// Function chooses a word from the word file
void choiceWord(){
  int qtWords = 10;
  FILE* f;
  f = fopen("words.txt", "r");
  if(f == NULL){
    printf("Fail to open file!\n");
    exit(1);
  }
  fscanf(f, "%d", &qtWords);
  srand(time(0));
  int randomic = rand() % qtWords;
  for (int i = 0; i <= randomic; i++) {
    fscanf(f, "%s", secretWord);
  }
  fclose(f);
}

// Function makes a mask for hide secret word
void hideWord(){
  for (i = 0; i < strlen(secretWord); i++) {
    aux_word[i] = '_';
  }
  aux_word[i]='\0';
}

// Function checks guess, counts errors and successes, and draws strength
int showHang(int *hits, int *wrongs){
  int repeat = 0;
  for(int i = 0; i < strlen(secretWord); i++){
    if(secretWord[i]==try){
      aux_word[i] = try;
      if(repeat == 0) (*hits)++;
      repeat = 1;
      discoveredLetters++;
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
  (*wrongs) = qtTries-*hits;
  printf("  _______       \n");
  printf(" |/      |      \n");
  printf(" |      %c%c%c  \n", (*wrongs>=2?'(':' '), (*wrongs>=2?'_':' '), (*wrongs>=2?')':' '));
  printf(" |      %c%c%c  \n", (*wrongs>=4?'\\':' '), (*wrongs>=3?'|':' '), (*wrongs>=4?'/': ' '));
  printf(" |       %c     \n", (*wrongs>=5?'|':' '));
  printf(" |      %c %c   \n", (*wrongs>=6?'/':' '), (*wrongs>=6?'\\':' '));
  printf(" |              \n");
  printf("_|___           \n");
  printf("\n\n");
  printf("WORD --->  %s \n", aux_word);
}

// Function gets the guess
int makeGuess(){
  setbuf(stdin, NULL);
  scanf(" %c", &try);
}

// Function checks whether player has won and, if won, congratulates
int win(){
  if (discoveredLetters>=strlen(secretWord)){
    printf("\n Congratulations, you win!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");
    return 1;
  }
  return 0;
}

// Function checks whether player has lose and, if lose, warning
int lose(int *wrongs){
  if (*wrongs>=6){
    printf("\n\n YOU LOSE!\n");
    printf(" The secret word was: **%s**\n\n", secretWord);
    printf("    _______________         \n");
    printf("   /               \\       \n");
    printf("  /                 \\      \n");
    printf("//                   \\/\\  \n");
    printf("\\|   XXXX     XXXX   | /   \n");
    printf(" |   XXXX     XXXX   |/     \n");
    printf(" |   XXX       XXX   |      \n");
    printf(" |                   |      \n");
    printf(" \\__      XXX      __/     \n");
    printf("   |\\     XXX     /|       \n");
    printf("   | |           | |        \n");
    printf("   | I I I I I I I |        \n");
    printf("   |  I I I I I I  |        \n");
    printf("   \\_             _/       \n");
    printf("     \\_         _/         \n");
    printf("       \\_______/           \n");
    return 1;
  }
  return 0;
}
