//
//  Parkingcontroll.h
//  map structure test
//
//  Created by 한설 on 2023/08/07.
//

#ifndef Parkingcontroll_h
#define Parkingcontroll_h

#define MAX_CHAR_PER_LINE 1000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _carinfo {
    char carnumber[9]; //12가3456 한글은 2byte취급이므로. not null Primary Key
    char name[40]; //차주명
    char phonenumber[14]; //전화번호
    char passcode[11]; //정기권 코드
    char gotpassday[11];   //정기권 발급일 년: 2 월: 2 일: 2 시간: 2 분: 2
} Carinfo;

typedef struct _parkinginfo {
    char carnumber[9];      //12가3456 한글은 2byte취급이므로. not null foreign key reference by carinfo.carnumber
    char parkingspacecode[6]; //층수: 1 자리타입: 1 자리번호: 3 not null
    char parkingtime[11];   //년: 2 월: 2 일: 2 시간: 2 분: 2 not null
} Parkinginfo;

typedef struct _commuterpass {
    char passcode[11]; //정기권 코드 not null primary key
    char passname[31]; //정기권 이름 not null
    char passendtime[4]; //정기권 기간 not null
} Commuterpass;

typedef struct _couponinfo {
    char couponcode[11];    //쿠폰 코드 not null primary key
    char couponname[31];    //쿠폰 이름 not null
    char couponend[11];     //쿠폰 만료일 not null
} Couponinfo;

typedef struct _realcoupon {
    char carnumber[9];  //12가3456 한글은 2byte취급이므로. not null foreign key reference by couponinfo.couponcode
    char couponcode[11]; //쿠폰 코드 not null foreign key reference by carinfo.carnumber
    char startday[11]; //쿠폰 발급일 년: 2 월: 2 일: 2 시간: 2 분: 2
} Realcoupon;

typedef struct _parkingplaceinfo {
    char areaname[31];
} Parkingplaceinfo;


//FileInOut
//parkinginfo
Parkinginfo* readParkinginfo(char areacode);     //선택한 공간의 주차정보 읽기(조회화면에 사용)
char* checkthecarparking(char* carnumber); //차량번호를 통해 현재 주차중인지 확인
void addParkedCar(char carnumber[8]);   //차량 주차(추가)
void ParkedcarOut(char carnumber[8]);   //차량 출차(삭제)

//carinfo
void addCarinfo(char* carnumber, char* name, char* phonenumber); //차량정보 등록(차량번호, 차주명, 전화번호)
void deleteCarinfo(char* carnumber); //차량정보를 이용한 차량정보 삭제
Carinfo searchCarinfo(char* carnumber);     //차량번호를 통한 차량정보 검색
void updateCarinfo(char* carnumber); //차량정보를 이용한 정보 수정

//commuterpass, couponinfo, realcoupon
void addCommuterpass(char* passname, char* passendtime); //정기권 추가
void deleteCommuterpass(char* passname); //정기권 삭제
void updateCommuterpass(char* passname); //정기권 수정


//Programinside
char* getnowtimeeightcharacter(void);   //현재 시각 10자리 코드로 가공


//UI
void Programstart(void);

#endif /* Parkingcontroll_h */
