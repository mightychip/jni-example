# jni-example
This is a super-simple example of JNI.  I got a little sick of the lack of current examples, or perhaps my weak google-fu.  This is the example I failed to find!  I'll update it from time to time.

In lieu of a full and beautiful README, I'll leave you with the sweet and simple basics: to build everything to run this application, you'll want to build the Java components by invoking the following maven goals: `clean install native:javah`

This will build your JNI Header and dump it into the `cpp` directory.  Now you're going to want to build the C++ project in the `cpp` directory, using the `CMakeLists.txt` (CLion does that for me... not that I'm plugging a product).  This will build the necessary `.dylib` file if you're using a Mac.  I'll update this with the necessary changes for Windows and Linux at some point.

You're also going to want to update the absolute path that you'll find in the constructor of the `BasicJNIWrapper` class.  You'll want to make that point to the absolute path of your `.dylib` (or `.dll` or `.so`).

Once all that is done, you simply run BasicJNIWrapper and watch as your code magically calls to and receives responses from a native library.