//
//  SCAssimilatedFrameMetadata_Private.h
//  StandardCyborgFusion
//
//  Created by Aaron Thompson on 12/20/18.
//  Copyright © 2018 Standard Cyborg. All rights reserved.
//

#import <StandardCyborgFusion/PBFAssimilatedFrameMetadata.hpp>
#import <StandardCyborgFusion/SCAssimilatedFrameMetadata.h>
#import <StandardCyborgFusion/EigenHelpers.hpp>

static SCAssimilatedFrameMetadata
SCAssimilatedFrameMetadataFromPBFAssimilatedFrameMetadata(PBFAssimilatedFrameMetadata pbfMetadata,
                                                          NSInteger consecutiveFailedFrameCount)
{
    static const float kPoorTrackingQualityThreshold = 0.1;
    // Novansa: raised from 8 (0.27 s at 30 fps) to 36 (1.2 s). ICP has no pose
    // prior, so brief lost-tracking streaks are routine while orbiting a foot's
    // smooth sole / thin side profile; 8 consecutive losses ended nearly every
    // scan seconds into the lateral pan once the client started honouring the
    // .failed contract (and 24 still cut orbits short on marginal-tracking
    // scans). 1.2 s tolerates pan blips but still ends the scan before a
    // long-lost re-lock can fuse badly mis-registered geometry (the velocity
    // sanity gate in PBFModel dilutes with time since the last merged frame).
    static const NSInteger kMaxConsecutiveFailedFrameCount = 36;
    
    SCAssimilatedFrameMetadata metadata;
    metadata.viewMatrix = toSimdFloat4x4(pbfMetadata.viewMatrix);

    metadata.projectionMatrix = toSimdFloat4x4(pbfMetadata.projectionMatrix);
    metadata.colorBuffer = NULL;
    metadata.depthBuffer = NULL;
    
    if (pbfMetadata.isMerged == false && consecutiveFailedFrameCount + 1 >= kMaxConsecutiveFailedFrameCount) {
        metadata.result = SCAssimilatedFrameResultFailed;
    } else if (pbfMetadata.isMerged == false) {
        metadata.result = SCAssimilatedFrameResultLostTracking;
    } else if (pbfMetadata.icpUnusedIterationFraction < kPoorTrackingQualityThreshold) {
        metadata.result = SCAssimilatedFrameResultPoorTracking;
    } else {
        metadata.result = SCAssimilatedFrameResultSucceeded;
    }
    
    return metadata;
}
