

subject = "001";
port = "";


s = serialport(port,9600);
fopen(s);
usrInpt = "";

while(~strcmp(usrInpt,"Y"))
    usrInpt = input("Convert to csv? \n","s");
end

str = "";
while(s.NumBytesAvailable > 0)
    str = append(str, readline(s));
end


usrInpt = input("Name of file?","s");


str = splitlines(str);
str(end) = [];
M = reshape(str,3,[])';
writematrix(M, usrInpt + '.csv')


fclose(s);
clear;





