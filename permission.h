#ifndef _PERMISSION_H_
#define _PERMISSION_H_

/****************************************************************************
*                         Public Constant Definition                        *
****************************************************************************/
#define LIMITATION_YEAR 2018
#define LIMITATION_MONTH 1
#define LIMITATION_DATE 1

#define PERMISSION_LOCK 0
#define PERMISSION_UNLOCK 1

#define TRANSFER_DATE_TO_INT(yy,mm,dd) (((yy) * 10000) + ((mm) * 100) + (dd))

#define GET_TIME_LOCK_FLAG(x) (*(x.lock))
#define GET_TIME_LOCK_DATE(x) (x.limitationDate)
#define IS_TIME_LOCK(x) (PERMISSION_LOCK == (*x.lock)) ? (1) : (0)
//#define IS_TIME_LOCK(x) 0
#define GET_PERMISSION_DATA PERMISSION_DATA

/****************************************************************************
*                          Public Type Declaration                          *
****************************************************************************/
typedef struct {
    int * lock;
    int limitationDate;

} PERMISSION_CONTROL_T;

extern PERMISSION_CONTROL_T PERMISSION_DATA;

/****************************************************************************
*                         Public Function Prototype                         *
****************************************************************************/
int permission_get_local_time_by_integer();
void permission_init();
void permission_deinit();

#endif
