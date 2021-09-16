SRC_DIR = src
SOURCES =   $(SRC_DIR)/test.cpp                 \
            $(SRC_DIR)/encryptedMessage.cpp     \
            ../cryptopals1_2/src/XOR.cpp        \
            ../cryptopals1_1/src/hex2base64.cpp 

INCLUDES =  -I includes/                    \
            -I ../cryptopals1_2/includes/   \
            -I ../cryptopals1_1/includes/
