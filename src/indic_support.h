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

#include "allocate_complex_width.h"
#define	start_devanagari_unicode 0x0900
#define	end_devanagari_unicode	0xa8fb
#define assumed_font_scale 9
#define temp_column_val 4
#define original_column_val 1
#define state_one 1
#define state_two 2
#define state_three 3
#define devanagari_halant 0x094d

static int no_of_columns_mov_cursor = 0;
static int diff = 0;
static short zero_width = 0;
static int font_diff = 0;
static gunichar stored_char;
static short exceptional_devanagari_case = 0;
void check_for_exceptional_cases_devanagari(gunichar stored_char, gunichar c);

/*This flag is for printing the characters
with halant in devnagari.*/
static short halant_flag = 0;

/* This flag is for the characters which
requires more space when appended to previous character.*/
static short iscomplex_flag = 0;
static short zero_width_and_dicretic_exception = 0;

/* Devanagari script related Exceptions Handling */
void
check_for_exceptional_cases_devanagari(gunichar stored_char, gunichar c){
                        /* Exceptional case handling  devanagari specific */
                        if ((halant_flag == 2) && (((stored_char == 0x0915 && c == 0x0937)
                          || (stored_char == 0x0915 && c == 0x924)
                          || (stored_char == 0x091f && (c == 0x0920 || c == 0x91f))
                          || (stored_char == 0x0920 && (c == 0x0920 || c == 0x91f))
                          || (stored_char == 0x0926 && c == 0x0926 )
                          || (stored_char == 0x0921 && c == 0x0921 )
                          || (stored_char == 0x0926 && c == 0x0927 )
                          || (stored_char == 0x0932 && c == 0x0932 )
                          || (stored_char == 0x0922 && c == 0x0922 )
                          || (stored_char == 0x0926 && c == 0x092f )
                          || (stored_char == 0x092A && c == 0x0924 )
                          || (stored_char == 0x0937 && c == 0x091f )
                          || (c == 0x0930))
                          && (exceptional_devanagari_case != 2) )) {
                                exceptional_devanagari_case = 1;
                        }
}
