#include "stdafx.h"
#include "stdio.h"
#include <windows.h>
#include "..\includes\injector\injector.hpp"
#include <cstdint>
#include "..\includes\IniReader.h"
#include <d3d9.h>

float TempHUDSize = 1.0f;
float TempHUDPos = 1.0f;
float HUDScale;
float HUDSize;
float HUDPos;
float FMVScale;

DWORD HUDSizeCodeCaveExit1 = 0x71C776;
DWORD HUDSizeCodeCaveExit2 = 0x71C78D;
DWORD HUDSizeCodeCaveExit3 = 0x71C93C;
DWORD MinimapRouteSizeCodeCaveExit = 0x742ED4;
DWORD RVMSizeCodeCaveExit = 0x750D0B;
DWORD PIPSizeCodeCaveExit = 0x750DFF;
DWORD RVMPIPPosCodeCaveExit = 0x750BB1;
DWORD FMVSizeCodeCaveExit = 0x598ED9;
DWORD sub_46EFE0 = 0x46EFE0;
DWORD sub_750B30 = 0x750B30;
DWORD sub_584700 = 0x584700;

void __declspec(naked) HUDSizeCodeCave()
{
	__asm {
		cmp dword ptr ds : [esp], 0x70EFC4
		je HUDSizeCodeCaveScale
		cmp dword ptr ds : [esp], 0x721FFF
		je HUDSizeCodeCaveScale
		cmp dword ptr ds : [esp], 0x585478
		je HUDSizeCodeCaveScale
		push ebp
		mov ebp, esp
		and esp, 0xFFFFFFF0
		jmp HUDSizeCodeCaveExit1
	
	HUDSizeCodeCaveScale:
		///////////////////////////////
		fld dword ptr ds : [TempHUDSize]
		fmul dword ptr ds : [HUDScale]
		fstp dword ptr ds : [HUDSize]
		fld dword ptr ds : [TempHUDPos]
		fsub dword ptr ds : [HUDSize]
		fstp dword ptr ds : [HUDPos]
		///////////////////////////////
		push ebp
		mov ebp, esp
		and esp, 0xFFFFFFF0
		sub esp, 0xD4
		mov eax, dword ptr ds : [0xAB0AEC]
		mov ecx, dword ptr ds : [ebp + 0x0C]
		push ebx
		xor bl, bl
		test eax, eax
		push esi
		mov esi, dword ptr ds : [ebp + 0x08]

	HUDSizeCodeCaveFullscreenCheck1:
		// Checks for Black Overlay
		cmp dword ptr ds : [esi], 0xC3892AAB
		jne HUDSizeCodeCaveFullscreenCheck2
		cmp dword ptr ds : [esi + 0x04], 0xC1900000
		jne HUDSizeCodeCaveFullscreenCheck2
		cmp dword ptr ds : [esi + 0x10], 0x448CB555
		jne HUDSizeCodeCaveFullscreenCheck2
		cmp dword ptr ds : [esi + 0x14], 0xC1900000
		jne HUDSizeCodeCaveFullscreenCheck2
		cmp dword ptr ds : [esi + 0x20], 0x448CB555
		jne HUDSizeCodeCaveFullscreenCheck2
		cmp dword ptr ds : [esi + 0x24], 0x43F70000
		jne HUDSizeCodeCaveFullscreenCheck2
		cmp dword ptr ds : [esi + 0x30], 0xC3892AAB
		jne HUDSizeCodeCaveFullscreenCheck2
		cmp dword ptr ds : [esi + 0x34], 0x43F70000
		jne HUDSizeCodeCaveFullscreenCheck2
		test eax, eax
		jmp HUDSizeCodeCaveExit2

	HUDSizeCodeCaveFullscreenCheck2:
		// Checks for Black Overlay
		cmp dword ptr ds : [esi], 0xC388AAAB
		jne HUDSizeCodeCaveFullscreenCheck3
		cmp dword ptr ds : [esi + 0x04], 0xC1A00000
		jne HUDSizeCodeCaveFullscreenCheck3
		cmp dword ptr ds : [esi + 0x10], 0x448CD555
		jne HUDSizeCodeCaveFullscreenCheck3
		cmp dword ptr ds : [esi + 0x14], 0xC1A00000
		jne HUDSizeCodeCaveFullscreenCheck3
		cmp dword ptr ds : [esi + 0x20], 0x448CD555
		jne HUDSizeCodeCaveFullscreenCheck3
		cmp dword ptr ds : [esi + 0x24], 0x43FA0000
		jne HUDSizeCodeCaveFullscreenCheck3
		cmp dword ptr ds : [esi + 0x30], 0xC388AAAB
		jne HUDSizeCodeCaveFullscreenCheck3
		cmp dword ptr ds : [esi + 0x34], 0x43FA0000
		jne HUDSizeCodeCaveFullscreenCheck3
		test eax, eax
		jmp HUDSizeCodeCaveExit2

	HUDSizeCodeCaveFullscreenCheck3:
		// Checks for Black Overlay
		cmp dword ptr ds : [esi] , 0xC32D5556
		jne HUDSizeCodeCaveFullscreenCheck4
		cmp dword ptr ds : [esi + 0x04], 0xC2700000
		jne HUDSizeCodeCaveFullscreenCheck4
		cmp dword ptr ds : [esi + 0x10], 0x44805555
		jne HUDSizeCodeCaveFullscreenCheck4
		cmp dword ptr ds : [esi + 0x14], 0xC2700000
		jne HUDSizeCodeCaveFullscreenCheck4
		cmp dword ptr ds : [esi + 0x20], 0x44805555
		jne HUDSizeCodeCaveFullscreenCheck4
		cmp dword ptr ds : [esi + 0x24], 0x44070000
		jne HUDSizeCodeCaveFullscreenCheck4
		cmp dword ptr ds : [esi + 0x30], 0xC32D5556
		jne HUDSizeCodeCaveFullscreenCheck4
		cmp dword ptr ds : [esi + 0x34], 0x44070000
		jne HUDSizeCodeCaveFullscreenCheck4
		test eax, eax
		jmp HUDSizeCodeCaveExit2

	HUDSizeCodeCaveFullscreenCheck4:
		// Checks for Green Overlay
		cmp dword ptr ds : [esi], 0xC1BAAAB0
		jne HUDSizeCodeCaveFullscreenCheck5
		cmp dword ptr ds : [esi + 0x04], 0xC1A00000
		jne HUDSizeCodeCaveFullscreenCheck5
		cmp dword ptr ds : [esi + 0x10], 0x445B2AAA
		jne HUDSizeCodeCaveFullscreenCheck5
		cmp dword ptr ds : [esi + 0x14], 0xC1A00000
		jne HUDSizeCodeCaveFullscreenCheck5
		cmp dword ptr ds : [esi + 0x20], 0x445B2AAA
		jne HUDSizeCodeCaveFullscreenCheck5
		cmp dword ptr ds : [esi + 0x24], 0x43FA0000
		jne HUDSizeCodeCaveFullscreenCheck5
		cmp dword ptr ds : [esi + 0x30], 0xC1BAAAB0
		jne HUDSizeCodeCaveFullscreenCheck5
		cmp dword ptr ds : [esi + 0x34], 0x43FA0000
		jne HUDSizeCodeCaveFullscreenCheck4
		test eax, eax
		jmp HUDSizeCodeCaveExit2

	HUDSizeCodeCaveFullscreenCheck5:
		// Checks for Green Overlay
		cmp dword ptr ds : [esi], 0xC1C2AAB0
		jne HUDSizeCodeCaveNotFullscreen
		cmp dword ptr ds : [esi + 0x04], 0xC1A80000
		jne HUDSizeCodeCaveNotFullscreen
		cmp dword ptr ds : [esi + 0x10], 0x445B6AAA
		jne HUDSizeCodeCaveNotFullscreen
		cmp dword ptr ds : [esi + 0x14], 0xC1A80000
		jne HUDSizeCodeCaveNotFullscreen
		cmp dword ptr ds : [esi + 0x20], 0x445B6AAA
		jne HUDSizeCodeCaveNotFullscreen
		cmp dword ptr ds : [esi + 0x24], 0x43FA8000
		jne HUDSizeCodeCaveNotFullscreen
		cmp dword ptr ds : [esi + 0x30], 0xC1C2AAB0
		jne HUDSizeCodeCaveNotFullscreen
		cmp dword ptr ds : [esi + 0x34], 0x43FA8000
		jne HUDSizeCodeCaveNotFullscreen
		test eax, eax
		jmp HUDSizeCodeCaveExit2

	HUDSizeCodeCaveNotFullscreen:
		push edi
		mov [esp + 0x1F], bl
		mov [esp + 0x1E], bl
		je HUDSizeCodeCaveScaleConditional1
		test ecx, ecx
		je HUDSizeCodeCaveScaleConditional2
		mov eax, dword ptr ds : [ecx + 0x0C]
		cmp eax, 0x40CDC515
		je HUDSizeCodeCaveScaleConditional3
		cmp eax, 0x1149C7DA
		jne HUDSizeCodeCaveScaleConditional2
	
	HUDSizeCodeCaveScaleConditional3:
		mov bl, 0x01
		mov [esp + 0x1F], bl

	HUDSizeCodeCaveScaleConditional2:
		mov al, [esi + 0x91]
		cmp al, 0x72
		je HUDSizeCodeCaveScaleConditional4
		cmp al, 0x73
		jne HUDSizeCodeCaveScaleConditional1
	
	HUDSizeCodeCaveScaleConditional4:
		mov byte ptr [esp + 0x1E], 0x01

	HUDSizeCodeCaveScaleConditional1:
		fld dword ptr ds : [esi]
		mov al, [esi + 0x90]
		and al, 0x02
		fmul dword ptr ds : [0x9E8F8C] // Width 1
		fmul dword ptr ds : [HUDSize] // Size
		fadd dword ptr ds : [HUDPos] // Pos
		fsub dword ptr ds : [0x9C2478]
		fstp dword ptr ds : [esp + 0x20]
		fld dword ptr ds : [esi + 0x04]
		fmul dword ptr ds : [0x9E8F88] // Height 1
		fmul dword ptr ds : [HUDSize] // Size
		fadd dword ptr ds : [HUDPos] // Pos
		fsub dword ptr ds : [0x9C2478]
		fchs
		fstp dword ptr ds : [esp + 0x24]
		je HUDSizeCodeCaveScaleConditional5
		mov edx, dword ptr ds : [esi + 0x08]
		mov dword ptr ds : [esp + 0x28], edx
		jmp HUDSizeCodeCaveScaleConditional6
	
	HUDSizeCodeCaveScaleConditional5:
		mov dword ptr ds : [esp + 0x28], 0x3F800000

	HUDSizeCodeCaveScaleConditional6:
		movzx edi, byte ptr [esi + 0x81]
		fld dword ptr ds : [esi + 0x10]
		fmul dword ptr ds : [0x9E8F8C] // Width 2
		fmul dword ptr ds : [HUDSize] // Size
		fadd dword ptr ds : [HUDPos] // Pos
		xor edx, edx
		mov dh, [esi + 0x83]
		fsub dword ptr ds : [0x9C2478]
		fstp dword ptr ds : [esp + 0x40]
		fld dword ptr ds : [esi + 0x14]
		fmul dword ptr ds : [0x9E8F88] // Height 2
		fmul dword ptr ds : [HUDSize] // Size
		fadd dword ptr ds : [HUDPos] // Pos
		mov dl, [esi + 0x80]
		fsub dword ptr ds : [0x9C2478]
		fchs
		fstp dword ptr ds : [esp + 0x44]
		shl edx, 0x08
		or edx, edi
		movzx edi, byte ptr [esi + 0x82]
		shl edx, 0x08
		or edx, edi
		test al, al
		mov dword ptr ds : [esp + 0x2C], edx
		mov edx, dword ptr ds : [esi + 0x40]
		mov dword ptr ds : [esp + 0x30], edx
		mov edx, dword ptr ds : [esi + 0x44]
		mov dword ptr ds : [esp + 0x34], edx
		mov edx, dword ptr ds : [esi + 0x60]
		mov dword ptr ds : [esp + 0x38], edx
		mov edx, dword ptr ds : [esi + 0x64]
		mov dword ptr ds : [esp + 0x3C], edx
		je HUDSizeCodeCaveScaleConditional7
		mov edx, dword ptr ds : [esi + 0x18]
		mov dword ptr ds : [esp + 0x48], edx
		jmp HUDSizeCodeCaveScaleConditional8
	
	HUDSizeCodeCaveScaleConditional7:
		mov dword ptr ds : [esp + 0x48], 0x3F800000

	HUDSizeCodeCaveScaleConditional8:
		movzx edi, byte ptr [esi + 0x85]
		fld dword ptr ds : [esi + 0x20]
		fmul dword ptr ds : [0x9E8F8C] // Width 3
		fmul dword ptr ds : [HUDSize] // Size
		fadd dword ptr ds : [HUDPos] // Pos
		xor edx, edx
		mov dh, [esi + 0x87]
		fsub dword ptr ds : [0x9C2478]
		fstp dword ptr ds : [esp + 0x60]
		fld dword ptr ds : [esi + 0x24]
		fmul dword ptr ds : [0x9E8F88] // Height 3
		fmul dword ptr ds : [HUDSize] // Size
		fadd dword ptr ds : [HUDPos] // Pos
		mov dl, [esi + 0x84]
		fsub dword ptr ds : [0x9C2478]
		fchs
		fstp dword ptr ds : [esp + 0x64]
		shl edx, 0x08
		or edx, edi
		movzx edi, byte ptr [esi + 0x86]
		shl edx, 0x08
		or edx, edi
		test al, al
		mov dword ptr ds : [esp + 0x4C], edx
		mov edx, dword ptr ds : [esi + 0x48]
		mov dword ptr ds : [esp + 0x50], edx
		mov edx, dword ptr ds : [esi + 0x4C]
		mov dword ptr ds : [esp + 0x54], edx
		mov edx, dword ptr ds : [esi + 0x68]
		mov dword ptr ds : [esp + 0x58], edx
		mov edx, dword ptr ds : [esi + 0x6C]
		mov dword ptr ds : [esp + 0x5C], edx
		je HUDSizeCodeCaveScaleConditional9
		mov edx, dword ptr ds : [esi + 28]
		mov dword ptr ds : [esp + 0x68], edx
		jmp HUDSizeCodeCaveScaleConditional10
	
	HUDSizeCodeCaveScaleConditional9:
		mov dword ptr ds : [esp + 0x68], 0x3F800000

	HUDSizeCodeCaveScaleConditional10:
		movzx edi, byte ptr [esi + 0x89]
		fld dword ptr ds : [esi + 0x30]
		fmul dword ptr ds : [0x9E8F8C] // Width 4
		fmul dword ptr ds : [HUDSize] // Size
		fadd dword ptr ds : [HUDPos] // Pos
		xor edx, edx
		mov dh, [esi + 0x8B]
		fsub dword ptr ds : [0x9C2478]
		fstp dword ptr ds : [esp + 0x80]
		fld dword ptr ds : [esi + 0x34]
		fmul dword ptr ds : [0x9E8F88] // Height 4
		fmul dword ptr ds : [HUDSize] // Size
		fadd dword ptr ds : [HUDPos] // Pos
		jmp HUDSizeCodeCaveExit3
	}
}

void __declspec(naked) MinimapRouteSizeCodeCave()
{
	__asm {
		call sub_46EFE0
		fld dword ptr ds : [esp + 0x48]
		fmul dword ptr ds : [0x9E8F8C] // Width
		fmul dword ptr ds : [HUDSize] // Size
		fadd dword ptr ds : [HUDPos] // Pos
		mov ecx, dword ptr ds : [esp + 0x2C]
		add esp, 0x18
		test bl, 0x01
		fsub dword ptr ds : [0x9C2478]
		fld dword ptr ds : [esp + 0x34]
		fmul dword ptr ds : [0x9E8F88] // Height
		fmul dword ptr ds : [HUDSize] // Size
		fadd dword ptr ds : [HUDPos] // Pos
		jmp MinimapRouteSizeCodeCaveExit
	}
}

void __declspec(naked) RVMSizeCodeCave()
{
	__asm {
		fld dword ptr ds : [esp + 0x10]
		fmul dword ptr ds : [HUDSize] // Height
		fstp dword ptr ds : [esp + 0x10]
		fld dword ptr ds : [esp + 0x0C]
		fmul dword ptr ds : [HUDSize] // Width
		fstp dword ptr ds : [esp + 0x0C]
		call sub_750B30
		jmp RVMSizeCodeCaveExit
	}
}

void __declspec(naked) PIPSizeCodeCave()
{
	__asm {
		fld dword ptr ds : [esp + 0x10]
		fmul dword ptr ds : [HUDSize] // Height
		fstp dword ptr ds : [esp + 0x10]
		fld dword ptr ds : [esp + 0x0C]
		fmul dword ptr ds : [HUDSize] // Width
		fstp dword ptr ds : [esp + 0x0C]
		call sub_750B30
		jmp PIPSizeCodeCaveExit
	}
}

void __declspec(naked) RVMPIPPosCodeCave()
{
	__asm {
		fsub dword ptr ds : [0x9C2478] // X Pos
		fmul dword ptr ds : [HUDSize]
		fstp dword ptr ds : [esp + 0x14]
		fld dword ptr ds : [esp + 0x18]
		mov eax, dword ptr ds : [esp + 0x14]
		fadd st(0), st(0)
		mov dword ptr ds : [esi], eax
		fsub dword ptr ds : [0x9C2478] // Y Pos
		fmul dword ptr ds : [HUDSize]
		jmp RVMPIPPosCodeCaveExit
	}
}

void __declspec(naked) FMVSizeCodeCave()
{
	__asm {
		fld dword ptr ds : [esp]
		fdiv dword ptr ds : [HUDSize] // Height 1
		fmul dword ptr ds : [FMVScale] // Scale
		fstp dword ptr ds : [esp]
		fld dword ptr ds : [esp + 0x04]
		fdiv dword ptr ds : [HUDSize] // Width 1
		fmul dword ptr ds : [FMVScale] // Scale
		fstp dword ptr ds : [esp + 0x04]
		fld dword ptr ds : [esp + 0x08]
		fdiv dword ptr ds : [HUDSize] // Width 2
		fmul dword ptr ds : [FMVScale] // Scale
		fstp dword ptr ds : [esp + 0x08]
		fld dword ptr ds : [esp + 0x0C]
		fdiv dword ptr ds : [HUDSize] // Height 2
		fmul dword ptr ds : [FMVScale] // Scale
		fstp dword ptr ds : [esp + 0x0C]
		call sub_584700
		jmp FMVSizeCodeCaveExit
	}
}

void Init()
{
	// Read values from .ini
	CIniReader iniReader("NFSCHUDResizer.ini");

	// General
	HUDScale = iniReader.ReadFloat("GENERAL", "HUDScale", 0.92f);
	FMVScale = iniReader.ReadFloat("GENERAL", "FMVScale", 1.0f);

	{
		// HUD Size
		injector::MakeJMP(0x71C770, HUDSizeCodeCave, true);
		// Minimap Route Size
		injector::MakeJMP(0x742EAB, MinimapRouteSizeCodeCave, true);
		// RVM Size
		injector::MakeJMP(0x750D06, RVMSizeCodeCave, true);
		// PIP Size
		injector::MakeJMP(0x750DFA, PIPSizeCodeCave, true);
		// RVM and PIP Position
		injector::MakeJMP(0x750B95, RVMPIPPosCodeCave, true);
		// FVM Size
		injector::MakeJMP(0x598ED4, FMVSizeCodeCave, true);
	}
}
	

BOOL APIENTRY DllMain(HMODULE /*hModule*/, DWORD reason, LPVOID /*lpReserved*/)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		uintptr_t base = (uintptr_t)GetModuleHandleA(NULL);
		IMAGE_DOS_HEADER* dos = (IMAGE_DOS_HEADER*)(base);
		IMAGE_NT_HEADERS* nt = (IMAGE_NT_HEADERS*)(base + dos->e_lfanew);

		if ((base + nt->OptionalHeader.AddressOfEntryPoint + (0x400000 - base)) == 0x87E926) // Check if .exe file is compatible - Thanks to thelink2012 and MWisBest
			Init();

		else
		{
			MessageBoxA(NULL, "This .exe is not supported.\nPlease use v1.4 English nfsc.exe (6,88 MB (7.217.152 bytes)).", "NFSC HUD Resizer", MB_ICONERROR);
			return FALSE;
		}
	}
	return TRUE;
	
}
