#include <iostream>
#include <string>
#include <msclr/gcroot.h>
#define var auto
typedef unsigned char byte;
typedef unsigned long ulong;
using namespace std;
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

#include "Ref.h"

class ByteBuffer
{
public:
    byte* data;
    ByteBuffer(ulong length);


    string getString(ulong offset);
    void setString(ulong offset, string value);
    int getInt(ulong offset) const;
    int& getInt(ulong offset);
    void setInt(ulong offset, int value);
    long getLong(ulong offset) const;
    long& getLong(ulong offset);
    void setLong(ulong offset, long value);
    float getFloat(ulong offset) const;
    float& getFloat(ulong offset);
    void setFloat(ulong offset, float value);
    double getDouble(ulong offset) const;
    double& getDouble(ulong offset);
    void setDouble(ulong offset, double value);
    char getChar(ulong offset) const;
    char& getChar(ulong offset);
    void setChar(ulong offset, char value);
    bool getBool(ulong offset) const;
    byte& getBool(ulong offset);
    void setBool(ulong offset, bool value);

};

namespace Cpp
{

    public ref class ByteBuffer
    {
    public:
        ::ByteBuffer* m_native;
        ByteBuffer(ulong length);

        //static System::Func<String^, int>^ GetStrLen;
        //static System::Func<String^, int, char>^ IndexStr;

        String^ getString(ulong offset);
        void setString(ulong offset, String^ value);
        int getInt(ulong offset);
        void setInt(ulong offset, int value);
        long getLong(ulong offset);
        void setLong(ulong offset, long value);
        float getFloat(ulong offset);
        void setFloat(ulong offset, float value);
        double getDouble(ulong offset);
        void setDouble(ulong offset, double value);
        char getChar(ulong offset);
        void setChar(ulong offset, char value);
        bool getBool(ulong offset);
        void setBool(ulong offset, bool value);
    };

}
