###########################################################################################
############################                                      #########################
############################ I/O BlockLibrary TTC580 for Simulink #########################
############################                                      #########################
###########################################################################################


1) Required Toolset:
  A) MATHWORKS
  MATLAB                                : Version 9.9+        (R2020b-R2021a)                   
  Simulink                     	        : Version 10.2+       (R2020b-R2021a)                   
  Embedded Coder                        : Version 7.5+        (R2020b-R2021a)                   
  MATLAB Coder                          : Version 5.1+        (R2020b-R2021a)     
  Simulink Coder                        : Version 9.4+        (R2020b-R2021a)    
  
  B) Make environment
  The required tool chain is TI ARM Code Generation Tools, version 5.1.6. An integrated development 
  environment (IDE) named TI Code Composer Studio (TI CCS), is available online from 
  http://processors.wiki.ti.com/index.php/Download_CCS# or from your local distributor. 
  How to install the ARM Compiler Tools 5.1.6 is described in detail within the HY-TTC500 Quick 
  Start Guide or the HY-TTC500 System Manual. 
  Note: To install ARM Compiler Tools 5.1.6 uncheck the option "Show only the latest version of available 
  software". By doing so you make the necessary compiler version visible for installation within CCS. 
  Please refere also to the Quick_Start_Guide and Installation_Note_Compiler.png which outlines this
  installation procedure.

  C) Downloader (Flash)
  TTC-Downloader 4.20 or higher from TTControl using PCAN for downloading.
  The "Starterkit" for TTC580 includes downloader, PCAN-USB-Adapter and 
  the ECU to run the generated code with the I/O Blocklibrary TTC580. 
  
  D) For running the DBC-Importer .Net (at least version 4.0) is required.
  
  E) For running the EEPROM-Importer Microsoft Excel (at least version 2010) is required.

  F) The add on library for IOLib_TTC580 features the usage of CAN Calibration Protocol (CCP) v2.1. 
     This may be used preferably with Vector's CANape 16.0. 

  G) The IOLib_TTC580 exploits complete pinout possibilities of the HY-TTC580. In case you are using a different variant 
     of the TTC500 family limitations in the amount of pins and/or functionality apply.   


2) Installation (read only if installation is not feasable with the standard installation file)

  If installation may not be processed automatically then the user needs to have some basic knowledge using MATLAB,
  in order to accomplish installation manually. The following steps lead through manual installation:
  
  A) Please copy the complete content of the directory 
          \IOLib_TTC580\TTTech 
     exactly to 
          C:\TTTech
          
    Note (only for update): The C-library included in this release is V3.1.0. You may only build your application 
        with this release. If you update your C-library to a newer version keep in mind to restore eventually 
        adaptions you have made before update within the file "IOLib_TTC580\TTTech\Environment_TTC580\env\settings.mk".
  
  B) Please copy the complete content of the directory 
          \IOLib_TTC580\IOBlock_Library_TTC580
     to any place e.g.  
  	  C:\TTTech\IOLib_TTC580\IOBlock_Library_TTC580
  
  C) Open MATLAB 
 
  D) Enter the following commands in the command-window
     >> addpath('C:\TTTech\IOLib_TTC580\IOBlock_Library_TTC580'); 
     alternatively you may use the command >> pathtool in order to interactively set the MATLABPATH and store the path permanently
     After having set the MATLABPATH, the "I/O Blocklibrary for TTC580" - appears in the SIMULINK-Library browser.
     Hint: If you want to have the IOLib_TTC580 permanently available save the path within pathtool.
   
  E) Install the TI C-Compiler preferably on "C:\TI\TI ARM Code Generation Tools 5.1.6" . If installed differently please
     change the entry C_COMP_PATH = <your_installation_directory> within the file IOLib_TTC580\TTTech\Environment_TTC580\env\settings.mk
     accordingly

  F) The FPGA-Version on the TTC580 necessary to run the application is "V16.5.0". In order to get the actual FPGA version of your TTC580 
     you need to read out the FPGA-IP Version using the TTC-Downloader, by clicking on the FIDB button. This will show you the 
     "FPGA IP Descriptor Block" containing the FPGA IP Version of your TTC580.

3) First Start & Example
    Please check first the document \UserDoc\quickstartguide_IOlibTTC580 which provides a step-by-step guide elaborating a explanatory example.
    The examples provide the principle ideas, how the "I/O Blocklibrary for TTC580" works. 
    
    A) Start Matlab and use the command >> pathtool to check your MATLABPATH. If the directory with the library is not included in your
       MATLABPATH add this directory to your path (e.g. C:\TTTech\IOLib_TTC580_V<major_minor_patchnumber>\IOBlock_Library_TTC580), save this path and
       close the pathtool window.
    
    B) Open SIMULINK-Library browser by clicking on the Simulink-icon within MATLAB
    
    C) Open the tab "I/O Blocklibrary for TTC580" within the SIMULINK-Library browser. If "I/O Blocklibrary for TTC580" does not appear
       on your browser try to refresh the tree by typing "F5" or using the menu "View/Refresh Tree View"
    
    D) There you click on "Examples" to open the list of examples comming along with this block library.
    
    E) Click on the blue "Info" block within the example models or read C:\TTTech\IOLib_TTC580\IOBlock_Library_TTC580\Example\how_to_build.txt 
       to get further instructions how to generate code and build your download image.

4) DBC_Importer
    A) Please copy the complete content of the directory 
           \IOLib_TTC580\DBC_Importer
       to any place e.g.  
  	   C:\TTTech\IOLib_TTC580\DBC_Importer
       and add this dirctory to your MATLABPATH within Matlab with the command add_path or pathtool

    B) In order to run the dbc-importer please change within MATLAB to the above defined directory DBC_Importer 
       and type:
       >> help DBC_Import
       to obtain more information about this tool and how to run an illustrative example.
  
5) EEPROM_Importer
    A) Please copy the complete contentadd of the directory 
           \IOLib_TTC580\EEPROM_Importer
       to any place e.g.  
  	   C:\TTTech\IOLib_TTC580\EEPROM_Importer
       and add this dirctory to your MATLABPATH within Matlab with the command add_path or pathtool

    B) In order to run the EEPROM-importer please change within MATLAB to the above defined directory EEPROM_Importer
       and type:
       >> help EEPROM_Import
       to obtain more information about this tool.
       EEPROM_Import will generate a library out of an Excel file with the Excel-sheets having to have a defined format. 
       Please use eeprom_example.xls as a starting template. 
       EEPROM_Import will also generate a ihex-file that can be used to flash the EEPROM with the values defined in
       the Excel-sheets. For flashing the EEPROM you need to use the TTC-Downloader.

   C)  In order to read out the values from the EEPROM, you need to first use the TTC-Downloader to generate a ihex-file.
       This ihex file can then be used to fill the actual values from EEPROM into your Excel-Sheet.
       Please type 
       >> help hex_read
       in order to obtain specific help how to call hex_read within MATLAB.

6) Known Limintations
   *  It is not possible to run IOLib_TTC580 and another IOLib of TTTech/TTControl in parallel during the same Matlab-session. 
      Please remove all directories to the the other IOLibs except for the IOLib_TTC580 from the MATLABPATH using the the 
      command "pathtool".
   *  In case you are using a smaller variant of the TTC500 family, not all pins that appear in the drop-down menus of the 
      masks may be used and not all functions are supported. Please refer to the pinout of the TTC5XX you are actually using, 
      in order to avoid specifying pins and functions that are not available on your TTC5XX. 
   *  Only single tasking supported
   *  CCP (add on library) may not be used for flash programming or any access to the Flash/EEPROM.
 
      




