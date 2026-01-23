function blkStruct = slblocks
%SLBLOCKS Defines the Simulink library block representation


%%%blkStruct.Name    = 'TTC580 basic';
%%%blkStruct.OpenFcn = 'IO_TMS570';

%%%blkStruct.MaskInitialization = '';

%%%blkStruct.MaskDisplay = '';

% Define the library list for the Simulink Library browser.
% Return the name of the library model and the name for it

Browser(1).Library = 'AddOn_Lib_TTC580_CCP';
Browser(1).Name    = 'Addon (CCP) for I/O Blocklib TTC580';

blkStruct.Browser  = Browser;

