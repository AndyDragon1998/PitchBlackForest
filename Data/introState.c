/*****************************************************************************/
/*  Автор         		: Дракончик				                             */
/*  Приставка     		: Super Nintendo Entertainment System	             */
/*  Язык	      		: GNU TCC C                                          */
/*                                                                           */
/*  Содержимое файла	: Стадия логотипов			                         */
/*  Атрибут файла		: SOURCE                                             */
/*  Имя файла     		: introState.c	                                     */
/*                                                                           */
/*****************************************************************************/

#include <snes.h>

#include "include/gameState.h"
#include "include/menuState.h"
#include "include/overState.h"
#include "include/introState.h"

#include "extern/introState.ext"

int introTimer;

void IntroStart(void)
{
    // Copy tiles to VRAM
    bgInitTileSet(0, &IntroPic, &IntroPal, 0, (&IntroPic_end - &IntroPic), (&IntroPal_end - &IntroPal), BG_16COLORS, 0x4000);

    // Copy Map to VRAM
    bgInitMapSet(0, &IntroMap, (&IntroMap_end - &IntroMap), SC_32x32, 0x0000);
	
    // Now Put in 16 color mode and disable other BGs except 1st one
    setMode(BG_MODE1, 0);
    bgSetDisable(1);
    bgSetDisable(2);
    setFadeEffectEx(FADE_IN, 6);
    WaitForVBlank();
    setScreenOn();
    introTimer = 0;

}

void IntroUpdate(void)
{
	introTimer++;
	
	if(introTimer == 100)
	{
		setFadeEffectEx(FADE_OUT, 6);
	}
	
	if(introTimer == 120)
	{
		setScreenOff();
	    // Copy tiles to VRAM
		bgInitTileSet(0, &SNOPic, &SNOPal, 0, (&SNOPic_end - &SNOPic), (&SNOPal_end - &SNOPal), BG_16COLORS, 0x4000);

		// Copy Map to VRAM
		bgInitMapSet(0, &SNOMap, (&SNOMap_end - &SNOMap), SC_32x32, 0x0000);
		setMode(BG_MODE1, 0);
		bgSetDisable(1);
		bgSetDisable(2);
		setFadeEffectEx(FADE_IN, 6);
		WaitForVBlank();
    	setScreenOn();
	}
	
	if(introTimer == 220)
	{
		setFadeEffectEx(FADE_OUT, 6);
	}
	
	if(introTimer > 250)
	{
		
		ChangeState = 4;
	}
}

void IntroDraw(void)
{
	WaitForVBlank();
}

void IntroEnd(void)
{

}

