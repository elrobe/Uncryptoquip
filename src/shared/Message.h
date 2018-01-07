/**
 * Message.h
 *
 * Header file for the Message class.
 * This class represents a character array for a message, whether it
 * be before encryption, after encryption, before decryption, or
 * after decryption.
 *
 * History:
 *   *ERB 01/07/18 - Created
 */

#ifndef MESSAGE_H
#define MESSAGE_H

class Message
{
  private:
    // Fields
    char* _msg;

  public:
    // Constructors
    Message(char* msg);

    // Destructor
    ~Message();
};

#endif // MESSAGE_H
