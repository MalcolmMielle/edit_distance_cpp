# Edit Distance function for string and graphs.

# Install

```
mkdir build
cd build
cmake ..
make -j8
make install
```

#Use in Cmake 

```
find_package( editdistance REQUIRED )
include_directories(${editdistance_INCLUDE_DIRS})
```
