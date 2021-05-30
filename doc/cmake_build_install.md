### clone the repo
```
sudo git clone https://gitlab.kitware.com/cmake/cmake.git
```

### install dependencies
```
sudo apt-get install openssl libssl-dev
```

### checkout the latest release version
```
cd cmake
sudo git checkout v3.16.0
```

### run bootstrap
```
sudo ./bootstrap
```

### make
```
sudo make
```

### install
The default install directory is /usr/local/bin
```
sudo make install
```
some of the installation log:
```
...
-- Installing: /usr/local/bin/cmake
-- Installing: /usr/local/bin/ctest
-- Installing: /usr/local/bin/cpack
...
```

### check the version
```
cmake -version
```
output
```
cmake version 3.16.0

CMake suite maintained and supported by Kitware (kitware.com/cmake).
```
