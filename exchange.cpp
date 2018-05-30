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
            struct collateral {
                // TODO - this will store collateral for each public key
            }

            struct market {
                // TODO - this will be a list of supported futures markets
            }

            struct trade {
                uint64_t        id;
                uint64_t        order_id;
                uint64_t        quantity;
                double          price;
                long            datetime;
                account_name    owner;
                EOSLIB_SERIALIZE(trade, (id)(order_id)(quantity)(price)(datetime)(owner))
            }

            struct order {
                uint64_t        id;
                asset           symbol;
                double          price;
                bool            buy;
                uint64_t        filled;
                long            expires;
                long            submitted;
                long            fulfilled;
                account_name    owner;
                EOSLIB_SERIALIZE(order, (id)(symbol)(price)(buy)(filled)(expires)(submitted)(fulfilled)(owner))
            };

        public:
            using contract::contract;

            void limitorder(asset a, double price, bool buy) {}
            void marketorder(asset a, bool buy) {}
            void cancelorder(const uint64_t id) {}
            void depositcollateral() {}
            void withdrawcollateral() {}

            // NOTE - every time there's a trade we need to recalculate the margin on all open positions
            // Cont: we might have to do some indexing here to prevent performance hits when opening trades
    };
}

EOSIO_ABI(exchange, (limitorder)(cancelorder)(marketorder)(depositmargin)(withdrawmargin))