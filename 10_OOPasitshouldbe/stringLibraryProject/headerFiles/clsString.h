#ifndef CLSSTRING_H
#define CLSSTRING_H

#include <iostream>
#include <string>

using namespace std;

class clsString
{
    private:
        string _Value;
        string _Delimiter;
        vector<string> _vString;
        char _Letter;
        string _StringToReplace;
        string _sRepalceTo;
        static char InvertLetterCase(char char1)
        {
            return isupper(char1) ? tolower(char1) : toupper(char1);
        } 
    public:
    clsString()
    {
        _Value = "";
    }
    clsString(string Value)
    {
        _Value = Value;
    }
    void SetString(string Value)
    {
        _Value = Value;
    }
    string GetString()
    {
        return _Value;
    }
    //36-Count Each Word In String
    static short CountWords(string S1)
    {
        std::string Delimeter = " ";
        short Counter = 0;
        short pos = 0;
        string sWord;
        
        while ((pos = S1.find(Delimeter)) != std::string::npos)
        {
            sWord = S1.substr(0,pos);
            if (sWord != "")
                Counter++;
            S1.erase(0, pos + Delimeter.length());
        }
        if (S1 != " ")
            Counter++;
        return Counter;
    }
    short CountWords()
    {
        return CountWords(_Value);
    }

    static void PrintFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;
        cout << "First letters of this string: " << endl;

        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ' && isFirstLetter)
            {
                    cout << S1[i] << endl;
            }
            isFirstLetter = (S1[i] == ' ') ? true : false;
        }
    }
    void PrintFirstLetterOfEachWord()
    {
        return PrintFirstLetterOfEachWord(_Value);
    }
    static string UpperFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;

        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = toupper(S1[i]);
            }
            isFirstLetter = (S1[i] == ' ') ? true : false;
        }
        return S1;
    }
    string UpperFirstLetterOfEachWord()
    {
        return UpperFirstLetterOfEachWord(_Value);
    }

    static string LowerFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;
        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = tolower(S1[i]);
            }
            isFirstLetter = (S1[i] == ' ') ? true : false;
        }
        return S1;
    }
    string LowerFirstLetterOfEachWord()
    {
        return LowerFirstLetterOfEachWord(_Value);
    }
    //Upper/lower all letters of a string
    static string UpperAllString(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = toupper(S1[i]);
        }
        return S1;
    }
    static string LowerAllString(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
        S1[i] = tolower(S1[i]);
        }
        return S1;
    }
    string UpperAllString()
    {
        return UpperAllString(_Value);
    }
    string LowerAllString()
    {
        return LowerAllString(_Value);
    }
    //InvertAllLettersCase
    static string InvertAllStringLettersCase(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
        S1[i] = InvertLetterCase(S1[i]);
        }
        return S1;
    }
    string InvertAllStringLettersCase()
    {
        return InvertAllStringLettersCase(_Value);
    }
    //Count Letters
    static short CountLetter(string S1, char Letter, bool MatchCase = true)
    {
        short Counter = 0;
        for (short i = 0; i < S1.length(); i++)
        {
        if (MatchCase)
        {
        if (S1[i] == Letter)
        Counter++;
        }
        else
        {
        if (tolower(S1[i]) == tolower(Letter))
        Counter++;
        }
        }
        return Counter;
    }
    short CountLetter()
    {
        return CountLetter(_Value,_Letter,true);
    }
    //Is Vowel?
    static bool IsVowel(char Ch1)
    {
        Ch1 = tolower(Ch1);
        return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1
        == 'o') || (Ch1 == 'u'));
    }
    bool IsVowel()
    {
        return IsVowel(_Letter);
    }
    // 37- Split String
    static vector<string> SplitString(string S1, string Delimiter)
    {
        vector<string> vString;
        short pos = 0;
        string sWord;
        while ((pos = S1.find(Delimiter)) != std::string::npos)
        {
            sWord = S1.substr(0, pos);
            if (sWord != "")
            {
                vString.push_back(sWord);
            }
            S1.erase(0, pos + Delimiter.length());
        }
        if (S1 != "")
        {
           vString.push_back(S1); 
        }
        return vString;
    }
    vector<string> SplitString(string S1, string Delimiter)
    {
        return SplitString(_Value, Delimiter);
    }
    // 39- Join String
    static string JoinString(vector<string> vString, string Delimiter)
    {
        string S1="";
        for (string& s : vString)
        {
            S1 = S1 + s + Delimiter;
        }
        return S1.substr(0,S1.length()-Delimiter.length());
    }
    string JoinString()
    {
        return JoinString(_vString, _Delimiter);
    }
    // 40-Join String

    // 42- Replace Words
    static string ReplaceWordInStringUsingBuiltInFunction(string S1, string StringToReplace, string sRepalceTo)
    {
        short pos = S1.find(StringToReplace);
        while (pos != std::string::npos)
        {
            S1 = S1.replace(pos, StringToReplace.length(),
            sRepalceTo);
            pos = S1.find(StringToReplace);
        }
        return S1;
    }
    string ReplaceWordInStringUsingBuiltInFunction()
    {
        return ReplaceWordInStringUsingBuiltInFunction(_Value, _StringToReplace, _sRepalceTo);
    }
    //

    
    // __declspec(property(get = GetValue, put = SetValue)) string Value;
};

#endif