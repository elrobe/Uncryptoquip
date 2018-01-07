/**
 * Message.cpp
 *
 * Implementation of the Message class.
 * This class represents a character array for a message, whether it
 * be before encryption, after encryption, before decryption, or
 * after decryption.
 *
 * History:
 *   *ERB 01/07/18 - Created
 */

#include <cstdlib>

#include "Message.h"

using namespace std;

Message::Message(char* msg)
{
  size_t length = (sizeof(msg))/(sizeof(*msg));
  _msg = new char[length];
  for ( size_t i = 0; i < length; i++ )
    _msg[i] = msg[i];
}

Message::~Message()
{
  delete _msg;
}
