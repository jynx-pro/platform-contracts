/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include <exchange.hpp>

using namespace eosio;

class exchange : public eosio::contract {
    public:
        using contract::contract;

        void hi(account_name user) {
            print("Hello, ", name{user});
        }
};

EOSIO_ABI(exchange, (hi))