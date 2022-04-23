@echo off

@REM powershell -c start -verb runas cmd '/c start /D "%CD%" bash.exe'

python ./cli.py %*