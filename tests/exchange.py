import os
import node
import sess
from eosf import *

def run():
    node.reset()
    sess.init()

    print()

    contract = Contract(os.path.abspath('') + "/dist")
    contract.deploy()

    contract.push_action("hi", '{"user":"fred"}')
    
    # c.push_action("issue", '{"to":"alice", "quantity":"100.0000 EOS", "memo":"memo"}', sess.eosio)

    # c.push_action("transfer", '{"from":"alice", "to":"carol", "quantity":"25.0000 EOS", "memo":"memo"}', sess.alice)
    
    # c.push_action("transfer", '{"from":"carol", "to":"bob", "quantity":"13.0000 EOS", "memo":"memo"}', sess.carol)
    
    # c.push_action("transfer", '{"from":"bob", "to":"alice", "quantity":"2.0000 EOS", "memo":"memo"}', sess.bob)

    # t1 = c.get_table("accounts", sess.alice)
    # t2 = c.get_table("accounts", sess.bob)
    # t3 = c.get_table("accounts", sess.carol)

    # assert t1.json["rows"][0]["balance"] == '77.0000 EOS'
    # assert t2.json["rows"][0]["balance"] == '11.0000 EOS'
    # assert t3.json["rows"][0]["balance"] == '12.0000 EOS'

    node.stop()
    print("Test OK")

run()