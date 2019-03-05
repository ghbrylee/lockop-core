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

static const unsigned int BLOCK_VERSION = 10000;
static const unsigned int MAX_BLOCK_SIZE = 1000000;
static const unsigned int BLCOK_CREATION_TIMESPAN = 1000000;

namespace lockop{
    void addBlock();
    
    class CBlockManager{
        public:
            CBlockManager();
            void blockAgeCalculator();
            void buildNewBlock();
            uint64_t buildMerkleTree() const;
            uint64_t getMerkleBranch() const;
            uint64_t checkMerkleBranch() const;

        private:
            uint8_t mLatestBlockAge;
            unsigned int mBlockCreationTimespan;
            std::vector<std::string> blockchain;
    };

    class CBlockStorage{
        public:
            void initest();
            CBlockStorage();
            uint32_t getLatestHeight();
            uint8_t getVersion(int index);
            std::string& getHashPrevBlock(int index);
            std::string& getHashMerkleRoot(int index);
            uint32_t getTime(int index);
            std::string& getData(int index);

            void setLatestHeight();
            void setVersion();
            void setHashPrevBlock(std::string& hashPrevBlock);
            void setHashMerkleRoot(std::string& hashMerkleRoot);
            void setTime(uint32_t time);
            void setData(std::string& data);

        private:
            static const std::vector<uint32_t> mLatestHeight;
            std::vector<uint8_t> mVersion;
            std::vector<std::string> mHashPrevBlock;
            std::vector<std::string> mHashMerkleRoot;
            std::vector<uint32_t> mTime;
            std::vector<std::string> mData;
    };

    /*
    class CBlockHeader{
        public:
            CBlockHeader();
            uint64_t getLatestHeight();
            uint8_t getVersion();
            std::string& getHashPrevBlock();
            std::string& getHashMerkleRoot();
            uint32_t getTime();
            std::string mData();

        private:
            const uint8_t mVersion;
            std::string mHashPrevBlock;
            std::string mHashMerkleRoot;
            uint32_t mTime;
            std::string mData;
    };
    */
}