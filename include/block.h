//
//  block.h
//  lockop-core
//
//  Created by 0xbrylee on 2019-02-02.
//  Copyright (c) 2019 brylabs. All rights reserved.
//
#pragma once
#include <string>
#include <unistd.h>
#include <thread>
#include <ctime>
#include <random>

static const unsigned int MAX_BLOCK_SIZE = 1000000;
static const unsigned int BLCOK_CREATION_TIMESPAN = 3000000;

namespace lockop{
    void generateBlock();
    void checkerBlock();
    class CBlockManager{
        public:
            CBlockManager();
            void blockAgeCalculator();
            uint64_t getHash() const;
            uint64_t buildMerkleTree() const;
            uint64_t getMerkleBranch() const;
            uint64_t checkMerkleBranch() const;
        private:
            uint8_t mLatestBlockAge;
            unsigned int mBlockCreationTimespan;
    };

    class CBlockHeader{
        public:
            CBlockHeader();
            void setHeight();
            uint8_t getVersion();
            uint64_t getHeight();
            uint64_t getHashPrevBlock();
            uint64_t getHashMerkleRoot();
            uint32_t getTime();

        private:
            const uint8_t mVersion;
            uint64_t mHeight;
            uint64_t mHashPrevBlock;
            uint64_t mHashMerkleRoot;
            uint32_t mTime;
            std::string mData;
    };
}