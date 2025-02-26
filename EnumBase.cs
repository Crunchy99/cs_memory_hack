using System;
using System.Linq;
using System.Collections.Generic;
using System.IO;
using System.Reflection;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using BEPUphysics;
using BEPUphysicsDemos;
using BEPUphysicsDrawer;
using BEPUutilities;
using BEPUutilities.Threading;
using Matrix = Microsoft.Xna.Framework.Matrix;
using BMatrix = BEPUutilities.Matrix;
using Vector2 = Microsoft.Xna.Framework.Vector2;
using Vector3 = Microsoft.Xna.Framework.Vector3;
using BVector3 = BEPUutilities.Vector3;
using SpriteFontPlus;
using Collada141;
using BEPUphysicsDemos.AlternateMovement;
using BQuaternion = BEPUutilities.Quaternion;
using Quaternion = Microsoft.Xna.Framework.Quaternion;

namespace game1
{
	public static class ext_enums
	{
		public static bool hasFlag(this int _int, int flag){ return (_int & flag) == flag; }
		public static bool hasFlag(this long _long, long flag){ return (_long & flag) == flag; }
	}
	
	public partial class Game1
	{
		public class EnumBase32<T>
		{
			public int value;
			public static int _currShift = -1;
			public static int next() { return 1 << ++_currShift; }
		}
		public class EnumBase64<T>
		{
			public long value;
			public static int _currShift = -1;
			public static long next() { return 1L << ++_currShift; }
		}
		
		public class TestEnum: EnumBase32<TestEnum>
		{
			public static int first = next();
			public static int second = next();
			public static int third = next();
			
			public static void Test()
			{
	           	var item1 = TestEnum.first | TestEnum.second;
	           	var item2 = TestEnum.second;
	           	if(item1 == item2)
	           		throw new Exception("failed");
	           	if(!item1.hasFlag(TestEnum.second))
	           		throw new Exception("failed");
			}
		}
		
	}
}
