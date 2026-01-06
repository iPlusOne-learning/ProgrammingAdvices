#include "headerFiles/clsString.h"

int main()
{
    clsString String1;
    clsString String2("Mohamed");

    String1.SetString("Hello how are you doing");
    cout << "String 1 = " << String1.GetString() << endl;
    cout << "String 2 = " << String2.GetString() << endl;
    cout << "Count number of words: " << String1.CountWords() << endl;
    cout << "Count number of words: " << clsString::CountWords("hey buddy") << endl;

    String1.PrintFirstLetterOfEachWord();
    clsString::PrintFirstLetterOfEachWord("i am who i am");

    cout << "First letter converted to uppercase: " <<String1.UpperFirstLetterOfEachWord() << endl;
    cout << "First letter converted to uppercase: " << clsString::UpperFirstLetterOfEachWord("i am who i am") << endl;

    cout << "First letter converted to lowercase: " <<String1.LowerFirstLetterOfEachWord() << endl;
    cout << "First letter converted to lowercase: " << clsString::LowerFirstLetterOfEachWord("IT IS NICE") << endl;

    //upper/lower all letters of a string
    cout << "convert  to uppercase: " <<String1.UpperAllString() << endl;
    cout << "converted to lowercase: " <<String1.LowerAllString() << endl;
    
    return 0;

}