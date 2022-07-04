/* Copyright 2020 Matthew Rhoten
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.

physical layout:

                                    (1   2   3    4    5   6   7   8   9    10   11)
      1    2    3   4   5   6        7   8   9    10   11  12  13  14  15   16   17

1)    ESC  F1  F2  F3  F4  MM        F5  F6  F7   F8   F9  F10 F11 F12 PRT  SCL  BRK
2)    `    1   2   3   4   5   6     6   7   8    9    0   -   =   BKS INS  HOME PGUP
3)    TAB  Q   W   E   R   T         Y   U   I    O    P   [   ]   \   DEL  END  PDDN
4)    LCTR A   S   D   F   G         H   J   K    L    ;   '   RET
5)    LSHF Z   X   C   V   B         B   N   M    ,    .   /   RSHF         UP
6)    LCTR WIN ALT SPC               SPC ALT ALTG MENU RCTR            LEFT DOWN RGHT

switch layout:

                                      (1    2    3    4    5    6    7    8    9    10)
     1    2    3    4    5    6        7    8    9    10   11   12   13   14   15   16

1)   ESC  F1   F2   F3   F4   6(L)     F5   F6   F7   F8   F9   F10  F11  F12  PRTS SCLK
2)   `    1    2    3    4    5        6(R) 7    8    9    9    -    =    BKSP INS  BRK
3)   TAB  Q    W    E    R    T        Y    U    I    O    P    [    ]    \    HOME PGUP
4)   CTRL A    S    D    F    G        H    J    K    L    ;    '    RET  DEL  END  PGDN
5)   LSHF Z    X    C    V    B(L)     B(R) N    M    ,    .    /    RSHF N/C  UP   N/C
6)   LCTR WIN  LALT SPC  N/C  FN1      SPC  RALT FN2  N/C  N/C  MENU CTRL LEFT DOWN RIGHT 

 * key 'MM' is wired to row 6, column 6
 * key '6'  is wired to row 1, column 6 on left side
 * key '6' is wired normally on right side
 * key 'BRK' is wired on row 2, column 16
 * ins/del block is scattered

 */
#define LAYOUT( \
  L1_01, L1_02, L1_03, L1_04, L1_05, L1_06,             R1_01, R1_02, R1_03, R1_04, R1_05, R1_06, R1_07, R1_08, R1_09, R1_10, R1_11, \
  L2_01, L2_02, L2_03, L2_04, L2_05, L2_06, L2_07,      R2_01, R2_02, R2_03, R2_04, R2_05, R2_06, R2_07, R2_08, R2_09, R2_10, R2_11, \
  L3_01, L3_02, L3_03, L3_04, L3_05, L3_06,             R3_01, R3_02, R3_03, R3_04, R3_05, R3_06, R3_07, R3_08, R3_09, R3_10, R3_11, \
  L4_01, L4_02, L4_03, L4_04, L4_05, L4_06,             R4_01, R4_02, R4_03, R4_04, R4_05, R4_06, R4_07,                             \
  L5_01, L5_02, L5_03, L5_04, L5_05, L5_06,             R5_01, R5_02, R5_03, R5_04, R5_05, R5_06, R5_07,               R5_10,        \
  L6_01, L6_02, L6_03, L6_04,                           R6_01, R6_02, R6_03, R6_04, R6_05,                      R6_09, R6_10, R6_11  \
  ) \
{ \
  { L1_01, L1_02, L1_03, L1_04, L1_05, L2_07,           R1_01, R1_02, R1_03, R1_04, R1_05, R1_06, R1_07, R1_08, R1_09, R1_10, }, \
  { L2_01, L2_02, L2_03, L2_04, L2_05, L2_06,           R2_01, R2_02, R2_03, R2_04, R2_05, R2_06, R2_07, R2_08, R2_09, R1_11, }, \
  { L3_01, L3_02, L3_03, L3_04, L3_05, L3_06,           R3_01, R3_02, R3_03, R3_04, R3_05, R3_06, R3_07, R3_08, R2_10, R2_11, }, \
  { L4_01, L4_02, L4_03, L4_04, L4_05, L4_06,           R4_01, R4_02, R4_03, R4_04, R4_05, R4_06, R4_07, R3_09, R3_10, R3_11, }, \
  { L5_01, L5_02, L5_03, L5_04, L5_05, L5_06,           R5_01, R5_02, R5_03, R5_04, R5_05, R5_06, R5_07, KC_NO, R5_10, KC_NO, }, \
  { L6_01, L6_02, L6_03, L6_04, KC_NO, L1_06,           R6_01, R6_02, R6_03, KC_NO, KC_NO, R6_04, R6_05, R6_09, R6_10, R6_11, }, \
}
