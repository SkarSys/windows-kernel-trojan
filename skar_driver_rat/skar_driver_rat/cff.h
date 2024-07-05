#pragma once
#include "includes.h"
// goofy shit, read in main to understand.
void _sub37B47A2F98347()
{
	int x011FB54A = 38;
	int x0FF5414B1114A = 38;

	int x0F114B4FF1A = 38;

	int x0F41FBF111F4A = 38;

}

void _sub37B47A2FF98347()
{
	int fbbfuehujefh = 0;

}
void _sub37BA47A2F98347()
{
	int fbbfuehujefh = 0;

}
void _sub37B47AA2F98347()
{
	int fbbfuehujefh = 0;

}
void _subA3F7B47A2F98347()
{
	int fbbfuehujefh = 0;

}
void _sub37fB47AA2F98347()
{
	int fbbfuehujefh = 0;

}
void _sub37B47A2F9834A7()
{
	int fbbfuehujefh = 0;

}



// Assuming n is a constant or pre-defined variable
int n = 10; // Example value for n

// Define the array and variables outside of the loop
int C[100][100];
int i = 0; // Initialize i
int j = 0; // Initialize j
int sum = 0; // Initialize sum
int __st__ = 1;


//NTSTATUS h8fh348()
//{
//    while (__st__) {
//        if ((__st__ == 1)) {
//            i = 0;
//            j = 0;
//            sum = 0;
//            __st__ = 2;
//            continue;
//        }
//        if ((__st__ == 2)) {
//            if ((i <= n)) {
//                __st__ = 4;
//                continue;
//            }
//            __st__ = 3;
//            continue;
//        }
//        if ((__st__ == 3)) {
//            sum = ((sum + i) * 2) % 100;
//            __st__ = 12;
//            continue;
//        }
//        if ((__st__ == 4)) {
//            if ((j < i)) {
//                __st__ = 6;
//                continue;
//            }
//            __st__ = 5;
//            continue;
//        }
//        if ((__st__ == 5)) {
//            C[i][i] = sum + i;
//            __st__ = 9;
//            continue;
//        }
//        if ((__st__ == 6)) {
//            if ((j % 2 == 0)) {
//                __st__ = 8;
//                continue;
//            }
//            __st__ = 7;
//            continue;
//        }
//        if ((__st__ == 7)) {
//            C[i][j] = sum * (i - j);
//            __st__ = 8;
//            continue;
//        }
//        if ((__st__ == 8)) {
//            j++;
//            sum += j;
//            if (j < i) {
//                __st__ = 6;
//            }
//            else {
//                __st__ = 4;
//            }
//            continue;
//        }
//        if ((__st__ == 9)) {
//            if (sum % 2 == 0) {
//                C[i][i] += sum / (i + 1);
//            }
//            else {
//                C[i][i] -= sum / (i + 1);
//            }
//            __st__ = 10;
//            continue;
//        }
//        if ((__st__ == 10)) {
//            i++;
//            sum += i;
//            if (i <= n) {
//                __st__ = 2;
//            }
//            else {
//                __st__ = 11;
//            }
//            continue;
//        }
//        if ((__st__ == 11)) {
//            C[n][n] = sum * (i + j);
//            __st__ = 3;
//            continue;
//        }
//        if ((__st__ == 12)) {
//            C[i][j] = sum * (i + j);
//            __st__ = 13;
//            continue;
//        }
//        if ((__st__ == 13)) {
//            __st__ = 0;
//            continue;
//        }
//    }
//
//    return STATUS_SUCCESS;
//}