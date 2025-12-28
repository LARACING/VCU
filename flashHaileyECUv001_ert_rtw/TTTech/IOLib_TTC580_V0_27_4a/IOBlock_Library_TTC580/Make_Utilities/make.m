function make(sNameOfMdl,sTarget)
%make is the regualar building function that executes the general Make-file 
%which is located in \IOLib_TTC580\IOBlock_Library_TTC580\Make_Utilities. 
%This results in a generated hex-file for downloading onto the Target
%
%make(sNameOfMdl[,sTarget])
%
%In: 
%sNameOfMdl: Name of the Model without extention
%sTarget:    any of 'TTC508','TTC510', 'TTC520', 'TTC540', 'TTC580','TTC590','TTC590E','TTC510_GEN2','TTC520_GEN2','TTC540_GEN2','TTC580_GEN2'
%            default: 'TTC580_GEN2'
%
%Note:prerequisit for using this make-skript is the directory \Make_Utilities 
%being part of the matlabpath.
%For using this make-Routine it is assumed that the sources are stored in a
%directory "<sNameOfMdl>_ert_rtw"
%



POSTFIX = '_ert_rtw';
C_ENVIRONMENT_TTC580 = 'C:\TTTech\Environment_TTC580';
VERSION_TAG = '\version';
VERSION_MATCH = '3.1.'; %differences in patch are tolerated
cALLOWED_TTC5XX = {'TTC508','TTC510', 'TTC520', 'TTC540', 'TTC580','TTC590','TTC590E','TTC510_GEN2','TTC520_GEN2','TTC540_GEN2','TTC580_GEN2'}; %valid HY-TTC580 variants

if nargin < 1
    error('Please specify the name of the model to make without extention')
end
if nargin < 2
    TARGET = 'TTC580_GEN2';
    disp([char(13),'No specific target specified, building default target : ',TARGET,char(13)]);
else
    TARGET = sTarget;
end

%checks:
if ~(isa(sNameOfMdl,'char'))
    error('Please specify the name of the model as a string')
end
if ~ismember(TARGET,cALLOWED_TTC5XX)
    error(['The target given as %s may only have one of the following values \n',cALLOWED_TTC5XX{:},'\n'],TARGET);
end


%Check MainDlg4App (4-Application: FileCopy) BEGIN
[dirMdl,sActDir] = make4App(sNameOfMdl);
%Check MainDlg4App END
try
    cd(dirMdl);
    cd([sNameOfMdl,POSTFIX]);
catch
    error('For application ''%s'' no generated code found. Please build the code first or complement the MATLABPATH. -> make aborted',sNameOfMdl);
end
if ~exist('.\build'), mkdir('.\build'); end

%Check Version of library BEGIN
sIO_Driver_h = fileread([C_ENVIRONMENT_TTC580,'\inc\IO_Driver.h']);
idx=strfind(sIO_Driver_h, VERSION_TAG);
if ~isempty(idx)
    idx_version_info = idx + length(VERSION_TAG); %here is the version info
    sVersion=sscanf(sIO_Driver_h(idx_version_info:end),'%s*%s');
    if isempty(strmatch(VERSION_MATCH,sVersion))
        warning(['The Version of the TTC580 driver library is ',sVersion,...
            ' this does not correspond to the required version ',VERSION_MATCH,'x. Please update.']);
    end
else
    warning('No version information from TTC580 driver library could be read, check the installation of the IOLib_TTC580 or check the output b_IODrv_version_OK of the DIAG_Status block for confirmation of compatible IO-Driver version.');
end
%Check Version of library END

sWhichMake = ['"',which('make.exe'),'"'];
sWhichMakeFile = ['"',which('Makefile.'),'"'];
sMatlabRoot = ['"',matlabroot,'"'];
s_cmd = (['!',sWhichMake,' TARGET=',TARGET,' MATLABROOT=',sMatlabRoot,' --makefile=',sWhichMakeFile,' clean all']);   %clean first then make all
disp(s_cmd);
eval(s_cmd);

%rename hex file from app.hex to <ModelName>.hex
try
    sHex_file_orig = ['.\build\','app.hex'];
    sHex_file_new =  ['.\build\',sNameOfMdl,'.hex'];
    if exist(sHex_file_orig,'file')
        movefile(sHex_file_orig,sHex_file_new);
    end
end
cd(sActDir);
%!C:\TTTech\IOBlock_Library_TTC580\Make_Utilities\make --makefile=C:\TTTech\IOBlock_Library_TTC580\Make_Utilities\Makefile
