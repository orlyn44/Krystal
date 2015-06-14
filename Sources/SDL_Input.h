/* ========================================================================= */
/*!
 * \file    SDL_Input.h
 * \brief   File to interface with the inputs (Keyboard, mouse..).
 * \author  Nyuu / Orlyn / Red
 * \version 1.0
 * \date    09 June 2015
 */
/* ========================================================================= */
/* Author  | Date     | Comments                                             */
/* --------+----------+----------------------------------------------------- */
/* Nyuu    | 09/06/15 | Creation.                                            */
/* Red     | 10/06/15 | Creation of the SDL_Input structure.                 */
/* ========================================================================= */

#ifndef __SDL_INPUT_H__
#define __SDL_INPUT_H__

    #include "SDL_Shared.h"

    /*!
     * \struct SDL_Input
     * \brief  Structure to handle the inputs.
     */
    typedef struct
    {
        SDL_bool bKey[SDL_NUM_SCANCODES]; /*!< Status of each key of the keyboard*/
        SDL_bool bMotionEvent;            /*!< Flag to indicate if the mouse has moved since the last time */
        Sint32   iMouseX;                 /*!< Absolute position of the mouse on X. */
        Sint32   iMouseY;                 /*!< Absolute position of the mouse on Y. */
        Sint32   iMouseXRel;              /*!< Relative position of the mouse on X. */
        Sint32   iMouseYRel;              /*!< Relative position of the mouse on Y. */
        Sint32   iScrollVertical;         /*!< Amount scrolled vertically, positive away from the user and negative toward the user. */
        SDL_bool bMouseButtons[8];        /*!< Status of each buttons of the mouse */
        SDL_bool bQuit;                   /*!< Flag to indicate if the cross has been pressed. */
    } SDL_Input;

    void SDL_Input_Init(SDL_Input *pInput);
    void SDL_Input_Update(SDL_Input *pInput);

#endif // __SDL_INPUT_H__

/* ========================================================================= */