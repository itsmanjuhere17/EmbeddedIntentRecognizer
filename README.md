# Embedded Intent Recognizer
Embedded Intent Recognizer is a command line tool that recognizes the intent of the user based on the input from the user. 
At the moment, the tool can recognize only Weather, Calendar and Fact intents. The tool can be extended to identify other intents as well. 

# Dependencies
1) Cmake verison (minimum 3.5)
2) Latest g++ compiler that supports C++ 17 langauge features.

# Building the project.
1) Clone the repo.
2) mkdir build && cd build
3) cmake ..
4) make

# Running the project:
From build, directory run "./src/IntentRecognizer_bin"

# Running the Unit-tests
From build directory, run "./tests/IntentRecognizer_tst"
