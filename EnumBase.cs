using System;
using System.Linq;
using System.Collections.Generic;
using System.IO;

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
