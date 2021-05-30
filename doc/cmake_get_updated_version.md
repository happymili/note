follow these steps to add the [kitware third-party apt repository](https://apt.kitware.com/) to get an updated version of cmake.

* Add the kitware signing key to apt:
```
wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | sudo apt-key add -
```

* Add the kitware repo corresponding to the Ubuntu 18.04 LTS release:
```
sudo apt-add-repository 'deb https://apt.kitware.com/ubuntu/ bionic main'
```

* Then install the updated cmake using the usual apt commands:
```
sudo apt update
sudo apt install cmake
```
