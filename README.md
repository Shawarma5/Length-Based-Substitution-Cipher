Overview:

A lightweight file encryption tool written in C++ that applies a dynamically generated substitution cipher. It reads an input text file, evaluates its total character length, and uses that integer to determine the offset and character spacing for the cipher mapping. Only alphabetical characters are transformed (and converted to lowercase), while spaces, numbers, and punctuation remain untouched.

Operation:

operates via a simple console prompt, asking the user to either encode or decode a file. When encoding, the program reads from a default message.txt file and outputs the resulting ciphertext to encoded_message.txt. When decoding, the user selects between two predefined target files (codedmessage1.txt or codedmessage2.txt), and the program applies the inverse substitution table to generate the restored plaintext in a new text file. All file operations are handled automatically via the standard <fstream> library.
