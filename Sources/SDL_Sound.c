/* ========================================================================= */
/*!
 * \file    SDL_Sound.c
 * \brief   File to handle the sounds.
 * \author  Nyuu / Orlyn / Red
 * \version 1.0
 * \date    13 June 2015
 */
/* ========================================================================= */
/* Author  | Date     | Comments                                             */
/* --------+----------+----------------------------------------------------- */
/* Nyuu    | 13/06/15 | Creation.                                            */
/* Red     | 13/06/15 | Add Alloc.                                           */
/* ========================================================================= */

#include "SDL_Util.h"
#include "SDL_Sound.h"

/* ========================================================================= */

/*! Global variable to handle the volume of the sounds (0 - 100)% */
static Uint32 SDL_Sound_volume = 100;

/* ========================================================================= */

/*!
 * \brief  Function to load a sound.
 *
 * \param  szSndName Name of the sound.
 * \return A pointer to the loaded sound, or NULL if error.
 */
SDL_Sound *SDL_Sound_Alloc(const char *szSndName)
{
    SDL_Sound *pSound      = NULL;
    char      *szSoundPath = NULL;

    szSoundPath = UTIL_StrBuild("sounds/", szSndName, ".wav", NULL);

    if (szSoundPath)
    {
        pSound = (SDL_Sound *) UTIL_Malloc(sizeof(SDL_Sound));

        if (pSound)
        {         
            pSound->pMixChunk = UTIL_ChunkLoad(szSoundPath);
            pSound->szName    = UTIL_StrCopy(szSndName);

            if (!pSound->pMixChunk || !pSound->szName) // Error: must free...
            {
                UTIL_ChunkFree(&pSound->pMixChunk);
                UTIL_Free(pSound->szName);
                UTIL_Free(pSound);
            }
        }

        UTIL_Free(szSoundPath);
    }

    return pSound;
}

/*!
 * \brief  Function to get the name of a sound.
 *
 * \param  pSound Pointer to the sound.
 * \return The name of the sound.
 */
const char *SDL_Sound_GetName(const SDL_Sound *pSound)
{
    return pSound->szName;
}

/*!
 * \brief  Function to play a sound.
 *
 * \param  pSound   Pointer to a loaded sound.
 * \param  iChannel Channel to play the sound.
 * \param  iVolume  Volume to play the sound (0 - 128).
 * \param  iLoops   Number of times the sound must be looped.
 * \return None.
 */
void SDL_Sound_Play(SDL_Sound *pSound, Uint32 iChannel, Uint32 iVolume, Sint32 iLoops)
{
    iVolume = ((iVolume * SDL_Sound_volume) / 100);

    Mix_VolumeChunk(pSound->pMixChunk, iVolume);
    Mix_PlayChannel(iChannel, pSound->pMixChunk, iLoops);
}

/*!
 * \brief  Function to free a sound.
 *
 * \param  ppSound Pointer to pointer to the sound to free.
 * \return None.
 */
void SDL_Sound_Free(SDL_Sound **ppSound)
{
    UTIL_Free((*ppSound)->szName);
    UTIL_ChunkFree(&( *ppSound )->pMixChunk);
    UTIL_Free(*ppSound);
}

/* ========================================================================= */

/*!
 * \brief  Function to set the global volume of the sounds.
 *
 * \param  iVolume the value of the global volume (0 - 100)%.
 * \return None.
 */
void SDL_Sound_SetGlobalVolume(Uint32 iVolume)
{
    iVolume = COM_Math_Min(iVolume, 100);

    SDL_Sound_volume = iVolume;

    COM_Log_Print(COM_LOG_INFO, "Sound volume is now: %d%%.", iVolume);
}

/*!
 * \brief  Function to get the global volume of the sounds.
 *
 * \return The value of the global volume (0 - 100)%.
 */
Uint32 SDL_Sound_GetGlobalVolume(void)
{
    return SDL_Sound_volume;
}
/* ========================================================================= */
