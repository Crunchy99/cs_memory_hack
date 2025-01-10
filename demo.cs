using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SharpDX.Direct3D9;

namespace CsMemoryHack2
{

    public class ByteBuffer
    {
        public byte[] data;
        public ByteBuffer(int length)
        {
            data = new byte[length];
        }


        public string getString(int offset)
        {
            string retv = "";
            unsafe
            {
                fixed (byte* ptr = &data[offset])
                {
                    char* cptr = (char*)ptr;
                    int* szptr = (int*)ptr;
                    var length = *szptr;
                    for (int i = 0; i < length; i++)
                    {
                        retv += cptr[sizeof(int) + i];
                    }
                }
            }
            return retv;
        }
        public void setString(int offset, string value)
        {
            unsafe
            {
                fixed (byte* ptr = &data[offset])
                {
                    char* cptr = (char*)ptr;
                    int* szptr = (int*)ptr;
                    *szptr = value.Length;
                    for (int i=0; i<value.Length; i++)
                    {
                        cptr[sizeof(int) + i] = value[i];
                    }
                }
            }
            return;
        }

        public int getInt(int offset)
        {
            int retv = 0;
            unsafe
            {
                fixed (byte* ptr = &data[offset])
                {
                    int* iptr = (int*)ptr;
                    retv = *iptr;
                }
            }
            return retv;
        }
        public void setInt(int offset, int value)
        {
            unsafe
            {
                fixed (byte* ptr = &data[offset])
                {
                    int* iptr = (int*)ptr;
                    *iptr = value;
                }
            }
            return;
        }

        public long getLong(int offset)
        {
            long retv = 0;
            unsafe
            {
                fixed (byte* ptr = &data[offset])
                {
                    long* iptr = (long*)ptr;
                    retv = *iptr;
                }
            }
            return retv;
        }
        public void setLong(int offset, long value)
        {
            unsafe
            {
                fixed (byte* ptr = &data[offset])
                {
                    long* iptr = (long*)ptr;
                    *iptr = value;
                }
            }
            return;
        }

        public float getFloat(int offset)
        {
            float retv = 0;
            unsafe
            {
                fixed (byte* ptr = &data[offset])
                {
                    float* iptr = (float*)ptr;
                    retv = *iptr;
                }
            }
            return retv;
        }
        public void setFloat(int offset, float value)
        {
            unsafe
            {
                fixed (byte* ptr = &data[offset])
                {
                    float* iptr = (float*)ptr;
                    *iptr = value;
                }
            }
            return;
        }

        public double getDouble(int offset)
        {
            double retv = 0;
            unsafe
            {
                fixed (byte* ptr = &data[offset])
                {
                    double* iptr = (double*)ptr;
                    retv = *iptr;
                }
            }
            return retv;
        }
        public void setDouble(int offset, double value)
        {
            unsafe
            {
                fixed (byte* ptr = &data[offset])
                {
                    double* iptr = (double*)ptr;
                    *iptr = value;
                }
            }
            return;
        }
        public char getChar(int offset)
        {
            char retv = default(char);
            unsafe
            {
                fixed (byte* ptr = &data[offset])
                {
                    char* iptr = (char*)ptr;
                    retv = *iptr;
                }
            }
            return retv;
        }
        public void setChar(int offset, char value)
        {
            unsafe
            {
                fixed (byte* ptr = &data[offset])
                {
                    char* iptr = (char*)ptr;
                    *iptr = value;
                }
            }
            return;
        }
        public bool getBool(int offset)
        {
            bool retv = false;
            unsafe
            {
                fixed (byte* ptr = &data[offset])
                {
                    byte* iptr = (byte*)ptr;
                    retv = (*iptr == 1);
                }
            }
            return retv;
        }
        public void setBool(int offset, bool value)
        {
            unsafe
            {
                fixed (byte* ptr = &data[offset])
                {
                    byte* iptr = (byte*)ptr;
                    *iptr = (value == true) ? (byte)1 : (byte)0;
                }
            }
            return;
        }

    }
}


//in Main()
var byteBuffer = new ByteBuffer(10 * 1000);
byteBuffer.setInt(128, 7);
Debug.Assert(byteBuffer.getInt(128) == 7);
byteBuffer.setString(256, "hello there.");
Debug.Assert(byteBuffer.getString(256) == "hello there.");
