//
//  ViewController.m
//  UpLoadVideo
//
//  Created by Superman on 2018/6/28.
//  Copyright © 2018年 Superman. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    UILabel  *titLabel=[[UILabel alloc]init];
    titLabel.frame=CGRectMake(10, 50, 260,23 );
    titLabel.font=[UIFont systemFontOfSize:17];
    titLabel.text=@"视频缩略图";
    [self.view addSubview:titLabel];
    
    
    
}



- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end



























