//
//  SocialLogin.m
//  SocialLogin
//
//  Created by aadil on 19/08/15.
//  Copyright (c) 2015 zaptechsolutions. All rights reserved.
//

#import "SocialLogin.h"
@implementation SocialLogin
-(instancetype)init
{
    self = [super init];
    if(self) {
        self.FBAppId=[[NSMutableString alloc]init];
        self.FBSecretKey=[[NSMutableString alloc]init];
        self.TwitterId=[[NSMutableString alloc]init];
        self.TwitterSecretKey=[[NSMutableString alloc]init];
        self.GoogleId=[[NSMutableString alloc]init];
        self.GoogleSecretKey=[[NSMutableString alloc]init];
        self.InstagramId=[[NSMutableString alloc]init];
        self.InstagramSecretKey=[[NSMutableString alloc]init];
    }
    return self;
}
-(void)getFacebookDetails
{
    if ([FBSDKAccessToken currentAccessToken]) {
        NSMutableDictionary* parameters = [NSMutableDictionary dictionary];
        [parameters setValue:@"id,name,email" forKey:@"fields"];
        [[[FBSDKGraphRequest alloc] initWithGraphPath:@"me" parameters:@{@"fields": @"id, name, link, first_name, last_name, picture.type(large), email, birthday, bio ,location ,friends ,hometown , friendlists"}]
         startWithCompletionHandler:^(FBSDKGraphRequestConnection *connection, id result, NSError *error) {
             if (!error) {
                 NSLog(@"%@",result);
                 
             }
             else{
                 

             }
         }];
        // User is logged in, do work such as go to next view controller.
    }
    else{

    }
}
-(void)loginWithFacebook
{

    FBSDKLoginManager *login = [[FBSDKLoginManager alloc] init];
    [login logInWithReadPermissions:@[@"email"] handler:^(FBSDKLoginManagerLoginResult *result, NSError *error) {
        if (error) {
            NSLog(@"%@",result);
            //There was error processing your request. Try again later.
            
            // Process error
        } else if (result.isCancelled) {

            //Facebook Registration process was canclled.
            
            // Handle cancellations
        } else {
            // If you ask for multiple permissions at once, you
            // should check if specific permissions missing
            if ([result.grantedPermissions containsObject:@"email"]) {

                // Do work
                [FBSDKProfile enableUpdatesOnAccessTokenChange:YES];
                [self getFacebookDetails];
            }
            else{

                //You have not granted the Email ID permission on Facebook. Please grant us permission to receive your email id
            }
        }
    }];
}
@end
