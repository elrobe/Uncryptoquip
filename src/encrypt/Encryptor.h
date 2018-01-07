/**
 * Encryptor.h
 *
 * Header file for the Encryptor class.
 *
 * History:
 *   *ERB 01/06/18 - Created
 */

#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H

#include "../shared/Message.h"

class Encryptor
{
  protected:
    // Fields
    Message* _message;
    Message* _encryptedMessage;

  public:
    // Constructors
    Encryptor(Message* message);

    // Destructor
    ~Encryptor();

    // Methods
    virtual void Encrypt();

    const Message* GetMessage();

    const Message* GetEncryptedMessage();
};

#endif // ENCRYPTOR_H
