#pragma once

#include <string>
#include <vector>

namespace p5
{
    class Files
    {
    public:
        static std::string checkExtension(std::string filename);
        static java.io.InputStream createInput(java.io.File file);
        static java.io.OutputStream createOutput(java.io.File file);
        static void createPath(java.io.File file);
        static void createPath(java.lang.String path);
        static java.io.BufferedReader createReader(java.io.File file);
        static java.io.BufferedReader createReader(java.io.InputStream input);
        static java.io.PrintWriter createWriter(java.io.File file);
        static java.io.PrintWriter createWriter(java.io.OutputStream output);
        static java.io.File desktopFile(java.lang.String what);
        static java.lang.String desktopPath(java.lang.String what);
        static java.lang.String getExtension(java.lang.String filename);
        static java.io.File[] listFiles(java.io.File base, java.lang.String... options);
        static byte[] loadBytes(java.io.File file);
        static byte[] loadBytes(java.io.InputStream input);
        static JSONArray loadJSONArray(java.io.File file);
        static JSONObject loadJSONObject(java.io.File file);
        static java.lang.String[] loadStrings(java.io.BufferedReader reader);
        static java.lang.String[] loadStrings(java.io.File file);
        static java.lang.String[] loadStrings(java.io.InputStream input);
        static void saveBytes(java.io.File file, byte[] data);
        static void saveBytes(java.io.OutputStream output, byte[] data);
        static boolean saveStream(java.io.File target, java.io.InputStream source);
        static void saveStream(java.io.OutputStream target, java.io.InputStream source);
        static void saveStrings(java.io.File file, java.lang.String[] data);
        static void saveStrings(java.io.OutputStream output, java.lang.String[] data);
        static void selectFolder(java.lang.String prompt, java.lang.String callbackMethod, java.io.File defaultSelection, java.lang.Object callbackObject, java.awt.Frame parentFrame);
        static void selectFolder(java.lang.String prompt, java.lang.String callbackMethod, java.io.File defaultSelection, java.lang.Object callbackObject, java.awt.Frame parentFrame, PApplet sketch);
        static void selectInput(java.lang.String prompt, java.lang.String callbackMethod, java.io.File file, java.lang.Object callbackObject, java.awt.Frame parent);
        static void selectInput(java.lang.String prompt, java.lang.String callbackMethod, java.io.File file, java.lang.Object callbackObject, java.awt.Frame parent, PApplet sketch);
        static void selectOutput(java.lang.String prompt, java.lang.String callbackMethod, java.io.File file, java.lang.Object callbackObject, java.awt.Frame parent);
        static void selectOutput(java.lang.String prompt, java.lang.String callbackMethod, java.io.File file, java.lang.Object callbackObject, java.awt.Frame parent, PApplet sketch);

    }
}