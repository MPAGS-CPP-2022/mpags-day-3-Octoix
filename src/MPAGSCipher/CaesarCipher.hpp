#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP
#include "CipherMode.hpp"
#include <string>
#include <vector>

class CaesarCipher {
    public:
        explicit CaesarCipher(const std::size_t key);
        explicit CaesarCipher(const std::string key);
        std::string applyCipher(const CipherMode mode, const std::string& inputText);
    private:
        std::size_t key_; 
        const std::vector<char> alphabet_ = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
};

#endif
