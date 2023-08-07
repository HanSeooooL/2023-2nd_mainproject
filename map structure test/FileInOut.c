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
Parkinginfo* readParkinginfo(char areacode) {     //주차정보 읽기(조회화면에 사용)
    Parkinginfo *res;
    FILE *fp;
    char* line;
    int n;
    if(fp = fopen("Parkinginfo.bin", "rb") == null) {
        exit(1);
    }
    if(line = fgets(line, MAX_CHAR_PER_LINE, fp)) {
        if(line[0] == areacode) {
            n += 1;
            readParkinginfotail(fp, res, areacode, &n);
            
            strncpy(res[n] -> carnumber, &line[0], 8);
            res[n] -> carnumber[8] = '\0';
            
            strncpy(res[n] -> parkingspacecode, &line[10], 5);
            res[n] -> parkingspacecode[5] = '\0';
            
            strncpy(res[n] -> parkingtime, &line[15], 10);
            res[n] -> parkingtime[10] = '\0';
            n--;
        }
    }
    
    return res;
}

void readParkinginfotail(FILE *fp ,Parkinginfo *arr, char areacode, int *n) {    //주차정보 재귀꼬리
    char* line;
    if(!(line = fgets(line, MAX_CHAR_PER_LINE,fp))) {
        arr = (Parkinginfo*)malloc(sizeof(Parkinginfo) * *n);
        *n--;
        free(line);
        return;
    }
    if(*n == - 1) return;
    
    *n += 1;
    readParkinginfotail(fp, arr, areacode, n);
    
    strncpy(res[*n] -> carnumber, &line[0], 8);
    res[*n] -> carnumber[8] = '\0';
    
    strncpy(res[*n] -> parkingspacecode, &line[10], 5);
    res[*n] -> parkingspacecode[5] = '\0';
    
    strncpy(res[*n] -> parkingtime, &line[15], 10);
    res[*n] -> parkingtime[10] = '\0';
    (*n)--;
    free(line);
    
    
    
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

