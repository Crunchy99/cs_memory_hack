using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CsMemoryHack2
{

    public class ByteBuffer
    {
        public byte[] data;
        public ByteBuffer(int length)
        {
            data = new byte[length];
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


    }
}
