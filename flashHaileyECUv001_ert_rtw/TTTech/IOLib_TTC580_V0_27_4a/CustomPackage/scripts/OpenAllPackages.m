%This script is meant to call customer libraries and execute the callbacks
%of the libraries
%#define
ACTIVATE_CUSTOM_LIBRARIES = 1;

if ACTIVATE_CUSTOM_LIBRARIES
    
    act_dir = pwd;                                      %store to revert later
    
    %CCP
    CCP_DIR = '..\CustomLibraries\CCP';
    if exist(CCP_DIR,'dir')
        cd(CCP_DIR);                                        %necessary for the PreLoad-Callbacks in Libraries
        open_system('AddOn_Lib_TTC580_CCP.slx');
        cd(act_dir);                                        %revert calling directory
    end
    
    %J1939DMx
    J1939DMx_DIR = '..\CustomLibraries\J1939DMx';
    if exist(J1939DMx_DIR,'dir')
        cd(J1939DMx_DIR);   %necessary for the PreLoad-Callbacks in Libraries
        open_system('AddOn_Lib_TTC580_J1939DMx.slx');
        cd(act_dir);                                        %revert calling directory
    end
    
    %ExtFlash
    ExtFlash_DIR = '..\CustomLibraries\ExtFlash';
    if  exist(ExtFlash_DIR,'dir')
        cd(ExtFlash_DIR);                  %necessary for the PreLoad-Callbacks in Libraries
        open_system('AddOn_Lib_TTC580_ExtFlash.slx');
        cd(act_dir);                                        %revert calling directory
    end
	
    %ConfigFlash
    ConfFlash_DIR = '..\..\CustomPackage\CustomClasses';
    if  exist(ConfFlash_DIR,'dir')
        addpath(ConfFlash_DIR);
        cd(act_dir);                                        %revert calling directory
    end
       
end