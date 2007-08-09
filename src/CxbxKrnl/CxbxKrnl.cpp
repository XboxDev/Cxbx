// ******************************************************************
// *
// *    .,-:::::    .,::      .::::::::.    .,::      .:
// *  ,;;;'````'    `;;;,  .,;;  ;;;'';;'   `;;;,  .,;; 
// *  [[[             '[[,,[['   [[[__[[\.    '[[,,[['  
// *  $$$              Y$$$P     $$""""Y$$     Y$$$P    
// *  `88bo,__,o,    oP"``"Yo,  _88o,,od8P   oP"``"Yo,  
// *    "YUMMMMMP",m"       "Mm,""YUMMMP" ,m"       "Mm,
// *
// *   Cxbx->Win32->CxbxKrnl->CxbxKrnl.cpp
// *
// *  This file is part of the Cxbx project.
// *
// *  Cxbx and Cxbe are free software; you can redistribute them
// *  and/or modify them under the terms of the GNU General Public
// *  License as published by the Free Software Foundation; either
// *  version 2 of the license, or (at your option) any later version.
// *
// *  This program is distributed in the hope that it will be useful,
// *  but WITHOUT ANY WARRANTY; without even the implied warranty of
// *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// *  GNU General Public License for more details.
// *
// *  You should have recieved a copy of the GNU General Public License
// *  along with this program; see the file COPYING.
// *  If not, write to the Free Software Foundation, Inc.,
// *  59 Temple Place - Suite 330, Bostom, MA 02111-1307, USA.
// *
// *  (c) 2002-2003 Aaron Robinson <caustik@caustik.com>
// *
// *  All rights reserved
// *
// ******************************************************************

#define _CXBXKRNL_INTERNAL
#define _XBOXKRNL_DEFEXTRN_

/* prevent name collisions */
namespace xboxkrnl
{
    #include <xboxkrnl/xboxkrnl.h>
};

#include "CxbxKrnl.h"
#include "Emu.h"
#include "EmuFS.h"
#include "EmuShared.h"
#include "HLEIntercept.h"

#include <shlobj.h>
#include <locale.h>

/* prevent name collisions */
namespace NtDll
{
    #include "EmuNtDll.h"
};

uint32 funcAddr[]=
{
    0x0003CFD0, // -> 0x0003CFF7 (Size : 39 bytes)
    0x0003D000, // -> 0x0003D05D (Size : 93 bytes)
    0x0003D060, // -> 0x0003D182 (Size : 290 bytes)
    0x0003D190, // -> 0x0003D2D0 (Size : 320 bytes)
    0x0003D3A0, // -> 0x0003D408 (Size : 104 bytes)
    0x0003D490, // -> 0x0003D4E1 (Size : 81 bytes)
    0x0003D560, // -> 0x0003D5D7 (Size : 119 bytes)
    0x0003D840, // -> 0x0003D945 (Size : 261 bytes)
    0x0003D950, // -> 0x0003D9B3 (Size : 99 bytes)
    0x0003D9C0, // -> 0x0003D9FD (Size : 61 bytes)
    0x0003DA00, // -> 0x0003DA39 (Size : 57 bytes)
    0x0003DA40, // -> 0x0003DB2C (Size : 236 bytes)
    0x0003DB30, // -> 0x0003DB9A (Size : 106 bytes)
    0x0003DBA0, // -> 0x0003DD85 (Size : 485 bytes)
    0x0003DD90, // -> 0x0003DDE9 (Size : 89 bytes)
    0x0003DDF0, // -> 0x0003DEBE (Size : 206 bytes)
    0x0003DEC0, // -> 0x0003E215 (Size : 853 bytes)
    0x0003E6A0, // -> 0x0003E6AD (Size : 13 bytes)
    0x0003E6B0, // -> 0x0003E6C7 (Size : 23 bytes)
    0x0003E6D0, // -> 0x0003E7E8 (Size : 280 bytes)
    0x0003E7F0, // -> 0x0003E815 (Size : 37 bytes)
    0x0003E820, // -> 0x0003E825 (Size : 5 bytes)
    0x0003E830, // -> 0x0003E854 (Size : 36 bytes)
    0x0003E860, // -> 0x0003E8A2 (Size : 66 bytes)
    0x0003E8B0, // -> 0x0003E901 (Size : 81 bytes)
    0x0003E910, // -> 0x0003E975 (Size : 101 bytes)
    0x0003E980, // -> 0x0003EA41 (Size : 193 bytes)
    0x0003EA50, // -> 0x0003ECC4 (Size : 628 bytes)
    0x0003ECD0, // -> 0x0003ED13 (Size : 67 bytes)
    0x0003ED20, // -> 0x0003EF42 (Size : 546 bytes)
    0x0003EF50, // -> 0x0003F203 (Size : 691 bytes)
    0x0003F210, // -> 0x0003F361 (Size : 337 bytes)
    0x0003F370, // -> 0x0003F514 (Size : 420 bytes)
    0x0003F520, // -> 0x0003F5A4 (Size : 132 bytes)
    0x0003F5B0, // -> 0x0003F5DF (Size : 47 bytes)
    0x0003F5E0, // -> 0x0003F6B1 (Size : 209 bytes)
    0x0003F6C0, // -> 0x0003F9C0 (Size : 768 bytes)
    0x0003F9C0, // -> 0x0003FA09 (Size : 73 bytes)
    0x0003FC60, // -> 0x0003FC94 (Size : 52 bytes)
    0x0003FCA0, // -> 0x0003FCEB (Size : 75 bytes)
    0x0003FCF0, // -> 0x0003FD3B (Size : 75 bytes)
    0x0003FD40, // -> 0x0003FD5E (Size : 30 bytes)
    0x0003FD60, // -> 0x0003FD6C (Size : 12 bytes)
    0x0003FD70, // -> 0x0003FE00 (Size : 144 bytes)
    0x0003FE00, // -> 0x0003FF65 (Size : 357 bytes)
    0x00040010, // -> 0x00040267 (Size : 599 bytes)
    0x00040270, // -> 0x000402A4 (Size : 52 bytes)
    0x000402A4, // -> 0x000402A7 (Size : 3 bytes)
    0x000402B0, // -> 0x000402E5 (Size : 53 bytes)
    0x00040310, // -> 0x00040331 (Size : 33 bytes)
    0x00040340, // -> 0x00040479 (Size : 313 bytes)
    0x00040480, // -> 0x0004052E (Size : 174 bytes)
    0x00040530, // -> 0x00040598 (Size : 104 bytes)
    0x000405A0, // -> 0x0004062C (Size : 140 bytes)
    0x00040630, // -> 0x00040684 (Size : 84 bytes)
    0x00040690, // -> 0x0004072C (Size : 156 bytes)
    0x00040730, // -> 0x00040848 (Size : 280 bytes)
    0x00040850, // -> 0x00040889 (Size : 57 bytes)
    0x00040890, // -> 0x0004097F (Size : 239 bytes)
    0x00040980, // -> 0x00040AE3 (Size : 355 bytes)
    0x00040AF0, // -> 0x00040B94 (Size : 164 bytes)
    0x00040BA0, // -> 0x00040C7F (Size : 223 bytes)
    0x00040C80, // -> 0x00040D9E (Size : 286 bytes)
    0x00040DA0, // -> 0x00040EB7 (Size : 279 bytes)
    0x00040EC0, // -> 0x0004103D (Size : 381 bytes)
    0x00041040, // -> 0x000410CA (Size : 138 bytes)
    0x000410D0, // -> 0x00041138 (Size : 104 bytes)
    0x00041140, // -> 0x000412BB (Size : 379 bytes)
    0x000412C0, // -> 0x000414A5 (Size : 485 bytes)
    0x000414B0, // -> 0x000415B4 (Size : 260 bytes)
    0x000415C0, // -> 0x00041600 (Size : 64 bytes)
    0x00041600, // -> 0x000416E5 (Size : 229 bytes)
    0x000416F0, // -> 0x000417A7 (Size : 183 bytes)
    0x00041BA0, // -> 0x00041BEB (Size : 75 bytes)
    0x00041BF0, // -> 0x00041C81 (Size : 145 bytes)
    0x00041C90, // -> 0x00041CC5 (Size : 53 bytes)
    0x00041CD0, // -> 0x00041D02 (Size : 50 bytes)
    0x00041D10, // -> 0x00041D47 (Size : 55 bytes)
    0x00041D50, // -> 0x00041D9E (Size : 78 bytes)
    0x00041DA0, // -> 0x00041E2A (Size : 138 bytes)
    0x00041E30, // -> 0x00041E92 (Size : 98 bytes)
    0x00041EA0, // -> 0x00041EB3 (Size : 19 bytes)
    0x00041EC0, // -> 0x00041EEF (Size : 47 bytes)
    0x00041EF0, // -> 0x00041F60 (Size : 112 bytes)
    0x00041F60, // -> 0x00041FA9 (Size : 73 bytes)
    0x00041FB0, // -> 0x00042050 (Size : 160 bytes)
    0x00042050, // -> 0x00042079 (Size : 41 bytes)
    0x00042080, // -> 0x0004217E (Size : 254 bytes)
    0x00042180, // -> 0x000421F8 (Size : 120 bytes)
    0x00042200, // -> 0x0004222D (Size : 45 bytes)
    0x00042230, // -> 0x000422E0 (Size : 176 bytes)
    0x000422E0, // -> 0x0004234B (Size : 107 bytes)
    0x00042350, // -> 0x000423FB (Size : 171 bytes)
    0x00042400, // -> 0x00042566 (Size : 358 bytes)
    0x00042570, // -> 0x000426A6 (Size : 310 bytes)
    0x000426B0, // -> 0x000426BF (Size : 15 bytes)
    0x000426C0, // -> 0x00042704 (Size : 68 bytes)
    0x00042710, // -> 0x00042721 (Size : 17 bytes)
    0x00042730, // -> 0x000427A8 (Size : 120 bytes)
    0x000427B0, // -> 0x000427E6 (Size : 54 bytes)
    0x000427F0, // -> 0x00042847 (Size : 87 bytes)
    0x00042850, // -> 0x0004294A (Size : 250 bytes)
    0x00042950, // -> 0x00042A1E (Size : 206 bytes)
    0x00042A20, // -> 0x00042A79 (Size : 89 bytes)
    0x00042A80, // -> 0x00042AAF (Size : 47 bytes)
    0x00042AB0, // -> 0x00042AF2 (Size : 66 bytes)
    0x00042B00, // -> 0x00043044 (Size : 1348 bytes)
    0x00043050, // -> 0x00043059 (Size : 9 bytes)
    0x00043060, // -> 0x00043069 (Size : 9 bytes)
    0x00043070, // -> 0x000430C2 (Size : 82 bytes)
    0x000430D0, // -> 0x000430DB (Size : 11 bytes)
    0x000430DB, // -> 0x0004315D (Size : 130 bytes)
    0x0004315D, // -> 0x000431B6 (Size : 89 bytes)
    0x000432B0, // -> 0x000433B8 (Size : 264 bytes)
    0x000433C0, // -> 0x00043482 (Size : 194 bytes)
    0x00043490, // -> 0x000435BF (Size : 303 bytes)
    0x000435C0, // -> 0x00043B56 (Size : 1430 bytes)
    0x00043B60, // -> 0x00044025 (Size : 1221 bytes)
    0x00044030, // -> 0x000441DC (Size : 428 bytes)
    0x000441E0, // -> 0x000441EC (Size : 12 bytes)
    0x000441F0, // -> 0x00044252 (Size : 98 bytes)
    0x000442B0, // -> 0x000442D3 (Size : 35 bytes)
    0x000442E0, // -> 0x0004431C (Size : 60 bytes)
    0x00044320, // -> 0x000443DB (Size : 187 bytes)
    0x00044440, // -> 0x00044486 (Size : 70 bytes)
    0x000444B0, // -> 0x00044600 (Size : 336 bytes)
    0x00044600, // -> 0x000446B1 (Size : 177 bytes)
    0x000446C0, // -> 0x000448E3 (Size : 547 bytes)
    0x000448F0, // -> 0x0004498B (Size : 155 bytes)
    0x00044990, // -> 0x00044B85 (Size : 501 bytes)
    0x00044B85, // -> 0x00044BC5 (Size : 64 bytes)
    0x00044BC5, // -> 0x00044BE4 (Size : 31 bytes)
    0x00044BE4, // -> 0x00044C5D (Size : 121 bytes)
    0x00044C5D, // -> 0x00044EC2 (Size : 613 bytes)
    0x00044ED0, // -> 0x00044EE1 (Size : 17 bytes)
    0x00044EF0, // -> 0x00044EF3 (Size : 3 bytes)
    0x00045020, // -> 0x000450F2 (Size : 210 bytes)
    0x00045100, // -> 0x0004520A (Size : 266 bytes)
    0x00045210, // -> 0x00045340 (Size : 304 bytes)
    0x00045340, // -> 0x000453A2 (Size : 98 bytes)
    0x000453B0, // -> 0x000453F8 (Size : 72 bytes)
    0x00045400, // -> 0x00045633 (Size : 563 bytes)
    0x00045670, // -> 0x0004571B (Size : 171 bytes)
    0x00045720, // -> 0x000458A3 (Size : 387 bytes)
    0x000458B0, // -> 0x00045987 (Size : 215 bytes)
    0x00045987, // -> 0x0004599A (Size : 19 bytes)
    0x0004599A, // -> 0x000459DA (Size : 64 bytes)
    0x000459DA, // -> 0x00045A3D (Size : 99 bytes)
    0x00045A3D, // -> 0x00045A71 (Size : 52 bytes)
    0x00045A71, // -> 0x00045A9C (Size : 43 bytes)
    0x00045A9C, // -> 0x00045ADD (Size : 65 bytes)
    0x00045ADD, // -> 0x00045B60 (Size : 131 bytes)
    0x00045B60, // -> 0x00045BF8 (Size : 152 bytes)
    0x00045BF8, // -> 0x00045C52 (Size : 90 bytes)
    0x00045C52, // -> 0x00045D21 (Size : 207 bytes)
    0x00045D21, // -> 0x00045DB1 (Size : 144 bytes)
    0x00045DB1, // -> 0x00045E1C (Size : 107 bytes)
    0x00045E1C, // -> 0x00045E31 (Size : 21 bytes)
    0x00045E31, // -> 0x00045E4F (Size : 30 bytes)
    0x00045E4F, // -> 0x00045F1D (Size : 206 bytes)
    0x00045F1D, // -> 0x00045F64 (Size : 71 bytes)
    0x00045F64, // -> 0x000460C6 (Size : 354 bytes)
    0x000460C6, // -> 0x000462B4 (Size : 494 bytes)
    0x000462B4, // -> 0x00046376 (Size : 194 bytes)
    0x00046376, // -> 0x00046532 (Size : 444 bytes)
    0x00046540, // -> 0x000465D8 (Size : 152 bytes)
    0x000465E0, // -> 0x00046745 (Size : 357 bytes)
    0x00046750, // -> 0x00046ACC (Size : 892 bytes)
    0x00046AD0, // -> 0x00046CB5 (Size : 485 bytes)
    0x00046CC0, // -> 0x00046E9C (Size : 476 bytes)
    0x00047260, // -> 0x0004734E (Size : 238 bytes)
    0x00047350, // -> 0x00047504 (Size : 436 bytes)
    0x00047510, // -> 0x00047648 (Size : 312 bytes)
    0x00047650, // -> 0x0004799E (Size : 846 bytes)
    0x000479A0, // -> 0x00047B93 (Size : 499 bytes)
    0x00047BA0, // -> 0x00047C1E (Size : 126 bytes)
    0x00047C20, // -> 0x00047DB1 (Size : 401 bytes)
    0x00047DC0, // -> 0x00047EFE (Size : 318 bytes)
    0x00047F00, // -> 0x000480F3 (Size : 499 bytes)
    0x00048100, // -> 0x0004814D (Size : 77 bytes)
    0x00048150, // -> 0x000481DC (Size : 140 bytes)
    0x00048200, // -> 0x0004857B (Size : 891 bytes)
    0x00048580, // -> 0x00048AE4 (Size : 1380 bytes)
    0x00048AF0, // -> 0x00048B41 (Size : 81 bytes)
    0x00048B50, // -> 0x00048B80 (Size : 48 bytes)
    0x00048B80, // -> 0x00048B94 (Size : 20 bytes)
    0x00048BA0, // -> 0x00048BC0 (Size : 32 bytes)
    0x00048BC0, // -> 0x00048BF3 (Size : 51 bytes)
    0x00048C00, // -> 0x00048C91 (Size : 145 bytes)
    0x00048C91, // -> 0x00048DF8 (Size : 359 bytes)
    0x00048DF8, // -> 0x00048EF6 (Size : 254 bytes)
    0x00048EF6, // -> 0x00048FC5 (Size : 207 bytes)
    0x00048FC5, // -> 0x00048FFB (Size : 54 bytes)
    0x00048FFB, // -> 0x0004902B (Size : 48 bytes)
    0x0004902B, // -> 0x0004909C (Size : 113 bytes)
    0x0004909C, // -> 0x000490DB (Size : 63 bytes)
    0x000490DB, // -> 0x00049114 (Size : 57 bytes)
    0x00049114, // -> 0x00049311 (Size : 509 bytes)
    0x00049311, // -> 0x00049323 (Size : 18 bytes)
    0x00049323, // -> 0x000494B0 (Size : 397 bytes)
    0x000494B0, // -> 0x000494E9 (Size : 57 bytes)
    0x000494E9, // -> 0x0004955E (Size : 117 bytes)
    0x0004955E, // -> 0x00049F3D (Size : 2527 bytes)
    0x00049F3D, // -> 0x0004A060 (Size : 291 bytes)
    0x0004A060, // -> 0x0004A0E1 (Size : 129 bytes)
    0x0004A0E1, // -> 0x0004A356 (Size : 629 bytes)
    0x0004A360, // -> 0x0004A3E1 (Size : 129 bytes)
    0x0004A400, // -> 0x0004A957 (Size : 1367 bytes)
    0x0004A9C0, // -> 0x0004AA70 (Size : 176 bytes)
    0x0004AA70, // -> 0x0004AA7E (Size : 14 bytes)
    0x0004AA80, // -> 0x0004AA85 (Size : 5 bytes)
    0x0004AA90, // -> 0x0004AADA (Size : 74 bytes)
    0x0004F780, // -> 0x0004F7AD (Size : 45 bytes)
    0x0004F7AD, // -> 0x0004F80C (Size : 95 bytes)
    0x0004F80C, // -> 0x0004F879 (Size : 109 bytes)
    0x0004F879, // -> 0x0004F8D5 (Size : 92 bytes)
    0x0004F8D5, // -> 0x0004F931 (Size : 92 bytes)
    0x0004F931, // -> 0x0004F9AB (Size : 122 bytes)
    0x0004F9AB, // -> 0x0004FA27 (Size : 124 bytes)
    0x0004FA27, // -> 0x0004FB09 (Size : 226 bytes)
    //0x0004FB09, // -> 0x0004FB9D (Size : 148 bytes)
    //0x0004FB9D, // -> 0x0004FC76 (Size : 217 bytes) CreateDevice
    0x0004FC76, // -> 0x0004FD0C (Size : 150 bytes)
    0x0004FD0C, // -> 0x0004FD2B (Size : 31 bytes)
    0x0004FD2B, // -> 0x0004FD53 (Size : 40 bytes)
    0x0004FD53, // -> 0x0004FD76 (Size : 35 bytes)
    0x0004FD76, // -> 0x0004FD9B (Size : 37 bytes)
    0x0004FD9B, // -> 0x0004FE17 (Size : 124 bytes)
    0x0004FE17, // -> 0x0004FECC (Size : 181 bytes)
    0x0004FECC, // -> 0x0004FFAF (Size : 227 bytes)
    0x0004FFAF, // -> 0x0004FFE8 (Size : 57 bytes)
    0x0004FFE8, // -> 0x000500DC (Size : 244 bytes)
    0x000500DC, // -> 0x000501D0 (Size : 244 bytes)
    0x000501D0, // -> 0x0005020D (Size : 61 bytes)
    0x0005020D, // -> 0x00050417 (Size : 522 bytes)
    0x00050417, // -> 0x000505D6 (Size : 447 bytes)
    0x000505D6, // -> 0x000506FF (Size : 297 bytes)
    0x000506FF, // -> 0x00050852 (Size : 339 bytes)
    0x00050852, // -> 0x00050BEE (Size : 924 bytes)
    0x00050BEE, // -> 0x00050C50 (Size : 98 bytes)
    0x00050C50, // -> 0x00050C75 (Size : 37 bytes)
    0x00050C75, // -> 0x00050C7F (Size : 10 bytes)
    0x00050C7F, // -> 0x00050C9D (Size : 30 bytes)
    0x00050C9D, // -> 0x00050E21 (Size : 388 bytes)
    0x00050E21, // -> 0x00050F83 (Size : 354 bytes)
    0x00050F83, // -> 0x0005109E (Size : 283 bytes)
    0x0005109E, // -> 0x000511F0 (Size : 338 bytes)
    0x000511F0, // -> 0x00051318 (Size : 296 bytes)
    0x00051318, // -> 0x00051469 (Size : 337 bytes)
    0x00051469, // -> 0x000515BE (Size : 341 bytes)
    0x000515BE, // -> 0x0005165A (Size : 156 bytes)
    0x0005165A, // -> 0x000517A7 (Size : 333 bytes)
    0x000517A7, // -> 0x000517AA (Size : 3 bytes)
    0x000517AA, // -> 0x000517D6 (Size : 44 bytes)
    0x000517D6, // -> 0x00051802 (Size : 44 bytes)
    0x00051802, // -> 0x00051931 (Size : 303 bytes)
    0x00051931, // -> 0x000519FF (Size : 206 bytes)
    0x000519FF, // -> 0x00051BD9 (Size : 474 bytes)
    0x00051BD9, // -> 0x00051DC6 (Size : 493 bytes)
    0x00051DC6, // -> 0x0005211B (Size : 853 bytes)
    0x0005211B, // -> 0x000524A5 (Size : 906 bytes)
    0x000524A5, // -> 0x000525A9 (Size : 260 bytes)
    0x000525A9, // -> 0x000528CF (Size : 806 bytes)
    0x000528CF, // -> 0x00052DBA (Size : 1259 bytes)
    0x00052DBA, // -> 0x00052DE8 (Size : 46 bytes)
    0x00052DE8, // -> 0x00052E0C (Size : 36 bytes)
    0x00052E0C, // -> 0x000530CD (Size : 705 bytes)
    0x000530CD, // -> 0x000534E5 (Size : 1048 bytes)
    0x000534E5, // -> 0x00053A37 (Size : 1362 bytes)
    0x00053A37, // -> 0x00053B49 (Size : 274 bytes)
    0x00053B49, // -> 0x00053B63 (Size : 26 bytes)
    0x00053B63, // -> 0x00053B7F (Size : 28 bytes)
    0x00053B7F, // -> 0x00053B9C (Size : 29 bytes)
    0x00053B9C, // -> 0x00053B9D (Size : 1 bytes)
    0x00053BB2, // -> 0x00053BC3 (Size : 17 bytes)
    0x00053BC3, // -> 0x00053C06 (Size : 67 bytes)
    0x00053C06, // -> 0x00053C12 (Size : 12 bytes)
    0x00053C12, // -> 0x00053C72 (Size : 96 bytes)
    0x00053C72, // -> 0x00053C96 (Size : 36 bytes)
    0x00053C96, // -> 0x0005437F (Size : 1769 bytes)
    0x0005437F, // -> 0x000545D8 (Size : 601 bytes)
    0x000545D8, // -> 0x00054A27 (Size : 1103 bytes)
    0x00054A27, // -> 0x00054CB3 (Size : 652 bytes)
    0x00054CB3, // -> 0x000551DE (Size : 1323 bytes)
    0x000551DE, // -> 0x00055509 (Size : 811 bytes)
    0x00055509, // -> 0x00055539 (Size : 48 bytes)
    0x00055539, // -> 0x00055683 (Size : 330 bytes)
    0x00055683, // -> 0x0005568D (Size : 10 bytes)
    0x0005568D, // -> 0x00055756 (Size : 201 bytes)
    0x00055756, // -> 0x00055775 (Size : 31 bytes)
    0x00055775, // -> 0x0005577A (Size : 5 bytes)
    0x0005577A, // -> 0x0005577D (Size : 3 bytes)
    0x0005577D, // -> 0x000557E6 (Size : 105 bytes)
    0x000557E6, // -> 0x0005587C (Size : 150 bytes)
    0x0005587C, // -> 0x000558FA (Size : 126 bytes)
    0x000558FA, // -> 0x00055964 (Size : 106 bytes)
    0x00055964, // -> 0x000559B9 (Size : 85 bytes)
    0x000559B9, // -> 0x000559E5 (Size : 44 bytes)
    0x000559E5, // -> 0x00055A2D (Size : 72 bytes)
    0x00055A2D, // -> 0x00055A4D (Size : 32 bytes)
    0x00055A4D, // -> 0x00055C4B (Size : 510 bytes)
    0x00055C4B, // -> 0x00055C90 (Size : 69 bytes)
    0x00055C90, // -> 0x00055D57 (Size : 199 bytes)
    0x00055D57, // -> 0x00055E56 (Size : 255 bytes)
    0x00055E56, // -> 0x00055F33 (Size : 221 bytes)
    0x00055F33, // -> 0x00056010 (Size : 221 bytes)
    0x00056010, // -> 0x000560ED (Size : 221 bytes)
    0x000560ED, // -> 0x000561E6 (Size : 249 bytes)
    0x000561E6, // -> 0x000562E5 (Size : 255 bytes)
    0x000562E5, // -> 0x0005636B (Size : 134 bytes)
    0x0005636B, // -> 0x00056425 (Size : 186 bytes)
    0x00056425, // -> 0x000564C7 (Size : 162 bytes)
    0x000564C7, // -> 0x0005659D (Size : 214 bytes)
    0x0005659D, // -> 0x00056652 (Size : 181 bytes)
    0x00056652, // -> 0x00056737 (Size : 229 bytes)
    0x00056737, // -> 0x0005684E (Size : 279 bytes)
    0x0005684E, // -> 0x00056905 (Size : 183 bytes)
    0x00056905, // -> 0x00056991 (Size : 140 bytes)
    0x00056991, // -> 0x00056A37 (Size : 166 bytes)
    0x00056A37, // -> 0x00056AD3 (Size : 156 bytes)
    0x00056AD3, // -> 0x00056B78 (Size : 165 bytes)
    0x00056B78, // -> 0x00056C1A (Size : 162 bytes)
    0x00056C1A, // -> 0x00056CCA (Size : 176 bytes)
    0x00056CCA, // -> 0x00056D79 (Size : 175 bytes)
    0x00056D79, // -> 0x00056DEB (Size : 114 bytes)
    0x00056DEB, // -> 0x00056E4F (Size : 100 bytes)
    0x00056E4F, // -> 0x00056EBD (Size : 110 bytes)
    0x00056EBD, // -> 0x00056F46 (Size : 137 bytes)
    0x00056F46, // -> 0x00057023 (Size : 221 bytes)
    0x00057023, // -> 0x00057216 (Size : 499 bytes)
    0x00057216, // -> 0x000574E7 (Size : 721 bytes)
    0x000574E7, // -> 0x0005755F (Size : 120 bytes)
    0x0005755F, // -> 0x000575CE (Size : 111 bytes)
    0x000575CE, // -> 0x000576F2 (Size : 292 bytes)
    0x000576F2, // -> 0x000579F7 (Size : 773 bytes)
    0x000579F7, // -> 0x00057C79 (Size : 642 bytes)
    0x00057C79, // -> 0x00057CFF (Size : 134 bytes)
    0x00057CFF, // -> 0x00057D73 (Size : 116 bytes)
    0x00057D73, // -> 0x00057D8F (Size : 28 bytes)
    0x00057D8F, // -> 0x00057DAB (Size : 28 bytes)
    0x00057DAB, // -> 0x00057DC7 (Size : 28 bytes)
    0x00057DC7, // -> 0x00057DE3 (Size : 28 bytes)
    0x00057DE3, // -> 0x00057DFF (Size : 28 bytes)
    0x00057DFF, // -> 0x00057E1B (Size : 28 bytes)
    0x00057E1B, // -> 0x00057E3C (Size : 33 bytes)
    0x00057E3C, // -> 0x00057E58 (Size : 28 bytes)
    0x00057E58, // -> 0x00057E74 (Size : 28 bytes)
    0x00057E74, // -> 0x00057E90 (Size : 28 bytes)
    0x00057E90, // -> 0x00057EAC (Size : 28 bytes)
    0x00057EAC, // -> 0x00057EC8 (Size : 28 bytes)
    0x00057EC8, // -> 0x00057EE4 (Size : 28 bytes)
    0x00057EE4, // -> 0x00057F00 (Size : 28 bytes)
    0x00057F00, // -> 0x00057F1C (Size : 28 bytes)
    0x00057F1C, // -> 0x00057F38 (Size : 28 bytes)
    0x00057F38, // -> 0x00057F63 (Size : 43 bytes)
    0x00057F63, // -> 0x00057F9D (Size : 58 bytes)
    0x00057F9D, // -> 0x00057FB5 (Size : 24 bytes)
    0x00057FB5, // -> 0x00057FCD (Size : 24 bytes)
    0x00057FCD, // -> 0x0005828A (Size : 701 bytes)
    0x0005830A, // -> 0x0005832E (Size : 36 bytes)
    0x0005832E, // -> 0x00058352 (Size : 36 bytes)
    0x00058352, // -> 0x000583D9 (Size : 135 bytes)
    0x000583D9, // -> 0x000583F3 (Size : 26 bytes)
    0x000583F3, // -> 0x00058411 (Size : 30 bytes)
    0x00058411, // -> 0x00058426 (Size : 21 bytes)
    0x00058426, // -> 0x00058449 (Size : 35 bytes)
    0x00058449, // -> 0x0005846E (Size : 37 bytes)
    0x0005846E, // -> 0x0005852E (Size : 192 bytes)
    0x0005852E, // -> 0x00058533 (Size : 5 bytes)
    0x00058533, // -> 0x000586A6 (Size : 371 bytes)
    0x000586A6, // -> 0x00058740 (Size : 154 bytes)
    0x00058740, // -> 0x000587E7 (Size : 167 bytes)
    0x000587E7, // -> 0x0005884A (Size : 99 bytes)
    0x0005884A, // -> 0x000588F3 (Size : 169 bytes)
    0x000588F3, // -> 0x00058977 (Size : 132 bytes)
    0x00058977, // -> 0x00058A36 (Size : 191 bytes)
    0x00058A36, // -> 0x00058AC4 (Size : 142 bytes)
    0x00058AC4, // -> 0x00058DBF (Size : 763 bytes)
    0x00058DBF, // -> 0x00059071 (Size : 690 bytes)
    0x00059071, // -> 0x000592AD (Size : 572 bytes)
    0x000592AD, // -> 0x00059427 (Size : 378 bytes)
    0x00059427, // -> 0x0005957E (Size : 343 bytes)
    0x0005957E, // -> 0x00059812 (Size : 660 bytes)
    0x00059812, // -> 0x00059A3B (Size : 553 bytes)
    0x00059A3B, // -> 0x00059B12 (Size : 215 bytes)
    0x00059B12, // -> 0x00059BAE (Size : 156 bytes)
    0x00059BAE, // -> 0x00059C85 (Size : 215 bytes)
    0x00059C85, // -> 0x00059D1C (Size : 151 bytes)
    0x00059D1C, // -> 0x00059F09 (Size : 493 bytes)
    0x00059F09, // -> 0x00059F87 (Size : 126 bytes)
    0x00059F87, // -> 0x0005A076 (Size : 239 bytes)
    0x0005A076, // -> 0x0005A0A0 (Size : 42 bytes)
    0x0005A0A0, // -> 0x0005A11D (Size : 125 bytes)
    0x0005A11D, // -> 0x0005A169 (Size : 76 bytes)
    0x0005A169, // -> 0x0005A200 (Size : 151 bytes)
    0x0005A200, // -> 0x0005A211 (Size : 17 bytes)
    0x0005A211, // -> 0x0005A25D (Size : 76 bytes)
    0x0005A25D, // -> 0x0005A360 (Size : 259 bytes)
    0x0005A360, // -> 0x0005A4D3 (Size : 371 bytes)
    0x0005A4D3, // -> 0x0005A4F3 (Size : 32 bytes)
    0x0005A4F3, // -> 0x0005A89A (Size : 935 bytes)
    0x0005A89A, // -> 0x0005A8E7 (Size : 77 bytes)
    0x0005A8E7, // -> 0x0005AA0A (Size : 291 bytes)
    0x0005AA0A, // -> 0x0005AA8B (Size : 129 bytes)
    0x0005AA8B, // -> 0x0005AAA5 (Size : 26 bytes)
    0x0005AAA5, // -> 0x0005AABB (Size : 22 bytes)
    0x0005AABB, // -> 0x0005AAD1 (Size : 22 bytes)
    0x0005AAD1, // -> 0x0005AAFA (Size : 41 bytes)
    0x0005AAFA, // -> 0x0005AB25 (Size : 43 bytes)
    0x0005AB25, // -> 0x0005ABF6 (Size : 209 bytes)
    0x0005ABF6, // -> 0x0005AC29 (Size : 51 bytes)
    0x0005AC29, // -> 0x0005AC90 (Size : 103 bytes)
    0x0005AC90, // -> 0x0005AC99 (Size : 9 bytes)
    0x0005AC99, // -> 0x0005ACB2 (Size : 25 bytes)
    0x0005ACB2, // -> 0x0005ACCB (Size : 25 bytes)
    0x0005ACCB, // -> 0x0005AD18 (Size : 77 bytes)
    0x0005AD18, // -> 0x0005ADD7 (Size : 191 bytes)
    0x0005ADD7, // -> 0x0005ADE0 (Size : 9 bytes)
    0x0005ADE0, // -> 0x0005AE16 (Size : 54 bytes)
    0x0005AE16, // -> 0x0005AE1F (Size : 9 bytes)
    0x0005AE1F, // -> 0x0005AF0A (Size : 235 bytes)
    0x0005AF0A, // -> 0x0005B01A (Size : 272 bytes)
    0x0005B01A, // -> 0x0005B194 (Size : 378 bytes)
    0x0005B194, // -> 0x0005B1D8 (Size : 68 bytes)
    0x0005B1D8, // -> 0x0005B40A (Size : 562 bytes)
    0x0005B40A, // -> 0x0005B758 (Size : 846 bytes)
    0x0005B758, // -> 0x0005B960 (Size : 520 bytes)
    0x0005B960, // -> 0x0005BCB6 (Size : 854 bytes)
    0x0005BCB6, // -> 0x0005BDC4 (Size : 270 bytes)
    0x0005BDC4, // -> 0x0005C0CF (Size : 779 bytes)
    0x0005C0CF, // -> 0x0005C1E2 (Size : 275 bytes)
    0x0005C1E2, // -> 0x0005C37E (Size : 412 bytes)
    0x0005C37E, // -> 0x0005C399 (Size : 27 bytes)
    0x0005C399, // -> 0x0005C43A (Size : 161 bytes)
    0x0005C43A, // -> 0x0005C45E (Size : 36 bytes)
    0x0005C45E, // -> 0x0005C479 (Size : 27 bytes)
    0x0005C479, // -> 0x0005C4B2 (Size : 57 bytes)
    0x0005C4B2, // -> 0x0005C4F9 (Size : 71 bytes)
    0x0005C4F9, // -> 0x0005C521 (Size : 40 bytes)
    0x0005C521, // -> 0x0005C560 (Size : 63 bytes)
    0x0005C560, // -> 0x0005C5A8 (Size : 72 bytes)
    0x0005C5A8, // -> 0x0005C5FB (Size : 83 bytes)
    0x0005C5FB, // -> 0x0005C600 (Size : 5 bytes)
    0x0005C600, // -> 0x0005C618 (Size : 24 bytes)
    0x0005C657, // -> 0x0005C665 (Size : 14 bytes)
    0x0005C665, // -> 0x0005C68B (Size : 38 bytes)
    0x0005C68B, // -> 0x0005C6F4 (Size : 105 bytes)
    0x0005C6F4, // -> 0x0005C71A (Size : 38 bytes)
    0x0005C71A, // -> 0x0005C74C (Size : 50 bytes)
    0x0005C74C, // -> 0x0005C781 (Size : 53 bytes)
    0x0005C781, // -> 0x0005C7B1 (Size : 48 bytes)
    0x0005C7B1, // -> 0x0005C7FE (Size : 77 bytes)
    0x0005C7FE, // -> 0x0005C89D (Size : 159 bytes)
    0x0005C89D, // -> 0x0005C928 (Size : 139 bytes)
    0x0005C928, // -> 0x0005CA5A (Size : 306 bytes)
    0x0005CA5A, // -> 0x0005CABB (Size : 97 bytes)
    0x0005CABB, // -> 0x0005CBA0 (Size : 229 bytes)
    0x0005CBA0, // -> 0x0005CBEE (Size : 78 bytes)
    0x0005CBEE, // -> 0x0005CCEE (Size : 256 bytes)
    0x0005CCEE, // -> 0x0005D198 (Size : 1194 bytes)
    0x0005D198, // -> 0x0005D1CA (Size : 50 bytes)
    0x0005D1CA, // -> 0x0005D223 (Size : 89 bytes)
    0x0005D223, // -> 0x0005D379 (Size : 342 bytes)
    0x0005D379, // -> 0x0005D389 (Size : 16 bytes)
    0x0005D389, // -> 0x0005D3A1 (Size : 24 bytes)
    0x0005D3A1, // -> 0x0005D3E8 (Size : 71 bytes)
    0x0005D3E8, // -> 0x0005D40A (Size : 34 bytes)
    0x0005D40A, // -> 0x0005D425 (Size : 27 bytes)
    0x0005D425, // -> 0x0005D457 (Size : 50 bytes)
    0x0005D457, // -> 0x0005D612 (Size : 443 bytes)
    0x0005D612, // -> 0x0005D788 (Size : 374 bytes)
    0x0005D788, // -> 0x0005D81A (Size : 146 bytes)
    0x0005D81A, // -> 0x0005D854 (Size : 58 bytes)
    0x0005D854, // -> 0x0005D8E7 (Size : 147 bytes)
    0x0005D8E7, // -> 0x0005D91E (Size : 55 bytes)
    0x0005D91E, // -> 0x0005D92F (Size : 17 bytes)
    0x0005D92F, // -> 0x0005D970 (Size : 65 bytes)
    0x0005D970, // -> 0x0005D985 (Size : 21 bytes)
    0x0005D985, // -> 0x0005DA81 (Size : 252 bytes)
    0x0005DA81, // -> 0x0005DB0F (Size : 142 bytes)
    0x0005DB0F, // -> 0x0005DBA1 (Size : 146 bytes)
    0x0005DBA1, // -> 0x0005DC3F (Size : 158 bytes)
    0x0005DC3F, // -> 0x0005DCA0 (Size : 97 bytes)
    0x0005DCA0, // -> 0x0005DD01 (Size : 97 bytes)
    0x0005DD01, // -> 0x0005DE80 (Size : 383 bytes)
    0x0005DE80, // -> 0x0005DF08 (Size : 136 bytes)
    0x0005DF08, // -> 0x0005DF93 (Size : 139 bytes)
    0x0005DF93, // -> 0x0005E0B1 (Size : 286 bytes)
    0x0005E0B1, // -> 0x0005E1D4 (Size : 291 bytes)
    0x0005E1D4, // -> 0x0005E2B5 (Size : 225 bytes)
    0x0005E2B5, // -> 0x0005E2E5 (Size : 48 bytes)
    0x0005E2E5, // -> 0x0005E399 (Size : 180 bytes)
    0x0005E399, // -> 0x0005E3BB (Size : 34 bytes)
    0x0005E3BB, // -> 0x0005E3D6 (Size : 27 bytes)
    0x0005E3D6, // -> 0x0005E3F2 (Size : 28 bytes)
    0x0005E3F2, // -> 0x0005E40E (Size : 28 bytes)
    0x0005E40E, // -> 0x0005E47F (Size : 113 bytes)
    0x0005E47F, // -> 0x0005E66E (Size : 495 bytes)
    0x0005E66E, // -> 0x0005E6DD (Size : 111 bytes)
    0x0005E6DD, // -> 0x0005E88A (Size : 429 bytes)
    0x0005E88A, // -> 0x0005E9B7 (Size : 301 bytes)
    0x0005E9B7, // -> 0x0005E9D8 (Size : 33 bytes)
    0x0005E9D8, // -> 0x0005EA08 (Size : 48 bytes)
    0x0005EA08, // -> 0x0005EA47 (Size : 63 bytes)
    0x0005EA47, // -> 0x0005EA85 (Size : 62 bytes)
    0x0005EA85, // -> 0x0005EB6A (Size : 229 bytes)
    0x0005EB6A, // -> 0x0005EB81 (Size : 23 bytes)
    0x0005EB81, // -> 0x0005EEB0 (Size : 815 bytes)
    0x0005EEE8, // -> 0x0005EF2E (Size : 70 bytes)
    0x0005EF2E, // -> 0x0005EF44 (Size : 22 bytes)
    0x0005EF44, // -> 0x0005EF7E (Size : 58 bytes)
    0x0005EF7E, // -> 0x0005EF9B (Size : 29 bytes)
    0x0005EF9B, // -> 0x0005EFBE (Size : 35 bytes)
    0x0005EFBE, // -> 0x0005EFEF (Size : 49 bytes)
    0x0005EFEF, // -> 0x0005F012 (Size : 35 bytes)
    0x0005F012, // -> 0x0005F02C (Size : 26 bytes)
    0x0005F02C, // -> 0x0005F08A (Size : 94 bytes)
    0x0005F08A, // -> 0x0005F0EC (Size : 98 bytes)
    0x0005F0EC, // -> 0x0005F302 (Size : 534 bytes)
    0x0005F302, // -> 0x0005F5CB (Size : 713 bytes)
    0x0005F5CB, // -> 0x0005F744 (Size : 377 bytes)
    0x0005F744, // -> 0x0005F8E0 (Size : 412 bytes)
    0x0005F8E0, // -> 0x0005F96C (Size : 140 bytes)
    0x0005F96C, // -> 0x0005FB62 (Size : 502 bytes)
    0x0005FB62, // -> 0x0005FC8C (Size : 298 bytes)
    0x0005FC8C, // -> 0x0005FCD6 (Size : 74 bytes)
    0x0005FCD6, // -> 0x0005FDE1 (Size : 267 bytes)
    0x0005FDE1, // -> 0x0005FED0 (Size : 239 bytes)
    0x0005FED0, // -> 0x00060087 (Size : 439 bytes)
    0x00060087, // -> 0x000600D1 (Size : 74 bytes)
    0x000600D1, // -> 0x000602F5 (Size : 548 bytes)
    0x000602F5, // -> 0x000603E4 (Size : 239 bytes)
    0x000603E4, // -> 0x000603F3 (Size : 15 bytes)
    0x000603F3, // -> 0x00060402 (Size : 15 bytes)
    0x00060402, // -> 0x00060407 (Size : 5 bytes)
    0x00060407, // -> 0x0006041B (Size : 20 bytes)
    0x0006041B, // -> 0x000604C3 (Size : 168 bytes)
    0x000604C3, // -> 0x000605F4 (Size : 305 bytes)
    0x000605F4, // -> 0x000606C8 (Size : 212 bytes)
    0x000606C8, // -> 0x0006075E (Size : 150 bytes)
    0x0006075E, // -> 0x000607C6 (Size : 104 bytes)
    0x000607C6, // -> 0x000608CE (Size : 264 bytes)
    0x000608CE, // -> 0x000608F1 (Size : 35 bytes)
    0x00060959, // -> 0x00060A2C (Size : 211 bytes)
    0x00060A2C, // -> 0x00060A6B (Size : 63 bytes)
    0x00060A6B, // -> 0x00060A7B (Size : 16 bytes)
    0x00060A7B, // -> 0x00060C55 (Size : 474 bytes)
    0x00060C55, // -> 0x00060C58 (Size : 3 bytes)
    0x00060C58, // -> 0x00060DF7 (Size : 415 bytes)
    0x00060DF7, // -> 0x00060F5D (Size : 358 bytes)
    0x00060F5D, // -> 0x00061040 (Size : 227 bytes)
    0x00061040, // -> 0x0006155A (Size : 1306 bytes)
    0x00061595, // -> 0x0006168D (Size : 248 bytes)
    0x0006168D, // -> 0x00061837 (Size : 426 bytes)
    0x00061837, // -> 0x00061921 (Size : 234 bytes)
    0x00061921, // -> 0x00061A0B (Size : 234 bytes)
    0x00061A0B, // -> 0x00061A69 (Size : 94 bytes)
    0x00061A69, // -> 0x00061E36 (Size : 973 bytes)
    0x00061E36, // -> 0x00061F65 (Size : 303 bytes)
    0x00061F65, // -> 0x00061F9F (Size : 58 bytes)
    0x00061F9F, // -> 0x00061FFA (Size : 91 bytes)
    0x00061FFA, // -> 0x000621F7 (Size : 509 bytes)
    0x000621F7, // -> 0x00062420 (Size : 553 bytes)
    0x00062420, // -> 0x00062502 (Size : 226 bytes)
    0x00062502, // -> 0x00062870 (Size : 878 bytes)
    0x00062870, // -> 0x00062B13 (Size : 675 bytes)
    0x00062B13, // -> 0x00062B74 (Size : 97 bytes)
    0x00062B74, // -> 0x00062D2B (Size : 439 bytes)
    0x00062D2B, // -> 0x00062D9F (Size : 116 bytes)
    0x00062D9F, // -> 0x00062E04 (Size : 101 bytes)
    0x00062E04, // -> 0x00062E94 (Size : 144 bytes)
    0x00062E94, // -> 0x00062F20 (Size : 140 bytes)
    0x00062FC6, // -> 0x00063049 (Size : 131 bytes)
    0x00063049, // -> 0x00063063 (Size : 26 bytes)
    0x00063063, // -> 0x00063129 (Size : 198 bytes)
    0x00063129, // -> 0x00063134 (Size : 11 bytes)
    0x0006313C, // -> 0x00063219 (Size : 221 bytes)
    0x00063219, // -> 0x00063270 (Size : 87 bytes)
    0x00063270, // -> 0x000632DA (Size : 106 bytes)
    0x000632DA, // -> 0x0006337E (Size : 164 bytes)
    0x0006337E, // -> 0x00063485 (Size : 263 bytes)
    0x00063485, // -> 0x00063644 (Size : 447 bytes)
    0x00063644, // -> 0x000636F4 (Size : 176 bytes)
    0x000636F4, // -> 0x0006375F (Size : 107 bytes)
    0x0006375F, // -> 0x00063782 (Size : 35 bytes)
    0x00063782, // -> 0x000638B4 (Size : 306 bytes)
    0x000638B4, // -> 0x000639F0 (Size : 316 bytes)
    0x000639F0, // -> 0x00063C0E (Size : 542 bytes)
    0x00063C0E, // -> 0x00063D2F (Size : 289 bytes)
    0x00063D2F, // -> 0x00063DDF (Size : 176 bytes)
    0x00063DF4, // -> 0x00063E9A (Size : 166 bytes)
    0x00063E9A, // -> 0x00063ECB (Size : 49 bytes)
    0x00063ECB, // -> 0x00064021 (Size : 342 bytes)
    0x00064021, // -> 0x00064207 (Size : 486 bytes)
    0x00064207, // -> 0x0006427C (Size : 117 bytes)
    0x0006427C, // -> 0x000642E8 (Size : 108 bytes)
    0x000642E8, // -> 0x00064620 (Size : 824 bytes)
    0x00064620, // -> 0x00064773 (Size : 339 bytes)
    0x00064773, // -> 0x000648AB (Size : 312 bytes)
    0x000648AB, // -> 0x00064938 (Size : 141 bytes)
    0x00064938, // -> 0x00064AB8 (Size : 384 bytes)
    0x00064AB8, // -> 0x00064BD2 (Size : 282 bytes)
    0x00064BD2, // -> 0x00064CA2 (Size : 208 bytes)
    0x00064CA2, // -> 0x00064D4B (Size : 169 bytes)
    0x00064D4B, // -> 0x00064FB9 (Size : 622 bytes)
    0x00064FB9, // -> 0x00065049 (Size : 144 bytes)
    0x00065049, // -> 0x0006506B (Size : 34 bytes)
    0x0006506B, // -> 0x0006516D (Size : 258 bytes)
    0x0006516D, // -> 0x0006517C (Size : 15 bytes)
    0x0006517C, // -> 0x0006528F (Size : 275 bytes)
    0x0006528F, // -> 0x0006535A (Size : 203 bytes)
    0x0006535A, // -> 0x00065487 (Size : 301 bytes)
    0x00065487, // -> 0x000655B2 (Size : 299 bytes)
    0x000655B2, // -> 0x00065677 (Size : 197 bytes)
    0x00065677, // -> 0x000656FF (Size : 136 bytes)
    0x000656FF, // -> 0x0006578C (Size : 141 bytes)
    0x0006578C, // -> 0x00065877 (Size : 235 bytes)
    0x00065877, // -> 0x00065976 (Size : 255 bytes)
    0x00065976, // -> 0x00065AF8 (Size : 386 bytes)
    0x00065AF8, // -> 0x00065B2E (Size : 54 bytes)
    0x00065B2E, // -> 0x00065BF8 (Size : 202 bytes)
    0x00065BF8, // -> 0x00065C0C (Size : 20 bytes)
    0x00065C0C, // -> 0x00065C93 (Size : 135 bytes)
    0x00065C93, // -> 0x00065CFE (Size : 107 bytes)
    0x00065CFE, // -> 0x00065D8B (Size : 141 bytes)
    0x00065D8B, // -> 0x000664FE (Size : 1907 bytes)
    0x00066526, // -> 0x0006655A (Size : 52 bytes)
    0x0006655A, // -> 0x00066673 (Size : 281 bytes)
    0x00066673, // -> 0x00066688 (Size : 21 bytes)
    0x00066688, // -> 0x00066697 (Size : 15 bytes)
    0x00066697, // -> 0x000669AC (Size : 789 bytes)
    0x000669AC, // -> 0x00066B6A (Size : 446 bytes)
    0x00066B6A, // -> 0x00066BA7 (Size : 61 bytes)
    0x00066BA7, // -> 0x00066BF3 (Size : 76 bytes)
    0x00066BF3, // -> 0x00066C3F (Size : 76 bytes)
    0x00066C3F, // -> 0x00067012 (Size : 979 bytes)
    0x00067012, // -> 0x00067046 (Size : 52 bytes)
    0x00067046, // -> 0x00067582 (Size : 1340 bytes)
    0x000675AA, // -> 0x000675BB (Size : 17 bytes)
    0x000675BB, // -> 0x00067938 (Size : 893 bytes)
    0x00067938, // -> 0x000679B7 (Size : 127 bytes)
    0x000679B7, // -> 0x00067ABA (Size : 259 bytes)
    0x00067ABA, // -> 0x00067AE9 (Size : 47 bytes)
    0x00067AE9, // -> 0x00067BFE (Size : 277 bytes)
    0x00067BFE, // -> 0x0006807B (Size : 1149 bytes)
    0x0006807B, // -> 0x00068733 (Size : 1720 bytes)
    0x00068733, // -> 0x00068A98 (Size : 869 bytes)
    0x00068A98, // -> 0x0006986B (Size : 3539 bytes)
    0x0006986B, // -> 0x00069B2B (Size : 704 bytes)
    0x0006C660, // -> 0x0006C67F (Size : 31 bytes)
    0x0006C67F, // -> 0x0006C6E0 (Size : 97 bytes)
    0x0006C6E0, // -> 0x0006C709 (Size : 41 bytes)
    0x0006C709, // -> 0x0006C732 (Size : 41 bytes)
    0x0006C732, // -> 0x0006C73C (Size : 10 bytes)
    0x0006C73C, // -> 0x0006C7B0 (Size : 116 bytes)
    0x0006C7B0, // -> 0x0006C8B0 (Size : 256 bytes)
    0x0006C8B0, // -> 0x0006C9AE (Size : 254 bytes)
    0x0006C9AE, // -> 0x0006CAA7 (Size : 249 bytes)
    0x0006CAA7, // -> 0x0006CB8A (Size : 227 bytes)
    0x0006CB8A, // -> 0x0006CC9C (Size : 274 bytes)
    0x0006CC9C, // -> 0x0006CD92 (Size : 246 bytes)
    0x0006CD92, // -> 0x0006CDD6 (Size : 68 bytes)
    0x0006CDD6, // -> 0x0006CE00 (Size : 42 bytes)
    0x0006CE52, // -> 0x0006CED3 (Size : 129 bytes)
    0x0006CED3, // -> 0x0006CF54 (Size : 129 bytes)
    0x0006CF54, // -> 0x0006D028 (Size : 212 bytes)
    0x0006D028, // -> 0x0006D0FC (Size : 212 bytes)
    0x0006D0FC, // -> 0x0006D17F (Size : 131 bytes)
    0x0006D17F, // -> 0x0006D202 (Size : 131 bytes)
    0x0006D202, // -> 0x0006D2CE (Size : 204 bytes)
    0x0006D2CE, // -> 0x0006D39A (Size : 204 bytes)
    0x0006D39A, // -> 0x0006D415 (Size : 123 bytes)
    0x0006D415, // -> 0x0006D490 (Size : 123 bytes)
    0x0006D490, // -> 0x0006D56C (Size : 220 bytes)
    0x0006D56C, // -> 0x0006D648 (Size : 220 bytes)
    0x0006D648, // -> 0x0006DD99 (Size : 1873 bytes)
    0x0006DD99, // -> 0x0006E4B0 (Size : 1815 bytes)
    0x0006E4C0, // -> 0x0006E4DF (Size : 31 bytes)
    0x0006E4DF, // -> 0x0006E4F0 (Size : 17 bytes)
    0x0006E4F0, // -> 0x0006E512 (Size : 34 bytes)
    0x0006E512, // -> 0x0006E529 (Size : 23 bytes)
    0x0006E529, // -> 0x0006E54E (Size : 37 bytes)
    0x0006E54E, // -> 0x0006E56C (Size : 30 bytes)
    0x0006E56C, // -> 0x0006E579 (Size : 13 bytes)
    0x0006E579, // -> 0x0006E58A (Size : 17 bytes)
    0x0006E58A, // -> 0x0006E5AB (Size : 33 bytes)
    0x0006E5AB, // -> 0x0006E5F4 (Size : 73 bytes)
    0x0006E5F4, // -> 0x0006E5F8 (Size : 4 bytes)
    0x0006E5F8, // -> 0x0006E621 (Size : 41 bytes)
    0x0006E621, // -> 0x0006E658 (Size : 55 bytes)
    0x0006E658, // -> 0x0006E678 (Size : 32 bytes)
    0x0006E678, // -> 0x0006E6AC (Size : 52 bytes)
    0x0006E6AC, // -> 0x0006E6CE (Size : 34 bytes)
    0x0006E6CE, // -> 0x0006E6F5 (Size : 39 bytes)
    0x0006E6F5, // -> 0x0006E713 (Size : 30 bytes)
    0x0006E713, // -> 0x0006E742 (Size : 47 bytes)
    0x0006E742, // -> 0x0006E781 (Size : 63 bytes)
    0x0006E781, // -> 0x0006E797 (Size : 22 bytes)
    0x0006E797, // -> 0x0006E7AD (Size : 22 bytes)
    0x0006E7AD, // -> 0x0006E7CC (Size : 31 bytes)
    0x0006E7CC, // -> 0x0006E816 (Size : 74 bytes)
    0x0006E816, // -> 0x0006E81B (Size : 5 bytes)
    0x0006E81B, // -> 0x0006E820 (Size : 5 bytes)
    0x0006E820, // -> 0x0006E842 (Size : 34 bytes)
    0x0006E842, // -> 0x0006E85F (Size : 29 bytes)
    0x0006E85F, // -> 0x0006E8A6 (Size : 71 bytes)
    0x0006E8A6, // -> 0x0006E8E0 (Size : 58 bytes)
    0x0006E8E0, // -> 0x0006E944 (Size : 100 bytes)
    0x0006E944, // -> 0x0006E9A3 (Size : 95 bytes)
    0x0006E9A3, // -> 0x0006E9D4 (Size : 49 bytes)
    0x0006E9D4, // -> 0x0006E9F9 (Size : 37 bytes)
    0x0006E9F9, // -> 0x0006EA67 (Size : 110 bytes)
    0x0006EA67, // -> 0x0006EAB4 (Size : 77 bytes)
    0x0006EAB4, // -> 0x0006EACD (Size : 25 bytes)
    0x0006EACD, // -> 0x0006EAE9 (Size : 28 bytes)
    0x0006EAE9, // -> 0x0006EAFC (Size : 19 bytes)
    0x0006EAFC, // -> 0x0006EB0F (Size : 19 bytes)
    0x0006EB0F, // -> 0x0006EB22 (Size : 19 bytes)
    0x0006EB22, // -> 0x0006EB45 (Size : 35 bytes)
    0x0006EB45, // -> 0x0006EB62 (Size : 29 bytes)
    0x0006EB62, // -> 0x0006EB73 (Size : 17 bytes)
    0x0006EB73, // -> 0x0006EB86 (Size : 19 bytes)
    0x0006EB86, // -> 0x0006ECB7 (Size : 305 bytes)
    0x0006ECB7, // -> 0x0006ECD4 (Size : 29 bytes)
    0x0006ECD4, // -> 0x0006EDA9 (Size : 213 bytes)
    0x0006EDA9, // -> 0x0006EDDC (Size : 51 bytes)
    0x0006EDDC, // -> 0x0006EE26 (Size : 74 bytes)
    0x0006EE26, // -> 0x0006EE77 (Size : 81 bytes)
    0x0006EE77, // -> 0x0006EEC6 (Size : 79 bytes)
    0x0006EEC6, // -> 0x0006EF1F (Size : 89 bytes)
    0x0006EF1F, // -> 0x0006EF70 (Size : 81 bytes)
    0x0006EF70, // -> 0x0006EFF5 (Size : 133 bytes)
    0x0006EFF5, // -> 0x0006F046 (Size : 81 bytes)
    0x0006F046, // -> 0x0006F084 (Size : 62 bytes)
    0x0006F084, // -> 0x0006F0CB (Size : 71 bytes)
    0x0006F0CB, // -> 0x0006F119 (Size : 78 bytes)
    0x0006F119, // -> 0x0006F180 (Size : 103 bytes)
    0x0006F180, // -> 0x0006F1CD (Size : 77 bytes)
    0x0006F1CD, // -> 0x0006F218 (Size : 75 bytes)
    0x0006F218, // -> 0x0006F269 (Size : 81 bytes)
    0x0006F269, // -> 0x0006F2E0 (Size : 119 bytes)
    0x0006F2E0, // -> 0x0006F331 (Size : 81 bytes)
    0x0006F331, // -> 0x0006F39B (Size : 106 bytes)
    0x0006F39B, // -> 0x0006F67C (Size : 737 bytes)
    0x0006F67C, // -> 0x0006F6B3 (Size : 55 bytes)
    0x0006F6B3, // -> 0x0006F6BD (Size : 10 bytes)
    0x0006F6BD, // -> 0x0006F6C7 (Size : 10 bytes)
    0x0006F6C7, // -> 0x0006F6E3 (Size : 28 bytes)
    0x0006F6E3, // -> 0x0006F731 (Size : 78 bytes)
    0x0006F731, // -> 0x0006F77F (Size : 78 bytes)
    0x0006F77F, // -> 0x0006F7CD (Size : 78 bytes)
    0x0006F7CD, // -> 0x0006F81B (Size : 78 bytes)
    0x0006F81B, // -> 0x0006F869 (Size : 78 bytes)
    0x0006F869, // -> 0x0006F8B7 (Size : 78 bytes)
    0x0006F8B7, // -> 0x0006F905 (Size : 78 bytes)
    0x0006F905, // -> 0x0006F953 (Size : 78 bytes)
    0x0006F953, // -> 0x0006F9A1 (Size : 78 bytes)
    0x0006F9A1, // -> 0x0006F9ED (Size : 76 bytes)
    0x0006F9ED, // -> 0x0006FA3F (Size : 82 bytes)
    0x0006FA3F, // -> 0x0006FA91 (Size : 82 bytes)
    0x0006FA91, // -> 0x0006FAE3 (Size : 82 bytes)
    0x0006FAE3, // -> 0x0006FB35 (Size : 82 bytes)
    0x0006FB35, // -> 0x0006FB87 (Size : 82 bytes)
    0x0006FB87, // -> 0x0006FBD9 (Size : 82 bytes)
    0x0006FBD9, // -> 0x0006FC2B (Size : 82 bytes)
    0x0006FC2B, // -> 0x0006FC7D (Size : 82 bytes)
    0x0006FC7D, // -> 0x0006FCCF (Size : 82 bytes)
    0x0006FCCF, // -> 0x0006FD1F (Size : 80 bytes)
    0x0006FD1F, // -> 0x0006FD3F (Size : 32 bytes)
    0x0006FD3F, // -> 0x0006FD5B (Size : 28 bytes)
    0x0006FD5B, // -> 0x0006FD77 (Size : 28 bytes)
    0x0006FD77, // -> 0x0006FD93 (Size : 28 bytes)
    0x0006FD93, // -> 0x0006FDAF (Size : 28 bytes)
    0x0006FDAF, // -> 0x0006FDCB (Size : 28 bytes)
    0x0006FDCB, // -> 0x0006FDE7 (Size : 28 bytes)
    0x0006FDE7, // -> 0x0006FE03 (Size : 28 bytes)
    0x0006FE03, // -> 0x0006FE27 (Size : 36 bytes)
    0x0006FE27, // -> 0x0006FE3F (Size : 24 bytes)
    0x0006FE3F, // -> 0x0006FE63 (Size : 36 bytes)
    0x0006FE63, // -> 0x0006FE83 (Size : 32 bytes)
    0x0006FE83, // -> 0x0006FE9F (Size : 28 bytes)
    0x0006FE9F, // -> 0x0006FEBB (Size : 28 bytes)
    0x0006FEBB, // -> 0x0006FED7 (Size : 28 bytes)
    0x0006FED7, // -> 0x0006FEF3 (Size : 28 bytes)
    0x0006FEF3, // -> 0x0006FF0F (Size : 28 bytes)
    0x0006FF0F, // -> 0x0006FF14 (Size : 5 bytes)
    0x0006FF14, // -> 0x0006FF19 (Size : 5 bytes)
    0x0006FF19, // -> 0x0006FF1E (Size : 5 bytes)
    0x0006FF1E, // -> 0x0006FF23 (Size : 5 bytes)
    0x0006FF23, // -> 0x0006FF28 (Size : 5 bytes)
    0x0006FF28, // -> 0x0006FF2D (Size : 5 bytes)
    0x0006FF2D, // -> 0x0006FF32 (Size : 5 bytes)
    0x0006FF32, // -> 0x0006FF37 (Size : 5 bytes)
    0x0006FF37, // -> 0x0006FF4F (Size : 24 bytes)
    0x0006FF4F, // -> 0x0006FF54 (Size : 5 bytes)
    0x0006FF54, // -> 0x0006FF59 (Size : 5 bytes)
    0x0006FF59, // -> 0x0006FF5E (Size : 5 bytes)
    0x0006FF5E, // -> 0x0006FF67 (Size : 9 bytes)
    0x0006FF67, // -> 0x0006FF90 (Size : 41 bytes)
    0x00070192, // -> 0x000701AD (Size : 27 bytes)
    0x000701AD, // -> 0x00070278 (Size : 203 bytes)
    0x00070278, // -> 0x0007034B (Size : 211 bytes)
    0x0007034B, // -> 0x00070375 (Size : 42 bytes)
    0x00070375, // -> 0x00070390 (Size : 27 bytes)
    0x00070390, // -> 0x00070427 (Size : 151 bytes)
    0x00070427, // -> 0x0007047B (Size : 84 bytes)
    0x0007047B, // -> 0x00070498 (Size : 29 bytes)
    0x00070498, // -> 0x000704BC (Size : 36 bytes)
    0x000704BC, // -> 0x000704D4 (Size : 24 bytes)
    0x000704D4, // -> 0x000704EF (Size : 27 bytes)
    0x000704EF, // -> 0x0007056F (Size : 128 bytes)
    0x0007058A, // -> 0x000705D8 (Size : 78 bytes)
    0x000705D8, // -> 0x00070626 (Size : 78 bytes)
    0x00070626, // -> 0x00070678 (Size : 82 bytes)
    0x00070678, // -> 0x000706CA (Size : 82 bytes)
    0x000706CA, // -> 0x000706E6 (Size : 28 bytes)
    0x000706E6, // -> 0x00070702 (Size : 28 bytes)
    0x00070702, // -> 0x00070722 (Size : 32 bytes)
    0x00070722, // -> 0x00070727 (Size : 5 bytes)
    0x00070727, // -> 0x0007072C (Size : 5 bytes)
    0x0007072C, // -> 0x000707F5 (Size : 201 bytes)
    0x000707F5, // -> 0x00070842 (Size : 77 bytes)
    0x00070842, // -> 0x000708C8 (Size : 134 bytes)
    0x000708C8, // -> 0x0007090C (Size : 68 bytes)
    0x0007090C, // -> 0x00070998 (Size : 140 bytes)
    0x00070998, // -> 0x00070A46 (Size : 174 bytes)
    0x00070A46, // -> 0x00070A6B (Size : 37 bytes)
    0x00070A6B, // -> 0x00070CAB (Size : 576 bytes)
    0x00070CAB, // -> 0x00070CF9 (Size : 78 bytes)
    0x00070CF9, // -> 0x00070D4B (Size : 82 bytes)
    0x00070D4B, // -> 0x00070D67 (Size : 28 bytes)
    0x00070D67, // -> 0x00070D87 (Size : 32 bytes)
    0x00070D87, // -> 0x00070D8C (Size : 5 bytes)
    0x00070D8C, // -> 0x00070D91 (Size : 5 bytes)
    0x00070D91, // -> 0x00070E20 (Size : 143 bytes)
    0x00070E20, // -> 0x00070EBA (Size : 154 bytes)
    0x00070EBA, // -> 0x00070ED5 (Size : 27 bytes)
    0x00070ED5, // -> 0x00070FD7 (Size : 258 bytes)
    0x00070FD7, // -> 0x00070FFC (Size : 37 bytes)
    0x00070FFC, // -> 0x00071061 (Size : 101 bytes)
    0x00071061, // -> 0x00071148 (Size : 231 bytes)
    0x00071148, // -> 0x00071169 (Size : 33 bytes)
    0x00071169, // -> 0x000711A2 (Size : 57 bytes)
    0x000711A2, // -> 0x0007124C (Size : 170 bytes)
    0x0007124C, // -> 0x00071264 (Size : 24 bytes)
    0x00071264, // -> 0x00071300 (Size : 156 bytes)
    0x00071300, // -> 0x00071391 (Size : 145 bytes)
    0x00071391, // -> 0x00071499 (Size : 264 bytes)
    0x00071499, // -> 0x000714B4 (Size : 27 bytes)
    0x000714B4, // -> 0x000714D8 (Size : 36 bytes)
    0x000714D8, // -> 0x000714FC (Size : 36 bytes)
    0x000714FC, // -> 0x0007151C (Size : 32 bytes)
    0x0007151C, // -> 0x00071655 (Size : 313 bytes)
    0x00071655, // -> 0x000716C2 (Size : 109 bytes)
    0x000716C2, // -> 0x00071709 (Size : 71 bytes)
    0x00071709, // -> 0x00071760 (Size : 87 bytes)
    0x00071760, // -> 0x000717A7 (Size : 71 bytes)
    0x000717A7, // -> 0x000717BF (Size : 24 bytes)
    0x000717BF, // -> 0x0007180E (Size : 79 bytes)
    0x0007180E, // -> 0x00071826 (Size : 24 bytes)
    0x00071826, // -> 0x0007188E (Size : 104 bytes)
    0x0007188E, // -> 0x000718C2 (Size : 52 bytes)
    0x000718C2, // -> 0x0007190C (Size : 74 bytes)
    0x0007190C, // -> 0x0007194F (Size : 67 bytes)
    0x0007194F, // -> 0x00071978 (Size : 41 bytes)
    0x00071978, // -> 0x0007199F (Size : 39 bytes)
    0x0007199F, // -> 0x000719E8 (Size : 73 bytes)
    0x000719E8, // -> 0x00071A2B (Size : 67 bytes)
    0x00071A41, // -> 0x00071A68 (Size : 39 bytes)
    0x00071A68, // -> 0x00071A9F (Size : 55 bytes)
    0x00071A9F, // -> 0x00071AE8 (Size : 73 bytes)
    0x00071AE8, // -> 0x00071B25 (Size : 61 bytes)
    0x00071B25, // -> 0x00071B6E (Size : 73 bytes)
    0x00071B6E, // -> 0x00071CD1 (Size : 355 bytes)
    0x00071CD1, // -> 0x00071D67 (Size : 150 bytes)
    0x00071D67, // -> 0x00071DB2 (Size : 75 bytes)
    0x00071DB2, // -> 0x00071EC3 (Size : 273 bytes)
    0x00071EC3, // -> 0x00071F53 (Size : 144 bytes)
    0x00071F53, // -> 0x00072022 (Size : 207 bytes)
    0x00072022, // -> 0x000720C4 (Size : 162 bytes)
    0x000720C4, // -> 0x0007213D (Size : 121 bytes)
    0x0007213D, // -> 0x00072259 (Size : 284 bytes)
    0x00072259, // -> 0x000722C8 (Size : 111 bytes)
    0x000722C8, // -> 0x000722E7 (Size : 31 bytes)
    0x000722E7, // -> 0x0007235C (Size : 117 bytes)
    0x0007235C, // -> 0x000724D1 (Size : 373 bytes)
    0x000724D1, // -> 0x000724F8 (Size : 39 bytes)
    0x000724F8, // -> 0x0007255D (Size : 101 bytes)
    0x0007255D, // -> 0x00072571 (Size : 20 bytes)
    0x00072571, // -> 0x00072588 (Size : 23 bytes)
    0x00072588, // -> 0x000725C9 (Size : 65 bytes)
    0x000725C9, // -> 0x00072662 (Size : 153 bytes)
    0x00072662, // -> 0x0007270B (Size : 169 bytes)
    0x0007270B, // -> 0x00072745 (Size : 58 bytes)
    0x00072745, // -> 0x0007276F (Size : 42 bytes)
    0x0007276F, // -> 0x00072807 (Size : 152 bytes)
    0x00072807, // -> 0x0007286A (Size : 99 bytes)
    0x0007286A, // -> 0x000728FB (Size : 145 bytes)
    0x000728FB, // -> 0x00072968 (Size : 109 bytes)
    0x00072968, // -> 0x000729CB (Size : 99 bytes)
    0x000729CB, // -> 0x00072A44 (Size : 121 bytes)
    0x00072A44, // -> 0x00072A70 (Size : 44 bytes)
    0x00072A70, // -> 0x00072ADE (Size : 110 bytes)
    0x00072ADE, // -> 0x00072B2E (Size : 80 bytes)
    0x00072B2E, // -> 0x00072B53 (Size : 37 bytes)
    0x00072B53, // -> 0x00072BB5 (Size : 98 bytes)
    0x00072BB5, // -> 0x00072C37 (Size : 130 bytes)
    0x00072C37, // -> 0x00072CC9 (Size : 146 bytes)
    0x00072CC9, // -> 0x00072D00 (Size : 55 bytes)
    0x00072D00, // -> 0x00072D45 (Size : 69 bytes)
    0x00072D45, // -> 0x00072D6C (Size : 39 bytes)
    0x00072D6C, // -> 0x00072D7D (Size : 17 bytes)
    0x00072D7D, // -> 0x00072E34 (Size : 183 bytes)
    0x00072E34, // -> 0x00072E40 (Size : 12 bytes)
    0x00072E40, // -> 0x00072E5C (Size : 28 bytes)
    0x00072E5C, // -> 0x00072F07 (Size : 171 bytes)
    0x00072F07, // -> 0x00072F49 (Size : 66 bytes)
    0x00072F49, // -> 0x00072F5F (Size : 22 bytes)
    0x00072F5F, // -> 0x00072FA3 (Size : 68 bytes)
    0x00072FA3, // -> 0x00072FAF (Size : 12 bytes)
    0x00072FAF, // -> 0x00072FCA (Size : 27 bytes)
    0x00072FCA, // -> 0x00073011 (Size : 71 bytes)
    0x00073011, // -> 0x000730E7 (Size : 214 bytes)
    0x000730E7, // -> 0x0007313C (Size : 85 bytes)
    0x0007313C, // -> 0x00073183 (Size : 71 bytes)
    0x0007318F, // -> 0x00073281 (Size : 242 bytes)
    0x00073281, // -> 0x0007329F (Size : 30 bytes)
    0x0007329F, // -> 0x000732E3 (Size : 68 bytes)
    0x000732E3, // -> 0x000732FE (Size : 27 bytes)
    0x000732FE, // -> 0x0007331C (Size : 30 bytes)
    0x0007331C, // -> 0x00073335 (Size : 25 bytes)
    0x00073335, // -> 0x00073357 (Size : 34 bytes)
    0x00073357, // -> 0x0007336F (Size : 24 bytes)
    0x0007336F, // -> 0x00073416 (Size : 167 bytes)
    0x00073416, // -> 0x00073488 (Size : 114 bytes)
    0x00073488, // -> 0x000734E2 (Size : 90 bytes)
    0x000734E2, // -> 0x0007350F (Size : 45 bytes)
    0x0007350F, // -> 0x00073672 (Size : 355 bytes)
    0x00073672, // -> 0x00073747 (Size : 213 bytes)
    0x00073747, // -> 0x00073793 (Size : 76 bytes)
    0x00073793, // -> 0x000737D3 (Size : 64 bytes)
    0x000737D3, // -> 0x00073802 (Size : 47 bytes)
    0x00073802, // -> 0x0007381C (Size : 26 bytes)
    0x0007381C, // -> 0x00073831 (Size : 21 bytes)
    0x00073831, // -> 0x000738DC (Size : 171 bytes)
    0x000738DC, // -> 0x00073915 (Size : 57 bytes)
    0x00073915, // -> 0x0007397C (Size : 103 bytes)
    0x0007397C, // -> 0x000739F2 (Size : 118 bytes)
    0x000739F2, // -> 0x00073A1A (Size : 40 bytes)
    0x00073A1A, // -> 0x00073A47 (Size : 45 bytes)
    0x00073A47, // -> 0x00073B0A (Size : 195 bytes)
    0x00073B0A, // -> 0x00073BEA (Size : 224 bytes)
    0x00073BEA, // -> 0x00073BFA (Size : 16 bytes)
    0x00073BFA, // -> 0x00073CDE (Size : 228 bytes)
    0x00073CDE, // -> 0x00073D66 (Size : 136 bytes)
    0x00073D66, // -> 0x00073DC3 (Size : 93 bytes)
    0x00073DC3, // -> 0x00073EB2 (Size : 239 bytes)
    0x00073EB2, // -> 0x00073F80 (Size : 206 bytes)
    0x00073F80, // -> 0x0007400E (Size : 142 bytes)
    0x0007400E, // -> 0x00074059 (Size : 75 bytes)
    0x00074059, // -> 0x00074074 (Size : 27 bytes)
    0x00074074, // -> 0x000740FD (Size : 137 bytes)
    0x000740FD, // -> 0x0007411B (Size : 30 bytes)
    0x0007411B, // -> 0x00074151 (Size : 54 bytes)
    0x00074151, // -> 0x00074178 (Size : 39 bytes)
    0x00074178, // -> 0x00074198 (Size : 32 bytes)
    0x00074198, // -> 0x000741BA (Size : 34 bytes)
    0x000741BA, // -> 0x00074245 (Size : 139 bytes)
    0x00074245, // -> 0x00074316 (Size : 209 bytes)
    0x00074316, // -> 0x00074337 (Size : 33 bytes)
    0x00074337, // -> 0x000743A4 (Size : 109 bytes)
    0x000743A4, // -> 0x000743BB (Size : 23 bytes)
    0x000743BB, // -> 0x000743E0 (Size : 37 bytes)
    0x000743E0, // -> 0x00074441 (Size : 97 bytes)
    0x00074441, // -> 0x000744C5 (Size : 132 bytes)
    0x000744C5, // -> 0x000745A6 (Size : 225 bytes)
    0x000745A6, // -> 0x000745C1 (Size : 27 bytes)
    0x000745C1, // -> 0x000745DC (Size : 27 bytes)
    0x000745DC, // -> 0x0007466B (Size : 143 bytes)
    0x0007466B, // -> 0x000746C7 (Size : 92 bytes)
    0x000746C7, // -> 0x000746E2 (Size : 27 bytes)
    0x000746E2, // -> 0x0007477B (Size : 153 bytes)
    0x0007477B, // -> 0x000747C6 (Size : 75 bytes)
    0x000747DC, // -> 0x000747E0 (Size : 4 bytes)
    0x000747E0, // -> 0x000747E4 (Size : 4 bytes)
    0x000747E4, // -> 0x00074806 (Size : 34 bytes)
    0x00074806, // -> 0x00074822 (Size : 28 bytes)
    0x00074822, // -> 0x0007486D (Size : 75 bytes)
    0x0007486D, // -> 0x00074980 (Size : 275 bytes)
    0x00074980, // -> 0x00074A08 (Size : 136 bytes)
    0x00074A08, // -> 0x00074AB9 (Size : 177 bytes)
    0x00074AB9, // -> 0x00074D0D (Size : 596 bytes)
    0x00074D0D, // -> 0x00074D8F (Size : 130 bytes)
    0x00074D8F, // -> 0x00074E03 (Size : 116 bytes)
    0x00074E03, // -> 0x00074FDF (Size : 476 bytes)
    0x00074FDF, // -> 0x00075044 (Size : 101 bytes)
    0x00075044, // -> 0x000750C8 (Size : 132 bytes)
    0x000750C8, // -> 0x0007511C (Size : 84 bytes)
    0x0007511C, // -> 0x00075202 (Size : 230 bytes)
    0x00075202, // -> 0x00075371 (Size : 367 bytes)
    0x00075371, // -> 0x000754A0 (Size : 303 bytes)
    0x000754A0, // -> 0x00075632 (Size : 402 bytes)
    0x00075632, // -> 0x0007577C (Size : 330 bytes)
    0x0007577C, // -> 0x00075807 (Size : 139 bytes)
    0x00075807, // -> 0x00075996 (Size : 399 bytes)
    0x00075996, // -> 0x000759B4 (Size : 30 bytes)
    0x000759B4, // -> 0x000759CB (Size : 23 bytes)
    0x000759CB, // -> 0x00075B45 (Size : 378 bytes)
    0x00075B45, // -> 0x00075C06 (Size : 193 bytes)
    0x00075C06, // -> 0x00075C9E (Size : 152 bytes)
    0x00075C9E, // -> 0x00075D30 (Size : 146 bytes)
    0x00075D30, // -> 0x00075D4C (Size : 28 bytes)
    0x00075D4C, // -> 0x00075DB5 (Size : 105 bytes)
    0x00075DB5, // -> 0x00075E1A (Size : 101 bytes)
    0x00075E1A, // -> 0x00075F54 (Size : 314 bytes)
    0x00075F54, // -> 0x00075FD9 (Size : 133 bytes)
    0x00075FD9, // -> 0x000760E6 (Size : 269 bytes)
    0x000760E6, // -> 0x000761ED (Size : 263 bytes)
    0x000761ED, // -> 0x00076225 (Size : 56 bytes)
    0x00076225, // -> 0x000763F1 (Size : 460 bytes)
    0x000763F1, // -> 0x0007640C (Size : 27 bytes)
    0x0007640C, // -> 0x0007647E (Size : 114 bytes)
    0x0007647E, // -> 0x000764C1 (Size : 67 bytes)
    0x000764C1, // -> 0x00076602 (Size : 321 bytes)
    0x00076602, // -> 0x00076781 (Size : 383 bytes)
    0x00076781, // -> 0x000767F4 (Size : 115 bytes)
    0x000767F4, // -> 0x00076836 (Size : 66 bytes)
    0x00076836, // -> 0x00076915 (Size : 223 bytes)
    0x00076915, // -> 0x0007695C (Size : 71 bytes)
    0x0007695C, // -> 0x000769BD (Size : 97 bytes)
    0x000769BD, // -> 0x000769F7 (Size : 58 bytes)
    0x000769F7, // -> 0x00076A26 (Size : 47 bytes)
    0x00076A26, // -> 0x00076A40 (Size : 26 bytes)
    0x00076A40, // -> 0x00076A9C (Size : 92 bytes)
    0x00076A9C, // -> 0x00076B01 (Size : 101 bytes)
    0x00076B01, // -> 0x00076B53 (Size : 82 bytes)
    0x00076B53, // -> 0x00076BF2 (Size : 159 bytes)
    0x00076BF2, // -> 0x00076C40 (Size : 78 bytes)
    0x00076C40, // -> 0x00076CF0 (Size : 176 bytes)
    0x00076CF0, // -> 0x00076D3B (Size : 75 bytes)
    0x00076D3B, // -> 0x00076D59 (Size : 30 bytes)
    0x00076D59, // -> 0x00076DE9 (Size : 144 bytes)
    0x00076DE9, // -> 0x00076EDF (Size : 246 bytes)
    0x00076EDF, // -> 0x00076F03 (Size : 36 bytes)
    0x00076F03, // -> 0x00076F1D (Size : 26 bytes)
    0x00076F1D, // -> 0x00076F6A (Size : 77 bytes)
    0x00076F6A, // -> 0x00076FC2 (Size : 88 bytes)
    0x00076FC2, // -> 0x00076FFB (Size : 57 bytes)
    0x00076FFB, // -> 0x00077016 (Size : 27 bytes)
    0x00077016, // -> 0x00077053 (Size : 61 bytes)
    0x00077053, // -> 0x00077084 (Size : 49 bytes)
    0x00077084, // -> 0x000770D3 (Size : 79 bytes)
    0x000770D3, // -> 0x000770EE (Size : 27 bytes)
    0x000770EE, // -> 0x000770F7 (Size : 9 bytes)
    0x000770F7, // -> 0x00077145 (Size : 78 bytes)
    0x00077145, // -> 0x000771D3 (Size : 142 bytes)
    0x000771D3, // -> 0x0007720C (Size : 57 bytes)
    0x0007720C, // -> 0x0007722A (Size : 30 bytes)
    0x0007722A, // -> 0x00077262 (Size : 56 bytes)
    0x00077262, // -> 0x000772FC (Size : 154 bytes)
    0x000772FC, // -> 0x00077379 (Size : 125 bytes)
    0x00077379, // -> 0x000773C6 (Size : 77 bytes)
    0x000773C6, // -> 0x00077483 (Size : 189 bytes)
    0x00077483, // -> 0x0007750F (Size : 140 bytes)
    0x0007750F, // -> 0x00077570 (Size : 97 bytes)
    0x00077570, // -> 0x0007761B (Size : 171 bytes)
    0x0007761B, // -> 0x0007774A (Size : 303 bytes)
    0x0007774A, // -> 0x00077834 (Size : 234 bytes)
    0x00077834, // -> 0x00077BBC (Size : 904 bytes)
    0x00077BBC, // -> 0x00077BD6 (Size : 26 bytes)
    0x00077BD6, // -> 0x00077C04 (Size : 46 bytes)
    0x00077C04, // -> 0x00077CB7 (Size : 179 bytes)
    0x00077CB7, // -> 0x00077D09 (Size : 82 bytes)
    0x00077D09, // -> 0x00077D31 (Size : 40 bytes)
    0x00077D31, // -> 0x00077E09 (Size : 216 bytes)
    0x00077E09, // -> 0x00077E82 (Size : 121 bytes)
    0x00077E82, // -> 0x00077EAF (Size : 45 bytes)
    0x00077EAF, // -> 0x00077F7E (Size : 207 bytes)
    0x00077F7E, // -> 0x00078051 (Size : 211 bytes)
    0x00078051, // -> 0x00078190 (Size : 319 bytes)
    0x00078190, // -> 0x00078334 (Size : 420 bytes)
    0x00078334, // -> 0x000783ED (Size : 185 bytes)
    0x000783ED, // -> 0x00078424 (Size : 55 bytes)
    0x00078424, // -> 0x0007845B (Size : 55 bytes)
    0x0007845B, // -> 0x000784B6 (Size : 91 bytes)
    0x000784B6, // -> 0x00078518 (Size : 98 bytes)
    0x00078518, // -> 0x0007858F (Size : 119 bytes)
    0x0007858F, // -> 0x000785CC (Size : 61 bytes)
    0x000785CC, // -> 0x0007860B (Size : 63 bytes)
    0x0007860B, // -> 0x00078685 (Size : 122 bytes)
    0x00078685, // -> 0x000786B1 (Size : 44 bytes)
    0x000786B1, // -> 0x000786D4 (Size : 35 bytes)
    0x000786D4, // -> 0x00078779 (Size : 165 bytes)
    0x00078779, // -> 0x00078846 (Size : 205 bytes)
    0x00078846, // -> 0x000789C6 (Size : 384 bytes)
    0x000789C6, // -> 0x00078AA3 (Size : 221 bytes)
    0x00078AA3, // -> 0x00078ABE (Size : 27 bytes)
    0x00078ABE, // -> 0x00078B3B (Size : 125 bytes)
    0x00078B3B, // -> 0x00078BA7 (Size : 108 bytes)
    0x00078BA7, // -> 0x00078BAF (Size : 8 bytes)
    0x00078BAF, // -> 0x00078BDC (Size : 45 bytes)
    0x00078BDC, // -> 0x00078C2C (Size : 80 bytes)
    0x00078C2C, // -> 0x00078C40 (Size : 20 bytes)
    0x00078C40, // -> 0x00078C5D (Size : 29 bytes)
    0x00078C5D, // -> 0x00078C75 (Size : 24 bytes)
    0x00078C75, // -> 0x00078CA4 (Size : 47 bytes)
    0x00078CA4, // -> 0x00078D34 (Size : 144 bytes)
    0x00078D34, // -> 0x00078D65 (Size : 49 bytes)
    0x00078D65, // -> 0x00078D93 (Size : 46 bytes)
    0x00078D93, // -> 0x00078DA1 (Size : 14 bytes)
    0x00078DA1, // -> 0x00078E09 (Size : 104 bytes)
    0x00078E09, // -> 0x00078E9A (Size : 145 bytes)
    0x00078E9A, // -> 0x00078F0C (Size : 114 bytes)
    0x00078F0C, // -> 0x00078F5A (Size : 78 bytes)
    0x00078F5A, // -> 0x00078FB4 (Size : 90 bytes)
    0x00078FB4, // -> 0x00079056 (Size : 162 bytes)
    0x00079056, // -> 0x000790A4 (Size : 78 bytes)
    0x000790A4, // -> 0x000790FB (Size : 87 bytes)
    0x000790FB, // -> 0x000791CF (Size : 212 bytes)
    0x000791CF, // -> 0x00079228 (Size : 89 bytes)
    0x00079245, // -> 0x00079284 (Size : 63 bytes)
    0x00079284, // -> 0x000792F3 (Size : 111 bytes)
    0x000792F3, // -> 0x00079302 (Size : 15 bytes)
    0x0007930F, // -> 0x000793EE (Size : 223 bytes)
    0x000793EE, // -> 0x000793F4 (Size : 6 bytes)
    0x000793F4, // -> 0x00079492 (Size : 158 bytes)
    0x00079492, // -> 0x0007949F (Size : 13 bytes)
    0x0007949F, // -> 0x000794A3 (Size : 4 bytes)
    0x000794A3, // -> 0x0007951A (Size : 119 bytes)
    0x0007951A, // -> 0x00079542 (Size : 40 bytes)
    0x00079542, // -> 0x00079587 (Size : 69 bytes)
    0x00079587, // -> 0x000795A4 (Size : 29 bytes)
    0x000795A4, // -> 0x000796D6 (Size : 306 bytes)
    0x0008CA20, // -> 0x0008CA38 (Size : 24 bytes)
    0x0008CA7C, // -> 0x0008CB10 (Size : 148 bytes)
    0x0008CB10, // -> 0x0008CBCD (Size : 189 bytes)
    0x0008CBCD, // -> 0x0008CC31 (Size : 100 bytes)
    0x0008CC31, // -> 0x0008CCF4 (Size : 195 bytes)
    0x0008CCF4, // -> 0x0008CD5B (Size : 103 bytes)
    0x0008CD5B, // -> 0x0008CE0F (Size : 180 bytes)
    0x0008CE0F, // -> 0x0008CEDF (Size : 208 bytes)
    0x0008D059, // -> 0x0008D117 (Size : 190 bytes)
    0x0008D117, // -> 0x0008D185 (Size : 110 bytes)
    0x0008D1E7, // -> 0x0008D207 (Size : 32 bytes)
    0x0008D25E, // -> 0x0008D283 (Size : 37 bytes)
    0x0008D283, // -> 0x0008D2F7 (Size : 116 bytes)
    0x0008D32D, // -> 0x0008D389 (Size : 92 bytes)
    0x0008D389, // -> 0x0008D546 (Size : 445 bytes)
    0x0008D546, // -> 0x0008D62D (Size : 231 bytes)
    0x0008D62D, // -> 0x0008D679 (Size : 76 bytes)
    0x0008D679, // -> 0x0008D754 (Size : 219 bytes)
    0x0008D754, // -> 0x0008D9B2 (Size : 606 bytes)
    0x0008D9B2, // -> 0x0008DB2F (Size : 381 bytes)
    0x0008DB2F, // -> 0x0008DBF6 (Size : 199 bytes)
    0x0008DF28, // -> 0x0008DFFC (Size : 212 bytes)
    0x0008DFFC, // -> 0x0008E035 (Size : 57 bytes)
    0x0008E035, // -> 0x0008E0A8 (Size : 115 bytes)
    0x0008E0A8, // -> 0x0008E15F (Size : 183 bytes)
    0x0008E15F, // -> 0x0008E250 (Size : 241 bytes)
    0x0008E250, // -> 0x0008E309 (Size : 185 bytes)
    0x0008E309, // -> 0x0008E600 (Size : 759 bytes)
    0x0008E600, // -> 0x0008E806 (Size : 518 bytes)
    0x0008E806, // -> 0x0008E8A6 (Size : 160 bytes)
    0x0008E8A6, // -> 0x0008EBF8 (Size : 850 bytes)
    0x0008EBF8, // -> 0x0008ECD9 (Size : 225 bytes)
    0x0008ECD9, // -> 0x0008EE42 (Size : 361 bytes)
    0x0008EE42, // -> 0x0008F24A (Size : 1032 bytes)
    0x0008F24A, // -> 0x0008F544 (Size : 762 bytes)
    0x0008F544, // -> 0x0008F5BE (Size : 122 bytes)
    0x0008F5BE, // -> 0x0008F5EA (Size : 44 bytes)
    0x0008F5EA, // -> 0x0008F608 (Size : 30 bytes)
    0x0008F608, // -> 0x0008F626 (Size : 30 bytes)
    0x0008F626, // -> 0x0008F64B (Size : 37 bytes)
    0x0008F64B, // -> 0x0008F675 (Size : 42 bytes)
    0x0008F675, // -> 0x0008F699 (Size : 36 bytes)
    0x0008F699, // -> 0x0008F752 (Size : 185 bytes)
    0x0008F752, // -> 0x0008F92E (Size : 476 bytes)
    0x0008F92E, // -> 0x0008F962 (Size : 52 bytes)
    0x0008F962, // -> 0x0008FB3C (Size : 474 bytes)
    0x0008FB3C, // -> 0x0008FCD4 (Size : 408 bytes)
    0x0008FCD4, // -> 0x0008FD05 (Size : 49 bytes)
    0x0008FF6E, // -> 0x0009002B (Size : 189 bytes)
    0x000902F6, // -> 0x00090505 (Size : 527 bytes)
    0x00090505, // -> 0x000905E6 (Size : 225 bytes)
    0x000905E6, // -> 0x000905FE (Size : 24 bytes)
    0x000905FE, // -> 0x00090601 (Size : 3 bytes)
    0x00090601, // -> 0x00090604 (Size : 3 bytes)
    0x00090604, // -> 0x00090611 (Size : 13 bytes)
    0x00090611, // -> 0x0009061E (Size : 13 bytes)
    0x0009061E, // -> 0x000908BE (Size : 672 bytes)
    0x000908BE, // -> 0x000909D4 (Size : 278 bytes)
    0x000909D4, // -> 0x00090F6F (Size : 1435 bytes)
    0x00090F6F, // -> 0x0009127D (Size : 782 bytes)
    0x0009127D, // -> 0x000914E8 (Size : 619 bytes)
    0x000914E8, // -> 0x00091554 (Size : 108 bytes)
    0x00091554, // -> 0x000915C5 (Size : 113 bytes)
    0x000915C5, // -> 0x000915FF (Size : 58 bytes)
    0x000915FF, // -> 0x000918BF (Size : 704 bytes)
    0x000918BF, // -> 0x0009193F (Size : 128 bytes)
    0x0009193F, // -> 0x00091998 (Size : 89 bytes)
    0x00091998, // -> 0x000919D6 (Size : 62 bytes)
    0x000919D6, // -> 0x00091A13 (Size : 61 bytes)
    0x00091A13, // -> 0x00091A50 (Size : 61 bytes)
    0x00091A50, // -> 0x00091BF2 (Size : 418 bytes)
    0x00091BF2, // -> 0x00091E8B (Size : 665 bytes)
    0x00091E8B, // -> 0x00091ED7 (Size : 76 bytes)
    0x00091ED7, // -> 0x00091F6F (Size : 152 bytes)
    0x00091F6F, // -> 0x00092299 (Size : 810 bytes)
    0x00092299, // -> 0x000922D4 (Size : 59 bytes)
    0x000922D4, // -> 0x000922ED (Size : 25 bytes)
    0x000922ED, // -> 0x00092479 (Size : 396 bytes)
    0x00092479, // -> 0x000924D8 (Size : 95 bytes)
    0x000925DD, // -> 0x0009264C (Size : 111 bytes)
    0x0009264C, // -> 0x000926BE (Size : 114 bytes)
    0x000926BE, // -> 0x00092764 (Size : 166 bytes)
    0x00092764, // -> 0x00092842 (Size : 222 bytes)
    0x00092842, // -> 0x0009327E (Size : 2620 bytes)
    0x0009327E, // -> 0x00093F04 (Size : 3206 bytes)
    0x000948EA, // -> 0x00094A41 (Size : 343 bytes)
    0x00094ABE, // -> 0x00094B8D (Size : 207 bytes)
    0x00094B8D, // -> 0x00094CBB (Size : 302 bytes)
    0x00094CBB, // -> 0x00094EDB (Size : 544 bytes)
    0x00094EDB, // -> 0x00095011 (Size : 310 bytes)
    0x00095011, // -> 0x00095597 (Size : 1414 bytes)
    0x00095621, // -> 0x0009562A (Size : 9 bytes)
    0x0009562A, // -> 0x00095986 (Size : 860 bytes)
    0x00095986, // -> 0x00095D06 (Size : 896 bytes)
    0x00095D06, // -> 0x00095D9A (Size : 148 bytes)
    0x00096370, // -> 0x00096650 (Size : 736 bytes)
    0x00096AD5, // -> 0x00096B2D (Size : 88 bytes)
    0x00096B2D, // -> 0x00096C40 (Size : 275 bytes)
    0x00096C40, // -> 0x00096D3F (Size : 255 bytes)
    0x00096D3F, // -> 0x00096E65 (Size : 294 bytes)
    0x00096E65, // -> 0x00096E9B (Size : 54 bytes)
    0x00096E9B, // -> 0x00096EF6 (Size : 91 bytes)
    0x00096EF6, // -> 0x00097125 (Size : 559 bytes)
    0x00097125, // -> 0x000978C6 (Size : 1953 bytes)
    0x000978C6, // -> 0x0009798B (Size : 197 bytes)
    0x000A5AA0, // -> 0x000A5ABE (Size : 30 bytes)
    0x000A5ABE, // -> 0x000A5AFD (Size : 63 bytes)
    0x000A5AFD, // -> 0x000A5B40 (Size : 67 bytes)
    0x000A5B40, // -> 0x000A5B83 (Size : 67 bytes)
    0x000A5B83, // -> 0x000A5BEC (Size : 105 bytes)
    0x000A5BEC, // -> 0x000A5C40 (Size : 84 bytes)
    0x000A5C40, // -> 0x000A5C75 (Size : 53 bytes)
    0x000A5C75, // -> 0x000A5C8D (Size : 24 bytes)
    0x000A5C8D, // -> 0x000A5CC0 (Size : 51 bytes)
    0x000A5CC0, // -> 0x000A5CE9 (Size : 41 bytes)
    0x000A5CE9, // -> 0x000A5D12 (Size : 41 bytes)
    0x000A5D12, // -> 0x000A5D17 (Size : 5 bytes)
    0x000A5D17, // -> 0x000A5D39 (Size : 34 bytes)
    0x000A5D39, // -> 0x000A5D50 (Size : 23 bytes)
    0x000A5D50, // -> 0x000A5E07 (Size : 183 bytes)
    0x000A5E07, // -> 0x000A5E27 (Size : 32 bytes)
    0x000A5E27, // -> 0x000A5E4F (Size : 40 bytes)
    0x000A5E4F, // -> 0x000A5F3A (Size : 235 bytes)
    0x000A5F3A, // -> 0x000A6058 (Size : 286 bytes)
    0x000A6058, // -> 0x000A60C0 (Size : 104 bytes)
    0x000A60C0, // -> 0x000A6126 (Size : 102 bytes)
    0x000A6126, // -> 0x000A61AF (Size : 137 bytes)
    0x000A61AF, // -> 0x000A61CB (Size : 28 bytes)
    0x000A61CB, // -> 0x000A6207 (Size : 60 bytes)
    0x000A6207, // -> 0x000A6253 (Size : 76 bytes)
    0x000A6253, // -> 0x000A6308 (Size : 181 bytes)
    0x000A6308, // -> 0x000A6321 (Size : 25 bytes)
    0x000A6321, // -> 0x000A63E0 (Size : 191 bytes)
    0x000A63E0, // -> 0x000A644C (Size : 108 bytes)
    0x000A644C, // -> 0x000A6482 (Size : 54 bytes)
    0x000A6482, // -> 0x000A649E (Size : 28 bytes)
    0x000A649E, // -> 0x000A64BA (Size : 28 bytes)
    0x000A64BA, // -> 0x000A64DD (Size : 35 bytes)
    0x000A64DD, // -> 0x000A64F9 (Size : 28 bytes)
    0x000A64F9, // -> 0x000A6562 (Size : 105 bytes)
    0x000A6562, // -> 0x000A65CA (Size : 104 bytes)
    0x000A65CA, // -> 0x000A670E (Size : 324 bytes)
    0x000A670E, // -> 0x000A673E (Size : 48 bytes)
    0x000A673E, // -> 0x000A6789 (Size : 75 bytes)
    0x000A6789, // -> 0x000A67F1 (Size : 104 bytes)
    0x000A67F1, // -> 0x000A686B (Size : 122 bytes)
    0x000A686B, // -> 0x000A68EA (Size : 127 bytes)
    0x000A68EA, // -> 0x000A694E (Size : 100 bytes)
    0x000A694E, // -> 0x000A69A8 (Size : 90 bytes)
    0x000A69A8, // -> 0x000A69ED (Size : 69 bytes)
    0x000A69ED, // -> 0x000A6A32 (Size : 69 bytes)
    0x000A6A32, // -> 0x000A6A79 (Size : 71 bytes)
    0x000A6A79, // -> 0x000A6AAA (Size : 49 bytes)
    0x000A6AAA, // -> 0x000A6B14 (Size : 106 bytes)
    0x000A6B14, // -> 0x000A6B4D (Size : 57 bytes)
    0x000A6B4D, // -> 0x000A6B6B (Size : 30 bytes)
    0x000A6B6B, // -> 0x000A6B87 (Size : 28 bytes)
    0x000A6B87, // -> 0x000A6CF2 (Size : 363 bytes)
    0x000A6CF2, // -> 0x000A6D2B (Size : 57 bytes)
    0x000A6D2B, // -> 0x000A6DEB (Size : 192 bytes)
    0x000A6DEB, // -> 0x000A6EE4 (Size : 249 bytes)
    0x000A6EE4, // -> 0x000A6F8D (Size : 169 bytes)
    0x000A6F8D, // -> 0x000A6FC4 (Size : 55 bytes)
    0x000A6FC4, // -> 0x000A70F0 (Size : 300 bytes)
    0x000A70F0, // -> 0x000A71DE (Size : 238 bytes)
    0x000A71DE, // -> 0x000A71FE (Size : 32 bytes)
    0x000A71FE, // -> 0x000A721E (Size : 32 bytes)
    0x000A721E, // -> 0x000A724D (Size : 47 bytes)
    0x000A724D, // -> 0x000A7306 (Size : 185 bytes)
    0x000A7306, // -> 0x000A7338 (Size : 50 bytes)
    0x000A7338, // -> 0x000A73DD (Size : 165 bytes)
    0x000A73DD, // -> 0x000A73FD (Size : 32 bytes)
    0x000A73FD, // -> 0x000A7435 (Size : 56 bytes)
    0x000A7435, // -> 0x000A750A (Size : 213 bytes)
    0x000A750A, // -> 0x000A755A (Size : 80 bytes)
    0x000A755A, // -> 0x000A781B (Size : 705 bytes)
    0x000A781B, // -> 0x000A783B (Size : 32 bytes)
    0x000A783B, // -> 0x000A78B7 (Size : 124 bytes)
    0x000A78B7, // -> 0x000A7909 (Size : 82 bytes)
    0x000A7909, // -> 0x000A7943 (Size : 58 bytes)
    0x000A7943, // -> 0x000A7976 (Size : 51 bytes)
    0x000A7976, // -> 0x000A79F5 (Size : 127 bytes)
    0x000A79F5, // -> 0x000A7A13 (Size : 30 bytes)
    0x000A7A13, // -> 0x000A7A47 (Size : 52 bytes)
    0x000A7A47, // -> 0x000A7C83 (Size : 572 bytes)
    0x000A7C83, // -> 0x000A7E3A (Size : 439 bytes)
    0x000A7E3A, // -> 0x000A7E9F (Size : 101 bytes)
    0x000A7E9F, // -> 0x000A7F64 (Size : 197 bytes)
    0x000A7F64, // -> 0x000A7F84 (Size : 32 bytes)
    0x000A7F84, // -> 0x000A7FD8 (Size : 84 bytes)
    0x000A7FD8, // -> 0x000A8115 (Size : 317 bytes)
    0x000A8115, // -> 0x000A821F (Size : 266 bytes)
    0x000A821F, // -> 0x000A832A (Size : 267 bytes)
    0x000A832A, // -> 0x000A8342 (Size : 24 bytes)
    0x000A8342, // -> 0x000A836B (Size : 41 bytes)
    0x000A836B, // -> 0x000A838C (Size : 33 bytes)
    0x000A838C, // -> 0x000A8472 (Size : 230 bytes)
    0x000A8472, // -> 0x000A8484 (Size : 18 bytes)
    0x000A8484, // -> 0x000A84AC (Size : 40 bytes)
    0x000A84AC, // -> 0x000A84E0 (Size : 52 bytes)
    0x000A84E0, // -> 0x000A8527 (Size : 71 bytes)
    0x000A8527, // -> 0x000A85C6 (Size : 159 bytes)
    0x000A85C6, // -> 0x000A85E6 (Size : 32 bytes)
    0x000A85E6, // -> 0x000A865D (Size : 119 bytes)
    0x000A865D, // -> 0x000A86BF (Size : 98 bytes)
    0x000A86BF, // -> 0x000A8722 (Size : 99 bytes)
    0x000A8722, // -> 0x000A873A (Size : 24 bytes)
    0x000A873A, // -> 0x000A8769 (Size : 47 bytes)
    0x000A8769, // -> 0x000A8883 (Size : 282 bytes)
    0x000A8883, // -> 0x000A88B1 (Size : 46 bytes)
    0x000A88B1, // -> 0x000A8904 (Size : 83 bytes)
    0x000A8904, // -> 0x000A8942 (Size : 62 bytes)
    0x000A8942, // -> 0x000A89A1 (Size : 95 bytes)
    0x000A89A1, // -> 0x000A89E7 (Size : 70 bytes)
    0x000A89E7, // -> 0x000A8A2D (Size : 70 bytes)
    0x000A8A2D, // -> 0x000A8A77 (Size : 74 bytes)
    0x000A8A77, // -> 0x000A8ABD (Size : 70 bytes)
    0x000A8ABD, // -> 0x000A8B03 (Size : 70 bytes)
    0x000A8B03, // -> 0x000A8B3D (Size : 58 bytes)
    0x000A8B3D, // -> 0x000A8B77 (Size : 58 bytes)
    0x000A8B77, // -> 0x000A8BBD (Size : 70 bytes)
    0x000A8BBD, // -> 0x000A8C03 (Size : 70 bytes)
    0x000A8C03, // -> 0x000A8C49 (Size : 70 bytes)
    0x000A8C49, // -> 0x000A8C8F (Size : 70 bytes)
    0x000A8C8F, // -> 0x000A8CC6 (Size : 55 bytes)
    0x000A8CC6, // -> 0x000A8D00 (Size : 58 bytes)
    0x000A8D00, // -> 0x000A8D46 (Size : 70 bytes)
    0x000A8D46, // -> 0x000A8D8C (Size : 70 bytes)
    0x000A8D8C, // -> 0x000A8DD2 (Size : 70 bytes)
    0x000A8DD2, // -> 0x000A8E0C (Size : 58 bytes)
    0x000A8E0C, // -> 0x000A8E3E (Size : 50 bytes)
    0x000A8E3E, // -> 0x000A8E7A (Size : 60 bytes)
    0x000A8E7A, // -> 0x000A8EAC (Size : 50 bytes)
    0x000A8EAC, // -> 0x000A8FB2 (Size : 262 bytes)
    0x000A8FB2, // -> 0x000A90A7 (Size : 245 bytes)
    0x000A90A7, // -> 0x000A90D1 (Size : 42 bytes)
    0x000A90D1, // -> 0x000A912C (Size : 91 bytes)
    0x000A912C, // -> 0x000A91C6 (Size : 154 bytes)
    0x000A91C6, // -> 0x000A91E6 (Size : 32 bytes)
    0x000A91E6, // -> 0x000A93A7 (Size : 449 bytes)
    0x000A93A7, // -> 0x000A94F1 (Size : 330 bytes)
    0x000A94F1, // -> 0x000A9571 (Size : 128 bytes)
    0x000A9571, // -> 0x000A95B2 (Size : 65 bytes)
    0x000A95B2, // -> 0x000A9761 (Size : 431 bytes)
    0x000A9761, // -> 0x000A97E1 (Size : 128 bytes)
    0x000A97E1, // -> 0x000A984A (Size : 105 bytes)
    0x000A984A, // -> 0x000A98CA (Size : 128 bytes)
    0x000A98CA, // -> 0x000A9913 (Size : 73 bytes)
    0x000A9913, // -> 0x000A9956 (Size : 67 bytes)
    0x000A9956, // -> 0x000A999C (Size : 70 bytes)
    0x000A999C, // -> 0x000A99DF (Size : 67 bytes)
    0x000A99DF, // -> 0x000A9A25 (Size : 70 bytes)
    0x000A9A25, // -> 0x000A9A6B (Size : 70 bytes)
    0x000A9A6B, // -> 0x000A9AB1 (Size : 70 bytes)
    0x000A9AB1, // -> 0x000A9B2F (Size : 126 bytes)
    0x000A9B2F, // -> 0x000A9B7F (Size : 80 bytes)
    0x000A9B7F, // -> 0x000A9C1E (Size : 159 bytes)
    0x000A9C1E, // -> 0x000A9C53 (Size : 53 bytes)
    0x000A9C53, // -> 0x000A9C88 (Size : 53 bytes)
    0x000A9C88, // -> 0x000A9CCE (Size : 70 bytes)
    0x000A9CCE, // -> 0x000A9D03 (Size : 53 bytes)
    0x000A9D03, // -> 0x000A9D1B (Size : 24 bytes)
    0x000A9D1B, // -> 0x000A9D3E (Size : 35 bytes)
    0x000A9D3E, // -> 0x000A9D79 (Size : 59 bytes)
    0x000A9D79, // -> 0x000A9E2D (Size : 180 bytes)
    0x000A9E2D, // -> 0x000A9E43 (Size : 22 bytes)
    0x000A9E43, // -> 0x000A9EA7 (Size : 100 bytes)
    0x000A9EA7, // -> 0x000A9F0C (Size : 101 bytes)
    0x000A9F0C, // -> 0x000A9FA4 (Size : 152 bytes)
    0x000A9FA4, // -> 0x000AA017 (Size : 115 bytes)
    0x000AA017, // -> 0x000AA085 (Size : 110 bytes)
    0x000AA085, // -> 0x000AA139 (Size : 180 bytes)
    0x000AA139, // -> 0x000AA1AF (Size : 118 bytes)
    0x000AA1AF, // -> 0x000AA20A (Size : 91 bytes)
    0x000AA20A, // -> 0x000AA4BE (Size : 692 bytes)
    0x000AA4BE, // -> 0x000AA5A8 (Size : 234 bytes)
    0x000AA5A8, // -> 0x000AA622 (Size : 122 bytes)
    0x000AA622, // -> 0x000AA642 (Size : 32 bytes)
    0x000AA642, // -> 0x000AA65A (Size : 24 bytes)
    0x000AA65A, // -> 0x000AA6A7 (Size : 77 bytes)
    0x000AA6C6, // -> 0x000AA6FB (Size : 53 bytes)
    0x000AA6FB, // -> 0x000AA70D (Size : 18 bytes)
    0x000AA70D, // -> 0x000AA73F (Size : 50 bytes)
    0x000AA73F, // -> 0x000AA770 (Size : 49 bytes)
    0x000AA770, // -> 0x000AA7A5 (Size : 53 bytes)
    0x000AA7A5, // -> 0x000AA7C6 (Size : 33 bytes)
    0x000AA7C6, // -> 0x000AA7E5 (Size : 31 bytes)
    0x000AA7E5, // -> 0x000AA88B (Size : 166 bytes)
    0x000AA88B, // -> 0x000AA947 (Size : 188 bytes)
    0x000AA947, // -> 0x000AA9A0 (Size : 89 bytes)
    0x000AA9A0, // -> 0x000AA9ED (Size : 77 bytes)
    0x000AA9ED, // -> 0x000AAA5B (Size : 110 bytes)
    0x000AAA83, // -> 0x000AABC3 (Size : 320 bytes)
    0x000AABC3, // -> 0x000AABF0 (Size : 45 bytes)
    0x000AABFD, // -> 0x000AAC00 (Size : 3 bytes)
    0x000AAC00, // -> 0x000AAD71 (Size : 369 bytes)
    0x000AAD71, // -> 0x000AAD9C (Size : 43 bytes)
    0x000AAD9C, // -> 0x000AADBF (Size : 35 bytes)
    0x000AADBF, // -> 0x000AAE47 (Size : 136 bytes)
    0x000AAE47, // -> 0x000AAEA5 (Size : 94 bytes)
    0x000AAEA5, // -> 0x000AAF19 (Size : 116 bytes)
    0x000AAF19, // -> 0x000AAFDF (Size : 198 bytes)
    0x000AAFDF, // -> 0x000AB06C (Size : 141 bytes)
    0x000AB06C, // -> 0x000AB0EF (Size : 131 bytes)
    0x000AB0EF, // -> 0x000AB122 (Size : 51 bytes)
    0x000AB14E, // -> 0x000AB191 (Size : 67 bytes)
    0x000AB191, // -> 0x000AB215 (Size : 132 bytes)
    0x000AB303, // -> 0x000AB382 (Size : 127 bytes)
    0x000AB7BE, // -> 0x000AB7E7 (Size : 41 bytes)
    0x000AB7E7, // -> 0x000AB7F4 (Size : 13 bytes)
    0x000AB7F4, // -> 0x000AB814 (Size : 32 bytes)
    0x000AB814, // -> 0x000AB8F3 (Size : 223 bytes)
    0x000AB8F3, // -> 0x000AB91B (Size : 40 bytes)
    0x000AB91B, // -> 0x000AB964 (Size : 73 bytes)
    0x000AB964, // -> 0x000AB9D7 (Size : 115 bytes)
    0x000AB9D7, // -> 0x000ABA1C (Size : 69 bytes)
    0x000ABA1C, // -> 0x000ABB24 (Size : 264 bytes)
    0x000ABB24, // -> 0x000ABB5D (Size : 57 bytes)
    0x000ABB5D, // -> 0x000ABBC8 (Size : 107 bytes)
    0x000ABBC8, // -> 0x000ABC18 (Size : 80 bytes)
    0x000ABC18, // -> 0x000ABC8B (Size : 115 bytes)
    0x000ABC8B, // -> 0x000ABCD4 (Size : 73 bytes)
    0x000ABCD4, // -> 0x000ABD08 (Size : 52 bytes)
    0x000ABD08, // -> 0x000ABD42 (Size : 58 bytes)
    0x000ABD42, // -> 0x000ABDF3 (Size : 177 bytes)
    0x000ABDF3, // -> 0x000ABE4E (Size : 91 bytes)
    0x000ABE4E, // -> 0x000ABE92 (Size : 68 bytes)
    0x000ABE92, // -> 0x000ABF03 (Size : 113 bytes)
    0x000ABF03, // -> 0x000ABF18 (Size : 21 bytes)
    0x000ABF18, // -> 0x000ABF80 (Size : 104 bytes)
    0x000ABF80, // -> 0x000ABFEF (Size : 111 bytes)
    0x000ABFEF, // -> 0x000AC00F (Size : 32 bytes)
    0x000AC00F, // -> 0x000AC1E8 (Size : 473 bytes)
    0x000AC1E8, // -> 0x000AC241 (Size : 89 bytes)
    0x000AC241, // -> 0x000AC3E1 (Size : 416 bytes)
    0x000AC3E1, // -> 0x000AC76A (Size : 905 bytes)
    0x000AC76A, // -> 0x000AC813 (Size : 169 bytes)
    0x000AC813, // -> 0x000AC861 (Size : 78 bytes)
    0x000AC861, // -> 0x000AC8C6 (Size : 101 bytes)
    0x000AC8C6, // -> 0x000AC9A2 (Size : 220 bytes)
    0x000AC9A2, // -> 0x000ACA82 (Size : 224 bytes)
    0x000ACA82, // -> 0x000ACBE1 (Size : 351 bytes)
    0x000ACBE1, // -> 0x000ACC1B (Size : 58 bytes)
    0x000ACC1B, // -> 0x000ACC6B (Size : 80 bytes)
    0x000ACC6B, // -> 0x000ACC82 (Size : 23 bytes)
    0x000ACC82, // -> 0x000ACC99 (Size : 23 bytes)
    0x000ACC99, // -> 0x000ACCAE (Size : 21 bytes)
    0x000ACCAE, // -> 0x000ACCCA (Size : 28 bytes)
    0x000ACCCA, // -> 0x000ACD27 (Size : 93 bytes)
    0x000ACD27, // -> 0x000ACD34 (Size : 13 bytes)
    0x000ACD34, // -> 0x000ACD89 (Size : 85 bytes)
    0x000ACD89, // -> 0x000ACDBA (Size : 49 bytes)
    0x000ACDBA, // -> 0x000ACF30 (Size : 374 bytes)
    0x000ACF30, // -> 0x000ACF74 (Size : 68 bytes)
    0x000ACF74, // -> 0x000AD06B (Size : 247 bytes)
    0x000AD06B, // -> 0x000AD0C4 (Size : 89 bytes)
    0x000AD0C4, // -> 0x000AD0F4 (Size : 48 bytes)
    0x000AD0F4, // -> 0x000AD259 (Size : 357 bytes)
    0x000AD259, // -> 0x000AD282 (Size : 41 bytes)
    0x000AD282, // -> 0x000AD2CB (Size : 73 bytes)
    0x000AD2CB, // -> 0x000AD613 (Size : 840 bytes)
    0x000AD613, // -> 0x000AD6F2 (Size : 223 bytes)
    0x000AD6F2, // -> 0x000AD75B (Size : 105 bytes)
    0x000AD75B, // -> 0x000AD7E4 (Size : 137 bytes)
    0x000AD7E4, // -> 0x000AD84D (Size : 105 bytes)
    0x000AD84D, // -> 0x000AD8C9 (Size : 124 bytes)
    0x000AD8C9, // -> 0x000AD952 (Size : 137 bytes)
    0x000AD952, // -> 0x000AD9A6 (Size : 84 bytes)
    0x000AD9A6, // -> 0x000ADAAD (Size : 263 bytes)
    0x000ADAAD, // -> 0x000ADAC7 (Size : 26 bytes)
    0x000ADAC7, // -> 0x000ADB5F (Size : 152 bytes)
    0x000ADB5F, // -> 0x000ADB79 (Size : 26 bytes)
    0x000ADB79, // -> 0x000ADD24 (Size : 427 bytes)
    0x000ADD24, // -> 0x000ADD4F (Size : 43 bytes)
    0x000ADD4F, // -> 0x000ADE7D (Size : 302 bytes)
    0x000ADE7D, // -> 0x000ADEB1 (Size : 52 bytes)
    0x000ADEB1, // -> 0x000ADF91 (Size : 224 bytes)
    0x000ADF91, // -> 0x000AE07E (Size : 237 bytes)
    0x000AE07E, // -> 0x000AE106 (Size : 136 bytes)
    0x000AE106, // -> 0x000AE13E (Size : 56 bytes)
    0x000AE13E, // -> 0x000AE33A (Size : 508 bytes)
    0x000AE33A, // -> 0x000AE4DF (Size : 421 bytes)
    0x000AE4DF, // -> 0x000AE564 (Size : 133 bytes)
    0x000AE564, // -> 0x000AE649 (Size : 229 bytes)
    0x000AE649, // -> 0x000AE79B (Size : 338 bytes)
    0x000AE79B, // -> 0x000AE941 (Size : 422 bytes)
    0x000AE941, // -> 0x000AEB6B (Size : 554 bytes)
    0x000AEB6B, // -> 0x000AEFE4 (Size : 1145 bytes)
    0x000AF00B, // -> 0x000AF2FA (Size : 751 bytes)
    0x000AF2FA, // -> 0x000AF3D8 (Size : 222 bytes)
    0x000AF3D8, // -> 0x000AF48F (Size : 183 bytes)
    0x000AF48F, // -> 0x000AF750 (Size : 705 bytes)
    0x000AF750, // -> 0x000AF7C7 (Size : 119 bytes)
    0x000AF7C7, // -> 0x000AF7D0 (Size : 9 bytes)
    0x000AF7D0, // -> 0x000AF82E (Size : 94 bytes)
    0x000AF82E, // -> 0x000AF883 (Size : 85 bytes)
    0x000AF883, // -> 0x000AF8AA (Size : 39 bytes)
    0x000AF8AA, // -> 0x000AF8C8 (Size : 30 bytes)
    0x000AFFE3, // -> 0x000B005C (Size : 121 bytes)
    0x000B005C, // -> 0x000B00D9 (Size : 125 bytes)
    0x000B00D9, // -> 0x000B0110 (Size : 55 bytes)
    0x000B0110, // -> 0x000B011C (Size : 12 bytes)
    0x000B011C, // -> 0x000B031E (Size : 514 bytes)
    0x000B031E, // -> 0x000B0467 (Size : 329 bytes)
    0x000B0467, // -> 0x000B050A (Size : 163 bytes)
    0x000B050A, // -> 0x000B0516 (Size : 12 bytes)
    0x000B0516, // -> 0x000B0558 (Size : 66 bytes)
    0x000B0558, // -> 0x000B06D3 (Size : 379 bytes)
    0x000B073F, // -> 0x000B07EF (Size : 176 bytes)
    0x000B07EF, // -> 0x000B09B4 (Size : 453 bytes)
    0x000B09B4, // -> 0x000B0A15 (Size : 97 bytes)
    0x000B0A15, // -> 0x000B0A20 (Size : 11 bytes)
    0x000B0A20, // -> 0x000B0A82 (Size : 98 bytes)
    0x000B0A82, // -> 0x000B0AD8 (Size : 86 bytes)
    0x000B0AD8, // -> 0x000B0AE4 (Size : 12 bytes)
    0x000B0AE4, // -> 0x000B0CBC (Size : 472 bytes)
    0x000B0CBC, // -> 0x000B0D2F (Size : 115 bytes)
    0x000B0D2F, // -> 0x000B0D62 (Size : 51 bytes)
    0x000B0D62, // -> 0x000B0D84 (Size : 34 bytes)
    0x000B0D84, // -> 0x000B0D89 (Size : 5 bytes)
    0x000B0D89, // -> 0x000B0DAB (Size : 34 bytes)
    0x000B0DAB, // -> 0x000B0E18 (Size : 109 bytes)
    0x000B0E18, // -> 0x000B0E4F (Size : 55 bytes)
    0x000B0E4F, // -> 0x000B0E7A (Size : 43 bytes)
    0x000B0E7A, // -> 0x000B0E95 (Size : 27 bytes)
    0x000B0E95, // -> 0x000B0EA6 (Size : 17 bytes)
    0x000B0EA6, // -> 0x000B0EC9 (Size : 35 bytes)
    0x000B0EC9, // -> 0x000B0F33 (Size : 106 bytes)
    0x000B0F33, // -> 0x000B0FDE (Size : 171 bytes)
    0x000B0FDE, // -> 0x000B108F (Size : 177 bytes)
    0x000B108F, // -> 0x000B114B (Size : 188 bytes)
    0x000B114B, // -> 0x000B11D5 (Size : 138 bytes)
    0x000B11D5, // -> 0x000B1227 (Size : 82 bytes)
    0x000B1227, // -> 0x000B124B (Size : 36 bytes)
    0x000B124B, // -> 0x000B1278 (Size : 45 bytes)
    0x000B1278, // -> 0x000B12DE (Size : 102 bytes)
    0x000B12DE, // -> 0x000B132B (Size : 77 bytes)
    0x000B132B, // -> 0x000B13B5 (Size : 138 bytes)
    0x000B13B5, // -> 0x000B1452 (Size : 157 bytes)
    0x000B1452, // -> 0x000B1470 (Size : 30 bytes)
    0x000B1470, // -> 0x000B14F4 (Size : 132 bytes)
    0x000B14F4, // -> 0x000B157F (Size : 139 bytes)
    0x000B157F, // -> 0x000B160A (Size : 139 bytes)
    0x000B1645, // -> 0x000B16D9 (Size : 148 bytes)
    0x000B16D9, // -> 0x000B1807 (Size : 302 bytes)
    0x000B1807, // -> 0x000B18E5 (Size : 222 bytes)
    0x000B18E5, // -> 0x000B19D9 (Size : 244 bytes)
    0x000B19D9, // -> 0x000B1C29 (Size : 592 bytes)
    0x000B1D7D, // -> 0x000B1D94 (Size : 23 bytes)
    0x000B1D94, // -> 0x000B1DAB (Size : 23 bytes)
    0x000B1DAB, // -> 0x000B1DC2 (Size : 23 bytes)
    0x000B1DC2, // -> 0x000B1DD3 (Size : 17 bytes)
    0x000B1DD3, // -> 0x000B1DE6 (Size : 19 bytes)
    0x000B1DE6, // -> 0x000B1DEA (Size : 4 bytes)
    0x000B1DEA, // -> 0x000B1DF7 (Size : 13 bytes)
    0x000B1DF7, // -> 0x000B1DFB (Size : 4 bytes)
    0x000B1DFB, // -> 0x000B1E05 (Size : 10 bytes)
    0x000B1E05, // -> 0x000B1E73 (Size : 110 bytes)
    0x000B1E73, // -> 0x000B1E79 (Size : 6 bytes)
    0x000B1E79, // -> 0x000B1EEF (Size : 118 bytes)
    0x000B1EEF, // -> 0x000B1EF3 (Size : 4 bytes)
    0x000B1EF3, // -> 0x000B1F79 (Size : 134 bytes)
    0x000B1F79, // -> 0x000B1FE5 (Size : 108 bytes)
    0x000B1FE5, // -> 0x000B2016 (Size : 49 bytes)
    0x000B2016, // -> 0x000B205E (Size : 72 bytes)
    0x000B205E, // -> 0x000B20BA (Size : 92 bytes)
    0x000B20BA, // -> 0x000B212F (Size : 117 bytes)
    0x000B212F, // -> 0x000B2219 (Size : 234 bytes)
    0x000B2219, // -> 0x000B225B (Size : 66 bytes)
    0x000B225B, // -> 0x000B22A6 (Size : 75 bytes)
    0x000B22A6, // -> 0x000B2300 (Size : 90 bytes)
    0x000B2300, // -> 0x000B2350 (Size : 80 bytes)
    0x000B2350, // -> 0x000B2364 (Size : 20 bytes)
    0x000B2364, // -> 0x000B23AD (Size : 73 bytes)
    0x000B23AD, // -> 0x000B23E2 (Size : 53 bytes)
    0x000B23E2, // -> 0x000B244A (Size : 104 bytes)
    0x000B244A, // -> 0x000B245C (Size : 18 bytes)
    0x000B245C, // -> 0x000B248E (Size : 50 bytes)
    0x000B248E, // -> 0x000B2552 (Size : 196 bytes)
    0x000B2552, // -> 0x000B2574 (Size : 34 bytes)
    0x000B2574, // -> 0x000B25C5 (Size : 81 bytes)
    0x000B25C5, // -> 0x000B25F0 (Size : 43 bytes)
    0x000B25F0, // -> 0x000B2621 (Size : 49 bytes)
    0x000B2621, // -> 0x000B2655 (Size : 52 bytes)
    0x000B2655, // -> 0x000B265C (Size : 7 bytes)
    0x000B265C, // -> 0x000B2663 (Size : 7 bytes)
    0x000B2663, // -> 0x000B2678 (Size : 21 bytes)
    0x000B2678, // -> 0x000B26DA (Size : 98 bytes)
    0x000B26DA, // -> 0x000B26DF (Size : 5 bytes)
    0x000B26DF, // -> 0x000B2755 (Size : 118 bytes)
    0x000B2755, // -> 0x000B27A7 (Size : 82 bytes)
    0x000B27A7, // -> 0x000B2856 (Size : 175 bytes)
    0x000B2856, // -> 0x000B28CD (Size : 119 bytes)
    0x000B28CD, // -> 0x000B2912 (Size : 69 bytes)
    0x000B2912, // -> 0x000B2993 (Size : 129 bytes)
    0x000B2993, // -> 0x000B29A6 (Size : 19 bytes)
    0x000B29A6, // -> 0x000B29D9 (Size : 51 bytes)
    0x000B29D9, // -> 0x000B2A46 (Size : 109 bytes)
    0x000B2A46, // -> 0x000B2AAB (Size : 101 bytes)
    0x000B2AAB, // -> 0x000B2C37 (Size : 396 bytes)
    0x000B2C37, // -> 0x000B2C6B (Size : 52 bytes)
    0x000B2C6B, // -> 0x000B2D46 (Size : 219 bytes)
    0x000B2D46, // -> 0x000B2E8D (Size : 327 bytes)
    0x000B2E8D, // -> 0x000B2F8D (Size : 256 bytes)
    0x000B2F8D, // -> 0x000B3046 (Size : 185 bytes)
    0x000B3046, // -> 0x000B3191 (Size : 331 bytes)
    0x000B31E5, // -> 0x000B31F8 (Size : 19 bytes)
    0x000B31F8, // -> 0x000B336C (Size : 372 bytes)
    0x000B336C, // -> 0x000B338D (Size : 33 bytes)
    0x000B338D, // -> 0x000B33BB (Size : 46 bytes)
    0x000B33BB, // -> 0x000B33F4 (Size : 57 bytes)
    0x000B33F4, // -> 0x000B342D (Size : 57 bytes)
    0x000B342D, // -> 0x000B345C (Size : 47 bytes)
    0x000B345C, // -> 0x000B34D2 (Size : 118 bytes)
    0x000B34D2, // -> 0x000B350F (Size : 61 bytes)
    0x000B350F, // -> 0x000B354A (Size : 59 bytes)
    0x000B354A, // -> 0x000B3601 (Size : 183 bytes)
    0x000B3601, // -> 0x000B3668 (Size : 103 bytes)
    0x000B3668, // -> 0x000B36BB (Size : 83 bytes)
    0x000B36BB, // -> 0x000B37D3 (Size : 280 bytes)
    0x000B37D3, // -> 0x000B37FF (Size : 44 bytes)
    0x000B37FF, // -> 0x000B3823 (Size : 36 bytes)
    0x000B3823, // -> 0x000B3880 (Size : 93 bytes)
    0x000B3880, // -> 0x000B38B6 (Size : 54 bytes)
    0x000B38B6, // -> 0x000B3927 (Size : 113 bytes)
    0x000B3927, // -> 0x000B398A (Size : 99 bytes)
    0x000B398A, // -> 0x000B3AD8 (Size : 334 bytes)
    0x000B3AD8, // -> 0x000B3B3B (Size : 99 bytes)
    0x000B3B3B, // -> 0x000B3C22 (Size : 231 bytes)
    0x000B3C22, // -> 0x000B3C44 (Size : 34 bytes)
    0x000B3C44, // -> 0x000B3C76 (Size : 50 bytes)
    0x000B3C76, // -> 0x000B3ED9 (Size : 611 bytes)
    0x000B4004, // -> 0x000B40D7 (Size : 211 bytes)
    0x000B40D7, // -> 0x000B4107 (Size : 48 bytes)
    0x000B4107, // -> 0x000B4187 (Size : 128 bytes)
    0x000B4187, // -> 0x000B4232 (Size : 171 bytes)
    0x000B4232, // -> 0x000B42AE (Size : 124 bytes)
    0x000B42AE, // -> 0x000B43D4 (Size : 294 bytes)
    0x000B44B6, // -> 0x000B4545 (Size : 143 bytes)
    0x000B4545, // -> 0x000B4592 (Size : 77 bytes)
    0x000B4592, // -> 0x000B45AF (Size : 29 bytes)
    0x000B45AF, // -> 0x000B45DA (Size : 43 bytes)
    0x000B45DA, // -> 0x000B4699 (Size : 191 bytes)
    0x000B4699, // -> 0x000B46B6 (Size : 29 bytes)
    0x000B46B6, // -> 0x000B46F3 (Size : 61 bytes)
    0x000B46F3, // -> 0x000B4743 (Size : 80 bytes)
    0x000B4743, // -> 0x000B4759 (Size : 22 bytes)
    0x000B4759, // -> 0x000B47D0 (Size : 119 bytes)
    0x000B47D0, // -> 0x000B49AC (Size : 476 bytes)
    0x000B49AC, // -> 0x000B4B25 (Size : 377 bytes)
    0x000B4B25, // -> 0x000B4BBB (Size : 150 bytes)
    0x000B4BBB, // -> 0x000B4BDF (Size : 36 bytes)
    0x000B4BDF, // -> 0x000B4CF2 (Size : 275 bytes)
    0x000B4CF2, // -> 0x000B4D6E (Size : 124 bytes)
    0x000B4D6E, // -> 0x000B4DA0 (Size : 50 bytes)
    0x000B4DA0, // -> 0x000B4E94 (Size : 244 bytes)
    0x000B4E94, // -> 0x000B4F40 (Size : 172 bytes)
    0x000B4F40, // -> 0x000B5042 (Size : 258 bytes)
    0x000B5042, // -> 0x000B5098 (Size : 86 bytes)
    0x000B5098, // -> 0x000B511F (Size : 135 bytes)
    0x000B511F, // -> 0x000B51F9 (Size : 218 bytes)
    0x000B51F9, // -> 0x000B530F (Size : 278 bytes)
    0x000B530F, // -> 0x000B5321 (Size : 18 bytes)
    0x000B5321, // -> 0x000B54CE (Size : 429 bytes)
    0x000B54CE, // -> 0x000B5512 (Size : 68 bytes)
    0x000B5512, // -> 0x000B559B (Size : 137 bytes)
    0x000B559B, // -> 0x000B5702 (Size : 359 bytes)
    0x000B5702, // -> 0x000B5821 (Size : 287 bytes)
    0x000B5821, // -> 0x000B587B (Size : 90 bytes)
    0x000B587B, // -> 0x000B596B (Size : 240 bytes)
    0x000B596B, // -> 0x000B598B (Size : 32 bytes)
    0x000B598B, // -> 0x000B59AA (Size : 31 bytes)
    0x000B59AA, // -> 0x000B59C9 (Size : 31 bytes)
    0x000B59C9, // -> 0x000B59FB (Size : 50 bytes)
    0x000B59FB, // -> 0x000B5A35 (Size : 58 bytes)
    0x000B5A35, // -> 0x000B5D33 (Size : 766 bytes)
    0x000B5D33, // -> 0x000B5D86 (Size : 83 bytes)
    0x000B5D86, // -> 0x000B5DD3 (Size : 77 bytes)
    0x000B5DD3, // -> 0x000B5E20 (Size : 77 bytes)
    0x000B5E20, // -> 0x000B5E53 (Size : 51 bytes)
    0x000B5E53, // -> 0x000B5E8F (Size : 60 bytes)
    0x000B5E8F, // -> 0x000B5ECB (Size : 60 bytes)
    0x000B5ECB, // -> 0x000B5F51 (Size : 134 bytes)
};

/*! thread local storage */
extern CXBXKRNL_API Xbe::TLS *CxbxKrnl_TLS = NULL;
/*! thread local storage data */
extern CXBXKRNL_API void *CxbxKrnl_TLSData = NULL;
/*! xbe header structure */
extern CXBXKRNL_API Xbe::Header *CxbxKrnl_XbeHeader = NULL;
/*! parent window handle */
extern CXBXKRNL_API HWND CxbxKrnl_hEmuParent = NULL;

/*! thread handles */
static HANDLE g_hThreads[MAXIMUM_XBOX_THREADS] = { 0 };

extern "C" CXBXKRNL_API bool CxbxKrnlVerifyVersion(const char *szVersion)
{
    if(strcmp(szVersion, _CXBX_VERSION) != 0)
        return false;

    return true;
}

extern "C" CXBXKRNL_API void CxbxKrnlInit
(
    HWND                    hwndParent,
    void                   *pTLSData, 
    Xbe::TLS               *pTLS,
    Xbe::LibraryVersion    *pLibraryVersion,
    DebugMode               DbgMode,
    char                   *szDebugFilename,
    Xbe::Header            *pXbeHeader,
    uint32                  dwXbeHeaderSize,
    void                  (*Entry)())
{
    // update caches
    CxbxKrnl_TLS = pTLS;
    CxbxKrnl_TLSData = pTLSData;
    CxbxKrnl_XbeHeader = pXbeHeader;
    CxbxKrnl_hEmuParent = IsWindow(hwndParent) ? hwndParent : NULL;

    // for unicode conversions
    setlocale(LC_ALL, "English");

    // debug console allocation (if configured)
    if(DbgMode == DM_CONSOLE)
    {
        if(AllocConsole())
        {
            freopen("CONOUT$", "wt", stdout);
            freopen("CONIN$", "rt", stdin);

            SetConsoleTitle("Cxbx : Kernel Debug Console");

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
            
            printf("EmuMain (0x%X): Cxbx Version %s\n", GetCurrentThreadId(), _CXBX_VERSION);
            printf("EmuMain (0x%X): Debug Console Allocated (DM_CONSOLE).\n", GetCurrentThreadId());
        }
    }
    else if(DbgMode == DM_FILE)
    {
        FreeConsole();

        freopen(szDebugFilename, "wt", stdout);

        printf("EmuMain (0x%X): Cxbx Version %s\n", GetCurrentThreadId(), _CXBX_VERSION);
        printf("EmuMain (0x%X): Debug Console Allocated (DM_FILE).\n", GetCurrentThreadId());
    }
    else
    {
        FreeConsole();

        char buffer[16];

        if(GetConsoleTitle(buffer, 16) != NULL)
            freopen("nul", "w", stdout);
    }

    //
    // debug trace
    //

    {
        #ifdef _DEBUG_TRACE
        printf("EmuMain (0x%X): Debug Trace Enabled.\n", GetCurrentThreadId());

        printf("EmuMain (0x%X): CxbxKrnlInit\n"
               "(\n"
               "   hwndParent          : 0x%.08X\n"
               "   pTLSData            : 0x%.08X\n"
               "   pTLS                : 0x%.08X\n"
               "   pLibraryVersion     : 0x%.08X\n"
               "   DebugConsole        : 0x%.08X\n"
               "   DebugFilename       : \"%s\"\n"
               "   pXBEHeader          : 0x%.08X\n"
               "   pXBEHeaderSize      : 0x%.08X\n"
               "   Entry               : 0x%.08X\n"
               ");\n",
               GetCurrentThreadId(), hwndParent, pTLSData, pTLS, pLibraryVersion, DbgMode, szDebugFilename, pXbeHeader, dwXbeHeaderSize, Entry);

        #else
        printf("EmuMain (0x%X): Debug Trace Disabled.\n", GetCurrentThreadId());
        #endif
    }

    //
    // load the necessary pieces of XbeHeader
    //

    {
        Xbe::Header *MemXbeHeader = (Xbe::Header*)0x00010000;

        uint32 old_protection = 0;

        VirtualProtect(MemXbeHeader, 0x1000, PAGE_READWRITE, &old_protection);

        // we sure hope we aren't corrupting anything necessary for an .exe to survive :]
        MemXbeHeader->dwSizeofHeaders   = pXbeHeader->dwSizeofHeaders;
        MemXbeHeader->dwCertificateAddr = pXbeHeader->dwCertificateAddr;
        MemXbeHeader->dwPeHeapReserve   = pXbeHeader->dwPeHeapReserve;
        MemXbeHeader->dwPeHeapCommit    = pXbeHeader->dwPeHeapCommit;

        memcpy(&MemXbeHeader->dwInitFlags, &pXbeHeader->dwInitFlags, sizeof(pXbeHeader->dwInitFlags));

        memcpy((void*)pXbeHeader->dwCertificateAddr, &((uint08*)pXbeHeader)[pXbeHeader->dwCertificateAddr - 0x00010000], sizeof(Xbe::Certificate));
    }

    //
    // initialize current directory
    //

    {
        char szBuffer[260];

        g_EmuShared->GetXbePath(szBuffer);

        if(szBuffer && *szBuffer)
            SetCurrentDirectory(szBuffer);
        else
            GetCurrentDirectory(260, szBuffer);

        g_strCurDrive = strdup(szBuffer);

        g_hCurDir = CreateFile(szBuffer, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);

        if(g_hCurDir == INVALID_HANDLE_VALUE)
            CxbxKrnlCleanup("Could not map D:\\\n");

        DbgPrintf("EmuMain (0x%X): CurDir := %s\n", GetCurrentThreadId(), szBuffer);
    }

    //
    // initialize EmuDisk
    //

    {
        char szBuffer[260];

        SHGetSpecialFolderPath(NULL, szBuffer, CSIDL_APPDATA, TRUE);

        strcat(szBuffer, "\\Cxbx\\");

        CreateDirectory(szBuffer, NULL);

        sint32 spot = -1;

        for(int v=0;v<260;v++)
        {
            if(szBuffer[v] == '\\') { spot = v; }
            else if(szBuffer[v] == '\0') { break; }
        }

        if(spot != -1) { szBuffer[spot] = '\0'; }

        Xbe::Certificate *pCertificate = (Xbe::Certificate*)pXbeHeader->dwCertificateAddr;

        //
        // create EmuDisk directory
        //

        strcpy(&szBuffer[spot], "\\EmuDisk");

        CreateDirectory(szBuffer, NULL);

        //
        // create T:\ directory
        //

        {
            strcpy(&szBuffer[spot], "\\EmuDisk\\T");

            CreateDirectory(szBuffer, NULL);

            sprintf(&szBuffer[spot+10], "\\%08x", pCertificate->dwTitleId);

            CreateDirectory(szBuffer, NULL);

            g_strTDrive = strdup(szBuffer);

            g_hTDrive = CreateFile(szBuffer, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);

            if(g_hTDrive == INVALID_HANDLE_VALUE)
                CxbxKrnlCleanup("Could not map T:\\\n");

            DbgPrintf("EmuMain (0x%X): T Data := %s\n", GetCurrentThreadId(), szBuffer);
        }

        //
        // create U:\ directory
        //

        {
            strcpy(&szBuffer[spot], "\\EmuDisk\\U");

            CreateDirectory(szBuffer, NULL);

            sprintf(&szBuffer[spot+10], "\\%08x", pCertificate->dwTitleId);

            CreateDirectory(szBuffer, NULL);

            g_strUDrive = strdup(szBuffer);

            g_hUDrive = CreateFile(szBuffer, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);

            if(g_hUDrive == INVALID_HANDLE_VALUE)
                CxbxKrnlCleanup("Could not map U:\\\n");

            DbgPrintf("EmuMain (0x%X): U Data := %s\n", GetCurrentThreadId(), szBuffer);
        }

        //
        // create Z:\ directory
        //

        {
            strcpy(&szBuffer[spot], "\\EmuDisk\\Z");

            CreateDirectory(szBuffer, NULL);

            //* is it necessary to make this directory title unique?
            sprintf(&szBuffer[spot+10], "\\%08x", pCertificate->dwTitleId);

            CreateDirectory(szBuffer, NULL);
            //*/

            g_strZDrive = strdup(szBuffer);

            g_hZDrive = CreateFile(szBuffer, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);

            if(g_hUDrive == INVALID_HANDLE_VALUE)
                CxbxKrnlCleanup("Could not map Z:\\\n");

            DbgPrintf("EmuMain (0x%X): Z Data := %s\n", GetCurrentThreadId(), szBuffer);
        }
    }

    //
    // initialize FS segment selector
    //

    {
        EmuInitFS();

        EmuGenerateFS(pTLS, pTLSData);
    }

    //
    // duplicate handle in order to retain Suspend/Resume thread rights from a remote thread
    //

    {
        HANDLE hDupHandle = NULL;

        DuplicateHandle(GetCurrentProcess(), GetCurrentThread(), GetCurrentProcess(), &hDupHandle, 0, FALSE, DUPLICATE_SAME_ACCESS);

        CxbxKrnlRegisterThread(hDupHandle);
    }

    DbgPrintf("EmuMain (0x%X): Initializing Direct3D.\n", GetCurrentThreadId());

    XTL::EmuD3DInit(pXbeHeader, dwXbeHeaderSize);

    EmuHLEIntercept(pLibraryVersion, pXbeHeader);

    DbgPrintf("EmuMain (0x%X): Initial thread starting.\n", GetCurrentThreadId());

    //
    // Xbe entry point
    //

    __try
    {
        EmuSwapFS();   // XBox FS

        // _USE_XGMATH Disabled in mesh :[
        // halo : dword_0_2E2D18
        // halo : 1744F0 (bink)
        //_asm int 3;

        /*
        for(int v=0;v<sizeof(funcAddr)/sizeof(uint32);v++)
        {
            bool bExclude = false;
            for(int r=0;r<sizeof(funcExclude)/sizeof(uint32);r++)
            {
                if(funcAddr[v] == funcExclude[r])
                {
                    bExclude = true;
                    break;
                }
            }

            if(!bExclude)
            {
                *(uint08*)(funcAddr[v]) = 0xCC;
            }
        }
        //*/

        Entry();

        EmuSwapFS();   // Win2k/XP FS
    }
    __except(EmuException(GetExceptionInformation()))
    {
        printf("Emu: WARNING!! Problem with ExceptionFilter\n");
    }

    DbgPrintf("EmuMain (0x%X): Initial thread ended.\n", GetCurrentThreadId());

    fflush(stdout);

    CxbxKrnlTerminateThread();

    return;
}

extern "C" CXBXKRNL_API void CxbxKrnlCleanup(const char *szErrorMessage, ...)
{
    g_bEmuException = true;

    CxbxKrnlResume();

    // print out error message (if exists)
    if(szErrorMessage != NULL)
    {
        char szBuffer1[255];
        char szBuffer2[255];

        va_list argp;

        sprintf(szBuffer1, "EmuMain (0x%X): Recieved Fatal Message:\n\n* ", GetCurrentThreadId());

        va_start(argp, szErrorMessage);

        vsprintf(szBuffer2, szErrorMessage, argp);

        va_end(argp);

        strcat(szBuffer1, szBuffer2);
        strcat(szBuffer1, "\n");

        printf("%s\n", szBuffer1);

        MessageBox(NULL, szBuffer1, "CxbxKrnl", MB_OK | MB_ICONSTOP);
    }

    printf("CxbxKrnl: Terminating Process\n");
    fflush(stdout);

    // cleanup debug output
    {
        FreeConsole();

        char buffer[16];

        if(GetConsoleTitle(buffer, 16) != NULL)
            freopen("nul", "w", stdout);
    }

    if(CxbxKrnl_hEmuParent != NULL)
        SendMessage(CxbxKrnl_hEmuParent, WM_PARENTNOTIFY, WM_DESTROY, 0);

    TerminateProcess(GetCurrentProcess(), 0);

    return;
}

extern "C" CXBXKRNL_API void CxbxKrnlRegisterThread(HANDLE hThread)
{
    int v=0;

    for(v=0;v<MAXIMUM_XBOX_THREADS;v++)
    {
        if(g_hThreads[v] == 0)
        {
            g_hThreads[v] = hThread;
            break;
        }
    }

    if(v == MAXIMUM_XBOX_THREADS)
    {
        CxbxKrnlCleanup("There are too many active threads!");
    }
}

extern "C" CXBXKRNL_API void CxbxKrnlSuspend()
{
    if(g_bEmuSuspended || g_bEmuException)
        return;

    for(int v=0;v<MAXIMUM_XBOX_THREADS;v++)
    {
        if(g_hThreads[v] != NULL)
        {
            DWORD dwExitCode;

            if(GetExitCodeThread(g_hThreads[v], &dwExitCode) && dwExitCode == STILL_ACTIVE)
            {
                // suspend thread if it is active
                SuspendThread(g_hThreads[v]);
            }
            else
            {
                // remove thread from thread list if it is dead
                g_hThreads[v] = 0;
            }
        }
    }

    // append 'paused' to rendering window caption text
    {
        char szBuffer[256];

        HWND hWnd = (CxbxKrnl_hEmuParent != NULL) ? CxbxKrnl_hEmuParent : g_hEmuWindow;

        GetWindowText(hWnd, szBuffer, 255 - 10);

        strcat(szBuffer, " (paused)");
        SetWindowText(hWnd, szBuffer);
    }

    g_bEmuSuspended = true;
}

extern "C" CXBXKRNL_API void CxbxKrnlResume()
{
    if(!g_bEmuSuspended)
        return;

    // remove 'paused' from rendering window caption text
    {
        char szBuffer[256];

        HWND hWnd = (CxbxKrnl_hEmuParent != NULL) ? CxbxKrnl_hEmuParent : g_hEmuWindow;

        GetWindowText(hWnd, szBuffer, 255);

        szBuffer[strlen(szBuffer)-9] = '\0';

        SetWindowText(hWnd, szBuffer);
    }

    for(int v=0;v<MAXIMUM_XBOX_THREADS;v++)
    {
        if(g_hThreads[v] != NULL)
        {
            DWORD dwExitCode;

            if(GetExitCodeThread(g_hThreads[v], &dwExitCode) && dwExitCode == STILL_ACTIVE)
            {
                // resume thread if it is active
                ResumeThread(g_hThreads[v]);
            }
            else
            {
                // remove thread from thread list if it is dead
                g_hThreads[v] = 0;
            }
        }
    }

    g_bEmuSuspended = false;
}

extern "C" CXBXKRNL_API void CxbxKrnlTerminateThread()
{
    if(EmuIsXboxFS())
        EmuSwapFS();    // Win2k/XP FS

    EmuCleanupFS();

    TerminateThread(GetCurrentThread(), 0);
}

extern "C" CXBXKRNL_API void CxbxKrnlPanic()
{
    if(EmuIsXboxFS())
        EmuSwapFS();   // Win2k/XP FS

    DbgPrintf("EmuMain (0x%X): CxbxKrnlPanic()\n", GetCurrentThreadId());

    CxbxKrnlCleanup("Kernel Panic!");

    EmuSwapFS();   // XBox FS
}

extern "C" CXBXKRNL_API void CxbxKrnlNoFunc()
{
    EmuSwapFS();   // Win2k/XP FS

    DbgPrintf("EmuMain (0x%X): CxbxKrnlNoFunc()\n", GetCurrentThreadId());

    EmuSwapFS();   // XBox FS
}
