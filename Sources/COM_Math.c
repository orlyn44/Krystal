/* ========================================================================= */
/*!
 * \file    COM_Math.c
 * \brief   File to handle mathematical functions.
 * \author  Nyuu / Orlyn / Red
 * \version 1.0
 * \date    23 June 2015
 */
/* ========================================================================= */
/* Author  | Date     | Comments                                             */
/* --------+----------+----------------------------------------------------- */
/* Nyuu    | 23/06/15 | Creation.                                            */
/* ========================================================================= */

#include "COM_Math.h"

/* ========================================================================= */

/*!
 * \brief Function to initialize the random number generator.
 *
 * \return None.
 */
void COM_Math_Init(void)
{
    srand((unsigned int) time(NULL));
}

/*!
 * \brief Function to get a random number.
 *
 * \param iMin Minimum random number.
 * \param iMax Maximum random number.
 * \return A random number between a min and a max.
 */
int COM_Math_Rand(int iMin, int iMax)
{
    return ((rand() % (iMax - iMin + 1)) + iMin);
}

/*!
 *  \brief  Function to compute the sqroot of a value.
 *
 *  \param  iValue Value to compute.
 *  \return The sqroot of the value.
 */
unsigned int COM_Math_Sqrt32(unsigned int iValue)
{
    unsigned int iCompute;
    unsigned int iIndex;

    if (iValue > 1)
    {
        iCompute = iValue;

        for (iIndex = 0 ; iIndex < 13 ; ++iIndex)
        {
            iCompute = (iCompute + (iValue / iCompute)) >> 1;
        }

        iValue = iCompute;
    }
    
    return iValue;
}

/* ========================================================================= */