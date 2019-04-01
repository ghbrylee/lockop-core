//
//  address.h
//  lockop-core
//
//  Created by 0xbrylee on 2019-02-02.
//  Copyright (c) 2019 brylabs. All rights reserved.
//
#pragma once
#include <sstream> // stringstream
#include <string>

namespace lockop{
    class CAddressManager{
        public:
            int EncodeBase58(const std::string input, uint16_t len,
                             unsigned char result[]
                             );
            CAddressManager();
            std::string getUniqueSeed();
            std::string generatePrivKey();
            std::string getAddress(std::string& sk);
            
        private:
            std::string mPrivKeyRaw;
    };
}

/*
Bryans-Mac-mini:lockop-core brylee$ ./bin/lockop-cored
[DEBUG] Lockop-core world
[DEBUG] SEED : 15540920158557008524
[DEBUG] Private key: B85EF6364ECF260E348C059EF23825486A
[DEBUG] len : 34
[DEBUG] Encoded: Ac59fzDStr4E9A39hhapeZFzJ1aWaZfhEmEPp1vikhmLTFTe
[DEBUG] Public key : Ac59fzDStr4E9A39hhapeZFzJ1aWaZfhEmEPp1vikhmLTFTe
Bryans-Mac-mini:lockop-core brylee$ ./bin/lockop-cored
[DEBUG] Lockop-core world
[DEBUG] SEED : 15540920169155351881
[DEBUG] Private key: 5AACE8070C035EE746B8D96CAA6A589309
[DEBUG] len : 34
[DEBUG] Encoded: Abn9jknTSstnntXX6sM58S1xdj97Tx1DTGnfy7FK22NB2oma
[DEBUG] Public key : Abn9jknTSstnntXX6sM58S1xdj97Tx1DTGnfy7FK22NB2oma
Bryans-Mac-mini:lockop-core brylee$ ./bin/lockop-cored
[DEBUG] Lockop-core world
[DEBUG] SEED : 15540920172161545922
[DEBUG] Private key: D0DDE2C7763CFD4D1D8D397E9B68FC3404
[DEBUG] len : 34
[DEBUG] Encoded: Ac7jQiPUFuLuwh5Jtkx1EWkQJEVojuYKmk1FKhoEd2LCwEzw
[DEBUG] Public key : Ac7jQiPUFuLuwh5Jtkx1EWkQJEVojuYKmk1FKhoEd2LCwEzw
Bryans-Mac-mini:lockop-core brylee$ ./bin/lockop-cored
[DEBUG] Lockop-core world
[DEBUG] SEED : 15540920514211514217
[DEBUG] Private key: 55823E404A0F8507C02704982A4B95E4BF
[DEBUG] len : 34
[DEBUG] Encoded: Abn6APbF3zuvrikY9FkTmuW45VVLJvWxkoyUz9eykSeTz6d3
[DEBUG] Public key : Abn6APbF3zuvrikY9FkTmuW45VVLJvWxkoyUz9eykSeTz6d3


*/
