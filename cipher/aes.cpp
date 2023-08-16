#include <iostream>
#include <openssl/aes.h>

int aes_encrypt(std::string &key, std::string iv, std::string &in, std::string &out) {
    AES_KEY aesKey;
    int r = AES_set_encrypt_key((const unsigned char *) key.c_str(), 256, &aesKey);
    if (r) {
        return r;
    }
    char padding = AES_BLOCK_SIZE - in.size() % AES_BLOCK_SIZE;
    in.append(padding, padding);

    auto out_buff = new unsigned char[in.size()];
    AES_cbc_encrypt((const unsigned char *) in.c_str(),
                    out_buff,
                    in.size(),
                    &aesKey,
                    (unsigned char *) iv.c_str(),
                    AES_ENCRYPT);
    out = std::string((char *) out_buff, in.size());
    return 0;
}

int aes_decrypt(std::string &key, std::string iv, std::string &in, std::string &out) {
    AES_KEY aesKey;
    int r = AES_set_decrypt_key((const unsigned char *) key.c_str(), 256, &aesKey);
    if (r) {
        return r;
    }
    auto out_buff = new unsigned char[in.size()];
    AES_cbc_encrypt((const unsigned char *) in.c_str(),
                    out_buff,
                    in.size(),
                    &aesKey,
                    (unsigned char *) iv.c_str(),
                    AES_DECRYPT);
    unsigned char padding = out_buff[in.size() - 1];
    std::cout << "in.size: " << in.size() << std::endl;
    std::cout << "padding: " << (unsigned int) padding << std::endl;
    out = std::string((char *) out_buff, in.size() - padding);

    return 0;
}
