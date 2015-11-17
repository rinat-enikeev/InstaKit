//
//  REViewController.m
//  InstaKit
//
//  Created by Rinat Enikeev on 11/17/2015.
//  Copyright (c) 2015 Rinat Enikeev. All rights reserved.
//

#import "REViewController.h"
#import <InstaKit/InstaKit.h>

@interface REViewController ()

@end

@implementation REViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    InstaKit* kit = [[InstaKit alloc] initWithClientId:@"24fc1af302d3442c86e5e3c1e8708015" dbFileName:@"dbFile"];
    [[kit postService] renewMediaPopularWithProgress:nil success:^(NSArray *objects) {
        NSLog(@"%@", objects);
        for (REInstaPost *post in objects) {
            NSLog(@"%@", post.imageStd.url);
        }
    } failure:^(NSError *error) {
        NSLog(@"%@", error.localizedDescription);
    }];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
