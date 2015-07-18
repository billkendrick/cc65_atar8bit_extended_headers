/*****************************************************************************/
/*                                                                           */
/*                                 gtia.h                                    */
/*                                                                           */
/*                  Internal include file, do not use directly               */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/* Updates, 2015 by Bill Kendrick <bill@newbreedsoftware.com>                */
/* Original:                                                                 */
/* (C) 2000 Freddy Offenga <taf_offenga@yahoo.com>                           */
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


#ifndef _GTIA_H
#define _GTIA_H

/* Define a structure with the gtia register offsets */
struct __x_gtia_write {
    unsigned char   hposp0; /* horizontal position player 0 */
    unsigned char   hposp1; /* horizontal position player 1 */
    unsigned char   hposp2; /* horizontal position player 2 */
    unsigned char   hposp3; /* horizontal position player 3 */
    unsigned char   hposm0; /* horizontal position missile 0 */
    unsigned char   hposm1; /* horizontal position missile 1 */
    unsigned char   hposm2; /* horizontal position missile 2 */
    unsigned char   hposm3; /* horizontal position missile 3 */
    unsigned char   sizep0; /* size of player 0 */
    unsigned char   sizep1; /* size of player 1 */
    unsigned char   sizep2; /* size of player 2 */
    unsigned char   sizep3; /* size of player 3 */
    unsigned char   sizem;  /* size of missiles */
    unsigned char   grafp0; /* graphics shape player 0 */
    unsigned char   grafp1; /* graphics shape player 1 */
    unsigned char   grafp2; /* graphics shape player 2 */
    unsigned char   grafp3; /* graphics shape player 3 */
    unsigned char   grafm;  /* graphics shape missiles */

    unsigned char   colpm0; /* color player and missile 0 */
    unsigned char   colpm1; /* color player and missile 1 */
    unsigned char   colpm2; /* color player and missile 2 */
    unsigned char   colpm3; /* color player and missile 3 */
    unsigned char   colpf0; /* color playfield 0 */
    unsigned char   colpf1; /* color playfield 1 */
    unsigned char   colpf2; /* color playfield 2 */
    unsigned char   colpf3; /* color playfield 3 */
    unsigned char   colbk;  /* color background */
#define PCOLR0 *(unsigned char *) 0x2C0
#define PCOLR1 *(unsigned char *) 0x2C1
#define PCOLR2 *(unsigned char *) 0x2C2
#define PCOLR3 *(unsigned char *) 0x2C3
#define COLOR0 *(unsigned char *) 0x2C4
#define COLOR1 *(unsigned char *) 0x2C5
#define COLOR2 *(unsigned char *) 0x2C6
#define COLOR3 *(unsigned char *) 0x2C7
#define COLOR4 *(unsigned char *) 0x2C8
    
    unsigned char   prior;  /* priority selection */
    unsigned char   vdelay; /* vertical delay */
    unsigned char   gractl; /* stick/paddle latch, p/m control */
    unsigned char   hitclr; /* clear p/m collision */
    unsigned char   consol; /* console buttons */
};

/* Define a structure with the gtia register offsets */
struct __x_gtia_read {
    unsigned char   m0pf;   /* missile 0 to playfield collision */
    unsigned char   m1pf;   /* missile 1 to playfield collision */
    unsigned char   m2pf;   /* missile 2 to playfield collision */
    unsigned char   m3pf;   /* missile 3 to playfield collision */
    unsigned char   p0pf;   /* player 0 to playfield collision */
    unsigned char   p1pf;   /* player 1 to playfield collision */
    unsigned char   p2pf;   /* player 2 to playfield collision */
    unsigned char   p3pf;   /* player 3 to playfield collision */
    unsigned char   m0pl;   /* missile 0 to player collision */
    unsigned char   m1pl;   /* missile 1 to player collision */
    unsigned char   m2pl;   /* missile 2 to player collision */
    unsigned char   m3pl;   /* missile 3 to player collision */
    unsigned char   p0pl;   /* player 0 to player collision */
    unsigned char   p1pl;   /* player 1 to player collision */
    unsigned char   p2pl;   /* player 2 to player collision */
    unsigned char   p3pl;   /* player 3 to player collision */
    unsigned char   trig0;  /* joystick trigger 0 */
    unsigned char   trig1;  /* joystick trigger 1 */
    unsigned char   trig2;  /* joystick trigger 2 */
    unsigned char   trig3;  /* joystick trigger 3 */
    unsigned char   pal;    /* pal/ntsc flag */
};

/* End of gtia.h */
#endif /* #ifndef _GTIA_H */
