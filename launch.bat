rem COPY RESSOURCE FOLDER FROM "src" TO "out"
cd out
rd /Q /S Ressources
cd ../out
mkdir Ressources
rem xcopy /E C:\Users\leophancao\Documents\AnimusDemoCpp\src\Ressources C:\Users\leophancao\Documents\AnimusDemoCpp\out\Ressources
xcopy /E D:\repos\AnimusDemoCpp\src\Ressources D:\repos\AnimusDemoCpp\out\Ressources

rem COMPILE
g++ src/main.cpp -Iinclude -Llib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_net -lSDL2_mixer  -o out/monprogramme 
rem -SDL2_ttf
cd out
monprogramme.exe