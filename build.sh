mkdir build
cd build
cmake .. -DCMAKE_ANDROID_NDK=$NDK
cmake --build .
