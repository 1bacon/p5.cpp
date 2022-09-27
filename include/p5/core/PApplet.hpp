#pragma once

#include <string>
#include <vector>

#include "p5/core/Math.hpp"
#include "p5/core/Constants.hpp"

#include "p5/data/Specializations.hpp"

namespace p5
{

    class PApplet : public Constants, public Math
    {
    public:
        static std::string ARGS_DENSITY;
        static std::string ARGS_DISPLAY;
        static std::string ARGS_EDITOR_LOCATION;
        static std::string ARGS_EXTERNAL;
        static std::string ARGS_HIDE_STOP;
        static std::string ARGS_LOCATION;
        static std::string ARGS_PRESENT;
        static std::string ARGS_SKETCH_FOLDER;
        static std::string ARGS_STOP_COLOR;
        static std::string ARGS_WINDOW_COLOR;
        static int DEFAULT_HEIGHT;
        static int DEFAULT_WIDTH;
        static std::string EXTERNAL_MOVE;
        static std::string EXTERNAL_STOP;
        static int javaPlatform;
        static std::string javaVersionName;
        static int platform;
        static bool useNativeSelect;

        std::vector<std::string> args;

        int displayHeight;
        int displayWidth;

        bool focused;
        bool finished;
        int frameCount;
        float frameRate;
        int height;
        int width;
        int pixelHeight;
        int pixelWidth;
        int pixelDensity;
        int *pixels;

        char key;
        int keyCode;
        bool keyPressed;
        int mouseButton;
        bool mousePressed;
        int mouseX;
        int mouseY;
        int pmouseX;
        int pmouseY;

        static int second();
        static int minute();
        static int hour();
        static int day();
        static int month();
        static int year();

        // static void debug(java.lang.String msg);
        // static float degrees(float radians);
        // static float radians(float degrees);
        // static void hideMenuBar();

        // static void print(boolean what);
        // static void print(byte what);
        // static void print(char what);
        // static void print(double what);
        // static void print(float what);
        // static void print(int what);
        // static void print(long what);
        // static void print(java.lang.Object... variables);
        // static void print(java.lang.String what);
        // static void printArray(java.lang.Object what);
        // static void println();
        // static void println(boolean what);
        // static void println(byte what);
        // static void println(char what);
        // static void println(double what);
        // static void println(float what);
        // static void println(int what);
        // static void println(long what);
        // static void println(java.lang.Object... variables);
        // static void println(java.lang.Object what);
        // static void println(java.lang.String what);

        // static int blendColor(int c1, int c2, int mode);

        // static java.lang.Process exec(java.lang.String... args);
        // static int exec(StringList stdout, StringList stderr, java.lang.String... args);
        // static java.lang.Process launch(java.lang.String... args);
        // static int lerpColor(int c1, int c2, float amt, int mode);
        // static float mag(float a, float b);
        // static float mag(float a, float b, float c);
        // static void main(java.lang.Class<?> mainClass, java.lang.String... args);
        // static void main(java.lang.String mainClass);
        // static void main(java.lang.String[] args);
        // static void main(java.lang.String mainClass, java.lang.String[] sketchArgs);
        // static boolean parseBoolean(int what);
        // static boolean[] parseBoolean(int[] what);
        // static boolean parseBoolean(java.lang.String what);
        // static boolean[] parseBoolean(java.lang.String[] what);
        // static byte parseByte(boolean what);
        // static byte[] parseByte(boolean[] what);
        // static byte parseByte(char what);
        // static byte[] parseByte(char[] what);
        // static byte parseByte(float what);
        // static byte[] parseByte(float[] what);
        // static byte parseByte(int what);
        // static byte[] parseByte(int[] what);
        // static char parseChar(byte what);
        // static char[] parseChar(byte[] what);
        // static char parseChar(int what);
        // static char[] parseChar(int[] what);
        // static float[] parseFloat(byte[] what);
        // static float parseFloat(int what);
        // static float[] parseFloat(int[] what);
        // static float parseFloat(java.lang.String what);
        // static float[] parseFloat(java.lang.String[] what);
        // static float[] parseFloat(java.lang.String[] what, float missing);
        // static float parseFloat(java.lang.String what, float otherwise);
        // static int parseInt(boolean what);
        // static int[] parseInt(boolean[] what);
        // static int parseInt(byte what);
        // static int[] parseInt(byte[] what);
        // static int parseInt(char what);
        // static int[] parseInt(char[] what);
        // static int parseInt(float what);
        // static int[] parseInt(float[] what);
        // static int parseInt(java.lang.String what);
        // static int[] parseInt(java.lang.String[] what);
        // static int[] parseInt(java.lang.String[] what, int missing);
        // static int parseInt(java.lang.String what, int otherwise);
        // static int shell(StringList stdout, StringList stderr, java.lang.String... args);
        // static void runSketch(java.lang.String[] args, PApplet constructedSketch);
        // static void showDepthWarning(java.lang.String method);
        // static void showDepthWarningXYZ(java.lang.String method);
        // static void showMethodWarning(java.lang.String method);
        // static void showMissingWarning(java.lang.String method);
        // static void showVariationWarning(java.lang.String str);

        // java.awt.Frame frame;
        // PGraphics g;
        // PGraphics recorder;
        
    };

}