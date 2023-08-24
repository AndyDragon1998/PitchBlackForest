/*****************************************************************************/
/*  Автор         		: Дракончик				                             */
/*  Приставка     		: Super Nintendo Entertainment System	             */
/*  Язык	      		: GNU TCC C                                          */
/*                                                                           */
/*  Содержимое файла	: управление тиле карти		                         */
/*  Атрибут файла		: SOURCE                                             */
/*  Имя файла     		: tileMap.c	           		                         */
/*                                                                           */
/*****************************************************************************/


const u16 *vramAddr = 0x2116;
const u16 *vramData = 0x2118;
const u16 TILESET_BASE = 0x2000;
// ...
*vramAddr = TILESET_BASE + tileIndex;
*vramData = tileData;
