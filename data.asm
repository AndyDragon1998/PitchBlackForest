.include "hdr.asm"

.section ".rodata1" superfree

;Folowing list is graphical data used for the game.

IntroPic:
.incbin "Graphics/Images/pvsneslib.pic"
IntroPic_end:


.ends

.section ".rodata2" superfree

TitlePic:
.incbin "Graphics/Images/Title.pic"
TitlePic_end:

IntroMap:
.incbin "Graphics/Images/pvsneslib.map"
IntroMap_end:

IntroPal: 
.incbin "Graphics/Images/pvsneslib.pal"
IntroPal_end:

TitleMap:
.incbin "Graphics/Images/Title.map"
TitleMap_end:

TitlePal: 
.incbin "Graphics/Images/Title.pal"
TitlePal_end:

.ends

.section ".rodata3" superfree
SNOPic:
.incbin "Graphics/Images/SNO.pic"
SNOPic_end:

SNOMap:
.incbin "Graphics/Images/SNO.map"
SNOMap_end:

SNOPal: 
.incbin "Graphics/Images/SNO.pal"
SNOPal_end:

.ends

