#include "pch.h"

Markov::Markov(string* rIn, string* rOut, size_t rC) : rulesCount(rC) {
    rulesIn = new string[rulesCount];
    rulesOut = new string[rulesCount];
    for (size_t i = 0; i < rulesCount; i++) {
        rulesIn[i] = rIn[i];
        rulesOut[i] = rOut[i];
    }
}

Markov::~Markov() {
    if (rulesIn != nullptr) {
        delete[] rulesIn;
    }
    if (rulesOut != nullptr) {
        delete[] rulesOut;
    }
}

string Markov::process(string s) {
    size_t pos;
    for (int i = 0; i < rulesCount; i++) {
        pos = s.find(rulesIn[i], 0);
        if (pos != string::npos) {
            if (rulesOut[i][0] == '.') {
                s.replace(pos, rulesIn[i].length(), rulesOut[i].substr(1));
                break;
            }
            s.replace(pos, rulesIn[i].length(), rulesOut[i]);
            i = -1;
        }
    }
    return s;
}

int main(int argc, char** argv) {
    
    string rulesIn1[] = { "1","|0","0" };
    string rulesOut1[] = { "0|", "0||", "" };

    string rulesIn2[] = { "|b","ab","b","*|","*","|c","ac","c" };
    string rulesOut2[] = { "ba|","ba","","b*","c","c","c|","." };

    string rulesIn3[] = { "washington", "I", "T", "C", "USA", "." };
    string rulesOut3[] = { "Washington", "is", "the", "capital", "United States of America", "" };

    Markov m1(rulesIn1, rulesOut1, 3);
    Markov m2(rulesIn2, rulesOut2, 8);
    Markov m3(rulesIn3, rulesOut3, 6);
    
    cout << "changed from 'washington I T C of T USA'\n";
    string inputString = "washington I T C of T USA.";
    string processedString = m3.process(inputString);
    cout << "Processed string: " << processedString << endl << endl;;

    cout << "converting 111 into the unary number system\n";
    inputString = "111";
    processedString = m1.process(inputString);
    cout << "Processed string: " << processedString << endl << endl;;

    cout << "multiplication of '||*|||' in the unary system\n ";
    inputString = "||*|||";
    processedString = m2.process(inputString);
    cout << "Processed string: " << processedString << endl << endl;;

    /*::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();*/

}