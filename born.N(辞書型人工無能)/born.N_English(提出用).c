//-------ここから
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>  
#include <string.h>
#include <conio.h>

void dic(int);//dictionary(辞書)
int div_fun(char str_user[128]);//divergence(分岐)のfunction(関数)
void vgan(char str_user[128]);//vavue answer:生返事
void msc(int);//my scan
void ppak(); //Please pless any key

int main()
{
	int div = 0;

	/*乱数初期化*/
	unsigned int now = (unsigned int)time(0);
	srand(now);rand(); rand(); rand(); rand(); rand();

	puts("Please type in within 125 characters.");
	/*ユーザーが入力*/
	char str_user[128] = {0};
	/*自作の入力関数,既存の関数がよくわからなかったり使いづらかったので作ってみた*/
	msc(125,str_user);

	/*メインの処理*/
	div = div_fun(str_user);
	dic(div,str_user);

	/*何故かこれ以降のみが繰り返される場合あり,軌道を追っていくと普通に動く*/
	printf("Please press any key...\n");
	ppak();
}

int div_fun(char str_user[128])
{

	int i = 0, j = 0;
	int cnt = 0;
	int div = 0;
	char dicN[10][18] = {
		"Good morning",
		"Hello",
		"Good evening",
		"Good night",
		"How are you",
		"Yo ",
		"What's up",
		"wazzup",
		"Hey",
		"Hi ",

	};

	/*文字列と一致するかの判定*/
	for (j = 0; j < 10;j++)
	{
		if (div != 0)break;
		for (i = 0;i < 128;i++)
		{
			if ((str_user[i] == dicN[j][cnt])||((cnt == 0)&&(str_user[i] == dicN[j][cnt] + 'a' - 'A')))
			{
				cnt++;
				if (dicN[j][cnt] == '\0')return j;
				if (str_user[i + 1] != dicN[j][cnt])cnt = 0;
			}
		}
	}return -1; //当てはまらなかった
}
void dic(int div,char str_user[128])
{
	int fun = 0,i = 0, cnt = 0;

	//おうむ返しするもの
	char dicN[5][62] = {
		"Good morning\n",
		"Hello\n",
		"Good evening\n",
		"Good night\n",
		"I'm fine\n"
	};
	//この中からランダムで表示する
	char dicN2[5][15] = {
		"Yo\n",
		"What's up!\n",
		"wazzup\n",
		"Hey\n",
		"Hi\n",
	};

	/*おうむ返し*/
	if ((div >= 0)&&(div < 5))	{printf("%s\n", dicN[div]);main();}
	/*ランダム出力*/
	else if(div >= 0) {
		fun = rand() % 5;
		printf("%s\n",dicN2[fun]);
		main();
	}

	/*当てはまらなかった場合、次の処理へ*/
	else vgan(str_user);
}


void vgan(char str_user[128])
{	
	int div = 0, i = 0, cnt = 0;

	/*乱数を作る*/
	div = rand() % 6;

	/*生返事のバリエーション*/
	char dicN[][14] = {
		"oh!\n",
		"hmm...\n",
		"Is that so?\n",
		"uh-huh\n",
		"and then\?\n",
		"Really\?\n",
		"oh,year!\n"
		};

	char dicNplus[] = "See you.\n";

	/*終了コマンド*/
	char dicN2[] = "bye";
	
	for (i = 0;i < 128;i++)
	{
		if (str_user[i] == dicN2[cnt])
		{
			cnt++;
			if (dicN2[cnt] == '\0') { div = 100; break; }
			if (str_user[i + 1] != dicN2[cnt])cnt = 0;
		}
	}
	
//	if (cnt == 100) div = 100;
	if(div < 6) printf("%s\n", dicN[div]);
	else printf("%s\n", dicNplus);
	if (div < 99)main();
}
void msc(int length,char y[])
{
#include <conio.h>
#include <string.h>
	int i=0;//現在表示されている文字数
    
	char x[32767] = {0};//文字列

	for(i = 0;i < length;i++)
	{
		x[i] = _getch();
		if((x[i] >= ' ')&&(x[i] <= '~')) //普通の半角文字
		{
			printf("%c",x[i]);
			y[i] = x[i];
			if(x[i] == '.')break;
		}
		else if(x[i] == '\b')if(i > 0){printf("\b \b");i -= 2;}else i = -1; //BackSpaceKeyの機能を追加
		
		else if (x[i] == 13)break; //EnterKey

		else i--;//出力されていないが１足されてしまうので±0にする
	}
	putchar('\n');
}

void ppak()
{
	//単体でも動くように
#include <conio.h>

	//キーボードに入っている文字列の初期化
	while (1) {
		if (_kbhit()) { _getch(); }
		else break;
	};

	//キー入力があったらループを抜ける
	while (1) {
		if (_kbhit()) {_getch(); break;}
	};
}
//ここまで
