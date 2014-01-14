//
//  Section.h
//  Wikipedia-iOS
//
//  Created by Monte Hurd on 12/19/13.
//  Copyright (c) 2013 Wikimedia Foundation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Article, Image, SectionImage;

@interface Section : NSManagedObject

@property (nonatomic, retain) NSString * anchor;
@property (nonatomic, retain) NSDate * dateRetrieved;
@property (nonatomic, retain) NSString * html;
@property (nonatomic, retain) NSNumber * index;
@property (nonatomic, retain) NSString * title;
@property (nonatomic, retain) NSNumber * tocLevel;
@property (nonatomic, retain) Article *article;
@property (nonatomic, retain) Image *thumbnailImage;
@property (nonatomic, retain) NSSet *sectionImage;
@end

@interface Section (CoreDataGeneratedAccessors)

- (void)addSectionImageObject:(SectionImage *)value;
- (void)removeSectionImageObject:(SectionImage *)value;
- (void)addSectionImage:(NSSet *)values;
- (void)removeSectionImage:(NSSet *)values;

//TODO: refactor other core data objects (article etc) to contain/encapsulate their communication code.

// Gets the latest revision of wikitext from server for this section.
// The block is passed a string with the wiki text once its retrieved.
- (void)getWikiTextThen:(void (^)(NSString *))block;

@end
