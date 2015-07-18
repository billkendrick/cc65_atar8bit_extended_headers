/*****************************************************************************/
/*                                                                           */
/*                                 pokey.h                                   */
/*                                                                           */
/*                Internal include file, do not use directly                 */
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



#ifndef _POKEY_H
#define _POKEY_H



/* Define a structure with the pokey register offsets */
struct __x_pokey_write {
    unsigned char   audf1;  /* audio channel #1 frequency */
    unsigned char   audc1;  /* audio channel #1 control */
    unsigned char   audf2;  /* audio channel #2 frequency */
    unsigned char   audc2;  /* audio channel #2 control */
    unsigned char   audf3;  /* audio channel #3 frequency */
    unsigned char   audc3;  /* audio channel #3 control */
    unsigned char   audf4;  /* audio channel #4 frequency */
    unsigned char   audc4;  /* audio channel #4 control */
/* The values for the distortion bits are as follows. The first process is
   to divide the clock value by the frequency, then mask the output
   using the polys in the order below. Finally, the result is divided by two */
#define AUDC_POLYS_5_17 0x00
#define AUDC_POLYS_5    0x20 /* Same as 0x60 */
#define AUDC_POLYS_5_4  0x40
#define AUDC_POLYS_17   0x80
#define AUDC_POLYS_NONE 0xA0 /* Same as 0xE0 */
#define AUDC_POLYS_4    0xC0

#define AUDC_VOLUME_ONLY 0x10

    unsigned char   audctl; /* audio control */
#define AUDCTL_CLOCKBASE_15HZ 0x01 /* Switch main clock base from 64 KHz to 15 KHz */
#define AUDCTL_HIGHPASS_CHAN2 0x02 /* Insert high pass filter into channel two, clocked by channel four */
#define AUDCTL_HIGHPASS_CHAN1 0x04 /* Insert high pass filter into channel one, clocked by channel two */
#define AUDCTL_JOIN_CHAN34    0x08 /* Join channels four and three (16 bit) */
#define AUDCTL_JOIN_CHAN12    0x10 /* Join channels two and one (16 bit) */
#define AUDCTL_CLOCK_CHAN3_179MHZ 0x20 /* Clock channel three with 1.79 MHz */
#define AUDCTL_CLOCK_CHAN1_179MHZ 0x40 /* Clock channel one with 1.79 MHz */
#define AUDCTL_9BIT_POLY      0x80 /* Makes the 17 bit poly counter into nine bit poly (see also: RANDOM) */

    unsigned char   stimer; /* start pokey timers */
    
    unsigned char   skrest; /* reset serial port status reg. */
    /* Reset BITs 5 - 7 of the serial port status register at 53775 to one */
    
    unsigned char   potgo;  /* start paddle scan sequence (see "allpot") */
    
    unsigned char   unuse1; /* unused */

    unsigned char   serout; /* serial port data output */

    unsigned char   irqen;  /* interrupt request enable */
#define POKMSK *(unsigned char *) 0x10 /* POKEY interrupts: the IRQ service uses and alters this location */
#define IRQEN_TIMER_1 0x01 /* The POKEY timer one interrupt is enabled */
#define IRQEN_TIMER_2 0x02 /* The POKEY timer two interrupt is enabled */
#define IRQEN_TIMER_4 0x04 /* The POKEY timer four interrupt is enabled */
#define IRQEN_SERIAL_TRANS_FINISHED 0x08 /* The serial out transmission finished interrupt is enabled */
#define IRQEN_SERIAL_OUT_DATA_REQUIRED 0x10 /* The serial output data required interrupt is enabled */
#define IRQEN_SERIAL_IN_DATA_READY 0x20 /* The serial input data ready interrupt is enabled. */
#define IRQEN_OTHER_KEY 0x40 /* The "other key" interrupt is enabled */
#define IRQEN_BREAK_KEY 0x80 /* The BREAK key is enabled */

    unsigned char   skctl;  /* serial port control */
#define SKCTL_KEYBOARD_DEBOUNCE 0x01 /* Enable keyboard debounce circuits */
#define SKCTL_KEYBOARD_SCANNING 0x02 /* Enable keyboard scanning circuit */
#define SKCTL_FAST_POT_SCAN 0x04 /* Fast pot scan */
/* the pot scan counter completes its sequence in two TV line times instead of 
   one frame time (228 scan lines). Not as accurate as the normal pot scan */
#define SKCTL_TWO_TONE_MODE 0x08 /* Serial output is transmitted as a two-tone 
signal rather than a logic true/false. POKEY two-tone mode. */
/* Serial port mode control used to set the bi-directional clock lines */
#define SKCTL_BIT4 0x10 /* FIXME; more meaningful name */
#define SKCTL_BIT5 0x20 /* FIXME; more meaningful name */
#define SKCTL_BIT6 0x40 /* FIXME; more meaningful name */
#define SKCTL_FORCE_BREAK 0x80 /* Force break (serial output to zero) */
};

struct __x_pokey_read {
/* Paddle values; a number between zero and 228 ($E4),
   increasing as the knob is turned counter-clockwise */
    unsigned char   pot0;   /* paddle 0 value */
    unsigned char   pot1;   /* paddle 1 value */
    unsigned char   pot2;   /* paddle 2 value */
    unsigned char   pot3;   /* paddle 3 value */
    unsigned char   pot4;   /* paddle 4 value */
    unsigned char   pot5;   /* paddle 5 value */
    unsigned char   pot6;   /* paddle 6 value */
    unsigned char   pot7;   /* paddle 7 value */
#define PADDL0 *(unsigned char *) 0x270
#define PADDL1 *(unsigned char *) 0x271
#define PADDL2 *(unsigned char *) 0x272
#define PADDL3 *(unsigned char *) 0x273
#define PADDL4 *(unsigned char *) 0x274
#define PADDL5 *(unsigned char *) 0x275
#define PADDL6 *(unsigned char *) 0x276
#define PADDL7 *(unsigned char *) 0x277

    unsigned char   allpot; /* eight paddle port status (see "potgo") */

    unsigned char   kbcode; /* keyboard code */
#define CH *(unsigned char *) 0x2FC /* Internal hardware value for the last key pressed. */

/* Internal key codes from http://www.atariarchives.org/c3ba/page004.php */
/* (Note: Numerous Shift+Ctrl+key combos are unavailable) */

#define KEYCODE_NONE 255 /* 255 = no key pressed (but is also same as Ctrl+Shift+A) */

/* Fx keys only available on 1200XL */
#define KEYCODE_F1 3
#define KEYCODE_F2 4
#define KEYCODE_F3 19
#define KEYCODE_F4 20

/* HELP key only available on XL/XE */
#define KEYCODE_HELP 17

#define KEYCODE_ESC 28
#define KEYCODE_1 31
#define KEYCODE_2 30
#define KEYCODE_3 26
#define KEYCODE_4 24
#define KEYCODE_5 29
#define KEYCODE_6 27
#define KEYCODE_7 51
#define KEYCODE_8 53
#define KEYCODE_9 48
#define KEYCODE_0 50
#define KEYCODE_LT 54
#define KEYCODE_GT 55
#define KEYCODE_BKSPC 52

#define KEYCODE_TAB 44
#define KEYCODE_Q 47
#define KEYCODE_W 46
#define KEYCODE_E 42
#define KEYCODE_R 40
#define KEYCODE_T 45
#define KEYCODE_Y 43
#define KEYCODE_U 11
#define KEYCODE_I 13
#define KEYCODE_O 8
#define KEYCODE_P 10
#define KEYCODE_MINUS 14
#define KEYCODE_EQUALS 15
#define KEYCODE_RETURN 12

#define KEYCODE_CTRL 128 /* binary OR'd */

#define KEYCODE_A 63
#define KEYCODE_S 62
#define KEYCODE_D 58
#define KEYCODE_F 56
#define KEYCODE_G 61
#define KEYCODE_H 57
#define KEYCODE_J 1
#define KEYCODE_K 5
#define KEYCODE_L 0
#define KEYCODE_; 2
#define KEYCODE_PLUS 6
#define KEYCODE_ASTERISK 7
#define KEYCODE_CAPS 60

#define KEYCODE_SHIFT 64 /* binary OR'd */

#define KEYCODE_Z 23
#define KEYCODE_X 22
#define KEYCODE_C 18
#define KEYCODE_V 16
#define KEYCODE_B 21
#define KEYCODE_N 35
#define KEYCODE_M 37
#define KEYCODE_COMMA 32
#define KEYCODE_PERIOD 34
#define KEYCODE_SLASH 38
#define KEYCODE_FUJI 39 /* (as seen on 400/800) */
#define KEYCODE_INVERSE 39 /* (alternative name; as seen on XL/XE) */

#define KEYCODE_SPACE 33

    unsigned char   random; /* random number generator */

    unsigned char   unuse2; /* unused */
    unsigned char   unuse3; /* unused */

    unsigned char   serin;  /* serial port input (see also: CHKSUM) */

    unsigned char   irqst;  /* interrupt request status */
/* Bit functions are the same as IRQEN except that they register the interrupt 
   request when it is zero rather than the enable when a bit equals one. */

    unsigned char   skstat; /* serial port status */
#define SKSTAT_SERIN_SHIFTREG_BUSY 0x02 /* Serial input shift register busy */
#define SKSTAT_LASTKEY_PRESSED 0x04 /* the last key is still pressed */
#define SKSTAT_SHIFTKEY_PRESSED 0x08 /* the [Shift] key is pressed */
#define SKSTAT_DATA_READ_INGORING_SHIFTREG 0x10 /* Data can be read directly from the serial input port, ignoring the shift register. */
#define SKSTAT_KEYBOARD_OVERRUN 0x20 /* Keyboard over-run; Reset BITs 7, 6 and 5 (latches) to 1, using SKREST */
#define SKSTAT_INPUT_OVERRUN 0x40 /* Serial data input over-run. Reset latches as above. */
#define SKSTAT_INPUT_FRAMEERROR 0x80 /* Serial data input frame error caused by missing or extra bits. Reset latches as above. */          
};

/* End of pokey.h */
#endif /* #ifndef _POKEY_H */
