//
//  merkleblock.h
//  lockop-core
//
//  Created by 0xbrylee on 2019-03-08.
//  Copyright (c) 2019 brylabs. All rights reserved.
//
#pragma once
#include <string>

namespace lockop{
    class CMerkleTreeManager{
        public:
            CMerkleTreeManager();
            uint64_t buildMerkleTree() const;
            uint64_t getMerkleBranch() const;
            uint64_t checkMerkleBranch() const;
        private:
            
            
    };

}