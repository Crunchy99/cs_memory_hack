#include "ByteBuffer.h"


    ByteBuffer::ByteBuffer(long length)
    {
        data = new byte[length];
    }


    string ByteBuffer::getString(long offset)
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
    void ByteBuffer::setString(long offset, string value)
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

    int ByteBuffer::getInt(long offset) const
    {
        int retv = 0;
        byte* ptr = &data[offset];
        {
            int* iptr = (int*)ptr;
            retv = *iptr;
        }
        return retv;
    }
    int& ByteBuffer::getInt(long offset)
    {
        return (int&)*((int*)&data[offset]);
    }
    void ByteBuffer::setInt(long offset, int value)
    {
        byte* ptr = &data[offset];
        {
            int* iptr = (int*)ptr;
            *iptr = value;
        }
        return;
    }

    long ByteBuffer::getLong(long offset) const
    {
        long retv = 0;
        byte* ptr = &data[offset];
        {
            long* iptr = (long*)ptr;
            retv = *iptr;
        }
        return retv;
    }
    long& ByteBuffer::getLong(long offset)
    {
        return (long&)*((long*)&data[offset]);
    }
    void ByteBuffer::setLong(long offset, long value)
    {
        byte* ptr = &data[offset];
        {
            long* iptr = (long*)ptr;
            *iptr = value;
        }
        return;
    }

    float ByteBuffer::getFloat(long offset) const
    {
        float retv = 0;
        byte* ptr = &data[offset];
        {
            float* iptr = (float*)ptr;
            retv = *iptr;
        }
        return retv;
    }
    float& ByteBuffer::getFloat(long offset)
    {
        return (float&)*((float*)&data[offset]);
    }
    void ByteBuffer::setFloat(long offset, float value)
    {
        byte* ptr = &data[offset];
        {
            float* iptr = (float*)ptr;
            *iptr = value;
        }
        return;
    }

    double ByteBuffer::getDouble(long offset) const
    {
        double retv = 0;
        byte* ptr = &data[offset];
        {
            double* iptr = (double*)ptr;
            retv = *iptr;
        }
        return retv;
    }
    double& ByteBuffer::getDouble(long offset)
    {
        return (double&)*((double*)&data[offset]);
    }
    void ByteBuffer::setDouble(long offset, double value)
    {
        byte* ptr = &data[offset];
        {
            double* iptr = (double*)ptr;
            *iptr = value;
        }
        return;
    }
    char ByteBuffer::getChar(long offset) const
    {
        char retv = '\0';
        byte* ptr = &data[offset];
        {
            char* iptr = (char*)ptr;
            retv = *iptr;
        }
        return retv;
    }
    char& ByteBuffer::getChar(long offset)
    {
        return (char&)*((char*)&data[offset]);
    }
    void ByteBuffer::setChar(long offset, char value)
    {
        byte* ptr = &data[offset];
        {
            char* iptr = (char*)ptr;
            *iptr = value;
        }
        return;
    }
    bool ByteBuffer::getBool(long offset) const
    {
        bool retv = false;
        byte* ptr = &data[offset];
        {
            byte* iptr = (byte*)ptr;
            retv = (*iptr == 1);
        }
        return retv;
    }
    byte& ByteBuffer::getBool(long offset)
    {
        return (byte&)*((byte*)&data[offset]);
    }
    void ByteBuffer::setBool(long offset, bool value)
    {
        byte* ptr = &data[offset];
        {
            byte* iptr = (byte*)ptr;
            *iptr = (value == true) ? (byte)1 : (byte)0;
        }
        return;
    }



    //-------------------------------------

    Cpp::ByteBuffer::ByteBuffer(long length)
    {
        m_native = new ::ByteBuffer(length);
    }

    String^ Cpp::ByteBuffer::getString(long offset)
    {
        return gcnew String(m_native->getString(offset).c_str());
    }
    void Cpp::ByteBuffer::setString(long offset, String^ value)
    {
        byte* ptr = &m_native->data[offset];
        {
            char* cptr = (char*)ptr;
            int* szptr = (int*)ptr;
            *szptr = (*value).Length;
            for (int i = 0; i < (*value).Length; i++)
            {
                cptr[sizeof(int) + i] = (*value)[i];
            }
        }
        return;
    }
    int Cpp::ByteBuffer::getInt(long offset)
    {
        return m_native->getInt(offset);
    }
    void Cpp::ByteBuffer::setInt(long offset, int value)
    {
        m_native->setInt(offset, value);
    }
    long Cpp::ByteBuffer::getLong(long offset)
    {
        return m_native->getLong(offset);
    }
    void Cpp::ByteBuffer::setLong(long offset, long value)
    {
        m_native->setLong(offset, value);
    }
    float Cpp::ByteBuffer::getFloat(long offset)
    {
        return m_native->getFloat(offset);
    }
    void Cpp::ByteBuffer::setFloat(long offset, float value)
    {
        m_native->setFloat(offset, value);
    }
    double Cpp::ByteBuffer::getDouble(long offset)
    {
        return m_native->getDouble(offset);
    }
    void Cpp::ByteBuffer::setDouble(long offset, double value)
    {
        m_native->setDouble(offset, value);
    }
    char Cpp::ByteBuffer::getChar(long offset)
    {
        return m_native->getChar(offset);
    }
    void Cpp::ByteBuffer::setChar(long offset, char value)
    {
        m_native->setChar(offset, value);
    }
    bool Cpp::ByteBuffer::getBool(long offset)
    {
        return m_native->getBool(offset);
    }
    void Cpp::ByteBuffer::setBool(long offset, bool value)
    {
        m_native->setBool(offset, value);
    }


/*
int main()
{
    var byteBuffer = ByteBuffer(10 * 1000);
    byteBuffer.setInt(128, 7);

    int& intv = byteBuffer.getInt(128);
    if (!(intv == 7))
        std::cout << "failed.";

    if (!(byteBuffer.getInt(128) == 7))
        std::cout << "failed.";
    byteBuffer.setString(256, "hello there.");
    if (byteBuffer.getString(256) == "hello there.");
    std::cout << "succeeded.";

 }

 //C# test
 {
    var byteBuffer = new ByteBuffer(10 * 1000);
    byteBuffer.setInt(128, 7);
    Debug.Assert(byteBuffer.getInt(128) == 7);
    byteBuffer.setString(256, "hello there.");
    Debug.Assert(byteBuffer.getString(256) == "hello there.");
}
*/
