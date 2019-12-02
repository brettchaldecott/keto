//
// Created by Brett Chaldecott on 2019/02/08.
//

#ifndef KETO_BLOCKCHAINCALLBACKIMPL_HPP
#define KETO_BLOCKCHAINCALLBACKIMPL_HPP

#include <string>
#include <vector>
#include <memory>

#include "keto/block_db/BlockChainCallback.hpp"

namespace keto {
namespace block {

class BlockChainCallbackImpl;
typedef std::shared_ptr<BlockChainCallbackImpl> BlockChainCallbackImplPtr;

class BlockChainCallbackImpl : virtual public keto::block_db::BlockChainCallback {
public:
    BlockChainCallbackImpl(bool ending = false);
    BlockChainCallbackImpl(const BlockChainCallbackImpl& orig) = delete;
    virtual ~BlockChainCallbackImpl();

    virtual void applyDirtyTransaction(const keto::asn1::HashHelper chainId, const TransactionWrapper_t& transactionWrapper) const;
    virtual void prePersistBlock(const keto::asn1::HashHelper chainId, const SignedBlock& signedBlock) const;
    virtual void prePersistTransaction(const keto::asn1::HashHelper chainId, const SignedBlock& signedBlock, const TransactionWrapper_t& transactionWrapper) const;
    virtual void postPersistTransaction(const keto::asn1::HashHelper chainId, const SignedBlock& signedBlock, const TransactionWrapper_t& transactionWrapper) const;
    virtual void postPersistBlock(const keto::asn1::HashHelper chainId, SignedBlock& signedBlock) const;


    virtual bool producerEnding() const;
private:
    bool ending;
};


}
}


#endif //KETO_BLOCKCHAINCALLBACKIMPL_HPP
