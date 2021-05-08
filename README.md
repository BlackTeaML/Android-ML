# Android-ML
---
First open source android modding library for Geometry Dash  
Based on [Hooking-and-Patching-android-template](https://github.com/Djngo/Hooking-and-Patching-android-template)
---

## Installation
1. Download this github files and unzip it
2. Download [Android NDK 16b](https://developer.android.com/ndk/downloads/older_releases)

## Compiling
```sh
./build.bat
```

## Loading the libandroidml.so
1. Open GeometryDash/smali/com/robtopx/geometryjump/geometryjump.smali
2. Add this to the first static constructor method
```
  .line 70
  const-string v0, "androidml"
  invoke-static {v0}, Ljava/lang/System;->loadLibrary(Ljava/lang/String;)V
```

---
## Special thanks
- [Pie](https://github.com/poweredbypie) for headers
- [HJfod](https://github.com/HJfod) for headers
- [Adaf](https://github.com/adafcaefc) for headers, haxormode and beeing Adaf
- [FlairyDash](https://github.com/FlairyDash) for development help

---
### Join [Galaxium](https://discord.gg/ZV2zDu6JUX)
