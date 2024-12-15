@ECHO OFF
cd "../Testcase gather"
IF EXIST tmp.exe DEL tmp.exe
IF EXIST *.zip DEL *.zip
FOR /r %%i IN (*) DO ECHO. 2>%%i
ECHO Testcases editor cleared
TIMEOUT 2