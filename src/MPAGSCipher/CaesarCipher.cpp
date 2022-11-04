#include "CaesarCipher.hpp"
#include "CipherMode.hpp"
#include <string>
#include <iostream>

CaesarCipher::CaesarCipher(const std::size_t key)
    : key_{key} 
{
    // some stuff goes here
}

CaesarCipher::CaesarCipher(const std::string key) : key_{0} {
    for (const auto& elem : key) {
        if (!std::isdigit(elem)) {
            return;
        }
    }
    key_ = std::stoul(key);
}

std::string CaesarCipher::applyCipher(const CipherMode mode, const std::string& inputText) {
    // Create the output string
    std::string outputText;

    // Define size of the alphabet
    const std::size_t alphabetSize{alphabet_.size()};

    // Make sure that the key is in the range 0 - 25
    const std::size_t truncatedKey{key_ % alphabetSize};

    // Loop over the input text
    char processedChar{'x'};
    for (const auto& origChar : inputText) {
        for (size_t i{0}; i < alphabetSize; ++i) {
            if (origChar == alphabet_[i]) {
                // Apply the appropriate shift (depending on whether we're encrypting
                // or decrypting) and determine the new character
                // Can then break out of the loop over the alphabet
                if (mode == CipherMode::encrypt) {
                    processedChar = alphabet_[(i + truncatedKey) % alphabetSize];
                } else {
                    processedChar = alphabet_[(i + alphabetSize - truncatedKey) %
                                             alphabetSize];
                }
                break;
            }
        }
        // Add the new character to the output text
        outputText += processedChar;
    }
    return outputText;
}