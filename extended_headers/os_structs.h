#ifndef _OS_STRUCTS_H
#define _OS_STRUCTS_H

/* I/O control block (taken from cc65 atari.h) */
struct ___iocb {
    unsigned char handler;    /* ICHID: handler index number (0xff free) */
    unsigned char drive;      /* ICDNO: device number (drive) */
    unsigned char command;    /* ICCOM: command */
    unsigned char status;     /* ICSTA: status of last operation */
    void          *buffer;    /* ICBAL/H: pointer to buffer */
    void          *put_byte;  /* ICPTL/H: pointer to device's PUT BYTE routine */
    unsigned int  buflen;     /* ICBLL/H: length of buffer */
    unsigned char aux1;       /* ICAX1: 1st auxiliary byte */
    unsigned char aux2;       /* ICAX2: 2nd auxiliary byte */
    unsigned char aux3;       /* ICAX3: 3rd auxiliary byte */
    unsigned char aux4;       /* ICAX4: 4th auxiliary byte */
    unsigned char aux5;       /* ICAX5: 5th auxiliary byte */
    unsigned char spare;      /* ICAX6: spare byte */
};

/* IOCB Command Codes (based on cc65's atari.h) */
#define IOCB_OPEN        0x03  /* open channel */
#define IOCB_GETREC      0x05  /* get record (line) */
#define IOCB_GETCHR      0x07  /* get character(s) */
#define IOCB_PUTREC      0x09  /* put record (line) */
#define IOCB_PUTCHR      0x0B  /* put character(s) */
#define IOCB_CLOSE       0x0C  /* close */
#define IOCB_STATUS      0x0D  /* status */
#define IOCB_SPECIAL     0x0E  /* special */
#define IOCB_DRAWLINE    0x11  /* draw line (S: only) */
#define IOCB_FILLLINE    0x12  /* draw line with right fill (S: only) */
#define IOCB_RENAME      0x20  /* rename disk file */
#define IOCB_OUT_PARTIAL 0x20  /* output partial block (R: only) */
#define IOCB_DELETE      0x21  /* delete disk file */
#define IOCB_CONTROL     0x22  /* control RTS,XMT,DTR */
#define IOCB_LOCK        0x23  /* lock file (set to read-only) */
#define IOCB_UNLOCK      0x24  /* unlock file */
#define IOCB_BAUD        0x24  /* baud, stop bits, word size (R: only) */ /* FIXME: Better name? */
#define IOCB_POINT       0x25  /* point sector */
#define IOCB_NOTE        0x26  /* note sector */
#define IOCB_TRANS_MODE  0x26  /* translation mode (R: only) */
#define IOCB_GETLEN      0x27  /* get file length */
#define IOCB_CONCURRENT  0x28  /* concurrent mode (R: only) */
#define IOCB_CHDIR_MYDOS 0x29  /* change directory (MyDOS) */
#define IOCB_MKDIR       0x2A  /* make directory (MyDOS/SpartaDOS) */
#define IOCB_RMDIR       0x2B  /* remove directory (SpartaDOS) */
#define IOCB_CHDIR_SPDOS 0x2C  /* change directory (SpartaDOS) */
#define IOCB_GETCWD      0x30  /* get current directory (MyDOS/SpartaDOS) */
#define IOCB_FORMAT      0xFE  /* format */
/* Note: CIO treats any command byte value greater than 13 ($D) as
   a special case, and transfers control over to the device handler for
   processing. */

/* FIXME: Fill these in */

/* General commands */
#define IOCB_AUX1_OPEN_APPEND    0x01
#define IOCB_AUX1_OPEN_READ      0x04
#define IOCB_AUX1_OPEN_WRITE     0x08

/* D: commands */
#define IOCB_AUX1_DISK_OPEN_DIRECTORY 0x02
#define IOCB_AUX1_DISK_FORMAT_SINGLE   0x00 /* Atari DOS 2.5 format single density */
#define IOCB_AUX1_DISK_FORMAT_ENHANCED 0x22 /* Atari DOS 2.5 format enhanced density */

/* S: commands */
/* FIXME: is this right? also, what's "read operation"? */
#define IOCB_AUX1_SCREEN_OPEN_NOTEXTWINDOW 0x10
#define IOCB_AUX1_SCREEN_OPEN_NOCLEAR      0x20

#endif /* _OS_STRUCTS_H */
