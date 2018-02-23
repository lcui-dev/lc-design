set "VSCMD_START_DIR=%CD%"
call %1
msbuild main.sln -nologo -t:Rebuild -p:Configuration=Release /p:Platform=x86 /t:demo
