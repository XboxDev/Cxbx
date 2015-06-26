// ******************************************************************
// *
// *    .,-:::::    .,::      .::::::::.    .,::      .:
// *  ,;;;'````'    `;;;,  .,;;  ;;;'';;'   `;;;,  .,;;
// *  [[[             '[[,,[['   [[[__[[\.    '[[,,[['
// *  $$$              Y$$$P     $$""""Y$$     Y$$$P
// *  `88bo,__,o,    oP"``"Yo,  _88o,,od8P   oP"``"Yo,
// *    "YUMMMMMP",m"       "Mm,""YUMMMP" ,m"       "Mm,
// *
// *   Cxbx->Win32->CxbxKrnl->EmuXOnline.cpp
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

#include "Emu.h"
#include "EmuFS.h"

// ******************************************************************
// * prevent name collisions
// ******************************************************************
namespace NtDll
{
    #include "EmuNtDll.h"
};

#include "EmuXTL.h"

// ******************************************************************
// * func: EmuWSAStartup
// ******************************************************************
int WINAPI XTL::EmuWSAStartup
(
    WORD        wVersionRequested,
    WSADATA    *lpWSAData
)
{
    EmuSwapFS();   // Win2k/XP FS

    DbgPrintf("EmuXapi (0x%X): EmuWSAStartup\n"
           "(\n"
           "   wVersionRequested   : 0x%.08X\n"
           "   lpWSAData           : 0x%.08X\n"
           ");\n",
           GetCurrentThreadId(), wVersionRequested, lpWSAData);

    int ret = WSAStartup(wVersionRequested, lpWSAData);

    EmuSwapFS();   // XBox FS

    return ret;
}

// ******************************************************************
// * func: EmuXNetStartup
// ******************************************************************
INT WINAPI XTL::EmuXNetStartup
(
    const PVOID pDummy
)
{
    EmuSwapFS();   // Win2k/XP FS

    DbgPrintf("EmuXapi (0x%X): EmuXNetStartup\n"
           "(\n"
           "   pDummy              : 0x%.08X\n"
           ");\n",
           GetCurrentThreadId(), pDummy);

    EmuSwapFS();   // XBox FS

    // Fake Successfull...hehehe...sucker...hehehehehe
    return 0;
}

// ******************************************************************
// * func: EmuXNetGetEthernetLinkStatus
// ******************************************************************
DWORD WINAPI XTL::EmuXNetGetEthernetLinkStatus()
{
    EmuSwapFS();   // Win2k/XP FS

    DbgPrintf("EmuXapi (0x%X): EmuXNetGetEthernetLinkStatus();\n", GetCurrentThreadId());

    EmuSwapFS();   // XBox FS

    // for now, no ethernet connection is available
    return XNET_ETHERNET_LINK_ACTIVE | XNET_ETHERNET_LINK_100MBPS;
}

// ******************************************************************
// * func: EmuThis::Emusocket
// ******************************************************************
SOCKET XTL::EmuThis::Emusocket
(
    int   af,
    int   type,
    int   protocol
)
{
    EmuSwapFS();   // Win2k/XP FS

    DbgPrintf("EmuXapi (0x%X): EmuThis::Emusocket\n"
           "(\n"
           "   this                : 0x%.08X\n"
           "   af                  : 0x%.08X\n"
           "   type                : 0x%.08X\n"
           "   protocol            : 0x%.08X\n"
           ");\n",
           GetCurrentThreadId(), this, af, type, protocol);

    SOCKET ret = socket(af, type, protocol);

    EmuSwapFS();   // XBox FS

    return ret;
}

// ******************************************************************
// * func: EmuThis::Emubind
// ******************************************************************
int XTL::EmuThis::Emubind(SOCKET s, const struct sockaddr FAR *name, int namelen)
{
    EmuSwapFS();   // Win2k/XP FS

    DbgPrintf("EmuXapi (0x%X): EmuThis::Emubind\n"
           "(\n"
           "   this                : 0x%.08X\n"
           "   s                   : 0x%.08X\n"
           "   name                : 0x%.08X\n"
           "   namelen             : 0x%.08X\n"
           ");\n",
           GetCurrentThreadId(), this, s, name, namelen);

    // TODO: Host-To-Network order if necessary (probably not?)

    int ret = bind(s, name, namelen);

    EmuSwapFS();   // XBox FS

    return ret;
}

// ******************************************************************
// * func: EmuThis::Emulisten
// ******************************************************************
int XTL::EmuThis::Emulisten(SOCKET s, int backlog)
{
    EmuSwapFS();   // Win2k/XP FS

    DbgPrintf("EmuXapi (0x%X): EmuThis::Emulisten\n"
           "(\n"
           "   this                : 0x%.08X\n"
           "   s                   : 0x%.08X\n"
           "   listen              : 0x%.08X\n"
           ");\n",
           GetCurrentThreadId(), this, s, backlog);

    // TODO: Host-To-Network order if necessary (probably not?)

    int ret = listen(s, backlog);

    EmuSwapFS();   // XBox FS

    return ret;
}

// ******************************************************************
// * func: EmuThis::Emuioctlsocket
// ******************************************************************
int XTL::EmuThis::Emuioctlsocket(SOCKET s, long cmd, u_long FAR *argp)
{
    EmuSwapFS();   // Win2k/XP FS

    DbgPrintf("EmuXapi (0x%X): EmuThis::Emuioctlsocket\n"
           "(\n"
           "   this                : 0x%.08X\n"
           "   s                   : 0x%.08X\n"
           "   cmd                 : 0x%.08X\n"
           "   argp                : 0x%.08X\n"
           ");\n",
           GetCurrentThreadId(), this, s, cmd, argp);

    int ret = ioctlsocket(s, cmd, argp);

    EmuSwapFS();   // XBox FS

    return ret;
}

// ******************************************************************
// * func: EmuXOnlineLaunchNewImage
// ******************************************************************
HRESULT WINAPI XOnlineLaunchNewImage
(
    LPCSTR	lpImagePath,
    LPVOID	pLaunchData
)
{
	EmuSwapFS();	// Win2k/XP FS

	DbgPrintf("XOnline (0x%X): EmuXOnlineLaunchNewImage\n"
		"(\n"
		"   lpImagePath           : 0x%.08X (%s)\n"
		"   pLaunchData           : 0x%.08X\n"
		");\n",
		GetCurrentThreadId(), lpImagePath, lpImagePath, pLaunchData);

	// TODO: Launch another .xbe from Cxbx someday?

	EmuSwapFS();	// Xbox FS

	return E_FAIL;
}

// ******************************************************************
// * func: EmuXOnlineLogon
// ******************************************************************
HRESULT WINAPI XTL::EmuXOnlineLogon
(
    VOID*	pUsers,
    DWORD*	pdwServiceIDs,
    DWORD	dwServices,
    HANDLE	hEvent,
    HANDLE	pHandle
)
{
	EmuSwapFS();	// Win2k/XP FS

	DbgPrintf("XOnline (0x%X): EmuXOnlineLogon\n"
		"(\n"
		"   pUsers                : 0x%.08X\n"
		"   pdwServiceIDs         : 0x%.08X\n"
		"   dwServices            : 0x%.08X\n"
		"   hEvent                : 0x%.08X\n"
		"   pHandle               : 0x%.08X\n"
		");\n",
		GetCurrentThreadId(), pUsers, pdwServiceIDs, dwServices, hEvent, pHandle);

	// TODO: What will it take to log on to Xbox Live?

	EmuSwapFS();	// Xbox FS

	return HRESULT(0x80151000L);	// XONLINE_E_LOGON_NO_NETWORK_CONNECTION
}