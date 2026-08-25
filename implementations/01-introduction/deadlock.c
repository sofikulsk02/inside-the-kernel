#include <stdio.h>
#include <windows.h>

CRITICAL_SECTION lock1;
CRITICAL_SECTION lock2;

DWORD WINAPI thread1_func(LPVOID arg) {
    EnterCriticalSection(&lock1);
    printf("Thread 1: holding lock1, waiting for lock2...\n");
    Sleep(1000);
    EnterCriticalSection(&lock2);
    printf("Thread 1: acquired lock2\n");
    LeaveCriticalSection(&lock2);
    LeaveCriticalSection(&lock1);
    return 0;
}

DWORD WINAPI thread2_func(LPVOID arg) {
    EnterCriticalSection(&lock2);
    printf("Thread 2: holding lock2, waiting for lock1...\n");
    Sleep(1000);
    EnterCriticalSection(&lock1);
    printf("Thread 2: acquired lock1\n");
    LeaveCriticalSection(&lock1);
    LeaveCriticalSection(&lock2);
    return 0;
}

int main(void) {
    InitializeCriticalSection(&lock1);
    InitializeCriticalSection(&lock2);

    HANDLE t1 = CreateThread(NULL, 0, thread1_func, NULL, 0, NULL);
    HANDLE t2 = CreateThread(NULL, 0, thread2_func, NULL, 0, NULL);

    WaitForSingleObject(t1, INFINITE);
    WaitForSingleObject(t2, INFINITE);

    CloseHandle(t1);
    CloseHandle(t2);
    DeleteCriticalSection(&lock1);
    DeleteCriticalSection(&lock2);
    return 0;
}
