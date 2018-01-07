/**
 * Encryptor.h
 *
 * Header file for the SubstitutionEncryptor class.
 *
 * History:
 *   *ERB 01/07/18 - Created
 */

#ifndef SUBSTITUTION_ENCRYPTOR_H
#define SUBSTITUTION_ENCRYPTOR_H

#include "Encryptor.h"

class SubstitutionEncryptor : public Encryptor
{
  private:
    // Fields
    char* _alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* _mapping;

  public:
    // Fields
    bool LettersCanEncryptToSelf;

    // Constructors
    SubstitutionEncryptor();

    // Destructor
    ~SubstitutionEncryptor();

    // Methods
    char* MonoalphabeticEncrypt();
};

#endif // SUBSTITUTION_ENCRYPTOR_H
