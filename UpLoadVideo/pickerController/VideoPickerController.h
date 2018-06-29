//
//  VideoPickerController.h
//  UpLoadVideo
//
//  Created by Superman on 2018/6/28.
//  Copyright © 2018年 Superman. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AssetsLibrary/AssetsLibrary.h>

@protocol VideoPickerControllerDelegate;

@interface VideoPickerController : UINavigationController
@property (nonatomic, weak) id <UINavigationControllerDelegate, VideoPickerControllerDelegate> delegate;

@property (nonatomic, strong) ALAssetsFilter *assetsFilter;

@property (nonatomic, copy, readonly) NSArray *indexPathsForSelectedItems;

@property (nonatomic, assign) NSInteger maximumNumberOfSelection;
@property (nonatomic, assign) NSInteger minimumNumberOfSelection;

@property (nonatomic, strong) NSPredicate *selectionFilter;

@property (nonatomic, assign) BOOL showCancelButton;

@property (nonatomic, assign) BOOL showEmptyGroups;

@property (nonatomic, assign) BOOL isFinishDismissViewController;

@end
@protocol VideoPickerControllerDelegate <NSObject>

-(void)assetPickerController:(VideoPickerController *)picker didFinishPickingAssets:(NSArray *)assets;

@optional

-(void)assetPickerControllerDidCancel:(VideoPickerController *)picker;

-(void)assetPickerController:(VideoPickerController *)picker didSelectAsset:(ALAsset*)asset;

-(void)assetPickerController:(VideoPickerController *)picker didDeselectAsset:(ALAsset*)asset;

-(void)assetPickerControllerDidMaximum:(VideoPickerController *)picker;

-(void)assetPickerControllerDidMinimum:(VideoPickerController *)picker;

@end

@interface AssetViewController : UITableViewController

@property (nonatomic, strong) ALAssetsGroup *assetsGroup;
@property (nonatomic, strong) NSMutableArray *indexPathsForSelectedItems;

@end

#pragma mark - VideoTitleView

@interface VideoTitleView : UILabel

@end

#pragma mark - TapAssetView

@protocol TapAssetViewDelegate <NSObject>

-(void)touchSelect:(BOOL)select;
-(BOOL)shouldTap;

@end

@interface TapAssetView : UIView

@property (nonatomic, assign) BOOL selected;
@property (nonatomic, assign) BOOL disabled;
@property (nonatomic, weak) id<TapAssetViewDelegate> delegate;

@end

#pragma mark - AssetView

@protocol AssetViewDelegate <NSObject>

-(BOOL)shouldSelectAsset:(ALAsset*)asset;
-(void)tapSelectHandle:(BOOL)select asset:(ALAsset*)asset;

@end

@interface AssetView : UIView

- (void)bind:(ALAsset *)asset selectionFilter:(NSPredicate*)selectionFilter isSeleced:(BOOL)isSeleced;

@end

#pragma mark - AssetViewCell

@protocol AssetViewCellDelegate;

@interface AssetViewCell : UITableViewCell

@property(nonatomic,weak)id<AssetViewCellDelegate> delegate;

- (void)bind:(NSArray *)assets selectionFilter:(NSPredicate*)selectionFilter minimumInteritemSpacing:(float)minimumInteritemSpacing minimumLineSpacing:(float)minimumLineSpacing columns:(int)columns assetViewX:(float)assetViewX;

@end

@protocol AssetViewCellDelegate <NSObject>

- (BOOL)shouldSelectAsset:(ALAsset*)asset;
- (void)didSelectAsset:(ALAsset*)asset;
- (void)didDeselectAsset:(ALAsset*)asset;

@end

#pragma mark - AssetGroupViewCell

@interface AssetGroupViewCell : UITableViewCell

- (void)bind:(ALAssetsGroup *)assetsGroup;

@end

#pragma mark - AssetGroupViewController

@interface AssetGroupViewController : UITableViewController





//@end



@end
