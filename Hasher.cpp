#ifndef HASHER_hpp
#define HASHER_HPP

#include"Hasher.hpp"

#endif

std::string Hasher::computeHash(const void* data, size_t size)
{
     unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hashLen = 0;

    // Create a new digest context.
    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    if (!ctx) {
        throw std::runtime_error("EVP_MD_CTX_new failed");
    }

    // Initialize the digest context with the SHA-256 algorithm.
    const EVP_MD* md = EVP_sha256();
    if (EVP_DigestInit_ex(ctx, md, nullptr) != 1) {
        EVP_MD_CTX_free(ctx);
        throw std::runtime_error("EVP_DigestInit_ex failed");
    }

    // Update the digest with the input data.
    if (EVP_DigestUpdate(ctx, data, size) != 1) {
        EVP_MD_CTX_free(ctx);
        throw std::runtime_error("EVP_DigestUpdate failed");
    }

    // Finalize the digest and retrieve the hash.
    if (EVP_DigestFinal_ex(ctx, hash, &hashLen) != 1) {
        EVP_MD_CTX_free(ctx);
        throw std::runtime_error("EVP_DigestFinal_ex failed");
    }

    // Clean up the digest context.
    EVP_MD_CTX_free(ctx);

    // Convert the hash to a hexadecimal string.
    std::string result;
    char buf[3] = {0};
    for (unsigned int i = 0; i < hashLen; ++i) {
        std::snprintf(buf, sizeof(buf), "%02x", hash[i]);
        result += buf;
    }
    return result;
}