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
#include <vector>


static const unsigned int MAX_BLOCK_SIZE = 1000000;
static const unsigned int BLCOK_CREATION_TIMESPAN = 1000000;

namespace lockop{
    void addBlock();
    void checkerBlock();
    
    class CBlockManager{
        public:
            CBlockManager();
            void blockAgeCalculator();
            uint64_t getHash() const;
            uint64_t buildMerkleTree() const;
            uint64_t getMerkleBranch() const;
            uint64_t checkMerkleBranch() const;
            void addingVecBlock();
            void getVecBlock(int i);
            void clearVecBlock();
        private:
            uint8_t mLatestBlockAge;
            unsigned int mBlockCreationTimespan;
            std::vector<std::string> blockchain;
    };

    class CBlockHeader{
        public:
            CBlockHeader();
            void setHeight();
            uint8_t getVersion(); // 255
            uint64_t getHeight(); // 18446744073709551615
            uint64_t getHashPrevBlock(); // 1844674407,3709551615
            uint64_t getHashMerkleRoot();
            uint32_t getTime(); // 4294967295
                            //uint16_t 65535
        private:
            const uint8_t mVersion;
            uint64_t mHeight;
            uint64_t mHashPrevBlock;
            uint64_t mHashMerkleRoot;
            uint32_t mTime;
            std::string mData;
    };
}