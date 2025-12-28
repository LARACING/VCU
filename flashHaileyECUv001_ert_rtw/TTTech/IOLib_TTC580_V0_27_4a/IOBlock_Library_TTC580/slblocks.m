function blkStruct = slblocks
%SLBLOCKS Defines the Simulink library block representation


%%%blkStruct.Name    = 'TTC580 basic';
%%%blkStruct.OpenFcn = 'IO_TMS570';

%%%blkStruct.MaskInitialization = '';

%%%blkStruct.MaskDisplay = '';

% Define the library list for the Simulink Library browser.
% Return the name of the library model and the name for it

Browser(1).Library = 'IOBlock_Library_TTC580';
Browser(1).Name    = 'I/O Blocklibrary for TTC580';

Browser(2).Library = 'IOBlock_Library_TTC580_SafeConfBlocks';
Browser(2).Name    = 'I/O Blocklibrary safety config for TTC580';

blkStruct.Browser  = Browser;

