/****************************************************************************
*                               Include File                                *
****************************************************************************/
#include <time.h>
#include <stdlib.h>
#include "permission.h"

/****************************************************************************
*                          Private Global Variable                          *
****************************************************************************/
static int DOOR_ON = PERMISSION_UNLOCK;
static int DOOR_OFF = PERMISSION_LOCK;

PERMISSION_CONTROL_T PERMISSION_DATA;

/****************************************************************************
*                              Public Function                              *
****************************************************************************/
int permission_get_local_time_by_integer()
{
    time_t localTime;
    struct tm *timeFormat;
    char timeBuf[128];
    int integerTime = 0;

    time(&localTime);
    timeFormat = localtime(&localTime);

    strftime(timeBuf, sizeof(timeBuf), "%Y%m%d", timeFormat);

    integerTime = atoi(timeBuf);
    
    return integerTime;
}

void permission_init()
{
    int currentTime = permission_get_local_time_by_integer();

    PERMISSION_DATA.limitationDate = TRANSFER_DATE_TO_INT(LIMITATION_YEAR, LIMITATION_MONTH, LIMITATION_DATE);

    if(currentTime > PERMISSION_DATA.limitationDate)
    {
        PERMISSION_DATA.lock = &DOOR_OFF;
    }
    else
    {
        PERMISSION_DATA.lock = &DOOR_ON;
    }
}

void permission_deinit()
{
}


