//
//  block.h
//  lockop-core
//
//  Created by 0xbrylee on 2019-02-02.
//  Copyright (c) 2019 brylabs. All rights reserved.
//

#pragma once
#include <string>

namespace lockop{
    const std::string genesisBlock = "ABCDEFSKSKSDKDSKLSDKLG";

    class CBlockHeader{
        public:
            CBlockHeader();
            int getBlockNum() const;
            void setGenesisBlock() const;
            int64_t getPreviousHash() const;
            std::string& getBlockData();

        private:
            int mBlockNum;
            int64_t mHash;
            int64_t mPreviousHash;
            int mTimestamp;
            std::string mBlockData;
    };

    class CBlockGenerate{
        public:
            void genesisBlockCheck() const;
            void blockGenerator() const;

        private:
    };

}