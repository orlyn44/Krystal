/* ========================================================================= */
/*!
 * \file    SDL_Util.h
 * \brief   File to interface with the 'SDL' util functions.
 * \author  Nyuu / Orlyn / Red
 * \version 1.0
 * \date    13 June 2015
 */
/* ========================================================================= */
/* Author  | Date     | Comments                                             */
/* --------+----------+----------------------------------------------------- */
/* Nyuu    | 13/06/15 | Creation.                                            */
/* ========================================================================= */

#ifndef __SDL_UTIL_H__
#define __SDL_UTIL_H__
    
    #include "SDL_Shared.h"

    SDL_Texture *UTIL_TextureLoadRW(const char *szPath, SDL_RWops *pRWops, SDL_Rect *pTextureSize);
    SDL_Texture *UTIL_TextureLoad(const char *szPath, SDL_Rect *pTextureSize);
    void         UTIL_TextureFree(SDL_Texture **ppTexture);
    SDL_RWops   *UTIL_RWOpen(const char *szPath, const char *szMode);
    void         UTIL_RWClose(SDL_RWops **pRw);
    Mix_Music   *UTIL_MusicLoad(const char *szPath);
    void         UTIL_MusicFree(Mix_Music **ppMusic);
    Mix_Chunk   *UTIL_ChunkLoad(const char *szPath);
    void         UTIL_ChunkFree(Mix_Chunk **ppChunk);

    int          UTIL_ContainPoint(const SDL_Rect *pRect, const SDL_Point *pPoint);

#endif // __SDL_UTIL_H__

/* ========================================================================= */
