//
//  block.h
//  lockop-core
//
//  Created by 0xbrylee on 2019-02-02.
//  Copyright (c) 2019 brylabs. All rights reserved.
//

#pragma once
#include <string>


static const unsigned int MAX_BLOCK_SIZE = 1000000;
namespace lockop{
    class CBlockHeader{
        public:
            CBlockHeader();
            uint8_t getBVersion;
            int getHegiht;
            uint64_t getHashPrevBlock;
            uint64_t getHashMerkleRoot;
            uint32_t getTime;

        private:
            const uint8_t mVersion;
            int mHeight;
            uint64_t mHashPrevBlock;
            uint64_t mHashMerkleRoot;
            uint32_t mTime;
            std::string mData;
    };

    class CBlockGenerate{
        public:
            void genesisBlockCheck() const;
            void blockGenerator() const;

        private:

    };
}