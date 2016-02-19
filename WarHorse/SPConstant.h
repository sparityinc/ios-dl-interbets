//
//  SPConstant.h
//  mywinners
//
//  Created by EnterPi on 10/09/13.
//  Copyright (c) 2013 Zytrix Labs. All rights reserved.
//

#ifndef WarHorse_SPConstant_h
#define WarHorse_SPConstant_h


#define IS_IPHONE5 (([[UIScreen mainScreen] bounds].size.height-568)?NO:YES)
#define CLIENT_ID @"Interbets"
#define CLIENT_NAME @"InterBets"
#define BASE_CONTEXT_NAME @"mobile_services"
#define BASE_CONTEXT_NAME_CMS @"mobile_cms"

#define QRCode_Text @"Withdrawal:\n    To withdraw funds or cash voucher.\nTerminal:\n     Access your One Day Pass on terminal."

#define TextviewMes_One @"On Hold will be deposited to your wagering when it clears the banking network. Additional requests will be deposited when they clear the banking network."
#define TextviewMes_Two @"Click here to learn how to have your immediate deposit limit increased."
#define TextviewMes_Third @"Note: Nassau OTB charges a "
#define TextviewMes_Four @"transaction fee for each ACH transaction."

#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)


// DevDl API's

#define kDownLoadedBaseCMSUrl @"http://interbets.spodemo.com/mobile_cms/file/"


#define kGetMyBets (BASE_CONTEXT_NAME@"/services/v1/myBets")
#define myBets1 (BASE_CONTEXT_NAME@"/services/v1/myBets1")
#define getResultsWithDate (BASE_CONTEXT_NAME@"/services/v1/getResultsWithDate")



//Register APIs

#define createOneDayPassAccount (BASE_CONTEXT_NAME@"/services/v3/createOneDayPassAccount")
#define kGetSendVerificationCodeForPassword (BASE_CONTEXT_NAME@"/services/v3/sendVerificationCodeForPassword")
#define kGetresetAccountPassword (BASE_CONTEXT_NAME@"/services/v3/resetAccountPassword")
#define kGetresetPassword (BASE_CONTEXT_NAME@"/services/v1/resetPassword")

#define registerAnonymousUsers (BASE_CONTEXT_NAME@"/services/v3/registerAnonymousUsers")

//New Registation API's

//#define validateAccount (BASE_CONTEXT_NAME@"/services/v4/validateAccount"

//#define getIdology (BASE_CONTEXT_NAME@"/services/v2/getIdology"

//#define kGetRegisterUser (BASE_CONTEXT_NAME@"/services/v4/registerUser"

//New Registation API's

#define validateAccount (BASE_CONTEXT_NAME@"/services/v5/validateAccount")

#define getIdology (BASE_CONTEXT_NAME@"/services/v3/getIdology")

#define kGetRegisterUser (BASE_CONTEXT_NAME@"/services/v5/registerUser")
// Final Registation Promo code validation

#define kPromoCodeValidation (BASE_CONTEXT_NAME@"/services/v3/validatePromocode")


//Registration AppConfig

#define kGetRegistrationConfig (BASE_CONTEXT_NAME@"/services/v3/getRegistrationConfig")

// ADW - NO

#define kGetValidateExistingAccount (BASE_CONTEXT_NAME@"/services/v3/validateExistingAccount")
#define kGetRegisterExistingUser (BASE_CONTEXT_NAME@"/services/v4/registerExistingUser")

//Old Registation API's
/*
 #define validateAccount (BASE_CONTEXT_NAME@"/services/v3/validateAccount"
 
 #define getIdology (BASE_CONTEXT_NAME@"/services/v1/getIdology"
 
 #define kGetRegisterUser (BASE_CONTEXT_NAME@"/services/v3/registerUser"
 */



#define digitalVoucherRegister (BASE_CONTEXT_NAME@"/services/v3/createTempAccount")

//LOGIN, LOGOUT API
#define Login (BASE_CONTEXT_NAME@"/services/Login")
#define logout (BASE_CONTEXT_NAME@"/services/v1/logout")
#define getActiveAccountIdForDevice (BASE_CONTEXT_NAME@"/services/v3/getActiveAccountIdForDevice")


#define isAccountClosedForDevice  (BASE_CONTEXT_NAME@"/services/v3/isAccountClosedForDevice")


//Dash Board API
#define getNumberOfInplayBets (BASE_CONTEXT_NAME@"/services/v1/getNumberOfInplayBets")
#define UserPreferences (BASE_CONTEXT_NAME@"/services/GetUserPreferences")


#define SaveUserPreferences (BASE_CONTEXT_NAME@"/services/v1/saveUserPreferencesIng4")
#define nickNameInfo (BASE_CONTEXT_NAME@"/services/v1/getNickName")



//Wager
#define kGetCards (BASE_CONTEXT_NAME@"/services/v3/getCards")
#define getCardDetail (BASE_CONTEXT_NAME@"/services/v3/getCardDetail")
#define isBetAmtValid (BASE_CONTEXT_NAME@"/services/v1/isBetAmtValid")
#define placeBet (BASE_CONTEXT_NAME@"/services/v3/placeBet")

//MyBets
#define myBets2 (BASE_CONTEXT_NAME@"/services/v1/myBets2")
#define mybetsfinal (BASE_CONTEXT_NAME@"/services/v1/myBetsFinal")
#define mybetsinplay (BASE_CONTEXT_NAME@"/services/v1/myBetsInplay")


#define mybetsfinal (BASE_CONTEXT_NAME@"/services/v1/myBetsFinal")

#define mybetsinplay (BASE_CONTEXT_NAME@"/services/v1/myBetsInplay")


#define CancelBet (BASE_CONTEXT_NAME@"/services/v3/CancelBet")

//Wallet
#define kGetPaymentServiceChargeInfo (BASE_CONTEXT_NAME@"/services/v3/getPaymentServiceChargeInfo")
#define getAccountActivityWithPagination (BASE_CONTEXT_NAME@"/services/getAccountActivityWithPagination")
#define Deposit (BASE_CONTEXT_NAME@"/services/v3/Deposit")
#define withdrawal (BASE_CONTEXT_NAME@"/services/v1/withdrawal")
#define encryptAndGenerateQR (BASE_CONTEXT_NAME@"/services/v1/encryptAndGenerateQR")
#define redeemRewards (BASE_CONTEXT_NAME@"/services/v3/redeemRewards")
#define getOntAndCplQRcode (BASE_CONTEXT_NAME@"/services/v1/encryptAndGenerateQRForTransaction")



//RESULT API
#define loadCardsArray (BASE_CONTEXT_NAME@"/services/v3/loadCardsArray")
#define getResultsWithMeetAndPerf (BASE_CONTEXT_NAME@"/services/v1/getResultsWithMeetAndPerfFromG4")

//ODDS BOARD
#define getQueryResult (BASE_CONTEXT_NAME@"/services/getQueryResult")

#define getAccountBalance (BASE_CONTEXT_NAME@"/services/v1/getAccountBalance")
#define AvailableBalance (BASE_CONTEXT_NAME@"/services/v1/AvailableBalance")
#define getRewardsSummary (BASE_CONTEXT_NAME@"/services/v1/getRewardsSummary")

//Live Video
#define loadStreamUrl (BASE_CONTEXT_NAME@"/services/loadStreamUrl")

//APP Config API
#define kAppConfig (BASE_CONTEXT_NAME@"/services/v1/ReadAPI?screenId=Interbets")
#define saveAdwUser (BASE_CONTEXT_NAME@"/services/v1/saveAdwUser")
#define RegisterAdwUser (BASE_CONTEXT_NAME@"/services/v1/RegisterAdwUser")
#define kGetSaveAnonymousUser (BASE_CONTEXT_NAME@"/services/v1/saveAnonymousUser")

#define getRewardPointsSummary (BASE_CONTEXT_NAME@"/services/getRewardPointsSummary")
#define saveCustomerInfo (BASE_CONTEXT_NAME@"/services/v1/saveCustomerInfo")

#define getCreditCardDepositUrl (BASE_CONTEXT_NAME@"/services/v3/getCreditCardDepositUrl")



#endif