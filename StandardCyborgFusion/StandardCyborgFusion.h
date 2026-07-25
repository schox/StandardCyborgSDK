//
//  StandardCyborgFusion.h
//  StandardCyborgFusion
//
//  Created by Aaron Thompson on 7/10/18.
//  Copyright © 2018 Standard Cyborg. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for StandardCyborgFusion.
FOUNDATION_EXPORT double StandardCyborgFusionVersionNumber;

//! Project version string for StandardCyborgFusion.
FOUNDATION_EXPORT const unsigned char StandardCyborgFusionVersionString[];

#import <StandardCyborgFusion/CVPixelBufferHelpers.h>
#import <StandardCyborgFusion/SCAssimilatedFrameMetadata.h>
#import <StandardCyborgFusion/SCFootTracking.h>
#import <StandardCyborgFusion/SCLandmark2D.h>
#import <StandardCyborgFusion/SCLandmark3D.h>
#import <StandardCyborgFusion/SCLandmarking2D.h>
#import <StandardCyborgFusion/SCMesh.h>
#import <StandardCyborgFusion/SCMesh+FileIO.h>
#import <StandardCyborgFusion/SCMesh+Geometry.h>
#import <StandardCyborgFusion/SCMesh+SceneKit.h>
#import <StandardCyborgFusion/SCMeshingOperation.h>
#import <StandardCyborgFusion/SCMeshTexturing.h>
#import <StandardCyborgFusion/SCPointCloud.h>
#import <StandardCyborgFusion/SCPointCloud+FileIO.h>
#import <StandardCyborgFusion/SCPointCloud+Geometry.h>
#import <StandardCyborgFusion/SCPointCloud+Metal.h>
#import <StandardCyborgFusion/SCPointCloud+SceneKit.h>
#import <StandardCyborgFusion/SCReconstructionManager.h>
#import <StandardCyborgFusion/SCReconstructionManagerParameters.h>
// Novansa: expose the ICP tuning surface (iterations/tolerance/downsample/outlier
// threshold) to the app — the setters exist and are needed to un-break the ignored
// maxThreadCount init parameter and to tune ICP robustness from the client.
#import <StandardCyborgFusion/SCReconstructionManagerParameters_Private.h>
#import <StandardCyborgFusion/SCReconstructionManager_Private.h>
#import <StandardCyborgFusion/SCScene.h>
