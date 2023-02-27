#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "yorkle.h"

/* Constants containing information about the files used in game
   mechanics */
#define WORD_LIST_FILENAME     "words.txt"
#define TODAYS_ANSWER_FILENAME "answer.txt"
#define STATS_FILENAME         "stats.txt"

/* Printf formats to be used for individual characters based on their
   match to the correct answer */
#define LETTER_FORMAT_IN_PLACE    "\e[42;30m%c\e[0m"
#define LETTER_FORMAT_WRONG_PLACE "\e[40;33m%c\e[0m"
#define LETTER_FORMAT_INCORRECT   "\e[40;37m%c\e[0m"

/**
   Reads the file words.txt and retrieves all words from that
   file. Updates the entries in `valid_words` according to the data in
   that file. If the file contains more than MAX_VALID_WORDS words,
   stops reading after that limit.

   @param valid_words a struct where the list of valid words is to be
   loaded to.

   @returns a non-zero value if the words were successfully loaded, or
   zero if an error happened while attempting to read the file.
*/
int load_valid_words(valid_word_list_t *valid_words) {
  // YOUR CODE HERE
  FILE* filePtr;
  char ch;
  int wordCount = 0;
  int charIdx = 0;
  filePtr = fopen("words.txt", "r");

  if (filePtr == NULL){
    return 0; //return error code 0 if file doesn't exist
  }

  //do while loop: get each char in file
  do {
    ch=fgetc(filePtr); //get character;
    valid_words->words[wordCount][charIdx];
    if (charIdx == WORD_SIZE){
      charIdx = 0;
      wordCount++;
    }
    charIdx++;
    //continue looping until end of file or word limit is reached
  } while (ch != EOF && wordCount < MAX_VALID_WORDS);
  
  fclose(filePtr);
  return 1;
}

/**
   Reads the file answer.txt and retrieves the correct answer to be
   used in the game. Saves the result in `answer` as a string,
   including a string-termination byte. `answer` is expected to have
   space for at least WORD_SIZE+1 characters.

   @param answer The output array where the answer string is to be stored.
    
   @returns a non-zero value if the answer was successfully read, or
   zero if an error happened while attempting to read the file.
 */
int load_todays_answer(char answer[]) {

  // YOUR CODE HERE
}

/**
   Reads the file stats.txt and retrieves the player's current
   stats. Saves the result in `stats_per_num_attempts` and
   `num_missed_words`. If the file does not exist or cannot be opened
   for another reason, sets all stats to zero.

   @param stats struct where player stats are to be loaded to.
 */
void load_stats(player_stats_t *stats) {
  
  // YOUR CODE HERE
}

/**
   Reads one guess attempt from the player. A prompt is provided in
   standard output with the format (replacing 1 with the attempt
   number):
    
       Attempt #1: 

   A space is included at the end of the prompt, but not a line
   break. At most WORD_SIZE characters are read, up to a space-like
   character (space, tab, line break, etc.). Spaces at the start of
   the input are ignored. Any characters read from the user are
   converted to lowercase before returning.
    
   @param num_attempt the attempt number, to be used in the prompt.

   @param attempt an array of characters where the read attempt is to
   be stored. A zero-termination byte is stored at the end of the
   string. Must have space for at least WORD_SIZE+1 characters
   (including the termination byte).
    
   @returns a non-zero value if the attempt was successfully read, or
   zero if an error happened while attempting to read the attempt
   (e.g., EOF).
 */
int read_attempt(unsigned int num_attempt, char attempt[]) {

  // YOUR CODE HERE
}

/**
   Checks if the attempt is a valid guess word, based on
   `valid_words`. If (and only if) it is not a valid word, prints an
   error message to standard error with the format (replacing `xxxxx`
   with the attempt word), followed by a line break:

       'xxxxx' is not a valid word.

   @param valid_words a struct where the list of valid words is stored.

   @param attempt the word guessed by the player.

   @returns a non-zero value if the attempt is a valid word according
   to the list of accepted words, or zero otherwise.
 */
int attempt_is_valid(const valid_word_list_t *valid_words, const char attempt[]) {

  // YOUR CODE HERE
}

/**
   Compares the guessed word with the correct answer, completing the
   result array according to the expected values:
    
   - If the letter at position i of the guess matches the
     corresponding letter in the same position in the answer, then
     `result[i]` is set to LR_IN_PLACE;

   - If the letter at position i of the guess matches some letter in
     the answer, but at a different position, then `result[i]` is set
     to LR_WRONG_PLACE;

   - If none of the matches above are correct, `result[i] is set to
     LR_INCORRECT.

   Note that, if the guess or answer have repeated letters,
   LR_IN_PLACE takes precedence if there is a match, and
   LR_WRONG_PLACE may only be used if the corresponding letter in the
   answer must not have been matched with another letter in the guess.

   Example: if the answer is `bread` and the guess is `erase`, index 1
   gets LR_IN_PLACE (R matches), indices 0 and 2 get LR_WRONG_PLACE (E
   and A are in the answer), index 3 gets LR_INCORRECT (there is no S)
   and index 4 gets LR_INCORRECT (there is an E, but it is matched by
   index 0).

   Another example: if the answer is `blood`, and the guess is
   `boron`, indices 0 and 3 get LR_IN_PLACE (B and the last O match),
   LR_WRONG_PLACE in index 1 (there is another unmatched O in the
   answer, but not at this position) and LR_INCORRECT in indices 2 and
   4 (since there is no R or N in the answer).

   @param todays_answer the answer to be compared against the guessed
   attempt.

   @param attempt the word guessed by the player.
   
   @param result an array where the results of each letter are
   stored. Must have space for WORD_SIZE elements.

   @returns a non-zero value if all letters match with LR_IN_PLACE,
   and zero otherwise. The result is always updated, regardless of the
   return value.
 */
int compare_result(const char todays_answer[], const char attempt[], letter_result_t result[]) {

  // YOUR CODE HERE
}

/**
   Prints the result of the word guessed by the user with appropriate
   visual cues for each letter. The result is prefixed by "Result: ",
   and a line break is added to the end of the word. Each letter is
   printed using the printf format set by LETTER_FORMAT_IN_PLACE,
   LETTER_FORMAT_WRONG_PLACE or LETTER_FORMAT_INCORRECT, according to
   the result array.

   @param attempt the word guessed by the player.

   @param result the result of the comparison of the attempted word
   with the correct answer. Matches the values set by
   `compare_result`.
 */
void print_attempt_result(const char attempt[], const letter_result_t result[]) {

  // YOUR CODE HERE
}

/**
   Updates the stats according to the latest results, and saves the
   new stats to the stats.txt file.

   @param stats struct containing the player current player
   stats. Will be updated based on the new value.

   @param num_attempts the number of attempts the player needed to
   guess the word. If the value is larger than MAX_NUM_ATTEMPTS, then
   the player was unable to guess the word.

   @returns a non-zero value if the stats were successfully saved to
   the file, or zero if an error happened while attempting to write to
   the file.
 */
int save_stats(player_stats_t *stats, unsigned int num_attempts) {

  // YOUR CODE HERE
}

/**
   Prints the currently loaded stats to standard output. The format
   follows the one in the following example, adjusting for proper
   values:

Played: 57
Win %: 96.5%

Guess distribution:
1: 0
2: *** 3
3: ***************** 17
4: ********************* 21
5: ****** 6
6: ******** 8

   @param stats struct containing the player stats.
 */
void print_stats(const player_stats_t *stats) {

  // YOUR CODE HERE
  //get total number of games
  int totalPlayed = 0;
  int numWins = 0;
  double winRate = 0;
  //totalPlayed = total num of wins per attempt + stats.num_missed_words
  for (int i = 0; i < MAX_NUM_ATTEMPTS; i++){
    numWins = numWins + stats->wins_per_num_attempts[i];
  }
  totalPlayed = numWins + stats->num_missed_words;

  printf("Played: %d\n", totalPlayed);

  winRate = numWins / totalPlayed;
  printf("Win \%: %lf\%\n\n", winRate);

  printf("Guess distribution:");

  //print distribution
  for (int i = 0; i < MAX_NUM_ATTEMPTS; i++){
    int wins = stats->wins_per_num_attempts[i];
    printf("%d:", i);
    for(int j = 0; j < wins ; j++){
        if (j == 0)
          printf(" ");
        printf("*");
    }
    printf(" %d\n", wins);
  }

  
}