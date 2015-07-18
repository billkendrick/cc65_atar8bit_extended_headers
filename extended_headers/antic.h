/*****************************************************************************/
/*                                                                           */
/*                                antic.h                                    */
/*                                                                           */
/*                  Internal include file, do not use directly               */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/* Updates, 2015 by Bill Kendrick <bill@newbreedsoftware.com>                */
/* Original:                                                                 */
/* (C) 2000 Freddy Offenga <taf_offenga@yahoo.com>                           */
/* 24-Jan-2011: Christian Krueger: Added defines for Antic instruction set   */
/*                                                                           */
/*                                                                           */
/* This software is provided 'as-is', without any expressed or implied       */
/* warranty.  In no event will the authors be held liable for any damages    */
/* arising from the use of this software.                                    */
/*                                                                           */
/* Permission is granted to anyone to use this software for any purpose,     */
/* including commercial applications, and to alter it and redistribute it    */
/* freely, subject to the following restrictions:                            */
/*                                                                           */
/* 1. The origin of this software must not be misrepresented; you must not   */
/*    claim that you wrote the original software. If you use this software   */
/*    in a product, an acknowledgment in the product documentation would be  */
/*    appreciated but is not required.                                       */
/* 2. Altered source versions must be plainly marked as such, and must not   */
/*    be misrepresented as being the original software.                      */
/* 3. This notice may not be removed or altered from any source              */
/*    distribution.                                                          */
/*                                                                           */
/*****************************************************************************/


#ifndef _ANTIC_H
#define _ANTIC_H

/* Define a structure with the antic register offsets */
struct __x_antic {
    unsigned char   dmactl; /* direct memory access control */
#define SDMCTL *(unsigned char *) 0x22F /* Direct Memory Access (DMA) enable */
/* Playfield modes: */
#define DMACTL_NO_PF     0x00
#define DMACTL_NARROW_PF 0x01
#define DMACTL_NORMAL_PF 0x02
#define DMACTL_WIDE_PF   0x03

/* Other options: */
#define DMACTL_MISSILE_DMA    0x04
#define DMACTL_PLAYER_DMA     0x08
#define DMACTL_SINGLELINE_PMG 0x10
#define DMACTL_DMA_FETCH      0x20

    unsigned char   chactl; /* character mode control */
#define CHACT *(unsigned char *) 0x2F3 /* Character Mode Register */
/* Inverted (upside-down) characters */
#define CHACTL_CHAR_NORMAL    0x00
#define CHACTL_CHAR_INVERTED  0x04
/* Inverse (reverse-video) characters */
#define CHACTL_INV_TRANS      0x00 /* chars with high-bit shown */
#define CHACTL_INV_OPAQUE     0x01 /* chars with high-bit appear as space */
#define CHACTL_INV_PRESENT    0x02 /* chars with high-bit are reverse-video */
/* N.B. Default is "CHACTL_CHAR_NORMAL | CHACTL_INV_PRESENT", aka decimal 2 */


    unsigned char   dlistl; /* display list pointer low-byte */
    unsigned char   dlisth; /* display list pointer high-byte */
#define SDLSTL *(unsigned char *) 0x230 /* Starting address of the display list */
#define SDLSTH *(unsigned char *) 0x231
#define SDLST *(unsigned int *) 0x230 /* (convenience) */

    unsigned char   hscrol; /* horizontal scroll enable (see DL_HSCROL) */
    unsigned char   vscrol; /* vertical scroll enable (see DL_VSCROL) */

    unsigned char   unuse0; /* unused */
    
    unsigned char   pmbase; /* msb of p/m base address */

    unsigned char   unuse1; /* unused */
    
    unsigned char   chbase; /* character base address */
#define CHBAS *(unsigned char *) 0x2F4 /* Character Base Register */
#define CHBASE_DEFAULT 0xE0 /* Location of OS ROM default character set */
#define CHBASE_DEFAULT_LOWERCASE 0xE2 /* Location of OS ROM default character set (for lowercase, used only by GRAPHICS 1 & 2) */

    unsigned char   wsync;  /* wait for horizontal synchronization (see also: vcount) */
    unsigned char   vcount; /* vertical line counter (see also: wsync) */

    unsigned char   penh;   /* light pen horizontal position */
    unsigned char   penv;   /* light pen vertical position */
#define LPENH *(unsigned char *) 234 /* Light pen horizontal value */
/* Horizontal positions are marked in color clocks. There are 228 horizontal 
   positions, numbered from 67 at the left. When the LPENH value reaches 255, it 
   is reset to 0 and begins counting again by 1 to the rightmost edge, which has
   a value of 7. */
#define LPENV *(unsigned char *) 235 /* Light pen vertical value */
/* The same values as VCOUNT register for two-line resolution */

    unsigned char   nmien;  /* non-maskable interrupt (nmi) enable */
#define NMIEN_DLI   0x80 /* see also: DL_DLI */
#define NMIEN_VBI   0x40
#define NMIEN_RESET 0x20

    unsigned char   nmires; /* nmi reset/status (Reset for NMIST) */
#define NMIST *(unsigned char *) 0xD40F /* (R) NMI status */
/* holds cause for the NMI interrupt in bits 5, 6 and 7;
   corresponding to the same bits in NMIEN above. */
};


/* antic instruction set */

/* absolute instructions (non mode lines) */
#define DL_JMP  1
#define DL_JVB  65

/* absolute instructions (blank lines) */
#define DL_BLK1 0
#define DL_BLK2 16
#define DL_BLK3 32
#define DL_BLK4 48
#define DL_BLK5 64
#define DL_BLK6 80
#define DL_BLK7 96
#define DL_BLK8 112

/* absolute instructions (mode lines) */
#define DL_CHR40x8x1    2   /* monochrome, 40 character & 8 scanlines per mode line (GR. 0) */
#define DL_CHR40x10x1   3   /* monochrome, 40 character & 10 scanlines per mode line (GR.0 with true descenders) */
#define DL_CHR40x8x4    4   /* colour, 40 character & 8 scanlines per mode line (GR. 12) */
#define DL_CHR40x16x4   5   /* colour, 40 character & 16 scanlines per mode line (GR. 13) */
#define DL_CHR20x8x2    6   /* colour (duochrome per character), 20 character & 8 scanlines per mode line (GR. 1) */
#define DL_CHR20x16x2   7   /* colour (duochrome per character), 20 character & 16 scanlines per mode line (GR. 2) */

#define DL_MAP40x8x4    8   /* colour, 40 pixel & 8 scanlines per mode line (GR. 3) */
#define DL_MAP80x4x2    9   /* 'duochrome', 80 pixel & 4 scanlines per mode line (GR.4) */
#define DL_MAP80x4x4    10  /* colour, 80 pixel & 4 scanlines per mode line (GR.5) */
#define DL_MAP160x2x2   11  /* 'duochrome', 160 pixel & 2 scanlines per mode line (GR.6) */
#define DL_MAP160x1x2   12  /* 'duochrome', 160 pixel & 1 scanline per mode line (GR.14) */
#define DL_MAP160x2x4   13  /* 4 colours, 160 pixel & 2 scanlines per mode line (GR.7) */
#define DL_MAP160x1x4   14  /* 4 colours, 160 pixel & 1 scanline per mode line (GR.15) */
#define DL_MAP320x1x1   15  /* monochrome, 320 pixel & 1 scanline per mode line (GR.8) */

/* FIXME: #define as GRAPHICS mode values, too? */
/* FIMXE: #define bits-per-pixel for each, too? */
/* FIXME: #define bytes-per-row for each, too? */
/* FIXME: #define resolution (W x H) for each, too? */

/* modifiers on mode lines */
#define DL_HSCROL       16
#define DL_VSCROL       32
#define DL_LMS          64

/* general modifier */
#define DL_DLI          128

/* RAM vector for Display List Interrupts:
   The vector for NMI Display List Interrupts (DLI): containing the
   address of the instructions to be executed during a DLI (DLI's are
   used to interrupt the processor flow for a few microseconds at the
   particular screen display line where the bit was set, allowing you
   to do another short routine such as music, changing graphics
   modes, etc.). The OS doesn't use DLI's; they must be user-
   enabled, written and vectored through here. The NMI status
   register at 54287 ($D40F) first tests to see if an interrupt was
   caused by a DLI and, if so, jumps through VDSLST to the routine
   written by the user. DLI's are disabled on powerup, but VBI's are
   enabled (see 546 to 549; $222 to $225).
*/
#define VDSLST *(unsigned int *) 0x200

/* Macros for the beginning and end of DLI functions */
#define DLI_START asm("pha"); asm("txa"); asm("pha"); asm("tya"); asm("pha");
#define DLI_END asm("pla"); asm("tay"); asm("pla"); asm("tax"); asm("pla"); asm("rti");

/* End of antic.h */
#endif /* #ifndef _ANTIC_H */

