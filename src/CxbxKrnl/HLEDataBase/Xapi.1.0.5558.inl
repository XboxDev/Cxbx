// ******************************************************************
// *
// *    .,-:::::    .,::      .::::::::.    .,::      .:
// *  ,;;;'````'    `;;;,  .,;;  ;;;'';;'   `;;;,  .,;; 
// *  [[[             '[[,,[['   [[[__[[\.    '[[,,[['  
// *  $$$              Y$$$P     $$""""Y$$     Y$$$P    
// *  `88bo,__,o,    oP"``"Yo,  _88o,,od8P   oP"``"Yo,  
// *    "YUMMMMMP",m"       "Mm,""YUMMMP" ,m"       "Mm,
// *
// *   Cxbx->Win32->CxbxKrnl->Xapi.1.0.5558.cpp
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

// ******************************************************************
// * XapiApplyKernelPatches
// ******************************************************************
SOOVPA<7> XapiApplyKernelPatches_1_0_5558 = 
{
    0,  // Large == 0
    7,  // Count == 7

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x17, 0x81 },
        { 0x30, 0x81 },
        { 0x49, 0x05 },
        { 0x62, 0x1B },
        { 0x7B, 0x85 },
        { 0x96, 0x6A },
        { 0xAD, 0x5F },
    }
};

// ******************************************************************
// * RtlCreateHeap
// ******************************************************************
SOOVPA<8> RtlCreateHeap_1_0_5558 = 
{
    0,  // Large == 0
    8,  // Count == 8

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x1E, 0x45 },
        { 0x3E, 0xFF },
        { 0x5E, 0x8C },
        { 0x7E, 0x75 },
        { 0xA1, 0x89 },
        { 0xBE, 0xC7 },
        { 0xDE, 0x00 },
        { 0xFE, 0x89 },
    }
};

// ******************************************************************
// * RtlAllocateHeap
// ******************************************************************
SOOVPA<8> RtlAllocateHeap_1_0_5558 = 
{
    0,  // Large == 0
    8,  // Count == 8

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x1E, 0x8B },
        { 0x3E, 0x7D },
        { 0x5E, 0x00 },
        { 0x7E, 0x45 },
        { 0x9E, 0xCF },
        { 0xBE, 0x8D },
        { 0xDE, 0x45 },
        { 0xFE, 0x8B },
    }
};

// ******************************************************************
// * RtlSizeHeap
// ******************************************************************
SOOVPA<8> RtlSizeHeap_1_0_5558 = 
{
    0,  // Large == 0
    8,  // Count == 8

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x04, 0x8A },
        { 0x0A, 0x05 },
        { 0x10, 0xA8 },
        { 0x16, 0x51 },
        { 0x1C, 0xC2 },
        { 0x22, 0xF0 },
        { 0x28, 0xE0 },
        { 0x2E, 0x00 },
    }
};

// ******************************************************************
// * XInitDevices
// ******************************************************************
// * NOTE: We are actually intercepting USBD_Init, because
// *       XInitDevices Simply redirects to that function
// ******************************************************************
SOOVPA<7> XInitDevices_1_0_5558 =
{
    0,  // Large == 0
    7,  // Count == 7

    -1, // XRef Not Saved
    0,  // XRef Not Used

    {
        { 0x0E, 0x75 },
        { 0x20, 0xBE },
        { 0x2E, 0xC0 },
        { 0x3E, 0xEC },
        { 0x50, 0x0F },
        { 0x5F, 0xE8 },
        { 0x70, 0x5F },
    }
};

// ******************************************************************
// * XInputGetCapabilities
// ******************************************************************
SOOVPA<8> XInputGetCapabilities_1_0_5558 = 
{
    0,  // Large == 0
    8,  // Count == 8

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x1D, 0x85 },
        { 0x3C, 0x8A },
        { 0x5B, 0x00 },
        { 0x7A, 0x45 },
        { 0x99, 0xD4 },
        { 0xB8, 0x02 },
        { 0xD7, 0x8D },
        { 0xF6, 0x46 },
    }
};

// ******************************************************************
// * XInputGetState
// ******************************************************************
SOOVPA<7> XInputGetState_1_0_5558 = 
{
    0,  // Large == 0
    7,  // Count == 7

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x0D, 0x0C },
        { 0x1C, 0x5E },
        { 0x2B, 0xBB },
        { 0x3A, 0x80 },
        { 0x49, 0x08 },
        { 0x58, 0xF3 },
        { 0x67, 0x15 },
    }
};

// ******************************************************************
// * XapiInitProcess
// ******************************************************************
SOOVPA<8> XapiInitProcess_1_0_5558 = 
{
    0,  // Large == 0
    8,  // Count == 8

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x22, 0x6A },
        { 0x3E, 0x01 },
        { 0x5E, 0x7D },
        { 0x7E, 0x8B },
        { 0x9F, 0x68 },
        { 0xBE, 0x01 },
        { 0xDE, 0x6A },
        { 0xFE, 0x02 },
    }
};

// ******************************************************************
// * XapiInitProcess
// ******************************************************************
SOOVPA<8> XapiInitProcess_1_0_5659 = 
{
    0,  // Large == 0
    8,  // Count == 8

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x22, 0x6A },
        { 0x3E, 0x01 },
        { 0x5E, 0xEB },
        { 0x7E, 0x8B },
        { 0x9F, 0x68 },
        { 0xBE, 0x01 },
        { 0xDE, 0x6A },
        { 0xFE, 0x02 },
    }
};

// ******************************************************************
// * XGetDeviceChanges
// ******************************************************************
SOOVPA<7> XGetDeviceChanges_1_0_5558 = 
{
    0,  // Large == 0
    7,  // Count == 7

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x0C, 0x75 },
        { 0x1A, 0x53 },
        { 0x28, 0xF7 },
        { 0x36, 0x56 },
        { 0x44, 0x89 },
        { 0x52, 0xC8 },
        { 0x60, 0x5F },
    }
};

// ******************************************************************
// * XInputSetState
// ******************************************************************
SOOVPA<7> XInputSetState_1_0_5558 = 
{
    0,  // Large == 0
    7,  // Count == 7

    -1, // Xref Not Saved
    0,  // Xref Not Used

    {
        { 0x05, 0x81 },
        { 0x0C, 0xF6 },
        { 0x13, 0x57 },
        { 0x1A, 0x08 },
        { 0x21, 0x8B },
        { 0x28, 0x88 },
        { 0x30, 0xC2 },
    }
};

// ******************************************************************
// * XAPI_1_0_5558
// ******************************************************************
OOVPATable XAPI_1_0_5558[] =
{
    // XapiApplyKernelPatches_1_0_5558
    {
        (OOVPA*)&XapiApplyKernelPatches_1_0_5558,

        XTL::EmuXapiApplyKernelPatches,

        #ifdef _DEBUG_TRACE
        "EmuXapiApplyKernelPatches"
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
    // RtlCreateHeap
    {
        (OOVPA*)&RtlCreateHeap_1_0_5558,

        XTL::EmuRtlCreateHeap,

        #ifdef _DEBUG_TRACE
        "EmuRtlCreateHeap"
        #endif
    },
    // RtlAllocateHeap
    {
        (OOVPA*)&RtlAllocateHeap_1_0_5558,

        XTL::EmuRtlAllocateHeap,

        #ifdef _DEBUG_TRACE
        "EmuRtlAllocateHeap"
        #endif
    },
    // RtlFreeHeap (* unchanged since 4627 *)
    {
        (OOVPA*)&RtlFreeHeap_1_0_4627,

        XTL::EmuRtlFreeHeap,

        #ifdef _DEBUG_TRACE
        "EmuRtlFreeHeap"
        #endif
    },
    // RtlReAllocateHeap (* unchanged since 4627 *)
    {
        (OOVPA*)&RtlReAllocateHeap_1_0_4627,

        XTL::EmuRtlReAllocateHeap,

        #ifdef _DEBUG_TRACE
        "EmuRtlReAllocateHeap"
        #endif
    },
    // RtlSizeHeap
    {
        (OOVPA*)&RtlSizeHeap_1_0_5558,

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
    // XInitDevices
    {
        (OOVPA*)&XInitDevices_1_0_5558,

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
    // XGetDeviceChanges
    {
        (OOVPA*)&XGetDeviceChanges_1_0_5558,

        XTL::EmuXGetDeviceChanges,

        #ifdef _DEBUG_TRACE
        "EmuXGetDeviceChanges"
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
    // XInputGetCapabilities
    {
        (OOVPA*)&XInputGetCapabilities_1_0_5558,

        XTL::EmuXInputGetCapabilities,

        #ifdef _DEBUG_TRACE
        "EmuXInputGetCapabilities"
        #endif
    },
    // XInputGetState
    {
        (OOVPA*)&XInputGetState_1_0_5558,

        XTL::EmuXInputGetState,

        #ifdef _DEBUG_TRACE
        "EmuXInputGetState"
        #endif
    },
    // XInputSetState
    {
        (OOVPA*)&XInputSetState_1_0_5558,

        XTL::EmuXInputSetState,

        #ifdef _DEBUG_TRACE
        "EmuXInputSetState"
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
    // XapiInitProcess
    {
        (OOVPA*)&XapiInitProcess_1_0_5558,

        XTL::EmuXapiInitProcess,

        #ifdef _DEBUG_TRACE
        "EmuXapiInitProcess" 
        #endif
    },
    // XapiInitProcess
    {
        (OOVPA*)&XapiInitProcess_1_0_5659,

        XTL::EmuXapiInitProcess,

        #ifdef _DEBUG_TRACE
        "EmuXapiInitProcess" 
        #endif
    },
    // XapiBootToDash (* unchanged since 1.0.3911 *)
    {
        (OOVPA*)&XapiBootDash_1_0_3911,

        XTL::EmuXapiBootDash,

        #ifdef _DEBUG_TRACE
        "EmuXapiBootDash"
        #endif
    },
};

// ******************************************************************
// * XAPI_1_0_5558_SIZE
// ******************************************************************
uint32 XAPI_1_0_5558_SIZE = sizeof(XAPI_1_0_5558);
