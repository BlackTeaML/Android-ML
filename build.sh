mkdir build
cd build
cmake .. -DCMAKE_ANDROID_NDK=$NDK -G "Ninja"
cmake --build .
