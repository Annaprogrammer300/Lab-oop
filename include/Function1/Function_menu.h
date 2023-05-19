#pragma once

#include <Function1/Function1.h>

#include <iostream>
#include <conio.h>
#include <cstdio>
#include <memory>
#include <vector>

namespace menu
{
	void text_menu();
	int get_key();
	function::FunctionPtr create_function();
}