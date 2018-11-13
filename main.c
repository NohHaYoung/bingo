#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"

#define N 3 // N*N 빙고의 N값을 결정하는 기호 상수 
#define M 3 // 승패를 결정하는 기호상수, M개 줄이 먼저 완성된 쪽이 승리 

#define ROWS N
#define COLS N

int main(int argc, char *argv[]) {
	
	int turn; // turn수를 세는 변수
	int Num; // 사용자가 입력한 정수
	int BingoUser=0, BingoCom=0; 
	
	/* N*N 빙고 테이블 2개를 이차원 배열로 정의(Table1 : 사용자, Table2 : 컴퓨터)*/
	 int Table1[ROWS][COLS];
	 int Table2[ROWS][COLS];
	
	/*1~N*N까지 범위 내의 난수를 발생시켜 앞서 정의한 빙고테이블 table1과 table2에 중복없이 랜덤으로 배열하는 함수*/
	initiate_bingo(N, Table1, Table2);
	
	
	/*Game start*/
	do{
	/*Table1 print*/
	 printf("[player Table]\n");
	 print_bingo(Table1); 
	
	 
	/* Table2 print*/
	 printf("[Computer Table]\n");
	 print_bingo(Table2);
	
	 printf("%d 번째 Turn", turn); 
	 printf("사용자 : %d 줄 빙고, 컴퓨터 : %d 줄 빙고", BingoUser, BingoCom);
	
	/*사용자 숫자 선택*/
	get_number_byMe(void){
		if(count_bingo(BingoCom)==M || count_bingo(BingoUser)==M){
			break;
		}
	}
	
	/*컴퓨터 숫자 선택*/
	get_number_byCom(void){
		if(count_bingo(BingoCom)==M || count_bingo(BingoUser)==M){
			break;
		}
	}
	 
	 
	 
	} while(count_bingo(BingoCom)!=M&&countBingo(BingoUser)!=M){
		if(/*player 승리*/){
			printf("turn : %d\n", turn);
			printf("승리하였습니다.\n");
		} 
		
		else(/*computer 승리*/){
			printf("turn : %d\n", turn);
			printf("패배하였습니다.\n");
			
		}
	}
	
	 
	 
	 
	return 0;
}
