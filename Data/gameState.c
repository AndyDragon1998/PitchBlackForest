/*****************************************************************************/
/*  Автор         		: Дракончик				                             */
/*  Приставка     		: Super Nintendo Entertainment System	             */
/*  Язык	      		: GNU TCC C                                          */
/*                                                                           */
/*  Содержимое файла	: Стадия Игри				                         */
/*  Атрибут файла		: SOURCE                                             */
/*  Имя файла     		: gameState.c	                                     */
/*                                                                           */
/*****************************************************************************/

#include <snes.h>

#include "include/gameState.h"
#include "include/menuState.h"
#include "include/overState.h"
#include "include/introState.h"

void GameStart(void)
{
    setMode(BG_MODE1, 0);
    bgSetDisable(1);
    bgSetDisable(2);
}

void GameUpdate(void)
{

}

void GameDraw(void)
{

}

void GameEnd(void)
{

}

