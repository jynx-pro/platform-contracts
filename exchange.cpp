/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include <exchange.hpp>

using namespace eosio;
using std::string;

class exchange : public eosio::contract {
    public:
        using contract::contract;

        void hi(account_name user) {
            print("Hello, ", name{user});
        }
        
    private:
        struct order {
            account_name    owner;
            asset           quantity;
            uint64_t        filled;
        };
};

EOSIO_ABI(exchange, (hi))