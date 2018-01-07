/**
 * Encryptor.cpp
 *
 * Implementation of the SubstitutionEncryptor class.
 *
 * History:
 *   *ERB 01/07/18 - Created
 */

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#include "SubstitutionEncryptor.h"

using namespace std;

/*
* ToUpper
* Modifies the input string, making all alphabetic characters upper-case.

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

void SubstitutionEncryptor::MonoalphabeticEncrypt()
{
  size_t length = message.length();
  srand( time(NULL) ); // Use the time as a random number seed

  // Generate the blank output string
  char* output = new char[length];

  // Randomize!
  for ( size_t i = 0; i < length; i++ )
  {
    char oldVal = message[i]; // Character to replace
    char newVal = MapLetter( oldVal );
    output[i] = newVal;
  }

  return (string) output;
}
*/
