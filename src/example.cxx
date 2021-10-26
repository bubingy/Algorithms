#include "print.hpp"
#include "ExternalSort.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	const char* input_file_path1 = "D:\\Workspace\\py_test\\1.txt";
	const char* input_file_path2 = "D:\\Workspace\\py_test\\2.txt";
	const char* output_file_path = "D:\\Workspace\\py_test\\output.txt";
	externalsort::Merge(input_file_path1, input_file_path2, output_file_path);
}