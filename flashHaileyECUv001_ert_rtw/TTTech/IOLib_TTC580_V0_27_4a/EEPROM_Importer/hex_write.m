function [ ErrorCode ] = hex_write( sXls_File)
%++
%function [ ErrorCode ] = hex_write( sXls_File)
%
% Copyright (C) 2021 TTTech Computertechnik AG. All rights reserved
% Schönbrunnerstraße 7, A--1040 Wien, Austria. office@tttech.com
%
% Name
%   hex_write.m
% In
%   sXls_File : [Path\]ExcelFilename.xls
%
% Out
%   ErrorCode : 0 ... at least one file written successfully
%               1 ... no file written
%
% Purpose
%   Store EEPROM data into ihex files.
%   The ihex files will be named by the parameter group names (=Excel
%   sheets)
%   In order to flash the paramters in the ihex-file use the TTC-Downloader.
%
% Example 
%   ErrorCode = hex_write('eeprom_example.xls')
%--

ErrorCode  = hex_readwrite_internal( sXls_File, 'hex_write'); 
