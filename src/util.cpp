//
//  util.cpp
//  lockop-core
//
//  Created by 0xbrylee on 2019-02-27.
//  Copyright (c) 2019 brylabs. All rights reserved.
//
#include <iostream>
#include "util.h"

using namespace std;
namespace lockop{
    CLogManager::CLogManager()
    {
    }

    void CLogManager::printLog(const std::string& type, const std::string& message){
//        std::cout << Type << '\n' << std::endl;
//        std::cout << Message << '\n' << std::endl;
        this->mType = type;
        this->mMessage = message;
        std::cout << "[" << mType << "] " << mMessage << std::endl;
    }


    void CLogManager::printBlock(const std::string& type, uint8_t version,
                                uint64_t height, uint64_t hashPrevBlock,
                                uint64_t hashMerkleRoot, uint32_t time){ 
        this->mType = type;
        this->mMessage = "(" + std::to_string(version) + ","
                             + std::to_string(height) + ","
                             + std::to_string(hashPrevBlock) + ","
                             + std::to_string(hashMerkleRoot) + ","
                             + std::to_string(time)
                        + ")";
        std::cout << "[" << mType << "] " << mMessage << std::endl;
    }

    void CLogManager::printBlockAge(const std::string& type, uint8_t latestBlockAge){
        this->mType = type;
        this->mMessage = "Latest block age : ("
                             + std::to_string(latestBlockAge)
                        + ")";
        std::cout << "[" << mType << "] " << mMessage << std::endl;
    }

}