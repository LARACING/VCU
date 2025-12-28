function [ ErrorCode ] = DBC_Import( sDBC_File, sNetworkNodeName, CAN_Channel, CycleTime, bDebounce )
%++
%function [ ErrorCode ] = DBC_Import( sDBC_File, sNetworkNodeName [, CAN_Channel [, CycleTime [,bDebounce ] )
%
% Copyright (C) 2021 TTTech Computertechnik AG. All rights reserved
% Schönbrunnerstraße 7, A--1040 Wien, Austria. office@tttech.com
%
% Name
%   DBC_Import.m
% In
%   sDBC_File : [Path\]Filename.dbc
%   sNetworkNodeName : Name of the Network Node that is defined in the
%       DBC-File.
%       In case sNetworkNodeName is a empty string, libraries for every 
%       Network Node are generated.
%   CAN_Channel: out of [0..6]. Default is 0 (meaning CAN_0)
%   CycleTime: Application runs on this CycleTime [ms]. This value is taken for
%       derate parameter of CAN-TX and CAN-RX messages. Default is 10[ms]
%       Note: in order to derate the CAN messages the attribute GenMsgCycleTime needs
%             to be set explicitely for every CAN message in the underlying dbc-file. 
%             Defaults in the dbc-file for GenMsgCycleTime are not accepted.
%   bDebounce: out of [0..1]. Default is 0 (meaning "no debounce"
%       Debouncing holds only for cyclic RX-messages, for other messages no effect.
%       Switching on means that an Rx-error is only passed to the application 
%       if the CAN-driver issues a Not_OK on two consecutive cycles. 
%
% Purpose
%     Import CAN-DBC and generate a library containing blocks for all rx/tx messages
%
% Example 
%     Open the DBC-File "hermes_mini_codings.dbc" and generate the
%     corresponding network node "measure" mapped onto the CAN0 of the
%     ECU assuming a cycle time of the application being 10ms
%     and debouncing is switched on:
%
%     ErrorCode = DBC_Import('hermes_mini_codings.dbc','measure', 0, 10, 1)
%
%--

%init
vALLOWED_CAN_CHANNELS = [0 1 2 3 4 5 6]; 
TTC_IOLIB_NAME = 'IOBlock_Library_TTC580'; %name of the TTC_IO-library
DEFAULT_CAN_CHANNEL = 0;
ErrorCode = 1;  %to be overwritten

if nargin('DBC_Import_internal') < 7 
    fprintf('Wrong version of DBC_Import_internal, please check your installation of the TTC-IOLibrary\n');
    return;
end
if nargin < 5
    bDebounce = '';
end
if nargin < 4 
    CycleTime = '';
end
if (nargin < 3)
    CAN_Channel = DEFAULT_CAN_CHANNEL;
    fprintf(1,'Default CAN channel Nr. %d is used \n', DEFAULT_CAN_CHANNEL)
end

%check input
if ~ismember(CAN_Channel, vALLOWED_CAN_CHANNELS)
    error(['The CAN_Channel given as %d may only have the values ',num2str(vALLOWED_CAN_CHANNELS),'\n'],CAN_Channel);
end

ErrorCode  = DBC_Import_internal( sDBC_File, sNetworkNodeName, CAN_Channel, CycleTime, bDebounce, '', TTC_IOLIB_NAME);
