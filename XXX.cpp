#include "XXX.h"
#include "permission.h"

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

#define XXX_EER_TIME_EXPIRED 0x0001

int XXX_Init(int dInArgument_a, int dInArgument_b)
{
    permission_init();

    if (IS_TIME_LOCK(GET_PERMISSION_DATA))
    {
        return XXX_EER_TIME_EXPIRED;
    }
    
    return EXIT_SUCCESS;
}