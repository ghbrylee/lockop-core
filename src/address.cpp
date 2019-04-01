//
//  address.cpp
//  lockop-core
//
//  Created by 0xbrylee on 2019-02-02.
//  Copyright (c) 2019 brylabs. All rights reserved.
//
#include <iostream>
#include "address.h"
#include "util.h"

using namespace std;
namespace lockop{
    CAddressManager::CAddressManager()
    {
    }

    const char * const ALPHABET =
        "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";
    
    const char ALPHABET_MAP[128] = {
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1,  0,  1,  2,  3,  4,  5,  6,  7,  8, -1, -1, -1, -1, -1, -1,
        -1,  9, 10, 11, 12, 13, 14, 15, 16, -1, 17, 18, 19, 20, 21, -1,
        22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, -1, -1, -1, -1, -1,
        -1, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, -1, 44, 45, 46,
        47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, -1, -1, -1, -1, -1
    };

    // result must be declared: char result[len * 137 / 100];
    int CAddressManager::EncodeBase58(const std::string input, uint16_t len,
                                     unsigned char result[]) {
        unsigned char const* bytes = (unsigned const char*)(input.c_str());
        unsigned char digits[len * 137 / 100];
        int digitslen = 1;
        for (int i = 0; i < len; i++) {
            unsigned int carry = (unsigned int) bytes[i];
            for (int j = 0; j < digitslen; j++) {
                carry += (unsigned int) (digits[j]) << 8;
                digits[j] = (unsigned char) (carry % 58);
                carry /= 58;
            }
            while (carry > 0) {
                digits[digitslen++] = (unsigned char) (carry % 58);
                carry /= 58;
            }
        }
        int resultlen = 0;
        // leading zero bytes
        for (; resultlen < len && bytes[resultlen] == 0;)
            result[resultlen++] = '1';
        // reverse
        for (int i = 0; i < digitslen; i++)
            result[resultlen + i] = ALPHABET[digits[digitslen - 1 - i]];
        result[digitslen + resultlen] = 0;
        return digitslen + resultlen;
    }

    std::string CAddressManager::getUniqueSeed(){
        CTimeManager time;
        CUtilManager util;
        uint32_t uniqueTime = time.getCurrentTimestamp();
        std::string uniqueTimeStr = std::to_string(uniqueTime);
        std::string uniqueSeed = uniqueTimeStr.append(util.getUniqueNum(10));
        std::cout << "[DEBUG] SEED : " << uniqueSeed << std::endl;

        return uniqueSeed;
    }

    std::string CAddressManager::generatePrivKey(){
        std::string uniqueSeed = this->getUniqueSeed();

        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, uniqueSeed.c_str(), uniqueSeed.size());
        SHA256_Final(hash, &sha256);
        
        std::stringstream res;
        res.str(""); // Initialization

        for(int i=0; i<17; i++){
            res << hex << setw(2) << setfill('0') << (int)hash[i];
        }

        this->mPrivKeyRaw = res.str();
        std::transform(this->mPrivKeyRaw.begin(), this->mPrivKeyRaw.end(), this->mPrivKeyRaw.begin(), ::toupper);

        return this->mPrivKeyRaw;
    }
    
    std::string CAddressManager::getAddress(std::string& sk){
        uint16_t len = sk.length();
        unsigned char x[0]; // = something
        unsigned char pk[(len) * 137 / 100];

        this->EncodeBase58(sk, len, pk);
        
        std::stringstream pkss; // unsigned char to 
        pkss << pk;
        std::string pkstr = pkss.str();
        
        return pkstr;
    }

}

// ** Below public and private key is example for test. Empty addresses.

// 78FE7E8850 B6598458BF BF7A74D5D1 5A8DE2BD (38)
//[DEBUG] Private key: EDB088AB4D2B667D20870C163A22200C (32bytes)
//[DEBUG] Public key : pcQ4oP2muEaihFVzdU3n2PUF1qqW7af8sFLeWuU9c8YSv (45bytes)
//[DEBUG] Private key: F905272F1CBDECC6FE02142B77DD3076D9 (34bytes)
//[DEBUG] Public key : GzYchUktHvms49khoS5sZWZkFau9QbJMKvtbyGhpHHPeLc6c (48bytes)
//[DEBUG] Private key: 2473D4D465F8BE722A8F1278F863954231
//[DEBUG] Public key : CCJhrdoDYVV4JzrFiWn6zfLGxrgPCYDeUcdGKaxQo6QMTFhz

//1MGMN7tqRC ZRiEX9kZ7n u6e1hMXbmV yqdD (34bytes)
//5K2FwRUtaS RqyG8FC7qS yi85vLW6My k2i57Y18Ff Ed3a1eJACy 5 (51bytes)

//1CWmbssvHe kt8ANuLdnr 9ZdBHe3NMv 5vXD (34bytes)
//5KKNGgCtje g5kTrnMEUw NKPNfwDYzg 39VXMJQY5R Li3VjMXYWs G (51bytes)

//1ECzy64N8UkucxQUGDbt2kczrunDSvJKRc
//5KRWVRXiUNgPr4DBRqiQ7iyjS2XGVDzUm6Mad8rrR6SjKgfEjXU

//GDKNTTVKGE E3P4FRLW6O KQRF5KTCC3 AQR6DDHKZE 4W5ZJRJTD6 B7HW2H (56bytes)
//SDWCGLXG5INK6CCS4BN24NWLVK37ANJBM6IUN6JQPOXQOUYJNTAQB3DN

//GCVFWJZZMPCHTSEVUNEROS5TD6H2473IVIX32G2ARZQ4XGCNHB6JKZBA
//SD2HTGC7PWMICJT2TZ5U2IOBTVXZ2EEFRJC3UBGSJVBQ26AESKXQCKNY

//GCD7XL DEIYZZ3LUI JMOAYMRN3C JZLW2MGLQR PMFNE35DBO NBBYKJAED5
//SBIXDTWMLISDA6Z6DX4CJQ2FWLKTWD4A4NATQTDEQ3QWIQXQCEH2BWNQ