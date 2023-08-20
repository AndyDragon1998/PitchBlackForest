/*****************************************************************************/
/*  Автор         		: Дракончик				                             */
/*  Приставка     		: Super Nintendo Entertainment System	             */
/*  Язык	      		: GNU TCC C                                          */
/*                                                                           */
/*  Содержимое файла	: Стадия главного меню		                         */
/*  Атрибут файла		: SOURCE                                             */
/*  Имя файла     		: menuState.c	                                     */
/*                                                                           */
/*****************************************************************************/

#include <snes.h>

#include "include/gameState.h"
#include "include/menuState.h"
#include "include/overState.h"
#include "include/introState.h"
#include "soundbank.h"


#include "extern/menuState.ext"

int menuTimer;


void MenuStart(void)
{
    // Copy tiles to VRAM
    bgInitTileSet(0, &TitlePic, &TitlePal, 0, (&TitlePic_end - &TitlePic), (&TitlePal_end - &TitlePal), BG_16COLORS, 0x4000);

    // Copy Map to VRAM
    bgInitMapSet(0, &TitleMap, (&TitleMap_end - &TitleMap), SC_32x32, 0x0000);
    
    // Load music
    spcLoad(MOD_BLOOBEHIND);

    // Now Put in 16 color mode and disable other BGs except 1st one
    setMode(BG_MODE1, 0);
    setFadeEffect(FADE_IN);
    bgSetDisable(1);
    bgSetDisable(2);
    setScreenOn();
    
     // Play file from the beginning
    spcPlay(0);
    
    menuTimer = 0;
}

void MenuUpdate(void)
{
    // Update music / sfx stream and wait vbl
	spcProcess();
	WaitForVBlank();
	menuTimer++;
	if(menuTimer == 3300)
	{
		setFadeEffect(FADE_OUT);
	}
	
	if(menuTimer == 3305)
	{
		ChangeState = 0;
	}
	
}

void MenuDraw(void)
{

}

void MenuEnd(void)
{

}

