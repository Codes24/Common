c sentinel là 1 hình thức truyền tham số cho hàm mà không qui định cụ thể bao nhiêu tham số

khai báo	
	void function(const char* arg, ... ) __attribute__ ((sentinel));
	void function(const char* arg, ... )
	{
		
	}

gọi hàm
	function(arg1, arg2, ... , NULL);