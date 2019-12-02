//
// Created by Brett Chaldecott on 2019-05-09.
//

#ifndef KETO_BLOCKSYNCMANAGER_HPP
#define KETO_BLOCKSYNCMANAGER_HPP

#include <memory>
#include <string>
#include <vector>

#include "BlockChain.pb.h"
#include "Protocol.pb.h"

#include "keto/asn1/HashHelper.hpp"

#include "keto/block_db/SignedBlockWrapperMessageProtoHelper.hpp"

namespace keto {
namespace block {


class BlockSyncManager;
typedef std::shared_ptr<BlockSyncManager> BlockSyncManagerPtr;

class BlockSyncManager {
public:
    enum Status {
        INIT,
        WAIT,
        ERROR,
        RETRY,
        COMPLETE
    };

    BlockSyncManager(bool enabled);
    BlockSyncManager(const BlockSyncManager& orig) = delete;
    virtual ~BlockSyncManager();

    static BlockSyncManagerPtr createInstance(bool enabled);
    static BlockSyncManagerPtr getInstance();
    static void finInstance();

    Status getStatus();
    std::time_t getStartTime();
    void sync();
    keto::proto::SignedBlockBatchMessage
    requestBlocks(const keto::proto::SignedBlockBatchRequest& signedBlockBatchRequest);
    keto::proto::MessageWrapperResponse
    processBlockSyncResponse(const keto::proto::SignedBlockBatchMessage& signedBlockBatchMessage);
    void
    processRequestBlockSyncRetry();
    void
    notifyPeers();
    bool
    isEnabled();

    void broadcastBlock(const keto::block_db::SignedBlockWrapperMessageProtoHelper& signedBlockWrapperProtoHelper);

private:
    std::mutex classMutex;
    bool enabled;
    Status status;
    std::time_t startTime;
    std::vector<keto::asn1::HashHelper> tangleHashes;


    bool isExpired();

};



}
}



#endif //KETO_BLOCKSYNCMANAGER_HPP
