#include <iostream>
#include <string>
#define var auto
typedef unsigned char byte;
using namespace std;


    class ByteBuffer
    {
    public:
        byte* data;
        ByteBuffer(int length)
        {
            data = new byte[length];
        }


        string getString(int offset)
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
        void setString(int offset, string value)
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

        int getInt(int offset) const
        {
            int retv = 0;
            byte* ptr = &data[offset];
            {
                int* iptr = (int*)ptr;
                retv = *iptr;
            }
            return retv;
        }
        int& getInt(int offset)
        {
            return (int&) *((int*)&data[offset]);
        }
        void setInt(int offset, int value)
        {
            byte* ptr = &data[offset];
            {
                int* iptr = (int*)ptr;
                *iptr = value;
            }
            return;
        }

        long getLong(int offset) const
        {
            long retv = 0;
            byte* ptr = &data[offset];
            {
                long* iptr = (long*)ptr;
                retv = *iptr;
            }
            return retv;
        }
        long& getLong(int offset)
        {
            return (long&)*((long*)&data[offset]);
        }
        void setLong(int offset, long value)
        {
            byte* ptr = &data[offset];
            {
                long* iptr = (long*)ptr;
                *iptr = value;
            }
            return;
        }

        float getFloat(int offset) const
        {
            float retv = 0;
            byte* ptr = &data[offset];
            {
                float* iptr = (float*)ptr;
                retv = *iptr;
            }
            return retv;
        }
        float& getFloat(int offset)
        {
            return (float&)*((float*)&data[offset]);
        }
        void setFloat(int offset, float value)
        {
            byte* ptr = &data[offset];
            {
                float* iptr = (float*)ptr;
                *iptr = value;
            }
            return;
        }

        double getDouble(int offset) const
        {
            double retv = 0;
            byte* ptr = &data[offset];
            {
                double* iptr = (double*)ptr;
                retv = *iptr;
            }
            return retv;
        }
        double& getDouble(int offset)
        {
            return (double&)*((double*)&data[offset]);
        }
        void setDouble(int offset, double value)
        {
            byte* ptr = &data[offset];
            {
                double* iptr = (double*)ptr;
                *iptr = value;
            }
            return;
        }
        char getChar(int offset) const
        {
            char retv = '\0';
            byte* ptr = &data[offset];
            {
                char* iptr = (char*)ptr;
                retv = *iptr;
            }
            return retv;
        }
        char& getChar(int offset)
        {
            return (char&)*((char*)&data[offset]);
        }
        void setChar(int offset, char value)
        {
            byte* ptr = &data[offset];
            {
                char* iptr = (char*)ptr;
                *iptr = value;
            }
            return;
        }
        bool getBool(int offset) const
        {
            bool retv = false;
            byte* ptr = &data[offset];
            {
                byte* iptr = (byte*)ptr;
                retv = (*iptr == 1);
            }
            return retv;
        }
        byte& getBool(int offset)
        {
            return (byte&)*((byte*)&data[offset]);
        }
        void setBool(int offset, bool value)
        {
            byte* ptr = &data[offset];
            {
                byte* iptr = (byte*)ptr;
                *iptr = (value == true) ? (byte)1 : (byte)0;
            }
            return;
        }

    };



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

