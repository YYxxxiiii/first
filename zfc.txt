#include <stdio.h>
#include <string.h>
void reverse(char* start, char* end){
while(start < end){
char temp = *start;
*start = *end;
*end = temp;
start++;
end--;
}
} int main(){
char input[100];
// 注意不能使用scanf，scanf遇到空格，一次输入接收就结束了
gets(input);
// 翻转整个句子
reverse(input, input + strlen(input) - 1);
// 翻转单词
char* start = input;
while(*start){
char *end = start;
while(*end != ' ' && *end)
end++;
reverse(start, end-1);
if(*end)
start = end + 1;
else
start = end;
} p
rintf("%s", input);
return 0;
}
