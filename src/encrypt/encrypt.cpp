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
const char NULL_CHAR = '\0';
const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const size_t ALPHA_LENGTH = ALPHABET.length();
string USED =           "                          ";
size_t USED_COUNT = 0;

/*
 * ToUpper
 * Takes in any old string and returns a version of it with every
 * alphabetic character in upper-case.
 */
string ToUpper(string s)
{
  string out;
  for ( size_t i = 0; i < s.length(); i++ )
    out += toupper( s[i] );

  return out;
}

/*
 * GetLetter
 * Takes in a random integer value and returns a random letter that
 * hasn't been used yet for the encryption.
 */
char GetLetter(int r)
{
  int idx = r % ALPHA_LENGTH; // 26 possible letters
  if ( USED[idx] != ' ' )
    return NULL_CHAR;

  char c = ALPHABET[idx];
  USED[idx] = c;
  USED_COUNT++;
  return c;
}

/*
 * main
 * Entry point for the program.
 */
int main( int argc, char** argv )
{
  // Replace this with taking in user input, a text file, etc.
  string input = "a young male deer was running around trying to catch others. I presume they were playing stag.";
  input = ToUpper( input );

  cerr << input << endl << endl;

  size_t length = input.length();
  srand( time(NULL) ); // Use the time as a random number seed

  // Generate the blank output string
  char* output = new char[length];
  for ( size_t i = 0; i < length; i++ )
    output[i] = ' ';

  // Randomize!
  for ( size_t i = 0; i < length; i++ )
  {
    if ( USED_COUNT == ALPHA_LENGTH )
      break;

    char replace = input[i]; // Character to replace

    // Skip already determined letters
    if ( output[i] != ' ' )
      continue;

    // Skip all non-alphabetic characters
    if ( !isalpha(replace) )
    {
      output[i] = replace;
      continue;
    }

    // Get a random letter to replace with
    char cur = NULL_CHAR;
    while ( cur == NULL_CHAR )
      cur = GetLetter( rand() );

    // Debug printout of the mapping
    //cerr << replace << " -> " << cur << endl;

    // Replace all later instances of the letter
    for ( size_t j = i; j < input.length(); j++ )
    {
      if ( input[j] == replace )
        output[j] = cur;
    }
  }

  // Output the crypoquip
  cout << output << endl << endl;
  delete output;

  return 0;
}
