@echo off

set REP=nul

rem uncomment this, if a report is required:
rem set REP=%cd%/report.txt 2> nul

echo cleaning %cd%
rmdir /S /Q .\Bin                 2>> %REP%
rmdir /S /Q .\RTE                 2>> %REP%
rmdir /S /Q .\DebugConfig         2>> %REP%
rmdir /S /Q .\Debug               2>> %REP%
rmdir /S /Q .\.settings           2>> %REP%

del .\*.bak           2>> %REP%
del .\*.dep*          2>> %REP%
del .\*.axf           2>> %REP%
del .\*.layout        2>> %REP%
del .\*.uvguix.*      2>> %REP%
del .\*.scvd          2>> %REP%
del .\main.exe        2>> %REP%
del .\JLinkLog.txt    2>> %REP%
del ".\Target 1.bat"  2>> %REP%


rem pause
