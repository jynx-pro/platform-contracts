/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include <exchange.hpp>

using namespace eosio;
using std::string;

namespace eosio {

    class exchange : public contract {
        private:
            struct order {
                asset       symbol;
                bool        buy;
                int64_t     filled;
                EOSLIB_SERIALIZE(order, (symbol)(buy)(filled))
            };

        public:
            using contract::contract;

            void limitorder(const order& o) {}
            void marketorder(const order& o) {}
            void cancelorder(const uint64_t id) {}
    };
}

EOSIO_ABI(exchange, (limitorder)(cancelorder)(marketorder))