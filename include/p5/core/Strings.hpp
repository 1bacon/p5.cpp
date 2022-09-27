#pragma once

#include <string>
#include <vector>

namespace p5
{
    class Strings
    {
    public:
        static std::string binary(char value);
        static std::string binary(int value);
        static std::string binary(int value, int digits);
        static std::string hex(char value);
        static std::string hex(int value);
        static std::string hex(int value, int digits);
        static std::string trim(std::string str);
        static std::vector<std::string> trim(std::vector<std::string> array);
        static int unbinary(std::string value);
        static int unhex(std::string value);
        static std::string urlDecode(std::string str);
        static std::string urlEncode(std::string str);

        static std::string join(std::vector<std::string> list, char separator);
        static std::string join(std::vector<std::string> list, std::string separator);

        static std::vector<std::string> match(std::string str, std::string regexp);
        static std::vector<std::vector<std::string>> matchAll(std::string str, std::string regexp);

        static std::string nf(float num);
        static std::vector<std::string> nf(std::vector<float> nums);
        static std::vector<std::string> nf(std::vector<float> nums, int left, int right);
        static std::string nf(float num, int left, int right);
        static std::vector<std::string> nf(std::vector<int> nums, int digits);
        static std::string nf(int num, int digits);
        static std::vector<std::string> nfc(std::vector<float> nums, int right);
        static std::string nfc(float num, int right);
        static std::string nfc(int num);
        static std::vector<std::string> nfc(std::vector<int> nums);
        static std::vector<std::string> nfp(std::vector<float> nums, int left, int right);
        static std::string nfp(float num, int left, int right);
        static std::vector<std::string> nfp(std::vector<int> nums, int digits);
        static std::string nfp(int num, int digits);
        static std::vector<std::string> nfs(std::vector<float> nums, int left, int right);
        static std::string nfs(float num, int left, int right);
        static std::vector<std::string> nfs(std::vector<int> nums, int digits);
        static std::string nfs(int num, int digits);

        static std::vector<std::string> splitTokens(std::string value);
        static std::vector<std::string> splitTokens(std::string value, std::string delim);

        static std::string str(bool x);
        static std::vector<std::string> str(std::vector<bool> x);
        static std::string str(char x);
        static std::vector<std::string> str(std::vector<char> x);
        static std::string str(float x);
        static std::vector<std::string> str(std::vector<float> x);
        static std::string str(int x);
        static std::vector<std::string> str(std::vector<int> x);
    };
}
