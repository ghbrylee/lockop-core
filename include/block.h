//
//  block.h
//  lockop-core
//
//  Created by 0xbrylee on 2019-02-02.
//  Copyright (c) 2019 brylabs. All rights reserved.
//
#pragma once
#include <string>
#include <unistd.h> // usleep
#include <sstream> // stringstream
#include <vector>

static const unsigned int BLOCK_VERSION = 10000;
static const unsigned int MAX_BLOCK_SIZE = 1000000;
static const unsigned int BLCOK_CREATION_TIMESPAN = 1000000;

namespace lockop{
    void addBlock();

    class CBlockManager{
        public:
            CBlockManager();
            void blockAgeCalculator();
            std::string buildBlockHash();

        private:
            uint8_t mLatestBlockAge;
            std::stringstream mResultHash;
    };

    class CBlockStorage{
        public:
            CBlockStorage();
            uint32_t getLatestHeight();
            uint8_t getVersion(int nIndex);
            std::string& getHashPrevBlock(int nIndex);
            std::string& getHashMerkleRoot(int nIndex);
            uint32_t getTime(int nIndex);
            std::string& getData(int nIndex);

            void setLatestHeight();
            void setVersion();
            void setHashPrevBlock(std::string& hashPrevBlock);
            void setHashMerkleRoot(std::string& hashMerkleRoot);
            void setTime(uint32_t time);
            void setData(std::string& data);

        private:
            std::vector<uint32_t> mLatestHeight;
            std::vector<uint8_t> mVersion;
            std::vector<std::string> mHashPrevBlock;
            std::vector<std::string> mHashMerkleRoot;
            std::vector<uint32_t> mTime;
            std::vector<std::string> mData;
    };
    
}