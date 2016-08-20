ECLIPSE ANDROID PROJECT IMPORT SUMMARY
======================================

Ignored Files:
--------------
The following files were *not* copied into the new Gradle project; you
should evaluate whether these are still needed in your project and if
so manually move them:

* .DS_Store
* .gitignore
* LICENCE
* ant.properties
* build.xml
* proguard-project.txt

Moved Files:
------------
Android Gradle projects use a different directory structure than ADT
Eclipse projects. Here's how the projects were restructured:

* AndroidManifest.xml => app\src\main\AndroidManifest.xml
* libs\armeabi-v7a\libsocketdest.so => app\src\main\jniLibs\armeabi-v7a\libsocketdest.so
* libs\armeabi\libsocketdest.so => app\src\main\jniLibs\armeabi\libsocketdest.so
* libs\bc.jar => app\libs\bc.jar
* libs\bsf-2.3.0.jar => app\libs\bsf-2.3.0.jar
* libs\bsh-2.0b4.jar => app\libs\bsh-2.0b4.jar
* libs\chardet.jar => app\libs\chardet.jar
* libs\concurrent.jar => app\libs\concurrent.jar
* libs\htmlparser.jar => app\libs\htmlparser.jar
* libs\java_websocket.jar => app\libs\java_websocket.jar
* libs\jcifs-1.3.14.jar => app\libs\jcifs-1.3.14.jar
* libs\jnetutils.jar => app\libs\jnetutils.jar
* libs\mips\libsocketdest.so => app\src\main\jniLibs\mips\libsocketdest.so
* libs\sandroproxylib.jar => app\libs\sandroproxylib.jar
* libs\x86\libsocketdest.so => app\src\main\jniLibs\x86\libsocketdest.so
* res\ => app\src\main\res\
* src\ => app\src\main\java\

Next Steps:
-----------
You can now build the project. The Gradle project needs network
connectivity to download dependencies.

Bugs:
-----
If for some reason your project does not build, and you determine that
it is due to a bug or limitation of the Eclipse to Gradle importer,
please file a bug at http://b.android.com with category
Component-Tools.

(This import summary is for your information only, and can be deleted
after import once you are satisfied with the results.)