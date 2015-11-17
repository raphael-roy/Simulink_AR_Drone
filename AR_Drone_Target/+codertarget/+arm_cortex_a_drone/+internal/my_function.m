% Copyright 2014 The MathWorks, Inc.
function my_function()

    try
        ab = getActiveConfigSet(gcs);
        IP_String  = codertarget.data.getParameterValue(ab,'IP');
    catch
        warning(['In ' , mfilename('fullpath') , ', "Invalid Simulink object specifier" error from "getActiveConfigSet" function -> IP adress fixed to 192.168.1.1']);
        IP_String = '192.168.1.1';
    end

    setenv('AR_DRONE_IP_ADDRESS',IP_String)
    
end