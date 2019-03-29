//
//  main.cpp
//  lockop-core
//
//  Created by 0xbrylee on 2019-02-01.
//  Copyright (c) 2019 brylabs. All rights reserved.
//
#include <iostream>
#include "main.h"
#include "util.h"
#include "block.h"
#include "address.h"

using namespace std;
using namespace lockop;

namespace lockop{
    CMainParams::CMainParams()
        : mNetworkPassphrase(18446744073709551615)
        , mStrNetworkID("main")
        , mStartMessage(256)
        , mDefaultPort(25250)
        , mNode("172.0.0.1")
    {
    }

    std::string& CMainParams::getNode(){
        return mNode;
    }

    uint8_t CMainParams::getStartMessage(int arrNum){
        return mStartMessage;
    }
}

void test(){
    for (int i=0; i<1000000; i++){
        std:;cout << "[DEBUG] Generating block.....  #Block age count : " << i << "\n";
        usleep(100000);
    }
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

int EncodeBase58(const string input, int len, unsigned char result[]) {
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


int main(void){
    lockop::CLogManager log;
    log.printText("DEBUG", "Lockop-core world");
    
    lockop::CAddressManager address;
    std::string privKeyRaw;
    privKeyRaw = address.generateAddress();
    
    cout << "[DEBUG] " << "address generator : " << privKeyRaw << endl;
    
    int len = privKeyRaw.length();
    unsigned char x[0]; // = something
    unsigned char encoded[(len) * 137 / 100];
    EncodeBase58(privKeyRaw, len, encoded);
    
    std:cout << "[DEBUG] BASE58 encoded : " << encoded << std::endl;

    /*
        //std::thread t1(addBlock);
        //t1.join();
        std::thread t2(checkerBlock);
        std::thread t3(test);
        t2.join();
        t3.join();
    */
}