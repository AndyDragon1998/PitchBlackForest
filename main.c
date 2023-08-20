/*****************************************************************************/
/*  Автор         		: Дракончик				                             */
/*  Приставка     		: Super Nintendo Entertainment System	             */
/*  Язык	      		: GNU TCC C                                          */
/*                                                                           */
/*  Содержимое файла	: Главный Cи файл			                         */
/*  Атрибут файла		: SOURCE                                             */
/*  Имя файла     		: main.c	                                         */
/*                                                                           */
/*****************************************************************************/

#include <snes.h>

#include "Data/include/introState.h"
#include "Data/include/menuState.h"
#include "Data/include/gameState.h"
#include "Data/include/overState.h"
#include "Data/soundbank.h"

int StateNumber = 0;

int ChangeState = -1;

extern char SOUNDBANK__;

typedef void (*void_fct_void)();

const void_fct_void StateManager[16]=
{
    &IntroStart,&IntroUpdate,&IntroDraw,&IntroEnd,
    &MenuStart,&MenuUpdate,&MenuDraw,&MenuEnd,
    &GameStart,&GameUpdate,&GameDraw,&GameEnd,
    &OverStart,&OverUpdate,&OverDraw,&OverEnd
};

void StateMachineChange()
{
	
	StateManager[StateNumber +3]();
	StateNumber = ChangeState;
	ChangeState =-1;
    StateManager[StateNumber]();
}

int main(void)
{

    // Initialize sound engine (take some time)
    spcBoot();

    // Initialize SNES
    consoleInit();
    
    // Set give soundbank
    spcSetBank(&SOUNDBANK__);

	StateManager[StateNumber]();
    while (1)
    {
    
        StateManager[StateNumber + 1]();
        StateManager[StateNumber + 2]();
        
        if(ChangeState != -1)
        {
        	StateMachineChange();
        }
        
    }
    return 0;
}
