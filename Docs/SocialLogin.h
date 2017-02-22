//
//  SocialLogin.h
//  SocialLogin
//
//  Created by aadil on 19/08/15.
//  Copyright (c) 2015 zaptechsolutions. All rights reserved.
//
// Library used :
// Twitter : https://github.com/nst/STTwitter
// Facebook : https://developers.facebook.com/docs/ios/
// Google + : https://developers.google.com/+/mobile/ios/getting-started
// Instagram : https://github.com/shyambhat/InstagramKit

// ***************************** For Facebook ***************************** //

// In App Delegate add Code to openURL Method :
//
//
//- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
//    return [[FBSDKApplicationDelegate sharedInstance] application:application
//                                                          openURL:url
//                                                sourceApplication:sourceApplication
//                                                       annotation:annotation];
//}
//
// In App Delegate add code to Application DidBecome Active
//
//- (void)applicationDidBecomeActive:(UIApplication *)application {
//    // Activates Facebook App
//    [FBSDKAppEvents activateApp];
//    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
//}
//
//
// In App Delegate return application didFinishLaunchingWithOptions
//
// - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
//  return [[FBSDKApplicationDelegate sharedInstance] application:application
// didFinishLaunchingWithOptions:launchOptions];
// }
//
// In Info.plist ADD -----(URL Types -> ITEM 0 -> URL Schemes =-> ITEM0 = fb<APPID>)
//               ADD -----FacebookAppID = <APPID>
//


#import <Foundation/Foundation.h>
#import <FBSDKCoreKit/FBSDKCoreKit.h>
#import <FBSDKLoginKit/FBSDKLoginKit.h>
#import <MBProgressHUD.h>
@interface SocialLogin : NSObject
@property (nonatomic,strong) NSMutableString *FBAppId;
@property (nonatomic,strong) NSMutableString *FBSecretKey;
@property (nonatomic,strong) NSMutableString *GoogleId;
@property (nonatomic,strong) NSMutableString *GoogleSecretKey;
@property (nonatomic,strong) NSMutableString *TwitterId;
@property (nonatomic,strong) NSMutableString *TwitterSecretKey;
@property (nonatomic,strong) NSMutableString *InstagramId;
@property (nonatomic,strong) NSMutableString *InstagramSecretKey;

-(void)loginWithFacebook;
-(void)getFacebookDetails;
-(void)loginWithGoogle;
-(void)loginWithTwitter;
-(void)loginWithInstagram;
@end
