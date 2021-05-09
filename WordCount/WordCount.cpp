
#include<stdio.h>
#include<cstdio>
#include<iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define MAX_NUM 1024

int main(int argc, char* argv[])
{   
	//缓冲区
    char buf[MAX_NUM]; 
	//文件指针
    FILE* fp; 
	//行字符个数
    int len;             
	int flag = 0;
	int total = 0;
	if (argc != 3) {
		printf("请输入正确的参数!");
		return 0;
	}
	for (int i = 0; i < 2; i++) {
		if (argv[1][0] == '-' && flag == 0 && i == 0) {
			flag = 1;
		}
		if (argv[1][1] == 'c' && flag == 1) {
			if ((fp = fopen(argv[2], "r")) == NULL)
			{
				perror("fail to read");
				exit(1);
			}
			//文件读取结束或出错则退出
			while (!feof(fp) && !ferror(fp)) {
				//每次读取一行或者MAX_NUM个字符
				fgets(buf, MAX_NUM, fp);
				len = strlen(buf);
				if (buf[len - 1] == '\n') {
					//去掉换行符在输出
					buf[len - 1] = '\0'; 
					len--;
				}
				//消除空白行
				if (len == 0) continue;
				total += len;
			}
			printf("文本中的字符数为：%d \n", total);
			break;
		}
		else if (argv[1][1] == 'w' && flag == 1) {
			if ((fp = fopen(argv[2], "r")) == NULL)
			{
				perror("fail to read");
				exit(1);
			}
			//文件读取结束或出错则退出
			while (!feof(fp) && !ferror(fp)) {
				if (fgets(buf, MAX_NUM, fp) != NULL) {
					len = strlen(buf);
					total++;
					for (i = 0; i < len - 1; i++) {
						if (buf[i] == ' ' || buf[i] == ',') {
							total++;
						}

					}
				}

			}
			printf("文本中的单词数为：%d \n", total);
		}

	}
	return 0;
}
