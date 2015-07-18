/* atascii.h */
/* 2015 by Bill Kendrick <bill@newbreedsoftware.com> */

#ifndef _ATASCII_H
#define _ATASCII_H

/* ATASCII codes

   CH_xxx are ATASCII codes & symbols in standard OS font
     (e.g., 0x00 = a heart symbol)

   CH_INTL_xxx are ATASCII codes & symbols in International OS font
     (e.g., 0x00 = á (small letter 'a' with acute))

   CH_ASCII_xxx are ASCII codes
     (e.g., 0x00 = NUL)

   Based on / thanks to:
    * http://joyfulcoder.net/atascii/
    * http://www.atariarchives.org/mapping/appendix10.php
    * http://www.the-liberator.net/site-files/retro-games/hardware/Atari-800-Rev-A-PAL/Atari-800-rev-a-pal/042-Atari-800-control-graphics-keyboard.JPG
    * http://newbreedsoftware.com/atari/linux2tbasicxl/

   FIXME: Under construction -bjk 2015.06.21
*/

/* ------------------------------------------------------------------------ */

/* ATASCII characters as numeric literals.
   e.g.,
     printf("%cHello world. Here's Escape char: %c%c\n",
            CH_CLR, CH_ESC, CH_ESC);
     if (i == CH_TAB) { ... }
*/

#define CH_HEART          0x00 /* heart suit (♥); [Ctrl]+[,] */
#define CH_INTL_A_ACUTE   0x00 /* lowercase a with actue (á) */
#define CH_ASCII_NUL      0x00 /* null */

#define CH_BOX_VERT_RIGHT 0x01 /* box vertical & right (├); [Ctrl]+[A] */
#define CH_INTL_U_GRAVE   0x01 /* lowercase u with grave (ù) */
#define CH_ASCII_SOH      0x01 /* start of heading */

#define CH_LINE_RIGHT     0x02 /* vertical line right (▕); [Ctrl]+[B] */
#define CH_INTL_CAP_N_TILDE 0x02 /* capital N with tilde (Ñ) */
#define CH_ASCII_STX      0x02 /* start of text */

#define CH_BOX_UP_LEFT    0x03 /* box up & left (┘); [Ctrl]+[C]  */
#define CH_INTL_CAP_E_ACUTE 0x03 /* capital E with acute (É) */
#define CH_ASCII_ETX      0x03 /* end of text */

#define CH_BOX_VERT_LEFT  0x04 /* box vertical & left (┤); [Ctrl]+[D]  */
#define CH_INTL_C_CEDIL   0x04 /* lowercase c with cedilla (ç) */
#define CH_ASCII_EOT      0x04 /* end of transmission */

#define CH_BOX_DOWN_LEFT  0x05 /* box down & left (┐); [Ctrl]+[E]  */
#define CH_INTL_O_CIRC    0x05 /* lowercase o with circumlex (ô) */
#define CH_ASCII_ENQ      0x05 /* enquiry */

#define CH_BOX_DIAG_UPPER_RIGHT_LOWER_LEFT 0x06 /* box diagonal upper right to lower left (╱); [Ctrl]+[F]  */
#define CH_INTL_O_GRAVE   0x06 /* lowercase o with grave (ò) */
#define CH_ASCII_ACK      0x06 /* acknowledge */

#define CH_BOX_DIAG_UPPER_LEFT_LOWER_RIGHT 0x07 /* box diagonal upper left to lower right (╲); [Ctrl]+[G]  */
#define CH_INTL_I_GRAVE   0x07 /* lowercase i with grave (ì) */
#define CH_ASCII_BEL      0x07 /* bell */

#define CH_TRI_LOWER_RIGHT 0x08 /* triangle lower right (◢); [Ctrl]+[H]  */
#define CH_INTL_POUND     0x08 /* pound (£) */
#define CH_ASCII_BS       0x08 /* backspace */

#define CH_BLOCK_LOWER_RIGHT 0x09 /* block lower right (▗); [Ctrl]+[I]  */
#define CH_INTL_I_DIA     0x09 /* lowercase i with diaeresis (ï) */
#define CH_ASCII_TAB      0x09 /* horizontal tab */

#define CH_TRI_LOWER_LEFT 0x0A /* triangle lower left (◣); [Ctrl]+[J]  */
#define CH_INTL_U_DIA     0x0A /* lowercase u with diaeresis (ü) */
#define CH_ASCII_LF       0x0A /* line feed (NL new line) */

#define CH_BLOCK_UPPER_RIGHT 0x0B /* block upper right (▝); [Ctrl]+[K]  */
#define CH_INTL_A_DIA     0x0B /* lowercase a with diaeresis (ä) */
#define CH_ASCII_VT       0x0B /* vertical tab */

#define CH_BLOCK_UPPER_LEFT 0x0C /* block upper left (▘); [Ctrl]+[L]  */
#define CH_INTL_CAP_O_DIA 0x0C /* capital O with diaeresis (Ö) */
#define CH_ASCII_FF       0x0C /* form feed (NP new page) */

#define CH_LINE_TOP       0x0D /* horizontal line top (▔); [Ctrl]+[M] */
#define CH_INTL_U_ACUTE   0x0D /* lowercase u with acute (ú) */
#define CH_ASCII_CR       0x0D /* carriage return */

#define CH_LINE_BOTTOM    0x0E /* horizontal line bottom (▁); [Ctrl]+[N]  */
#define CH_INTL_O_ACUTE   0x0E /* lowercase o with acute (ó) */
#define CH_ASCII_SO       0x0E /* shift out */

#define CH_BLOCK_LOWER_LEFT 0x0F /* block lower left (▖); [Ctrl]+[O]  */
#define CH_INTL_O_DIA     0x0F /* lowercase o with diaeresis (ö) */
#define CH_ASCII_SI       0x0F /* shift in */

#define CH_CLUB           0x10 /* club suit (♣); [Ctrl]+[P] */
#define CH_INTL_CAP_U_DIA 0x10 /* capital U with diaeresis (Ü) */
#define CH_ASCII_DLE      0x10 /* data link escape */

#define CH_BOX_DOWN_RIGHT 0x11 /* box down & right (┌); [Ctrl]+[Q]  */
#define CH_INTL_A_CIRC    0x11 /* lowercase a with circumflex (â) */
#define CH_ASCII_DC1      0x11 /* device control 1 */

#define CH_BOX_HORIZONTAL 0x12 /* box horizontal (─); [Ctrl]+[R]  */
#define CH_INTL_U_CIRC    0x12 /* lowercase u with circumflex (û) */
#define CH_ASCII_DC2      0x12 /* device control 2 */

#define CH_BOX_VERT_HORIZ 0x13 /* box vertical and horizontal (┼); [Ctrl]+[S]  */
#define CH_INTL_I_CIRC    0x13 /* lowercase i with circumflex (î) */
#define CH_ASCII_DC3      0x13 /* device control 3 */

#define CH_BALL           0x14 /* ball (●); [Ctrl]+[T]  */
#define CH_INTL_E_ACUTE   0x14 /* lowercase e with acute (é) */
#define CH_ASCII_DC4      0x14 /* device control 4 */

#define CH_BLOCK_LOWER    0x15 /* block lower half (▄); [Ctrl]+[U]  */
#define CH_INTL_E_GRAVE   0x15 /* lowercase e with grave (è) */
#define CH_ASCII_NAK      0x15 /* negative acknowledge */

#define CH_LINE_LEFT      0x16 /* vertical line left (▏); [Ctrl]+[V]  */
#define CH_INTL_N_TILDE   0x16 /* lowercase n with tilde (ñ) */
#define CH_ASCII_SYN      0x16 /* synchronous idle */

#define CH_BOX_HORIZ_DOWN 0x17 /* box horizontal & down (┬); [Ctrl]+[W]  */
#define CH_INTL_E_CIRC    0x17 /* lowercase e with circumflex (ê) */
#define CH_ASCII_ETB      0x17 /* end of transmission block */

#define CH_BOX_HORIZ_UP   0x18 /* box horizontal & up (┴); [Ctrl]+[X]  */
#define CH_INTL_A_DOT     0x18 /* lowercase a with dot (ȧ) */
#define CH_ASCII_CAN      0x18 /* cancel */

#define CH_BLOCK_LEFT     0x19 /* block left half (▌); [Ctrl]+[Y]  */
#define CH_INTL_A_GRAVE   0x19 /* lowercase a with grave (à) */
#define CH_ASCII_EM       0x19 /* end of medium */

#define CH_BOX_UP_RIGHT   0x1A /* box up & right (└); [Ctrl]+[Z]  */
#define CH_INTL_CAP_A_DOT 0x1A /* capital A with dot (Ȧ) */
#define CH_ASCII_SUB      0x1A /* substitute */

#ifndef _ATARI_H
  #define CH_ESC          0x1B /* [Escape] */
#endif
#define CH_ASCII_ESC      0x1B /* escape */

#ifndef _ATARI_H
  #define CH_CURS_UP      0x1C /* move cursor up; [Ctrl]+[-] */
#endif
#define CH_ASCII_FS       0x1C /* file separator */

#ifndef _ATARI_H
  #define CH_CURS_DOWN    0x1D /* move cursor down; [Ctrl]+[=] */
#endif
#define CH_ASCII_GS       0x1D /* group separator */

#ifndef _ATARI_H
  #define CH_CURS_LEFT    0x1E /* move cursor left; [Ctrl]+[+] */
#endif
#define CH_ASCII_RS       0x1E /* record separator */

#ifndef _ATARI_H
  #define CH_CURS_RIGHT   0x1F /* move cursor right; [Ctrl]+[*] */
#endif
#define CH_ASCII_US       0x1F /* unit separator */

/* 0x20 thru 0x5F (space, punctuation, numerals, capital A-Z)
   are identical to ASCII */

#define CH_DIAMOND        0x60 /* diamond suit (◆); [Ctrl]+[.] */
#define CH_INTL_INV_EXCLAM 0x60 /* inverted exclamation point (¡) */
#define CH_ASCII_GRAVE    0x60 /* grave accent (`) */

/* 0x61 thru 0x7A (lowercase a-z) are identical to ASCII */

#define CH_SPADE          0x7B /* spade suit (♠); [Ctrl]+[;] */
#define CH_INTL_CAP_A_DIA 0x7B /* capital A with diaeresis (Ä) */
#define CH_ASCII_CURLY_LEFT 0x7B /* left curly bracket ({) */

#define CH_BOX_VERTICAL   0x7C /* box vertical (│); [Shift]+[] */
/* 0x7C (pipe (|)) is identical to ASCII */

#ifndef _ATARI_H
  #define CH_CLR          0x7D /* clear screen; [Ctrl]+[<] / [Shift]+[<] */
#endif
#define CH_ASCII_CURLY_RIGHT 0x7D /* right curly bracket (}) */

#ifndef _ATARI_H
  #define CH_DEL          0x7E /* [Backspace] */
  #define CH_RUBOUT       0x7E
#endif
#define CH_ASCII_TILDE    0x7E /* tilde (~) */

#ifndef _ATARI_H
  #define CH_TAB          0x7F /* tab; [Tab] */
#endif
#define CH_ASCII_DEL      0x7F /* delete */

/* ------------------------------------------------------------------------ */

/* ATASCII with high bit set (0x80 thru 0xFF) are identical
   as with high bit clear (0x00 thru 0x7F), but characters are
   (generally) rendered in inverse video.
   (Entered via [Fuji] or [Inverse Video] toggle key on the Atari keyboard.)
   
   However, some values have special editor meanings, or are block graphics,
   so are worth defining, as well.
*/

#define CH_BLOCK_MOST_LEFT   0x82 /* block most left (▉); [Inv] [Ctrl]+[B]  */
#define CH_TRI_UPPER_LEFT    0x88 /* triangle upper left (◤); [Inv] [Ctrl]+[H]  */
#define CH_BLOCK_LOWER_LEFT_AND_UPPER 0x89 /* block lower left and upper halft (▛); [Inv] [Ctrl]+[I]  */
#define CH_TRI_UPPER_RIGHT   0x8A /* triangle upper right  (◥); [Inv] [Ctrl]+[J]  */
#define CH_BLOCK_UPPER_LEFT_AND_LOWER 0x8B /* block upper left and lower half (▙); [Inv] [Ctrl]+[K]  */
#define CH_BLOCK_UPPER_RIGHT_AND_LOWER 0x8C /* block upper right and lower half (▟); [Inv] [Ctrl]+[L]  */
#define CH_BLOCK_MOST_LOWER  0x8D /* block most lower (▇); [Inv] [Ctrl]+[M] */
#define CH_BLOCK_MOST_UPPER  0x8E /* block most upper ([no unicode]); [Inv] [Ctrl]+[N]  */
#define CH_BLOCK_LOWER_RIGHT_AND_UPPER 0x8F /* block lower right and upper half (▜); [Inv] [Ctrl]+[O]  */
#define CH_BLOCK_UPPER       0x95 /* block upper half (▀); [Inv] [Ctrl]+[U]  */
#define CH_BLOCK_MOST_RIGHT  0x96 /* block most right ([no unicode]); [Inv] [Ctrl]+[V]  */
#define CH_BLOCK_RIGHT       0x99 /* block right half (▐); [Inv] [Ctrl]+[Y]  */

#ifndef _ATARI_H
  #define CH_ENTER        0x9B /* [Return] */
  #define CH_EOL          0x9B
#endif

#ifndef _ATARI_H
  #define CH_DELLINE      0x9C /* delete current logical line; [Shift]+[Backspace] */
#endif

#ifndef _ATARI_H
  #define CH_INSLINE      0x9D /* insert new physical line; [Shift]+[>] */
#endif

#define CH_TAB_CLR        0x9E /* clear tabstop under cursor; [Ctrl]+[Tab] */

#define CH_TAB_SET        0x9F /* set new tabstop under cursor; [Shift]+[Tab] */

#ifndef _ATARI_H
  #define CH_BEL          0xFD /* sound bell / buzzer; [Ctrl]+[2] */
#endif

#ifndef _ATARI_H
  #define CH_DELCHR       0xFE /* delete character under cursor; [Ctrl]+[Backspace] */
#endif

#define CH_INSCHR         0xFF /* insert space under cursor; [Ctrl]+[>] */

/* ------------------------------------------------------------------------ */

/* ATASCII symbols and ATASCII international characters as string literals
   e.g.,
     printf(CHS_CLR "Hello world. Here's Escape char: "
            CHS_ESC CHS_ESC "\n");
*/

#define CHS_HEART          "\x00"
#define CHS_INTL_A_ACUTE   "\x00"

#define CHS_BOX_VERT_RIGHT "\x01"
#define CHS_INTL_U_GRAVE   "\x01"

#define CHS_LINE_RIGHT     "\x02"
#define CHS_INTL_CAP_N_TILDE "\x02"

#define CHS_BOX_UP_LEFT    "\x03"
#define CHS_INTL_CAP_E_ACUTE "\x03"

#define CHS_BOX_VERT_LEFT  "\x04"
#define CHS_INTL_C_CEDIL   "\x04"

#define CHS_BOX_DOWN_LEFT  "\x05"
#define CHS_INTL_O_CIRC    "\x05"

#define CHS_BOX_DIAG_UPPER_RIGHT_LOWER_LEFT "\x06"
#define CHS_INTL_O_GRAVE   "\x06"

#define CHS_BOX_DIAG_UPPER_LEFT_LOWER_RIGHT "\x07"
#define CHS_INTL_I_GRAVE   "\x07"

#define CHS_TRI_LOWER_RIGHT "\x08"
#define CHS_INTL_POUND     "\x08"

#define CHS_BLOCK_LOWER_RIGHT "\x09"
#define CHS_INTL_I_DIA     "\x09"

#define CHS_TRI_LOWER_LEFT "\x0A"
#define CHS_INTL_U_DIA     "\x0A"

#define CHS_BLOCK_UPPER_RIGHT "\x0B"
#define CHS_INTL_A_DIA     "\x0B"

#define CHS_BLOCK_UPPER_LEFT "\x0C"
#define CHS_INTL_CAP_O_DIA "\x0C"

#define CHS_LINE_TOP       "\x0D"
#define CHS_INTL_U_ACUTE   "\x0D"

#define CHS_LINE_BOTTOM    "\x0E"
#define CHS_INTL_O_ACUTE   "\x0E"

#define CHS_BLOCK_LOWER_LEFT "\x0F"
#define CHS_INTL_O_DIA     "\x0F"

#define CHS_CLUB           "\x10"
#define CHS_INTL_CAP_U_DIA "\x10"

#define CHS_BOX_DOWN_RIGHT "\x11"
#define CHS_INTL_A_CIRC    "\x11"

#define CHS_BOX_HORIZONTAL "\x12"
#define CHS_INTL_U_CIRC    "\x12"

#define CHS_BOX_VERT_HORIZ "\x13"
#define CHS_INTL_I_CIRC    "\x13"

#define CHS_BALL           "\x14"
#define CHS_INTL_E_ACUTE   "\x14"

#define CHS_BLOCK_LOWER    "\x15"
#define CHS_INTL_E_GRAVE   "\x15"

#define CHS_LINE_LEFT      "\x16"
#define CHS_INTL_N_TILDE   "\x16"

#define CHS_BOX_HORIZ_DOWN "\x17"
#define CHS_INTL_E_CIRC    "\x17"

#define CHS_BOX_HORIZ_UP   "\x18"
#define CHS_INTL_A_DOT     "\x18"

#define CHS_BLOCK_LEFT     "\x19"
#define CHS_INTL_A_GRAVE   "\x19"

#define CHS_BOX_UP_RIGHT   "\x1A"
#define CHS_INTL_CAP_A_DOT "\x1A"

#define CHS_ESC            "\x1B"

#define CHS_CURS_UP        "\x1C"

#define CHS_CURS_DOWN      "\x1D"

#define CHS_CURS_LEFT      "\x1E"

#define CHS_CURS_RIGHT     "\x1F"

#define CHS_DIAMOND        "\x60"
#define CHS_INTL_INV_EXCLAM "\x60"

#define CHS_SPADE          "\x7B"
#define CHS_INTL_CAP_A_DIA "\x7B"

#define CHS_BOX_VERTICAL   "\x7C"

#define CHS_CLR            "\x7D"
#define CHS_DEL            "\x7E"
#define CHS_RUBOUT         "\x7E"
#define CHS_TAB            "\x7F"
#define CHS_BLOCK_MOST_LEFT   "x82"
#define CHS_TRI_UPPER_LEFT    "x88"
#define CHS_BLOCK_LOWER_LEFT_AND_UPPER "x89"
#define CHS_TRI_UPPER_RIGHT   "x8A"
#define CHS_BLOCK_UPPER_LEFT_AND_LOWER "x8B"
#define CHS_BLOCK_UPPER_RIGHT_AND_LOWER "x8C"
#define CHS_BLOCK_MOST_LOWER  "x8D"
#define CHS_BLOCK_MOST_UPPER  "x8E"
#define CHS_BLOCK_LOWER_RIGHT_AND_UPPER "x8F"
#define CHS_BLOCK_UPPER       "x95"
#define CHS_BLOCK_MOST_RIGHT  "x96"
#define CHS_BLOCK_RIGHT       "x99"
#define CHS_ENTER          "x9B"
#define CHS_EOL            "x9B"
#define CHS_DELLINE        "x9C"
#define CHS_INSLINE        "x9D"
#define CHS_TAB_CLR        "x9E"
#define CHS_TAB_SET        "x9F"
#define CHS_BEL            "xFD"
#define CHS_DELCHR         "xFE"
#define CHS_INSCHR         "xFF"

/* ------------------------------------------------------------------------ */

#endif /* _ATASCII_H */

