// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from bitcoin_like_wallet.djinni

#import "RCTCoreLGBitcoinLikeOperation.h"


@implementation RCTCoreLGBitcoinLikeOperation
//Export module
RCT_EXPORT_MODULE(RCTCoreLGBitcoinLikeOperation)

-(instancetype)init
{
    self = [super init];
    //Init Objc implementation
    if(self)
    {
        self.objcImpl = [[LGBitcoinLikeOperation alloc] init];
    }
    return self;
}

/**
 *Get operation's transaction
 *@return BitcoinLikeTransaction object
 */
RCT_REMAP_METHOD(getTransaction,getTransactionWithResolver:(RCTPromiseResolveBlock)resolve rejecter:(RCTPromiseRejectBlock)reject) {

    id result = @{@"result" :[self.objcImpl getTransaction]};
    if(result)
    {
        resolve(result);
    }
    else
    {
        reject(@"impl_call_error", @"Error while calling LGBitcoinLikeOperation::getTransaction", nil);
    }
}
@end