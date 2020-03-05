# Raytracing
This is just a sandbox project, to have fun with SFML and hopefully make a few cool looking effects.

# Dependencies
## Conan
This project uses [Conan](https://conan.io/)
To install it :
```shell script
pip3 install conan
```
Then if conan is not automatically on your path (like on Windows), you can do :
```shell script
pip3 show conan
```
It will tell you where it is.

Recommanded conan profile on Windows :
```buildoutcfg
[settings]
os=Windows
os_build=Windows
arch=x86_64
arch_build=x86_64
compiler=Visual Studio
compiler.version=15
build_type=Debug
[options]
[build_requires]
[env]
```
On Linux, the default profile, once created should work out of the box.

You should also have the [bincrafters](https://bincrafters.github.io/2017/06/06/using-bincrafters-conan-repository/) remote configured :
```shell script
conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan
```

## CMake
You should also have Cmake available on your path.

# Compilation
To compile the project :
```shell script
mkdir build
cd build
conan install ..
cmake .. # on windows, add  -G "Visual Studio 15 Win64"
cmake --build .
```
You should then have the `raytracing` executable in `build/bin` directory. If you don't, please open an issue describing your problem so that I can get better at cross-platform :D
