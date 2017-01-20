#import "WMFArticle+CoreDataClass.h"

NS_ASSUME_NONNULL_BEGIN

@interface WMFArticle (CoreDataProperties)

+ (NSFetchRequest<WMFArticle *> *)fetchRequest;

@property (nonatomic) BOOL isExcludedFromFeed;
@property (nullable, nonatomic, copy) NSString *key;
@property (nullable, nonatomic, copy) NSDate *viewedDate;
@property (nullable, nonatomic, copy) NSDate *viewedDateWithoutTime;
@property (nullable, nonatomic, copy) NSString *viewedFragment;
@property (nonatomic) double viewedScrollPosition;
@property (nullable, nonatomic, copy) NSDate *newsNotificationDate;
@property (nullable, nonatomic, copy) NSDate *savedDate;
@property (nonatomic) BOOL wasSignificantlyViewed;
@property (nullable, nonatomic, copy) NSString *displayTitle;
@property (nullable, nonatomic, copy) NSString *wikidataDescription;
@property (nullable, nonatomic, copy) NSString *snippet;
@property (nullable, nonatomic, copy) NSString *thumbnailURLString;
@property (nullable, nonatomic, retain) NSDictionary *pageViews;
@property (nullable, nonatomic, retain) NSNumber *signedQuadKey;

@property (nonatomic) double latitude; //__deprecated; // Use coordinate instead (not using actual __deprecated tag due to inability to ignore the warning when these are used in Swift)
@property (nonatomic) double longitude; //__deprecated; // Use coordinate instead (not using actual __deprecated tag due to inability to ignore the warning when these are used in Swift)

@end

NS_ASSUME_NONNULL_END
