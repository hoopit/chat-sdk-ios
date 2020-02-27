//
//  BFriendsListViewController.h
//  NekNominate
//
//  Created by Benjamin Smiley-andrews on 28/01/2014.
//  Copyright (c) 2014 deluge. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MBProgressHUD/MBProgressHUD.h>
#import <VENTokenField/VENTokenField.h>
#import <ChatSDK/PThread_.h>
#import <ChatSDK/PFriendsListViewController.h>

@class BSearchIndexViewController;
@class MBProgressHUD;
@protocol  PThread;
@protocol PUser;
@class BHook;

@protocol BFriendsListDataSource <NSObject>

-(NSArray *) contacts;

@end

@interface BFriendsListViewController : UIViewController<UITableViewDataSource, UITableViewDelegate, VENTokenFieldDelegate, VENTokenFieldDataSource, UITextFieldDelegate, PFriendsListViewController, UISearchBarDelegate> {
    NSMutableArray * _contacts;
    NSMutableArray * _searchedContacts;
    NSMutableArray * _selectedContacts;
    NSMutableArray * _contactsToExclude;
    
    NSString * _filterByName;
    BOOL* _isSearching;
    BHook * _internetConnectionHook;
}

@property (weak, nonatomic) IBOutlet UITableView *tableView;
@property (nonatomic, readwrite, copy) void (^usersToInvite)(NSArray * users, NSString * groupName);
@property (nonatomic, readwrite) NSString * rightBarButtonActionTitle;

@property (nonatomic, readwrite) NSArray * (^overrideContacts)(void);

@property (strong, nonatomic) NSMutableArray * names;
@property (nonatomic, readwrite) int maximumSelectedUsers;

-(instancetype) initWithUsersToExclude: (NSArray *) users onComplete: (void(^)(NSArray * users, NSString * name)) action;

-(void) setUsersToExclude: (NSArray *) users;
-(void) setSelectedUsers: (NSArray *) users;

@end
