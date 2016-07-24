#import <XCTest/XCTest.h>
#import "WMFTaskGroup.h"

@interface WMFTaskGroupTests : XCTestCase

@end

@implementation WMFTaskGroupTests

- (void)setUp {
    [super setUp];
}

- (void)tearDown {
    [super tearDown];
}

- (void)testEmptyGroup {
    WMFTaskGroup *group = [WMFTaskGroup new];
    XCTestExpectation *expectation = [self expectationWithDescription:@"Wait for group"];
    [group waitInBackgroundWithCompletion:^{
        XCTAssertTrue(true);
        [expectation fulfill];
    }];
    [self waitForExpectationsWithTimeout:5 handler:^(NSError * _Nullable error) {
        if (error) {
            XCTFail();
        }
    }];
}

- (void)testTimeout {
    WMFTaskGroup *group = [WMFTaskGroup new];
    [group enter];
    XCTestExpectation *expectation = [self expectationWithDescription:@"Wait for group"];
    [group waitInBackgroundWithTimeout:1 completion:^{
        XCTAssertTrue(true);
        [expectation fulfill];
    }];
    [self waitForExpectationsWithTimeout:5 handler:^(NSError * _Nullable error) {
        if (error) {
            XCTFail();
        }
    }];
}

- (void)testSimple {
    WMFTaskGroup *group = [WMFTaskGroup new];
    [group enter];
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [group leave];
    });
    XCTestExpectation *expectation = [self expectationWithDescription:@"Wait for group"];
    [group waitInBackgroundWithCompletion:^{
        XCTAssertTrue(true);
        [expectation fulfill];
    }];
    [self waitForExpectationsWithTimeout:5 handler:^(NSError * _Nullable error) {
        if (error) {
            XCTFail();
        }
    }];
}

- (void)testHang {
    WMFTaskGroup *group = [WMFTaskGroup new];
    [group enter];
    [group waitInBackgroundWithCompletion:^{
        XCTFail();
    }];
    XCTestExpectation *expectation = [self expectationWithDescription:@"Wait for group"];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [expectation fulfill];
    });
    [self waitForExpectationsWithTimeout:5 handler:^(NSError * _Nullable error) {
        XCTAssert(true);
    }];
}


@end