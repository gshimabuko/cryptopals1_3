#ifndef __HEX2BASE64__
#define __HEX2BASE64__

#include <vector>

std::vector<unsigned char> bin2hex(std::vector<unsigned char> binString);
std::vector<unsigned char> hex2bin(std::vector<unsigned char> hexString);
std::vector<unsigned char> bin2base64(std::vector<unsigned char> binString);
#endif /* __HEX2BASE64__ */
