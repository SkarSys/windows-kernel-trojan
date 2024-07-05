#include <ntifs.h>
#include <windef.h>
#include <ntimage.h>
#include "shared.h"
#include "utils.h"
#include "log.h"
/**
 * \brief Get base address of kernel module
 * \param moduleName Name of the module (ex. storport.sys)
 * \return Address of the module or null pointer if failed
 */
PVOID Utils::GetModuleBase(const char* moduleName)
{
	PVOID address = nullptr;
	ULONG size = 0;
	
	auto status = ZwQuerySystemInformation(SystemModuleInformation, &size, 0, &size);
	if (status != STATUS_INFO_LENGTH_MISMATCH)
		return nullptr;

	auto* moduleList = static_cast<PSYSTEM_MODULE_INFORMATION>(ExAllocatePoolWithTag(NonPagedPool, size, POOL_TAG));
	if (!moduleList)
		return nullptr;

	status = ZwQuerySystemInformation(SystemModuleInformation, moduleList, size, nullptr);
	if (!NT_SUCCESS(status))
		goto end;

	for (auto i = 0; i < moduleList->ulModuleCount; i++)
	{
		auto module = moduleList->Modules[i];
		if (strstr(module.ImageName, moduleName))
		{
			address = module.Base;
			break;
		}
	}
	
end:
	ExFreePool(moduleList);
	return address;
}


/**
 * \brief Checks if buffer at the location of base parameter
 * matches pattern and mask
 * \param base Address to check
 * \param pattern Byte pattern to match
 * \param mask Mask containing unknown bytes
 * \return 
 */
bool Utils::CheckMask(const char* base, const char* pattern, const char* mask)
{
	for (; *mask; ++base, ++pattern, ++mask) 
	{
		if ('x' == *mask && *base != *pattern) 
		{
			return false;
		}
	}

	return true;
}

/**
 * \brief Find byte pattern in given buffer
 * \param base Address to start searching in
 * \param length Maximum length
 * \param pattern Byte pattern to match
 * \param mask Mask containing unknown bytes
 * \return Pointer to matching memory
 */
PVOID Utils::FindPattern(PVOID base, int length, const char* pattern, const char* mask)
{
	length -= static_cast<int>(strlen(mask));
	for (auto i = 0; i <= length; ++i) 
	{
		const auto* data = static_cast<char*>(base);
		const auto* address = &data[i];
		if (CheckMask(address, pattern, mask))
			return PVOID(address);
	}

	return nullptr;
}

/**
 * \brief Find byte pattern in given module/image ".text" and "PAGE" sections
 * \param base Base address of the kernel module
 * \param pattern Byte pattern to match
 * \param mask Mask containing unknown bytes
 * \return Pointer to matching memory
 */
PVOID Utils::FindPatternImage(PVOID base, const char* pattern, const char* mask)
{
	PVOID match = nullptr;

	auto* headers = reinterpret_cast<PIMAGE_NT_HEADERS>(static_cast<char*>(base) + static_cast<PIMAGE_DOS_HEADER>(base)->e_lfanew);
	auto* sections = IMAGE_FIRST_SECTION(headers);
	
	for (auto i = 0; i < headers->FileHeader.NumberOfSections; ++i) 
	{
		auto* section = &sections[i];
		if ('EGAP' == *reinterpret_cast<PINT>(section->Name) || memcmp(section->Name, ".text", 5) == 0) 
		{
			match = FindPattern(static_cast<char*>(base) + section->VirtualAddress, section->Misc.VirtualSize, pattern, mask);
			if (match) 
				break;
		}
	}

	return match;
}


void Utils::RandomText(char* text, const int length)
{

	if (!text)
		return;

	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	auto seed = KeQueryTimeIncrement();
	int serialLength = length; // Variable to keep track of the actual length of the serial number
	int counter = 0; // Counter for underscores inserted

	for (auto n = 0; n < serialLength; n++)
	{
		auto key = RtlRandomEx(&seed) % static_cast<int>(sizeof(alphanum) - 1);
		text[n] = alphanum[key];

		// Insert underscore after every group of four characters
		if ((n + 1) % 5 == 0 && n != serialLength - 1)
		{
			text[n + 1] = '_';
			counter++;
			n++;
			serialLength++; // Increase the length due to underscore insertion
		}
	}

	text[serialLength] = '\0'; // Terminate the string
}
