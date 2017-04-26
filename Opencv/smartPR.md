# Sundy #
## smart PR ##

### 1.OpenCV3.1.0交叉编译	###
 
#### 1.1 Download OpenCV3.1.0 source code. ####

	http://opencv.org/releases.html	

1.2 设置CMakeLists.txt	

	set(CMAKE_SYSTEM_NAME Linux)
	set(CMAKE_SYSTEM_VERSION 1)
	set(CMAKE_SYSTEM_PROCESSOR arm-hisiv300-linux-gcc)
	
	set(GCC_COMPILER_VERSION "4.6" CACHE STRING "GCC Compiler version")
	
	set(FLOAT_ABI_SUFFIX "")
	if (NOT SOFTFP)
	  set(FLOAT_ABI_SUFFIX "hf")
	endif()
		
	#CROSS COMPILE SETTING
	set(TOOLCHAIN_DIR "/opt/hisi-linux/x86-arm/arm-hisiv300-linux/")
	set(CMAKE_C_COMPILER "/opt/hisi-linux/x86-arm/arm-hisiv300-linux/bin/arm-hisiv300-linux-uclibcgnueabi-gcc")
	set(CMAKE_CXX_COMPILER "/opt/hisi-linux/x86-arm/arm-hisiv300-linux/bin/arm-hisiv300-linux-uclibcgnueabi-g++")
	set(CMAKE_FIND_ROOT_PATH /opt/hisi-linux/ /opt/hisi-linux/x86-arm/arm-hisiv300-linux/)
	set(ARM_LINUX_SYSROOT /opt/hisi-linux/x86-arm/arm-hisiv300-linux/ CACHE PATH "ARM cross compile system root")	
	
	MESSAGE(STATUS "This is cross compile dir --->"$(CMAKE_C_COMPILER))
	
	#find_program(CMAKE_C_COMPILER NAMES arm-linux-gnueabi${FLOAT_ABI_SUFFIX}-gcc-${GCC_COMPILER_VERSION})
	#find_program(CMAKE_CXX_COMPILER NAMES arm-linux-gnueabi${FLOAT_ABI_SUFFIX}-g++-${GCC_COMPILER_VERSION})
	#set(ARM_LINUX_SYSROOT /usr/arm-linux-gnueabi${FLOAT_ABI_SUFFIX} CACHE PATH "ARM cross compilation system root")
	
	#set(CMAKE_CXX_FLAGS           ""                    CACHE STRING "c++ flags")
	#set(CMAKE_C_FLAGS             ""                    CACHE STRING "c flags")
	#set(CMAKE_SHARED_LINKER_FLAGS ""                    CACHE STRING "shared linker flags")
	#set(CMAKE_MODULE_LINKER_FLAGS ""                    CACHE STRING "module linker flags")
	#set(CMAKE_EXE_LINKER_FLAGS    "-Wl,-z,nocopyreloc"  CACHE STRING "executable linker flags")
	 
1.2 cmake

	mkdir buildDir 
	mkdir install_dir
	cd buildDir

	cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=../install_dir/ -D SOFTFP=ON -D ENABLE_NEON=ON -D CMAKE_TOOLCHAIN_FILE=../arm-gnueabi.toolchain.cmake ../../../
	
	
### 2 编译OpenCV应用程序 ###

2.1 CMakeLists.txt
	
	cmake_minimum_required(VERSION 3.1.0)
	set(CMAKE_SYSTEM_NAME Linux)
	
	# c++11 required
	set(CMAKE_CXX_STANDARD 11)
	set(CMAKE_CXX_STANDARD_REQUIRED ON)
	
	set(CMAKE_SYSTEM_VERSION 1)
	set(CMAKE_SYSTEM_PROCESSOR arm-hisiv300-linux-gcc)
	
	set(GCC_COMPILER_VERSION "4.8" CACHE STRING "GCC Compiler version")
	
	set(FLOAT_ABI_SUFFIX "")
	if (NOT SOFTFP)
	    set(FLOAT_ABI_SUFFIX "hf")
	endif()
	
	#CROSS COMPILE SETTING
	set(TOOLCHAIN_DIR "/opt/hisi-linux/x86-arm/arm-hisiv300-linux/")
	set(CMAKE_C_COMPILER "/opt/hisi-linux/x86-arm/arm-hisiv300-linux/bin/arm-hisiv300-linux-uclibcgnueabi-gcc")
	set(CMAKE_CXX_COMPILER "/opt/hisi-linux/x86-arm/arm-hisiv300-linux/bin/arm-hisiv300-linux-uclibcgnueabi-g++")
	set(CMAKE_FIND_ROOT_PATH /opt/hisi-linux/ /opt/hisi-linux/x86-arm/arm-hisiv300-linux/)
	set(ARM_LINUX_SYSROOT /opt/hisi-linux/x86-arm/arm-hisiv300-linux/ CACHE PATH "ARM cross compile system root")
	
	MESSAGE(STATUS "This is cross compile dir --->"$(CMAKE_C_COMPILER))
	
	
	project(easypr)
	set(OpenCV_DIR /home/software/opencv-3.1.0/platforms/linux/build_softfp)
	include_directories(/home/software/opencv-3.1.0/platforms/linux/install_dir/include)
	
	# OpenVC3 required
	find_package(OpenCV 3.1.0 REQUIRED)
	
	# where to find header files
	include_directories(.)
	include_directories(include)
	include_directories(${OpenCV_INCLUDE_DIRS})
	
	# sub directories
	add_subdirectory(thirdparty)
	
	# sources to be compiled
	set(SOURCE_FILES
	        src/core/core_func.cpp
	        src/core/chars_identify.cpp
	        src/core/chars_recognise.cpp
	        src/core/chars_segment.cpp
	        src/core/feature.cpp
	        src/core/plate_detect.cpp
	        src/core/plate_judge.cpp
	        src/core/plate_locate.cpp
	        src/core/plate_recognize.cpp
	        src/core/params.cpp
	
	        src/train/ann_train.cpp
	        src/train/svm_train.cpp
	        src/train/train.cpp
	
	        src/preprocess/deface.cpp
	        src/preprocess/gdts.cpp
	        src/preprocess/mc_data.cpp
	
	        src/util/util.cpp
	        src/util/program_options.cpp
	        src/util/kv.cpp
	        )
	
	# pack objects to static library
	add_library(easypr STATIC ${SOURCE_FILES})
	
	if (CMAKE_SYSTEM_NAME MATCHES "WinLinux")
	  set(EXECUTABLE_NAME "demo_darwin_amd64")
	elseif (CMAKE_SYSTEM_NAME MATCHES "Linux")
	  set(EXECUTABLE_NAME "demoPR32")
	endif ()
	
	# test cases
	add_executable(${EXECUTABLE_NAME} test/main.cpp)
	# link opencv libs
	target_link_libraries(${EXECUTABLE_NAME} easypr thirdparty ${OpenCV_LIBS})
	                                                                            


### Reference ###
[http://blog.csdn.net/brightming/article/details/50563565](http://blog.csdn.net/brightming/article/details/50563565)