/**
 * encrypt.cpp
 *
 * A small, C-style program to encrypt user input with a randomized
 * substitution cipher.
 *
 * History:
 *   *ERB 01/06/18 - Created
 */

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// Globals
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string MAP =      "                          ";

// Not currently used; will turn on/off the ability to encrypt a letter
// to itself. E.g. I -> I
bool SAME_LETTER_ENCRYPTION_ON = false;

/*
 * ToUpper
 * Modifies the input string, making all alphabetic characters upper-case.
 */
void ToUpper(string* s)
{
  for ( size_t i = 0; i < (*s).length(); i++ )
    ((*s)[i]) = toupper( ((*s)[i]) );
}

/*
 * ToMap
 * Translates an uppercase letter to an index into the map, based on the
 * position of the letter in the alphabet.
 * All non-uppercase alphabetic letters will return -1.
 */
int ToMap(char c)
{
  if ( c >= 'A' && c <= 'Z' )
    return c - 'A'; // Map A-Z, uppercase only
  return -1;
}

/*
 * MapLetter
 * Takes in a random integer value and returns a random letter that
 * hasn't been used yet for the encryption.
 */
char MapLetter(char oldVal)
{
  // Turn the old value into an index into the map based on it's position
  // in the alphabet.
  int idx = ToMap( oldVal );
  if ( idx == -1 )
    return oldVal; // Return the character if non-alphabetic

  // See if a new letter has been mapped to the old letter yet.
  char newVal = MAP[idx];
  if ( newVal != ' ' )
    return newVal;

  // If we don't have a mapping yet, create it and remove the newly
  // mapped character from the list of possible characters.
  int randIdx = rand() % ALPHABET.length();

  //if ( SAME_LETTER_ENCRYPTION_ON )
  //{
    // Not used yet
  //}

  newVal = ALPHABET[randIdx];
  MAP[idx] = newVal;
  ALPHABET.replace( randIdx, 1, "" ); // Remove the letter from the alphabet

  // Debug printout for the mapping
  //cout << "Mapping " << oldVal << " -> " << newVal << endl;

  return newVal;
}

/*
 * main
 * Entry point for the program.
 */
int main( int argc, char** argv )
{
  // Replace this with taking in user input, a text file, etc.
  string input = "a young male deer was running around trying to catch others. I presume they were playing stag.";
  ToUpper( &input );

  //cerr << input << endl << endl;

  size_t length = input.length();
  srand( time(NULL) ); // Use the time as a random number seed

  // Generate the blank output string
  char* output = new char[length];

  // Randomize!
  for ( size_t i = 0; i < length; i++ )
  {
    char oldVal = input[i]; // Character to replace
    char newVal = MapLetter( oldVal );
    output[i] = newVal;
  }

  // Replace this with output matching the input method
  cout << output << endl << endl;
  delete output;

  return 0;
}
