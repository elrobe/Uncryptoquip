/**
 * Encryptor.h
 *
 * Header file for the Encryptor class.
 * This is a static class that encrypts a message with one of
 *
 * History:
 *   *ERB 01/06/18 - Created
 */

static class Encryptor
{
  private:
    // Fields
    bool ENABLE_SAME_LETTER;

  public:
    // Methods
    static void Monoalphabetic(string* message);
}
