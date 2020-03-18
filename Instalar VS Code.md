# Instalar VS Code

Instrucciones originales: [Link](https://code.visualstudio.com/docs/cpp/config-mingw)

## Windows

1. Descargar e instalar VS Code de este [link](https://code.visualstudio.com/download)
2. Abrir VS Code e instalar la extensión de `C/C++`.
3. Descargar el compilador MinGW de este [link](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download)
4. Para instalar MinGW es necesario instalarlo en `C:\mingw\`
5. Modificar las variables de entorno para incluir `C:\mingw\mingw64\bin`
6. Configurar los archivos `launch.json` `y tasks.json`

Archivo launch.json
```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "My debugger",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "C:\\mingw\\mingw64\\bin\\gdb.exe",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "Compile C++"
        }
    ]
}
```

Archivo tasks.json
```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "type": "shell",
            "label": "Compile C++",
            "command": "C:\\mingw\\mingw64\\bin\\g++.exe",
            "args": [
                "-g",
                "${file}",
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe"
            ],
            "options": {
                "cwd": "C:\\mingw\\mingw64\\bin"
            }
        }
    ]
}
```

6. Presionar `F5` y el programa debe ejecutarse.

**Nota**: Versión de MinGW probada 8.1.0
