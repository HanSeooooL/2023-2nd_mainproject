//
//  FileInOut.c
//  map structure test
//
//  Created by 한설 on 2023/08/07.
//

#include "Parkingcontroll.h"
#include <string.h>
#include <math.h>
#include <unistd.h>


//parkinginfo
Parkinginfo* readParkinginfo(void) {     //주차정보 읽기(조회화면에 사용)
    Parkinginfo *res;
    
    return res;
}

char* checkthecarparking(char* carnumber) { //차량번호를 통해 현재 주차중인지 확인
    char *res;
    return res;
}

void addParkedCar(char carnumber[8]) {   //차량 주차(추가)
    FILE *fp;
    if (access("parkinginfo.bin", 0) != -1) {  //이미 존재하는 파일인 경우 내용 추가
            fp = fopen("parkinginfo.bin", "a");
        }
        else    //없는 경우 생성
            fp = fopen("parkinginfo.bin", "w");
    
}

void ParkedcarOut(char carnumber[8]) {   //차량 출차(삭제)
    
}

