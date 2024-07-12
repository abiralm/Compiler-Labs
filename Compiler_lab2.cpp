#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool is_delimiter(char character)
{
   if (character == ' ' || character == '+' || character == '-' || character == '*' ||
       character == '/' || character == ',' || character == ';' || character == '>' ||
       character == '<' || character == '=' || character == '(' || character == ')' ||
       character == '[' || character == ']' || character == '{' || character == '}')
       return (true);
   return (false);
}

bool is_operator(char character)
{
   if (character == '+' || character == '-' || character == '*' ||
       character == '/' || character == '>' || character == '<' ||
       character == '=')
       return (true);
   return (false);
}

bool valid_identifier(char* string)
{
   if (string[0] == '0' || string[0] == '1' || string[0] == '2' ||
       string[0] == '3' || string[0] == '4' || string[0] == '5' ||
       string[0] == '6' || string[0] == '7' || string[0] == '8' ||
       string[0] == '9' || is_delimiter(string[0]) == true)
       return (false);
   return (true);
}

bool is_keyword(char* string)
{
   if (!strcmp(string, "if") || !strcmp(string, "else") ||
       !strcmp(string, "while") || !strcmp(string, "do") ||
       !strcmp(string, "break") ||
       !strcmp(string, "continue") || !strcmp(string, "int")
       || !strcmp(string, "double") || !strcmp(string, "float")
       || !strcmp(string, "return") || !strcmp(string, "char")
       || !strcmp(string, "case") || !strcmp(string, "char")
       || !strcmp(string, "sizeof") || !strcmp(string, "long")
       || !strcmp(string, "short") || !strcmp(string, "typedef")
       || !strcmp(string, "switch") || !strcmp(string, "unsigned")
       || !strcmp(string, "void") || !strcmp(string, "static")
       || !strcmp(string, "struct") || !strcmp(string, "goto"))
       return (true);
   return (false);
}

bool is_integer(char* string)
{
   int i, len = strlen(string);

   if (len == 0)
       return (false);
   for (i = 0; i < len; i++) {
       if (string[i] != '0' && string[i] != '1' && string[i] != '2'
           && string[i] != '3' && string[i] != '4' && string[i] != '5'
           && string[i] != '6' && string[i] != '7' && string[i] != '8'
           && string[i] != '9' || (string[i] == '-' && i > 0))
           return (false);
   }
   return (true);
}

bool is_real_number(char* string)
{
   int i, len = strlen(string);
   bool has_decimal = false;

   if (len == 0)
       return (false);
   for (i = 0; i < len; i++) {
       if (string[i] != '0' && string[i] != '1' && string[i] != '2'
           && string[i] != '3' && string[i] != '4' && string[i] != '5'
           && string[i] != '6' && string[i] != '7' && string[i] != '8'
           && string[i] != '9' && string[i] != '.' ||
           (string[i] == '-' && i > 0))
           return (false);
       if (string[i] == '.')
           has_decimal = true;
   }
   return (has_decimal);
}

char* get_substring(char* string, int left, int right)
{
   int i;
   char* sub_string = (char*)malloc(
               sizeof(char) * (right - left + 2));

   for (i = left; i <= right; i++)
       sub_string[i - left] = string[i];
   sub_string[right - left + 1] = '\0';
   return (sub_string);
}

void analyze_string(char* string)
{
   int left = 0, right = 0;
   int len = strlen(string);

   while (right <= len && left <= right) {
       if (is_delimiter(string[right]) == false)
           right++;

       if (is_delimiter(string[right]) == true && left == right) {
           if (is_operator(string[right]) == true)
               printf("operator:'%c'\n", string[right]);

           right++;
           left = right;
       } else if (is_delimiter(string[right]) == true && left != right
               || (right == len && left != right)) {
           char* sub_string = get_substring(string, left, right - 1);

           if (is_keyword(sub_string) == true)
               printf("keyword:'%s'\n", sub_string);

           else if (is_integer(sub_string) == true)
               printf("integer:'%s'\n", sub_string);

           else if (is_real_number(sub_string) == true)
               printf("real Number:'%s'\n", sub_string);

           else if (valid_identifier(sub_string) == true
                   && is_delimiter(string[right - 1]) == false)
               printf("identifier:'%s'\n", sub_string);

           else if (valid_identifier(sub_string) == false
                   && is_delimiter(string[right - 1]) == false)
               printf("invalid:'%s' \n", sub_string);
           left = right;
       }
   }
   return;
}

int main()
{
   char str[100] = "(for i=0;i<=5;i++)";
   printf("Expression: %s\n\n", str);
   analyze_string(str); 

   return (0);
}

