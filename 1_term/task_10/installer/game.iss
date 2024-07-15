;  
#define   Name       "ZombieVsPlants"
;  
#define   Version    "1.0.0"
; -
#define   Publisher  "Veronika Kurtmullaeva"
;   
#define   URL        "http://www.vk.com/verosh_ka"
;   
#define   ExeName    "ZombieVsPlants.exe"

;------------------------------------------------------------------------------
;    
;------------------------------------------------------------------------------
[Setup]

;   , 
;  Tools -> Generate GUID
AppId={{EB5FD14E-63E7-426C-9ADB-A4007ED8EBEA}

;  ,   
AppName={#Name}
AppVersion={#Version}
AppPublisher={#Publisher}
AppPublisherURL={#URL}
AppSupportURL={#URL}
AppUpdatesURL={#URL}

;   -
DefaultDirName={pf}\{#Name}
;     ""
DefaultGroupName={#Name}

; ,     setup    
OutputDir=C:\Git\additionals\task_10\installer\output
OutputBaseFileName=ZombieVsPlants

;  
SetupIconFile=C:\Git\additionals\task_10\img\icon32.ico

;  
Compression=lzma
SolidCompression=yes

;------------------------------------------------------------------------------
;       
;------------------------------------------------------------------------------
[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"; LicenseFile: "License_ENG.txt"
Name: "russian"; MessagesFile: "compiler:Languages\Russian.isl"; LicenseFile: "License_RUS.txt"

;------------------------------------------------------------------------------
;    -  ,     
;------------------------------------------------------------------------------
[Tasks]
;     
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

;------------------------------------------------------------------------------
;   ,      
;------------------------------------------------------------------------------
[Files]

;  
Source: "C:\Git\additionals\task_10\Release\ZombieVsPlants.exe"; DestDir: "{app}"; Flags: ignoreversion

;  
Source: "C:\Git\additionals\task_10\img*"; DestDir: "{app}\img\"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\Git\additionals\task_10\fonts\*"; DestDir: "{app}\fonts\"; Flags: ignoreversion recursesubdirs createallsubdirs

; VS Redistributable package
Source: "C:\Git\additionals\task_10\installer\VC_redist.x64.exe"; DestDir: "{tmp}"; Flags: deleteafterinstall
;------------------------------------------------------------------------------
;    ,     
;------------------------------------------------------------------------------ 
[Icons]

Name: "{group}\{#Name}"; Filename: "{app}\{#ExeName}"

Name: "{commondesktop}\{#Name}"; Filename: "{app}\{#ExeName}"; Tasks: desktopicon

[Run]
;------------------------------------------------------------------------------
;      VS
;------------------------------------------------------------------------------
Filename: {tmp}\VC_redist.x64.exe; Parameters: "/q:a /c:""install /l /q"""; StatusMsg: VS redistributable package is installed. Please wait...
