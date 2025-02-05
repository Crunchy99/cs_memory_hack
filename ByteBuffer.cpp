#include "ByteBuffer.h"


    ByteBuffer::ByteBuffer(int length)
    {
        data = new byte[length];
    }


    string ByteBuffer::getString(int offset)
    {
        string retv = "";
        byte* ptr = &data[offset];
        {
            char* cptr = (char*)ptr;
            int* szptr = (int*)ptr;
            var length = *szptr;
            for (int i = 0; i < length; i++)
            {
                retv += cptr[sizeof(int) + i];
            }
        }
        return retv;
    }
    void ByteBuffer::setString(int offset, string value)
    {
        byte* ptr = &data[offset];
        {
            char* cptr = (char*)ptr;
            int* szptr = (int*)ptr;
            *szptr = value.size();
            for (int i = 0; i < value.size(); i++)
            {
                cptr[sizeof(int) + i] = value[i];
            }
        }
        return;
    }

    int ByteBuffer::getInt(int offset) const
    {
        int retv = 0;
        byte* ptr = &data[offset];
        {
            int* iptr = (int*)ptr;
            retv = *iptr;
        }
        return retv;
    }
    int& ByteBuffer::getInt(int offset)
    {
        return (int&)*((int*)&data[offset]);
    }
    void ByteBuffer::setInt(int offset, int value)
    {
        byte* ptr = &data[offset];
        {
            int* iptr = (int*)ptr;
            *iptr = value;
        }
        return;
    }

    long ByteBuffer::getLong(int offset) const
    {
        long retv = 0;
        byte* ptr = &data[offset];
        {
            long* iptr = (long*)ptr;
            retv = *iptr;
        }
        return retv;
    }
    long& ByteBuffer::getLong(int offset)
    {
        return (long&)*((long*)&data[offset]);
    }
    void ByteBuffer::setLong(int offset, long value)
    {
        byte* ptr = &data[offset];
        {
            long* iptr = (long*)ptr;
            *iptr = value;
        }
        return;
    }

    float ByteBuffer::getFloat(int offset) const
    {
        float retv = 0;
        byte* ptr = &data[offset];
        {
            float* iptr = (float*)ptr;
            retv = *iptr;
        }
        return retv;
    }
    float& ByteBuffer::getFloat(int offset)
    {
        return (float&)*((float*)&data[offset]);
    }
    void ByteBuffer::setFloat(int offset, float value)
    {
        byte* ptr = &data[offset];
        {
            float* iptr = (float*)ptr;
            *iptr = value;
        }
        return;
    }

    double ByteBuffer::getDouble(int offset) const
    {
        double retv = 0;
        byte* ptr = &data[offset];
        {
            double* iptr = (double*)ptr;
            retv = *iptr;
        }
        return retv;
    }
    double& ByteBuffer::getDouble(int offset)
    {
        return (double&)*((double*)&data[offset]);
    }
    void ByteBuffer::setDouble(int offset, double value)
    {
        byte* ptr = &data[offset];
        {
            double* iptr = (double*)ptr;
            *iptr = value;
        }
        return;
    }
    char ByteBuffer::getChar(int offset) const
    {
        char retv = '\0';
        byte* ptr = &data[offset];
        {
            char* iptr = (char*)ptr;
            retv = *iptr;
        }
        return retv;
    }
    char& ByteBuffer::getChar(int offset)
    {
        return (char&)*((char*)&data[offset]);
    }
    void ByteBuffer::setChar(int offset, char value)
    {
        byte* ptr = &data[offset];
        {
            char* iptr = (char*)ptr;
            *iptr = value;
        }
        return;
    }
    bool ByteBuffer::getBool(int offset) const
    {
        bool retv = false;
        byte* ptr = &data[offset];
        {
            byte* iptr = (byte*)ptr;
            retv = (*iptr == 1);
        }
        return retv;
    }
    byte& ByteBuffer::getBool(int offset)
    {
        return (byte&)*((byte*)&data[offset]);
    }
    void ByteBuffer::setBool(int offset, bool value)
    {
        byte* ptr = &data[offset];
        {
            byte* iptr = (byte*)ptr;
            *iptr = (value == true) ? (byte)1 : (byte)0;
        }
        return;
    }



    //-------------------------------------

    Cpp::ByteBuffer::ByteBuffer(int length)
    {
        m_native = new ::ByteBuffer(length);
    }

    String^ Cpp::ByteBuffer::getString(int offset)
    {
        return gcnew String(m_native->getString(offset).c_str());
    }
    void Cpp::ByteBuffer::setString(int offset, String^ value)
    {
        byte* ptr = &m_native->data[offset];
        {
            char* cptr = (char*)ptr;
            int* szptr = (int*)ptr;
            *szptr = GetStrLen(value);
            for (int i = 0; i < GetStrLen(value); i++)
            {
                cptr[sizeof(int) + i] = IndexStr(value, i);
            }
        }
        return;
    }
    int Cpp::ByteBuffer::getInt(int offset)
    {
        return m_native->getInt(offset);
    }
    void Cpp::ByteBuffer::setInt(int offset, int value)
    {
        m_native->setInt(offset, value);
    }
    long Cpp::ByteBuffer::getLong(int offset)
    {
        return m_native->getLong(offset);
    }
    void Cpp::ByteBuffer::setLong(int offset, long value)
    {
        m_native->setLong(offset, value);
    }
    float Cpp::ByteBuffer::getFloat(int offset)
    {
        return m_native->getFloat(offset);
    }
    void Cpp::ByteBuffer::setFloat(int offset, float value)
    {
        m_native->setFloat(offset, value);
    }
    double Cpp::ByteBuffer::getDouble(int offset)
    {
        return m_native->getDouble(offset);
    }
    void Cpp::ByteBuffer::setDouble(int offset, double value)
    {
        m_native->setDouble(offset, value);
    }
    char Cpp::ByteBuffer::getChar(int offset)
    {
        return m_native->getChar(offset);
    }
    void Cpp::ByteBuffer::setChar(int offset, char value)
    {
        m_native->setChar(offset, value);
    }
    bool Cpp::ByteBuffer::getBool(int offset)
    {
        return m_native->getBool(offset);
    }
    void Cpp::ByteBuffer::setBool(int offset, bool value)
    {
        m_native->setBool(offset, value);
    }

