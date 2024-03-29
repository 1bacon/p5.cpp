

namespace p5
{
    class Arrays
    {
    public:
        static char[] append(char[] array, char value);
        static float[] append(float[] array, float value);
        static int[] append(int[] array, int value);
        static java.lang.Object append(java.lang.Object array, java.lang.Object value);
        static std::string[] append(std::string[] array, std::string value);
        static void arraycopy(java.lang.Object src, int srcPosition, java.lang.Object dst, int dstPosition, int length);
        static void arrayCopy(java.lang.Object src, int srcPosition, java.lang.Object dst, int dstPosition, int length);
        static void arraycopy(java.lang.Object src, java.lang.Object dst);
        static void arrayCopy(java.lang.Object src, java.lang.Object dst);
        static void arraycopy(java.lang.Object src, java.lang.Object dst, int length);
        static void arrayCopy(java.lang.Object src, java.lang.Object dst, int length);
        static bool[] concat(bool[] a, bool[] b);
        static char[] concat(char[] a, char[] b);
        static float[] concat(float[] a, float[] b);
        static int[] concat(int[] a, int[] b);
        static java.lang.Object concat(java.lang.Object a, java.lang.Object b);
        static std::string[] concat(std::string[] a, std::string[] b);
        static bool[] expand(bool[] list);
        static bool[] expand(bool[] list, int newSize);
        static char[] expand(char[] list);
        static char[] expand(char[] list, int newSize);
        static double[] expand(double[] list);
        static double[] expand(double[] list, int newSize);
        static float[] expand(float[] list);
        static float[] expand(float[] list, int newSize);
        static int[] expand(int[] list);
        static int[] expand(int[] list, int newSize);
        static long[] expand(long[] list);
        static long[] expand(long[] list, int newSize);
        static java.lang.Object expand(java.lang.Object array);
        static java.lang.Object expand(java.lang.Object list, int newSize);
        static std::string[] expand(std::string[] list);
        static std::string[] expand(std::string[] list, int newSize);
        static bool[] reverse(bool[] list);
        static byte[] reverse(byte[] list);
        static char[] reverse(char[] list);
        static float[] reverse(float[] list);
        static int[] reverse(int[] list);
        static java.lang.Object reverse(java.lang.Object list);
        static std::string[] reverse(std::string[] list);
        static bool[] shorten(bool[] list);
        static char[] shorten(char[] list);
        static float[] shorten(float[] list);
        static int[] shorten(int[] list);
        static java.lang.Object shorten(java.lang.Object list);
        static std::string[] shorten(std::string[] list);
        static char[] sort(char[] list);
        static char[] sort(char[] list, int count);
        static float[] sort(float[] list);
        static float[] sort(float[] list, int count);
        static int[] sort(int[] list);
        static int[] sort(int[] list, int count);
        static std::string[] sort(std::string[] list);
        static std::string[] sort(std::string[] list, int count);
        static bool[] splice(bool[] list, bool[] value, int index);
        static bool[] splice(bool[] list, bool value, int index);
        static char[] splice(char[] list, char[] value, int index);
        static char[] splice(char[] list, char value, int index);
        static float[] splice(float[] list, float[] value, int index);
        static float[] splice(float[] list, float value, int index);
        static int[] splice(int[] list, int[] value, int index);
        static int[] splice(int[] list, int value, int index);
        static java.lang.Object splice(java.lang.Object list, java.lang.Object value, int index);
        static std::string[] splice(std::string[] list, std::string[] value, int index);
        static std::string[] splice(std::string[] list, std::string value, int index);
        static std::string[] split(std::string value, char delim);
        static std::string[] split(std::string value, std::string delim);
        static bool[] subset(bool[] list, int start);
        static bool[] subset(bool[] list, int start, int count);
        static char[] subset(char[] list, int start);
        static char[] subset(char[] list, int start, int count);
        static double[] subset(double[] list, int start);
        static double[] subset(double[] list, int start, int count);
        static float[] subset(float[] list, int start);
        static float[] subset(float[] list, int start, int count);
        static int[] subset(int[] list, int start);
        static int[] subset(int[] list, int start, int count);
        static long[] subset(long[] list, int start);
        static long[] subset(long[] list, int start, int count);
        static java.lang.Object subset(java.lang.Object list, int start);
        static java.lang.Object subset(java.lang.Object list, int start, int count);
        static std::string[] subset(std::string[] list, int start);
        static std::string[] subset(std::string[] list, int start, int count);
    };
}