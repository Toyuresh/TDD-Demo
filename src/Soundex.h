#ifndef Soundex_h
#define Soundex_h

#include <string>
#include <unordered_map>
#include <cctype>
#include "CharUtil.h"
#include "StringUtil.h"
// ...

class Soundex
{
public:
    std::string encoded(const std::string& word) const;

private:
    std::string lastDigit(const std::string& encoding)const;
    std::string upperFront(const std::string& string)const;
    char lower(char c)const;
    void encodedHead(std::string& encoding,const std::string& word)const;
    void encodedTail(std::string& encoding,const std::string& word)const;
    void encodedLetter(std::string& encoding,char letter,char lastLetter)const;
    bool isVowel(char letter)const;
    std::string head(const std::string& word) const;
    std::string tail(const std::string& word)const;
    std::string encodedDigits(const std::string& word) const;
    std::string encodedDigit(char letter) const;
    bool isComplete(const std::string& encoding)const;
    std::string zeroPad(const std::string& word) const;    
    static const size_t MaxCodeLength{4};
    const std::string NotADigit{"*"};
   
};

#endif