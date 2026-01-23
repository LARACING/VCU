function [ ErrorCode ] = EEPROM_Import( sXls_File)
%++
%function [ ErrorCode ] = EEPROM_Import( sXls_File)
%
% Copyright (C) 2021 TTTech Computertechnik AG. All rights reserved
% Schönbrunnerstraße 7, A--1040 Wien, Austria. office@tttech.com
%
% Name
%   EEPROM_Import.m
% In
%   sXls_File : [Path\]Filename.xls
%
% Purpose
%     Import EEPROM configuration data and generate a library containing
%     blocks for all EEPROM access
%     Every block has the parameters defined in Filename.xls as ports.
%     Every block has a busy output indicating that the EEPROM access is
%     ongoing
%     Generated EEPROM-Read blocks have a output CRC_OK
%       The output CRC_OK may hold three possible values: 
%           -1 => after EEPROM section was read, CRC check failed (terminal state)
%            0 => reading of EEPROM section not completed yet, CRC check is pending
%           +1 => after EEPROM section was read, CRC check was successful (terminal state)
%     Generated EEPROM-Write blocks have a input trigger, on a rising edge
%     parameters are written physically to EEPROM
%
% Example 
%     Open the xls-File "eeprom_example.xls" and generate the
%     corresponding EEPROM blocks within the library LibEEPROM_eeprom_example.mdl
%     ErrorCode = EEPROM_Import('eeprom_example.xls')
%
%See also HEX_READ
%--

ErrorCode  = EEPROM_Import_internal( sXls_File ); 
if (ErrorCode == 0)
    ErrorCode  = hex_readwrite_internal( sXls_File, 'hex_write'); 
end
