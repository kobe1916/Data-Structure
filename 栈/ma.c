#include <stdio.h>  
  2 #include <stdlib.h>  
  3 #include <time.h>  
  4   
  5 #define X 5  //定义棋盘。为测试方便，用5格棋盘。8格棋盘的时间复杂度，真的伤不起啊……期待更好的算法  
  6 #define Y 5  
  7   
  8 void print_chess();  
  9 int next(int *x,int *y,int step);  
 10 int traverse(int x,int y,int count);  
 11 int traverse_chess(int x,int y,int tag);  
 12   
 13 int chess[X][Y]; //棋盘  
 14   
 15 int main23()  
 16 {  
 17     clock_t start,end; //记录一下程序耗时  
 18     int i,j;  
 19     //初始化棋盘  
 20     for(i=0;i<X;i++)  
 21     {  
 22         for(j=0;j<Y;j++)  
 23         {  
 24             chess[i][j]=0;  
 25         }  
 26     }  
 27     start=clock();  
 28   
 29     //方法一  
 30     chess[2][0]=1;  
 31     int result=traverse(2,0,2);  
 32   
 33     //方法二  
 34     //int result=traverse_chess(2,0,1); //也可以使用这个方法  
 35   
 36     end=clock();  
 37     if(1==result)  
 38     {  
 39         printf("ok\n");  
 40         print_chess();  
 41         printf("共耗时:%f\n",(double)(end-start)/CLOCKS_PER_SEC);  
 42     }  
 43     else  
 44     {  
 45         printf("此路不通，马儿无法踏遍所有棋格！\n");  
 46     }  
 47     return 0;  
 48 }  
 49   
 50 /* 
 51 判断下一个结点位置是否可用 
 52 当前结点位置(x,y) 
 53 step:下一个结点位置编号 
 54 */  
 55 int next(int *x,int *y,int step)  
 56 {  
 57    // printf("%d\n",step);  
 58     switch(step)  
 59     {  
 60         case 0:  
 61             if(*y+2<=Y-1 && *x-1>=0 && chess[*x-1][*y+2]==0)  
 62             {  
 63                 *y+=2;  
 64                 *x-=1;  
 65                 return 1;  
 66             }  
 67             break;  
 68         case 1:  
 69             if(*y+2<=Y-1 && *x+1<=X-1 && chess[*x+1][*y+2]==0)  
 70             {  
 71                 *y+=2;  
 72                 *x+=1;  
 73                 return 1;  
 74             }  
 75             break;  
 76         case 2:  
 77             if(*y+1<=Y-1 && *x+2<=X-1 && chess[*x+2][*y+1]==0)  
 78             {  
 79                 *y+=1;  
 80                 *x+=2;  
 81                 return 1;  
 82             }  
 83             break;  
 84         case 3:  
 85             if(*y-1>=0 && *x+2<=X-1 && chess[*x+2][*y-1]==0)  
 86             {  
 87                 *y-=1;  
 88                 *x+=2;  
 89                 return 1;  
 90             }  
 91             break;  
 92         case 4:  
 93             if(*y-2>=0 && *x+1<=X-1 && chess[*x+1][*y-2]==0)  
 94             {  
 95                 *y-=2;  
 96                 *x+=1;  
 97                 return 1;  
 98             }  
 99             break;  
100         case 5:  
101             if(*y-2>=0 && *x-1>=0 && chess[*x-1][*y-2]==0)  
102             {  
103                 *y-=2;  
104                 *x-=1;  
105                 return 1;  
106             }  
107             break;  
108         case 6:  
109             if(*y-1>=0 && *x-2>=0 && chess[*x-2][*y-1]==0)  
110             {  
111                 *y-=1;  
112                 *x-=2;  
113                 return 1;  
114             }  
115             break;  
116         case 7:  
117             if(*y+1<=Y-1 && *x-2>=0 && chess[*x-2][*y+1]==0)  
118             {  
119                 *y+=1;  
120                 *x-=2;  
121                 return 1;  
122             }  
123             break;  
124         default:  
125             break;  
126     }  
127     return 0;  
128 }  
129   
130 /* 
131 遍历整个棋盘-方法一 
132 (x,y)为坐标位置 
133 count为遍历次数 
134 */  
135 int traverse(int x,int y,int count)  
136 {  
137     int x1=x,y1=y; //新节点位置  
138     if(count>X*Y) //已全部遍历且可用，则返回。  
139         return 1;  
140     int flag,result,i;  
141     for(i=0;i<8;i++)  
142     {  
143         flag=next(&x1,&y1,i); //寻找下一个可用位置  
144         if(1==flag)  
145         {  
146             chess[x1][y1]=count; //新找到的结点标识可用,  
147             result=traverse(x1,y1,count+1); //以新节点为根据，再次递归下一个可用结点  
148             if(result) //当前棋盘已全部可用  
149             {  
150                 return 1;  
151             }  
152             else //新找到的结点无下一个可用位置，进行回溯  
153             {  
154                 chess[x1][y1]=0;  
155                 x1=x; //结点位置也要回溯  
156                 y1=y;  
157             }  
158         }  
159     }  
160     return 0;  
161 }  
162   
163 /* 
164 遍历整个棋盘-方法二 
165 (x,y)为坐标位置 
166 tag为遍历次数 
167 */  
168 int traverse_chess(int x,int y,int tag)  
169 {  
170     int x1=x,y1=y,flag=0,count=0;  
171     chess[x][y]=tag;  
172     if(X*Y==tag)  
173     {  
174         return 1;  
175     }  
176     flag=next(&x1,&y1,count);  
177     while(0==flag && count<=7)  
178     {  
179         count++;  
180         flag=next(&x1,&y1,count);  
181     }  
182     while(flag)  
183     {  
184         if(traverse_chess(x1,y1,tag+1)) //如果全部遍历完毕，则返回。  
185         {  
186             return 1;  
187         }  
188         //没有找到下一个可用结点，则回溯  
189         x1=x;  
190         y1=y;  
191         count++;  
192         flag=next(&x1,&y1,count);  
193         while(0==flag && count<=7)  
194         {  
195             count++;  
196             flag=next(&x1,&y1,count);  
197         }  
198     }  
199     if(flag==0)  
200     {  
201         chess[x][y]=0;  
202     }  
203     return 0;  
204 }  
205   
206 /* 
207 打印棋盘 
208 */  
209 void print_chess()  
210 {  
211     int i,j;  
212     for(i=0;i<X;i++)  
213     {  
214         for(j=0;j<Y;j++)  
215         {  
216             printf("%d\t",chess[i][j]);  
217         }  
218         printf("\n");  
219     }  
220 }  
