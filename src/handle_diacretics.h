/*
 * Copyright (C) 2011 Swapnil Sudhakar Kulkarni (swapnilkulkarni.cofsug@gmail.com)
 * Copyright (C) 2011 Sourabh S. Dige (sourabhdige@gmail.com)
 * Copyright (C) 2011 Mihir S. Kulkarni (mihirk.31@gmail.com)
 * Copyright (C) 2011 Abhijit A. M. (abhijit13@gmail.com)
 *
 * This is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Library General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 * The full text of the GNU General Public
 * License version 3 can be found in the file `/usr/share/common-licenses/LGPL-3
 */

typedef struct {
    short full_width;
    short halant_width;
} complex_character_width;
short iscomplex(gunichar c);

/* This array consists of the unicode values of the
 * characters which are not zero width characters, which
 * means the characters in this array when appended to
 * the previous character it will require more space than
 * that of normal ones. It requires almost one and half of
 * the vte cell. So we just appended these characters and
 * moved to next character leaving half of the vte cell empty.
 * So, the string with such appended characters will not be
 * continuous one, but it will do. */

gunichar devnagari[]= {
    0x901,
    0x902,
    0x903,
    0x93d,
    0x93e,
    0x93f,
    0x940,
    0x945,
    0x949,
    0x94a,
    0x94b,
    0x94c,
    0x953,
    0x954,
    0x962,
    0x963,
    '\0'
};

/* This function determines wheather the
*  character belongs to array "devnagari".
*  It returns 1 if found in that array,else returns 0. */

short
iscomplex (gunichar c) {
    short i = 0;
    while(devnagari[i] != '\0') {
        if(c == devnagari[i])
            return 1;
        else
            i++;

    }
    return 0;
}
