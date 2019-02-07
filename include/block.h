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
    const std::string genesisBlock = "ABCDEFG";

    class CBlockHeader{
        public:
            CBlockHeader();
            int getBlockNum() const;
            void setGenesisBlock() const;

        private:
            int mBlockNum;
            std::string mHash;
            std::string mPreviousHash;
            int mTimestamp;
            
            
    };

}