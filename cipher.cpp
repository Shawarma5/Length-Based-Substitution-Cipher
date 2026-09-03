#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

string readFile(string filename) {
    ifstream in(filename.c_str());
    string text = "";
    char ch;

    if (!in) {
        cout << "could not open input file\n";
        return "";
    }

    while (in.get(ch)) {
        text += ch;
    }

    in.close();
    return text;
}

bool writeFile(string filename, string text) {
    ofstream out(filename.c_str());
    if (!out) {
        cout << "could not open output file\n";
        return false;
    }
    out << text;
    out.close();
    return true;
}

void buildTables(int length, char encodeTable[26], char decodeTable[26]) {
    int offset = length % 25 + 1;
    int spacing = (length % 6) * 2 + 1;

    for (int i = 0; i < 26; i++) {
        int codeNum = offset + spacing * i;
        codeNum = codeNum % 26;
        encodeTable[i] = char('a' + codeNum);
    }

    for (int i = 0; i < 26; i++) {
        char encoded = encodeTable[i];
        int index = encoded - 'a';
        decodeTable[index] = char('a' + i);
    }
}

string applyTable(string text, char table[26]) {
    string result = text;

    for (int i = 0; i < result.length(); i++) {
        char ch = tolower(result[i]);

        if (ch >= 'a' && ch <= 'z') {
            int index = ch - 'a';
            result[i] = table[index];
        }
        else {
            result[i] = ch;
        }
    }

    return result;
}

int main() {
    char choice;
    cout << "encode or decode? (e/d): ";
    cin >> choice;

    string inputFile, outputFile;

    if (choice == 'e') {
        inputFile = "message.txt";
        outputFile = "encoded_message.txt";
    }
    else if (choice == 'd') {
        int which;
        cout << "decode 1 or 2: ";
        cin >> which;

        if (which == 1) {
            inputFile = "codedmessage1.txt";
            outputFile = "decoded1.txt";
        }
        else {
            inputFile = "codedmessage2.txt";
            outputFile = "decoded2.txt";
        }
    }
    else {
        cout << "invalid choice\n";
        return 0;
    }

    string text = readFile(inputFile);
    if (text == "") return 0;

    int length = text.length();

    char encodeTable[26];
    char decodeTable[26];

    buildTables(length, encodeTable, decodeTable);

    string result;

    if (choice == 'e')
        result = applyTable(text, encodeTable);
    else
        result = applyTable(text, decodeTable);

    writeFile(outputFile, result);

    cout << "done\n";
    return 0;
}
