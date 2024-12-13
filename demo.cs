            //Write animation data
 			
            Quaternion[] quaternions = new Quaternion[100];
            for(int i=0; i<100; i += 4)
            {
            	quaternions[i + 0].X = i + 1;
            	quaternions[i + 1].X = i + 2;
            	quaternions[i + 2].X = i + 3;
            	quaternions[i + 3].X = i + 4;
            }
            
            byte[] bytes = new byte[100 * sizeof(float)*4];
            int byteIndex = -1;
            for(int i=0; i<100; i++)
            {
            	var xb = BitConverter.GetBytes(quaternions[i].X);
            	bytes[++byteIndex] = xb[0];
            	bytes[++byteIndex] = xb[1];
            	bytes[++byteIndex] = xb[2];
            	bytes[++byteIndex] = xb[3];
            	var yb = BitConverter.GetBytes(quaternions[i].Y);
            	bytes[++byteIndex] = yb[0];
            	bytes[++byteIndex] = yb[1];
            	bytes[++byteIndex] = yb[2];
            	bytes[++byteIndex] = yb[3];
            	var zb = BitConverter.GetBytes(quaternions[i].Z);
            	bytes[++byteIndex] = zb[0];
            	bytes[++byteIndex] = zb[1];
            	bytes[++byteIndex] = zb[2];
            	bytes[++byteIndex] = zb[3];
            	var wb = BitConverter.GetBytes(quaternions[i].W);
            	bytes[++byteIndex] = wb[0];
            	bytes[++byteIndex] = wb[1];
            	bytes[++byteIndex] = wb[2];
            	bytes[++byteIndex] = wb[3];
            }
            File.WriteAllBytes(@"out.bin", bytes);
            
            
            
            
            //Pull values from byte buffer at runtime
           	byte[] qbytes = File.ReadAllBytes(@"out.bin");
           	Quaternion static_retvalue_on_getter = new Quaternion();
           	int index = 99;
           	unsafe
           	{
           		fixed(byte* bPtr = &qbytes[index * 16])
           		{
           			Quaternion* xp = (Quaternion*)(bPtr);
           			static_retvalue_on_getter.X = xp->X;
           			static_retvalue_on_getter.Y = xp->Y;
           			static_retvalue_on_getter.Z = xp->Z;
           			static_retvalue_on_getter.W = xp->W;
           		}
           	}
           	Debug.Assert(static_retvalue_on_getter.X == 100);
           	//return static_retvalue_on_getter;




            
