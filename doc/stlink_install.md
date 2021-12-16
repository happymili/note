# github page

[stlink](https://github.com/texane/stlink)

# stlink installation

### install dependency

```
sudo apt-get install libusb-1.0
```

### clone stlink

```
git clone https://github.com/texane/stlink
```

### make

```
cd stlink
make release
```

### install

```
cd build/Release
sudo make install
```
