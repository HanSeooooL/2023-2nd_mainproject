//
//  Parkingcontroll.c
//  map structure test
//
//  Created by 한설 on 2023/08/07.
//

#include "Parkingcontroll.h"
#include <time.h>


char* getnowtimeeightcharacter(void) {
    char *res;
    time_t now;
    struct tm *t;
    
    
    now = time(&now);
    t = localtime(&now);
    
    res = (char*)malloc(sizeof(char) * 10);
    res[0] = ((t -> tm_year + 1900) % 100) / 10 + 48;
    res[1] = ((t -> tm_year + 1900) % 10) + 48;
    if((t -> tm_mon) < 9) {
        sprintf(res, "%s0%d", res, (t -> tm_mon) + 1);
    }
    else sprintf(res, "%s%d", res, (t -> tm_mon) + 1);
    
    if((t -> tm_mday) < 10) {
        sprintf(res, "%s0%d", res, t -> tm_mday);
    }
    else sprintf(res, "%s%d", res, t -> tm_mday);
    if((t -> tm_hour) < 10) {
        sprintf(res, "%s0%d", res, t -> tm_hour);
    }
    else sprintf(res, "%s%d", res, t -> tm_hour);
    if((t -> tm_min) < 10) {
        sprintf(res, "%s0%d", res, t -> tm_min);
    }
    else sprintf(res, "%s%d", res, t -> tm_min);
    
    
    
    return res;
}
