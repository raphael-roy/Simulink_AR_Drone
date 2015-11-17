% Copyright 2014 The MathWorks, Inc.

disp('===================================================================')
disp('          Please browse to location of Code Sourcery Directory     ')
disp('===================================================================')
disp(char(10));
FolderIsLegit = 0;

while(FolderIsLegit==0)
    FolderName = uigetdir('c:\', 'Select Code Sourcery Directory Location (look for <bin> directory in the Code Sourcery Directory)');
    ListOfFiles =ls(FolderName);
    NumFile= 1 ;
    % This loop will test if an executable file contains <arm-none-linux-gnueabi>
    while ( (FolderIsLegit==0) && (NumFile<=size(ListOfFiles,1)) )
        FileName = ListOfFiles(NumFile,:);
        [pathstr,name,ext] = fileparts([FolderName,'\',FileName]);
        % Tests if the file extension is .exe
        if ( strcmp('.exe',ext) || strcmp('.exe ',ext) )
            % Tests if the file contains <arm-none-linux-gnueabi>
            if  strcmp('arm-none-linux-gnueabi',name(1:22))
                FolderIsLegit = 1;
            end
        end
        NumFile = NumFile + 1;
    end
end


disp(char(10));
disp('===============================================================================')
disp('                 Generating XML File for Third Party Tools in                  ')
disp('                  \AR_Drone\registry\thirdpartytools                           ')
disp('===============================================================================')
disp(char(10));

PassFail = RegisterThirdPartyCompilerXML(FolderName);


if PassFail==1
    disp('Compiler Succesfully Registered');
end

disp(char(10));
disp('===============================================================================')
disp('                              Updating Path Settings')
disp('===============================================================================')
disp(char(10));

addpath([pwd]);
addpath([pwd '\blocks']);
addpath([pwd '\registry']);
savepath
