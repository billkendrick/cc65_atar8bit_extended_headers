/* 2015 by Bill Kendrick <bill@newbreedsoftware.com> */
/* Notes from http://www.atariarchives.org/mapping/memorymap.php */

/*
  Locations 512 to 1151 ($200 to $47F) are used by the OS for working
  variables, tables and data buffers. In this area, locations 512 to 553
  ($200 to $229) are used for interrupt vectors, and locations 554 to 623
  ($22A to $26F) are for miscellaneous use. Much of pages two through
  five cannot be used except by the OS unless specifically noted. A
  number of bytes are marked as "spare", i.e., not in use currently. The
  status of these bytes may change with an Atari upgrade, so their use is
  not recommended.
  
  Locations 768 to 831 ($300 to $33F) are used for the device handler and
  vectors to the handler routines (devices S:, P:, E:, D:, C:, R: and K:).
  A device handler is a routine used by the OS to control the transfer of
  data in that particular device for the task allotted (such as read, write,
  save, etc.). The resident D: handler does not conform entirely with the
  other handler--SIO calling routines. Instead, you use the DCB to
  communicate directly with the disk handler. The device handler for R:
  is loaded in from the 850 interface module. See De Re Atari, the 850
  Interface Manual, and the OS Listings pages 64 - 65.
  
  Locations 768 to 779 ($300 to $30B) are the resident Device Control
  Block (DCB) addresses, used for I/O operations that require the serial
  bus; also used as the disk DCB. DUP.SYS uses this block to interface
  the FMS with the disk handler. The Atari disk drive uses a serial access
  at 19,200 baud (about 20 times slower than the Apple!). It has its own
  microprocessor, a 6507, plus 128 bytes of RAM, a 2316 2K masked
  ROM chip (like a 2716), a 2332 RAM-I/O timer chip with another 128
  bytes of RAM (like the PIA chip) and a WD 1771 FD controller chip.
  See the "Outpost Atari" column, Creative Computing, May 1982, for
  an example of using the disk DCB.
  
  All of the parameters passed to SIO are contained in the DCB. SIO
  uses the DCB information and returns the status in the DCB for
  subsequent use by the device handler.
*/

#ifndef _PAGE3_H
#define _PAGE3_H

#include "os_structs.h"

/*
     Device serial bus ID (serial device type) set up by the handler,
     not user-alterable. Values are:

     Disk drives  D1 - D4   49-52   ($31-$34)
     Printer      P1           64       ($40)
     Printer      P2           79       ($4F)
     RS232 ports  R1-R4     80-83   ($50-$53)
*/
#define DDEVIC *(unsigned char *) 0x300

#define DEVICE_ID_D1 0x31
#define DEVICE_ID_D2 0x32
#define DEVICE_ID_D3 0x33
#define DEVICE_ID_D4 0x34
/* Making assumptions, below ;) */
#define DEVICE_ID_D5 0x35
#define DEVICE_ID_D6 0x36
#define DEVICE_ID_D7 0x37
#define DEVICE_ID_D8 0x38
#define DEVICE_ID_D9 0x39
/* FIXME: should I go on to D15:, 0x3F? */

#define DEVICE_ID_P1 0x40
#define DEVICE_ID_P2 0x4F

#define DEVICE_ID_R1 0x80
#define DEVICE_ID_R2 0x81
#define DEVICE_ID_R3 0x82
#define DEVICE_ID_R4 0x83

/*
  Disk or device unit number: one to four, set up by the user.
*/
#define DUNIT *(unsigned char *) 0x301

/*
  The number of the disk or device operation (command) to be
  performed, set by the user or by the device handler prior to
  calling SIO. Serial bus commands are:

  Read             82    ($52)
  Write (verify)   87    ($57)
  Status           83    ($53)
  Put (no verify)  80    ($50)
  Format           33    ($21)
  Download         32    ($20)
  Read address     84    ($54)
  Read spin        81    ($51)
  Motor on         85    ($55)
  Verify sector    86    ($56)

  All of the above are disk device commands, except write and
  status, which are also printer commands (with no verify).
*/
#define DCOMND *(unsigned char *) 0x302

#define DEVICE_CMD_READ      0x52
#define DEVICE_CMD_WRITE     0x57
#define DEVICE_CMD_STATUS    0x53
#define DEVICE_CMD_PUT       0x50
#define DEVICE_CMD_FORMAT    0x21
#define DEVICE_CMD_DOWNLOAD  0x20
#define DEVICE_CMD_READ_ADDR 0x54
#define DEVICE_CMD_READ_SPIN 0x51
#define DEVICE_CMD_MOTOR_ON  0x55
#define DEVICE_CMD_VERIFY_SECTOR 0x56

/* FIXME 0x303-0x33F */

/*
  I/O Control Block (IOCB) zero. Normally used for the screen
  editor (E:).
*/
#define IOCB0 (*(struct ___iocb *)0x340)

/*
  Other IOCBs (not used by OS)
*/
#define IOCB1 (*(struct ___iocb *)0x350)
#define IOCB2 (*(struct ___iocb *)0x360)
#define IOCB3 (*(struct ___iocb *)0x370)
#define IOCB4 (*(struct ___iocb *)0x380)
#define IOCB5 (*(struct ___iocb *)0x390)

/*
  IOCB six. The GRAPHICS statement OPENs channel six for
  screen display (S:), so once you are out of mode zero, you cannot
  use channel six unless you first issue a CLOSE#6 statement. If
  you CLOSE this channel, you will not be able to use the
  DRAWTO, PLOT or LOCATE commands until you reOPEN the
  channel. The LOAD command closes channel six; it also closes
  all channels except zero.
*/
#define IOCB6 (*(struct ___iocb *)0x3A0)

/*
  IOCB seven. LPRINT automatically uses channel seven for its
  use. If the channel is OPEN for some other use and an LPRINT is
  done, an error will occur, the channel will be CLOSEd, and
  subsequent LPRINTs will work. The LIST command also uses
  channel seven, even if channel seven is already OPEN. However,
  when the LIST is done, it CLOSEs channel seven. The LOAD
  command uses channel seven to transfer programs to and from
  the recorder or disk. LIST (except to the display screen), LOAD
  and LPRINT also close all sound voices. The RUN from tape or
  disk and SAVE commands use channel seven, as does LIST.
  The bytes within each IOCB are used as follows:
*/
#define IOCB7 (*(struct ___iocb *)0x3B0)


/* End of page3.h */
#endif /* #ifndef _PAGE3_H */
