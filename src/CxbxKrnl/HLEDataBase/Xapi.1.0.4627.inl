// ******************************************************************
// *
// *    .,-:::::    .,::      .::::::::.    .,::      .:
// *  ,;;;'````'    `;;;,  .,;;  ;;;'';;'   `;;;,  .,;;
// *  [[[             '[[,,[['   [[[__[[\.    '[[,,[['
// *  $$$              Y$$$P     $$""""Y$$     Y$$$P
// *  `88bo,__,o,    oP"``"Yo,  _88o,,od8P   oP"``"Yo,
// *    "YUMMMMMP",m"       "Mm,""YUMMMP" ,m"       "Mm,
// *
// *   Cxbx->Win32->CxbxKrnl->Xapi.1.0.4627.cpp
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

// NOTE: This function actually came in with 4831, not 4928!
// ******************************************************************
// * XapiApplyKernelPatches
// ******************************************************************
SOOVPA<7> XapiApplyKernelPatches_1_0_4928 =
{
    0,  // Large == 0
    7,  // Count == 7

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x17, 0x81 },
        { 0x2A, 0x81 },
        { 0x4B, 0x05 },
        { 0x5F, 0x1B },
        { 0x7C, 0xFF },
        { 0x88, 0x6A },
        { 0x92, 0xC7 },
    }
};

// NOTE: This function actually came in with 4928
// ******************************************************************
// * XapiInitProcess
// ******************************************************************
SOOVPA<7> XapiInitProcess_1_0_4928 =
{
    0,  // Large == 0
    7,  // Count == 7

    -1, // XRef Not Saved
    0,  // XRef Not Used

    {
        { 0x22, 0xC7 }, // (Offset,Value)-Pair #1
        { 0x23, 0x45 }, // (Offset,Value)-Pair #2
        { 0x24, 0xCC }, // (Offset,Value)-Pair #3
        { 0x25, 0x30 }, // (Offset,Value)-Pair #4
        { 0x4A, 0xA1 }, // (Offset,Value)-Pair #5
        { 0x4B, 0x18 }, // (Offset,Value)-Pair #6
        { 0x4C, 0x01 }, // (Offset,Value)-Pair #7
    }
};

// ******************************************************************
// * XapiInitProcess
// ******************************************************************
SOOVPA<7> XapiInitProcess_1_0_4831 = 
{
    0,  // Large == 0
    7,  // Count == 7

    -1, // XRef Not Saved
    0,  // XRef Not Used

    {
        // XapiInitProcess+0x03 : sub esp, 0x34
        { 0x05, 0x34 }, // (Offset,Value)-Pair #1

        // XapiInitProcess+0x13 : push 0x0C
        { 0x13, 0x6A }, // (Offset,Value)-Pair #2
        { 0x14, 0x0C }, // (Offset,Value)-Pair #3

        // XapiInitProcess+0x2A : repe stosd
        { 0x1B, 0xF3 }, // (Offset,Value)-Pair #4
        { 0x1C, 0xAB }, // (Offset,Value)-Pair #5

        // XapiInitProcess+0x55 : jz +0x0B
        { 0x48, 0x74 }, // (Offset,Value)-Pair #6
        { 0x49, 0x4A }, // (Offset,Value)-Pair #7
    }
};

// ******************************************************************
// * XapiInitProcess
// ******************************************************************
SOOVPA<7> XapiInitProcess_1_0_5028 = 
{
    0,  // Large == 0
    7,  // Count == 7

    -1, // XRef Not Saved
    0,  // XRef Not Used

    {
        // XapiInitProcess+0x03 : sub esp, 0x34
        { 0x05, 0x34 }, // (Offset,Value)-Pair #1

        // XapiInitProcess+0x22 : push 0x0C
        { 0x22, 0x6A }, // (Offset,Value)-Pair #2
        { 0x23, 0x0C }, // (Offset,Value)-Pair #3

        // XapiInitProcess+0x2A : repe stosd
        { 0x2A, 0xF3 }, // (Offset,Value)-Pair #4
        { 0x2B, 0xAB }, // (Offset,Value)-Pair #5

        // XapiInitProcess+0x55 : jz +0x0B
        { 0x55, 0x74 }, // (Offset,Value)-Pair #6
        { 0x56, 0x5F }, // (Offset,Value)-Pair #7
    }
};

// ******************************************************************
// * XFormatUtilityDrive
// ******************************************************************
SOOVPA<7> XFormatUtilityDrive_1_0_4627 =
{
    0,  // Large == 0
    7,  // Count == 7

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x10, 0x50 },
        { 0x23, 0xFF },
        { 0x34, 0xC0 },
        { 0x46, 0x45 },
        { 0x58, 0xFF },
        { 0x6D, 0x33 },
        { 0x7C, 0x40 },
    }
};

// ******************************************************************
// * SetThreadPriorityBoost
// ******************************************************************
SOOVPA<10> SetThreadPriorityBoost_1_0_4627 =
{
    0,  // Large == 0
    10, // Count == 10

    -1, // XRef Not Saved
    0,  // XRef Not Used

    {
        // SetThreadPriorityBoost+0x0D : push [ebp+0x08]
        { 0x0D, 0xFF }, // (Offset,Value)-Pair #1
        { 0x0E, 0x75 }, // (Offset,Value)-Pair #2
        { 0x0F, 0x08 }, // (Offset,Value)-Pair #3

        // SetThreadPriorityBoost+0x18 : jl +0x20
        { 0x18, 0x7C }, // (Offset,Value)-Pair #4
        { 0x19, 0x20 }, // (Offset,Value)-Pair #5

        // SetThreadPriorityBoost+0x1F : setnz al
        { 0x1F, 0x0F }, // (Offset,Value)-Pair #6
        { 0x20, 0x95 }, // (Offset,Value)-Pair #7
        { 0x21, 0xC0 }, // (Offset,Value)-Pair #8

        // SetThreadPriorityBoost+0x2C : mov ecx, [ebp+0x08]
        { 0x2C, 0x8B }, // (Offset,Value)-Pair #9
        { 0x2D, 0x4D }, // (Offset,Value)-Pair #10
    }
};

// ******************************************************************
// * GetThreadPriority
// ******************************************************************
SOOVPA<10> GetThreadPriority_1_0_4627 =
{
    0,  // Large == 0
    10, // Count == 10

    -1, // XRef Not Saved
    0,  // XRef Not Used

    {
        // GetThreadPriority+0x0D : push [ebp+0x08]
        { 0x0D, 0xFF }, // (Offset,Value)-Pair #1
        { 0x0E, 0x75 }, // (Offset,Value)-Pair #2
        { 0x0F, 0x08 }, // (Offset,Value)-Pair #3

        // GetThreadPriority+0x18 : jl +0x2B
        { 0x18, 0x7C }, // (Offset,Value)-Pair #4
        { 0x19, 0x2B }, // (Offset,Value)-Pair #5

        // GetThreadPriority+0x2F : cmp esi, 0xFFFFFFF0
        { 0x2F, 0x83 }, // (Offset,Value)-Pair #6
        { 0x30, 0xFE }, // (Offset,Value)-Pair #7
        { 0x31, 0xF0 }, // (Offset,Value)-Pair #8

        // GetThreadPriority+0x37 : mov ecx, [ebp+0x08]
        { 0x37, 0x8B }, // (Offset,Value)-Pair #9
        { 0x38, 0x4D }, // (Offset,Value)-Pair #10
    }
};

// ******************************************************************
// * RtlFreeHeap
// ******************************************************************
SOOVPA<9> RtlFreeHeap_1_0_4627 =
{
    0,  // Large == 0
    9,  // Count == 9

    -1, // XRef Not Saved
    0,  // XRef Not Used

    {
        // RtlFreeHeap+0x1F : test edi, edi
        { 0x1F, 0x85 }, // (Offset,Value)-Pair #1
        { 0x20, 0xFF }, // (Offset,Value)-Pair #2

        // RtlFreeHeap+0x23 : mov al, 1
        { 0x23, 0xB0 }, // (Offset,Value)-Pair #3
        { 0x24, 0x01 }, // (Offset,Value)-Pair #4

        // RtlFreeHeap+0x35 : mov eax, fs:[0x20]
        { 0x35, 0x64 }, // (Offset,Value)-Pair #5
        { 0x36, 0xA1 }, // (Offset,Value)-Pair #6
        { 0x37, 0x20 }, // (Offset,Value)-Pair #7

        // RtlFreeHeap+0x49 : push 0x0B
        { 0x49, 0x6A }, // (Offset,Value)-Pair #8
        { 0x4A, 0x0B }, // (Offset,Value)-Pair #9
    }
};

// ******************************************************************
// * RtlReAllocateHeap
// ******************************************************************
SOOVPA<10> RtlReAllocateHeap_1_0_4627 =
{
    0,  // Large == 0
    10,  // Count == 10

    -1, // XRef Not Saved
    0,  // XRef Not Used

    {
        // RtlReAllocateHeap+0x1C : test esi, esi
        { 0x1C, 0x85 }, // (Offset,Value)-Pair #1
        { 0x1D, 0xF6 }, // (Offset,Value)-Pair #2

        // RtlReAllocateHeap+0x26 : or [ebp+0x0C], ecx
        { 0x26, 0x09 }, // (Offset,Value)-Pair #3
        { 0x27, 0x4D }, // (Offset,Value)-Pair #4
        { 0x28, 0x0C }, // (Offset,Value)-Pair #5

        // RtlReAllocateHeap+0x61 : jz +0x06; add ecx, 0x10
        { 0x61, 0x74 }, // (Offset,Value)-Pair #6
        { 0x62, 0x06 }, // (Offset,Value)-Pair #7
        { 0x63, 0x83 }, // (Offset,Value)-Pair #8
        { 0x64, 0xC1 }, // (Offset,Value)-Pair #9
        { 0x65, 0x10 }, // (Offset,Value)-Pair #10
    }
};

// ******************************************************************
// * XID_fCloseDevice
// ******************************************************************
SOOVPA<7> XID_fCloseDevice_1_0_4627 = 
{
    0,  // Large == 0
    7,  // Count == 7

    XREF_FCLOSEDEVICE,  // Xref Is Saved
    0,  // Xref Not Used

    {
        { 0x13, 0x1E },
        { 0x28, 0x75 },
        { 0x3D, 0x01 },
        { 0x52, 0xC6 },
        { 0x67, 0xFF },
        { 0x7C, 0x06 },
        { 0x91, 0x89 },
    }
};

// ******************************************************************
// * XID_fCloseDevice
// ******************************************************************
SOOVPA<11> XID_fCloseDevice_1_0_4928 =
{
    0,  // Large == 0
    11, // Count == 11

    XREF_FCLOSEDEVICE,  // XRef Is  Saved
    0,                  // XRef Not Used

    {
        { 0x13, 0x8B }, // (Offset,Value)-Pair #1
        { 0x14, 0x86 }, // (Offset,Value)-Pair #2
        { 0x15, 0xA3 }, // (Offset,Value)-Pair #3

        { 0x4C, 0x89 }, // (Offset,Value)-Pair #4
        { 0x4D, 0x86 }, // (Offset,Value)-Pair #5
        { 0x4E, 0x9E }, // (Offset,Value)-Pair #6

        { 0x87, 0x89 }, // (Offset,Value)-Pair #7
        { 0x88, 0x86 }, // (Offset,Value)-Pair #8
        { 0x89, 0xA7 }, // (Offset,Value)-Pair #9

        { 0x95, 0xC9 }, // (Offset,Value)-Pair #10
        { 0x96, 0xC3 }, // (Offset,Value)-Pair #11
    }
};

// ******************************************************************
// * XInputClose
// ******************************************************************
SOOVPA<8> XInputClose_1_0_4928 =
{
    0,  // Large == 0
    8,  // Count == 8

    -1, // XRef Not Saved
    1,  // XRef Is Used

    {
        // XInputClose+0x05 : call [fCloseDevice]
        { 0x05, XREF_FCLOSEDEVICE },  // (Offset,Value)-Pair #1

        // XInputClose+0x00 : mov ecx, [esp+0x04]
        { 0x00, 0x8B }, // (Offset,Value)-Pair #2
        { 0x01, 0x4C }, // (Offset,Value)-Pair #3
        { 0x02, 0x24 }, // (Offset,Value)-Pair #4
        { 0x03, 0x04 }, // (Offset,Value)-Pair #5

        // XInputClose+0x04 : call [fCloseDevice]
        { 0x04, 0xE8 }, // (Offset,Value)-Pair #6

        // XInputClose+0x09 : retn 0x04
        { 0x09, 0xC2 }, // (Offset,Value)-Pair #7
        { 0x0A, 0x04 }, // (Offset,Value)-Pair #8
    }
};

// ******************************************************************
// * XInputGetState
// ******************************************************************
SOOVPA<12> XInputGetState_1_0_4928 =
{
    0,  // Large == 0
    12, // Count == 12

    -1, // XRef Not Saved
    0,  // XRef Not Used

    {
        { 0x0E, 0x8B }, // (Offset,Value)-Pair #1
        { 0x0F, 0x8A }, // (Offset,Value)-Pair #2
        { 0x10, 0xA3 }, // (Offset,Value)-Pair #3

        { 0x1A, 0x6A }, // (Offset,Value)-Pair #4
        { 0x1B, 0x57 }, // (Offset,Value)-Pair #5

        { 0x1D, 0xEB }, // (Offset,Value)-Pair #6
        { 0x1E, 0x3E }, // (Offset,Value)-Pair #7

        { 0x3A, 0x8B }, // (Offset,Value)-Pair #8
        { 0x3B, 0x8A }, // (Offset,Value)-Pair #9
        { 0x3C, 0xA3 }, // (Offset,Value)-Pair #10

        { 0x69, 0xC2 }, // (Offset,Value)-Pair #11
        { 0x6A, 0x08 }, // (Offset,Value)-Pair #12
    }
};

// ******************************************************************
// * XInputGetCapabilities
// ******************************************************************
SOOVPA<12> XInputGetCapabilities_1_0_4928 =
{
    0,  // Large == 0
    12, // Count == 12

    -1, // XRef Not Saved
    0,  // XRef Not Used

    {
        { 0x0B, 0x8B }, // (Offset,Value)-Pair #1
        { 0x0C, 0x1D }, // (Offset,Value)-Pair #2
        { 0x0D, 0xAC }, // (Offset,Value)-Pair #3

        { 0x25, 0xF6 }, // (Offset,Value)-Pair #4
        { 0x26, 0x46 }, // (Offset,Value)-Pair #5
        { 0x27, 0x04 }, // (Offset,Value)-Pair #6
        { 0x28, 0x02 }, // (Offset,Value)-Pair #7

        { 0x39, 0xF3 }, // (Offset,Value)-Pair #8
        { 0x3A, 0xAB }, // (Offset,Value)-Pair #9

        { 0x90, 0xBF }, // (Offset,Value)-Pair #10
        { 0x91, 0xE8 }, // (Offset,Value)-Pair #11
        { 0x92, 0x7B }, // (Offset,Value)-Pair #12
    }
};

// ******************************************************************
// * XInputGetCapabilities2
// ******************************************************************
/* Unreal Championship's version is different */
SOOVPA<12> XInputGetCapabilities2_1_0_4928 =
{
    0,  // Large == 0
    12, // Count == 12

    -1, // XRef Not Saved
    0,  // XRef Not Used

    {
		// mov     ebx, ds:KeRaiseIrqlToDpcLevel
        { 0x0B, 0x8B }, // (Offset,Value)-Pair #1
        { 0x0C, 0x1D }, // (Offset,Value)-Pair #2
        { 0x0D, 0x1C }, // (Offset,Value)-Pair #3

		// test    byte ptr [esi+4], 2
        { 0x25, 0xF6 }, // (Offset,Value)-Pair #4
        { 0x26, 0x46 }, // (Offset,Value)-Pair #5
        { 0x27, 0x04 }, // (Offset,Value)-Pair #6
        { 0x28, 0x02 }, // (Offset,Value)-Pair #7

		// rep stosd
        { 0x39, 0xF3 }, // (Offset,Value)-Pair #8
        { 0x3A, 0xAB }, // (Offset,Value)-Pair #9

		// mov  edi, offset unknown_libname_2
        { 0x90, 0xBF }, // (Offset,Value)-Pair #10
        { 0x91, 0xCC }, // (Offset,Value)-Pair #11
        { 0x92, 0x5C }, // (Offset,Value)-Pair #12
    }
};

// ******************************************************************
// * XInputGetCapabilities3
// ******************************************************************
SOOVPA<12> XInputGetCapabilities3_1_0_4928 =
{
    0,  // Large == 0
    12, // Count == 12

    -1, // XRef Not Saved
    0,  // XRef Not Used

    {
        { 0x0B, 0x8B }, // (Offset,Value)-Pair #1
        { 0x0C, 0x1D }, // (Offset,Value)-Pair #2
        { 0x0D, 0xA4 }, // (Offset,Value)-Pair #3

        { 0x25, 0xF6 }, // (Offset,Value)-Pair #4
        { 0x26, 0x46 }, // (Offset,Value)-Pair #5
        { 0x27, 0x04 }, // (Offset,Value)-Pair #6
        { 0x28, 0x02 }, // (Offset,Value)-Pair #7

        { 0x39, 0xF3 }, // (Offset,Value)-Pair #8
        { 0x3A, 0xAB }, // (Offset,Value)-Pair #9

        { 0x90, 0xBF }, // (Offset,Value)-Pair #10
        { 0x91, 0x8A }, // (Offset,Value)-Pair #11
        { 0x92, 0x2A }, // (Offset,Value)-Pair #12
    }
};

// ******************************************************************
// * XInputGetCapabilities2
// ******************************************************************
/* Unreal Championship's version is different */
SOOVPA<12> XInputGetCapabilities4_1_0_4928 =
{
    0,  // Large == 0
    12, // Count == 12

    -1, // XRef Not Saved
    0,  // XRef Not Used

    {
		// mov     ebx, ds:KeRaiseIrqlToDpcLevel
        { 0x0B, 0x8B }, // (Offset,Value)-Pair #1
        { 0x0C, 0x1D }, // (Offset,Value)-Pair #2
        { 0x0D, 0xDC }, // (Offset,Value)-Pair #3

		// test    byte ptr [esi+4], 2
        { 0x25, 0xF6 }, // (Offset,Value)-Pair #4
        { 0x26, 0x46 }, // (Offset,Value)-Pair #5
        { 0x27, 0x04 }, // (Offset,Value)-Pair #6
        { 0x28, 0x02 }, // (Offset,Value)-Pair #7

		// rep stosd
        { 0x39, 0xF3 }, // (Offset,Value)-Pair #8
        { 0x3A, 0xAB }, // (Offset,Value)-Pair #9

		// mov  edi, offset unknown_libname_2
        { 0x90, 0xBF }, // (Offset,Value)-Pair #10
        { 0x91, 0x8C }, // (Offset,Value)-Pair #11
        { 0x92, 0x8C }, // (Offset,Value)-Pair #12
    }
};

// ******************************************************************
// * XInputGetCapabilities5
// ******************************************************************
/* DOAV */
SOOVPA<12> XInputGetCapabilities5_1_0_4928 =
{
    0,  // Large == 0
    12, // Count == 12

    -1, // XRef Not Saved
    0,  // XRef Not Used

    {
		// mov     ebx, ds:KeRaiseIrqlToDpcLevel
        { 0x0B, 0x8B }, // (Offset,Value)-Pair #1
        { 0x0C, 0x1D }, // (Offset,Value)-Pair #2
        { 0x0D, 0xF4 }, // (Offset,Value)-Pair #3

		// test    byte ptr [esi+4], 2
        { 0x25, 0xF6 }, // (Offset,Value)-Pair #4
        { 0x26, 0x46 }, // (Offset,Value)-Pair #5
        { 0x27, 0x04 }, // (Offset,Value)-Pair #6
        { 0x28, 0x02 }, // (Offset,Value)-Pair #7

		// rep stosd
        { 0x39, 0xF3 }, // (Offset,Value)-Pair #8
        { 0x3A, 0xAB }, // (Offset,Value)-Pair #9

		// mov  edi, offset unknown_libname_2
        { 0x90, 0xBF }, // (Offset,Value)-Pair #10
        { 0x91, 0x17 }, // (Offset,Value)-Pair #11
        { 0x92, 0xB7 }, // (Offset,Value)-Pair #12
    }
};

// ******************************************************************
// * XInputGetCapabilities6
// ******************************************************************
/* Defender */
SOOVPA<12> XInputGetCapabilities6_1_0_4928 =
{
    0,  // Large == 0
    12, // Count == 12

    -1, // XRef Not Saved
    0,  // XRef Not Used

    {
		// mov     ebx, ds:KeRaiseIrqlToDpcLevel
        { 0x0B, 0x8B }, // (Offset,Value)-Pair #1
        { 0x0C, 0x1D }, // (Offset,Value)-Pair #2
        { 0x0D, 0x78 }, // (Offset,Value)-Pair #3

		// test    byte ptr [esi+4], 2
        { 0x25, 0xF6 }, // (Offset,Value)-Pair #4
        { 0x26, 0x46 }, // (Offset,Value)-Pair #5
        { 0x27, 0x04 }, // (Offset,Value)-Pair #6
        { 0x28, 0x02 }, // (Offset,Value)-Pair #7

		// rep stosd
        { 0x39, 0xF3 }, // (Offset,Value)-Pair #8
        { 0x3A, 0xAB }, // (Offset,Value)-Pair #9

		// mov  edi, offset unknown_libname_2
        { 0x90, 0xBF }, // (Offset,Value)-Pair #10
        { 0x91, 0xE5 }, // (Offset,Value)-Pair #11
        { 0x92, 0xCF }, // (Offset,Value)-Pair #12
    }
};

// Blueshogun96 11/27/08
// This function actually began in 4831 XDKs.  Since 4831 is a
// rare XDK, I'm assuming no one paid much attention to it.
// ******************************************************************
// * XapiApplyKernelPatches
// ******************************************************************
SOOVPA<7> XapiApplyKernelPatches_1_0_4831 =
{
    0,  // Large == 0
    7,  // Count == 7

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x17, 0x81 },
        { 0x2A, 0x81 },
        { 0x4B, 0x05 },
        { 0x64, 0x1B },
		{ 0x94, 0xFF },
		{ 0x96, 0xFA },
        { 0xA2, 0xFF },
    }
};

// ******************************************************************
// * XInputGetCapabilities
// ******************************************************************
SOOVPA<12> XInputGetCapabilities_1_0_4831 =
{
    0,  // Large == 0
    12, // Count == 12

    -1, // XRef Not Saved
    0,  // XRef Not Used

    {
        { 0x0B, 0x8B }, // (Offset,Value)-Pair #1
        { 0x0C, 0x1D }, // (Offset,Value)-Pair #2
        { 0x0D, 0x88 }, // (Offset,Value)-Pair #3

        { 0x25, 0xF6 }, // (Offset,Value)-Pair #4
        { 0x26, 0x46 }, // (Offset,Value)-Pair #5
        { 0x27, 0x04 }, // (Offset,Value)-Pair #6
        { 0x28, 0x02 }, // (Offset,Value)-Pair #7

        { 0x39, 0xF3 }, // (Offset,Value)-Pair #8
        { 0x3A, 0xAB }, // (Offset,Value)-Pair #9

        { 0xAF, 0xC7 }, // (Offset,Value)-Pair #10
        { 0xB0, 0x45 }, // (Offset,Value)-Pair #11
        { 0xB1, 0xE2 }, // (Offset,Value)-Pair #12
    }
};

// ******************************************************************
// * XInputGetCapabilities2
// ******************************************************************
SOOVPA<12> XInputGetCapabilities2_1_0_4831 =
{
    0,  // Large == 0
    12, // Count == 12

    -1, // XRef Not Saved
    0,  // XRef Not Used

    {
        { 0x0B, 0x8B }, // (Offset,Value)-Pair #1
        { 0x0C, 0x1D }, // (Offset,Value)-Pair #2
        { 0x0D, 0x50 }, // (Offset,Value)-Pair #3

        { 0x25, 0xF6 }, // (Offset,Value)-Pair #4
        { 0x26, 0x46 }, // (Offset,Value)-Pair #5
        { 0x27, 0x04 }, // (Offset,Value)-Pair #6
        { 0x28, 0x02 }, // (Offset,Value)-Pair #7

        { 0x39, 0xF3 }, // (Offset,Value)-Pair #8
        { 0x3A, 0xAB }, // (Offset,Value)-Pair #9

        { 0xAF, 0xC7 }, // (Offset,Value)-Pair #10
        { 0xB0, 0x45 }, // (Offset,Value)-Pair #11
        { 0xB1, 0xE2 }, // (Offset,Value)-Pair #12
    }
};

// ******************************************************************
// * XInputGetCapabilities3
// ******************************************************************
SOOVPA<12> XInputGetCapabilities3_1_0_4831 =
{
    0,  // Large == 0
    12, // Count == 12

    -1, // XRef Not Saved
    0,  // XRef Not Used

    {
        { 0x0B, 0x8B }, // (Offset,Value)-Pair #1
        { 0x0C, 0x1D }, // (Offset,Value)-Pair #2
        { 0x0D, 0x14 }, // (Offset,Value)-Pair #3

        { 0x25, 0xF6 }, // (Offset,Value)-Pair #4
        { 0x26, 0x46 }, // (Offset,Value)-Pair #5
        { 0x27, 0x04 }, // (Offset,Value)-Pair #6
        { 0x28, 0x02 }, // (Offset,Value)-Pair #7

        { 0x39, 0xF3 }, // (Offset,Value)-Pair #8
        { 0x3A, 0xAB }, // (Offset,Value)-Pair #9

        { 0xAF, 0xC7 }, // (Offset,Value)-Pair #10
        { 0xB0, 0x45 }, // (Offset,Value)-Pair #11
        { 0xB1, 0xE2 }, // (Offset,Value)-Pair #12
    }
};

// ******************************************************************
// * XInputGetCapabilities4
// ******************************************************************
SOOVPA<12> XInputGetCapabilities4_1_0_4831 =
{
    0,  // Large == 0
    12, // Count == 12

    -1, // XRef Not Saved
    0,  // XRef Not Used

    {
        { 0x0B, 0x8B }, // (Offset,Value)-Pair #1
        { 0x0C, 0x1D }, // (Offset,Value)-Pair #2
        { 0x0D, 0x9C }, // (Offset,Value)-Pair #3

        { 0x25, 0xF6 }, // (Offset,Value)-Pair #4
        { 0x26, 0x46 }, // (Offset,Value)-Pair #5
        { 0x27, 0x04 }, // (Offset,Value)-Pair #6
        { 0x28, 0x02 }, // (Offset,Value)-Pair #7

        { 0x39, 0xF3 }, // (Offset,Value)-Pair #8
        { 0x3A, 0xAB }, // (Offset,Value)-Pair #9

        { 0xAF, 0xC7 }, // (Offset,Value)-Pair #10
        { 0xB0, 0x45 }, // (Offset,Value)-Pair #11
        { 0xB1, 0xE2 }, // (Offset,Value)-Pair #12
    }
};

// ******************************************************************
// * XInputGetCapabilities5
// ******************************************************************
SOOVPA<12> XInputGetCapabilities5_1_0_4831 =
{
    0,  // Large == 0
    8,	// Count == 8

    -1, // XRef Not Saved
    0,  // XRef Not Used

    {
		{ 0x22, 0xF6 },
		{ 0x23, 0x46 },
		{ 0x24, 0x04 },
		{ 0x25, 0x02 },
		{ 0x44, 0x6A },
		{ 0x45, 0x12 },
		{ 0xF1, 0xC2 },
		{ 0xF2, 0x08 },
    }
};

// ******************************************************************
// * XLoadSectionA
// ******************************************************************
SOOVPA<10> XLoadSectionA_1_0_4627 = 
{
	0,	// Large == 0
	10,	// Count == 10

	-1,	// XRef not saved
	0,	// XRef not used

	{
		// XLoadSectionA+0x0F : call XLoadSectionByHandle
//		{ 0x10, XREF_XLoadSectionByHandle },

		// XLoadSectionA+0x0: push dword ptr [esp+4]
		{ 0x00, 0xFF },
		{ 0x01, 0x74 },
		{ 0x02, 0x24 },
		{ 0x03, 0x04 },

		// XLoadSectionA+0x9: cmp eax, 0xFFFFFFFF
		{ 0x09, 0x83 },
		{ 0x0A, 0xF8 },
		{ 0x0B, 0xFF },

		// XLoadSectionA+0xE: push eax
		{ 0x0E, 0x50 },

		// XLoadSectionA+0x18: ret 4
		{ 0x18, 0xC2 },
		{ 0x19, 0x04 },
	}
};

// ******************************************************************
// * XFreeSectionA
// ******************************************************************
SOOVPA<11> XFreeSectionA_1_0_4627 = 
{
	0,	// Large == 0
	11,	// Count == 11

	-1,	// XRef not saved
	0,	// XRef not used

	{
		// XFreeSectionA+0x0F : call XFreeSectionByHandle
//		{ 0x10, XREF_XFreeSectionByHandle },

		// XLoadSectionA+0x0: push dword ptr [esp+4]
		{ 0x00, 0xFF },
		{ 0x01, 0x74 },
		{ 0x02, 0x24 },
		{ 0x03, 0x04 },

		// XLoadSectionA+0x9: cmp eax, 0xFFFFFFFF
		{ 0x09, 0x83 },
		{ 0x0A, 0xF8 },
		{ 0x0B, 0xFF },

		// XLoadSectionA+0x14: jz 0x2
		{ 0x14, 0xEB },
		{ 0x15, 0x02 },

		// XLoadSectionA+0x18: ret 4
		{ 0x18, 0xC2 },
		{ 0x19, 0x04 },
	}
};

// ******************************************************************
// * GetOverlappedResult
// ******************************************************************
SOOVPA<7> GetOverlappedResult_1_0_4627 = 
{
    0,  // Large == 0
    7,  // Count == 7

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x0B, 0x75 },
        { 0x18, 0xC0 },
        { 0x27, 0xEB },
        { 0x32, 0x00 },
        { 0x3F, 0xEB },
        { 0x4C, 0x89 },
        { 0x59, 0x56 },
    }
};

// ******************************************************************
// * XLaunchNewImageA
// ******************************************************************
SOOVPA<8> XLaunchNewImageA_1_0_4627 = 
{
    0,  // Large == 0
    8,  // Count == 8

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x1E, 0x80 },
        { 0x3E, 0xC0 },
        { 0x5E, 0xFF },
        { 0x7E, 0xFC },
        { 0x9E, 0x08 },
        { 0xBE, 0x50 },
        { 0xDE, 0x05 },
        { 0xFE, 0x85 },
    }
};

// ******************************************************************
// * XLaunchNewImageA
// ******************************************************************
SOOVPA<12> XLaunchNewImageA_1_0_4928 = 
{
    0,   // Large == 0
    12,  // Count == 12

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        // XLaunchNewImageA+0x03 : sub esp, 0x384
		{ 0x03, 0x81 },
		{ 0x04, 0xEC },
		{ 0x05, 0x84 },
		{ 0x06, 0x03 },
		{ 0x07, 0x00 },
		{ 0x08, 0x00 },
		// XLaunchNewImageA+0x33 : cmp al, 0x44
		{ 0x33, 0x3C },
		{ 0x34, 0x44 },
		// XLaunchNewImageA+0x41 : cmp byte ptr [esi+1], 0x3A
		{ 0x41, 0x80 },
		{ 0x42, 0x7E },
		{ 0x43, 0x02 },
		{ 0x44, 0x5C },
    }
};

// ******************************************************************
// * XGetLaunchInfo
// ******************************************************************
SOOVPA<7> XGetLaunchInfo_1_0_4627 = 
{
    0,  // Large == 0
    7,  // Count == 7

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x0B, 0x8B },
        { 0x18, 0x15 },
        { 0x25, 0x8B },
        { 0x32, 0x30 },
        { 0x3F, 0x00 },
        { 0x4C, 0x83 },
        { 0x59, 0x5E },
    }
};

// ******************************************************************
// * XSetProcessQuantumLength
// ******************************************************************
SOOVPA<7> XSetProcessQuantumLength_1_0_4627 = 
{
    0,  // Large == 0
    7,  // Count == 7

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x01, 0xA1 },
        { 0x04, 0x00 },
        { 0x07, 0x4C },
        { 0x0A, 0x8B },
        { 0x0D, 0x8D },
        { 0x10, 0x89 },
        { 0x13, 0xC2 },
    }
};

// ******************************************************************
// * timeSetEvent
// ******************************************************************
SOOVPA<7> timeSetEvent_1_0_4627 = 
{
    0,  // Large == 0
    7,  // Count == 7

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x1E, 0x8D },
        { 0x3E, 0x89 },
        { 0x5E, 0x15 },
        { 0x7E, 0x3F },
        { 0x9E, 0x03 },
        { 0xBE, 0x32 },
        { 0xDE, 0x89 },
    }
};

// ******************************************************************
// * timeKillEvent
// ******************************************************************
SOOVPA<8> timeKillEvent_1_0_4627 = 
{
    0,  // Large == 0
    8,  // Count == 8

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x0E, 0x8B },
        { 0x1A, 0xC2 },
        { 0x28, 0x8D },
        { 0x36, 0x56 },
        { 0x44, 0x00 },
        { 0x52, 0x00 },
        { 0x60, 0x5E },
        { 0x6E, 0x00 },
    }
};

// ******************************************************************
// * RaiseException
// ******************************************************************
SOOVPA<7> RaiseException_1_0_4627 = 
{
    0,  // Large == 0
    7,  // Count == 7

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x09, 0x83 },
        { 0x14, 0x8B },
        { 0x1F, 0xC7 },
        { 0x2A, 0x10 },
        { 0x35, 0x89 },
        { 0x40, 0x5F },
        { 0x4B, 0xFF },
    }
};


// ******************************************************************
// * VirtualProtect
// ******************************************************************
SOOVPA<7> VirtualProtect_1_0_4627 = 
{
    0,  // Large == 0
    7,  // Count == 7

    0/*XREF_VirtualProtect*/,  // Xref Is Saved
    0,  // Xref Not Used

    {
        { 0x04, 0x8D },
        { 0x0A, 0x24 },
        { 0x10, 0x10 },
        { 0x18, 0x85 },
        { 0x1C, 0x33 },
        { 0x22, 0xE8 },
        { 0x28, 0xC0 },
    }
};

// ******************************************************************
// * CreateSemaphoreA
// ******************************************************************
SOOVPA<7> CreateSemaphoreA_1_0_4627 = 
{
    0,  // Large == 0
    7,  // Count == 7

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x0A, 0x74 },
        { 0x16, 0x50 },
        { 0x22, 0x10 },
        { 0x31, 0x85 },
        { 0x3A, 0x75 },
        { 0x4A, 0x8B },
        { 0x55, 0x33 },
    }
};

// ******************************************************************
// * ReleaseSemaphore
// ******************************************************************
SOOVPA<7> ReleaseSemaphore_1_0_4627 = 
{
    0,  // Large == 0
    7,  // Count == 7

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x03, 0x0C },
        { 0x08, 0xFF },
        { 0x0D, 0x15 },
        { 0x12, 0x85 },
        { 0x17, 0xC0 },
        { 0x1C, 0xE8 },
        { 0x21, 0x33 },
    }
};

// ******************************************************************
// * XMountAlternateTitleA
// ******************************************************************
SOOVPA<7> XMountAlternateTitleA_1_0_4627 = 
{
    0,  // Large == 0
    7,  // Count == 7

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x1E, 0x0F },
        { 0x3E, 0x56 },
        { 0x5E, 0xFF },
        { 0x7E, 0x8D },
        { 0x9E, 0x50 },
        { 0xBE, 0x66 },
        { 0xDE, 0xF0 },
    }
};

// ******************************************************************
// * XMountAlternateTitleA
// ******************************************************************
SOOVPA<7> XMountAlternateTitleA_1_0_4928 = 
{
    0,  // Large == 0
    7,  // Count == 7

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x1E, 0x0F },
        { 0x3E, 0x83 },
        { 0x5E, 0x03 },
        { 0x7E, 0x8D },
        { 0x9E, 0x00 },
        { 0xBE, 0x01 },
        { 0xDE, 0x45 },
    }
};

// ******************************************************************
// * XUnmountAlternateTitleA
// ******************************************************************
SOOVPA<7> XUnmountAlternateTitleA_1_0_4627 = 
{
    0,  // Large == 0
    7,  // Count == 7

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x0A, 0x65 },
        { 0x16, 0xFF },
        { 0x23, 0x83 },
        { 0x2E, 0x45 },
        { 0x3A, 0x50 },
        { 0x46, 0x0B },
        { 0x52, 0x50 },
    }
};

// ******************************************************************
// * XGetFileCacheSize
// ******************************************************************
SOOVPA<6> XGetFileCacheSize_1_0_4627 = 
{
    0,  // Large == 0
    6,  // Count == 6

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x00, 0xFF },
        { 0x01, 0x15 },
        { 0x06, 0xC1 },
        { 0x07, 0xE0 },
        { 0x08, 0x0C },
        { 0x09, 0xC3 },
    }
};

// ******************************************************************
// * MoveFileA
// ******************************************************************
SOOVPA<7> MoveFileA_1_0_4627 = 
{
    0,  // Large == 0
    7,  // Count == 7

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x11, 0x8D },
        { 0x24, 0xE8 },
        { 0x37, 0x50 },
        { 0x4A, 0x7D },
        { 0x5D, 0xFF },
        { 0x74, 0xFF },
        { 0x83, 0x33 },
    }
};

// ******************************************************************
// * XInputGetDeviceDescription
// ******************************************************************
SOOVPA<9> XInputGetDeviceDescription_1_0_4831 = 
{
	0,	// Large == 0
	9,	// Count == 9

	-1,	// Xref Not Saved
	0,	// Xref Not Used

	{
		{ 0x03, 0x83 },
		{ 0x04, 0xEC },
		{ 0x05, 0x48 },
		{ 0x06, 0x83 },
		{ 0x07, 0x65 },
		{ 0x08, 0xF8 },
		{ 0x09, 0x00 },
		{ 0x34, 0x6A },
		{ 0x35, 0x06 },
	}
};

// ******************************************************************
// * WaitForSingleObjectEx
// ******************************************************************
SOOVPA<7> WaitForSingleObjectEx_1_0_4627 = 
{
    0,  // Large == 0
    7,  // Count == 7

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x07, 0x75 },
        { 0x12, 0x8B },
        { 0x19, 0x01 },
        { 0x23, 0x85 },
        { 0x2B, 0x74 },
        { 0x34, 0xEB },
        { 0x3D, 0xC8 },
    }
};

// ******************************************************************
// * JvsEEPROM_Read
// ******************************************************************
SOOVPA<8> JvsEEPROM_Read_1_0_5028 = 
{
    0,  // Large == 0
    8,  // Count == 8

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x00, 0x51 },
        { 0x11, 0x83 },
        { 0x12, 0xF9 },
        { 0x13, 0x40 },
        { 0x43, 0x6A },
		{ 0x44, 0x17 },
        { 0x4C, 0x6A },
        { 0x4D, 0x40 },
    }
};

// ******************************************************************
// * JvsBACKUP_Read
// ******************************************************************
SOOVPA<8> JvsBACKUP_Read_1_0_5028 = 
{
    0,  // Large == 0
    8,  // Count == 8

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x00, 0x8B },
        { 0x11, 0x8D },
        { 0x12, 0x54 },
        { 0x13, 0x24 },
        { 0x43, 0xBE },
		{ 0x44, 0x00 },
        { 0x4C, 0x05 },
        { 0x4D, 0x00 },
    }
};

// ******************************************************************
// * JvsScFirmwareDownload
// ******************************************************************
SOOVPA<8> JvsScFirmwareDownload_1_0_5028 = 
{
    0,  // Large == 0
    8,  // Count == 8

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x03, 0x8B },
        { 0x04, 0x4C },
        { 0x05, 0x24 },
        { 0x06, 0x30 },
        { 0x07, 0x53 },
		{ 0x0F, 0x83 },
        { 0x10, 0xF9 },
        { 0x11, 0x20 },
    }
};

// ******************************************************************
// * JvsBACKUP_Write
// ******************************************************************
SOOVPA<8> JvsBACKUP_Write_1_0_5028 = 
{
    0,  // Large == 0
    8,  // Count == 8

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x00, 0x8B },
        { 0x11, 0x8D },
        { 0x12, 0x54 },
        { 0x13, 0x24 },
        { 0x43, 0xBE },
		{ 0x78, 0xC2 },
        { 0x79, 0x10 },
        { 0x7A, 0x00 },
    }
};

// ******************************************************************
// * JvsEEPROM_Write
// ******************************************************************
SOOVPA<9> JvsEEPROM_Write_1_0_5028 = 
{
    0,  // Large == 0
    9,  // Count == 9

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x3E, 0x8D },
        { 0x3F, 0x44 },
        { 0x40, 0x24 },
        { 0x41, 0x24 },
        { 0x42, 0x50 },
		{ 0x8D, 0x6A },
        { 0x8E, 0x1E },
        { 0x9C, 0x6A },
		{ 0x9D, 0x09 },
    }
};

// ******************************************************************
// * JvsFirmwareUpload
// ******************************************************************
SOOVPA<8> JvsFirmwareUpload_1_0_5028 = 
{
    0,  // Large == 0
    8,  // Count == 8

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x00, 0x83 },
        { 0x12, 0x83 },
        { 0x13, 0xF9 },
        { 0x14, 0x20 },
        { 0x40, 0x8D },
		{ 0x41, 0x44 },
        { 0x42, 0x24 },
        { 0x43, 0x4C },
    }
};

// ******************************************************************
// * JvsScFirmwareUpload
// ******************************************************************
SOOVPA<8> JvsScFirmwareUpload_1_0_5028 = 
{
    0,  // Large == 0
    8,  // Count == 8

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x00, 0x51 },
        { 0x10, 0x83 },
        { 0x11, 0xF9 },
        { 0x12, 0x20 },
        { 0x3C, 0x8D },
		{ 0x3D, 0x44 },
        { 0x3E, 0x24 },
        { 0x3F, 0x2C },
    }
};

// ******************************************************************
// * JvsFirmwareDownload
// ******************************************************************
SOOVPA<8> JvsFirmwareDownload_1_0_5028 = 
{
    0,  // Large == 0
    8,  // Count == 8

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x03, 0x8B },
        { 0x04, 0x4C },
        { 0x05, 0x24 },
        { 0x06, 0x30 },
        { 0x07, 0x53 },
		{ 0x0F, 0x83 },
        { 0x58, 0x6A },
        { 0x59, 0x20 },
    }
};

// ******************************************************************
// * JvsRTC_Read
// ******************************************************************
SOOVPA<8> JvsRTC_Read_1_0_5028 = 
{
    0,  // Large == 0
    8,  // Count == 8

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x23, 0x6A },
        { 0x24, 0x1C },
        { 0x42, 0x81 },
        { 0x43, 0xE2 },
        { 0x44, 0x00 },
		{ 0x45, 0xFF },
        { 0x46, 0xFF },
        { 0x47, 0xFF },
    }
};

// ******************************************************************
// * JvsNodeSendPacket
// ******************************************************************
SOOVPA<8> JvsNodeSendPacket_1_0_5028 = 
{
    0,  // Large == 0
    8,  // Count == 8

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x23, 0x6A },
        { 0x24, 0x20 },
        { 0x26, 0x6A },
        { 0x27, 0x0B },
        { 0x54, 0xF6 },
		{ 0x55, 0xC3 },
        { 0x56, 0x01 },
        { 0xC9, 0xC2 },
    }
};

// ******************************************************************
// * JvsNodeReveivePacket
// ******************************************************************
SOOVPA<8> JvsNodeReceivePacket_1_0_5028 = 
{
    0,  // Large == 0
    8,  // Count == 8

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x28, 0x6A },
        { 0x29, 0x19 },
        { 0x2B, 0x6A },
        { 0x2C, 0x03 },
        { 0x54, 0xF6 },
		{ 0x55, 0xC3 },
        { 0x56, 0x01 },
        { 0xC9, 0xC2 },
    }
};

// ******************************************************************
// * JvsUnknown1
// ******************************************************************
SOOVPA<8> JvsUnknown1_1_0_5028 = 
{
    0,  // Large == 0
    8,  // Count == 8

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x00, 0x81 },
        { 0x01, 0xEC },
        { 0x75, 0xFF },
        { 0x76, 0x15 },
        { 0x77, 0x80 },
		{ 0x78, 0x02 },
        { 0x79, 0x14 },
        { 0x7A, 0x00 },
    }
};

// ******************************************************************
// * JvsUnknown2
// ******************************************************************
SOOVPA<8> JvsUnknown2_1_0_5028 = 
{
    0,  // Large == 0
    8,  // Count == 8

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x57, 0x81 },
        { 0x58, 0xC4 },
        { 0x59, 0x94 },
        { 0x5A, 0x00 },
        { 0x5B, 0x00 },
		{ 0x5D, 0xC2 },
        { 0x5E, 0x28 },
        { 0x5F, 0x00 },
    }
};

// ******************************************************************
// * JvsUnknown3
// ******************************************************************
SOOVPA<8> JvsUnknown3_1_0_5028 = 
{
    0,  // Large == 0
    8,  // Count == 8

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x0C, 0x81 },
        { 0x0D, 0xEC },
        { 0x0E, 0x90 },
        { 0x0F, 0x00 },
        { 0x10, 0x00 },
		{ 0x5B, 0xC2 },
        { 0x5C, 0x28 },
        { 0x5D, 0x00 },
    }
};

// ******************************************************************
// * XAPI_1_0_4627
// ******************************************************************
OOVPATable XAPI_1_0_4627[] =
{
    // XapiApplyKernelPatches
    {
        (OOVPA*)&XapiApplyKernelPatches_1_0_4928,

        XTL::EmuXapiApplyKernelPatches,

        #ifdef _DEBUG_TRACE
        "EmuXapiApplyKernelPatches"
        #endif
    },
    // XapiInitProcess
    {
        (OOVPA*)&XapiInitProcess_1_0_4928,

        XTL::EmuXapiInitProcess,

        #ifdef _DEBUG_TRACE
        "EmuXapiInitProcess"
        #endif
    },
	// XapiInitProcess
    {
        (OOVPA*)&XapiInitProcess_1_0_4831,

        XTL::EmuXapiInitProcess,

        #ifdef _DEBUG_TRACE
		"EmuXapiInitProcess (4831)"
        #endif
    },
	// XapiInitProcess
    {
        (OOVPA*)&XapiInitProcess_1_0_5028,

        XTL::EmuXapiInitProcess,

        #ifdef _DEBUG_TRACE
		"EmuXapiInitProcess (5028)"
        #endif
    },
    // XFormatUtilityDrive
    {
        (OOVPA*)&XFormatUtilityDrive_1_0_4627,

        XTL::EmuXFormatUtilityDrive,

        #ifdef _DEBUG_TRACE
        "EmuXFormatUtilityDrive"
        #endif
    },
    // SetThreadPriorityBoost
    {
        (OOVPA*)&SetThreadPriorityBoost_1_0_4627,

        XTL::EmuSetThreadPriorityBoost,

        #ifdef _DEBUG_TRACE
        "EmuSetThreadPriorityBoost"
        #endif
    },
    // SetThreadPriority (* unchanged since 3911 *)
    {
        (OOVPA*)&SetThreadPriority_1_0_3911,

        XTL::EmuSetThreadPriority,

        #ifdef _DEBUG_TRACE
        "EmuSetThreadPriority"
        #endif
    },
    // GetThreadPriority
    {
        (OOVPA*)&GetThreadPriority_1_0_4627,

        XTL::EmuGetThreadPriority,

        #ifdef _DEBUG_TRACE
        "EmuGetThreadPriority"
        #endif
    },
    // XRegisterThreadNotifyRoutine (* unchanged since 3911 *)
    {
        (OOVPA*)&XRegisterThreadNotifyRoutine_1_0_3911,

        XTL::EmuXRegisterThreadNotifyRoutine,

        #ifdef _DEBUG_TRACE
        "EmuXRegisterThreadNotifyRoutine"
        #endif
    },
    // RtlCreateHeap (* unchanged since 1.0.3911 *)
    {
        (OOVPA*)&RtlCreateHeap_1_0_3911,

        XTL::EmuRtlCreateHeap,

        #ifdef _DEBUG_TRACE
        "EmuRtlCreateHeap"
        #endif
    },
    // RtlAllocateHeap (* unchanged since 1.0.3911 *)
    {
        (OOVPA*)&RtlAllocateHeap_1_0_3911,

        XTL::EmuRtlAllocateHeap,

        #ifdef _DEBUG_TRACE
        "EmuRtlAllocateHeap"
        #endif
    },
    // RtlFreeHeap
    {
        (OOVPA*)&RtlFreeHeap_1_0_4627,

        XTL::EmuRtlFreeHeap,

        #ifdef _DEBUG_TRACE
        "EmuRtlFreeHeap"
        #endif
    },
    // RtlReAllocateHeap
    {
        (OOVPA*)&RtlReAllocateHeap_1_0_4627,

        XTL::EmuRtlReAllocateHeap,

        #ifdef _DEBUG_TRACE
        "EmuRtlReAllocateHeap"
        #endif
    },
    // RtlSizeHeap (* unchanged since 3911 *)
    {
        (OOVPA*)&RtlSizeHeap_1_0_3911,

        XTL::EmuRtlSizeHeap,

        #ifdef _DEBUG_TRACE
        "EmuRtlSizeHeap"
        #endif
    },
    // QueryPerformanceCounter (* unchanged since 4361 *)
    {
        (OOVPA*)&QueryPerformanceCounter_1_0_4361,

        XTL::EmuQueryPerformanceCounter,

        #ifdef _DEBUG_TRACE
        "EmuQueryPerformanceCounter"
        #endif
    },
    // QueryPerformanceFrequency (* unchanged since 4361 *)
    {
        (OOVPA*)&QueryPerformanceFrequency_1_0_4361,

        XTL::EmuQueryPerformanceFrequency,

        #ifdef _DEBUG_TRACE
        "EmuQueryPerformanceFrequency"
        #endif
    },
    // XMountUtilityDrive (* unchanged since 4432 *)
    {
        (OOVPA*)&XMountUtilityDrive_1_0_4432,

        XTL::EmuXMountUtilityDrive,

        #ifdef _DEBUG_TRACE
        "EmuXMountUtilityDrive"
        #endif
    },
    // XInitDevices (* unchanged since 1.0.3911 *)
    {
        (OOVPA*)&XInitDevices_1_0_3911,

        XTL::EmuXInitDevices,

        #ifdef _DEBUG_TRACE
        "EmuXInitDevices"
        #endif
    },
    // XGetDevices (* unchanged since 1.0.4134 *)
    {
        (OOVPA*)&XGetDevices_1_0_4134,

        XTL::EmuXGetDevices,

        #ifdef _DEBUG_TRACE
        "EmuXGetDevices"
        #endif
    },
    // XInputOpen (* unchanged since 1.0.4361 *)
    {
        (OOVPA*)&XInputOpen_1_0_4361,

        XTL::EmuXInputOpen,

        #ifdef _DEBUG_TRACE
        "EmuXInputOpen"
        #endif
    },
    // XInputPoll (* unchanged since 4134 *)
    {
        (OOVPA*)&XInputPoll_1_0_4134,

        XTL::EmuXInputPoll,

        #ifdef _DEBUG_TRACE
        "EmuXInputPoll"
        #endif
    },
	// XID_fCloseDevice
    {
        (OOVPA*)&XID_fCloseDevice_1_0_4627, 0,

        #ifdef _DEBUG_TRACE
		"XID_fCloseDevice (4627) (XREF)"
        #endif
    },
    // XID_fCloseDevice
    {
        (OOVPA*)&XID_fCloseDevice_1_0_4928, 0,

        #ifdef _DEBUG_TRACE
        "XID_fCloseDevice (XREF)"
        #endif
    },
    // XInputClose
    {
        (OOVPA*)&XInputClose_1_0_4928,

        XTL::EmuXInputClose,

        #ifdef _DEBUG_TRACE
        "EmuXInputClose"
        #endif
    },
    // XInputGetCapabilities (* unchanged since 1.0.4361 *)
    {
        (OOVPA*)&XInputGetCapabilities_1_0_4361,

        XTL::EmuXInputGetCapabilities,

        #ifdef _DEBUG_TRACE
        "EmuXInputGetCapabilities"
        #endif
    },
    // XInputGetState (* unchanged since 1.0.4361 *)
    {
        (OOVPA*)&XInputGetState_1_0_4361,

        XTL::EmuXInputGetState,

        #ifdef _DEBUG_TRACE
        "EmuXInputGetState"
        #endif
    },
    // XInputGetState
    {
        (OOVPA*)&XInputGetState_1_0_4928,

        XTL::EmuXInputGetState,

        #ifdef _DEBUG_TRACE
        "EmuXInputGetState"
        #endif
    },
    // XInputGetCapabilities
    {
        (OOVPA*)&XInputGetCapabilities_1_0_4928,

        XTL::EmuXInputGetCapabilities,

        #ifdef _DEBUG_TRACE
        "EmuXInputGetCapabilities"
        #endif
    },
	// XInputGetCapabilities2
    {
        (OOVPA*)&XInputGetCapabilities2_1_0_4928,

        XTL::EmuXInputGetCapabilities,

        #ifdef _DEBUG_TRACE
        "EmuXInputGetCapabilities2"
        #endif
    },
	// XInputGetCapabilities3
    {
        (OOVPA*)&XInputGetCapabilities3_1_0_4928,

        XTL::EmuXInputGetCapabilities,

        #ifdef _DEBUG_TRACE
        "EmuXInputGetCapabilities3"
        #endif
    },
	// XInputGetCapabilities4
    {
        (OOVPA*)&XInputGetCapabilities4_1_0_4928,

        XTL::EmuXInputGetCapabilities,

        #ifdef _DEBUG_TRACE
        "EmuXInputGetCapabilities4"
        #endif
    },
	// XInputGetCapabilities5
    {
        (OOVPA*)&XInputGetCapabilities5_1_0_4928,

        XTL::EmuXInputGetCapabilities,

        #ifdef _DEBUG_TRACE
		"EmuXInputGetCapabilities(5)"
        #endif
    },
    // XInputSetState (* unchanged since 1.0.4361 *)
    {
        (OOVPA*)&XInputSetState_1_0_4361,

        XTL::EmuXInputSetState,

        #ifdef _DEBUG_TRACE
        "EmuXInputSetState"
        #endif
    },
	// XInputSetState
    {
        (OOVPA*)&XInputSetState_1_0_4928,

        XTL::EmuXInputSetState,

        #ifdef _DEBUG_TRACE
		"EmuXInputSetState (4928)"
        #endif
    },
    /* obsolete?
    // XapiThreadStartup (* unchanged since 1.0.4361 *)
    {
        (OOVPA*)&XapiThreadStartup_1_0_4361,

        XTL::EmuXapiThreadStartup,

        #ifdef _DEBUG_TRACE
        "EmuXapiThreadStartup"
        #endif
    },
    //*/
    //* Too High Level
    // XapiInitProcess (* unchanged since 1.0.4361 *)
    {
        (OOVPA*)&XapiInitProcess_1_0_4361,

        XTL::EmuXapiInitProcess,

        #ifdef _DEBUG_TRACE
        "EmuXapiInitProcess"
        #endif
    },
    //*/
    // XapiBootToDash (* unchanged since 1.0.3911 *)
    {
        (OOVPA*)&XapiBootDash_1_0_3911,

        XTL::EmuXapiBootDash,

        #ifdef _DEBUG_TRACE
        "EmuXapiBootDash"
        #endif
    },
	// XapiApplyKernelPatches
    {
        (OOVPA*)&XapiApplyKernelPatches_1_0_4831,

        XTL::EmuXapiApplyKernelPatches,

        #ifdef _DEBUG_TRACE
        "EmuXapiApplyKernelPatches_4831"
        #endif
    },
	// XInputGetCapabilities
    {
        (OOVPA*)&XInputGetCapabilities_1_0_4831,

        XTL::EmuXInputGetCapabilities,

        #ifdef _DEBUG_TRACE
        "EmuXInputGetCapabilities_4831"
        #endif
    },
	// XInputGetCapabilities2
    {
        (OOVPA*)&XInputGetCapabilities2_1_0_4831,

        XTL::EmuXInputGetCapabilities,

        #ifdef _DEBUG_TRACE
        "EmuXInputGetCapabilities2_4831"
        #endif
    },
	// XInputGetCapabilities3
    {
        (OOVPA*)&XInputGetCapabilities3_1_0_4831,

        XTL::EmuXInputGetCapabilities,

        #ifdef _DEBUG_TRACE
        "EmuXInputGetCapabilities3_4831"
        #endif
    },
	// XInputGetCapabilities4
    {
        (OOVPA*)&XInputGetCapabilities4_1_0_4831,

        XTL::EmuXInputGetCapabilities,

        #ifdef _DEBUG_TRACE
        "EmuXInputGetCapabilities4_4831"
        #endif
    },
	// XInputGetCapabilities5
    {
        (OOVPA*)&XInputGetCapabilities5_1_0_4831,

        XTL::EmuXInputGetCapabilities,

        #ifdef _DEBUG_TRACE
        "EmuXInputGetCapabilities5_4831"
        #endif
    },
	// XInputGetCapabilities6
    {
        (OOVPA*)&XInputGetCapabilities6_1_0_4928,

        XTL::EmuXInputGetCapabilities,

        #ifdef _DEBUG_TRACE
        "EmuXInputGetCapabilities6_4928"
        #endif
    },
	// XGetSectionHandleA (* unchanged since 4134 *)
	{
		(OOVPA*)&XGetSectionHandleA_1_0_4134, 
			
		XTL::EmuXGetSectionHandleA,

		#ifdef _DEBUG_TRACE
		"EmuXGetSectionHandleA"
		#endif
	},
	// XLoadSectionByHandle (* unchanged since 4134 *)
	{
		(OOVPA*)&XLoadSectionByHandle_1_0_4134, 
			
		XTL::EmuXLoadSectionByHandle,

		#ifdef _DEBUG_TRACE
		"EmuXLoadSectionByHandle"
		#endif
	},
	// XFreeSectionByHandle (* unchanged since 4134 *)
	{
		(OOVPA*)&XFreeSectionByHandle_1_0_4134, 
			
		XTL::EmuXFreeSectionByHandle,

		#ifdef _DEBUG_TRACE
		"EmuXFreeSectionByHandle"
		#endif
	},
	// XLoadSectionA
	{
		(OOVPA*)&XLoadSectionA_1_0_4627, 
			
		XTL::EmuXLoadSectionA,

		#ifdef _DEBUG_TRACE
		"EmuXLoadSectionA"
		#endif
	},
	// XFreeSectionA
	{
		(OOVPA*)&XFreeSectionA_1_0_4627, 
			
		XTL::EmuXFreeSectionA,

		#ifdef _DEBUG_TRACE
		"EmuXFreeSectionA"
		#endif
	},
    // +s
    /* not necessary?
    // XCalculateSignatureBeginEx
    {
        (OOVPA*)&XCalculateSignatureBeginEx_1_0_4627,

        XTL::EmuXCalculateSignatureBeginEx,

        #ifdef _DEBUG_TRACE
        "EmuXCalculateSignatureBeginEx (XREF&FUNC)"
        #endif
    },
    // XCalculateSignatureBegin
    {
        (OOVPA*)&XCalculateSignatureBegin_1_0_4627,

        XTL::EmuXCalculateSignatureBegin,

        #ifdef _DEBUG_TRACE
        "EmuXCalculateSignatureBegin"
        #endif
    },
    // XCalculateSignatureUpdate
    {
        (OOVPA*)&XCalculateSignatureUpdate_1_0_4627,

        XTL::EmuXCalculateSignatureUpdate,

        #ifdef _DEBUG_TRACE
        "EmuXCalculateSignatureUpdate"
        #endif
    },
    // XCalculateSignatureEnd
    {
        (OOVPA*)&XCalculateSignatureEnd_1_0_4627,

        XTL::EmuXCalculateSignatureEnd,

        #ifdef _DEBUG_TRACE
        "EmuXCalculateSignatureEnd"
        #endif
    },
    //*/
    // s+
	// CreateFiber (* unchanged since 3911 *)
	{
		(OOVPA*)&CreateFiber_1_0_3911,

		XTL::EmuCreateFiber,

		#ifdef _DEBUG_TRACE
		"EmuCreateFiber"
		#endif
	},
	// DeleteFiber (* unchanged since 3911 *)
	{
		(OOVPA*)&DeleteFiber_1_0_3911,

		XTL::EmuDeleteFiber,

		#ifdef _DEBUG_TRACE
		"EmuDeleteFiber"
		#endif
	},
	// GetTimeZoneInformation (* unchanged since 3911 *)
    {
        (OOVPA*)&GetTimeZoneInformation_1_0_3911,

        XTL::EmuGetTimeZoneInformation,

        #ifdef _DEBUG_TRACE
        "GetTimeZoneInformation"
        #endif
    },
	// GetExitCodeThread (* unchanged since 3911 *)
    {
        (OOVPA*)&GetExitCodeThread_1_0_3911,

        XTL::EmuGetExitCodeThread,

        #ifdef _DEBUG_TRACE
        "EmuGetExitCodeThread"
        #endif
    },
	// RtlDestroyHeap (* unchanged since 4134 *)
    {
        (OOVPA*)&RtlDestroyHeap_1_0_4134,

        XTL::EmuRtlDestroyHeap,

        #ifdef _DEBUG_TRACE
        "EmuRtlDestroyHeap"
        #endif
    },
	// GetOverlappedResult
    {
        (OOVPA*)&GetOverlappedResult_1_0_4627,

        XTL::EmuGetOverlappedResult,

        #ifdef _DEBUG_TRACE
        "EmuGetOverlappedResult"
        #endif
    },
	// XLaunchNewImageA
    {
        (OOVPA*)&XLaunchNewImageA_1_0_4627,
        XTL::EmuXLaunchNewImage,

        #ifdef _DEBUG_TRACE
		"EmuXLaunchNewImageA"
        #endif
    },
	// XLaunchNewImageA
    {
        (OOVPA*)&XLaunchNewImageA_1_0_4928,
        XTL::EmuXLaunchNewImage,

        #ifdef _DEBUG_TRACE
		"EmuXLaunchNewImageA"
        #endif
    },
	// XGetLaunchInfo
    {
        (OOVPA*)&XGetLaunchInfo_1_0_4627,
        XTL::EmuXGetLaunchInfo,

        #ifdef _DEBUG_TRACE
        "EmuXGetLaunchInfo"
        #endif
    },
	// XSetProcessQuantumLength
    {
        (OOVPA*)&XSetProcessQuantumLength_1_0_4627,
		XTL::EmuXSetProcessQuantumLength,

        #ifdef _DEBUG_TRACE
        "EmuXSetProcessQuantumLength"
        #endif
    },
	// SignalObjectAndWait (* unchanged since 3911 *)
	{
		(OOVPA*)&SignalObjectAndWait_1_0_3911, 
			
		XTL::EmuSignalObjectAndWait,

		#ifdef _DEBUG_TRACE
		"EmuSignalObjectAndWait"
		#endif
	},
	// timeSetEvent
    {
        (OOVPA*)&timeSetEvent_1_0_4627,
        XTL::EmutimeSetEvent,

        #ifdef _DEBUG_TRACE
        "EmutimeSetEvent"
        #endif
    },
    // timeKillEvent
    {
        (OOVPA*)&timeKillEvent_1_0_4627,
        XTL::EmutimeKillEvent,

        #ifdef _DEBUG_TRACE
        "EmutimeKillEvent"
        #endif
    },
	// RaiseException
    {
        (OOVPA*)&RaiseException_1_0_4627,
        XTL::EmuRaiseException,

        #ifdef _DEBUG_TRACE
        "EmuRaiseException"
        #endif
    },
	// QueueUserAPC (* unchanged since 3911 *)
	{ 
		(OOVPA*)&QueueUserAPC_1_0_3911,

		XTL::EmuQueueUserAPC,
			
		#ifdef _DEBUG_TRACE
		"EmuQueueUserAPC"
		#endif
	},
	// VirtualProtect (* unchanged since 4627 *)
    {
        (OOVPA*)&VirtualProtect_1_0_4627,
        XTL::EmuVirtualProtect,

        #ifdef _DEBUG_TRACE
        "VirtualProtect"
        #endif
    },
	// CreateSemaphore
	{
		(OOVPA*)&CreateSemaphoreA_1_0_4627,

		XTL::EmuCreateSemaphore,

		#ifdef _DEBUG_TRACE
		"EmuCreateSemaphoreA"
		#endif
	},
	// ReleaseSemaphore
	{
		(OOVPA*)&ReleaseSemaphore_1_0_4627,

		XTL::EmuReleaseSemaphore,

		#ifdef _DEBUG_TRACE
		"EmuReleaseSemaphore"
		#endif
	},
	// XMountAlternateTitleA
	{
		(OOVPA*)&XMountAlternateTitleA_1_0_4627,
		XTL::EmuXMountAlternateTitle,

		#ifdef _DEBUG_TRACE
		"XMountAlternateTitleA"
		#endif
	},
	// XMountAlternateTitleA
	{
		(OOVPA*)&XMountAlternateTitleA_1_0_4928,
		XTL::EmuXMountAlternateTitle,

		#ifdef _DEBUG_TRACE
		"XMountAlternateTitleA (4928)"
		#endif
	},
	// XUnmountAlternateTitleA
	{
		(OOVPA*)&XUnmountAlternateTitleA_1_0_4627,
	    XTL::EmuXUnmountAlternateTitle,

		#ifdef _DEBUG_TRACE
		"XUnmountAlternateTitleA"
		#endif
	},
	// GetFileAttributesA (* unchanged since 4134 *)
    {
        (OOVPA*)&GetFileAttributesA_1_0_4134,
        XTL::EmuGetFileAttributesA,

        #ifdef _DEBUG_TRACE
        "EmuGetFileAttributesA"
        #endif
    },
	// XGetFileCacheSize
    {
        (OOVPA*)&XGetFileCacheSize_1_0_4627,
        XTL::EmuXGetFileCacheSize,

        #ifdef _DEBUG_TRACE
        "XGetFileCacheSize"
        #endif
	},
	// XInputGetDeviceDescription
	{
        (OOVPA*)&XInputGetDeviceDescription_1_0_4831,
        XTL::EmuXInputGetCapabilities,

        #ifdef _DEBUG_TRACE
        "EmuXInputGetCapabilities_4831" // <- Cheap, I know..
        #endif
	},
	// JvsEEPROM_Read_1_0_5028
	{
		(OOVPA*)&JvsEEPROM_Read_1_0_5028, 
			
		XTL::EmuJvsEEPROM_Read,

        #ifdef _DEBUG_TRACE
		"EmuJvsEEPROM_Read"
        #endif
	},
	// JvsBACKUP_Read_1_0_5028
	{
		(OOVPA*)&JvsBACKUP_Read_1_0_5028, 
			
		XTL::EmuJvsBACKUP_Read,

        #ifdef _DEBUG_TRACE
		"EmuJvsBACKUP_Read"
        #endif
	},
	// JvsScFirmwareDownload_1_0_5028
	{
		(OOVPA*)&JvsScFirmwareDownload_1_0_5028,  
			
		XTL::EmuJvsScFirmwareDownload,

        #ifdef _DEBUG_TRACE
		"EmuJvsScFirmwareDownload"
        #endif
	},
	// JvsEEPROM_Write_1_0_5028
	{
		(OOVPA*)&JvsEEPROM_Write_1_0_5028, 
			
		XTL::EmuJvsEEPROM_Write,

        #ifdef _DEBUG_TRACE
		"EmuJvsEEPROM_Write"
        #endif
	},
	// JvsBACKUP_Write_1_0_5028
	{
		(OOVPA*)&JvsBACKUP_Write_1_0_5028, 
			
		XTL::EmuJvsBACKUP_Write,

        #ifdef _DEBUG_TRACE
		"EmuJvsBACKUP_Write"
        #endif
	},
	// JvsFirmwareUpload_1_0_5028
	{
		(OOVPA*)&JvsFirmwareUpload_1_0_5028,  
			
		XTL::EmuJvsFirmwareUpload,

        #ifdef _DEBUG_TRACE
		"EmuJvsFirmwareUpload"
        #endif
	},
	// JvsScFirmwareUpload_1_0_5028
	{
		(OOVPA*)&JvsScFirmwareUpload_1_0_5028,  
			
		XTL::EmuJvsScFirmwareUpload,

        #ifdef _DEBUG_TRACE
		"EmuJvsScFirmwareUpload"
        #endif
	},
	// JvsFirmwareDownload_1_0_5028
	{
		(OOVPA*)&JvsFirmwareDownload_1_0_5028,  
			
		XTL::EmuJvsFirmwareDownload,

        #ifdef _DEBUG_TRACE
		"EmuJvsFirmwareDownload"
        #endif
	},
	// JvsRTC_Read_1_0_5028
	{
		(OOVPA*)&JvsRTC_Read_1_0_5028, 
			
		XTL::EmuJvsRTC_Read,

        #ifdef _DEBUG_TRACE
		"EmuJvsRTC_Read"
        #endif
	},
	// JvsNodeSendPacket_1_0_5028
	{
		(OOVPA*)&JvsNodeSendPacket_1_0_5028,  
			
		XTL::EmuJvsNodeSendPacket,

        #ifdef _DEBUG_TRACE
		"EmuJvsNodeSendPacket"
        #endif
	},
	// JvsNodeReceivePacket_1_0_5028
	{
		(OOVPA*)&JvsNodeReceivePacket_1_0_5028,  
			
		XTL::EmuJvsNodeReceivePacket,

        #ifdef _DEBUG_TRACE
		"EmuJvsNodeReceivePacket"
        #endif
	},
	// JvsUnknown1_1_0_5028
	{
		(OOVPA*)&JvsUnknown1_1_0_5028, 
			
		XTL::EmuJVS_SendCommand,

        #ifdef _DEBUG_TRACE
		"EmuJVS_SendCommand"
        #endif
	},
	// JvsUnknown2_1_0_5028
	{
		(OOVPA*)&JvsUnknown2_1_0_5028, 0,

        #ifdef _DEBUG_TRACE
		"EmuJvsUnknown2 (XREF)"
        #endif
	},
	// JvsUnknown3_1_0_5028
	{
		(OOVPA*)&JvsUnknown3_1_0_5028, 0,

        #ifdef _DEBUG_TRACE
		"EmuJvsUnknown3(XREF)"
        #endif
	},
	// WaitForSingleObjectEx
	/*{
        (OOVPA*)&WaitForSingleObjectEx_1_0_4627,
        XTL::EmuWaitForSingleObjectEx,

        #ifdef _DEBUG_TRACE
		"EmuWaitForSingleObjectEx (Test)"
        #endif
	},*/
	// MoveFileA
	/*{
		(OOVPA*)&MoveFileA_1_0_4627,
		XTL::EmuMoveFileA,

		#ifdef _DEBUG_TRACE
		"MoveFileA"
		#endif
	},*/
};

// ******************************************************************
// * XAPI_1_0_4627_SIZE
// ******************************************************************
uint32 XAPI_1_0_4627_SIZE = sizeof(XAPI_1_0_4627);
