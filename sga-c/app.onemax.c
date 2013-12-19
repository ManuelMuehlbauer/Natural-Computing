/*----------------------------------------------------------------------------*/
/* app.c - application dependent routines, change these for different problem */
/* Modified by Michael O'Neill 19 September 2006                              */
/* Implements OneMax                                                          */
/*----------------------------------------------------------------------------*/

#include <math.h>
#include "external.h"

void application()
/* this routine should contain any application-dependent computations */
/* that should be performed before each GA cycle. called by main()    */
{
}


void app_data()
/* application dependent data input, called by init_data() */
/* ask your input questions here, and put output in global variables */
{
}


void app_free()
/* application dependent free() calls, called by freeall() */
{
}


void app_init()
/* application dependent initialization routine called by intialize() */
{
}


void app_initreport()
/* Application-dependent initial report called by initialize() */
{
}


void app_malloc()
/* application dependent malloc() calls, called by initmalloc() */
{
/*    char *malloc(); */
}


void app_report()
/* Application-dependent report, called by report() */
{
}


void app_stats(pop)
/* Application-dependent statistics calculations called by statistics() */
struct individual *pop;
{
}


void objfunc(critter)
/* fitness function is OneMax, 
    */

struct individual *critter;
{
    unsigned mask=1;   /* mask for current bit */
    unsigned bitpos;   /* current bit position */
    unsigned tp;
    int j, k, stop;

    critter->fitness = 0.0;

    /* loop thru number of bytes holding chromosome */
    for(k = 0; k < chromsize; k++)
    {
        if(k == (chromsize-1))
            stop = lchrom-(k*UINTSIZE);
        else
            stop = UINTSIZE;

        /* loop thru bits in current byte */
        tp = critter->chrom[k];
        for(j = 0; j < stop; j++)
        {
            bitpos = j + UINTSIZE*k; 
            /* test for current bit 0 or 1 */
            if((tp&mask) == 1)
            {
                critter->fitness = critter->fitness + 1.0;
            }
            tp = tp>>1;
        }
    }

    /* At this point, fitness = x */
    //   printf("Raw Fitness: %f\n", critter->fitness);
    /* normalize the fitness */
    /*  bitpos counts from zero the number 
	of bits in the individual that are used */
    critter->fitness = critter->fitness/(bitpos+1);
    //   printf("Normalised Fitness: %f\n", critter->fitness);
}
