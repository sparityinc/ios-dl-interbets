//
//  ZLWager.m
//  WarHorse
//
//  Created by Jugs VN on 8/23/13.
//  Copyright (c) 2013 Zytrix Labs. All rights reserved.
//

#import "ZLWager.h"
#import "ZLWagerUtility.h"
#import "ZLAppDelegate.h"

@implementation ZLWager

@synthesize selectedRaceId;

@synthesize selectedTrackId;

@synthesize selectedTrack;

@synthesize selectedRace;

@synthesize selectedRaceMeetNumber;

@synthesize selectedRacePerformanceNumber;

@synthesize selectedBetType;

@synthesize amount;

@synthesize selectedRunners;

@synthesize tsnNumber;
@synthesize is123Available;

- (id)init
{
    self = [super init];
    if (self) {
        self.selectedRaceId = -1;
        self.selectedTrackId = -1;
        self.selectedRace = nil;
        self.selectedTrack = nil;
        self.selectedBetType = @"";
        self.amount = 0.0;
        self.selectedRunners = [[NSMutableDictionary alloc] init];
        [ZLWagerUtility initialize];
    }
    return self;
}

-(double) calculateTotalBetAmount{
    
    int combos = [ZLWagerUtility getNumCombos:self];
    return combos * self.amount;
}

/*-(NSString*) getBetString{
    
    NSMutableString * textString = [NSMutableString string];    
    NSMutableDictionary * dictLegs = self.selectedRunners;
    
    for(int i=0;i<[dictLegs count];i++){
        NSMutableArray *currentLegArray = [dictLegs valueForKey:[NSString stringWithFormat:@"%d", i]];
        if(currentLegArray != nil){
            NSArray *sortedArrayOfString = [currentLegArray sortedArrayUsingComparator:^NSComparisonResult(id obj1, id obj2) {
                return [(NSString *)obj1 compare:(NSString *)obj2 options:NSNumericSearch];
            }];
            if( sortedArrayOfString && [sortedArrayOfString count] > 0) {
                NSString * legString = [sortedArrayOfString componentsJoinedByString:@","];
                [textString appendString:legString];
            }
        }
        [textString appendString:@"/"];
    }
    
    if (textString.length > 0){
        [textString deleteCharactersInRange:NSMakeRange([textString length]-1, 1)];
    }
    return textString;
}*/

-(NSString*) getBetString{
    
    NSMutableString * textString = [NSMutableString string];
    NSMutableDictionary * dictLegs = self.selectedRunners;

    ZLBetType* betType = nil;
    ZLRaceCard *_race_card = [ZLRaceCard findRaceCardByMeetNumber:[ZLAppDelegate getAppData].currentWager.selectedRaceMeetNumber AndPerformanceNumber:[ZLAppDelegate getAppData].currentWager.selectedRacePerformanceNumber];
    if(_race_card){
        ZLRaceDetails * _race_details = [_race_card findRaceDeatilsByRaceId:[ZLAppDelegate getAppData].currentWager.selectedRaceId];
        if(_race_details){
            betType = [_race_details findBetTypeWithName:[ZLAppDelegate getAppData].currentWager.selectedBetType];
        }
    }
    int numLegs = [dictLegs count];
    if( [betType.typeID isEqualToString:@"EBX"] || [betType.typeID isEqualToString:@"TBX"] || [betType.typeID isEqualToString:@"SFX"]){
        numLegs = 1;
    }
    
        
    for(int i=0;i<numLegs;i++){
        NSMutableArray *currentLegArray = [dictLegs valueForKey:[NSString stringWithFormat:@"%d", i]];
        NSMutableString * legString = [NSMutableString string];
        if(currentLegArray != nil){
            NSArray *sortedArrayOfString = [currentLegArray sortedArrayUsingComparator:^NSComparisonResult(id obj1, id obj2) {
                return [(NSString *)obj1 compare:(NSString *)obj2 options:NSNumericSearch];
            }];
            if( sortedArrayOfString && [sortedArrayOfString count] > 0) {
                NSString * lastNum = @"1000"; //any arbitrary value and shouldn't be zero
                int consecutive = 0;

                for(NSString * runner in sortedArrayOfString){
                    if( [runner intValue] == ([lastNum intValue] + 1) ){
                        consecutive++;
                    }
                    else{
                        if( consecutive >= 2){
                            [legString appendString:[NSString stringWithFormat:@"%d-%d,",[lastNum intValue] - consecutive,[lastNum intValue]]];
                            consecutive = 0;
                        }
                        else if( consecutive == 1 ){
                            [legString appendString:[NSString stringWithFormat:@"%d,%d,",[lastNum intValue] - consecutive,[lastNum intValue]]];
                            consecutive = 0;
                        }
                        else{
                            if(![lastNum isEqualToString:@"1000"]){
                                [legString appendString:[NSString stringWithFormat:@"%d,",[lastNum intValue]]];
                            }
                            consecutive = 0;
                        }
                    }
                    lastNum = runner;
                }
                if( consecutive >= 2){
                    [legString appendString:[NSString stringWithFormat:@"%d-%d,",[lastNum intValue] - consecutive,[lastNum intValue]]];
                }
                else if(consecutive == 1){
                    [legString appendString:[NSString stringWithFormat:@"%d,%d,",[lastNum intValue] - consecutive,[lastNum intValue]]];
                }
                else{
                    [legString appendString:[NSString stringWithFormat:@"%d,",[lastNum intValue]]];
                }
            }
        }
        if (legString.length > 0){
            [legString deleteCharactersInRange:NSMakeRange([legString length]-1, 1)];
        }
        [textString appendString:legString];
        [textString appendString:@"/"];
    }
    
    if (textString.length > 0){
        [textString deleteCharactersInRange:NSMakeRange([textString length]-1, 1)];
    }
    return textString;
}


@end
