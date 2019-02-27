//
//  util.cpp
//  lockop-core
//
//  Created by 0xbrylee on 2019-02-27.
//  Copyright (c) 2019 brylabs. All rights reserved.
//
#pragma once
#include <string>

namespace lockop{
    class CLogManager{
        public:
            CLogManager();
            void printLog(const std::string& type, const std::string& message);
            void printBlock(const std::string& type, uint8_t version,
                            uint64_t height, uint64_t hashPrevBlock,
                            uint64_t hashMerkleRoot, uint32_t time
                            );
            void printBlockAge(const std::string& type, uint8_t latestBlockAge);
        private:
            std::string mType;
            std::string mMessage;

    };

}