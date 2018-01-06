/**
 * menu.cpp
 *
 * A user-facing menu program to run either the encryption program or
 * decryption program.
 *
 * History:
 *   *ERB 01/06/18 - Created
 */

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

#include "../encrypt/Encryptor.h"

using namespace std;

enum Option
{
  Encryptor = 1,
  Decryptor = 2
};

void Menu()
{
  cout << "Pick a program to run by entering it's number:" << endl;
  cout << "\t(1) Encryptor" << endl;
  cout << "\t(2) Decryptor" << endl;
  cout << endl << "Option: ";
}

Option GetOption()
{
  string input;
  int option;
  bool showErr;
  do
  {
    if ( showErr )
      cerr << "Invalid option!" << endl;

    Menu();
    cin >> input;
    // Convert the input into an integer using a string stream
    stringstream s( input );
    s >> option;

    showErr = true; // Always show the error after the first attempt

  } while ( option != 1 && option != 2 );

  return (Option) option;
}

/*
 * main
 * Entry point for the program.
 */
int main( int argc, char** argv )
{
  Option o = GetOption();
  if ( o == Encryptor )
    cout << "You picked Encryptor" << endl;
  else if ( o == Decryptor )
    cout << "You picked Decryptor" << endl;
  else
    cout << "Not sure what you picked..." << endl;

    return 0;
}
