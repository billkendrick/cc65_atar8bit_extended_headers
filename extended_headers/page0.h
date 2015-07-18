/* 2015 by Bill Kendrick <bill@newbreedsoftware.com> */
/* Notes from http://www.atariarchives.org/mapping/memorymap.php */
/* Note: Shadows of chip registers are in their respective header files
   (e.g., POKMSK (0x10), shadow of IRQEN (0xD20E),
   is defined in pokey.h) */

#ifndef _PAGE0_H
#define _PAGE0_H

#include "os_structs.h"

/* FIXME: #include headers containing the shadows? */

/*
  RAM pointer for the memory test used on powerup. Also used to
  store the disk boot address--normally 1798 ($706)--for the
  boot continuation routine.
*/
#define RAMLO_lo *(unsigned char *) 0x4
#define RAMLO_hi *(unsigned char *) 0x5
#define RAMLO *(unsigned int *) 0x4

/* Warmstart flag. If the location reads zero, then it is in the middle
   of powerup; 255 is the normal RESET status
   (See NMIRES) */
#define WARMST *(unsigned char *) 0x8

/* Internal realtime clock. Location 20 increments every stage one VBLANK 
   interrupt (1/60 second = one jiffy) until it reaches 255 ($FF);
   then location 19 is incremented by one and 20 is reset to zero
   (every 4.27 seconds). When location 19 reaches 255, it and 20 are reset to
   zero and location 18 is incremented by one (every 18.2 minutes or 65536 TV
   frames). */
#define RTCLOK_hi *(unsigned char *) 0x12
#define RTCLOK_md *(unsigned char *) 0x13
#define RTCLOK_lo *(unsigned char *) 0x14

#define ZIOCB (*(struct ___iocb *)0x20)  /* zero page IOCB */

/*
  Critical I/O region flag; defines the current operation as a time-
  critical section when the value here is non-zero. Checked at the
  NMI process after the stage one VBLANK has been processed.
  POKEing any number other than zero here will disable the repeat
  action of the keys and change the sound of the CTRL-2 buzzer.

  Zero is normal; setting CRITIC to a non-zero value suspends a
  number of OS processes including system software timer coun-
  ting (timers two, three, four and five; see locations 536 to 558;
  $218 to $22E). It is suggested that you do not set CRITIC for any
  length of time. When one timer is being set, CRITIC stops the
  other timers to do so, causing a tiny amount of time to be "lost."
  When CRITIC is zero, both stage one and stage two VBLANK
  procedures will be executed. When non-zero, only the stage one
  VBLANK will be processed.
*/
#define CRITIC *(unsigned char *) 0x42

/*
  Column of the left margin of text (GR.0 or text window only).
  Zero is the value for the left edge of the screen; LMARGN is
  initialized to two.
*/
#define LMARGN *(unsigned char *) 0x52

/*
  Right margin of the text screen initialized to 39 ($27).
*/
#define RMARGN *(unsigned char *) 0x53

/*
  Current graphics or text screen cursor row, value ranging from
  zero to 191 ($BF) depending on the current GRAPHICS mode
*/
#define ROWCRS *(unsigned char *) 0x54

/*
  Current graphics or text mode cursor column; values range from
  zero to 319 (high byte, for screen mode eight) depending on
  current GRAPHICS mode.
*/
#define COLCRS *(unsigned int *) 0x55

/*
  Display mode/current screen mode.
  DINDEX contains the number obtained from the low order four
  bits of most recent open AUX1 byte. It can be used to fool the OS
  into thinking you are in a different GRAPHICS mode by
  POKEing DINDEX with a number from zero to 11. POKE with
  seven after you have entered GRAPHICS mode eight, and it will
  give you a split screen with mode seven on top and mode eight
  below. However, in order to use both halves of the screen, you
  will have to modify location 89 (below) to point to the area of the
  screen you wish to DRAW in.
*/
#define DINDEX *(unsigned char *) 0x57

/*
  The lowest address of the screen memory, corresponding to the
  upper left corner of the screen (where the value at this address
  will be displayed).
  (See also: TXTMSC)
*/
#define SAVMSC *(unsigned int *) 0x58

/*
   RAM size, defined by powerup as passed from TRAMSZ (location 6),
   given in the total number of available pages (one page equals
   256 bytes, so PEEK(106) * 256 will tell you where the Atari thinks
   the last usable address -- byte -- of RAM is).

   MEMTOP (741, 742; $2E5, $2E6) may not extend below this value.
   In a 48K Atari, RAMTOP is initialized to 160 ($A0), which points
   to location 40960 ($A000). The user's highest address will be one
   byte less than this value.

   This is initially the same value as in location 740.
   PEEK(740) / 4 or PEEK(106) / 4 gives the number of 1K blocks.
   You can fool the computer into thinking you have less memory than
   you actually have, thus reserving a relatively safe area for data
   (for your new character set or player/missile characters, for example)
   or machine language subroutines by:

   POKE(106), PEEK(106) - # of pages you want to reserve.
*/
#define RAMTOP *(unsigned char *) 0x6A

/*
  Split-screen cursor control. Equal to 255 ($FF) if the text window
  RAM and regular RAM are swapped; otherwise, it is equal to
  zero. In split-screen modes, the graphics cursor data and the text
  window data are frequently swapped in order to get the values
  associated with the area being accessed into the OS data base
  locations 84 to 95 ($54 to $5F). SWPFLG helps to keep track of
  which data set is in these locations.
*/
#define SWPFLG *(unsigned char *) 0x7B

/*
FIXME
7C          	HOLDCH
7D          	INSDAT
7E,7F          	COUNTR
*/

/*
  Pointer to BASIC's low memory (at the high end of OS RAM
  space). The first 256 bytes of the memory pointed to are the token
  output buffer, which is used by BASIC to convert BASIC
  statements into numeric representation (tokens; see locations
  136, 137; $88, $89). This value is loaded from MEMLO (locations
  743, 744; $2E7, $2E8) on initialization or the execution of a NEW
  command (not on RESET!). Remember to update this value when
  changing MEMLO to reserve space for drivers or buffers.
*/
#define LOMEM *(unsigned int *) 0x80

/*
  Pointer to the top of BASIC memory, the end of the space the
  program takes up. There may still be space between this address
  and the display list, the size of which may be retrieved by the
  FRE(0) command (which actually subtracts the MEMTOP value
  that is at locations 741 and 742; $2E5, $2E6). Not to be confused
  with locations 741 and 742, which have the same name but are an
  OS variable. MEMTOP is also called TOPSTK; it points to the top
  of the stack space pointed to by RUNSTK above.
*/
#define TOPSTK_lo *(unsigned char *) 0x90
#define TOPSTK_hi *(unsigned char *) 0x91
#define TOPSTK *(unsigned int) 0x90
#define MEMTOP_basic_lo *(unsigned char *) 0x90
#define MEMTOP_basic_hi *(unsigned char *) 0x91
#define MEMTOP_basic *(unsigned int) 0x90

/* End of page0.h */
#endif /* #ifndef _PAGE0_H */

