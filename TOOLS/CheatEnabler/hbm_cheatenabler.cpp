// Original enabler by ZoID: http://forums.eidosgames.com/showthread.php?t=61298
// Improved, fixed for Steam by RDJ http://roguedarkjedi.com

// Allow XP access
#define _WIN32_WINNT _WIN32_WINNT_WINXP

#include <windows.h>
#include <string>
#include <iostream>
#pragma comment(lib, "User32.lib")

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
  if(IsWindowVisible(hwnd) != 0)
  {
    TCHAR WindowTitle[1024];
    if(GetWindowText(hwnd, WindowTitle, 1024) == 0)
      return true;

    if(strcmp(WindowTitle, "Hitman") == 0 || strcmp(WindowTitle, "Hitman Blood Money") == 0)
    {
      DWORD ProcessId = 0;
      GetWindowThreadProcessId(hwnd, &ProcessId);
      HANDLE ProcessHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessId);

      if(ProcessHandle != NULL)
        *((HANDLE*)lParam) = ProcessHandle;
    }
  }
  return true;
}

int main(void)
{
  // Again, laziness.
  const char *title = "HBM Cheat Enabler";
  SetConsoleTitle(title);
  
  // Credits because why the fuck not.
  std::cout << "Hitman Blood Money Cheat Menu enabler V1.12" << std::endl;
  std::cout << "Original by ZoID. Updated & Fixed by RDJ.\n\n" << std::endl;
  
  HANDLE ProcessHandle = NULL;
  // Retail versions use 0x8ACA89, steam uses 0x8ABA89
  void* g_bEnableCheats_Address;
  unsigned char	Byte;

  // Grab the process handle;
  EnumWindows(EnumWindowsProc, (LPARAM)&ProcessHandle);

  if(ProcessHandle == NULL)
  {
    std::cout << "ERROR: Could not find the Hitman Blood Money process.\nYou must run the game first!" << std::endl;
    std::cin.get();
    return 1;
  }
  
  /* Just to let the original work as well and make a super lazy selector :D */
  char versionSelect = '1';
  std::cout << "Which version of Hitman Blood Money do you have?\n1. Steam\n2. Original CD Retail\n" << std::endl;
  std::cin >> versionSelect;
  
  if(versionSelect == '1')
    g_bEnableCheats_Address = (void *)0x8ABA89;
  else
    g_bEnableCheats_Address = (void *)0x8ACA89;

  
  std::cout << "Version set.\n\nOnce you start gameplay, press the C key for the cheat console.\nRunning....\n\n" << std::endl;
  
  while(true)
  {
    // Check if process exists still
    if(ReadProcessMemory(ProcessHandle, g_bEnableCheats_Address, &Byte, 1, NULL) == 0)
    {
      std::cout << "ERROR: Could not read memory for game! Did you close the process?" << std::endl;
      std::cin.get();
      return 1;
    }

    if(Byte == 0)
    {
      std::cout << "EnableCheats is set to 0" << std::endl;
      Byte = 1;

      if(WriteProcessMemory(ProcessHandle, g_bEnableCheats_Address, &Byte, 1, NULL) == 0)
      {
        std::cout << "Failed to set EnableCheats to 1." << std::endl;
        std::cin.get();
        return 1;
      }
      std::cout << "Successfully set EnableCheats to 1." << std::endl;
    }

    Sleep(1000);
  }
  
  return 0;
}
