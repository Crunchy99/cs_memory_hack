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
    ByteBuffer(long length);

    string getString(long offset);
    void setString(long offset, string value);
    int getInt(long offset) const;
    int& getInt(long offset);
    void setInt(long offset, int value);
    long getLong(long offset) const;
    long& getLong(long offset);
    void setLong(long offset, long value);
    float getFloat(long offset) const;
    float& getFloat(long offset);
    void setFloat(long offset, float value);
    double getDouble(long offset) const;
    double& getDouble(long offset);
    void setDouble(long offset, double value);
    char getChar(long offset) const;
    char& getChar(long offset);
    void setChar(long offset, char value);
    bool getBool(long offset) const;
    byte& getBool(long offset);
    void setBool(long offset, bool value);

};

namespace Cpp
{

    public ref class ByteBuffer
    {
    public:
        ::ByteBuffer* m_native;
        ByteBuffer(long length);

        //static System::Func<String^, int>^ GetStrLen;
        //static System::Func<String^, int, char>^ IndexStr;

        String^ getString(long offset);
        void setString(long offset, String^ value);
        int getInt(long offset);
        void setInt(long offset, int value);
        long getLong(long offset);
        void setLong(long offset, long value);
        float getFloat(long offset);
        void setFloat(long offset, float value);
        double getDouble(long offset);
        void setDouble(long offset, double value);
        char getChar(long offset);
        void setChar(long offset, char value);
        bool getBool(long offset);
        void setBool(long offset, bool value);
    };

}
