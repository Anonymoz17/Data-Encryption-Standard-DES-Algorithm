#include <algorithm>
#include <bitset>
#include <cstdint>
#include <iostream>
#include <vector>

// this binary is hexadecimal -> 0123456789ABCDEF
uint64_t bits = 0b0000000100100011010001010110011110001001101010111100110111101111;

// initial permutation 64 bits fixed table
int IP[64] = {
    58, 50, 42, 34, 26, 18, 10,  2,
    60, 52, 44, 36, 28, 20, 12,  4,
    64, 56, 48, 40, 32, 24, 16,  8,
    57, 49, 41, 33, 25, 17,  9,  1,
    59, 51, 43, 35, 27, 19, 11,  3,
    61, 53, 45, 37, 29, 21, 13,  5,
    63, 55, 47, 39, 31, 23, 15,  7
};

std::vector<uint64_t> bitsToVector(uint64_t inputBits);
std::vector<uint64_t> initialPermutation(uint64_t inputBits);
std::vector<uint64_t> roundFunction(std::vector<uint64_t> inputBits, std::vector<uint64_t> roundKey);
std::vector<uint64_t> manglerFunction(std::vector<uint64_t> rightHalfBits);

std::vector<uint64_t> bitsToVector(uint64_t inputBits) {
    std::vector<uint64_t> result(64);

    for (int i = 0; i < 64; i++) {
        result[63-i] = (inputBits >> 1) & 1;
    }

    return result;
}

std::vector<uint64_t> initialPermutation(uint64_t inputBits) {
    //take in 64 bits.
    std::vector<uint64_t> bits = bitsToVector(inputBits);

    //rearrange the bits as structured in DES doc.
    std::vector<uint64_t> permuted;
    for (int i = 0; i < 64; i++) {
        permuted[i] = bits[IP[i] - 1];
    }

    //output 64 bits.
    return permuted;
}

// single round of the feistel network.
std::vector<uint64_t> roundFunction(std::vector<uint64_t> inputBits, std::vector<uint64_t> roundKey) {
    //split to left and right halves of 32 bits each.
    std::vector<uint64_t> left(inputBits.begin(), inputBits.begin() + 32);
    std::vector<uint64_t> right(inputBits.begin() + 32, inputBits.end());

    std::vector<uint64_t> manglerFunctionResult = manglerFunction(right);
}

std::vector<uint64_t> manglerFunction(std::vector<uint64_t> rightHalfBits) {

}


int main() {
    initialPermutation(bits);
}