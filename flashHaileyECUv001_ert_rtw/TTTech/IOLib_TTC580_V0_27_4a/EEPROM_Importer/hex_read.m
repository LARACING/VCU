function [ ErrorCode ] = hex_read( sXls_File, sIhex_File)
%++
%function [ ErrorCode ] = hex_read( sXls_File, sIhex_File)
%
% Copyright (C) 2021 TTTech Computertechnik AG. All rights reserved
% Schönbrunnerstraße 7, A--1040 Wien, Austria. office@tttech.com
%
% Name
%   hex_read.m
% In
%   sXls_File : [Path\]ExcelFilename.xls
%   sIhex_File : [Path\]IhexFilename.ihex
%
% Out
%   ErrorCode : 0 ... at least one paramter group stored successfully 
%               1 ... no parameter group processed successfully
%
% Purpose
%     Store EEPROM data into an Excel file.
%
% Prerequisite
%     EEPROM data have to be already stored into an ihex-file. This action
%     is accomplished by the TTC-Downloader.
%     The ihex-file has to cover at least all addresses for data defined 
%     in the Excel-file
%
% Example 
%     ErrorCode = hex_read('eeprom_example.xls','eeprom_example.ihex')
%--

ErrorCode  = hex_readwrite_internal( sXls_File, 'hex_read',  sIhex_File  ); 
