#include <iostream>
#include <string>
#include <msclr/gcroot.h>
#define var auto
typedef unsigned char byte;
using namespace std;
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;


class ByteBuffer
{
public:
    byte* data;
    ByteBuffer(int length);

    string getString(int offset);
    void setString(int offset, string value);
    int getInt(int offset) const;
    int& getInt(int offset);
    void setInt(int offset, int value);
    long getLong(int offset) const;
    long& getLong(int offset);
    void setLong(int offset, long value);
    float getFloat(int offset) const;
    float& getFloat(int offset);
    void setFloat(int offset, float value);
    double getDouble(int offset) const;
    double& getDouble(int offset);
    void setDouble(int offset, double value);
    char getChar(int offset) const;
    char& getChar(int offset);
    void setChar(int offset, char value);
    bool getBool(int offset) const;
    byte& getBool(int offset);
    void setBool(int offset, bool value);

};

namespace Cpp
{

    public ref class ByteBuffer
    {
    public:
        ::ByteBuffer* m_native;
        ByteBuffer(int length);

        static System::Func<String^, int>^ GetStrLen;
        static System::Func<String^, int, char>^ IndexStr;

        String^ getString(int offset);
        void setString(int offset, String^ value);
        int getInt(int offset);
        void setInt(int offset, int value);
        long getLong(int offset);
        void setLong(int offset, long value);
        float getFloat(int offset);
        void setFloat(int offset, float value);
        double getDouble(int offset);
        void setDouble(int offset, double value);
        char getChar(int offset);
        void setChar(int offset, char value);
        bool getBool(int offset);
        void setBool(int offset, bool value);
    };

}
