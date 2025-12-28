function make_obj(s_MdlName,sTarget)
%make_obj(s_MdlName[,sTarget])
%In: 
%s_MdlName: Name of the Model without extention
%sTarget:    any of 'TTC508','TTC510', 'TTC520', 'TTC540', 'TTC580','TTC590','TTC590E','TTC510_GEN2','TTC520_GEN2','TTC540_GEN2','TTC580_GEN2'
%            default: 'TTC580'
%

%init
c_all_mk_without_sim={};
sBUILD = 'build';
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
if ~ismember(TARGET,cALLOWED_TTC5XX)
    error(['The target given as %s may only have the following values \n',cALLOWED_TTC5XX{:},'\n'],TARGET);
end


%find the relevant code to build objects for:
all_mk = rdir([pwd,'\**\',s_MdlName,'.mk']);
if isempty(all_mk)
    error([s_MdlName,': Makefile not found']);
else
    for i = 1:length(all_mk);
        if(isempty(strfind(all_mk(i).name,'\sim\')))
            c_all_mk_without_sim{end+1} = all_mk(i).name;
        end
    end
    if isempty(c_all_mk_without_sim)
        error([s_MdlName,' only code for simulation generated: no embedded objects to make']);
    elseif length(c_all_mk_without_sim) ~= 1
        s_all_mk_without_sim = '';
        for i=1:length(c_all_mk_without_sim)
            s_all_mk_without_sim = sprintf(['%s\n%s'],c_all_mk_without_sim{i},s_all_mk_without_sim);
        end
        error([s_MdlName,' not unique: multiple code found, please delete the obsolte one:',char(10),s_all_mk_without_sim]);
    else %OK
        s_CodePath = fileparts(c_all_mk_without_sim{1});
    end
end

s_ActDir = pwd;

try
cd(s_CodePath);

sWhichMake = ['"',which('make.exe'),'"'];

if not(exist(['.\',sBUILD])), mkdir(sBUILD); end

make_file=dir('*.mk');
sWhichMakeFile = ['"',make_file.name,'"'];
sMatlabRoot = ['"',matlabroot,'"'];

s_cmd = (['!',sWhichMake,' TARGET=',TARGET,' MATLABROOT=',sMatlabRoot,' -f ',sWhichMakeFile,' compile']);
disp(s_cmd);
eval(s_cmd);

end

cd(s_ActDir)
