function [dirMdl,sActDir]=make4app(sPathNameOfMdl)
%Note:prerequisit for using this make: opening the I/O Blocklibrary for TTC580 in Simulink-Browser
%For using this make-Routine it is assumed that all sources are stored in
%the directories "<sNameOfMdl>_ert_rtw","<application_1>_ert_rtw".."<application_4>_ert_rtw" 
%These directories have to be visible either from the model directory or on
%the MATLAB-path

POSTFIX = '_ert_rtw';
C_ENVIRONMENT_TTC580 = 'C:\TTTech\Environment_TTC580';
NO_APP = 'none';    %TAG if no application is defined in MainDlg4App-Mask
MAIN_DLG_APP = 'MainDlg4App';

if nargin < 1
    error('Please specify the name of the model to make without extention')
end

%extrakt & checks of actual model
[dirMdl,sNameOfMdl] = Mdl_fileparts(sPathNameOfMdl);
cd(dirMdl);
sActDir = pwd;
sActSrcDir = ([sActDir,'\',sNameOfMdl,POSTFIX]);

%copy files from referenced applications
fprintf('The following blocks listed need to be updated before Code generation.\nIf the list is empty: ignore\nIf the list is not empty: update model and resume make.\n\n');
load_system(sPathNameOfMdl);
fprintf('\n\n');
sMainDlg4App_block = find_system(sNameOfMdl,'LookUnderMasks','on','ttDescription',MAIN_DLG_APP);
if isempty(sMainDlg4App_block)
    return; %no MainDlg4App block: no need to copy files
    %error('The Model %s does not contain any %s block -> make aborted.',sNameOfMdl,MAIN_DLG_APP);
end
for i = 1:4
    cApp_name= get_param(sMainDlg4App_block,['app_',num2str(i)]);
    if ~strcmp(strtrim(cApp_name{1}),NO_APP);
        dirApp = Mdl_fileparts(cApp_name{1});    
        try
            cd(dirApp);
            cd([cApp_name{1},POSTFIX]);
        catch
            error('For application ''%s'' no generated code found. Please build the code first or complement the MATLABPATH. -> make aborted',cApp_name{1});
        end
        all_c_h_files = dir([cApp_name{1},'*']);
        for idx = 1:length(all_c_h_files)
            act_file = all_c_h_files(idx).name;
            if isempty(findstr(act_file,'_main'))   % don't copy <Mdl>_main.c
                [success,msg] = copyfile(all_c_h_files(idx).name,sActSrcDir,'f');
                if (success~=1), error([msg,' -> make aborted']); end
            end
        end
        cd(sActDir);    %return to actual directory
    end
end

%call real make
%make(sNameOfMdl);

%%% internal function %%%
function [dirMdl,sNameOfMdl] = Mdl_fileparts(sNameOfMdl)
sWhichMdl = which([sNameOfMdl,'.mdl']);
if isempty(sWhichMdl)
    sWhichMdl = which([sNameOfMdl,'.slx']);
    if isempty(sWhichMdl)
        error(['Specified Model:  ',sNameOfMdl,'.mdl or ',sNameOfMdl,'.slx could not be found']);
    end
end
[dirMdl,sNameOfMdl] = fileparts(sWhichMdl);
return;
