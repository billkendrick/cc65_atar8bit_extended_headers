/* 2015 by Bill Kendrick <bill@newbreedsoftware.com> */
/* Notes from http://www.atariarchives.org/mapping/memorymap.php */
/* Note: Shadows of chip registers are in their respective header files
   (e.g., COLOR0 (0x2C4), shadow of COLPF0 (0xD016),
   is defined in gtia.h) */

/*
  Locations 512 to 1151 ($200 to $47F) are used by the OS for working
  variables, tables and data buffers. In this area, locations 512 to 553
  ($200 to $229) are used for interrupt vectors, and locations 554 to 623
  ($22A to $26F) are for miscellaneous use. Much of pages two through
  five cannot be used except by the OS unless specifically noted. A
  number of bytes are marked as "spare", i.e., not in use currently. The
  status of these bytes may change with an Atari upgrade, so their use is
  not recommended.
*/

#ifndef _PAGE2_H
#define _PAGE2_H

/* FIXME: #include headers containing the shadows? */

/*
  The IRQ immediate vector (general). Initialized to 59126
  ($E6F6). JMP through here to determine cause of the IRQ
  interrupt.
*/
#define VIMIRQ *(unsigned int *) 0x216

/*
  System timer one value. Counts backwards from 255. This SIO
  timer is decremented every stage one VBLANK. When it reaches
  zero, it sets a flag to jump (JSR) through the address stored in
  locations 550, 551 ($226, $227). Only the realtime clock
  (locations 18-20; $12-14), timer one, and the attract mode
  register (77; $4D) are updated when the VBLANK routine is cut
  short because time-critical code (location 66; $42 set to non-zero
  for critical code) is executed by the OS. Since the OS uses timer
  one for its I/O routines and for timing serial bus operations
  (setting it to different values for timeout routines), you should use
  another timer to avoid conflicts or interference with the operation
  of the system.
*/
#define CDTMV1 *(unsigned int *) 0x218

/*
  System timer two. Decremented at the stage two VBLANK. Can
  be decremented every stage one VBLANK, subject to critical
  section test as defined by setting of CRITIC flag (location 66;
  $42). This timer may miss (skip) a count when time-critical code
  (CRITIC equals non-zero) is being executed. It performs a JSR
  through location 552, 553 ($228, $229) when the value counts
  down to zero.
*/
#define CDTMV2 *(unsigned int *) 0x21A

/*
  System timer three. Same as 538. Timers three, four, and five are
  stopped when the OS sets the CRITIC flag to non-zero as well.
  The OS uses timer three to OPEN the cassette recorder and to set
  the length of time to read and write tape headers. Any prior value
  in the register during this function will be lost.
*/
#define CDTMV3 *(unsigned int *) 0x21C

/*
  System timer four. Same as 538 ($21A).
*/
#define CDTMV4 *(unsigned int *) 0x21E

/*
  System timer five. Same as 538 ($21A). Timers three, four, and
  five all set flags at 554, 556 and 558 ($22A, $22C, $22E),
  respectively, when they decrement to zero.
*/
#define CDTMV5 *(unsigned int *) 0x220

/*
  VBLANK immediate register. Normally jumps to the stage one
  VBLANK vector NMI interrupt processor at location 59345
  ($E7D1); in the new OS "B" ROMs; 59310, $E7AE). The NMI
  status register tests to see if the interrupt was due to a VBI (after
  testing for a DLI) and, if so, vectors through here to the VBI
  routine, which may be user-written. On powerup, VBI's are
  enabled and DLI's are disabled. See location 512; $200.
*/
#define VVBLKI *(unsigned int *) 0x222

/*
  VBLANK deferred register; system return from interrupt,
  initialized to 59710 ($E93E, in the new OS "B" ROMs; 59653;
  $E905), the exit for the VBLANK routine. NMI.
*/
#define VVBLKD *(unsigned int *) 0x224

/*
  Text window cursor row; value ranges from zero to three (the text
  window has only four lines). TXTROW specifies where the next
  read or write in the text window will occur
*/
#define TXTROW *(unsigned char *) 0x290

/*
  Text window cursor column; value ranges from zero to 39. Unless
  changed by the user, location 658 will always be zero (there are
  only 40 columns in the display, so the MSB will be zero). Since
  POSITION, PLOT, LOCATE and similar commands refer to the
  graphics cursor in the display area above the text window, you
  must use POKE statements to write to this area if PRINT
  statements are insufficient.
*/
#define TXTCOL *(unsigned int *) 0x291

/*
  Contains the current split-screen text window GRAPHICS mode.
  It is the split-screen equivalent to DINDEX (location 87; $57) and
  is always equal to zero when location 128 ($7B) equals zero.
  Initialized to zero (which represents GR.0). You can alter the
  display list to change the text window into any GRAPHICS mode
  desired. If you do so, remember to change TINDEX to reflect that
  alteration.
*/
#define TINDEX *(unsigned char *) 0x293

/*
  Address of the upper left corner of the text window. Split-screen
  equivalent of locations 88, 89 ($58, $59).
  (See also: SAVMSC)
*/
#define TXTMSC *(unsigned int *) 0x294

/*
  Flag for the number of text rows available for printing. 24 ($18) is
  normal for text mode GR.0; four for the text window, zero for all
  graphics modes. In all GRAPHICS modes except zero, if there is
  no text window then 703 will also read zero. The large-text
  displays in GR.1 and GR.2 are treated as graphics displays for
  this purpose. The display handler specifically checks for split-
  screen mode by looking for the variable 24 or four here. If it finds
  24 here, it assumes there is no text window; if not, it looks for the
  variable four.
*/
#define BOTSCR *(unsigned char *) 0x2BF

/*
  Pointer to the top of free memory used by both BASIC (which
  calls it HIMEM) and the OS, passed here from TRAMSZ, location
  6 after powerup. This address is the highest free location in RAM
  for programs and data. The value is updated on powerup, when
  RESET is pressed, when you change GRAPHICS mode, or when
  a channel (IOCB) is OPENed to the display. The display list starts
  at the next byte above MEMTOP.
*/

#define MEMTOP_lo *(unsigned char *) 0x2E5
#define MEMTOP_hi *(unsigned char *) 0x2E6
#define MEMTOP *(unsigned int *) 0x2E5
#define HIMEM_basic_lo *(unsigned char *) 0x2E5
#define HIMEM_basic_hi *(unsigned char *) 0x2E6
#define HIMEM_basic *(unsigned int *) 0x2E5

/*
  Pointer to the bottom of free memory, initialized to 1792 ($700)
  and updated by the presence of DOS or any other low-memory
  application program. It is used by the OS; the BASIC pointer to
  the bottom of free memory is at locations 128, 129 ($80, $81). The
  value in MEMLO is never altered by the OS after powerup.

  This is the address of the first free location in RAM available for
  program use. Set after all FMS buffers have been allocated (see
  locations 1801 and 1802; $709 and $70A). The address of the last
  sector buffer is incremented by 128 (the buffer size in bytes) and
  the value placed in MEMLO. The value updates on powerup or
  when RESET is pressed. This value is passed back to locations 
  128, 129 ($80, $81) on the execution of the BASIC NEW
  command, but not RUN, LOAD or RESET.
*/
#define MEMLO_lo *(unsigned char *) 0x2E7
#define MEMLO_hi *(unsigned char *) 0x2E8
#define MEMLO *(unsigned int *) 0x2E7


/* Cursor inhibit flag. Zero turns the cursor on; any other number turns
   the cursor off. */
#define CRSINH *(unsigned char *) 0x2F0

/* End of page2.h */
#endif /* #ifndef _PAGE2_H */

