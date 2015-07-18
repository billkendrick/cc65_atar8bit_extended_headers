/* os.h */
/* 2015 by Bill Kendrick <bill@newbreedsoftware.com> */
/* Notes from http://www.atariarchives.org/mapping/memorymap.php */
/* and http://www.atariarchives.org/mmm/ */

#ifndef _OS_H
#define _OS_H

/* FIXME
   0xE000 - 0xE399 = OS font -- give it a label, and its page
   #define XXX 0xE000
   #define PAGEXXX 0xE0
*/

/*
  FIXME 0xE400 - 0xE455
*/

/*
  Central Input/Output (CIO) utility entry. CIO handles all of the
  I/O operations or data transfers. Information placed in the
  IOCB's tells CIO what operations are necessary. CIO passes this
  information to the correct device driver routine and then passes
  control to the Device Control Block (DCB). This in turn calls up
  SIO (below) to control the actual peripheral(s). CIO treats all I/O
  in the same manner: device independent. The differentiation
  between operations is done by the actual device drivers.

  You jump to here to use the IOCB handler routines in ROM.
  BASIC supports only record I/O or one-byte-at-a-time I/O (GET
  and PUT). Addressing CIOV directly will allow the user to input
  or output a buffer of characters at a time, such as loading a
  machine language program directly into memory from a disk file.
  This is considerably faster than using BASIC functions such as
  GET. Here is a typical machine language subroutine to do this:
*/
#define CIOV 0xE456

#define CALL_CIOV0 asm("ldx #$00"); asm("JSR $E456")
#define CALL_CIOV1 asm("ldx #$10"); asm("JSR $E456")
#define CALL_CIOV2 asm("ldx #$20"); asm("JSR $E456")
#define CALL_CIOV3 asm("ldx #$30"); asm("JSR $E456")
#define CALL_CIOV4 asm("ldx #$40"); asm("JSR $E456")
#define CALL_CIOV5 asm("ldx #$50"); asm("JSR $E456")
#define CALL_CIOV6 asm("ldx #$60"); asm("JSR $E456")
#define CALL_CIOV7 asm("ldx #$70"); asm("JSR $E456")

/* FIXME: Add a generic CALL_CIO(channel) function/macro/whatever */

/*
  Serial Input/Output (SIO) utility entry point. SIO drives the
  serial bus and the peripherals. When a request is placed in the
  Device Control Block (DCB) by a device handler, SIO takes
  control and uses the data in the DCB to perform the operation
  required. SIO takes care of the transfer of data as defined by the
  DCB. CIO (above) is responsible for the "packaging" of the data
  and transfers control to SIO when necessary. See the DCB
  locations 768 to 779 ($300-$30B).
  SIO first sends a command frame to the device, consisting of five
  bytes: the device ID, the command BYTE, two auxiliary bytes for
  device-specific information, then a checksum (which is the sum
  of the first four bytes). If the device acknowledges this frame, it is
  followed, if necessary, by the data frame of a fixed number of
  bytes depending on the device record size, plus a checksum
  byte. Initialized to 59737 ($E959).
*/
#define SIOV 0xE459

/*
  Set system timers during the VBLANK routine. Uses the 6502 X
  register for the MSB of vector/times, Y for the LSB and A for the
  number of the vector to hack (change). SETVBV insures that both
  bytes of the vector addressed will be updated while VBLANK is
  enabled. You can JSR here when creating your own timer
  routines. See COMPUTE!, November 1981, for an application.
  Initialized to 59666 ($E912) old ROMs, 59629 ($E8ED) new
  ROMs.
*/
#define SETVBV 0xE45C

/*
  Stage one VBLANK calculations entry. It performs the
  processing of a VBLANK interrupt. Contains JMP instruction for
  the vector in the next two addresses (58464, 58465; $E460,
  $E461). This is the address normally found in VVBLKI (546, 547;
  $222, $223). It is initialized to 59345 ($E7D1), which is the
  VBLANK routine entry. Initialized to 59345 ($E7D1) old ROMs,
  59310 ($E7AE) new ROMs.
*/
#define SYSVBV 0xE45F

/*
  Exit from the VBLANK routine, entry point. Contains JMP to the
  address stored in next two locations (58467, 58468; $E463,
  $E464). This is the address normally found in VVBLKD (548, 549;
  $224, $225). Initialized to 59710 ($E93E), which is the VBLANK
  exit routine. It is used to restore the computer to its pre-interrupt
  state and to resume normal processing. Initialized to 59710
  ($E93E) old ROMs, 59653 ($E905) new ROMs.
*/
#define XITVBV 0xE462

/*
  Warmstart entry point (RESET button vector). Initializes the OS
  RAM region. The RESET key produces an NMI interrupt and a
  chip reset (see below). Jump to here on an NMI caused by
  pressing the RESET key. Initialized to 61723 ($F11B).
*/
#define WARMSV 0xE474

/*
  Coldstart (powerup) entry point. Initializes the OS and user RAM
  regions; wipes out any program in memory. Initialized to 61733
  ($F125).
*/
#define COLDSV 0xE477

/* -- The following are the addresses for the handler routines -- */

/*
  Addresses for the Central Input/Output routines (CIO):
  0xE4A6 - 0xE6D4
*/
#define CIOORG 0xE4A6

/*
  CIO initialization routine called by the monitor on powerup
*/
#define CIOINT 0xE4A6

/*
  move the user IOCB to the ZIOCB
*/
#define _CIO_MOVE_USER_IOCB_TO_ZIOCB 0xE4D1

/*
  check for a valid command
*/
#define _CIO_CHECK_VALID_CMD 0xE4E4

/*
  OPEN command routines.
*/
#define CIOPEN 0xE509

/*
  CLOSE command routines.
*/
#define CICLOS 0xE533

/*
  STATUS and special command routines.
*/
#define CISTSP 0xE54E

/*
  process the CIO commands for read and
  write, including buffer check for full or empty.
  GET routine (GET character and GET record).
*/
#define CIREAD 0xE569

/*
  PUT routine (PUT character and PUT record). 
*/
#define CIWRIT 0xE5C9

/*
  routine to return to the user from CIO.
  Return from CIO with the status in the Y register.
*/
#define CIRTN1 0xE61B

/*
  Return from CIO with the status in ICSTAZ (35).
*/
#define CIRTN2 0xE61D

/*
  Compute the handler entry point using HATABS (794) and COMTAB (59081).
*/
#define COMENT 0xE63D

/*
  routines to compute the device handler entry point,
  jump to the handler, transfer control, and then return to CIO after the
  operation.

  Jump indirectly to the device handler. An indirect jump, in this case,
  means fooling the 6502 into thinking that the address you want to jump
  to is actually the one you want to RTS to. This involves playing with
  the stack and is a pretty neat trick you may want to look at.
*/
#define GOHAND 0xE689



/* Addresses for the interrupt handler routines:
   0xE6D5 - 0xE943 */

#define INTORG 0xE6D5

/* FIXME
59123 ($E6F3) PIRQ;
IRQ interrupt service routines start here.

59126 ($E6F6);
the immediate IRQ vector to the IRQ handler. The
global NMI and IRQ RAM vectors in locations 512 to 527 ($200 to $20F)
are all initialized to this area (59142, $E706 for the new OS ROMs).

59314 ($E7B2);
the vector for the IRQ interrupts on powerup; it
points to a PLA and RTI instruction sequence (new OS ROMs; 59219;
$E78F).

59316 ($E7B4) PNMI;
the NMI handler, tests for the reason for the
NMI, then jumps through the appropriate RAM vector. Also called the
Interrupt Service Routine (ISR).

59345 ($E7D1) SYSVBL;
the VBLANK routines start here,
including frame counter, update timer, update hardware registers
from shadow registers, update the attract mode counter and the
realtime clock. The vertical blank immediate vector, VVBLKL1,
normally pointed to by locations 546, 547 ($222, $223), points to here.
The Updated OS ROMs point to 59310 ($E7AE).

59666 ($E912) SETVBL;
subroutines to set the VBLANK timers
and vectors.

The vertical blank deferred interrupt, normally vectored from
locations 548, 549 ($224, $225), points to 59710 ($E93E). In the
Updated OS ROMs, it points to 59653 ($E905). In both cases they point
to the VBLANK exit routine.

See page 104 of the OS User's Manual for a list of the vectors and
MICRO, January 1982, for an explanation of the VBLANK process.
*/

/* Routines for the Serial Input/Output (SIO) routines:
   0xE944 - 0xEDE9 */

#define SIOORG 0xE944

/* FIXME
60011 ($EA6B) SEND;
is the SIO send buffer routine entry.

60048 ($EA90) ISRODN,
is the serial output ready IRQ vector.

60113 ($EAD1) ISRTD;
is the serial output complete IRQ vector.
This is at 60111 ($EACF) in the new OS ROMs.

60177 ($EB11) ISRSIR;
is the serial input ready IRQ vector. This
is 60175 ($EB0F) in the new OS ROMs.

60292 ($EB84) CASENT;
is the start of the cassette handling code
SIO subroutine to set baud rate, tone values, inter-record gap, to load
the buffer from the cassette and to turn on the recorder motor. Write
routines are located in 61249 to 61666 ($EFF5 to $F0E2).

60515 ($EC63)
is the start of the disable POKEY interrupts routine
entry, which also disables the send and receive functions.

60583 ($ECA7) COMPUT;
is the subroutine to calculate baud
rate using the POKEY frequency registers and the VCOUNT timer.
The tables for the AUDF and VCOUNT values are between 60882 and
60905 ($EDD2 and $EDE9).
*/

/* Routines for the disk handler.
   Initialization is at DINIT, 60906 ($EDEA), entry is at DSKIF, 60912
   ($EDF0).

   0xEDEA-0xEE77 */
#define DSKORG 0xEDEA
/* FIXME: Check MMM */

/* FIXME
61048-61248          	EE78-EF40          	PRNORG
Routines for the printer handler.

61249-61666          	EF41-F0E2          	CASORG
Routines for the cassette handler.

The buzz used in the cassette CLOAD command can be called up from
BASIC by:

BUZZ = USR(61530).

You can turn it off with the RESET key. While this isn't terribly
exciting, it points to the potential of using the console speaker for
sound instead of merely for beeps (the RAM location for the speaker is
at 53279; $D01F). See the speaker location and COMPUTE!, August
1981, for a short routine to use the speaker for sound effects.


61667-62435          	F0E3-F3E3          	MONORG
Routines for the monitor handler. This is also the address area of
PWRUP, the powerup module (61733; $F125). Coldstart routines are
initialized to this location. The routine to check for cartridge
installation begins at 61845 ($F195). Hardware initialization begins at
62081 ($F281).

61723 ($F11B) RESET;
the RESET button routine starts here.

62081 ($F281) HARDI,
the start of the hardware initialization
routines.

62100 ($F294) OSRAM;
the start of the OS RAM initialization
and setup routines.

62159 ($F2CF) BOOT;
the entry point for the disk boot routine.

62189 ($F2ED) DOBOOT;
the disk boot routine activation.

62334 ($F37E) DOPEN;
the entry point for the reinitialization
of disk software.

62436-65535          	F3E4-FFFF          	KBDORG
     Routines for the display and keyboard handler. The display
     handler beqins at 62454 ($F3F6) and the keyboard handler
     begins at 63197 ($F6DD), below.

63038          	F63E          	EGETCH
     Like the BASIC INPUT command, EGETCH gets a line from the
     screen and keyboard, but only one character at a time. You must
     do a JSR $F63E for each character input. This is also the address
     of the beginning of the screen editor routines.

63140          	F6A4          	EOUTCH
     This routine puts the character currently in the accumulator onto
     the screen in the next print location. Similar to the BASIC PUT
     command.

63197          	F6DD          	KGETC2
     Beginning of the keyboard handler.

63202          	F6E2          	KGETCH
     This routine waits for a key to be pressed and returns its value to
     the accumulator (6502 register A). Similar to the BASIC GET
     command.

64428          	FBAC          	SCROLL
     The screen scroll routine starts here.

64764          	FCFC          	DRAW
     Screen draw routines begin here, end at 65092 ($FE44). See
     Creative Computing, March 1982, for an example of a
     modification to the draw routines to avoid the "out-of-bounds"
     error for use in GR.7+.

65093-469          	FE45-FFBD          	....
     The ROM tables for display lists, ANTIC codes, control codes,
     and ATASCII conversion codes.

65470          	FFBE          	PIRQQ
     Subroutines to test the acceptance of the last key pressed and to
     process the debounce delay routines start here.
     When a key is pressed, it initiates an IRQ through VKEYBD at
     locations 520, 521 ($208, $209) to 65470 ($FFBE). This is the
     keyboard service routine. It processes debounce, and SHIFT-
     CTRL logic (see location 559; $22F); saves the internal keyboard
     code in 754 ($2F2) and 764 ($2FC); sets the ATTRACT mode flag
     at 77 ($4D) and sets location 555 ($22B -- SRTIMR) to 48 ($30).

65528          	FFF8          	CHKSUN
     According to Softside Magazine, December 1981, if a PEEK here
     returns 255, then you have the older OS ROM(s). There were
     some troubles with cassette loads in the older ROMs that
     sometimes require the following to cure:

     Do an LPRINT without a printer attached before CLOAD. This
     clears the cassette buffer.

     Press RESET before CSAVEing or CLOADing will restore the
     system to its initialization parameters and help with loading and
     saving routines.

     There is a new OS available from Atari which fixes a bug that
     would cause the I/O operations to "time out" for a few seconds. It
     apparently does not alter any of the routines mentioned here.

     The chip reset interrupt (powerup) vectors through location
     65532 ($FFFC) to 58487 ($E477) where a JMP vector to the
     powerup routine is located. A chip reset is not the same as
     pressing the RESET key, which in itself does not generate a chip
     reset.

     The NMI interrupts are vectored through 65530 ($FFFA) to the
     NMI service routine (ISR) at 59316 ($E7B4), and all IRQ
     interrupts are vectored through 65534 ($FFFE) to the IRQ service
     routine at 59123 ($E6F3). In these service routine areas, the
     cause of the interrupt is determined, and the appropriate action
     is taken, either by the OS or through a JMP to a RAM vector
     where a user routine exists.
*/

#endif /* _OS_H */

