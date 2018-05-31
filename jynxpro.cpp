/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include <jynxpro.hpp>

using namespace eosio;
using std::string;

namespace eosio {

    class jynxpro : public contract {
        private:
            struct deposit {
                uint64_t        id;
                asset           symbol;
                account_name    owner;
                long            submitted;
                long            confirmed;
                auto            primary_key() { return id; }
                EOSLIB_SERIALIZE(deposit, (id)(symbol)(owner)(submitted)(confirmed))
            };

            struct withdrawal {
                uint64_t        id;
                asset           symbol;
                account_name    owner;
                long            submitted;
                long            approved;
                long            confirmed;
                auto            primary_key() { return id; }
                EOSLIB_SERIALIZE(withdrawal, (id)(symbol)(owner)(submitted)(approved)(confirmed))
            };

            struct collateral {
                uint64_t        id;
                account_name    owner;
                uint64_t        amount;
                auto            primary_key() { return id; }
                EOSLIB_SERIALIZE(collateral, (id)(owner)(amount))
            };

            struct market {
                uint64_t        id;
                asset           symbol;
                bool            suspended;
                auto            primary_key() { return id; }
                EOSLIB_SERIALIZE(market, (id)(symbol)(suspended))
            };

            struct trade {
                uint64_t        id;
                uint64_t        order_id;
                uint64_t        quantity;
                uint64_t        price;
                long            datetime;
                account_name    owner;
                auto            primary_key() { return id; }
                EOSLIB_SERIALIZE(trade, (id)(order_id)(quantity)(price)(datetime)(owner))
            };

            struct order {
                uint64_t        id;
                asset           symbol;
                uint64_t        price;
                bool            buy;
                uint64_t        filled;
                long            expires;
                long            submitted;
                long            fulfilled;
                account_name    owner;
                auto            primary_key() { return id; }
                asset           get_symbol() { return symbol; }
                bool            get_buy() { return buy; }
                EOSLIB_SERIALIZE(order, (id)(symbol)(price)(buy)(filled)(expires)(submitted)(fulfilled)(owner))
            };

            typedef multi_index<N(order), order> orders;
            typedef multi_index<N(trade), trade> trades;
            typedef multi_index<N(market), market> markets;
            typedef multi_index<N(collateral), collateral> all_collateral;
            typedef multi_index<N(withdrawl), withdrawal> withdrawls;
            typedef multi_index<N(deposit), deposit> deposits;

        public:
            using contract::contract;

            void limitorder(asset symbol, uint64_t price, bool buy) {}
            void marketorder(asset symbol, bool buy) {}
            void cancelorder(uint64_t id) {}
            void deposit() {}
            void withdraw() {}

            // NOTE - every time there's a trade we need to recalculate the margin on all open positions
            // Cont: we might have to do some indexing here to prevent performance hits when opening trades
    };
}

EOSIO_ABI(jynxpro, (limitorder)(cancelorder)(marketorder)(deposit)(withdraw))